/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_to_picture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 02:12:54 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/20 01:55:04 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_colectible_ids(t_game *map)
{
	int i;
	int j;

	map->colectible_ids = malloc(sizeof(int *) * map->y);
	if (!map->colectible_ids)
		return ;
	i = 0;
	while (i < map->y)
	{
		map->colectible_ids[i] = malloc(sizeof(int) * map->x);
		if (!map->colectible_ids[i])
			return ;
		j = 0;
		while (j < map->x)
		{
			map->colectible_ids[i][j] = -1;
			j++;
		}
		i++;
	}
}

static void	put_base_images(t_game *map, int x, int y)
{
	char	picture;
	int		id;

	id = 0;
	picture = map->map[y][x];
	if (picture == '0')
	{
		id = mlx_image_to_window(map->mlx, map->floor_img, x * 100, y * 100);
		mlx_set_instance_depth(&map->floor_img->instances[id], 0);
	}
	else if (picture == '1')
		id = mlx_image_to_window(map->mlx, map->tree_img, x * 100, y * 100);
	else if (picture == 'E')
		id = mlx_image_to_window(map->mlx, map->exit_img, x * 100, y * 100);
	else
		return ;
	if (id == -1)
		free_images(map, NULL);
}

static void	put_entities(t_game *map, int x, int y)
{
	char	picture;
	int		id;

	id = 0;
	picture = map->map[y][x];
	if (picture == 'C')
	{
		id = mlx_image_to_window(map->mlx, map->colectible_img, x * 100, \
		y * 100);
		mlx_set_instance_depth(&map->colectible_img->instances[id], 1);
		map->colectible_ids[y][x] = id;
	}
	else if (picture == 'P')
	{
		id = mlx_image_to_window(map->mlx, map->player_img, x * 100, y * 100);
		map->player_id = id;
		mlx_set_instance_depth(&map->player_img->instances[map->player_id], 10);
	}
	else
		return ;
	if (id == -1)
		free_images(map, NULL);
}

void	image_to_window(t_game *map)
{
	int	x;
	int	y;

	init_colectible_ids(map);
	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			put_base_images(map, x, y);
			put_entities(map, x, y);
			x++;
		}
		y++;
	}
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
	map->colectible_img = mlx_texture_to_image(map->mlx, assets->colect_textur);
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
