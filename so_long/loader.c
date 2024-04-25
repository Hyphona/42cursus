/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:48:50 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/25 13:50:03 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

static void	ft_error(t_game *game)
{
	t_level	*level;
	
	level = game->level;
	ft_printf("%s", mlx_strerror(mlx_errno));
	if (level)
	{
		while (level->next)
		{
			mlx_delete_image(game->mlx, level->img);
			level = level->next;
		}
		free_stack(game->level);
	}
	if (game->player)
		mlx_delete_image(game->mlx, game->player);
	mlx_terminate(game->mlx);
	free(game);
	exit(EXIT_FAILURE);
}

static void	load_background(t_game *game)
{
	int			x;
	int			y;
	mlx_image_t	*back_img;
	t_level		*level;

	x = 0;
	y = 0;
	level = NULL;
	while (y < 512)
	{
		while (x < 512)
		{
			back_img = mlx_texture_to_image(game->mlx, mlx_load_png("./img/1.png"));
			if (!back_img || (mlx_image_to_window(game->mlx, back_img, x, y) < 0))
				ft_error(game);
			add_node(&level, create_node(back_img));
			x += 32;
		}
		y += 32;
		x = 0;
	}
	game->level = level;
}

void	load_textures(t_game *game)
{
	mlx_image_t	*player_img;
	
	load_background(game);
	player_img = mlx_texture_to_image(game->mlx, mlx_load_png("./img/0.png"));
	if (!player_img || (mlx_image_to_window(game->mlx, player_img, 0, 0) < 0))
		ft_error(game);
	game->player = player_img;
}
