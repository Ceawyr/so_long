/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:37:25 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/20 00:12:24 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_player_position(t_game *game, int move_x, int move_y)
{
	int	check_id;

	check_id = 0;
	if (game->map[move_y][move_x] == 'C')
	{
		game->map[move_y][move_x] = '0';
		game->colectible--;
		check_id = mlx_image_to_window(game->mlx, game->floor_img, move_x * 100, \
		move_y * 100);
		if (check_id == -1)
			free_images(game, NULL);
	}
	game->map[game->player_y_pos][game->player_x_pos] = '0';
	game->player_x_pos = move_x;
	game->player_y_pos = move_y;
	game->map[move_y][move_x] = 'P';
	game->player_img->instances[game->player_id].x = move_x * 100;
	game->player_img->instances[game->player_id].y = move_y * 100;
}

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_game *game;
	int	move_x;
	int	move_y;

	game = (t_game *)param;
	move_x = game->player_x_pos;
	move_y = game->player_y_pos;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_y--;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_y++;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_x--;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_x++;
	if (game->map[move_y][move_x] == '1')
		return ;
	if (game->map[move_y][move_x] == 'E' && game->colectible > 0)
		return ;
	update_player_position(game, move_x, move_y);
}
