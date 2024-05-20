/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:26:47 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/20 12:22:05 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	error(t_stack **s)
{
	free_stack(*s);
	write(2, "Error\n", 6);
	exit(0);
}

static void	check_double(t_stack **s)
{
	t_stack	*tmp;
	t_stack	*current;

	tmp = *s;
	while (tmp)
	{
		current = tmp->next;
		while (current)
		{
			if (tmp->nb == current->nb)
				error(s);
			current = current->next;
		}
		tmp = tmp->next;
	}
}

static void	sub_parsing(char *av, t_stack **s_a)
{
	int		i;
	char	*nb;

	i = 0;
	nb = "";
	while (av[i])
	{
		while (is_space(av[i]) && av[i])
			i++;
		if (av[i])
		{
			while (av[i] && !is_space(av[i]))
			{
				nb = ft_joinchar(nb, av[i]);
				if (!nb)
					error(s_a);
				i++;
			}
			add_node(s_a, create_node(ft_atoi(nb)));
			free(nb);
			nb = "";
			if (av[i])
				i++;
		}
	}
}

t_stack	*parse(char **av, t_stack **s_a)
{
	while (*av)
	{
		if (has_space(*av))
			sub_parsing(*av, s_a);
		else
			add_node(s_a, create_node(ft_atoi(*av)));
		av++;
	}
	check_double(s_a);
	return (*s_a);
}
