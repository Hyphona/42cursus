/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:53:11 by alperrot          #+#    #+#             */
/*   Updated: 2023/12/18 12:53:36 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb < 0)
		return (2);
	else if (ft_isprime(nb) == 1)
		return (nb);
	i = 1;
	while (ft_isprime(nb + i) != 1)
		i++;
	return (nb + i);
}
