/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 01:01:07 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/20 00:37:00 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	if (assets)
		ft_exit_map(map, assets, 2);
	else
		ft_exit_map(map, NULL, 2);
}

void	erase_texture(t_game *map, t_assets *assets)
{
	mlx_delete_texture(assets->tree_texture);
	mlx_delete_texture(assets->floor_texture);
	mlx_delete_texture(assets->exit_texture);
	mlx_delete_texture(assets->colect_textur);
	mlx_delete_texture(assets->player_texture);
	mlx_delete_texture(assets->p_right_texture);
	mlx_delete_texture(assets->p_left_texture);
	mlx_delete_texture(assets->p_back_texture);
	free(assets);
	image_to_window(map);
}

void	map_copy(char **map, char **visited)
{
	int	i;

	i = 0;
	while (map[i])
	{
		visited[i] = ft_strdup(map[i]);
		if (!visited[i])
		{
			free_tab(visited);
			free_tab(map);
			ft_exit(6);
		}
		i++;
	}
	visited[i] = NULL;
}

t_assets	*create_assets(void)
{
	t_assets	*assets = malloc(sizeof(t_assets));
	if (!assets)
		return (NULL);
	assets->tree_texture = NULL;
	assets->floor_texture = NULL;
	assets->exit_texture = NULL;
	assets->colect_textur = NULL;
	assets->player_texture = NULL;
	assets->p_back_texture = NULL;
	assets->p_right_texture = NULL;
	assets->p_left_texture = NULL;
	return (assets);
}

void	ft_exit_map(t_game *map, t_assets *assets, int code_error)
{
	free_tab(map->map);
	if (code_error == 2 && assets)
	{
		if (assets->tree_texture)
			mlx_delete_texture(assets->tree_texture);
		if (assets->floor_texture)
			mlx_delete_texture(assets->floor_texture);
		if (assets->exit_texture)
			mlx_delete_texture(assets->exit_texture);
		if (assets->colect_textur)
			mlx_delete_texture(assets->colect_textur);
		if (assets->player_texture)
			mlx_delete_texture(assets->player_texture);
		if (assets->p_back_texture)
			mlx_delete_texture(assets->p_back_texture);
		if (assets->p_right_texture)
			mlx_delete_texture(assets->p_right_texture);
		if (assets->p_left_texture)
			mlx_delete_texture(assets->p_left_texture);
	}
	if (assets)
		free(assets);
	mlx_terminate(map->mlx);
	ft_exit(7);
}