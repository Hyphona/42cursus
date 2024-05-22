/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:26:47 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/22 11:26:44 by alperrot         ###   ########.fr       */
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

static int	is_valid(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i + 1] <= '0' || str[i + 1] >= '9')
				return (0);
			if (str[i - 1])
			{
				if (!is_space(str[i - 1]))
					return (0);
			}
		}
		i++;
	}
	return (1);
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
			add_node(s_a, create_node(ft_atoi(nb, s_a, 1)));
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
		if (!is_valid(*av))
			error(s_a);
		if (has_space(*av))
		{
			if (is_empty(*av))
				error(s_a);
			sub_parsing(*av, s_a);
		}
		else
			add_node(s_a, create_node(ft_atoi(*av, s_a, 0)));
		av++;
	}
	check_double(s_a);
	return (*s_a);
}
