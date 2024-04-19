/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:55:31 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/19 13:48:00 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	if (!*s)
		*s = new;
	else
		(get_last(*s))->next = new;
}

t_stack	*get_last(t_stack *s)
{
	if (!s)
		return (NULL);
	while (s->next)
		s = s->next;
	return (s);
}
