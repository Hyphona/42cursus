/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:41:45 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/12 13:49:44 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Create a new level node
// Inspired by Minecraft, each node is a block
t_level	*create_node(mlx_image_t *img, int x, int y, int type)
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
	new->type = type;
	return (new);
}

// Get the last node of the level
t_level	*get_last(t_level *l)
{
	if (!l)
		return (NULL);
	while (l->next)
		l = l->next;
	return (l);
}

// Add a new node to the level
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

// Free the level
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
