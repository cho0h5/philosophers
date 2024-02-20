/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:09:37 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/16 15:09:38 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>

# define NOT_INT 900000000000

typedef struct s_env
{
	long long	start_time;
	long long	number_of_philosophers;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	long long	number_of_must_eat;
	pid_t		*children;
	sem_t		*sem_forks;
	sem_t		*sem_starve;
	sem_t		*sem_print;
}	t_env;

typedef struct s_parameter
{
	t_env		*env;
	int			id;
	long long	last_eat_time;
	long long	count_eat;
}	t_parameter;

void		parse_argument(int argc, char **argv, t_env *env);

void		init_env(t_env *env);
void		destroy_env(t_env *env);
void		unlink_semaphores(void);

void		init_parameters(t_env *env, t_parameter **parameters);
void		free_parameters(t_parameter **parameters);

void		spawn_philosophers(t_env *env, t_parameter *parameters);
void		wait_philosophers(t_env *env);

void		philosopher(t_parameter *const param);
void		philosopher_eat(t_parameter *const param);
void		philosopher_sleep(t_parameter *const param);
int			check_eat_done(t_parameter *const param);
int			check_me_starve(t_parameter *const param);
void		create_die_checker(t_parameter *const param);

int			print_fork(t_parameter *param);
int			print_eating(t_parameter *param);
int			print_sleeping(t_parameter *param);
int			print_thinking(t_parameter *param);
int			print_died(t_parameter *param);

void		take_forks(t_parameter *const param);
void		release_forks(t_parameter *const param);

size_t		ft_strlen(const char *s);
long long	parse_int(char *str);
void		panic(char *error_message);
long long	get_time(void);

#endif
