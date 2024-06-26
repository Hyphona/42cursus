/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:27:31 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/14 16:29:31 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_wall(t_game *game, int x, int y)
{
	t_level	*block;

	block = get_block_at(game->level, x, y);
	if (block->type == 1)
		return (1);
	return (0);
}

int	is_grass(t_game *game, int x, int y)
{
	t_level	*block;

	block = get_block_at(game->level, x, y);
	if (block->type == 2)
		return (1);
	return (0);
}

int	is_collectible(t_game *game, int x, int y)
{
	t_level	*block;

	block = get_block_at(game->level, x, y);
	if (block->type == 3)
		return (1);
	return (0);
}

int	is_exit(t_game *game, int x, int y)
{
	t_level	*block;

	block = get_block_at(game->level, x, y);
	if (block->type == 4)
		return (1);
	return (0);
}
