/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:02:56 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/19 15:50:48 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_stack *s)
{
	int	n_tmp;
	int	i_tmp;

	n_tmp = s->nb;
	i_tmp = s->index;
	s->nb = s->next->nb;
	s->next->nb = n_tmp;
	s->next->index = i_tmp;
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
