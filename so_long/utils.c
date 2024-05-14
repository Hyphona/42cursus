/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:53:40 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/14 16:31:38 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	ft_clear(t_game *g)
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
}

void	ft_error(t_game *g)
{
	write(2, "Error\n", 6);
	ft_clear(g);
	mlx_terminate(g->mlx);
	free(g);
	exit(EXIT_FAILURE);
}

void	ft_exit(t_game *g)
{
	ft_clear(g);
	mlx_terminate(g->mlx);
	free(g);
	exit(EXIT_SUCCESS);
}

void	ft_map_error(t_game *g, char *map_file, char *text, int fd)
{
	ft_printf("Error - %s\n", text);
	free(g);
	free(map_file);
	if (fd > 0)
		close(fd);
	exit(EXIT_FAILURE);
}

void	ft_parse_error(t_game *g, char *text)
{
	ft_printf("Error - %s\n", text);
	free(g);
	exit(EXIT_FAILURE);
}
