/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:28:48 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/24 19:30:58 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
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

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	has_space(char *str)
{
	while (*str)
	{
		if (is_space(*str))
			return (1);
		str++;
	}
	return (0);
}

char	*ft_joinchar(char *s1, char s2)
{
	char	*str;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	str = malloc((sizeof(char) * (ft_strlen(s1))) + 2);
	if (!str)
	{
		write(2, "Error\n", 6);
		if (ft_strlen(s1) > 0)
			free(s1);
		return (NULL);
	}
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
