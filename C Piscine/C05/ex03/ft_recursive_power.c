/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:40:21 by alperrot          #+#    #+#             */
/*   Updated: 2023/08/28 16:05:09 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
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
	if (power != 1)
	{
		power--;
		nb = nb * ft_recursive_power(n, power);
	}
	return (nb);
}
