/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truth_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:47:54 by alperrot          #+#    #+#             */
/*   Updated: 2023/08/27 16:43:02 by nberduck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	ft_check(char *table, char *nb, int *i)
{
	if (nb[0] != nb[1] && nb[0] != nb[2] && nb[0] != nb[3] &&
		nb[1] != nb[2] && nb[1] != nb[3] && nb[2] != nb[3])
	{
		table[0] = nb[0];
		table[1] = nb[1];
		table[2] = nb[2];
		table[3] = nb[3];
		i[0]++;
	}
}

char	**ft_generate(char **table, char *nb, int *i)
{
	while (nb[0] <= '4')
	{
		while (nb[1] <= '4')
		{
			while (nb[2] <= '4')
			{
				while (nb[3] <= '4')
				{
					ft_check(table[i[0]], nb, i);
					nb[3]++;
				}
				nb[3] = '1';
				nb[2]++;
			}
			nb[2] = '1';
			nb[1]++;
		}
		nb[1] = '1';
		nb[0]++;
	}
	return (table);
}

char	**ft_init(void)
{
	char	**table;
	int		*i;
	char	value[4];

	table = malloc(256 + 1);
	i = (int *)malloc(8);
	i[0] = 0;
	while (i[0] < 24)
	{
		table[i[0]] = malloc(4 + 1);
		i[0]++;
	}
	i[0] = 0;
	value[0] = '1';
	value[1] = '1';
	value[2] = '1';
	value[3] = '1';
	return (ft_generate(table, value, i));
}
