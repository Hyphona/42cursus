/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:12:34 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/12 16:04:22 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && !(str[i] >= '\t' && str[i] <= '\r'))
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*nstr;

	if ((!s1 || !set) || (ft_isspace(s1) && ft_isspace(set)))
		return (ft_strdup(""));
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	len = ft_strlen(s1);
	while (len > 0 && ft_strchr(set, s1[len - 1]))
		len--;
	nstr = ft_calloc(sizeof(char), len - i + 1);
	if (!nstr)
		return ((void *) 0);
	j = 0;
	while (i < len)
		nstr[j++] = s1[i++];
	return (nstr);
}
