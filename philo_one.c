#include "philo_one.h"


void eat_process(t_philo **input)
{
	t_philo *ph;

	ph = (*input);
}

void sleep_porcess(t_philo **input)
{
	t_philo *ph;

	ph = (*input);
}

void *philo_process(void *arg)
{
	t_philo *ph;

	ph = (t_philo *)arg;
	printf("hello~ im No.%d\n", ph->name);
	printf("No.%d is eating\n", ph->name);
	printf("No.%d is sleeping\n", ph->name);
	printf("sleeping time : %d\n", ph->rule->sleep);
	return (0);
}

int create_philo_thread(t_philo *ph, t_rule rule)
{
	int i;
	int ret;
	int ret2;

	i = 0;
	while (i < rule.num)
	{
		ph[i].name = i + 1;
		ph[i].rule = &rule;
		ret2 = pthread_mutex_init(&ph[i].fork, NULL);
		ret = pthread_create(&ph[i].tid, NULL, philo_process, ph);
		i++;
		if (ret != 0)
			return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	struct timeval start;
	t_rule rule;
	t_philo *ph;
	int i;
	pthread_mutex_t mutex;

	i = 0;
	if (argc < 5 || 6 < argc)
		return (1);
	if (is_number_check(&rule, argv))
		return (1);
	if (!(ph = (t_philo *)malloc(sizeof(t_philo) * rule.num)))
		return (1);
	if (create_philo_thread(ph, rule))
		return (1);

	gettimeofday(&start, NULL);
	usleep(1000);

	return (0);
}