/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:33:01 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/16 11:30:54 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

mlx_image_t	*get_texture(t_game *g, char c)
{
	mlx_image_t		*img;
	mlx_texture_t	*png;

	if (c == '0')
		png = mlx_load_png("./img/2.png");
	else if (c == '1')
		png = mlx_load_png("./img/1.png");
	else if (c == 'C')
		png = mlx_load_png("./img/3.png");
	else if (c == 'E')
		png = mlx_load_png("./img/4.png");
	else
		png = mlx_load_png("./img/2.png");
	img = mlx_texture_to_image(g->mlx, png);
	mlx_delete_texture(png);
	return (img);
}

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
