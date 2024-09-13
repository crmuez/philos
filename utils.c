/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:33:11 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/09/13 16:30:58 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	ft_atol(char *str)
{
	int		i;
	long	n;

	i = 0;
	n = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = ((n * 10) + (str[i] - '0'));
		i++;
	}
	return (n);
}


int	input_checker(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == ' ')
				j++;
			if ((argv[i][j] < 48 || argv[i][j] > 57))
				print_error(2, NULL);
			j++;
		}
		i++;
	}
	if (ft_atol(argv[1]) > 200)
		print_error(1, NULL);
	return (1);
}

int	waiting(t_philos *philo, long time)
{
	long	start;

	start = timeset();
	while ((timeset() - start) < time)
	{
		//printf("tiempo: %ld\n", timeset() - start);
		usleep(100);
		if (check_grim_reaper(philo) == -1)
			return (0);
	}
	return (1);
}

int	lets_print(t_philos	*philo, long id, char *status)
{
	pthread_mutex_lock(&(*philo).table->print);
	if ((*philo).table->death > 0)
	{
		pthread_mutex_unlock(&(*philo).table->print);
		return (-1);
	}
	if ((timeset() - philo->last_meal) > philo->table->time_to_dead)
	{
		(*philo).table->death = 1;
		printf("%lu %ld %s\n", timeset() - (*philo).table->start_time, (*philo).id, DIED);
		pthread_mutex_unlock(&(*philo).table->print);
		return (-1);
	}
	printf("%lu %ld %s\n", timeset() - (*philo).table->start_time, id, status);
	pthread_mutex_unlock(&(*philo).table->print);
	return (0);
}