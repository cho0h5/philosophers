/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_die.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:40:18 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/17 12:40:20 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int	check_me_starve(t_parameter *const param)
{
	if (get_time() - param->last_eat_time > param->env->time_to_die)
	{
		print_died(param);
		return (1);
	}
	return (0);
}

static void	*die_checker(void *arg)
{
	t_parameter *const	param = (t_parameter *const)arg;

	while (1)
	{
		if (check_me_starve(param))
			exit(0);
		usleep(100);
	}
	return (NULL);
}

void	create_die_checker(t_parameter *const param)
{
	pthread_t tid;

	if (pthread_create(&tid, NULL, die_checker, param))
		panic("failed to pthread_create");
}
