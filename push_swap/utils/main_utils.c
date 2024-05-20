/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:03:09 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/20 13:01:36 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	error(t_stack **s)
{
	free_stack(*s);
	write(2, "Error\n", 6);
	exit(0);
}

long ft_atoi(const char *str, t_stack **s)
{
	long n;
	int i;
	int neg;

	i = 0;
	n = 0;
	neg = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	n *= neg;
	if (n > 2147483647 || n < -2147483648)
		error(s);
	return (n);
}

int	check_args(char **av)
{
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-' || av[i][j] == '+')
			{
				if (!(av[i][j + 1] < '9') && !(av[i][j + 1] > '0'))
					return (0);
				j++;
			}
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
			{
				if (!is_space(av[i][j]))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
