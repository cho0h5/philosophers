/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:01:54 by Youngho Cho       #+#    #+#             */
/*   Updated: 2024/01/19 13:53:17 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/_pthread/_pthread_mutex_t.h>
#include <sys/time.h>

void	*philosopher(void *arg)
{
	t_philosopher	*philo;

	philo = arg;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		printf("timestamp_in_ms %d has taken a fork\n", philo->id);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
		printf("timestamp_in_ms %d has taken a fork\n", philo->id);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	return (NULL);
}

static int	init(int argc, char **argv, t_env *env)
{
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
	env->forks = malloc(sizeof(pthread_mutex_t) * env->number_of_philosophers);
	if (env->philosophers == NULL || env->forks == NULL)
	{
		free(env->philosophers);
		free(env->forks);
		return (-1);
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
//	struct timeval	time;

	if (init(argc, argv, &env))
		return (1);
//	gettimeofday(&time, NULL);
//	printf("%ld %d\n", time.tv_sec, time.tv_usec);
	i = 0;
	while (i < env.number_of_philosophers)
	{
		pthread_mutex_init(&env.forks[i], NULL);
		i++;
	}
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
		pthread_mutex_destroy(&env.forks[i]);
		i++;
	}
	return (0);
}
