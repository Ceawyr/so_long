/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_to_picture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 02:12:54 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/18 22:45:57 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_game *map, t_assets *assets)
{
	if (map->tree_img)
		mlx_delete_image(map->mlx, map->tree_img);
	if (map->floor_img)
		mlx_delete_image(map->mlx, map->floor_img);
	if (map->exit_img)
		mlx_delete_image(map->mlx, map->exit_img);
	if (map->colectible_img)
		mlx_delete_image(map->mlx, map->colectible_img);
	if (map->player_img)
		mlx_delete_image(map->mlx, map->player_img);
	if (map->player_right)
		mlx_delete_image(map->mlx, map->player_right);
	if (map->player_left)
		mlx_delete_image(map->mlx, map->player_left);
	if (map->player_up)
		mlx_delete_image(map->mlx, map->player_up);
	ft_exit_map(map, assets, 2);
}

void	image_to_window(t_game *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == '0')
				mlx_image_to_window(map->mlx, map->floor_img, x * 100, y * 100);
			if (map->map[y][x] == '1')
				mlx_image_to_window(map->mlx, map->tree_img, x * 100, y * 100);
			if (map->map[y][x] == 'P')
				mlx_image_to_window(map->mlx, map->player_img, x * 100,\
				 y * 100);
			if (map->map[y][x] == 'C')
				mlx_image_to_window(map->mlx, map->colectible_img,\
				 x * 100, y * 100);
			if (map->map[y][x] == 'E')
				mlx_image_to_window(map->mlx, map->exit_img, x * 100, y * 100);
			x++;
		}
		y++;
	}
	mlx_loop(map->mlx);
}

void	erase_texture(t_game *map, t_assets *assets)
{
	mlx_delete_texture(assets->tree_texture);
	mlx_delete_texture(assets->floor_texture);
	mlx_delete_texture(assets->exit_texture);
	mlx_delete_texture(assets->colectible_texture);
	mlx_delete_texture(assets->player_texture);
	mlx_delete_texture(assets->p_right_texture);
	mlx_delete_texture(assets->p_left_texture);
	mlx_delete_texture(assets->p_back_texture);
	image_to_window(map);
}

void	texture_to_picture(t_game *map, t_assets *assets)
{
	map->tree_img = mlx_texture_to_image(map->mlx, assets->tree_texture);
	if (!map->tree_img)
		free_images(map, assets);
	map->floor_img = mlx_texture_to_image(map->mlx, assets->floor_texture);
	if (!map->floor_img)
		free_images(map, assets);
	map->exit_img = mlx_texture_to_image(map->mlx, assets->exit_texture);
	if (!map->exit_img)
		free_images(map, assets);
	map->colectible_img = mlx_texture_to_image(map->mlx, assets->colectible_texture);
	if (!map->colectible_img)
		free_images(map, assets);
	map->player_img = mlx_texture_to_image(map->mlx, assets->player_texture);
	if (!map->player_img)
		free_images(map, assets);
	map->player_right = mlx_texture_to_image(map->mlx, assets->p_right_texture);
	if (!map->player_right)
		free_images(map, assets);
	map->player_left = mlx_texture_to_image(map->mlx, assets->p_left_texture);
	if (!map->player_left)
		free_images(map, assets);
	map->player_up = mlx_texture_to_image(map->mlx, assets->p_back_texture);
	if (!map->player_up)
		free_images(map, assets);
	erase_texture(map, assets);
}
