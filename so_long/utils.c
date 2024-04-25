/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:53:40 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/25 16:02:08 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

// Clear all game data, except the t_game structure.
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
	ft_printf("%s", mlx_strerror(mlx_errno));
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
