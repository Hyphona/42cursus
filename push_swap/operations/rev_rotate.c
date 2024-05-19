/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:07:33 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/19 18:54:46 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rev_rotate(t_stack **s)
{
	t_stack	*tmp;

	if (!*s || !(*s)->next)
		return ;
	tmp = get_last(*s);
	tmp->prev->next = NULL;
	tmp->next = *s;
	tmp->prev = NULL;
	*s = tmp;
	tmp->next->prev = tmp;
}

void	rev_rotate_a(t_stack **s)
{
	if (!*s || !(*s)->next)
		return ;
	rev_rotate(s);
	write(1, "rra\n", 4);
}

void	rev_rotate_b(t_stack **s)
{
	if (!*s || !(*s)->next)
		return ;
	rev_rotate(s);
	write(1, "rrb\n", 4);
}

void	rev_rotate_r(t_stack **s_a, t_stack **s_b)
{
	if (!*s_a || !*s_b || !(*s_a)->next || !(*s_b)->next)
		return ;
	rev_rotate(s_a);
	rev_rotate(s_b);
	write(1, "rrr\n", 4);
}
