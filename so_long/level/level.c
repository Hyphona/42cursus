/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:30:34 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/14 16:29:42 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_level	*get_block_at(t_level *l, int x, int y)
{
	if (!l)
		return (NULL);
	while (l->pos_y != y)
		l = l->next;
	while (l->pos_x != x)
		l = l->next;
	if ((l->pos_x != x) || (l->pos_y != y))
		return (NULL);
	return (l);
}

void	update_block_at(t_game *g, int x, int y, int type)
{
	mlx_image_t	*img;
	t_level		*l;

	if (type < 1 || type > 4)
		return ;
	l = get_block_at(g->level, x, y);
	if (!l)
		return ;
	img = NULL;
	if (type == 1)
		img = mlx_texture_to_image(g->mlx, mlx_load_png("./img/1.png"));
	else if (type == 2)
		img = mlx_texture_to_image(g->mlx, mlx_load_png("./img/2.png"));
	else if (type == 3)
		img = mlx_texture_to_image(g->mlx, mlx_load_png("./img/3.png"));
	else if (type == 4)
		img = mlx_texture_to_image(g->mlx, mlx_load_png("./img/4.png"));
	if (l->img)
		mlx_delete_image(g->mlx, l->img);
	if (!img || (mlx_image_to_window(g->mlx, img, x, y) < 0))
		ft_error(g);
	l->img = img;
	l->type = type;
}
