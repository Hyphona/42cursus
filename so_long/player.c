/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:27:20 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/17 09:33:08 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/MLX42/include/MLX42/MLX42.h"
#include "./include/so_long.h"

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

void	spawn_player(t_game *g, int x, int y)
{
	mlx_image_t		*player_img;
	mlx_texture_t	*png;
	int				fd;

	if (g->player)
		mlx_delete_image(g->mlx, g->player);
	fd = open("./img/0.png", O_RDONLY);
	if (fd <= 0)
	{
		close(fd);
		ft_error(g, "Cannot open/find player texture");
	}
	close(fd);
	png = mlx_load_png("./img/0.png");
	player_img = mlx_texture_to_image(g->mlx, png);
	mlx_delete_texture(png);
	if (!player_img || (mlx_image_to_window(g->mlx, player_img, x, y) < 0))
		ft_error(g, "Cannot display player texture");
	g->player = player_img;
}

int	update_player_pos(t_game *g, int x, int y)
{
	if (can_move_to(g, x, y))
	{
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

void	set_spawn(t_game *g, int x, int y)
{
	g->spawn_x = x;
	g->spawn_y = y;
}
