/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:22:49 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/12 21:47:30 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_it_corrupt(char *map)
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

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return ;
	while (1)
	{
		map = get_next_line(fd);
		if (!map)
			break ;
		if (!is_it_corrupt(map))
		{
			free(map);
			while (map)
			{
				map = get_next_line(fd);
				free(map);
			}
			close(fd);
			ft_exit(1);
		}
		free(map);
	}
	close(fd);
}

int	is_map_closed(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
		j++;
	if (j == 0)
		return (0);
	j--;
	while (map[j][i] != '\n' && map[j][i] != '\0')
	{
		if (map[j][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[0][i] != '\n' && map[0][i] != '\0')
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	get_map_dimention(char *argv, int *y)
{
	char	*line;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return ;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return ;
		(*y)++;
		free(line);
	}
	close(fd);
}

t_map_dimension	get_map_size(char *argv)
{
	t_map_dimension	map;
	int				i;

	i = 0;
	scan_map(argv);
	map = (t_map_dimension){NULL, 0, 0, 0, 0, 0, 0, 0};
	get_map_dimention(argv, &map.y);
	map.map = malloc(sizeof(char *) * (map.y + 1));
	if (!map.map)
		ft_exit(0);
	map.fd = open(argv, O_RDONLY);
	while (i < map.y)
	{
		map.map[i] = get_next_line(map.fd);
		i++;
	}
	map.map[i] = NULL;
	close(map.fd);
	if (!is_map_closed(map.map))
	{
		free_tab(map.map);
		ft_exit(1);
	}
	return (map);
}
