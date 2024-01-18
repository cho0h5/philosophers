/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Youngho Cho <younghoc@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:01:54 by Youngho Cho       #+#    #+#             */
/*   Updated: 2024/01/18 16:03:25 by Youngho Cho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	*philosophers(void *arg)
{
	printf("%s\n", (char *)arg);
	return (NULL);
}

int	main(void)
{
	pthread_t	p1;
	pthread_t	p2;

	pthread_create(&p1, NULL, philosophers, "A");
	pthread_create(&p2, NULL, philosophers, "B");
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	return (0);
}
