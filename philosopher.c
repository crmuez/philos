/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:15:52 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/09/13 13:25:18 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char **argv)
{
	t_table		*table;
	t_philos	*philos;

	if (argc < 5 || argc > 6 || (input_checker(argv) == 0))
		print_error(2, NULL);
	init_table(argv, &table);
	init_philo(&philos, table);;
	create_threads(table, philos);
	join_threads(table, philos);
	return (0);
}
/*
	- input_checker(argv)
	
	init
	philo_num == 1¿?

*/