/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:19:25 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/25 19:34:33 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>

typedef struct s_level
{
	mlx_image_t		*img;
	int				pos_x;
	int				pos_y;
	int				type;
	struct s_level	*next;
	struct s_level	*prev;
}					t_level;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t 	*player;
	struct s_level 	*level;
}					t_game;

//level.c
t_level	*get_block_at(t_level *t, int x, int y);
void	update_block_at(t_game *g, t_level *l, int x, int y, int type);
//node.c
t_level	*create_node(mlx_image_t *img, int x, int y, int type);
t_level	*get_last(t_level *l);
void	add_node(t_level **l, t_level *new);
void	free_level(t_level *l);
//hook.c
void	ft_hook_close(void *param);
void	ft_hook_move(mlx_key_data_t keydata, void *param);
//loader.c
void	load_textures(t_game *g);
//utils.c
void	ft_clear(t_game *g);
void	ft_error(t_game *g);
void	ft_exit(t_game *g);

#endif