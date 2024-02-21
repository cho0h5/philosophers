/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:56:14 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/21 11:31:08 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	wait_to_start(t_parameter *const param)
{
	pthread_mutex_lock(&param->env->mutex_ready);
	pthread_mutex_unlock(&param->env->mutex_ready);
}

void	*philosopher(void *arg)
{
	t_parameter *const	param = arg;

	wait_to_start(param);
	if (check_eat_done(param))
		return (NULL);
	param->last_eat_time = param->env->start_time;
	if (print_thinking(param))
		return (NULL);
	if (param->id % 2 == 0 && philosopher_sleep(param))
		return (NULL);
	while (1)
	{
		if (take_forks(param))
			return (NULL);
		if (print_eating(param) || philosopher_eat(param))
			return (NULL);
		release_forks(param);
		param->count_eat += 1;
		if (check_eat_done(param))
			return (NULL);
		if (print_sleeping(param) || philosopher_sleep(param)
			|| print_thinking(param))
			return (NULL);
	}
	return (NULL);
}
