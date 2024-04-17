/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:55:31 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/17 16:27:05 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stack	*create_node(int nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	add_node(t_stack **s, t_stack *new)
{
	t_stack	*last;

	if (!*s)
		*s = new;
	last = get_last(*s);
	last->next = new;
	new->prev = last;
}

t_stack	*get_last(t_stack *s)
{
	if (!s)
		return (NULL);
	while (s->next)
		s = s->next;
	return (s);
}
