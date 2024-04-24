/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:33:32 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/24 16:18:00 by alperrot         ###   ########.fr       */
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

char	*ft_joinchar(char *s1, char s2)
{
	char	*str;
	size_t	i;

	if (!s1 || !s2)
		return ((void *) 0);
	str = malloc((sizeof(char) * (ft_strlen(s1))) + 2);
	if (!str)
		return ((void *) 0);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = s2;
	str[i + 1] = '\0';
	if (ft_strlen(s1) > 0)
		free(s1);
	return (str);
}
