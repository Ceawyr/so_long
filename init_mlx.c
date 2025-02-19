/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:30:57 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/20 00:31:02 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures_base(t_game *map, t_assets *assets)
{
	assets->tree_texture = mlx_load_png("images/tree.png");
	if (!assets->tree_texture)
		ft_exit_map(map, assets, 2);
	assets->floor_texture = mlx_load_png("images/floor.png");
	if (!assets->floor_texture)
		ft_exit_map(map, assets, 2);
	assets->exit_texture = mlx_load_png("images/exit.png");
	if (!assets->exit_texture)
		ft_exit_map(map, assets, 2);
	assets->colect_textur = mlx_load_png("images/colectible.png");
	if (!assets->colect_textur)
		ft_exit_map(map, assets, 2);
}

void	load_textures_player(t_game *map, t_assets *assets)
{
	assets->player_texture = mlx_load_png("images/p.png");
	if (!assets->player_texture)
		ft_exit_map(map, assets, 2);
	assets->p_back_texture = mlx_load_png("images/p_back.png");
	if (!assets->p_back_texture)
		ft_exit_map(map, assets, 2);
	assets->p_left_texture = mlx_load_png("images/p_left.png");
	if (!assets->p_left_texture)
		ft_exit_map(map, assets, 2);
	assets->p_right_texture = mlx_load_png("images/p_right.png");
	if (!assets->p_right_texture)
		ft_exit_map(map, assets, 2);
}

void	init_mlx(t_game *map)
{
	t_assets	*assets;

	assets = create_assets();
	if (!assets)
	{
		free_tab(map->map);
		ft_exit(4);
	}
	map->mlx = mlx_init(map->x * 100, map->y * 100, "map.ber", true);
	if (!map->mlx)
		ft_exit_map(map, assets, 1);
	load_textures_base(map, assets);
	load_textures_player(map, assets);
	texture_to_picture(map, assets);
}
