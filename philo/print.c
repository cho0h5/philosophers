/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:30:42 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/11 17:30:43 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_fork(int id, t_env *env)
{
	printf("%lld %d has taken a fork\n", get_time_in_ms() - env->start_time, id + 1);
}

void	print_eating(int id, t_env *env)
{
	printf("%lld %d is eating\n", get_time_in_ms() - env->start_time, id + 1);
}

void	print_sleeping(int id, t_env *env)
{
	printf("%lld %d is sleeping\n", get_time_in_ms() - env->start_time, id + 1);
}

void	print_thinking(int id, t_env *env)
{
	printf("%lld %d is thinking\n", get_time_in_ms() - env->start_time, id + 1);
}

void	print_died(int id, t_env *env)
{
	printf("%lld %d died\n", get_time_in_ms() - env->start_time, id + 1);
}
