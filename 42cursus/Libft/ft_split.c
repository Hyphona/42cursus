/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:30:10 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/15 11:15:11 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_countword(char const *s, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] == c)
			w++;
		i++;
	}
	printf("(ft_countword) return value: %d\n", w + 1);
	return (w + 1);
}

static char	**ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		//printf("(ft_free) Attempt to free tab[%d]", i);
		free(tab[i]);
		//printf(" | tab[%d] got free!\n", i);
		i++;
	}
	free(tab);
	//printf("(ft_free) **tab got completely free!\n");
	return ((char **) 0);
}

char	**ft_split(char const *s, char c)
{
	int	i;
	int	j;
	int	wcount;
	char	**astr;

	if (!s || !c)
		return ((char **) 0);
	i = 0;
	j = 0;
	wcount = 0;
	astr = malloc(sizeof(char *) * ft_countword(s, c) + 1);
	if (!astr)
		return ((char **) 0);
	while (s[i])
	{
		while (s[j] != c && s[j])
			j++;
		astr[wcount] = ft_substr(s, i, j - i);
		if (!astr[wcount])
			return (ft_free(astr));
		wcount++;
		j++;
		i = j;
	}
	return (astr);
}

// TESTS //
int	main()
{
	int	i;
	char	**tab;

	i = 0;
	tab = ft_split("ab.bcd.cdefg.defghi", '.');
	while (tab[i])
	{
		printf("(ft_split) Value of tab[%d] : %s\n", i, tab[i]);
		i++;
	}
	ft_free(tab);
}
