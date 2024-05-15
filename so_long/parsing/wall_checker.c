/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 12:43:07 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/15 12:07:44 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ft_linelen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		if (str[len] == '\n')
			break ;
		len++;
	}
	return (len + 1);
}

static int	check_first(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
	{
		if (map[i] != '1')
			return (0);
		i++;
	}
	return (i);
}

static int	check_last(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1')
			return (0);
		i++;
	}
	return (i);
}

int	check_wall(char *map)
{
	int	i;
	int	len;

	i = check_first(map);
	if (i == 0)
		return (0);
	len = ft_linelen(map);
	while (map[i])
	{
		if (map[i] == '\n' && (map[i - (len - 1)] != '1' || map[i - 1] != '1'))
			return (0);
		i++;
	}
	return (check_last(&map[i - (len - 1)]));
}
