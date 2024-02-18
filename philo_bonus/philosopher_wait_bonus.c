/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_wait_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:02:30 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/18 14:02:31 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <signal.h>
#include <stdlib.h>

void	wait_philosophers(t_env *env)
{
	int	i;

	waitpid(0, NULL, 0);
	i = 0;
	while (i < env->number_of_philosophers)
	{
		kill(env->children[i], SIGKILL);
		i++;
	}
	i = 0;
	while (i < env->number_of_philosophers - 1)
	{
		waitpid(0, NULL, 0);
		i++;
	}
	sem_post(env->sem_print);
}
