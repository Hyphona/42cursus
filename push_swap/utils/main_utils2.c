/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:33:32 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/19 14:50:06 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return ((void *) 0);
	str = malloc((sizeof(char) * (ft_strlen(s1))) + 2);
	if (!str)
		return ((void *) 0);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	str[j++] = s2;
	str[j++] = '\0';
	return (str);
}
