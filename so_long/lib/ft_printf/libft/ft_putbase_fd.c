/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:01:31 by alperrot          #+#    #+#             */
/*   Updated: 2024/01/03 12:19:21 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putbase_fd(long unsigned int n, char *base, int fd)
{
	size_t	len;
	size_t	b_len;

	if (!base || !fd)
		return (0);
	if (!ft_check_base(base))
		return (0);
	len = 0;
	b_len = ft_strlen(base);
	if (n >= b_len)
	{
		len = ft_putbase_fd(n / b_len, base, fd);
		len += ft_putbase_fd(n % b_len, base, fd);
	}
	else
		len += ft_putchar_fd(base[n], fd);
	return (len);
}
