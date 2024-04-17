/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:55:31 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/17 16:07:21 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stack	*create_stack(int nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->index = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack *getItemAt(t_stack *head, int index)
{
	if (!head)
		return (NULL);
	while (head->index != index)
		head = head->next;
	return (head);
}

t_stack	*getLast(t_stack *s)
{
	if (!s)
		return (NULL);
	while (s->next)
		s = s->next;
	return (s);
}
