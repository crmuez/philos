/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   survival.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:31:23 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/09/19 13:24:29 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	waiting(t_philos *philo, long time)
{
	long	start;

	start = timeset();
	while ((timeset() - start) < time)
	{
		usleep(100);
		if (check_grim_reaper(philo) == -1)
			return (0);
	}
	return (1);
}

int	keep_survival(t_philos *philo)
{
	if (philo_eat(philo) == 0)
		return (0);
	if (check_grim_reaper(philo) == -1)
		return (0);
	philo_sleep(philo);
	if (check_grim_reaper(philo) == -1)
		return (0);
	if (philo->table->philos % 2 == 1)
		waiting(philo, (*philo).table->time_to_eat);
	return (1);
}

int	survival(t_philos *philo)
{
	philo->last_meal = philo->table->start_time;
	if (philo->id % 2 == 0)
		waiting(philo, (*philo).table->time_to_eat);
	while (1 + 1 != 7)
	{
		if (check_grim_reaper(philo) == -1)
			return (0);
		if (philo->id == (philo->table->philos))
		{
			if (last_philo_fork(philo) == 0)
				return (0);
		}
		else
		{
			if (philo_fork(philo) == 0)
				return (0);
		}
		if (keep_survival(philo) == 0)
			return (0);
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
