/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:31:03 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/16 17:31:05 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>

int	print_fork(t_parameter *param)
{
	sem_wait(param->env->sem_print);
	printf("%lld %d has taken a fork\n",
		(get_time() - param->env->start_time) / 1000, param->id + 1);
	sem_post(param->env->sem_print);
	return (0);
}

int	print_eating(t_parameter *param)
{
	sem_wait(param->env->sem_print);
	printf("%lld %d is eating\n",
		(get_time() - param->env->start_time) / 1000, param->id + 1);
	sem_post(param->env->sem_print);
	return (0);
}

int	print_sleeping(t_parameter *param)
{
	sem_wait(param->env->sem_print);
	printf("%lld %d is sleeping\n",
		(get_time() - param->env->start_time) / 1000, param->id + 1);
	sem_post(param->env->sem_print);
	return (0);
}

int	print_thinking(t_parameter *param)
{
	sem_wait(param->env->sem_print);
	printf("%lld %d is thinking\n",
		(get_time() - param->env->start_time) / 1000, param->id + 1);
	sem_post(param->env->sem_print);
	return (0);
}

int	print_died(t_parameter *param)
{
	sem_wait(param->env->sem_print);
	printf("%lld %d died\n",
		(get_time() - param->env->start_time) / 1000, param->id + 1);
	return (0);
}
