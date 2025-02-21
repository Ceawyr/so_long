/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:41:16 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/20 02:27:39 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	is_this_map(char *argv)
{
	int	i;

	i = ft_strrstr(argv);
	if (i == 0)
		ft_exit(0);
}

void	free_int_tab(int **tab, int rows)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (i < rows)
	{
		if (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
		}
		i++;
	}
	free(tab);
	tab = NULL;
}
void	clear_image(t_game *map)
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
}
void	free_rest(t_game *map)
{
	free_tab(map->map);
	free_int_tab(map->colectible_ids, map->y);
	mlx_terminate(map->mlx);
	write(1, "Congratz ! You saved the forest from the Robots.\n", 49);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_game	map;

	map = (t_game){NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
	if (argc != 2)
		return (0);
	is_this_map(argv[1]);
	map = get_map_size(argv[1]);
	is_map_valid(&map);
	is_it_praticable(&map);
	init_mlx(&map);
	mlx_key_hook(map.mlx, key_handler, &map);
	mlx_loop(map.mlx);
	return (0);
}
