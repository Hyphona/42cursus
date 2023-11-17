/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:27:34 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/17 12:43:12 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*str;

	if (!s)
		return (ft_strdup(""));
	if (!f)
		return (ft_strdup(s));
	len = ft_strlen(s);
	str = ft_calloc(sizeof(char), len + 1);
	if (!str)
		return ((char *) 0);
	i = 0;
	while (i != len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
