/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_spawn.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:00:07 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/21 11:31:06 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_simulation(t_env *env)
{
	env->start_time = get_time();
	pthread_mutex_unlock(&env->mutex_ready);
}

int	spawn_philosophers(t_env *env, t_parameter *parameters)
{
	int	i;

	i = 0;
	while (i < env->number_of_philosophers)
	{
		if (pthread_create(&env->philosophers[i], NULL,
				philosopher, &parameters[i]) != 0)
			return (panic("failed to create thread"));
		i++;
	}
	return (0);
}
