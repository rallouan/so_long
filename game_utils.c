/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:29:54 by rallouan          #+#    #+#             */
/*   Updated: 2023/10/23 17:40:47 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*ft_initialize(char **map)
{
	t_game	*game;
	int		i;

	game = malloc (1 * sizeof(t_game));
	if (! game)
		return (NULL);
	i = 0;
	while (map[i])
		i++;
	game->map = map;
	game->width = ft_strlen(map[0]) * 50;
	game->height = i * 50;
	game->collectible = ft_content_check(map, 'C');
	game->moves = 0;
	game->p_x = ft_get_x(map, 'P');
	game->p_y = ft_get_y(map[game->p_x], 'P');
	game->e_x = ft_get_x(map, 'E');
	game->e_y = ft_get_y(map[game->e_x], 'E');
	return (game);
}

void	ft_set_textures(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./textures/taytay.png");
	game->taylor = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./textures/floor.png");
	game->floor = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./textures/wall.png");
	game->tree = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./textures/scarf.png");
	game->scarf = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./textures/vault.png");
	game->vault = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
}

void	ft_draw_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1')
				mlx_image_to_window(game->mlx, game->floor, j * 50, i * 50);
			if (game->map[i][j] == '1')
				mlx_image_to_window(game->mlx, game->tree, j * 50, i * 50);
			else if (game->map[i][j] == 'P')
				mlx_image_to_window(game->mlx, game->taylor, j * 50, i * 50);
			else if (game->map[i][j] == 'C')
				mlx_image_to_window(game->mlx, game->scarf, j * 50, i * 50);
			if (i == game->e_x && j == game->e_y)
				mlx_image_to_window(game->mlx, game->vault, j * 50, i * 50);
			j++;
		}
		i++;
	}
	ft_show_moves(game);
}

void	ft_show_moves(t_game *game)
{
	char	*s_moves;

	s_moves = ft_itoa(game->moves);
	mlx_put_string(game->mlx, "Moves: ", 0, 0);
	mlx_put_string(game->mlx, s_moves, 140, 0);
	free(s_moves);
}
