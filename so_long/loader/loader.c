/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:48:50 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/15 10:07:04 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	load_error(t_game *g, char *map)
{
	free(map);
	ft_error(g);
}

static void	load_level(t_game *g, char *m, int x, int y)
{
	mlx_image_t	*b_img;
	int			i;

	i = 0;
	while (m[i])
	{
		if (m[i] != '\n')
		{
			b_img = get_texture(g, m[i]);
			if (!b_img || (mlx_image_to_window(g->mlx, b_img, x, y) < 0))
				load_error(g, m);
			add_node(&g->level, create_node(b_img, x, y, get_type(m[i])));
			x += 32;
		}
		else
		{
			x = 0;
			y += 32;
		}
		i++;
	}
}

void	load(t_game *g, char *map)
{
	load_level(g, map, 0, 0);
	spawn_player(g, g->spawn_x, g->spawn_y);
	free(map);
}
