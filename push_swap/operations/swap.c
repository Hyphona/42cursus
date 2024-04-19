/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:02:56 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/18 01:07:47 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_stack *s)
{
	int	tmp;

	tmp = s->nb;
	s->nb = s->next->nb;
	s->next->nb = tmp;
}

void	swap_a(t_stack *s)
{
	if (!s || !s->next)
		return ;
	swap(s);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *s)
{
	if (!s || !s->next)
		return ;
	swap(s);
	write(1, "sb\n", 3);
}

void	swap_s(t_stack *s_a, t_stack *s_b)
{
	if (!s_a || !s_a->next || !s_b || !s_b->next)
		return ;
	swap(s_a);
	swap(s_b);
	write(1, "ss\n", 3);
}
