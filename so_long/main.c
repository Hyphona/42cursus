/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:57:15 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/17 09:31:24 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

static void	ft_g_init_error(void)
{
	ft_printf("Error\nt_game structure failed to initialize\n");
	exit(EXIT_FAILURE);
}

static void	ft_mlx_init_error(t_game *g)
{
	ft_printf("Error\nMLX failed to initialize\n");
	free(g);
	exit(EXIT_FAILURE);
}

static t_game	*init_game(t_game *g)
{
	g->mlx = NULL;
	g->player = NULL;
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

static void	check_textures(char *txt, int num)
{
	int	fd;

	fd = open(txt, O_RDONLY);
	if (fd <= 0)
	{
		close(fd);
		ft_printf("Error\n%s is missing/can't be open\n", txt);
		exit(EXIT_FAILURE);
	}
	close(fd);
	if (num == 1)
		check_textures("./img/1.png", 2);
	if (num == 2)
		check_textures("./img/2.png", 3);
	if (num == 3)
		check_textures("./img/3.png", 4);
	if (num == 4)
		check_textures("./img/4.png", 5);
}

int32_t	main(int argc, char **argv)
{
	mlx_t		*mlx;
	t_game		*g;
	char		*map_name;
	char		*map;

	check_textures("./img/0.png", 1);
	g = malloc(sizeof(t_game));
	if (!g)
		ft_g_init_error();
	g = init_game(g);
	map_name = NULL;
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
