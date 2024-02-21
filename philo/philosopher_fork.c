/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:44:22 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/21 11:30:59 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

static t_fork	*left_fork(t_parameter *const param)
{
	const int	id_fork = param->id;

	return (&param->env->forks[id_fork]);
}

static t_fork	*right_fork(t_parameter *const param)
{
	const int	id_fork = (param->id + 1) % param->env->number_of_philosophers;

	return (&param->env->forks[id_fork]);
}

int	take_forks(t_parameter *const param)
{
	while (try_lock_fork(left_fork(param)))
	{
		check_me_starve(param);
		if (check_someone_starve(param))
			return (-1);
		usleep(100);
	}
	print_fork(param);
	while (try_lock_fork(right_fork(param)))
	{
		check_me_starve(param);
		if (check_someone_starve(param))
			return (-1);
		usleep(100);
	}
	print_fork(param);
	return (0);
}

void	release_forks(t_parameter *const param)
{
	unlock_fork(left_fork(param));
	unlock_fork(right_fork(param));
}
