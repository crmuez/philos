/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   living.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:07:12 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/09/19 16:57:09 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	philo_sleep(t_philos *philo)
{
	if (check_grim_reaper(philo) == -1)
		return (0);
	lets_print(philo, (*philo).id, SLEEPING);
	waiting(philo, (*philo).table->time_to_sleep);
	if (check_grim_reaper(philo) == -1)
		return (0);
	printf("%lu %ld %s\n", timeset() - (*philo).table->start_time,
		(*philo).id, THINKING);
	return (1);
}

int	last_philo_fork(t_philos *philo)
{
	pthread_mutex_lock((*philo).l_fork);
	if (lets_print(philo, (*philo).id, FORK) == -1)
	{
		pthread_mutex_unlock((*philo).l_fork);
		return (0);
	}
	if (check_grim_reaper(philo) == -1)
	{
		pthread_mutex_unlock((*philo).l_fork);
		return (0);
	}
	pthread_mutex_lock((*philo).r_fork);
	if (lets_print(philo, (*philo).id, FORK) == -1)
	{
		pthread_mutex_unlock((*philo).r_fork);
		pthread_mutex_unlock((*philo).l_fork);
		return (0);
	}
	return (1);
}

int	philo_fork(t_philos *philo)
{
	pthread_mutex_lock((*philo).r_fork);
	if (lets_print(philo, (*philo).id, FORK) == -1)
	{
		pthread_mutex_unlock((*philo).r_fork);
		return (0);
	}
	if (check_grim_reaper(philo) == -1)
	{
		pthread_mutex_unlock((*philo).r_fork);
		return (0);
	}
	pthread_mutex_lock((*philo).l_fork);
	if (lets_print(philo, (*philo).id, FORK) == -1)
	{
		pthread_mutex_unlock((*philo).r_fork);
		pthread_mutex_unlock((*philo).l_fork);
		return (0);
	}
	return (1);
}

int	philo_eat(t_philos *philo)
{
	if (lets_print(philo, (*philo).id, EATING) == -1)
	{
		pthread_mutex_unlock((*philo).r_fork);
		pthread_mutex_unlock((*philo).l_fork);
		return (0);
	}
	waiting(philo, (*philo).table->time_to_eat);
	pthread_mutex_unlock((*philo).l_fork);
	pthread_mutex_unlock((*philo).r_fork);
	(*philo).meals_done++;
	if ((*philo).meals_done == (*philo).table->n_meals)
		return (0);
	(*philo).last_meal = timeset();
	return (1);
}
