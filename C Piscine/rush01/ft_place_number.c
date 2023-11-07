/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberduck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:26:32 by nberduck          #+#    #+#             */
/*   Updated: 2023/08/27 14:16:35 by nberduck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
char ft_number_selector(char *str,int n);
char **ft_init();

char	ft_first_possibility(char view)
{
	char **list;
	list = ft_init();
	if(view == 4)
		return list[0];
	if(view == 3)
		return list[1];
	if(view == 2)
		return list[4];
	if(view == 1)
		return list[18];
}

void ft_placement(char view, int **tab, int j)
{
	char *str;
	int	i;

	i = 0;
	str = ft_first_possibility(view);
	while(i < 4)
	{
		tab[j][i] = str[i];
		i++;
	}
}

void	ft_place_number(char	views)
{
	int	**tab;
	tab = malloc (4 * 4 * 1 + 1);

	int	i;
	int	n;
	int	j;

	j = 0;
	i = 0;
	n = 5;
	while (i < 4)
	{
		ft_placement(ft_number_selector(views,n), tab, j);
		i++;
		n += 2;
		j++;
	}
	free(tab);
}
