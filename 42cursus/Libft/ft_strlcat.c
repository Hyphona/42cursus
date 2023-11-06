/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:22:32 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/06 18:13:06 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	long unsigned int	i;
	long unsigned int	destlen;

	i = 0;
	destlen = ft_strlen(dest);
	if (size != 0)
	{
		while (i < size && src[i] != '\0')
		{
			dest[i + destlen] = src[i];
			i++;
		}
	}
	dest[i + destlen] = '\0';
	return (i + destlen);
}
