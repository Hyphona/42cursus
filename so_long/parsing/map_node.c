/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 13:07:27 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/12 14:35:23 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map	*create_map_node(char type, int x, int y)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->block_type = type;
	map->next = NULL;
	map->prev = NULL;
	map->x = x;
	map->y = y;
	return (map);
}

static t_map	*get_last_node(t_map *map)
{
	if (!map)
		return (NULL);
	while (map->next)
		map = map->next;
	return (map);
}

void	add_map_node(t_map **map, t_map *new)
{
	if (!*map)
		*map = new;
	else
	{
		new->prev = get_last_node(*map);
		new->prev->next = new;
	}
}

void	free_map(t_map *map)
{
	t_map	*tmp;

	while (map->prev)
		map = map->prev;
	while (map)
	{
		tmp = map;
		map = map->next;
		free(tmp);
	}
}
