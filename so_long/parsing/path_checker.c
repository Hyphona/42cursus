/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:04:38 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/12 15:23:12 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static t_map	*create_map(t_map *map_node, char *map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while(map[i])
	{
		if (map[i] != '\n')
		{
			add_map_node(&map_node, create_map_node(map[i], x, y));
			x += 32;
		}
		else
		{
			x = 0;
			y += 32;
		}
		i++;
	}
	return (map_node);
}

static t_map	*get_node_at(t_map *map, int x, int y)
{
	if (!map)
		return (NULL);
	while (map->y != y)
		map = map->next;
	while (map->x != x)
		map = map->next;
	if ((map->x == x) && (map->y == y))
		return (map);
	while (map->y != y)
		map = map->prev;
	while (map->x != x)
		map = map->prev;
	if ((map->x != x) || (map->y != y))
		return (NULL);
	return (map);
}

void	backtrack_path(t_map *map_node, int x, int y)
{
	if (!map_node)
		return ;
	if (map_node->block_type != '1')
	{
		map_node->block_type = '1';
		map_node = get_node_at(map_node, x + 32, y);
		backtrack_path(map_node, x + 32, y);
		map_node = get_node_at(map_node, x - 32, y);
		backtrack_path(map_node, x - 32, y);
		map_node = get_node_at(map_node, x, y + 32);
		backtrack_path(map_node, x, y + 32);
		map_node = get_node_at(map_node, x, y - 32);
		backtrack_path(map_node, x, y - 32);
	}
}

int	check_path(char *map)
{
	t_map	*map_node;

	map_node = create_map(NULL, map);
	while(map_node->block_type != 'P')
		map_node = map_node->next;
	backtrack_path(map_node, map_node->x, map_node->y);
	while (map_node->prev)
		map_node = map_node->prev;
	while (map_node)
	{
		if (map_node->block_type != '1')
		{
			free_map(map_node);
			return (0);
		}
		map_node = map_node->next;
	}
	free_map(map_node);
	return (1);
}
