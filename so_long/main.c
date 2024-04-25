/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:57:15 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/25 13:05:05 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

#define WIDTH 512
#define HEIGHT 512

static void	ft_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(void)
{
	mlx_t		*mlx;
	t_game		*game;

	mlx = mlx_init(WIDTH, HEIGHT, "Super Adventure Plus Ultra", false);
	if (!mlx)
		ft_error();
	game = malloc(sizeof(t_game));
	if (!game)
		ft_error();
	game->mlx = mlx;
	load_textures(game);
	mlx_loop_hook(mlx, ft_hook_close, mlx);
	mlx_key_hook(mlx, ft_hook_move, game);
	mlx_loop(mlx);
	mlx_delete_image(mlx, game->player);
	free(game);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
