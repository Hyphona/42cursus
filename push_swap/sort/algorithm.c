/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 09:53:40 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/19 11:28:11 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static void	three_sort(t_stack **s)
{
	if ((*s)->nb > (*s)->next->nb && (*s)->nb < (*s)->next->next->nb)
		swap_a(*s);
	else if ((*s)->nb > (*s)->next->nb && (*s)->nb > (*s)->next->next->nb)
	{
		rotate_a(*s);
		if ((*s)->nb > (*s)->next->nb)
			swap_a(*s);
	}
	else if ((*s)->nb < (*s)->next->nb && (*s)->nb > (*s)->next->next->nb)
		rev_rotate_a(*s);
	else if ((*s)->nb < (*s)->next->nb && (*s)->nb > (*s)->next->next->nb)
		rotate_a(*s);
	else if ((*s)->nb < (*s)->next->nb && (*s)->next->nb > (*s)->next->next->nb)
	{
		swap_a(*s);
		rotate_a(*s);
	}
}

static void print_stack(t_stack *s_a, t_stack *s_b)
{
	while (s_a)
	{
		if (s_b){
			printf("%d  %d\n", s_a->nb, s_b->nb);
			s_a = s_a->next;
			s_b = s_b->next;
		}
		else
		{
			printf("%d  -\n", s_a->nb);
			s_a = s_a->next;
		}
	}
	if (s_b)
	{
		while (s_b)
		{
			printf("-  %d\n", s_b->nb);
			s_b = s_b->next;
		}
	}
	printf("_  _\nA  B\n\n");
}

static void	smart_sort(t_stack **s_a, t_stack **s_b)
{
	int	size_a;

	size_a = stack_size(*s_a);
}

void	sort(t_stack **s_a, t_stack **s_b)
{
	int		*tab;
	int		size;

	size = stack_size(*s_a);
	tab = stack_to_tab(*s_a, size);
	if (size == 2)
	{
		if (tab[0] > tab[1])
			swap_a(*s_a);
	}
	else if (size == 3)
		three_sort(s_a);
	/*else
		quick_sort(s_a, s_b, tab, size);*/
	print_stack(*s_a, *s_b);
	free(tab);
}
