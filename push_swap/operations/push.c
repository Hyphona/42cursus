/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:23:46 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/24 21:23:19 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_stack **s_a, t_stack **s_b)
{
	t_stack	*tmp;

	if (!*s_b)
		return ;
	tmp = *s_a;
	*s_a = *s_b;
	*s_b = (*s_b)->next;
	(*s_a)->next = tmp;
	write(1, "pa\n", 3);
}

void	push_b(t_stack **s_a, t_stack **s_b)
{
	t_stack	*tmp;

	if (!*s_a)
		return ;
	tmp = *s_b;
	*s_b = *s_a;
	*s_a = (*s_a)->next;
	(*s_b)->next = tmp;
	write(1, "pb\n", 3);
}
