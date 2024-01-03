/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:44:33 by alperrot          #+#    #+#             */
/*   Updated: 2024/01/03 12:22:24 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (!s || !fd)
		return (0);
	len = 0;
	while (*s)
	{
		len += ft_putchar_fd(*s, fd);
		s++;
	}
	return (len);
}
