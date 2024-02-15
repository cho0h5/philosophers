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

int	philosopher_eat(t_parameter *const param)
{
	const long long	start_time_eat = get_time();

	while (get_time() - start_time_eat < param->env->time_to_eat)
	{
		check_me_starve(param);
		if (check_someone_starve(param))
			return (-1);
		usleep(100);
	}
	param->last_eat_time = get_time();
	return (0);
}
