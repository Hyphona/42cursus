/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:57:15 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/27 14:15:50 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

// In case MLX fail to initialize
static void	ft_mlx_init_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// In case the t_game structure fail to initialize
static void	ft_game_init_error(mlx_t *mlx)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	mlx_terminate(mlx);
	exit(EXIT_FAILURE);
}

int32_t	main(void)
{
	mlx_t		*mlx;
	t_game		*g;

	mlx = mlx_init(512, 512, "Super Adventure Plus Ultra", false);
	if (!mlx)
		ft_mlx_init_error();
	g = malloc(sizeof(t_game));
	if (!g)
		ft_game_init_error(mlx);
	g->mlx = mlx;
	load(g);
	mlx_loop_hook(mlx, close_window_listener, g);
	mlx_key_hook(mlx, p_move_listener, g);
	mlx_loop(mlx);
	ft_exit(g);
	return (EXIT_SUCCESS);
}
