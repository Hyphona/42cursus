/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:55:05 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/20 13:09:07 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *s)
{
	if (!s)
		return (0);
	while (s->next)
	{
		if (s->nb > s->next->nb)
			return (0);
		s = s->next;
	}
	return (1);
}

int	get_max(t_stack *s, int max)
{
	t_stack	*tmp;
	int		pos;

	tmp = s;
	pos = 0;
	while (tmp && tmp->index != max)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

void	sort_selector(t_stack **s_a, t_stack **s_b)
{
	int		size;

	size = stack_size(*s_a);
	if (size == 2)
	{
		if ((*s_a)->nb > (*s_a)->next->nb)
			swap_a(s_a);
	}
	else if (size == 3)
		three_sort(s_a);
	else if (size == 4)
		butterfly(s_a, s_b, 1);
	else if (size == 5)
		five_sort(s_a, s_b);
	else if (size >= 6 && size <= 100)
		butterfly(s_a, s_b, 3);
	else if (size > 100 && size <= 200)
		butterfly(s_a, s_b, 4);
	else if (size > 200 && size <= 300)
		butterfly(s_a, s_b, 5);
	else if (size > 300 && size <= 400)
		butterfly(s_a, s_b, 6);
	else
		butterfly(s_a, s_b, 8);
}
