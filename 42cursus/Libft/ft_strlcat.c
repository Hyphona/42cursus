/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:22:32 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/22 09:34:03 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;

	if ((!dst && !src))
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	len = ft_strlen(dst);
	if (len >= size)
		return (ft_strlen(src) + size);
	ft_strlcpy(&dst[len], src, size - len);
	return (ft_strlen(src) + len);
}
