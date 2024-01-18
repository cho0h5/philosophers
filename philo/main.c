/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Youngho Cho <younghoc@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:01:54 by Youngho Cho       #+#    #+#             */
/*   Updated: 2024/01/18 16:18:38 by Youngho Cho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	*philosophers(void *arg)
{
	pthread_mutex_lock(arg);
	printf("children\n");
	pthread_mutex_unlock(arg);
	return (NULL);
}

int	main(void)
{
	pthread_t		p1;
	pthread_t		p2;
	pthread_mutex_t	mutex;

	pthread_mutex_init(&mutex, NULL);
	pthread_create(&p1, NULL, philosophers, &mutex);
	pthread_create(&p2, NULL, philosophers, &mutex);
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	return (0);
}
