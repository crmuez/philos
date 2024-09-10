/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:02:16 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/09/10 20:18:26 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	init_table(char **argv, t_table **table)
{
	long i;

	i = 0;
	(*table) = malloc(sizeof(t_table));
	if (!*table)
		exit (1); //escribir función de error
	(*table)->philos = ft_atol(argv[1]);
	(*table)->time_to_dead = ft_atol(argv[2]);
	(*table)->time_to_eat = ft_atol(argv[3]);
	(*table)->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		(*table)->n_meals = ft_atol(argv[5]);
	else
		(*table)->n_meals = -1;
	while (i < (*table)->philos)
	{
		pthread_mutex_init(&(*table)->forks[i], NULL);
		i++;
	}
}

void	init_philo(t_philos **philos, t_table *table)
{
	long	i;

	i = 0;
	(*philos) = malloc(sizeof(t_philos) * table->philos);
	
	while (i <  table->philos)
	{
		(*philos)[i].id = i;
		(*philos)[i].meals_done = 0;
		(*philos)[i].table = table;
		(*philos)[i].r_fork = table->forks[i];
		(*philos)[i].l_fork = table->forks[(i + 1) % table->philos];
		//pthread_create(&philos[i].thread, NULL, hacercosas, (void*) quehaceres);	
		i++;
	}
}