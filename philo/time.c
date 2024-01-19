/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:58:10 by younghoc          #+#    #+#             */
/*   Updated: 2024/01/19 14:03:43 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long   get_time_in_ms()
{
    struct timeval  tv;
    long long       ms;

    gettimeofday(&tv, NULL);
    ms = tv.tv_sec * 1000LL + tv.tv_usec / 1000;
    return (ms);
}
