/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:16:09 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/06 18:30:00 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	*ft_memset(void *str, int c, size_t size)
{
	long unsigned int	i;

	i = 0;
	if (size != 0)
	{
		while (i != size && str[i] != '\0')
		{
			str[i] = c;
			i++;
		}
	}
	return (&str);
}
