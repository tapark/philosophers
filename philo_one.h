# ifndef PHILO_ONE_H
# define PHILO_ONE_H

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct	s_init
{
	int			num;
	int			die;
	int			eat;
	int			sleep;
	int			eat_f;
}				t_init;

typedef struct	s_philo
{
	int			num;
	pthread_t	tid;
}				t_philo;
#endif