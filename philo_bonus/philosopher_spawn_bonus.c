/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_spawn_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:56:20 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/18 13:56:21 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

static void	handling_fork_exception(pid_t *children, int number_of_created)
{
	int	j;

	j = 0;
	while (j < number_of_created)
	{
		kill(children[j], SIGKILL);
		waitpid(0, NULL, 0);
		j++;
	}
	panic("failed to fork");
}

void	spawn_philosophers(t_env *env, t_parameter *parameters)
{
	int			i;
	const int	delay = env->number_of_philosophers * 30 * 1000;

	i = 0;
	env->start_time = get_time() + delay;
	while (i < env->number_of_philosophers)
	{
		env->children[i] = fork();
		if (env->children[i] == 0)
		{
			philosopher(&parameters[i]);
			sem_close(parameters[i].sem_last_eat_time);
			sem_unlink(parameters[i].str_last_eat_time);
			free(parameters[i].str_last_eat_time);
			free_parameters(&parameters);
			destroy_env(env);
			exit(0);
		}
		else if (env->children[i] == -1)
			handling_fork_exception(env->children, i);
		i++;
	}
}
