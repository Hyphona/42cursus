/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:06:55 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/02 11:13:54 by alperrot         ###   ########.fr       */
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
		ft_parse_error(g);
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
static char	check_char(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P')
		return (c);
	if (c == '\n')
		return (c);
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
		ft_parse_error(g);
	line = get_next_line(fd);
	g->collectibles = 0;
	while (line)
	{
		i = 0;
		while (line[i])
		{
			if (!check_char(line[i]))
				ft_map_error(g, line);
			if (check_char(line[i]) == 'C')
				g->collectibles++;
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
