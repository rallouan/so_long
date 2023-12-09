/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:40:19 by rallouan          #+#    #+#             */
/*   Updated: 2023/10/23 17:42:55 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W)
		|| mlx_is_key_down(game->mlx, MLX_KEY_UP))
		ft_move(game, game->p_x - 1, game->p_y);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S)
		|| mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		ft_move(game, game->p_x + 1, game->p_y);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A)
		|| mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		ft_move(game, game->p_x, game->p_y - 1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D)
		|| mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		ft_move(game, game->p_x, game->p_y + 1);
}

void	ft_update_player(t_game *game)
{
	game->p_x = ft_get_x(game->map, 'P');
	game->p_y = ft_get_y(game->map[game->p_x], 'P');
}

void	ft_move(t_game *game, int row, int col)
{
	if (game->map[row][col] == '0' || game->map[row][col] == 'C')
	{
		if (game->map[row][col] == 'C')
			game->collectible--;
		game->map[game->p_x][game->p_y] = '0';
		game->map[row][col] = 'P';
		ft_printf("Moves: %d\n", ++(game->moves));
	}
	if (game->map[row][col] == 'E')
	{
		game->map[game->p_x][game->p_y] = '0';
		game->map[row][col] = 'P';
		ft_printf("Moves: %d\n", ++(game->moves));
	}
	if (game->collectible == 0 && row == game->e_x
		&& col == game->e_y)
	{
		ft_free_all(game->map);
		exit(1);
	}
	ft_update_player(game);
	ft_draw_map(game);
}

int	game_start(t_game *game, char **map)
{
	game = ft_initialize(map);
	if (! game)
		return (0);
	game->mlx = mlx_init(game->width, game->height, "Taylor's Version", false);
	if (! game->mlx)
	{
		ft_printf("MlX error: %s\n", mlx_strerror(mlx_errno));
		return (0);
	}
	ft_set_textures(game);
	ft_draw_map(game);
	mlx_loop_hook(game->mlx, ft_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game);
	return (1);
}
