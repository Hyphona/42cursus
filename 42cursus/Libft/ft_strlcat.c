/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:22:32 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/07 20:33:47 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;

	i = 0;
	dstlen = ft_strlen(dst);
	if (size > i)
	{
		while (i < size && src[i] != '\0')
		{
			dst[i + dstlen] = src[i];
			i++;
		}
	}
	dst[i + dstlen] = '\0';
	return (i + dstlen);
}
