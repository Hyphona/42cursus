/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:34:02 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/12 14:02:33 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	int	i;

	i = 0;
	if (i < (int) size)
	{
		while (i < (int) size && (str1[i] || str2[i]))
		{
			if (str1[i] == str2[i])
				i++;
			else
				return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
	}
	return (0);
}
