/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:57:15 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/01 17:27:05 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

// In case t_game fail to initialize
static void	ft_g_init_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

// In case MLX fail to initialize
static void	ft_mlx_init_error(t_game *g)
{
	write(2, "Error\n", 6);
	free(g);
	exit(EXIT_FAILURE);
}

int32_t	main(int argc, char **argv)
{
	mlx_t		*mlx;
	t_game		*g;
	char		*map_name;

	g = malloc(sizeof(t_game));
	if (!g)
		ft_g_init_error();
	g->map_h = 0;
	g->map_w = 0;
	if (argc == 1)
		map_name = "./custom_map/default.ber";
	else if (check_args(g, argc, argv))
		map_name = argv[1];
	else
		ft_parse_error(g);
	parse_map(g, map_name);
	mlx = mlx_init(g->map_w * 32, g->map_h * 32, "SAPU", false);
	if (!mlx)
		ft_mlx_init_error(g);
	g->mlx = mlx;
	load(g, map_name);
	mlx_loop_hook(mlx, close_window_listener, g);
	mlx_key_hook(mlx, p_move_listener, g);
	mlx_loop(mlx);
	ft_exit(g);
	return (EXIT_SUCCESS);
}
