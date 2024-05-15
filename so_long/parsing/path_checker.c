/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:04:38 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/15 10:13:26 by alperrot         ###   ########.fr       */
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

static void	fill_floor(char *map, int len)
{
	int	i;

	i = 0;
	if (map[i] == '1' || map[i] == '\n')
		return ;
	map[i] = 'x';
	if (map[i + 1] && map[i + 1] != 'x')
		fill_floor(&map[i + 1], len);
	if (map[i + len + 1] && map[i + len + 1] != 'x')
		fill_floor(&map[i + len + 1], len);
	if (map[i - 1] && map[i - 1] != 'x')
		fill_floor(&map[i - 1], len);
	if (map[i - len - 1] && map[i - len - 1] != 'x')
		fill_floor(&map[i - len - 1], len);
}

int	check_path(char *map)
{
	int		i;
	int		len;
	char	*tmp;

	len = 0;
	tmp = ft_strdup(map);
	while (tmp[len] != '\n')
		len++;
	i = 0;
	while (tmp[i] != 'P')
		i++;
	fill_floor(&tmp[i], len);
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == 'P' || tmp[i] == 'C' || tmp[i] == 'E')
		{
			free(tmp);
			return (0);
		}
		i++;
	}
	free(tmp);
	return (1);
}
