/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:27:56 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/22 09:57:31 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

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

static int	check(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i][0] == '\0')
			return (0);
		i++;
	}
	if (!check_args(av))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*s_a;
	t_stack	*s_b;

	if (ac < 2)
		return (0);
	if (!check(av))
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
	set_index(s_a);
	sort(&s_a, &s_b);
	free_stack(s_a);
	if (s_b)
		free_stack(s_b);
	return (0);
}
