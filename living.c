/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   living.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:07:12 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/09/12 16:33:20 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	philo_sleep(t_philos philo)
{
	if (check_grim_reaper(philo) == -1)
		return (0);
	pthread_mutex_lock(&philo.table->print);
	printf("%lu %ld %s\n", philo.table->start_time, philo.id, SLEEPING);
	pthread_mutex_unlock(&philo.table->print);
	waiting(philo, philo.table->time_to_sleep);
	return (1);
}

int	philo_think(t_philos philo)
{
	if (check_grim_reaper(philo) == -1)
		return (-1);
	pthread_mutex_lock(&philo.table->print);
	printf("%lu %ld %s\n", philo.table->start_time, philo.id, THINKING);
	pthread_mutex_unlock(&philo.table->print);
	if (check_grim_reaper(philo) == -1)
		return (0);
	return (1);
}
int	philo_eat(t_philos philo)
{
	pthread_mutex_lock(&philo.l_fork);
	pthread_mutex_lock(&philo.table->print);
	printf("%lu %ld %s\n", philo.table->start_time, philo.id, FORK);
	pthread_mutex_unlock(&philo.table->print);
	pthread_mutex_lock(&philo.r_fork);
	pthread_mutex_lock(&philo.table->print);
	printf("%lu %ld %s\n", philo.table->start_time, philo.id, FORK);
if (check_grim_reaper(philo) == -1)
		return (0);
	philo.last_meal = timeset;
	printf("%lu %ld %s\n", philo.table->start_time, philo.id, EATING);
	pthread_mutex_unlock(&philo.table->print);
	waiting(philo, philo.table->time_to_eat);
	pthread_mutex_unlock(&philo.l_fork);
	pthread_mutex_unlock(&philo.r_fork);
	philo.meals_done++;
	return (1);
}

int survival(t_philos philo)
{
	philo_eat(philo);
	if (check_grim_reaper(philo) == -1)
		return (0);
	philo_sleep(philo);
	return (1);
}

int	check_grim_reaper(t_philos	philo)
{
	if (philo.last_meal + philo.table->time_to_dead < timeset() || philo.table->death > 0)
	{
		pthread_mutex_lock(&philo.table->print);
		philo.table->death = 1;
		printf("%lu %ld %s\n", philo.table->start_time, philo.id, DIED);
		pthread_mutex_unlock(&philo.table->print);
		return (-1);
	}
	return (0);
}