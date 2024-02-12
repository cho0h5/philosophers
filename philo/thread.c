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
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

static void	wait_to_start(t_parameter const *param)
{
	pthread_mutex_lock(&param->env->mutex_ready);
	pthread_mutex_unlock(&param->env->mutex_ready);
}

static void	check_me_starve(t_parameter const *param)
{
	if (get_time() - param->last_eat_time > param->env->time_to_die)
	{
		pthread_mutex_lock(&param->env->mutex_starve);
		param->env->is_someone_starved = 1;
		pthread_mutex_unlock(&param->env->mutex_starve);
	}
}

static int	check_someone_starve(t_parameter const *param)
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
	while (try_lock_fork(left_fork(param)))
	{
		check_me_starve(param);
		if (check_someone_starve(param))
		{
			// print dead
			return (-1);
		}
	}
	printf("id%d: has taken left fork (%p)\n", param->id, left_fork(param));
	while (try_lock_fork(right_fork(param)))
	{
		check_me_starve(param);
		if (check_someone_starve(param))
		{
			// print dead
			return (-1);
		}
	}
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
