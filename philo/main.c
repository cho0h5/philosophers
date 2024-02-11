/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Youngho Cho <younghoc@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:01:54 by Youngho Cho       #+#    #+#             */
/*   Updated: 2024/01/25 13:56:09 by Youngho Cho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher(void *arg)
{
	t_philosopher	*philo;
	t_state			state;
	long long		last_eat_time;
	long long		eat_count;

	philo = (t_philosopher *)arg;
	pthread_mutex_lock(&philo->env->mutex_wait);
	pthread_mutex_unlock(&philo->env->mutex_wait);
	state = THINKING;
	last_eat_time = 0;
	eat_count = 0;
	if (philo->id % 2 == 1)
	{
		print_thinking(philo->id, philo->env);
		msleep(philo->env->time_to_eat);
	}
	while (philo->env->number_of_must_eat == -1 || eat_count < philo->env->number_of_must_eat)
	{
		if (state == THINKING)
		{
			if (get_time_in_ms() - philo->env->start_time - last_eat_time > philo->env->time_to_die)
			{
				print_died(philo->id, philo->env);
				break;
			}
			if (take_fork(&philo->env->forks[philo->id], philo->env, philo->id) &&
				take_fork(&philo->env->forks[(philo->id + 1) % philo->env->number_of_philosophers], philo->env, philo->id) &&
				&philo->env->forks[philo->id] != &philo->env->forks[(philo->id + 1) % philo->env->number_of_philosophers])
				state = EATING;
		}
		else if (state == EATING)
		{
			eat_count++;
			print_eating(philo->id, philo->env);
			last_eat_time = get_time_in_ms() - philo->env->start_time;
			msleep(philo->env->time_to_eat);
			release_fork(&philo->env->forks[philo->id]);
			release_fork(&philo->env->forks[(philo->id + 1) % philo->env->number_of_philosophers]);
			state = SLEEPING;
		}
		else if (state == SLEEPING)
		{
			print_sleeping(philo->id, philo->env);
			msleep(philo->env->time_to_sleep);
			print_thinking(philo->id, philo->env);
			state = THINKING;
		}
		usleep(100);
	}
	return (NULL);
}

static int	init(int argc, char **argv, t_env *env)
{
	int	i;

	env->number_of_philosophers = parse_int(argv[1]);
	env->time_to_die = parse_int(argv[2]);
	env->time_to_eat = parse_int(argv[3]);
	env->time_to_sleep = parse_int(argv[4]);
	if (argc == 5)
		env->number_of_must_eat = -1;
	else if (argc == 6)
		env->number_of_must_eat = parse_int(argv[5]);
	else
		return (-1);
	env->philosophers = malloc(sizeof(pthread_t) * env->number_of_philosophers);
	env->forks = malloc(sizeof(t_fork) * env->number_of_philosophers);
	if (env->philosophers == NULL || env->forks == NULL)
	{
		free(env->philosophers);
		free(env->forks);
		return (-1);
	}
	i = 0;
	while (i < env->number_of_philosophers)
	{
		pthread_mutex_init(&env->forks[i].mutex, NULL);
		env->forks[i].is_available = 1;
		i++;
	}
	pthread_mutex_init(&env->mutex_wait, NULL);
	pthread_mutex_init(&env->mutex_print, NULL);
	pthread_mutex_lock(&env->mutex_wait);
	return (0);
}

static t_philosopher	*create_t_philosopher(t_env *env, int id)
{
	t_philosopher	*philo;

	philo = malloc(sizeof(t_philosopher));
	if (philo == NULL)
		return (NULL);
	philo->id = id;
	philo->env = env;
	return (philo);
}

int	main(int argc, char **argv)
{
	t_env			env;
	int				i;
	t_philosopher	*philo_env;

	if (init(argc, argv, &env))
		return (1);
	i = 0;
	while (i < env.number_of_philosophers)
	{
		philo_env = create_t_philosopher(&env, i);
		if (philo_env == NULL)
			return (1);	// 만들어진 쓰레드 회수해줘야함
		pthread_create(&env.philosophers[i++], NULL, philosopher, philo_env);
	}
	env.start_time = get_time_in_ms();
	pthread_mutex_unlock(&env.mutex_wait);
	i = 0;
	while (i < env.number_of_philosophers)
		pthread_join(env.philosophers[i++], NULL);
	i = 0;
	while (i < env.number_of_philosophers)
		pthread_mutex_destroy(&env.forks[i++].mutex);
	return (0);
}
