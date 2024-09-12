/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:33:11 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/09/12 16:26:55 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_atol(char *str)
{
	long int	n;
	int			sign;
	long int	i;

	n = 0;
	sign = 1;
	i = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '-')
		return (-1);
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			n = n * 10 + (str[i]++ - '0');
		else
			return (-1);
	}
	return (n * sign);
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