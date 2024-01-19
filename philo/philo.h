/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:52:11 by Youngho Cho       #+#    #+#             */
/*   Updated: 2024/01/19 14:33:15 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

# define NOT_INT 900000000000

#include <stdio.h>

typedef struct s_fork
{
	int				is_available;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct	s_env
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_must_eat;
	pthread_t		*philosophers;
	t_fork			*forks;
}	t_env;


typedef struct	s_philosopher
{
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_must_eat;	// 필요한가?
	t_fork			*left_fork;
	t_fork			*right_fork;
}	t_philosopher;

long long	parse_int(char *str);

size_t	ft_strlen(const char *s);

long long get_time_in_ms();

#endif
