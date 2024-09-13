/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:18:40 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/09/13 16:01:15 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <fcntl.h>
# include <pthread.h>

# define FORK "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIED "died"

typedef struct s_timeval
{
	time_t		tv_sec;
	suseconds_t	tv_usec;
}				t_timeval;

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
	long			start_time;
}					t_table;

typedef struct s_philos
{
	long			id;
	pthread_t		thread;
	t_table			*table;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	long			meals_done;
	long			last_meal;
}					t_philos;

/* UTILS */
int		input_checker(char **argv);
long	ft_atol(char *str);
int		waiting(t_philos *philo, long time);
int		lets_print(t_philos	*philo, long id, char *status);

/* INIT */
void	init_table(char **argv, t_table **table);
void	init_philo(t_philos **philos, t_table *table);
long	timeset(void);
int		join_threads(t_table *table, t_philos *philos);
int		create_threads(t_table *table, t_philos *philos);

/* LIVING */
int		philo_sleep(t_philos *philo);
int		philo_think(t_philos *philo);
int		philo_eat(t_philos *philo);
int		survival(t_philos *philo);
int		check_grim_reaper(t_philos	*philo);

/* ERROR */
int		print_error(int n, t_table **array);

#endif