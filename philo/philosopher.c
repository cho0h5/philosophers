/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:12:53 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/12 14:12:54 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

//static int	is_die(t_philosopher *philo)
//{
//	if (get_time_in_ms() - philo->env->start_time - philo->last_eat_time
//		> philo->env->time_to_die)
//	{
//		print_died(philo->id, philo->env);
//		return (1);
//	}
//	return (0);
//}

//static void	die(t_philosopher *philo)
//{
//	pthread_mutex_lock(&philo->env->mutex_die);
//	if (philo->env->mutex_is_die == 0)
//	{
//		philo->env->mutex_is_die = 1;
//		print_died(philo->id, philo->env);
//	}
//	pthread_mutex_unlock(&philo->env->mutex_die);
//}
//
//static int	should_i_die(t_env *env)
//{
//	pthread_mutex_lock(&env->mutex_die);
//	if (env->mutex_is_die == 1)
//	{
//		pthread_mutex_unlock(&env->mutex_die);
//		return (1);
//	}
//	pthread_mutex_unlock(&env->mutex_die);
//	return (0);
//}

static int	philosopher_think(t_philosopher *philo)
{
	print_thinking(philo->id, philo->env);
	while (!take_fork(get_left_fork(philo), philo->env, philo->id))
		usleep(100);
	while (!take_fork(get_right_fork(philo), philo->env, philo->id))
		usleep(100);
//	if (get_left_fork(philo) == get_right_fork(philo))
//		die(philo);
	return (0);
}

static int	philosopher_eat(t_philosopher *philo)
{
	philo->eat_count++;
	print_eating(philo->id, philo->env);
	philo->last_eat_time = get_time_in_ms() - philo->env->start_time;
	msleep(philo->env->time_to_eat);
	release_fork(get_left_fork(philo));
	release_fork(get_right_fork(philo));
	return (0);
}

static int	philosopher_sleep(t_philosopher *philo)
{
	print_sleeping(philo->id, philo->env);
	msleep(philo->env->time_to_sleep);
	return (0);
}

void	*philosopher(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	pthread_mutex_lock(&philo->env->mutex_wait);
	pthread_mutex_unlock(&philo->env->mutex_wait);
	if (philo->id % 2 == 1)
	{
		print_thinking(philo->id, philo->env);
		msleep(philo->env->time_to_eat);
	}
	while (philo->env->number_of_must_eat == -1
		|| philo->eat_count < philo->env->number_of_must_eat)
	{
		philosopher_eat(philo);
		philosopher_sleep(philo);
		philosopher_think(philo);
	}
	return (NULL);
}
