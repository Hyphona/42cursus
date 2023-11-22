/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:12:47 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/12 13:50:56 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return ((void *) 0);
	if (len == 0)
		return (ft_strdup(""));
	if (start > ft_strlen(s) || len > ft_strlen(s))
		return (ft_strdup(""));
	str = ft_calloc(sizeof(char), len + 1);
	if (!str)
		return ((void *) 0);
	i = 0;
	while (start < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	return (str);
}
