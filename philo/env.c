#include "philo.h"
#include <stdlib.h>

void	init_env(t_env *env)
{
	int	i;

	env->philosophers = malloc(sizeof(pthread_t) * env->number_of_philosophers);
	env->forks = malloc(sizeof(t_fork) * env->number_of_philosophers);
	if (env->philosophers == NULL || env->forks == NULL)
		panic("failed to malloc");
	i = 0;
	while (i < env->number_of_philosophers)
	{
		if (init_fork(&env->forks[i])!= 0)
			panic("failed to initialize mutex");
		i++;
	}
	if (pthread_mutex_init(&env->mutex_ready, NULL)
		|| pthread_mutex_init(&env->mutex_starve, NULL))
		panic("failed to initiliaze mutex");
	pthread_mutex_lock(&env->mutex_ready);
	env->is_someone_starved = 0;
}

void	free_env(t_env *env)
{
	free(env->philosophers);
	free(env->forks);
	env->philosophers = NULL;
	env->forks = NULL;
}
