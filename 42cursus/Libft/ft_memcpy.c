/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:33:31 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/06 18:36:18 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	long unsigned int	i;

	i = 0;
	if (size != 0)
	{
		while (i != size && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (&dest);
}
