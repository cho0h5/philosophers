/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:56:23 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/13 15:56:23 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

long long	get_time(void)
{
	struct timeval	tv;
	long long		us;

	gettimeofday(&tv, NULL);
	us = tv.tv_sec * 1000000 + tv.tv_usec;
	return (us);
}
