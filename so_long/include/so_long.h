/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:19:25 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/15 10:11:49 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <fcntl.h>

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
	mlx_image_t		*player;
	size_t			spawn_x;
	size_t			spawn_y;
	int				collectibles;
	size_t			map_w;
	size_t			map_h;
	int				has_spawn;
	int				has_exit;
	struct s_level	*level;
}					t_game;

int			is_wall(t_game *game, int x, int y);
int			is_grass(t_game *game, int x, int y);
int			is_collectible(t_game *game, int x, int y);
int			is_exit(t_game *game, int x, int y);
t_level		*get_block_at(t_level *t, int x, int y);
void		update_block_at(t_game *g, int x, int y, int type);
t_level		*create_node(mlx_image_t *img, int x, int y, int type);
t_level		*get_last(t_level *l);
void		add_node(t_level **l, t_level *new);
void		free_level(t_level *l);
void		close_window_listener(void *param);
void		p_move_listener(mlx_key_data_t keydata, void *param);
mlx_image_t	*get_texture(t_game *g, char c);
int			get_type(char c);
void		load(t_game *g, char *map);
int			check_args(t_game *g, int argc, char **argv);
char		*get_map(t_game *g, char *map_name);
int			check_path(char *map);
int			check_wall(char *map);
int			can_move_to(t_game *game, int x, int y);
void		spawn_player(t_game *g, int x, int y);
int			update_player_pos(t_game *g, int x, int y);
void		set_spawn(t_game *g, int x, int y);
void		ft_clear(t_game *g);
void		ft_error(t_game *g);
void		ft_exit(t_game *g);
void		ft_map_error(t_game *g, char *map_file, char *text, int fd);
void		ft_parse_error(t_game *g, char *text);

#endif