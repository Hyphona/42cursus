/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 09:53:40 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/19 19:27:39 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	three_sort(t_stack **s)
{
	if ((*s)->nb > (*s)->next->nb && (*s)->nb < (*s)->next->next->nb)
		swap_a(s);
	else if ((*s)->nb > (*s)->next->nb && (*s)->nb > (*s)->next->next->nb)
	{
		rotate_a(s);
		if ((*s)->nb > (*s)->next->nb)
			swap_a(s);
	}
	else if ((*s)->nb < (*s)->next->nb && (*s)->nb > (*s)->next->next->nb)
		rev_rotate_a(s);
	else if ((*s)->nb < (*s)->next->nb && (*s)->nb > (*s)->next->next->nb)
		rotate_a(s);
	else if ((*s)->nb < (*s)->next->nb && (*s)->next->nb > (*s)->next->next->nb)
	{
		swap_a(s);
		rotate_a(s);
	}
}

static void print_stack(t_stack *s_a, t_stack *s_b)
{
	while (s_a)
	{
		if (s_b){
			printf("%d  %d\n", (int)s_a->nb, (int)s_b->nb);
			s_a = s_a->next;
			s_b = s_b->next;
		}
		else
		{
			printf("%d  -\n", (int)s_a->nb);
			s_a = s_a->next;
		}
	}
	if (s_b)
	{
		while (s_b)
		{
			printf("-  %d\n", (int)s_b->nb);
			s_b = s_b->next;
		}
	}
	printf("_  _\nA  B\n\n");
}

static void	finish_sort(t_stack **s_a, t_stack **s_b)
{
	int		size;
	int		pos;

	while (*s_b)
	{
		size = stack_size(*s_b);
		pos = get_max(*s_b, size) - 1;
		if (pos > stack_size(*s_b) / 2)
			while ((*s_b)->index != size)
			{
				printf("size = %d/%d:%d\n", size, stack_size((*s_b)), (*s_b)->index);
				rev_rotate_b(s_b);
			}
		else
			while ((*s_b)->index != size)
				rotate_b(s_b);
		push_a(s_a, s_b);
	}
}

void	butterfly(t_stack **s_a, t_stack **s_b, int chunk)
{
	int		i;
	int		size;
	int		track;
	int		elem_in_chunk;

	size = stack_size(*s_a);
	elem_in_chunk = size / chunk;
	track = elem_in_chunk;
	while (*s_a)
	{
		i = 0;
		while (i < elem_in_chunk && *s_a)
		{
			if ((*s_a)->index < track)
			{
				push_b(s_a, s_b);
				if ((*s_b)->index > (track - size / (chunk * 2)))
					rotate_b(s_b);
				i++;
			}
			else
				rotate_a(s_a);
		}
		track += elem_in_chunk;
	}
}
void	sort(t_stack **s_a, t_stack **s_b)
{
	sort_selector(s_a, s_b);
	print_stack(*s_a, *s_b);
	if (!is_sorted(*s_a))
		finish_sort(s_a, s_b);
	print_stack(*s_a, *s_b);
}
