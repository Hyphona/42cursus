/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberduck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:37:17 by nberduck          #+#    #+#             */
/*   Updated: 2023/08/27 15:19:37 by nberduck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

void	ft_write(char **str);
void	ft_place_number(char *views);
int	ft_verif_start(char *str);
/*
void	ft_view(char *av, char **t)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		
		if (i >= 0 && i <= 8)
			t[0][j] = av[i];
		else if (i >= 10 && i <= 16)
			t[1][j] = av[i];
		else if (i >= 18 && i <= 24)
			t[2][j] = av[i];
		else if (i >= 26 && i <= 32)
			t[3][j] = av[i];
		if(j == 8 || j == 16 || j == 24 || j == 32)
			j = 0;
		i += 2;
		j++;
	}
}
*/

int	ft_num_settings(char *av)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 1;
	n = 0;
	while (av[i])
	{
		if (av[i] >= '1' && av[i] <= '4' && j == 1)
		{
			n++;
			j = 0;
		}
		else if (av[i] == ' ' && j == 0)
			j = 1;
		else
			return (0);
		i++;
	}
	return (n);
}

int	main(int ac, char **av)
{
	//char	**tab;
	//int		i;

	//i = 0;
	//tab = malloc(4 * 4 * 1);
	//while (i < 8)
	//{
	//	tab[i] = malloc(4 + 1);
	//	i++;
	//}
	//if (tab == NULL)
	//	exit(0);
	if (ft_num_settings(av[1]) == 16 && ac == 2 && ft_verif_start(av[1]) == 1)
		ft_place_number(av[1]);
	else
		write(1, "Error\n", 7);
	return (0);
}
