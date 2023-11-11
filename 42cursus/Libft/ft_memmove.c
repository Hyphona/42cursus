/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:32:18 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/11 14:57:14 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*p_dst;
	char	*p_src;

	if ((!dest && !src) || !n)
		return (dest);
	p_dst = (char *) dest;
	p_src = (char *) src;
	if (p_dst > p_src)
		while (n--)
			p_dst[n] = p_src[n];
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
