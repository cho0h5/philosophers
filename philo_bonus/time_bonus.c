/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:43:45 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/21 11:32:43 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <sys/time.h>
#include <stdlib.h>

long long	get_time(void)
{
	struct timeval	tv;
	long long		us;

	gettimeofday(&tv, NULL);
	us = tv.tv_sec * 1000000 + tv.tv_usec;
	return (us);
}
