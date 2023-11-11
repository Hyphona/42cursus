/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:05:25 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/11 14:32:37 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t size)
{
	int	i;
	int	j;

	i = 0;
	if (!str2[i] || !size)
		return ((char *) str1);
	while (str1[i] && (i < (int) size))
	{
		j = 0;
		while (str1[i + j] == str2[j] && (i + j) < (int) size)
		{
			if (!str2[j + 1])
				return ((char *) &str1[i]);
			j++;
		}
		i++;
	}
	return ((void *) 0);
}
