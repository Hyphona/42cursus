/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:38:41 by alperrot          #+#    #+#             */
/*   Updated: 2024/01/24 09:26:04 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    ft_bzero(char *str)
{
    size_t  len;

    len = 0;
    while (str[len])
    {
        str[len] = '\0';
        len++;
    }
}

size_t  ft_strlen(const char *str)
{
    size_t  len;

    len = 0;
    while (str[len])
        len++;
    return(len);
}

char	*ft_strjoin(char const *s1, char const*s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return ((void *) 0);
	str = malloc((sizeof(char) * (ft_strlen(s1) + ft_strlen(s2))) + 1);
	if (!str)
		return ((void *) 0);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}