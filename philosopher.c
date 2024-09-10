/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:15:52 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/09/10 20:19:00 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"



int	main(int argc, char **argv)
{
	t_table		*table;
	t_philos	*philos;

	if (argc < 5 || argc > 6)
		return (printf("Error: invalid arguments\n"));
	if (input_checker(argv) == 0)
		return (printf("Error: invalid arguments\n"));
	else
	{
		init_table(argv, &table);
		init_philo(&philos, table);
	}

}

/*
	- input_checker(argv)
	
	init
	philo_num == 1¿?

*/