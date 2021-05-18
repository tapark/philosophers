# ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0

typedef struct	s_rule
{
	int			num;
	int			die;
	int			eat;
	int			sleep;
	int			eat_f;
}				t_rule;

typedef struct		s_philo
{
	int				name;
	int				count_meal;
	int				alive;
	pthread_t		tid;
	pthread_mutex_t	fork;
	t_rule			*rule;
}					t_philo;

int is_number_check(t_rule *rule, char **argv);

#endif