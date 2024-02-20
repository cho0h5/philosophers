/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_eat_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:50:35 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/16 18:50:36 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <unistd.h>
#include <stdlib.h>

int	check_eat_done(t_parameter *const param)
{
	return ((param->env->number_of_must_eat != -1
			&& param->count_eat >= param->env->number_of_must_eat));
}

void	philosopher_eat(t_parameter *const param)
{
	const long long	start_time_eat = get_time();

	param->last_eat_time = get_time();
	while (get_time() - start_time_eat < param->env->time_to_eat)
	{
		if (check_me_starve(param))
			exit(1);
		usleep(100);
	}
}
