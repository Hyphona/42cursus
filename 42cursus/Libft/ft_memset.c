/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:16:09 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/07 20:18:33 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	unsigned char	*ptr_s;

	i = 0;
	ptr_s = (unsigned char *) s;
	if (n > i)
	{
		while (i != n && ptr_s[i] != '\0')
		{
			ptr_s[i] = c;
			i++;
		}
	}
	return (s);
}
