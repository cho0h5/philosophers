/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:54:09 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/12 19:54:10 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int	init_fork(t_fork *fork)
{
	fork->is_available = 1;
	return (pthread_mutex_init(&fork->mutex, NULL));
}
