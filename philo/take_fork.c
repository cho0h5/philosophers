/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:38:08 by younghoc          #+#    #+#             */
/*   Updated: 2024/01/19 14:53:41 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_left_fork(t_philosopher *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->left_fork->mutex);
		if (philo->left_fork->is_available == 1)
		{
			philo->left_fork->is_available = 0;
			printf("%lld %d has taken a fork\n", get_time_in_ms(), philo->id);
			pthread_mutex_unlock(&philo->left_fork->mutex);
			return ;
		}
		pthread_mutex_unlock(&philo->left_fork->mutex);
	}
}

static void	take_right_fork(t_philosopher *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->right_fork->mutex);
		if (philo->right_fork->is_available == 1)
		{
			philo->right_fork->is_available = 0;
			printf("%lld %d has taken a fork\n", get_time_in_ms(), philo->id);
			pthread_mutex_unlock(&philo->right_fork->mutex);
			return ;
		}
		pthread_mutex_unlock(&philo->right_fork->mutex);
	}
}

void	take_fork(t_philosopher *philo)
{
	take_left_fork(philo);
	take_right_fork(philo);
}