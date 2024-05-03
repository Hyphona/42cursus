/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:20:49 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/03 08:09:24 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Check if the argument is a valid map
int	check_args(t_game *g, int argc, char **argv)
{
	int		i;

	if (argc > 2)
		ft_parse_error(g, "Too many arguments");
	if (argc == 1)
		return (0);
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] && argv[1][i + 1] && argv[1][i + 2]
			&& argv[1][i + 3] && !argv[1][i + 4])
		{
			if (argv[1][i] == '.' && argv[1][i + 1] == 'b'
				&& argv[1][i + 2] == 'e' && argv[1][i + 3] == 'r')
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (0);
}
