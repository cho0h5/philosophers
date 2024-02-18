/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:55:54 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/13 15:55:55 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

int	init_parameters(t_env *env, t_parameter **parameters)
{
	int	i;

	*parameters = malloc(sizeof(t_parameter) * env->number_of_philosophers);
	if (parameters == NULL)
		return (panic("failed to malloc"));
	i = 0;
	while (i < env->number_of_philosophers)
	{
		(*parameters)[i].env = env;
		(*parameters)[i].id = i;
		(*parameters)[i].last_eat_time = 0;
		(*parameters)[i].count_eat = 0;
		i++;
	}
	return (0);
}

void	free_parameters(t_parameter **parameters)
{
	free(*parameters);
	*parameters = NULL;
}
