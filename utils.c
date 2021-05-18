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

int is_number_check(t_rule *rule, char **argv)
{
	int i;

	i = 0;
	if ((rule->num = ft_atoi(argv[1])) < 1)
		return (1);
	if ((rule->die = ft_atoi(argv[2])) < 1)
		return (1);
	if ((rule->eat = ft_atoi(argv[3])) < 1)
		return (1);
	if ((rule->sleep = ft_atoi(argv[4])) < 1)
		return (1);
	if (argv[5] != NULL)
	{
		rule->eat_f = ft_atoi(argv[5]);
		if (rule->eat_f < 1)
			return (1);
	}
	else
		rule->eat_f = -1;
	return (0);
}
