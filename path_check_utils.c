/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:57:44 by rallouan          #+#    #+#             */
/*   Updated: 2023/10/19 13:26:08 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_copy_map(char **map)
{
	int		i;
	int		size;
	char	**copy;

	size = 0;
	i = 0;
	while (map[size])
		size++;
	copy = malloc(sizeof(char *) * (size + 1));
	if (!copy)
		return (NULL);
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	ft_get_x(char **map, int c)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (ft_strchr(map[i], c))
			return (i);
		i++;
	}
	return (0);
}

int	ft_get_y(char *line, int c)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			return (i);
		i++;
	}
	return (i);
}
