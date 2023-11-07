/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:53:20 by alperrot          #+#    #+#             */
/*   Updated: 2023/09/06 23:22:07 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp[size];
	int	i;

	temp = tab;
	while (size >= 0)
	{
		tab[size] = temp[i];
		i++;
		size--;
	}
}
#include <stdio.h>
int	main(void)
{
	int	tab[3];
	int	size;
	int	i;

	size = 3;
	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 3;
	ft_rev_int_tab(tab, size);
	i = 0;
	while (size > 0)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}
