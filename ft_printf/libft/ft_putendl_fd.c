/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:51:06 by alperrot          #+#    #+#             */
/*   Updated: 2024/01/03 12:20:00 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	if (!s || !fd)
		return (0);
	len = 0;
	len += ft_putstr_fd(s, fd);
	len += ft_putchar_fd('\n', fd);
	return (len);
}
