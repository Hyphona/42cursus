/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberduck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:30:25 by nberduck          #+#    #+#             */
/*   Updated: 2023/08/26 11:50:22 by nberduck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_verif_start_return(int tab)
{
	if (tab > 31 && tab < 37)
		return (1);
	return (0);
}

int	ft_verif_start_find(char str)
{
	int	tab;

	tab = 0;
	if (str == '1')
		tab++;
	if (str == '2')
		tab += 2;
	if (str == '3')
		tab += 3;
	if (str == '4')
		tab += 4;
	return (tab);
}

int	ft_verif_start(char *str)
{
	int	i;
	int	tab;

	i = 0;
	tab = 0;
	while (i < 32)
	{
		tab += ft_verif_start_find(str[i]);
		i += 2;
	}
	return (ft_verif_start_return(tab));
}
/*#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	(void)ac;
	if (ft_verif_start(av[1]) == 1)
		printf("%s", "OK");
	else
		printf("%s", "TAMERE");
	return (0);
}*/
