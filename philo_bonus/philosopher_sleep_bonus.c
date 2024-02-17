/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_sleep_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:50:39 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/16 18:50:40 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <unistd.h>
#include <stdlib.h>

int	philosopher_sleep(t_parameter *const param)
{
	const long long	start_time_sleep = get_time();

	while (get_time() - start_time_sleep < param->env->time_to_sleep)
	{
		if (check_me_starve(param))
			exit(0);
		usleep(100);
	}
	return (0);
}
