/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_fork_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:36:19 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/21 11:32:36 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <semaphore.h>
#include <unistd.h>

void	take_forks(t_parameter *const param)
{
	sem_wait(param->env->sem_forks);
	print_fork(param);
	sem_wait(param->env->sem_forks);
	print_fork(param);
}

void	release_forks(t_parameter *const param)
{
	sem_post(param->env->sem_forks);
	sem_post(param->env->sem_forks);
}
