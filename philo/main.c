/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Youngho Cho <younghoc@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:01:54 by Youngho Cho       #+#    #+#             */
/*   Updated: 2024/01/19 15:11:31 by Youngho Cho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->id % 2 == 0)
	{
		take_fork(philo->left_fork, philo->id);
		take_fork(philo->right_fork, philo->id);
		printf("%lld %d is eating\n", get_time_in_ms(), philo->id);
		release_fork(philo->right_fork);
		release_fork(philo->left_fork);
	}
	else
	{
		take_fork(philo->right_fork, philo->id);
		take_fork(philo->left_fork, philo->id);
		printf("%lld %d is eating\n", get_time_in_ms(), philo->id);
		release_fork(philo->left_fork);
		release_fork(philo->right_fork);
	}

	// while (philo->state != DEAD)
	// {
	// 	if (philo->state == EATING)
	// 		eating(philo);
	// 	else if (philo->state == SLEEPING)
	// 		sleeping(philo);
	// 	else if (philo->state == THINKING)
	// 		thinking(philo);
	// 	else if (philo->state == FORK)
	// 		take_fork(philo);
	// 	else if (philo->state == DEAD)
	// 		break ;
	// }
	return (NULL);
}

static int	init(int argc, char **argv, t_env *env)
{
	int	i;

	if (argc == 5)
	{
		env->number_of_philosophers = parse_int(argv[1]);
		env->time_to_die = parse_int(argv[2]);
		env->time_to_eat = parse_int(argv[3]);
		env->time_to_sleep = parse_int(argv[4]);
		env->time_to_sleep = -1;
	}
	else if (argc == 6)
	{
		env->number_of_philosophers = parse_int(argv[1]);
		env->time_to_die = parse_int(argv[2]);
		env->time_to_eat = parse_int(argv[3]);
		env->time_to_sleep = parse_int(argv[4]);
		env->number_of_must_eat = parse_int(argv[5]);
	}
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
	return (0);
}

static t_philosopher	*create_t_philosopher(t_env *env, int id)
{
	t_philosopher	*philo;

	philo = malloc(sizeof(t_philosopher));
	if (philo == NULL)
		return (NULL);
	philo->id = id;
	philo->time_to_die = env->time_to_die;
	philo->time_to_eat = env->time_to_eat;
	philo->time_to_sleep = env->time_to_sleep;
	philo->number_of_must_eat = env->number_of_must_eat;
	philo->left_fork = &env->forks[id];
	philo->right_fork = &env->forks[(id + 1) % env->number_of_philosophers];
	return (philo);
}

int	main(int argc, char **argv)
{
	t_env			env;
	int				i;
	t_philosopher	*philo_env;
	struct timeval	time;

	if (init(argc, argv, &env))
		return (1);
	gettimeofday(&time, NULL);
	printf("%ld %d\n", time.tv_sec, time.tv_usec);
	i = 0;
	while (i < env.number_of_philosophers)
	{
		philo_env = create_t_philosopher(&env, i);
		if (philo_env == NULL)
			return (1);	// 만들어진 쓰레드 회수해줘야함
		pthread_create(&env.philosophers[i], NULL, philosopher, philo_env);
		i++;
	}
	i = 0;
	while (i < env.number_of_philosophers)
	{
		pthread_join(env.philosophers[i], NULL);
		i++;
	}
	i = 0;
	while (i < env.number_of_philosophers)
	{
		pthread_mutex_destroy(&env.forks[i].mutex);
		i++;
	}
	return (0);
}
