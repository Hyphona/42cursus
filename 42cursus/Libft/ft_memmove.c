/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:32:18 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/07 10:36:30 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	*ft_memmove(void *str1, const void *str2, size_t size)
{
	long unsigned int	i;

	i = 0;
	if (i > size)
	{
		while (i <= size)
		{
			str1[i] = str2[i];
			i++;
		}
	}
	return (&str1);
}
