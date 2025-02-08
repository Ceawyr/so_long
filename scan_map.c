/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:22:49 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/08 01:13:19 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	is_map_closed(char *map)
{
	static int		column;
	static int		x_len;
	static int		y_len;
	int				caze;

	caze = 0;
	x_len += (int)ft_strlen(map) + 1;
	y_len++;
	while (caze < x_len && column == 0)
	{
		if (map[caze] != 1)
			return (0);
		caze++;
	}
	column = 1;
	if (map[0] != 1)
		return (0);
	else if (map[ft_strlen(map) - 1] != 1)
		return (0);
	return (x_len + y_len);
}

void	scan_map(char *argv)
{
	char			*map;
	int				fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return ;
	while (1)
	{
		map = get_next_line(fd);
		if (!is_map_closed(map));
		{
			free(map);
			ft_exit(2);
		}
		free(map);
	}
}
