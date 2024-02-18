/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:07:05 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/15 20:07:06 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <pthread.h>

int	main(int argc, char **argv)
{
	t_env		env;
	t_parameter	*parameters;

	parse_argument(argc, argv, &env);
	init_env(&env);
	init_parameters(&env, &parameters);
	spawn_philosophers(&env, parameters);
	wait_philosophers(&env);
	free_parameters(&parameters);
	destroy_env(&env);
	unlink_semaphores();
}
