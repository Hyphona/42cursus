/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:32:18 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/07 20:16:29 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	j;
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	i = 0;
	ptr_dest = (unsigned char *) dest;
	ptr_src = (unsigned char *) src;
	if (n > i && (ptr_dest > ptr_src))
	{
		j = ft_strlen((const char *) ptr_src);
		while (j != 0)
		{
			ptr_dest[i] = ptr_src[j];
			j--;
			i++;
		}
		return (dest);
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
#include <stdio.h>
#include <string.h>
int	main(int argc, char **argv)
{
	(void) argc;
	printf("%s\n", (unsigned char *) ft_memmove(argv[1], argv[2], atoi(argv[3])));
	printf("%s\n", (unsigned char *) memmove(argv[1], argv[2], atoi(argv[3])));
}
