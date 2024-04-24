/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:27:56 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/24 16:31:21 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"
#include <stdio.h> //TESTING PURPOSES

int	main(int ac, char **av)
{
	t_stack	*s_a;
	t_stack	*tmp;

	if (ac < 2 || !check_args(av))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	av++;
	s_a = NULL;
	s_a = parse(av, &s_a);
	//START OF TESTING
	tmp = s_a;
	while (tmp)
	{
		printf("%d\n", tmp->nb);
		tmp = tmp->next;
	}
	//END OF TESTING
	free_stack(s_a);
	return (0);
}
