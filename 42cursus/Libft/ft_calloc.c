/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:33:35 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/22 10:46:56 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb == (size_t) -1 || size == (size_t) -1)
		return ((void *) 0);
	p = malloc(nmemb * size);
	if (!p)
		return ((void *) 0);
	ft_bzero(p, nmemb * size);
	return (p);
}
