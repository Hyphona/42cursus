/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:01:31 by alperrot          #+#    #+#             */
/*   Updated: 2024/02/02 20:04:34 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putbase_fd(long unsigned int n, char *base, int fd)
{
	size_t	len;

	if (!base || !fd)
		return (0);
	len = 0;
	if (n >= ft_strlen(base))
	{
		len = ft_putbase_fd(n / ft_strlen(base), base, fd);
		len += ft_putbase_fd(n % ft_strlen(base), base, fd);
	}
	else
		len += ft_putchar_fd(base[n], fd);
	return (len);
}
