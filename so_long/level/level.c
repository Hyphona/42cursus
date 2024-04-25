/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:30:34 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/25 19:59:05 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Get the block at the specified position
// Return NULL if the block does not exist
t_level	*get_block_at(t_level *l, int x, int y)
{
	if (!l)
		return (NULL);
	while ((l->pos_x != x) && (l->pos_y != y))
		l = l->next;
	if ((l->pos_x != x) && (l->pos_y != y))
		return (NULL);
	return (l);
}

// Update the block at the specified position with the specified type
// Type 1: Grass
// Type 2: Object that can be taken by player
// Type 3: Wall
// Do nothing if the type is not valid or if the block does not exist
void	update_block_at(t_game *g, t_level *l, int x, int y, int type)
{
	mlx_image_t *img;

	if (type < 1 || type > 3)
		return ;
	l = get_block_at(l, x, y);
	if (!l)
		return ;
	img = NULL;
	if (type == 1)
		img = mlx_texture_to_image(g->mlx, mlx_load_png("./img/1.png"));
	else if (type == 2)
		img = mlx_texture_to_image(g->mlx, mlx_load_png("./img/2.png"));
	else if (type == 3)
		img = mlx_texture_to_image(g->mlx, mlx_load_png("./img/3.png"));
	if (!img || (mlx_image_to_window(g->mlx, img, x, y) < 0))
		ft_error(g);
	mlx_delete_image(g->mlx, l->img);
	l->img = img;
	l->type = type;
}
