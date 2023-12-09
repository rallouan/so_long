/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:03:03 by rallouan          #+#    #+#             */
/*   Updated: 2023/10/23 17:40:53 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/lib.h"
# include <fcntl.h>
# include "./MLX42/include/MLX42/MLX42.h"

typedef struct s_game
{
	mlx_t		*mlx;
	int			height;
	int			width;
	int			moves;
	int			collectible;
	int			p_x;
	int			p_y;
	int			e_x;
	int			e_y;
	char		**map;
	mlx_image_t	*taylor;
	mlx_image_t	*floor;
	mlx_image_t	*tree;
	mlx_image_t	*scarf;
	mlx_image_t	*vault;
}	t_game;

//Map parsing funcs
int		ft_extension(char *argv);
char	**ft_map_read(char *file);
char	**check_map(char *argv);

// Map parsing utils funcs
int		double_nl(char *str);
int		ft_wrong_content_check(char *map);
int		ft_rectangle(char **map);
int		ft_walls(char **map);
int		ft_content_check(char **matrix, int c);

// Path check funcs
void	map_fill(char **map, int x, int y);
int		ft_path_check(char **map, int x, int y);
int		ft_valid_path(char **matrix);

// Path check utils funcs
char	**ft_copy_map(char **map);
int		ft_get_x(char **map, int c);
int		ft_get_y(char *line, int c);

// Game utils funcs
t_game	*ft_initialize(char **map);
void	ft_set_textures(t_game *game);
void	ft_draw_map(t_game *game);
void	ft_show_moves(t_game *game);
// void	ft_add_comp(t_game *game, int c, mlx_image_t *img);

// Game funcs
// void	ft_game_hooks(void *param);
// void	ft_make_move(t_game *game, int i, int j);
void	ft_hook(void *param);
void	ft_move(t_game *game, int row, int col);
int		game_start(t_game *game, char **map);

#endif