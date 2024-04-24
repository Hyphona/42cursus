/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:27:56 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/24 21:42:46 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"
#include <stdio.h> //DEBUG ONLY

/*
 * This function prints the stacks A and B (just for debug purposes)
 */
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
	printf("_  _\nA  B\n------------\n");
}

static t_stack	*init_stack_a(char **av)
{
	t_stack	*s_a;

	s_a = NULL;
	s_a = parse(av, &s_a);
	if (!s_a)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	return (s_a);
}

static t_stack	*init_stack_b(t_stack **s_a)
{
	t_stack	*s_b;

	s_b = NULL;
	push_b(s_a, &s_b);
	print_stack(*s_a, s_b);
	push_b(s_a, &s_b);
	return (s_b);
}

int	main(int ac, char **av)
{
	t_stack	*s_a;
	t_stack	*s_b;

	if (ac < 2)
		return (0);
	if (!check_args(av))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	av++;
	s_a = init_stack_a(av);
	if (is_sorted(s_a))
	{
		free_stack(s_a);
		return (0);
	}
	s_b = NULL;
	s_b = init_stack_b(&s_a);
	free_stack(s_a);
	free_stack(s_b);
	return (0);
}
