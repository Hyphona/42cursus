/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:55:33 by alperrot          #+#    #+#             */
/*   Updated: 2023/08/28 16:06:32 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	n;

	n = nb;
	if (nb == 0 && power == 0)
		return (1);
	if (nb == 0 && power != 0)
		return (0);
	if (power == 0)
		return (1);
	if (power <= 0)
		return (0);
	while (power != 1)
	{
		power--;
		nb = nb * n;
	}
	return (nb);
}
