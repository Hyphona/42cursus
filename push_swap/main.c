/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:27:56 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/24 19:28:19 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack	*s_a;

	if (ac < 2)
		return (0);
	if (!check_args(av))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	av++;
	s_a = NULL;
	s_a = parse(av, &s_a);
	if (!s_a)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (is_sorted(s_a))
	{
		free_stack(s_a);
		return (0);
	}
	free_stack(s_a);
	return (0);
}
