/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:57:15 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/26 13:13:01 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

#define WIDTH 512
#define HEIGHT 512

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

	mlx = mlx_init(WIDTH, HEIGHT, "Super Adventure Plus Ultra", false);
	if (!mlx)
		ft_mlx_init_error();
	g = malloc(sizeof(t_game));
	if (!g)
		ft_game_init_error(mlx);
	g->mlx = mlx;
	load_textures(g);
	mlx_loop_hook(mlx, ft_hook_close, g);
	mlx_key_hook(mlx, ft_hook_move, g);
	mlx_loop(mlx);
	ft_exit(g);
	return (EXIT_SUCCESS);
}
