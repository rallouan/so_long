/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:27:19 by rallouan          #+#    #+#             */
/*   Updated: 2023/10/05 12:14:13 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Checks if the given map is .ber or not
int	ft_extension(char *argv)
{
	char	**path;
	char	**name;
	int		i;

	path = ft_split(argv, '/');
	if (!path || !*path)
		return (0);
	i = 0;
	while (path[i])
		i++;
	if (path[i - 1][ft_strlen(path[i - 1]) - 1] == '.')
		return (ft_free_all(path), 0);
	name = ft_split(path[i - 1], '.');
	if (!name || !*name)
		return (ft_free_all(path), 0);
	ft_free_all(path);
	if (ft_strlen(name[1]) == 3
		&& ft_strncmp(name[1], "ber", ft_strlen(name[1])) == 0 && !name[2])
	{
		ft_free_all(name);
		return (1);
	}
	ft_free_all(name);
	return (0);
}

// Check if the provided file can be opened
// Reads the map, checks if it has wrong chars
// Returns the matrix
char	**ft_map_read(char *file)
{
	char	**matrix;
	char	*line;
	char	*map;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	map = malloc(1 * sizeof(char *));
	while (line != NULL)
	{
		map = gnl_strjoin(map, line);
		free(line);
		line = get_next_line(fd);
	}
	if (double_nl(map) == 1 || ft_wrong_content_check(map) == 0)
		return (free(map), NULL);
	matrix = ft_split(map, '\n');
	free(line);
	free(map);
	return (matrix);
}

/*
1 - check file extension √
2 - check if file can be opened and read it √
	- checks if dounle nl || wrong chars exist √
3 - check matrix √
	- if rectangle √
	- if walls √
4 - Check that components exist the right amount of times
5 - check valid path
*/
char	**check_map(char *argv)
{
	char	**matrix;

	if (!ft_extension(argv))
		return (ft_printf("Error\n"), NULL);
	matrix = ft_map_read(argv);
	if (!matrix)
		return (ft_printf("Error\n"), NULL);
	if (! *matrix)
		return (ft_printf("Error\n"), ft_free_all(matrix), NULL);
	if (!ft_rectangle(matrix))
		return (ft_printf("Error\n"), ft_free_all(matrix), NULL);
	if (!ft_walls(matrix))
		return (ft_printf("Error\n"), ft_free_all(matrix), NULL);
	if (ft_content_check(matrix, 'E') != 1)
		return (ft_printf("Error\n"), ft_free_all(matrix), NULL);
	if (ft_content_check(matrix, 'P') != 1)
		return (ft_printf("Error\n"), ft_free_all(matrix), NULL);
	if (ft_content_check(matrix, 'C') < 1)
		return (ft_printf("Error\n"), ft_free_all(matrix), NULL);
	if (! ft_valid_path(matrix))
		return (ft_printf("Error\n"), ft_free_all(matrix), NULL);
	return (matrix);
}
