#include "philo.h"
#include <sys/time.h>

long long	get_time(void)
{
	struct timeval	tv;
	long long		us;

	gettimeofday(&tv, NULL);
	us = tv.tv_sec * 1000000 + tv.tv_usec;
	return (us);
}
