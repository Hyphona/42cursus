/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:23:46 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/19 19:19:49 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_stack **s_a, t_stack **s_b)
{
	t_stack	*tmp;

	if (!*s_b)
		return ;
	tmp = *s_b;
	*s_b = (*s_b)->next;
	if (*s_b)
		(*s_b)->prev = NULL;
	tmp->prev = NULL;
	if (!*s_a)
	{
		*s_a = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = *s_a;
		tmp->next->prev = tmp;
		*s_a = tmp;
	}
	write(1, "pa\n", 3);
}

void	push_b(t_stack **s_a, t_stack **s_b)
{
	t_stack	*tmp;

	if (!*s_a)
		return ;
	tmp = *s_a;
	*s_a = (*s_a)->next;
	if (*s_a)
		(*s_a)->prev = NULL;
	tmp->prev = NULL;
	if (!*s_b)
	{
		*s_b = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = *s_b;
		tmp->next->prev = tmp;
		*s_b = tmp;
	}
	write(1, "pb\n", 3);
}
