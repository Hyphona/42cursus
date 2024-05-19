/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:24:39 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/19 15:55:22 by alperrot         ###   ########.fr       */
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
