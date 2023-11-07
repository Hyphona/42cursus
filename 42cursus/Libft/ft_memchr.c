/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:46:43 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/07 20:14:11 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *) s;
	if (n > 0)
	{
		while (i <= n && ptr[i] != '\0')
		{
			if (ptr[i] == c)
				return (&ptr[i]);
			i++;
		}
	}
	return ((void *) 0);
}
