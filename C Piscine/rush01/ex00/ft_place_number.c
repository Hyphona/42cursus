/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberduck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:26:32 by nberduck          #+#    #+#             */
/*   Updated: 2023/08/27 15:20:58 by nberduck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_write.c"

char	ft_number_selector(char *str, int n);
char	**ft_init(void);
void	ft_write(char **str);

char	*ft_first_possibility(char view)
{
	char	**list;

	list = ft_init();
	if (view == 4)
		return (list[0]);
	if (view == 3)
		return (list[1]);
	if (view == 2)
		return (list[4]);
	if (view == 1)
		return (list[18]);
	return (0);
}

void	ft_placement(char view, char **tab, int j)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_first_possibility(view);
	while (i < 4)
	{
		tab[j][i] = str[i];
		i++;
	}
}

void	ft_place_number(char *views)
{
	char	**tab;
	int	i;
	int	n;
	int	j;

	tab = malloc (256);
	j = 0;
	i = 0;
	n = 5;
	i = 0;
	while (i < 4)
	{
		tab[i] = malloc(256);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		ft_placement(ft_number_selector(views, n), tab, j);
		i++;
		n += 2;
		j++;
	}
	ft_write(tab);
	free(tab);
	
}

