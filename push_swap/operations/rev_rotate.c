/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:07:33 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/17 16:17:34 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void static	rev_rotate(t_stack **head)
{
	t_stack	*current;
	int		tmp;

	current = get_last(*head);
	tmp = current->nb;
	while (current->prev)
	{
		current->nb = current->prev->nb;
		current = current->prev;
	}
	current->nb = tmp;
}

void	rev_rotate_a(t_stack **head)
{
	if (!*head || !(*head)->next)
		return ;
	rev_rotate(head);
	write(1, "rra\n", 3);
}

void	rev_rotate_b(t_stack **head)
{
	if (!*head || !(*head)->next)
		return ;
	rev_rotate(head);
	write(1, "rrb\n", 3);
}

void	rev_rotate_r(t_stack **s_a, t_stack **s_b)
{
	if (!*s_a || !*s_b || !(*s_a)->next || !(*s_b)->next)
		return ;
	rev_rotate(s_a);
	rev_rotate(s_b);
	write(1, "rrr\n", 3);
}
