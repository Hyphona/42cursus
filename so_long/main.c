/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:57:15 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/25 14:16:19 by alperrot         ###   ########.fr       */
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

void	ft_exit(t_game *g)
{
	t_level	*level;

	level = g->level;
	if (level)
	{
		while (level->next)
		{
			mlx_delete_image(g->mlx, level->img);
			level = level->next;
		}
		free_level(g->level);
	}
	if (g->player)
		mlx_delete_image(g->mlx, g->player);
	mlx_terminate(g->mlx);
	free(g);
	exit(EXIT_SUCCESS);
}

int32_t	main(void)
{
	mlx_t		*mlx;
	t_game		*g;

	mlx = mlx_init(WIDTH, HEIGHT, "Super Adventure Plus Ultra", false);
	if (!mlx)
		ft_error();
	g = malloc(sizeof(t_game));
	if (!g)
		ft_error();
	g->mlx = mlx;
	load_textures(g);
	mlx_loop_hook(mlx, ft_hook_close, mlx);
	mlx_key_hook(mlx, ft_hook_move, g);
	mlx_loop(mlx);
	ft_exit(g);
	return (EXIT_SUCCESS);
}
