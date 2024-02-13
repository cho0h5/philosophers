/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:15:56 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/13 13:32:25 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

static void	wait_to_start(t_parameter *const param)
{
	pthread_mutex_lock(&param->env->mutex_ready);
	pthread_mutex_unlock(&param->env->mutex_ready);
}

static void	check_me_starve(t_parameter *const param)
{
	if (get_time() - param->env->start_time - param->last_eat_time > param->env->time_to_die)
	{
		pthread_mutex_lock(&param->env->mutex_starve);
		param->env->is_someone_starved = 1;
		pthread_mutex_unlock(&param->env->mutex_starve);
		printf("%lld\t%d\tdied\n",
			(get_time() - param->env->start_time) / 1000, param->id);
	}
}

static int	check_someone_starve(t_parameter *const param)
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

static t_fork	*left_fork(t_parameter *const param)
{
	const int	id_fork = param->id;

	return (&param->env->forks[id_fork]);
}

static t_fork	*right_fork(t_parameter *const param)
{
	const int	id_fork = (param->id + 1) % param->env->number_of_philosophers;

	return (&param->env->forks[id_fork]);
}

static int	take_forks(t_parameter *const param)
{
	while (try_lock_fork(left_fork(param)))
	{
		check_me_starve(param);
		if (check_someone_starve(param))
			return (-1);
	}
	printf("%lld\t%d\thas taken a left fork\n",
		(get_time() - param->env->start_time) / 1000, param->id);
	while (try_lock_fork(right_fork(param)))
	{
		check_me_starve(param);
		if (check_someone_starve(param))
			return (-1);
	}
	printf("%lld\t%d\thas taken a right fork\n",
		(get_time() - param->env->start_time) / 1000, param->id);
	return (0);
}

static void	release_forks(t_parameter *const param)
{
	unlock_fork(left_fork(param));
	unlock_fork(right_fork(param));
}

static int	eat(t_parameter *const param)
{
	const long long	start_time_eat = get_time();

	while (get_time() - start_time_eat < param->env->time_to_eat)
	{
		check_me_starve(param);
		if (check_someone_starve(param))
			return (-1);
		// usleep(100);
	}
	param->last_eat_time = get_time();
	return (0);
}

void	*philosopher(void *arg)
{
	t_parameter *const	param = arg;

	wait_to_start(param);
	printf("%lld\t%d\tcreated\n",
		(get_time() - param->env->start_time) / 1000, param->id);
	if (take_forks(param))
		return (NULL);
	printf("%lld\t%d\tis eating\n",
		(get_time() - param->env->start_time) / 1000, param->id);
	if (eat(param))
		return (NULL);
	release_forks(param);
	return (NULL);
}
