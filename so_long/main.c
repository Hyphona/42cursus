/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:57:15 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/25 14:05:09 by alperrot         ###   ########.fr       */
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

void	ft_exit(t_game *game)
{
	t_level	*level;
	
	level = game->level;
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
	exit(EXIT_SUCCESS);
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
	ft_exit(game);
	return (EXIT_SUCCESS);
}
