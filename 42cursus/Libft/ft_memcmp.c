/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:52:45 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/07 20:14:58 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	i = 0;
	ptr_s1 = (unsigned char *) s1;
	ptr_s2 = (unsigned char *) s2;
	if (n > i)
	{
		while (i <= n)
		{
			if (ptr_s1[i] == ptr_s2[i])
				i++;
			else if (ptr_s1[i] > ptr_s2[i])
				return (ptr_s2[i] - ptr_s1[i]);
			else if (ptr_s1[i] < ptr_s2[i])
				return (ptr_s2[i] - ptr_s1[i]);
		}
	}
	return (0);
}
