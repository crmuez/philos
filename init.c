/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:02:16 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/09/11 16:36:39 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	init_table(char **argv, t_table **table)
{
	long i;

	i = 0;
	(*table) = malloc(sizeof(t_table));
	if (!*table)
		exit (-1);
	(*table)->philos = ft_atol(argv[1]);
	if ((*table)->philos > 200)
	{
		printf("Error: Philosophers can't be more than 200\n");
		exit(-1);
	}
	(*table)->time_to_dead = (ft_atol(argv[2]) * 1000);
	(*table)->time_to_eat = (ft_atol(argv[3]) * 1000);
	(*table)->time_to_sleep = (ft_atol(argv[4]) * 1000);
	if (argv[5])
		(*table)->n_meals = ft_atol(argv[5]);
	else
		(*table)->n_meals = -1;
	while (i < (*table)->philos)
	{
		pthread_mutex_init(&(*table)->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&(*table)->print, NULL);
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
		(*philos)[i].id = i;
		(*philos)[i].meals_done = 0;
		(*philos)[i].table = table;
		(*philos)[i].r_fork = table->forks[i];
		(*philos)[i].l_fork = table->forks[(i + 1) % table->philos];
		//pthread_create((*philos)[i].thread, NULL, hacercosas, (void *) (philos)[i]);	
		i++;
	}
}

