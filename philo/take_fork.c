/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Youngho Cho <younghoc@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:38:08 by younghoc          #+#    #+#             */
/*   Updated: 2024/01/19 15:07:55 by Youngho Cho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_fork *fork, int id)
{
	while (1)
	{
		pthread_mutex_lock(&fork->mutex);
		if (fork->is_available == 1)
		{
			fork->is_available = 0;
			printf("%lld %d has taken a fork\n", get_time_in_ms(), id);
			pthread_mutex_unlock(&fork->mutex);
			return ;
		}
		pthread_mutex_unlock(&fork->mutex);
	}
}

void	release_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
	fork->is_available = 1;
	pthread_mutex_unlock(&fork->mutex);
}
