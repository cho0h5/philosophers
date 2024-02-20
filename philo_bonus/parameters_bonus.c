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
#include <stdlib.h>
#include <semaphore.h>

void	init_parameters(t_env *env, t_parameter **parameters)
{
	int		i;
	char	*str_id;

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
		i++;
	}
	str_id = ft_itoa((*parameters)->id);
	if (str_id == NULL)
		panic("failed to malloc");
	(*parameters)->str_last_eat_time = ft_strjoin("philo_bonus_eat_", str_id);
	if ((*parameters)->str_last_eat_time == NULL)
		panic("failed to malloc");
	free(str_id);
	sem_unlink((*parameters)->str_last_eat_time);
	sem_open((*parameters)->str_last_eat_time, O_CREAT, 0666, 1);
}

void	free_parameters(t_parameter **parameters)
{
	sem_close((*parameters)->sem_last_eat_time);
	sem_unlink((*parameters)->str_last_eat_time);
	free((*parameters)->str_last_eat_time);
	free(*parameters);
	*parameters = NULL;
}
