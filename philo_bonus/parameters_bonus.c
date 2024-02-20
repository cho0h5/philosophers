/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:44:00 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/16 16:44:02 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <semaphore.h>
#include <stdlib.h>
#include <fcntl.h>

static char	*get_eat_time_sem_name(int id)
{
	char	*str_id;
	char	*str_sem_name;

	str_id = ft_itoa(id);
	if (str_id == NULL)
		panic("failed to malloc");
	str_sem_name = ft_strjoin("philo_bonus_eat_", str_id);
	free(str_id);
	if (str_sem_name == NULL)
		panic("failed to malloc");
	return (str_sem_name);
}

void	init_parameters(t_env *env, t_parameter **parameters)
{
	int		i;
	char	*sem_name;

	*parameters = malloc(sizeof(t_parameter) * env->number_of_philosophers);
	if (parameters == NULL)
		panic("failed to malloc");
	i = 0;
	while (i < env->number_of_philosophers)
	{
		(*parameters)[i].env = env;
		(*parameters)[i].id = i;
		(*parameters)[i].last_eat_time = 0;
		(*parameters)[i].count_eat = 0;
		sem_name = get_eat_time_sem_name(i);
		(*parameters)[i].eat_time_sem_name = sem_name;
		sem_unlink(sem_name);
		(*parameters)[i].eat_time_sem = sem_open(sem_name, O_CREAT, 0666, 1);
		if ((*parameters)[i].eat_time_sem == SEM_FAILED)
			panic("failed to open semaphore");
		i++;
	}
}

void	free_parameters(t_parameter **parameters, int number_of_philosophers)
{
	int	i;

	i = 0;
	while (i < number_of_philosophers)
	{
		sem_close((*parameters)[i].eat_time_sem);
		sem_unlink((*parameters)[i].eat_time_sem_name);
		free((*parameters)[i].eat_time_sem_name);
		i++;
	}
	free(*parameters);
	*parameters = NULL;
}
