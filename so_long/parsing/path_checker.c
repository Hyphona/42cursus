/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:04:38 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/14 11:02:35 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	*ft_strdup(char *str)
{
	char	*dst;
	int		i;

	i = 0;
	while (str[i])
		i++;
	dst = malloc((sizeof(char) * i) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static void	is_finishable(char *map, int len)
{
	static int	i;
	
	if (map[i] != '1' && map[i] != '\n')
	{
		map[i] = '1';
		if (map[i + 1])
			is_finishable(&map[i + 1], len);
		if (map[i + len])
			is_finishable(&map[i + len], len);
		if (map[i - 1])
			is_finishable(&map[i - 1], len);
		if (map[i - len])
			is_finishable(&map[i - len], len);
	}
}

int	check_path(char *map)
{
	int	i;
	int	len;
	char	*tmp;

	len = 0;
	tmp = ft_strdup(map);
	while (tmp[len] != '\n')
		len++;
	i = 0;
	while (tmp[i] != 'P')
		i++;
	is_finishable(&tmp[i], len);
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] != '1' && tmp[i] != '\n')
		{
			free(tmp);
			return (0);
		}
		i++;
	}
	free(tmp);
	return (1);
}
