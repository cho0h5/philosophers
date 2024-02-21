/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_wait_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:02:30 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/21 11:32:41 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <signal.h>
#include <sys/wait.h>

static void	kill_children(t_env *const env)
{
	int	i;

	i = 0;
	while (i < env->number_of_philosophers)
	{
		kill(env->children[i], SIGKILL);
		i++;
	}
}

void	wait_philosophers(t_env *const env)
{
	int	i;
	int	stat_loc;

	i = 0;
	while (i < env->number_of_philosophers)
	{
		waitpid(0, &stat_loc, 0);
		if (WIFEXITED(stat_loc))
		{
			if (WEXITSTATUS(stat_loc) == 1)
				kill_children(env);
		}
		i++;
	}
	sem_post(env->sem_print);
}
