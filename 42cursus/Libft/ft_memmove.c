/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:32:18 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/11 10:47:57 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int		i;
	char	*p_dst;
	char	*p_src;

	if ((!dst && !src) || !n)
		return (dst);
	i = 0;
	p_dst = (char *) dst;
	p_src = (char *) src;
	if (p_dst > p_src)
		while (n--)
			p_dst[n] = p_src[n];
	else
	{
		while (i < (int) n)
		{
			p_dst[i] = p_src[i];
			i++;
		}
	}
	return (dst);
}
