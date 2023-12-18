/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:48:42 by alperrot          #+#    #+#             */
/*   Updated: 2023/12/18 12:49:07 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_power(int nb, int power)
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
