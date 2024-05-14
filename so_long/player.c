/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:27:20 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/14 16:16:58 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/MLX42/include/MLX42/MLX42.h"
#include "./include/so_long.h"

// Know if the player can move to x:y
int	can_move_to(t_game *game, int x, int y)
{
	if (is_wall(game, x, y))
		return (0);
	else if (is_exit(game, x, y))
	{
		if (game->collectibles == 0)
			ft_exit(game);
	}
	return (1);
}

// Spawn the player at x:y
// Can also be used to update the player texture
void	spawn_player(t_game *g, int x, int y)
{
	mlx_image_t	*player_img;

	if (g->player)
		mlx_delete_image(g->mlx, g->player);
	player_img = mlx_texture_to_image(g->mlx, mlx_load_png("./img/0.png"));
	if (!player_img || (mlx_image_to_window(g->mlx, player_img, x, y) < 0))
		ft_error(g);
	g->player = player_img;
}

// Update the player position
// Also check if the player can move to x:y
// Return 0 if the player can't move to x:y
int	update_player_pos(t_game *g, int x, int y, int updt_texture, int texture_id)
{
	if (can_move_to(g, x, y))
	{
		if (updt_texture)
		{
			mlx_delete_image(g->mlx, g->player);
			if (texture_id == 0)
				g->player = mlx_texture_to_image(g->mlx, mlx_load_png("./img/0.png"));
			else if (texture_id == 1)
				g->player = mlx_texture_to_image(g->mlx, mlx_load_png("./img/0-1.png"));
			if (!g->player || (mlx_image_to_window(g->mlx, g->player, x, y) < 0))
				ft_error(g);
		}
		if (is_collectible(g, x, y))
		{
			update_block_at(g, x, y, 2);
			g->collectibles--;
			spawn_player(g, x, y);
			return (1);
		}
		g->player->instances[0].x = x;
		g->player->instances[0].y = y;
		return (1);
	}
	return (0);
}

// Set the spawn position of the player
void	set_spawn(t_game *g, int x, int y)
{
	g->spawn_x = x;
	g->spawn_y = y;
}
