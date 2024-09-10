/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:18:40 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/09/10 20:19:51 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <pthread.h>

typedef struct s_table
{
	pthread_mutex_t	*forks;
	long			philos;
	long			time_to_dead;
	long			time_to_eat;
	long			time_to_sleep;
	long			n_meals;
	long			death;
	pthread_mutex_t	print;
}					t_table;

typedef struct s_philos
{
	long			id;
	pthread_t		thread;
	t_table			*table;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	r_fork;
	long			meals_done;
}					t_philos;

/* UTILS */
int	input_checker(char **argv);
int	ft_atol(char *str);

/* PHILOSOPHERS */

/* INIT */
void	init_table(char **argv, t_table **table);
void	init_philo(t_philos **philos, t_table *table);

#endif