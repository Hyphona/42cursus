/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:04:38 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/13 10:05:00 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static t_map	*create_map(t_map *map_node, char *map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
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

static t_map	*get_node_at(t_game *g, t_map *map, int x, int y)
{
	if (!map)
		return (NULL);
	if (map->x == x && map->y == y)
		return (map);
	if (x > (int)g->map_w * 32 || y > (int)g->map_h * 32 || x < 0 || y < 0)
		return (NULL);
	while (map->y != y)
		if (map->next)
			map = map->next;
		else
			return (NULL);
	while (map->x != x)
		if (map->next)
			map = map->next;
		else
			return (NULL);
	if (map->x == x && map->y == y)
		return (map);
	while (map->y != y)
		if (map->prev)
			map = map->prev;
		else
			return (NULL);
	while (map->x != x)
		if (map->prev)
			map = map->prev;
		else
			return (NULL);
	if ((map->x != x) || (map->y != y))
		return (NULL);
	return (map);
}

void	backtrack_path(t_game *g, t_map *map_node, int x, int y)
{
	if (!map_node)
		return ;
	if (x <= (int)g->map_w * 32 && y <= (int)g->map_h * 32 && x >= 0 && y >= 0)
	{
		map_node->type = '1';
		if (get_node_at(g, map_node, x + 32, y))
			if (get_node_at(g, map_node, x + 32, y)->type != '1')
				backtrack_path(g, get_node_at(g, map_node, x + 32, y), x + 32, y);
		if (get_node_at(g, map_node, x, y + 32))
			if (get_node_at(g, map_node, x, y + 32)->type != '1')
				backtrack_path(g, get_node_at(g, map_node, x, y + 32), x, y + 32);
		if (get_node_at(g, map_node, x - 32, y))
			if (get_node_at(g, map_node, x - 32, y)->type != '1')
				backtrack_path(g, get_node_at(g, map_node, x - 32, y), x - 32, y);
		if (get_node_at(g, map_node, x, y - 32))
			if (get_node_at(g, map_node, x, y - 32)->type != '1')
				backtrack_path(g, get_node_at(g, map_node, x, y - 32), x, y - 32);
	}
}

int	check_path(t_game *g, char *map)
{
	t_map	*map_node;

	map_node = create_map(NULL, map);
	while(map_node->type != 'P')
		map_node = map_node->next;
	backtrack_path(g, map_node, map_node->x, map_node->y);
	while (map_node->prev)
		map_node = map_node->prev;
	while (map_node->next)
	{
		if (map_node->type != '1')
		{
			free_map(map_node);
			return (0);
		}
		map_node = map_node->next;
	}
	free_map(map_node);
	return (1);
}