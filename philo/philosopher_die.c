/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_die.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:41:06 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/13 14:41:08 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_me_starve(t_parameter *const param)
{
	if (get_time() - param->env->start_time - param->last_eat_time > param->env->time_to_die)
	{
		pthread_mutex_lock(&param->env->mutex_starve);
		param->env->is_someone_starved = 1;
		pthread_mutex_unlock(&param->env->mutex_starve);
		print_died(param);
	}
}

int	check_someone_starve(t_parameter *const param)
{
	pthread_mutex_lock(&param->env->mutex_starve);
	if (param->env->is_someone_starved)
	{
		pthread_mutex_unlock(&param->env->mutex_starve);
		return (1);
	}
	pthread_mutex_unlock(&param->env->mutex_starve);
	return (0);
}
