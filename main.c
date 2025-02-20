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
/*
static void	free_int_tab(int **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

static void	free_rest(t_game *map)
{
	free_tab(map->map);
	free_int_tab(map->colectible_ids);
	mlx_terminate(map->mlx);
}
*/
int	main(int argc, char **argv)
{
	t_game	map;

	map = (t_game){NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL, \
	NULL, NULL, NULL, NULL, NULL, NULL, NULL};
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
