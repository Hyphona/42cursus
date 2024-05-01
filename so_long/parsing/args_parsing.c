/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:20:49 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/01 15:22:49 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Check if the argument is a valid map
int	check_args(t_game *g, int argc, char **argv)
{
	int		i;
	
	if (argc > 2)
		ft_parse_error(g);
	if (argc == 1)
		return (1);
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] && argv[1][i + 1] && argv[1][i + 2] && argv[1][i + 3] && !argv[1][i + 4])
			if (argv[1][i] == '.' && argv[1][i + 1] == 'b' && argv[1][i + 2] == 'e' && argv[1][i + 3] == 'r')
				return (1);
		i++;
	}
	return (0);
}
