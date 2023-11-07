/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:32:18 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/07 20:16:29 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	unsigned char	*temp_dest;

	i = 0;
	temp_dest = (unsigned char *) dest;
	if (n > i)
	{
		ft_memcpy(temp_dest, src, ft_strlen(src));
		ft_memcpy(dest, temp_dest, n);
	}
	return (dest);
}
