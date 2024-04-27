/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:27:20 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/27 14:45:28 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/MLX42/include/MLX42/MLX42.h"
#include "./include/so_long.h"

// Know if the player can move to x:y
int	can_move_to(t_game *game, int x, int y)
{
	if (is_wall(game, x, y))
		return (0);
	else if (is_collectible(game, x, y))
		game->collectibles--;
	else if (is_exit(game, x, y))
	{
		if (game->collectibles == 0)
			ft_exit(game);
	}
	return (1);
}

// Spawn the player at x:y
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
int	update_player_pos(t_game *g, int x, int y)
{
	if (can_move_to(g, x, y))
	{
		g->player->instances[0].x = x;
		g->player->instances[0].y = y;
		return (1);
	}
	return (0);
}
