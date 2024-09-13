/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:24:52 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/09/13 11:18:37 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	print_error(int n, t_table **array)
{
	if (n == 1)
		printf("Error: Philosophers can't be more than 200\n");
	else if (n == 2)
		printf("Error: invalid arguments\n");
	else if (n == 3)
	{
		printf("Error: malloc failed.\n");
		free(array);
	}
	else if (n == 4)
		printf("Error: pthread failed.\n");
	return (-1);
}