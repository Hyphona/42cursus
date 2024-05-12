/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:35:21 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/12 14:37:58 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Returns the line lenght without the '\n' character
static int	ft_strlen_nonl(char *str)
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

// Define the spawn point
static void	create_spawn(t_game *g, char *map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			y += 32;
			x = 0;
		}
		else
		{
			if (map[i] == 'P')
			{
				g->spawn_x = x;
				g->spawn_y = y;
			}
			x += 32;
		}
		i++;
	}
}

// Check if the characters are valid
// If no exit, spawn or collectibles, return 0
// If more than one exit or spawn, return 0
static int	check_char(t_game *g, char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '1' || map[i] == '0' || map[i] == 'C' || map[i] == 'E'
			|| map[i] == 'P' || map[i] == '\n')
		{
			if (map[i] == 'E')
				g->has_exit++;
			else if (map[i] == 'P')
				g->has_spawn++;
			else if (map[i] == 'C')
				g->collectibles++;
		}
		else
			return (0);
		i++;
	}
	if (g->has_exit != 1 || g->has_spawn != 1 || g->collectibles == 0)
		return (0);
	return (1);
}

// Open and store the map file in a string
static char	*load_map_file(t_game *g, char *map_name)
{
	int		fd;
	int		line_len;
	char	*line;
	char	*map;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_parse_error(g, "Cannot open the map file");
	line = get_next_line(fd);
	line_len = ft_strlen_nonl(line);
	map = NULL;
	while (line)
	{
		if (ft_strlen_nonl(line) != line_len)
			ft_map_error(g, map, "Map is not a rectangle/square", fd);
		map = ft_strjoin(map, line);
		g->map_h++;
		free(line);
		line = get_next_line(fd);
	}
	g->map_w = line_len;
	free(line);
	close(fd);
	return (map);
}

// Do basics checks on the map and return it
char	*get_map(t_game *g, char *map_name)
{
	char	*map;

	map = load_map_file(g, map_name);
	if (!check_char(g, map))
		ft_map_error(g, map, "Missing collectibles or duplicated exit/player\n", 0);
	if (!check_wall(map))
		ft_map_error(g, map, "Map is not surounded by walls\n", 0);
	if (!check_path(map))
		ft_map_error(g, map, "Map is not finishable\n", 0);
	create_spawn(g, map);
	return (map);
}

