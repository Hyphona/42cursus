/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:33:31 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/07 20:15:40 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	unsigned char	*ptr_src;
	unsigned char	*ptr_dest;

	i = 0;
	ptr_src = (unsigned char *) src;
	ptr_dest = (unsigned char *) dest;
	if (n > i)
	{
		while (i != n && ptr_src[i] != '\0')
		{
			ptr_dest[i] = ptr_src[i];
			i++;
		}
	}
	return (dest);
}
