/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:27:56 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/24 16:24:10 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"
#include <stdio.h> //TESTING PURPOSES

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

static t_stack	*parse(char **av, t_stack **s_a)
{
	while (*av)
	{
		if (has_space(*av))
			sub_parsing(*av, s_a);
		else
			add_node(s_a, create_node(ft_atoi(*av)));
		av++;
	}
	return (*s_a);
}

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
