/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:47:32 by alperrot          #+#    #+#             */
/*   Updated: 2023/08/29 13:25:14 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	ncount;
	int	final;

	i = 0;
	ncount = 0;
	final = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			ncount++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		final = (final * 10) + (str[i] - 0 - 48);
		i++;
	}
	if (ncount % 2 != 0)
		final = (final - final) - final;
	return (final);
}
