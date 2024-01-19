/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:58:10 by younghoc          #+#    #+#             */
/*   Updated: 2024/01/19 19:00:30 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long   get_time_in_ms(void)
{
    struct timeval  tv;
    long long       ms;

    gettimeofday(&tv, NULL);
    ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    return (ms);
}

void	msleep(unsigned int ms)
{
    long long   start_time;

    start_time = get_time_in_ms();
    while (get_time_in_ms() - start_time < ms)
        usleep(100);
}
