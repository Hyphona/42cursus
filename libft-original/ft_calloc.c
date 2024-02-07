/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:33:35 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/25 12:44:36 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;

	if (!nmemb || !size)
		return (ft_calloc(1, 1));
	if (nmemb > 2147483647 / size)
		return ((void *) 0);
	str = malloc(nmemb * size);
	if (!str)
		return ((void *) 0);
	ft_bzero(str, nmemb * size);
	return (str);
}
