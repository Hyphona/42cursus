/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:02:56 by alperrot          #+#    #+#             */
/*   Updated: 2024/02/19 09:40:08 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *s, char c, int print)
{
	t_stack	*tmp;
	size_t	size;
	
	if (!s || !s->next)
		return ;
	size = ft_ssize(s);
	tmp = s;
	tmp->next = NULL;
	while (size > 0)
	{
		s = s->next;
		size--;
	}
	s->next = tmp;
	if (print)
		ft_printf("s%c\n", c);
}

void	swap_s(t_stack *s_a, t_stack *s_b)
{
	if (!s_a || !s_a->next || !s_b || !s_b->next)
		return ;
	swap(s_a, 'a', 0);
	swap(s_b, 'b', 0);
	ft_printf("ss\n");
}
