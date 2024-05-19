/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:55:05 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/19 15:31:14 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_max(t_stack *s, int max)
{
	t_stack	*tmp;
	int		pos;

	tmp = s;
	pos = 0;
	while (tmp && tmp->index != max)
	{
		tmp = tmp->next;
		pos++;
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
			swap_a(*s_a);
	}
	else if (size == 3)
		three_sort(s_a);
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
