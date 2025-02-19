/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 01:01:07 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/19 23:00:58 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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