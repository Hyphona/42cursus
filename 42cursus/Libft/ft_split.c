/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:30:10 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/15 20:59:21 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	**ft_freeall(char **tab, size_t j)
{
	while (j > 0)
	{
		free(tab[j]);
		j--;
	}
	free(tab);
	return ((char **) 0);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**tab;

	if (!s)
		return ((char **) 0);
	i = 0;
	j = 0;
	tab = ft_calloc(sizeof(char *), (ft_countword(s, c) + 1));
	if (!tab)
		return ((char **) 0);
	while (s[i])
	{
		if (s[i] != c)
		{
			k = i;
			while (s[i] != c)
				i++;
			tab[j] = ft_substr(s, k, i - k);
			if (!tab[j])
				return (ft_freeall(tab, j));
			j++;
		}
		else
			i++;
	}
	tab[j] = (char *) 0;
	return (tab);
}
