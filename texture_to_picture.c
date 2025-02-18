/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_to_picture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 02:12:54 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/18 02:38:40 by cnamoune         ###   ########.fr       */
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
}
