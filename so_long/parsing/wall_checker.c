/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 12:43:07 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/13 09:39:46 by alperrot         ###   ########.fr       */
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
	return (len);
}

int check_wall(char *map)
{
	int	i;
	int	first;

	i = 0;
	first = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			if (map[i - ft_linelen(map)] != '1' && map[i - 1] != '1')
				return (0);
			first = 1;
		}
		if (first == 0 && map[i] != '1')
			return (0);
		i++;
	}
	i -= ft_linelen(map);
	while (map[i + 1])
	{
		if (map[i + 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
