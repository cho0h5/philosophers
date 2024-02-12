/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:15:56 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/12 20:15:57 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

static	void	wait_to_start(t_parameter const *param)
{
	pthread_mutex_lock(&param->env->mutex_ready);
	pthread_mutex_unlock(&param->env->mutex_ready);
}

void	*philosopher(void *arg)
{
	t_parameter const	*param = arg;

	wait_to_start(param);
	printf("id%d: %lld\n", param->id, get_time());
	return (NULL);
}
