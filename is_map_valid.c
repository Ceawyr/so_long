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

void	check_pec(t_map_dimension)
{
	
}

void	check_last_line(char *line)
{
	
}

int	is_map_rectangle(t_map_dimension *map, char *argv)
{
	char	*line;
	int		y;
	
	map->fd = open(argv, O_RDONLY);
	line  = get_next_line(map->fd);
	map->y = ft_strlen(line) - 1;
	y = map->y;
	free(line);
	while (line)
	{
		if (ft_strlen(line) - 1 != '\n')
		{
			
		}
		if (map->y != y)
			return (0);
		line = get_next_line(map->fd);
		map->y = ft_strlen(line) - 1;
		free(line);
	}
}

void	is_map_valid(t_map_dimension *map, char *argv)
{
	is_map_rectangle(map, argv);
}
