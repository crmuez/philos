/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:15:52 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/09/12 20:46:30 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char **argv)
{
	t_table		*table;
	t_philos	*philos;
	long		i;

	i = 0;
	write(1, "1\n", 2);
	if (argc < 5 || argc > 6 || (input_checker(argv) == 0))
		print_error(2);
	write(1, "2\n", 2);
	init_table(argv, &table);
	write(1, "3\n", 2);
	init_philo(&philos, table);
	write(1, "4\n", 2);
	timeset();
	write(1, "5\n", 2);
	//printf("%ld", table->philos);
	create_threads(table, philos);
	while (i < table->philos)
	{
		write(1, "6\n", 2);
		join_threads(table, philos);
		i++;
	}
		write(1, "7\n", 2);
	return (0);
}
/*
	- input_checker(argv)
	
	init
	philo_num == 1¿?

*/