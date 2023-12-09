/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:11:33 by rallouan          #+#    #+#             */
/*   Updated: 2023/10/23 17:47:27 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	char	**map;

	if (argc == 2)
	{
		map = check_map(argv[1]);
		game = NULL;
		if (! map)
			return (0);
		if (! game_start(game, map))
			return (0);
		ft_free_all(map);
	}
	return (0);
}
