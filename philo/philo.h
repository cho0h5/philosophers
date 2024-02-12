/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Youngho Cho <younghoc@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:52:11 by Youngho Cho       #+#    #+#             */
/*   Updated: 2024/01/19 19:35:21 by Youngho Cho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define NOT_INT 900000000000

typedef struct s_fork
{
	int				owner;
	int				is_available;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_env
{
	long long		start_time;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_must_eat;
	pthread_t		*philosophers;
	t_fork			*forks;
	pthread_mutex_t	mutex_wait;
	pthread_mutex_t	mutex_print;
	int				mutex_is_die;
	pthread_mutex_t	mutex_die;
}	t_env;

typedef struct s_philosopher
{
	int			id;
	long long	last_eat_time;
	long long	eat_count;
	t_env		*env;
}	t_philosopher;

typedef enum e_state
{
	THINKING,
	EATING,
	SLEEPING,
}	t_state;

long long	parse_int(char *str);

size_t		ft_strlen(const char *s);

long long	get_time_in_ms(void);
void		msleep(unsigned int ms);

int			take_fork(t_fork *fork, t_env *env, int id);
void		release_fork(t_fork *fork);
t_fork		*get_left_fork(t_philosopher *philo);
t_fork		*get_right_fork(t_philosopher *philo);

void		print_fork(int id, t_env *env);
void		print_eating(int id, t_env *env);
void		print_sleeping(int id, t_env *env);
void		print_thinking(int id, t_env *env);
void		print_died(int id, t_env *env);

void		*philosopher(void *arg);

#endif
