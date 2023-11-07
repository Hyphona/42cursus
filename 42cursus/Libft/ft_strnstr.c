/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:05:25 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/07 20:38:55 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size > i)
	{
		if (str2[i] == '\0')
			return ((char *) str1);
		while (str2[j])
		{
			while (str1[i])
			{
				if (str1[i] == str2[j])
					return ((char *) &str1[i]);
				i++;
			}
			j++;
		}
	}
	return ((void *) 0);
}
