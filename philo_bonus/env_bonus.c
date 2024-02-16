/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:48:13 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/16 15:49:14 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo_bonus.h"
#include <fcntl.h>

static void	unlink_semaphores()
{
	sem_unlink("philo_bonus_forks");
	sem_unlink("philo_bonus_ready");
	sem_unlink("philo_bonus_starve");
	sem_unlink("philo_bonus_print");
}

void	init_env(t_env *env)
{
	unlink_semaphores();
	env->sem_forks = sem_open("philo_bonus_forks", O_CREAT, 0666, env->number_of_philosophers);
	env->sem_ready = sem_open("philo_bonus_ready", O_CREAT, 0666, 0);
	env->sem_starve = sem_open("philo_bonus_starve", O_CREAT, 0666, 123);
	env->sem_print = sem_open("philo_bonus_print", O_CREAT, 0666, 1);
	if (env->sem_forks == SEM_FAILED || env->sem_ready == SEM_FAILED
		|| env->sem_starve == SEM_FAILED || env->sem_print == SEM_FAILED)
		panic("failed to open semaphore");
}

void	free_env(t_env *env)
{
	sem_close(env->sem_forks);
	sem_close(env->sem_ready);
	sem_close(env->sem_starve);
	sem_close(env->sem_print);
	unlink_semaphores();
}

