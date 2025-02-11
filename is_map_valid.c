/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 00:57:58 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/11 01:51:45 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_pec(t_map_dimension *map)
{
	int		i;
	char	**str;

	map->player = 0;
	map->exit = 0;
	map->colectible = 0;
	str = map->map;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'P')
			map->player++;
		else if (str[i] == 'E')
			map->exit++;
		else if (str[i] == 'C')
			map->colectible++;
		i++;
	}
	if (map->player != 1 || map->exit != 1 || map->colectible == 0)
	{
		if (map->player != 1)
			ft_putstr_fd(ERROR_PLAYER_NUMBER, 2);
		if (map->exit != 1)
			ft_putstr_fd(ERROR_EXIT, 2);
		if (map->colectible == 0)
			ft_putstr_fd("Error\nNo colectible on map.\n", 2);
		ft_exit(1);
	}
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
	i = 1;
	while (map->map[i])
	{
		if (!check_line_length(map->map[i], expected_len))
			return (0);
		i++;
	}
	return (1);
}

void	is_map_valid(t_map_dimension *map)
{
	if (!is_map_rectangle(map))
		ft_exit(1);
}
