/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:00:27 by alperrot          #+#    #+#             */
/*   Updated: 2023/09/03 22:37:41 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

int	ft_atoi(char *str);
int	ft_count_line(char *dist);

int	ft_recursive_power(long long int nbr, int power)
{
	if (power == 0)
		return (1);
	else
		return (nbr * ft_recursive_power(nbr, power - 1));
}

int	ft_nbrlen(char *nbr)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (nbr[i] != '\n')
	{
		counter++;
		i++;
	}
	return (counter);
}

void	ft_putchar(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	find(char *dict, char *to_find)
{
	int	i;
	int	counter;
	int	find_len;

	i = 0;
	counter = 0;
	find_len = ft_nbrlen(to_find);
	while (dict[i++])
	{
		if (dict[i] == to_find[counter])
		{
			if (dict[i - 1] == '\n')
			{
				while (to_find[counter++] != '\n')
				{
					if (to_find[counter] == dict[i + counter])
						if (counter == (find_len - 1)
							&& dict[i + counter + 1] == '\n')
							ft_putchar(&dict[i + counter + 2]);
				}
				counter = 0;
			}
		}
	}
}

void	solve(int nbr, char *dict, int len)
{
	int		mod;
	int		result;
	char	test[3];

	test[0] = '1';
	test[1] = '0';
	test[2] = '\n';
	mod = nbr / ft_recursive_power(10, (len - 1));
	find(dict, test);
	result = mod * ft_recursive_power(10, (len - 1));
	result = result / mod;
	free(dict);
}
