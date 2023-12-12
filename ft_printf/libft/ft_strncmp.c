/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:34:02 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/15 19:48:36 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	size_t	i;

	i = 0;
	if (i < size)
	{
		while (i < size && (str1[i] || str2[i]))
		{
			if (str1[i] == str2[i])
				i++;
			else
				return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
	}
	return (0);
}
