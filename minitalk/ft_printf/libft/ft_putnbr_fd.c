/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:57:58 by alperrot          #+#    #+#             */
/*   Updated: 2024/01/03 12:05:00 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_fd(int n, int fd)
{
	size_t	len;
	char	c;

	if (!fd)
		return (0);
	len = 0;
	c = '0';
	if (n == -2147483648)
	{
		len += ft_putstr_fd("-2147483648", fd);
		return (len);
	}
	else if (n < 0)
	{
		len += ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
		len += ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	len += ft_putchar_fd(c, fd);
	return (len);
}
