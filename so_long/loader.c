/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:48:50 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/25 14:13:36 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

static void	ft_error(t_game *g)
{
	t_level	*level;

	level = g->level;
	ft_printf("%s", mlx_strerror(mlx_errno));
	if (level)
	{
		while (level->next)
		{
			mlx_delete_image(g->mlx, level->img);
			level = level->next;
		}
		free_level(g->level);
	}
	if (g->player)
		mlx_delete_image(g->mlx, g->player);
	mlx_terminate(g->mlx);
	free(g);
	exit(EXIT_FAILURE);
}

static void	load_background(t_game *g)
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
			add_node(&level, create_node(b_img));
			x += 32;
		}
		y += 32;
		x = 0;
	}
	g->level = level;
}

void	load_textures(t_game *g)
{
	mlx_image_t	*player_img;

	load_background(g);
	player_img = mlx_texture_to_image(g->mlx, mlx_load_png("./img/0.png"));
	if (!player_img || (mlx_image_to_window(g->mlx, player_img, 0, 0) < 0))
		ft_error(g);
	g->player = player_img;
}
