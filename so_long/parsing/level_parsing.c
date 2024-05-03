/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:06:55 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/03 08:10:18 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static size_t	ft_strlen_lp(char *str)
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

// Set the map size in the t_game structure
static void	set_map_size(t_game *g, char *map_name)
{
	int		fd;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_parse_error(g, "Cannot open the map file");
	line = get_next_line(fd);
	while (line)
	{
		if (g->map_w == 0)
			g->map_w = ft_strlen_lp(line);
		else if (g->map_w != ft_strlen_lp(line))
			ft_map_error(g, line);
		g->map_h++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

// Check if the character is a valid character
static char	is_valid(t_game *g, char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P' || c == '\n')
	{
		if (c == 'C')
			g->collectibles++;
		else if (c == 'P')
		{
			if (g->has_spawn)
				return (0);
			g->has_spawn = 1;
		}
		else if (c == 'E')
		{
			if (g->has_exit)
				return (0);
			g->has_exit = 1;
		}
		return (c);
	}
	return (0);
}

// Parse the map char and count the collectibles
static void	parse_char(t_game *g, char *map_name)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_parse_error(g, "Cannot open the map file");
	line = get_next_line(fd);
	g->collectibles = 0;
	while (line)
	{
		i = 0;
		while (line[i])
		{
			if (!is_valid(g, line[i]))
				ft_map_error(g, line);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	parse_map(t_game *g, char *map_name)
{
	set_map_size(g, map_name);
	parse_char(g, map_name);
}
