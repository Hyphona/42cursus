/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:27:56 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/19 14:15:16 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	char	*nb;
	t_stack	*s_a;
	
	if (ac < 2 || !check_args(av))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	av++;
	s_a = NULL;
	nb = "";
	while (*av)
	{
		if (ft_hasspace(*av))
		{
			i = 0;
			while ((*av)[i])
			{
				while (ft_isspace((*av)[i]) && (*av)[i])
					i++;
				while (!ft_isspace((*av)[i]) && (*av)[i])
				{
					nb = ft_strjoin(nb, (*av)[i]);
					i++;
				}
				add_node(&s_a, create_node(ft_atoi(nb)));
				if (nb)
					free(nb);
				nb = "";
				if ((*av)[i])
					i++;
			}
		}
		else
			add_node(&s_a, create_node(ft_atoi(*av)));
		av++;
	}
	return (0);
}
