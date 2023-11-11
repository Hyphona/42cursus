/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:22:32 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/11 15:38:30 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;

	if ((!dst && !src) || size == 0)
		return (0);
	len = ft_strlen(dst);
	return (ft_strlcpy(&dst[len], src, size - len) + size);
}
