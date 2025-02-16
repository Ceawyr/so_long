/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:30:57 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/16 23:57:12 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_game *map)
{
	map->mlx = mlx_init(map->x * 100, map->y * 100, "map.ber", true);
	if (map->mlx)
		ft_exit_map(map, 7);
	mlx_texture_t *texture = mlx_load_png("images/wall.png");
	if (!texture)
		ft_exit_map(map, 8);
}