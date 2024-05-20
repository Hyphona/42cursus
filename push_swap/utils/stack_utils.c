/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:04:37 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/19 19:43:50 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_size(t_stack *s)
{
	int		size;

	if (!s)
		return (0);
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
	t_stack	*tmp;
	t_stack	*current;
	int		i;

	tmp = s;
	current = s;
	while (tmp)
	{
		i = 0;
		while (current)
		{
			if (tmp->nb > current->nb)
				i++;
			current = current->next;
		}
		tmp->index = i;
		tmp = tmp->next;
		current = s;
	}
}
