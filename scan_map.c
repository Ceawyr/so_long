/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:22:49 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/10 00:56:39 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_it_corrupt(char *map, int count)
{
	int	len;

	if (!map)
		return (1);
	if (ft_strlen(map) == 0)
		return (0);
	len = ft_strlen(map);
	if (map[len - 1] == '\n')
	{
		if (map[0] != '1' || map[len - 2] != '1')
			return (0);
	}
	else
	{
		if (map[0] != '1' || map[len -1] != '1')
			return (0);
	}
	return (1);
}

void	scan_map(char *argv)
{
	char	*map;
	int		fd;
	int		count;

	count = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return ;
	while (1)
	{
		map = get_next_line(fd);
		if (!map)
			break ;
		count++;
		if (!is_it_corrupt(map, count))
		{
			free(map);
			while ((map = get_next_line(fd)) != NULL)
				free(map);
			close(fd);
			ft_exit(1);
		}
		free(map);
	}
	close(fd);
}

int	is_map_closed(char *argv)
{
	
}

void	get_map_size(char *argv)
{
	char	**map;

	
}