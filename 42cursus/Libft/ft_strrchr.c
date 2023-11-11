/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:48:28 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/11 15:04:35 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t			len;

	len = ft_strlen(str);
	if (str[len] == '\0' && (char) c == '\0')
		return ((char *) &str[len]);
	while (len--)
		if (str[len] == (char) c)
			return ((char *) &str[len]);
	return ((void *) 0);
}
