/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:04:37 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/19 11:42:53 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_size(t_stack *s)
{
	int		size;

	size = 0;
	while (s)
	{
		size++;
		s = s->next;
	}
	return (size);
}

void	set_index(t_stack *s)
{
	int		i;
	int		median;

	i = 0;
	median = stack_size(s) / 2;
	while (s)
	{
		s->index = i;
		if (i > median)
			s->above_median = 1;
		else
			s->above_median = 0;
		s = s->next;
		i++;
	}
}
