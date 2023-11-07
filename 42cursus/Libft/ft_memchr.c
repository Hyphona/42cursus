/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:46:43 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/07 09:51:34 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	*ft_memchr(const void *str, int c, size_t size)
{
	long unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (i <= size && str[i] != '\0')
		{
			if (str[i] == c)
				return (&str[i]);
			i++;
		}
	}
	return ((void *) 0);
}
