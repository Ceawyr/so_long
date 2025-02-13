/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_praticable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:34:25 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/13 00:15:21 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_copy(char **map, char **visited)
{
	int	i;

	i = 0;
	while (map[i])
	{
		visited[i] = ft_strdup(map[i]);
		i++;
	}
}

t_map_dimension	*where_is_player(t_map_dimension *map)
{
	
}

void	is_it_praticable(t_map_dimension *map)
{
	char	**visited;

	visited = malloc(sizeof(char *) * map->y);
	map_copy(map->map, visited);
	map = where_is_player(map);
}