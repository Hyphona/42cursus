/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:55:31 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/19 11:40:19 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*create_node(long nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->index = 0;
	new->target = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	add_node(t_stack **s, t_stack *new)
{
	if (!*s)
		*s = new;
	else
	{
		new->prev = get_last(*s);
		new->prev->next = new;
	}
}

t_stack	*get_last(t_stack *s)
{
	if (!s)
		return (NULL);
	while (s->next)
		s = s->next;
	return (s);
}

t_stack	*get_node_at(t_stack *s, int index)
{
	while (s)
	{
		if (s->index == index)
			return (s);
		s = s->next;
	}
	return (NULL);
}

void	free_stack(t_stack *s)
{
	t_stack	*tmp;

	while (s)
	{
		tmp = s;
		s = s->next;
		free(tmp);
	}
}
