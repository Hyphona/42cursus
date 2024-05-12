/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:57:15 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/12 12:02:35 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

// In case t_game fail to initialize
static void	ft_g_init_error(void)
{
	ft_printf("Error - t_game structure failed to initialize\n");
	exit(EXIT_FAILURE);
}

// In case MLX fail to initialize
static void	ft_mlx_init_error(t_game *g)
{
	ft_printf("Error - MLX failed to initialize\n");
	free(g);
	exit(EXIT_FAILURE);
}

// Avoid memory leaks by setting up t_game structure
static t_game	*init_game(t_game *g)
{
	g->mlx = NULL;
	g->map_h = 0;
	g->map_w = 0;
	g->collectibles = 0;
	g->has_spawn = 0;
	g->has_exit = 0;
	g->level = NULL;
	g->spawn_x = 0;
	g->spawn_y = 0;
	return (g);
}

int32_t	main(int argc, char **argv)
{
	mlx_t		*mlx;
	t_game		*g;
	char		*map_name;
	char		*map;

	g = malloc(sizeof(t_game));
	if (!g)
		ft_g_init_error();
	g = init_game(g);
	map_name = "./custom_map/default.ber";
	if (check_args(g, argc, argv))
		map_name = argv[1];
	else if (!check_args(g, argc, argv) && argc != 1)
		ft_parse_error(g, "Invalid map file");
	map = get_map(g, map_name);
	mlx = mlx_init(g->map_w * 32, g->map_h * 32, "SAPU", false);
	if (!mlx)
		ft_mlx_init_error(g);
	g->mlx = mlx;
	load(g, map);
	mlx_loop_hook(mlx, close_window_listener, g);
	mlx_key_hook(mlx, p_move_listener, g);
	mlx_loop(mlx);
	return (EXIT_SUCCESS);
}
