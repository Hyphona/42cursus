/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:34:02 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/07 10:00:39 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	long unsigned int	i;

	i = 0;
	if (i < size)
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
	return (0);
}
