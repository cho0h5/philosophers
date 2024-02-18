/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:55:33 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/13 15:55:34 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_argument(int argc, char **argv, t_env *env)
{
	env->philosophers = NULL;
	env->forks = NULL;
	if (argc != 5 && argc != 6)
		return (panic("invalid argument"));
	env->number_of_philosophers = parse_int(argv[1]);
	env->time_to_die = parse_int(argv[2]);
	env->time_to_eat = parse_int(argv[3]);
	env->time_to_sleep = parse_int(argv[4]);
	if (argc == 5)
		env->number_of_must_eat = -1;
	else if (argc == 6)
		env->number_of_must_eat = parse_int(argv[5]);
	else
		return (panic("invalid argument"));
	if (env->number_of_philosophers == NOT_INT
		|| env->time_to_die == NOT_INT
		|| env->time_to_eat == NOT_INT
		|| env->time_to_sleep == NOT_INT
		|| env->number_of_must_eat == NOT_INT)
		return (panic("invalid argument"));
	env->time_to_die *= 1000;
	env->time_to_eat *= 1000;
	env->time_to_sleep *= 1000;
	return (0);
}
