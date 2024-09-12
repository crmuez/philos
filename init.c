/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:02:16 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/09/12 20:45:10 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	init_table(char **argv, t_table **table)
{
	long i;

	i = 0;
	(*table) = malloc(sizeof(t_table));
	if (!(*table))
		print_error(3);
	(*table)->philos = ft_atol(argv[1]);
	printf("%ld", (*table)->philos);
	(*table)->forks = malloc (sizeof(pthread_mutex_t) * (*table)->philos);
	if ((*table)->philos > 200)
		print_error(1);
	(*table)->time_to_dead = (ft_atol(argv[2]) * 1000);
	(*table)->time_to_eat = (ft_atol(argv[3]) * 1000);
	(*table)->time_to_sleep = (ft_atol(argv[4]) * 1000);
	(*table)->death = 0;
	if (argv[5])
		(*table)->n_meals = ft_atol(argv[5]);
	else
		(*table)->n_meals = -1;
	pthread_mutex_init(&(*table)->print, NULL);
	while (i < (*table)->philos)
	{
		pthread_mutex_init(&((*table)->forks[i]), NULL);
		i++;
	}
}

long	timeset(void)
{
	struct timeval current_time;
	long	miliseconds;
	gettimeofday(&current_time, NULL);
	miliseconds = (current_time.tv_sec*1000) + (current_time.tv_usec/1000);
	return (miliseconds);
}

void	init_philo(t_philos **philos, t_table *table)
{
	long	i;

	i = 0;
	(*philos) = malloc(sizeof(t_philos) * table->philos);

	table->start_time = timeset();
	while(i < (table->philos))
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].meals_done = 0;
		(*philos)[i].table = table;
		(*philos)[i].r_fork = table->forks[i];
		(*philos)[i].l_fork = table->forks[(i + 1) % table->philos];
		i++;
	}
}
int	join_threads(t_table *table, t_philos *philos)
{
	long	i;

	i = 0;
	while (i < table->philos)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			print_error(4);
		i++;
	}
	return (0);
}

int	create_threads(t_table *table, t_philos *philos)
{
	int	i;

	i = 0;
	while (i < table->philos)
	{
		if ((pthread_create(&philos[i].thread, NULL, (void *) &survival, (void *) &philos[i])) != 0)
			print_error(4);
		i++;
	}
	return (0);
}
