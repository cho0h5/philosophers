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
	print_fork(param);
	while (try_lock_fork(right_fork(param)))
	{
		check_me_starve(param);
		if (check_someone_starve(param))
			return (-1);
	}
	print_fork(param);
	return (0);
}

static void	release_forks(t_parameter *const param)
{
	unlock_fork(left_fork(param));
	unlock_fork(right_fork(param));
}

static int	philosopher_eat(t_parameter *const param)
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

static int	philosopher_sleep(t_parameter *const param)
{
	const long long	start_time_sleep = get_time();

	while (get_time() - start_time_sleep < param->env->time_to_sleep)
	{
		check_me_starve(param);
		if (check_someone_starve(param))
			return (-1);
		// usleep(100);
	}
	return (0);
}

void	*philosopher(void *arg)
{
	t_parameter *const	param = arg;

	wait_to_start(param);
	param->last_eat_time = param->env->start_time;
	print_thinking(param);
	if (param->id % 2 == 0)
		if (philosopher_eat(param))
			return (NULL);
	while (1)
	{
		if (take_forks(param))
			return (NULL);
		print_eating(param);
		if (philosopher_eat(param))
			return (NULL);
		release_forks(param);
		print_sleeping(param);
		if (philosopher_sleep(param))
			return (NULL);
		print_thinking(param);
	}
	return (NULL);
}
