/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:48:50 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/02 11:10:29 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Just here to save line from load_level_loop()
static void load_error(t_game *g, char *line)
{
	free(line);
	ft_error(g);
}

// The while loop
static t_level *load_level_loop(t_game *g, t_level *level, size_t x, size_t y, int fd)
{
	char		*line;
	mlx_image_t	*b_img;

	while (y <= g->map_h * 32)
	{
		line = get_next_line(fd);
		while (x <= g->map_w * 32)
		{
			if (line && (line[x / 32] || line[x / 32] != '\n'))
			{
				if (line[x / 32] == 'P')
					set_spawn(g, x, y);
				b_img = get_texture(g, line[x / 32]);
				if (!b_img || (mlx_image_to_window(g->mlx, b_img, x, y) < 0))
					load_error(g, line);
				add_node(&level, create_node(b_img, x, y, get_type(line[x / 32])));
			}
			x += 32;
		}
		y += 32;
		x = 0;
		free(line);
	}
	return (level);
}

// Load the level
static void	load_level(t_game *g, char *map_name)
{
	int			fd;
	t_level		*level;

	level = NULL;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_error(g);
	g->level = load_level_loop(g, level, 0, 0, fd);
}

// Load the textures and the level
void	load(t_game *g, char *map_name)
{
	load_level(g, map_name);
	spawn_player(g, g->spawn_x, g->spawn_y);
}
