/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 00:57:54 by alperrot          #+#    #+#             */
/*   Updated: 2023/09/06 19:38:23 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_output(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '9' && str[1] == '8' && str[2] == '9' && str[3] == '9')
	{
		write(1, "98 99\n", 6);
		return ;
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		if (i == 1)
			write(1, " ", 1);
		else if (i == 3)
			write(1, ", ", 2);
		i++;
	}
}

void	ft_print_comb2(void)
{
	char	nb[4];

	nb[0] = '0';
	nb[1] = '0';
	nb[2] = '0';
	nb[3] = '1';
	while (nb[1] <= '9')
	{
		while (nb[2] <= '9')
		{
			while (nb[3] <= '9')
			{
				ft_output(nb);
				nb[3]++;
			}
			nb[2]++;
			nb[3] = nb[2];
		}
		nb[1]++;
		nb[2] = nb[1];
		nb[0] = nb[1] + 1;
	}
}
