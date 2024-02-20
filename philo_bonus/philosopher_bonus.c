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
#include <fcntl.h>
#include <stdlib.h>

static void	init_philosopher(t_parameter *const param)
{
	char	*str_id;

	str_id = ft_itoa(param->id);
	if (str_id == NULL)
		panic("failed to malloc");
	param->str_last_eat_time = ft_strjoin("philo_bonus_eat_", str_id);
	if (param->str_last_eat_time == NULL)
		panic("failed to malloc");
	free(str_id);
	sem_unlink(param->str_last_eat_time);
	param->sem_last_eat_time = sem_open(param->str_last_eat_time,
			O_CREAT, 0666, 1);
}

static void	wait_to_start(t_parameter *const param)
{
	while (get_time() < param->env->start_time)
		usleep(100);
}

void	philosopher(t_parameter *const param)
{
	init_philosopher(param);
	wait_to_start(param);
	print_thinking(param);
	sem_wait(param->sem_last_eat_time);
	param->last_eat_time = param->env->start_time;
	sem_post(param->sem_last_eat_time);
	create_die_checker(param);
	if (param->id % 2 == 0)
		philosopher_sleep(param);
	while (1)
	{
		take_forks(param);
		print_eating(param);
		philosopher_eat(param);
		release_forks(param);
		param->count_eat += 1;
		if (check_eat_done(param))
			return ;
		print_sleeping(param);
		philosopher_sleep(param);
		print_thinking(param);
	}
}
