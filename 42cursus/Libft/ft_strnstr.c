/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:05:25 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/15 19:49:04 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!str2[i] || !size)
		return ((char *) str1);
	while (str1[i] && (i < size))
	{
		j = 0;
		while (str1[i + j] == str2[j] && (i + j) < size)
		{
			if (!str2[j + 1])
				return ((char *) &str1[i]);
			j++;
		}
		i++;
	}
	return ((void *) 0);
}
