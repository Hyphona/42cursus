/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:53:40 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/01 17:35:45 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

// Clear the game level and image data, except the t_game structure
// The t_game structure need to be freed after calling this function
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

// Clear all data and exit the program as failure
// Also print the error message
void	ft_error(t_game *g)
{
	write(2, "Error\n", 6);
	ft_clear(g);
	mlx_terminate(g->mlx);
	free(g);
	exit(EXIT_FAILURE);
}

// Clear all data and exit the program normally
void	ft_exit(t_game *g)
{
	ft_clear(g);
	mlx_terminate(g->mlx);
	free(g);
	exit(EXIT_SUCCESS);
}

// Clear malloced line and exit the program as failure
void	ft_map_error(t_game *g, char *map_file)
{
	write(2, "Error\n", 6);
	free(g);
	free(map_file);
	exit(EXIT_FAILURE);
}

// Exit the program if there is a parsing error
void	ft_parse_error(t_game *g)
{
	write(2, "Error\n", 6);
	free(g);
	exit(EXIT_FAILURE);
}
