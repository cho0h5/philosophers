/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:31:15 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/13 14:31:16 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	print_fork(t_parameter *param)
{
	while (try_lock_fork(&param->env->fork_print))
	{
		check_me_starve(param);
		if (check_someone_starve(param))
			return (-1);
	}
	printf("%lld %d has taken a fork\n",
		(get_time() - param->env->start_time) / 1000, param->id + 1);
	unlock_fork(&param->env->fork_print);
	return (0);
}

int	print_eating(t_parameter *param)
{
	while (try_lock_fork(&param->env->fork_print))
	{
		check_me_starve(param);
		if (check_someone_starve(param))
			return (-1);
	}
	printf("%lld %d is eating\n",
		(get_time() - param->env->start_time) / 1000, param->id + 1);
	unlock_fork(&param->env->fork_print);
	return (0);
}

int	print_sleeping(t_parameter *param)
{
	while (try_lock_fork(&param->env->fork_print))
	{
		check_me_starve(param);
		if (check_someone_starve(param))
			return (-1);
	}
	printf("%lld %d is sleeping\n",
		(get_time() - param->env->start_time) / 1000, param->id + 1);
	unlock_fork(&param->env->fork_print);
	return (0);
}

int	print_thinking(t_parameter *param)
{
	while (try_lock_fork(&param->env->fork_print))
	{
		check_me_starve(param);
		if (check_someone_starve(param))
			return (-1);
	}
	printf("%lld %d is thinking\n",
		(get_time() - param->env->start_time) / 1000, param->id + 1);
	unlock_fork(&param->env->fork_print);
	return (0);
}

int	print_died(t_parameter *param)
{
	while (try_lock_fork(&param->env->fork_print))
	{
		check_me_starve(param);
		if (check_someone_starve(param))
			return (-1);
	}
	printf("%lld %d died\n",
		(get_time() - param->env->start_time) / 1000, param->id + 1);
	return (0);
}
