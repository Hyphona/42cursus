/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:37:23 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/18 01:07:37 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack **head)
{
	int	tmp;

	tmp = (*head)->nb;
	while ((*head)->next)
	{
		(*head)->nb = (*head)->next->nb;
		*head = (*head)->next;
	}
	(*head)->nb = tmp;
}

void	rotate_a(t_stack **head)
{
	if (!*head || !(*head)->next)
		return ;
	rotate(head);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **head)
{
	if (!*head || !(*head)->next)
		return ;
	rotate(head);
	write(1, "rb\n", 3);
}

void	rotate_r(t_stack **s_a, t_stack **s_b)
{
	if (!*s_a || !*s_b || !(*s_a)->next || !(*s_b)->next)
		return ;
	rotate(s_a);
	rotate(s_b);
	write(1, "rr\n", 3);
}
