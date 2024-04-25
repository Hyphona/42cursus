/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:30:34 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/25 14:22:58 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

t_level	*create_node(mlx_image_t *img, int x, int y)
{
	t_level	*new;

	new = malloc(sizeof(t_level));
	if (!new)
		return (NULL);
	new->img = img;
	new->next = NULL;
	new->prev = NULL;
	new->pos_x = x;
	new->pos_y = y;
	return (new);
}

t_level	*get_last(t_level *l)
{
	if (!l)
		return (NULL);
	while (l->next)
		l = l->next;
	return (l);
}

void	add_node(t_level **l, t_level *new)
{
	if (!*l)
		*l = new;
	else
	{
		new->prev = get_last(*l);
		new->prev->next = new;
	}
}

void	free_level(t_level *l)
{
	t_level	*tmp;

	while (l)
	{
		tmp = l;
		l = l->next;
		free(tmp);
	}
}
