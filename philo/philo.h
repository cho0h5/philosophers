/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:26:20 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/12 19:26:21 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

# define NOT_INT (900000000000)

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				owner;
	int				is_available;
}	t_fork;

typedef struct s_env
{
	long long	start_time;
	long long	number_of_philosophers;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	long long	number_of_must_eat;
	pthread_t	*philosophers;
	t_fork		*forks;
}	t_env;

typedef struct s_parameter
{
	t_env		*env;
	int			id;
	long long	last_eat_time;
	long long	count_eat;
}	t_parameter;

void	*philosopher(void *arg);

int			init_fork(t_fork *fork);

size_t		ft_strlen(const char *s);
long long	parse_int(char *str);
void		panic(char *error_message);

#endif
