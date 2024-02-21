/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:54:09 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/21 11:30:37 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int	init_fork(t_fork *fork)
{
	fork->is_available = 1;
	return (pthread_mutex_init(&fork->mutex, NULL));
}

int	try_lock_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
	if (fork->is_available)
	{
		fork->is_available = 0;
		pthread_mutex_unlock(&fork->mutex);
		return (0);
	}
	pthread_mutex_unlock(&fork->mutex);
	return (-1);
}

void	unlock_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
	fork->is_available = 1;
	pthread_mutex_unlock(&fork->mutex);
}
