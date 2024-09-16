/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   living.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:07:12 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/09/16 14:27:52 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	philo_sleep(t_philos *philo)
{
	if (check_grim_reaper(philo) == -1)
		return (0);
	lets_print(philo, (*philo).id, SLEEPING);
	waiting(philo, (*philo).table->time_to_sleep);
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
	pthread_mutex_lock((*philo).l_fork);
	if (check_grim_reaper(philo) == -1)
	{
		pthread_mutex_unlock((*philo).r_fork);
		pthread_mutex_unlock((*philo).l_fork);
		return (0);
	}
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
	(*philo).last_meal = timeset();
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
	return (1);
}

int	survival(t_philos *philo)
{
	philo->last_meal = philo->table->start_time;
	if (philo->id % 2 == 0)
		philo_sleep(philo);
	while (1 + 1 != 7)
	{
		if (philo_fork(philo) == 0)
			return (0);
		if (philo_eat(philo) == 0)
			return (0);
		if (check_grim_reaper(philo) == -1)
			return (0);
		philo_sleep(philo);
	}
	return (1);
}

int	check_grim_reaper(t_philos	*philo)
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
		printf("%lu %ld %s\n", timeset() - (*philo).table->start_time,
			(*philo).id, DIED);
		pthread_mutex_unlock(&(*philo).table->print);
		return (-1);
	}
	pthread_mutex_unlock(&(*philo).table->print);
	return (0);
}
