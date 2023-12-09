/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:57:22 by rallouan          #+#    #+#             */
/*   Updated: 2023/10/19 13:26:53 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_fill(char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == '2')
		return ;
	map[x][y] = '2';
	map_fill(map, x - 1, y);
	map_fill(map, x + 1, y);
	map_fill(map, x, y - 1);
	map_fill(map, x, y + 1);
}

int	ft_path_check(char **map, int x, int y)
{
	map_fill(map, x, y);
	if (ft_content_check(map, 'C')
		|| ft_content_check(map, 'E') == 1)
		return (0);
	return (1);
}

//checks if player can go from P to E and collect all C
// Makes a copy of the matrix and uses the copy to check
int	ft_valid_path(char **matrix)
{
	char	**copy;
	int		p_x;
	int		p_y;
	int		valid;

	copy = ft_copy_map(matrix);
	p_x = ft_get_x(matrix, 'P');
	p_y = ft_get_y(matrix[p_x], 'P');
	valid = ft_path_check(copy, p_x, p_y);
	ft_free_all(copy);
	return (valid);
}
