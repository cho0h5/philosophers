/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:26:02 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/12 19:26:03 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

static void	parse_argument(int argc, char **argv, t_env *env)
{
	env->number_of_philosophers = parse_int(argv[1]);
	env->time_to_die = parse_int(argv[2]);
	env->time_to_eat = parse_int(argv[3]);
	env->time_to_sleep = parse_int(argv[4]);
	if (argc == 5)
		env->number_of_must_eat = -1;
	else if (argc == 6)
		env->number_of_must_eat = parse_int(argv[5]);
	else
		panic("invalid argument");
	if (env->number_of_philosophers == NOT_INT
		|| env->time_to_die == NOT_INT
		|| env->time_to_eat == NOT_INT
		|| env->time_to_sleep == NOT_INT
		|| env->number_of_must_eat == NOT_INT)
		panic("invalid argument");
}

static void	init_env(t_env *env)
{
	int	i;

	env->philosophers = malloc(sizeof(pthread_t) * env->number_of_philosophers);
	env->forks = malloc(sizeof(t_fork) * env->number_of_philosophers);
	if (env->philosophers == NULL || env->forks == NULL)
		panic("failed to malloc");
	i = 0;
	while (i < env->number_of_philosophers)
	{
		if (init_fork(&env->forks[i])!= 0)
			panic("failed to initialize mutex");
		i++;
	}
}

static void	init_parameters(t_env *env, t_parameter **parameters)
{
	int	i;

	*parameters = malloc(sizeof(t_parameter) * env->number_of_philosophers);
	if (parameters == NULL)
		panic("failed to malloc");
	i = 0;
	while (i < env->number_of_philosophers)
	{
		(*parameters)[i].env = env;
		(*parameters)[i].id = i;
		(*parameters)[i].last_eat_time = 0;
		(*parameters)[i].count_eat = 0;
		i++;
	}
}

static void	create_philosophers(t_env *env, t_parameter *parameters)
{
	int	i;

	i = 0;
	while (i < env->number_of_philosophers)
	{
		pthread_create(&env->philosophers[i], NULL, philosopher, &parameters[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_env		env;
	t_parameter	*parameters;

	parse_argument(argc, argv, &env);
	init_env(&env);
	init_parameters(&env, &parameters);
	create_philosophers(&env, parameters);
}
