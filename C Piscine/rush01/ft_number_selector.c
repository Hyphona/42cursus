/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_selector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberduck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:42:10 by nberduck          #+#    #+#             */
/*   Updated: 2023/08/26 18:48:51 by nberduck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_number_selector(char *str, int n)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	j = 1;
	nb = 1;
	while (str[i])
	{
		if (str[i] >= 1 && str[i] <= 4 && j == 1)
		{
			nb++;
			j = 0;
			if (nb == n)
				return (str[i]);
		}
		else if (str[i] == ' ' && j == 0)
			j = 1;
		else
			return (0);
		i++;
	}
	return (0);
}
