#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include "philo_one.h"

int	ft_atoi(const char *str)
{
	int i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' ' ||
			str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] != '\0' && '0' <= str[i] && str[i] <= '9')
	{
		result = result * 10;
		result = result + str[i] - '0';
		i++;
	}
	result = result * sign;
	return (result);
}

void print_time_stamp(struct timeval start)
{
	int msec;
	struct timeval end;

	gettimeofday(&end, NULL);
	msec = (end.tv_sec-start.tv_sec)*1000+(end.tv_usec - start.tv_usec)/1000;
	printf("time_stamp : %dms\n", msec);
}

int is_number_check(t_init *init, char **argv)
{
	int i;

	i = 0;
	if ((init->num = ft_atoi(argv[1])) < 1)
		return (1);
	if ((init->die = ft_atoi(argv[2])) < 1)
		return (1);
	if ((init->eat = ft_atoi(argv[3])) < 1)
		return (1);
	if ((init->sleep = ft_atoi(argv[4])) < 1)
		return (1);
	if (argv[5] != NULL)
	{
		init->eat_f = ft_atoi(argv[5]);
		if (init->eat_f < 1)
			return (1);
	}
	else
		init->eat_f = -1;
	return (0);
}

void *test_philo(void *arg)
{
	t_philo *ph;

	ph = (t_philo *)arg;
	printf("hello~ im No.%d\n", ph->num);
	printf("No.%d is eating\n", ph->num);
	printf("No.%d is sleeping\n", ph->num);
	return (0);
}

int create_philo_thread(t_philo *ph, t_init init)
{
	int i;
	int ret;

	i = 0;
	while (i < init.num)
	{
		ph->num = i + 1;
		ret = pthread_create(&ph->tid, NULL, test_philo, ph);
		ph++;
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	struct timeval start;
	t_init init;
	t_philo *ph;
	int i;
	pthread_mutex_t mutex;

	i = 0;
	if (argc < 5 || 6 < argc)
		return (1);
	if (is_number_check(&init, argv))
		return (1);
	if(!(ph = (t_philo *)malloc(sizeof(t_philo) * init.num)))
		return (1);
	create_philo_thread(ph, init);

	gettimeofday(&start, NULL);
	sleep(1);
	print_time_stamp(start);

	return (0);
}