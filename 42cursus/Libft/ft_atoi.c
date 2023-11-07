/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:04:58 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/07 10:29:14 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	final;

	i = 0;
	if (str[i] != 0)
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			final = (final * 10) + (str[i] - 0 - 48);
			i++;
		}
		return (final);
	}
	return (0);
}