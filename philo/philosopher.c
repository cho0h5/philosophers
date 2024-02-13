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
