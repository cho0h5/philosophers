/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Youngho Cho <younghoc@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:01:54 by Youngho Cho       #+#    #+#             */
/*   Updated: 2024/01/18 20:00:55 by Youngho Cho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/_pthread/_pthread_mutex_t.h>
#include <sys/time.h>

void	*philosophers(void *arg)
{
	(void)arg;
	printf("children\n");
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

int	main(int argc, char **argv)
{
	t_env			env;
	int				i;
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
		pthread_create(&env.philosophers[i], NULL, philosophers, NULL);
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
