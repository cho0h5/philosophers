/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:26:02 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/12 19:26:03 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int	main(int argc, char **argv)
{
	t_env		env;
	t_parameter	*parameters;

	if (parse_argument(argc, argv, &env)
		|| init_env(&env))
	{
		free_env(&env);
		return (1);
	}
	if (init_parameters(&env, &parameters)
		|| spawn_philosophers(&env, parameters))
	{
		free_parameters(&parameters);
		free_env(&env);
		return (1);
	}
	start_simulation(&env);
	join_philosophers(&env);
	free_parameters(&parameters);
	free_env(&env);
}
