/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_listener.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:10:05 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/17 09:51:17 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../include/so_long.h"

static int	is_move_key(mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN
		|| keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
		return (1);
	else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S
		|| keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
		return (1);
	return (0);
}

void	p_move_listener(mlx_key_data_t keydata, void *param)
{
	t_game			*g;
	static size_t	i;
	int				x;
	int				y;
	int				moved;

	g = param;
	if (keydata.action == MLX_RELEASE && is_move_key(keydata))
	{
		x = g->player->instances[0].x;
		y = g->player->instances[0].y;
		if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
			moved = update_player_pos(g, x, y - 32, i);
		if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
			moved = update_player_pos(g, x, y + 32, i);
		if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
			moved = update_player_pos(g, x - 32, y, i);
		if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
			moved = update_player_pos(g, x + 32, y, i);
		if (moved)
		{
			ft_printf("Move count: %d\n", i + 1);
			i++;
		}
	}
}
