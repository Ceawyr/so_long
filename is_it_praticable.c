/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_praticable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:34:25 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/14 01:06:50 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_copy(char **map, char **visited)
{
	int	i;

	i = 0;
	while (map[i])
	{
		visited[i] = ft_strdup_map(map[i]);
		if (!visited[i])
		{
			free_tab(visited);
			free_tab(map);
			ft_exit(6);
		}
		i++;
	}
	visited[i] = NULL;
}

static int	check_c(t_map_dimension *map, int y_p, int x_p, char **visite)
{
	int	collected;

	collected = 0;
	if (y_p < 0 || y_p >= map->y || x_p < 0 || x_p >= map->x)
		return (0);
	if (visite[y_p][x_p] == 'V')
		return (0);
	if (map->map[y_p][x_p] == '1')
		return (0);
	visite[y_p][x_p] = 'V';
	if (map->map[y_p][x_p] == 'C')
		collected++;
	collected += check_c(map, y_p + 1, x_p, visite);
	collected += check_c(map, y_p - 1, x_p, visite);
	collected += check_c(map, y_p, x_p + 1, visite);
	collected += check_c(map, y_p, x_p - 1, visite);
	return (collected);
}

static int	flood_fill(t_map_dimension *map, int y_p, int x_p, char **visited)
{
	if (y_p < 0 || y_p >= map->y || x_p < 0 || x_p >= map->x)
		return (0);
	if (visited[y_p][x_p] == 'V')
		return (0);
	if (map->map[y_p][x_p] == '1')
		return (0);
	visited[y_p][x_p] = 'V';
	if (map->map[y_p][x_p] == 'E')
		return (1);
	if (flood_fill(map, y_p + 1, x_p, visited))
		return (1);
	if (flood_fill(map, y_p - 1, x_p, visited))
		return (1);
	if (flood_fill(map, y_p, x_p + 1, visited))
		return (1);
	if (flood_fill(map, y_p, x_p - 1, visited))
		return (1);
	return (0);
}

static int	player_can_exit(t_map_dimension *map, char **visited)
{
	int	x_p;
	int	y_p;

	y_p = 0;
	while (map->map[y_p])
	{
		x_p = 0;
		while (map->map[y_p][x_p])
		{
			if (map->map[y_p][x_p] == 'P')
			{
				map->player_x_pos = x_p;
				map->player_y_pos = y_p;
				if (check_c(map, y_p, x_p, visited) != map->colectible)
					return (0);
				map_copy(map->map, visited);
				return (flood_fill(map, y_p, x_p, visited));
			}
			x_p++;
		}
		y_p++;
	}
	return (0);
}

void	is_it_praticable(t_map_dimension *map)
{
	char	**visited;

	visited = malloc(sizeof(char *) * (map->y + 1));
	if (!visited)
	{
		free_tab(map->map);
		ft_exit(4);
	}
	map_copy(map->map, visited);
	if (!player_can_exit(map, visited))
	{
		free_tab(visited);
		free_tab(map->map);
		ft_exit(5);
	}
}
