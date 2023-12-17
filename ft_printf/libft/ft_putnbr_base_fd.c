/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:01:31 by alperrot          #+#    #+#             */
/*   Updated: 2023/12/17 12:29:34 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base_fd(unsigned int n, char *base, int fd)
{
	size_t	lenght;
	size_t	base_len;

	if (!base || !fd)
		return (0);
	lenght = 0;
	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		lenght = ft_putnbr_base_fd(n / base_len, base, fd);
		lenght += ft_putnbr_base_fd(n % base_len, base, fd);
	}
	else
		lenght += ft_putchar_fd(base[n], fd);
	return (lenght);
}
