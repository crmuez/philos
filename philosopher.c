/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:15:52 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/09/16 14:18:35 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char **argv)
{
	t_table		*table;
	t_philos	*philos;

	if (argc < 5 || argc > 6 || (input_checker(argv) == 0))
		print_error(2, NULL);
	if (ft_atol(argv[1]) == 1)
	{
		printf("0 1 has taken a fork\n");
		printf("%ld 1 died\n", (ft_atol(argv[2]) + 1));
		return (0);
	}
	init_table(argv, &table);
	init_philo(&philos, table);
	create_threads(table, philos);
	join_threads(table, philos);
	return (0);
}
