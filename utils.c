/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:33:11 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/09/12 19:29:47 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	ft_atol(char *str)
{
	int		i;
	long	n;

	i = 0;
	n = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = ((n * 10) + (str[i] - '0'));
		i++;
	}
	return (n);
}


int	input_checker(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == ' ')
				j++;
			if ((argv[i][j] < 48 || argv[i][j] > 57))
				print_error(2);
			j++;
		}
		i++;
	}
	return (1);
}

int	waiting(t_philos philo, long time)
{
	long	n;

	n = time / 100;
	while (n > 0)
	{
		usleep(100);
		if (check_grim_reaper(philo) == -1)
			return (0);
		n--;
	}
	return (1);
}