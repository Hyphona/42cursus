/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:27:53 by alperrot          #+#    #+#             */
/*   Updated: 2023/12/11 20:38:18 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(n);
	str = ft_calloc(sizeof(char), len + 1);
	if (!str)
		return ((char *) 0);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	len--;
	while (n > 9)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	str[len] = n + '0';
	return (str);
}
