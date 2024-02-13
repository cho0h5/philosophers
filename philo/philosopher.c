/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:56:14 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/13 15:56:15 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	wait_to_start(t_parameter *const param)
{
	pthread_mutex_lock(&param->env->mutex_ready);
	pthread_mutex_unlock(&param->env->mutex_ready);
}

void	spawn_philosophers(t_env *env, t_parameter *parameters)
{
	int	i;

	i = 0;
	while (i < env->number_of_philosophers)
	{
		if (pthread_create(&env->philosophers[i], NULL,
				philosopher, &parameters[i]) != 0)
			panic("failed to create thread");
		i++;
	}
}

void	start_simulation(t_env *env)
{
	env->start_time = get_time();
	pthread_mutex_unlock(&env->mutex_ready);
}

void	join_philosophers(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->number_of_philosophers)
	{
		pthread_join(env->philosophers[i], NULL);
		i++;
	}
}

void	*philosopher(void *arg)
{
	t_parameter *const	param = arg;

	wait_to_start(param);
	param->last_eat_time = param->env->start_time;
	print_thinking(param);
	if (param->id % 2 == 0)
		if (philosopher_eat(param))
			return (NULL);
	while (1)
	{
		if (take_forks(param))
			return (NULL);
		print_eating(param);
		if (philosopher_eat(param))
			return (NULL);
		release_forks(param);
		print_sleeping(param);
		if (philosopher_sleep(param))
			return (NULL);
		print_thinking(param);
	}
	return (NULL);
}
