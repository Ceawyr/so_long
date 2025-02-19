/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:41:16 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/19 23:14:56 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_this_map(char *argv)
{
	int	i;

	i = ft_strrstr(argv);
	if (i == 0)
		ft_exit(0);
}

int	main(int argc, char **argv)
{
	t_game	map;

	map = (t_game){NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
	if (argc != 2)
		return (0);
	is_this_map(argv[1]);
	map = get_map_size(argv[1]);
	is_map_valid(&map);
	is_it_praticable(&map);
	init_mlx(&map);
	mlx_key_hook(map.mlx, key_handler, &map);
	mlx_loop(map.mlx);
	printf("%d", map.player_id);
	printf("%d", map.floor_img->instances->z);
	return (0);
}
