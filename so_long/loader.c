/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:48:50 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/25 19:56:15 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

// Load the level
static void	load_level(t_game *g)
{
	int			x;
	int			y;
	mlx_image_t	*b_img;
	t_level		*level;

	x = 0;
	y = 0;
	level = NULL;
	while (y < 512)
	{
		while (x < 512)
		{
			b_img = mlx_texture_to_image(g->mlx, mlx_load_png("./img/1.png"));
			if (!b_img || (mlx_image_to_window(g->mlx, b_img, x, y) < 0))
				ft_error(g);
			add_node(&level, create_node(b_img, x, y, 1));
			x += 32;
		}
		y += 32;
		x = 0;
	}
	g->level = level;
}

// Load the textures and the level
void	load_textures(t_game *g)
{
	mlx_image_t	*player_img;

	load_level(g);
	player_img = mlx_texture_to_image(g->mlx, mlx_load_png("./img/0.png"));
	if (!player_img || (mlx_image_to_window(g->mlx, player_img, 0, 0) < 0))
		ft_error(g);
	g->player = player_img;
}
