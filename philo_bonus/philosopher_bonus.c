/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:59:02 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/16 16:59:04 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <sys/wait.h>
#include <unistd.h>

static void	wait_to_start(t_parameter *const param)
{
	while (get_time() < param->env->start_time)
		usleep(100);
}

void	philosopher(t_parameter *const param)
{
	wait_to_start(param);
	if (check_eat_done(param))
		return ;
	param->last_eat_time = param->env->start_time;
	if (print_thinking(param))
		return ;
	if (param->id % 2 == 0 && philosopher_sleep(param))
		return ;
	while (1)
	{
		take_forks(param);
		if (print_eating(param) || philosopher_eat(param))
			return ;
		release_forks(param);
		param->count_eat += 1;
		if (check_eat_done(param))
			return ;
		if (print_sleeping(param) || philosopher_sleep(param)
			|| print_thinking(param))
			return ;
	}
}
