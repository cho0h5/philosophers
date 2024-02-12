/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:15:56 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/12 20:15:57 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

static	void	wait_to_start(t_parameter const *param)
{
	pthread_mutex_lock(&param->env->mutex_ready);
	pthread_mutex_unlock(&param->env->mutex_ready);
}

static t_fork	*left_fork(t_parameter const *param)
{
	const int	id_fork = param->id;

	return (&param->env->forks[id_fork]);
}

static t_fork	*right_fork(t_parameter const *param)
{
	const int	id_fork = (param->id + 1) % param->env->number_of_philosophers;

	return (&param->env->forks[id_fork]);
}

static int	take_forks(t_parameter const *param)
{
	while (try_lock_fork(left_fork(param))) ;
	printf("id%d: has taken left fork (%p)\n", param->id, left_fork(param));
	usleep(1000);
	while (try_lock_fork(right_fork(param))) ;
	printf("id%d: has taken right fork (%p)\n", param->id, right_fork(param));
	return (0);
}

static void	release_forks(t_parameter const *param)
{
	unlock_fork(left_fork(param));
	unlock_fork(right_fork(param));
}

void	*philosopher(void *arg)
{
	t_parameter const	*param = arg;

	wait_to_start(param);
	printf("id%d: %lld\n", param->id, get_time());
	take_forks(param);
	release_forks(param);
	return (NULL);
}
