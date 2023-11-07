/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truth_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:47:54 by alperrot          #+#    #+#             */
/*   Updated: 2023/08/26 22:30:58 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

int	check(char a, char b, char c, char d)
{
	if (a != b && a != c && a != d
		&& b != c && b != d
		&& c != d)
		return (1);
	return (0);
}

void	generate(char **table, char *nb)
{
	int	i;

	i = 0;
	while (nb[0] <= '4')
	{
		while (nb[1] <= '4')
		{
			while (nb[2] <= '4')
			{
				while (nb[3] <= '4')
				{
					if (check(nb[0], nb[1], nb[2], nb[3]))
					{
						table[i][0] = nb[0];
						table[i][1] = nb[1];
						table[i][2] = nb[2];
						table[i][3] = nb[3];
						i++;
					}
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
}

int	main(void)
{
	char	**table;
	char	nb[4];
	int	i;

	i = 0;
	nb[0] = '1';
	nb[1] = '1';
	nb[2] = '1';
	nb[3] = '1';
	//Un malloc de 24 Octets (24 possibilitees) + 1 pour le null byte
	table = malloc((168 * 1) + 1);
	while (i <= 24)
	{
		//Un malloc de 24 * 4 octets (les 4 characteres des 24
		// possibilitees)+ 1 en prolongement du premier malloc
		table[i] = malloc((4) + 1);
		i++;
	}
	i = 0;
	generate(table, nb);
	//Pour voir le tab
	/*
	while (table[i])
	{
		write (1, table[i], 4);
		write (1, "\n", 1);
		i++;
	}
	*/
	free(table);
}
