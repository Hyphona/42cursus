/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:26:35 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/26 15:12:22 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/MLX42/include/MLX42/MLX42.h"
#include "include/so_long.h"

// Just a function to know if the pressed key is a 'move' key
static int	ft_is_move_key(mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN
		|| keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
		return (1);
	else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S
		|| keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
		return (1);
	return (0);
}

// Close the window if the escape key is pressed
void	ft_hook_close(void *param)
{
	t_game	*g;

	g = param;
	if (mlx_is_key_down(g->mlx, MLX_KEY_ESCAPE))
		ft_exit(g);
}

// Listen to input and update the player position
void	ft_hook_move(mlx_key_data_t keydata, void *param)
{
	t_game			*g;
	static size_t	i;

	g = param;
	if (keydata.action == MLX_RELEASE && ft_is_move_key(keydata))
	{
		if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
			g->player->instances[0].y -= 32;
		if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
			g->player->instances[0].y += 32;
		if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
			g->player->instances[0].x -= 32;
		if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
			g->player->instances[0].x += 32;
		ft_printf("Move count: %d\n", i + 1);
		i++;
	}
}
