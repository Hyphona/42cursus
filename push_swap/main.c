/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:27:56 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/19 14:50:00 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	sub_parsing(char *av, t_stack *s_a)
{
	int		i;
	char	*nb;

	i = 0;
	nb = "";
	while (av[i])
	{
		while (ft_isspace(av[i]) && av[i])
			i++;
		while (!ft_isspace(av[i]) && av[i])
		{
			nb = ft_strjoin(nb, av[i]);
			i++;
		}
		if (nb[0] != '\0')
		{
			add_node(&s_a, create_node(ft_atoi(nb)));
			free(nb);
			nb = "";
			if (av[i])
				i++;
		}
	}
}

static void	parse(char **av)
{
	t_stack	*s_a;

	s_a = NULL;
	while (*av)
	{
		if (ft_hasspace(*av))
			sub_parsing(*av, s_a);
		else
			add_node(&s_a, create_node(ft_atoi(*av)));
		av++;
	}
}

int	main(int ac, char **av)
{
	if (ac < 2 || !check_args(av))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	av++;
	parse(av);
	return (0);
}
