/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_sleep.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:45:32 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/13 16:45:33 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

int	philosopher_sleep(t_parameter *const param)
{
	const long long	start_time_sleep = get_time();

	while (get_time() - start_time_sleep < param->env->time_to_sleep)
	{
		check_me_starve(param);
		if (check_someone_starve(param))
			return (-1);
		usleep(100);
	}
	return (0);
}
