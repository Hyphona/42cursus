/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:37:23 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/19 15:49:00 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack *s)
{
	int	n_tmp;
	int	i_tmp;

	n_tmp = s->nb;
	i_tmp = s->index;
	while (s->next)
	{
		s->nb = s->next->nb;
		s->index = s->next->index;
		s = s->next;
	}
	s->nb = n_tmp;
	s->index = i_tmp;
}

void	rotate_a(t_stack *s)
{
	if (!s || !s->next)
		return ;
	rotate(s);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack *s)
{
	if (!s || !s->next)
		return ;
	rotate(s);
	write(1, "rb\n", 3);
}

void	rotate_r(t_stack *s_a, t_stack *s_b)
{
	if (!s_a || !s_b || !s_a->next || !s_b->next)
		return ;
	rotate(s_a);
	rotate(s_b);
	write(1, "rr\n", 3);
}
