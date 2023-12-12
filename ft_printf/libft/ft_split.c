/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:30:10 by alperrot          #+#    #+#             */
/*   Updated: 2023/12/11 20:35:46 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freearray(char **tab, size_t j)
{
	while (j > 0)
	{
		free(tab[j]);
		j--;
	}
	free(tab);
	return ((char **) 0);
}

static char	**ft_splitloop(char const *s, char c, char **tab)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			k = i;
			while (s[i] != c && s[i])
				i++;
			tab[j] = ft_substr(s, k, i - k);
			if (!tab[j])
				return (ft_freearray(tab, j));
			j++;
		}
		else
			i++;
	}
	tab[j] = (char *) 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return ((char **) 0);
	tab = ft_calloc(sizeof(char *), (ft_countword(s, c) + 1));
	if (!tab)
		return ((char **) 0);
	return (ft_splitloop(s, c, tab));
}
