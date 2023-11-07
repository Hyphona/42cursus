/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:52:45 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/07 09:56:53 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_memcmp(const void *str1, const void *str2, size_t size)
{
	long unsigned int	i;

	i = 0;
	if (size > i)
	{
		while (i <= size)
		{
			if (str1[i] == str2[i])
				i++;
			else if (str1[i] > str2[i])
				return (1);
			else if (str1[i] < str2[i])
				return (-1);
		}
	}
	return ((void *) 0);
}
