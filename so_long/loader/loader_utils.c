/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:33:01 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/01 12:50:11 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Select the right texture for the block
mlx_image_t	*get_texture(t_game *g, char c)
{
	mlx_image_t	*img;

	if(c == '0')
		img = mlx_texture_to_image(g->mlx, mlx_load_png("./img/2.png"));
	else if(c == '1')
		img = mlx_texture_to_image(g->mlx, mlx_load_png("./img/1.png"));
	else if(c == 'C')
		img = mlx_texture_to_image(g->mlx, mlx_load_png("./img/3.png"));
	else if(c == 'E')
		img = mlx_texture_to_image(g->mlx, mlx_load_png("./img/4.png"));
	else
		img = mlx_texture_to_image(g->mlx, mlx_load_png("./img/2.png"));
	return (img);
}

// Get the type of the block depending on the character
// Type 1: Wall
// Type 2: Grass
// Type 3: Collectible
// Type 4: Exit
int	get_type(char c)
{
	if (c == '0')
		return (2);
	else if (c == '1')
		return (1);
	else if (c == 'C')
		return (3);
	else if (c == 'E')
		return (4);
	else
		return (2);
	return (0);
}
