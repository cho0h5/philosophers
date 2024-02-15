/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:45:25 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/13 16:45:27 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

int	check_eat_done(t_parameter *const param)
{
	return ((param->env->number_of_must_eat != -1
			&& param->count_eat >= param->env->number_of_must_eat));
}

int	philosopher_eat(t_parameter *const param)
{
	const long long	start_time_eat = get_time();

	param->last_eat_time = get_time();
	usleep(0.9 * param->env->time_to_eat);
	while (get_time() - start_time_eat < param->env->time_to_eat)
	{
		check_me_starve(param);
		if (check_someone_starve(param))
			return (-1);
		usleep(100);
	}
	return (0);
}
