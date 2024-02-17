/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_die.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:40:18 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/17 12:40:20 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_me_starve(t_parameter *const param)
{
	if (get_time() - param->last_eat_time > param->env->time_to_die)
	{
		print_died(param);
		return (1);
	}
	return (0);
}
