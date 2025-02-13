/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 00:57:58 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/12 23:42:46 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_pec(t_map_dimension *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
				map->player++;
			if (map->map[i][j] == 'C')
				map->colectible++;
			if (map->map[i][j] == 'E')
				map->exit++;
			j++;
		}
		i++;
	}
	if (map->colectible > 1 && map->player == 1 && map->exit == 1)
		return (1);
	return (0);
}

static int	check_last_line(char *line, int expected_len)
{
	if (ft_strlen(line) == expected_len)
		return (1);
	return (0);
}

static int	check_line_length(char *line, int expected_len)
{
	if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
		return ((int)ft_strlen(line) - 1 == expected_len);
	else
		return (check_last_line(line, expected_len));
}

static int	is_map_rectangle(t_map_dimension *map)
{
	int		expected_len;
	int		i;

	if (!map->map || !map->map[0])
		return (0);
	expected_len = ft_strlen(map->map[0]);
	if (expected_len > 0 && map->map[0][expected_len - 1] == '\n')
		expected_len--;
	if (expected_len < 5)
		return (0);
	i = 1;
	while (map->map[i])
	{
		if (!check_line_length(map->map[i], expected_len))
			return (0);
		i++;
	}
	if (i < 3)
		return (0);
	return (map->x = expected_len);
}

void	is_map_valid(t_map_dimension *map)
{
	if (!is_map_rectangle(map))
	{
		free_gnl(map->fd, NULL);
		free_tab(map->map);
		ft_exit(2);
	}
	if (!check_pec(map))
	{
		free_gnl(map->fd, NULL);
		free_tab(map->map);
		ft_exit(3);
	}
}
