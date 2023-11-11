/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:48:28 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/11 11:08:47 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			len;

	len = ft_strlen(s);
	if (s[len] == '\0' && (char) c == '\0')
		return ((char *) &s[len]);
	while (len-- > 0)
		if (s[len] == (char) c)
			return ((char *) &s[len]);
	return ((void *) 0);
}
