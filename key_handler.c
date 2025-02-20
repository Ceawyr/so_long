/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:37:25 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/20 02:37:47 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Redessine le floor sur la cellule d'où le joueur vient (position de départ)
static void	redraw_depart_cell(t_game *game)
{
	int	id;

	id = mlx_image_to_window(game->mlx, game->floor_img, game->player_x_pos * 100, game->player_y_pos * 100);
	if (id == -1)
		free_images(game, NULL);
	else
		mlx_set_instance_depth(&game->floor_img->instances[id], 0);
}

static void	redraw_cell(t_game *game, int x, int y)
{
	int	id;

	id = mlx_image_to_window(game->mlx, game->floor_img, x * 100, y * 100);
	if (id == -1)
		free_images(game, NULL);
	else
		mlx_set_instance_depth(&game->floor_img->instances[id], 0);
}

static void	update_player_position(t_game *game, int move_x, int move_y)
{
	int	old_x;
	int	old_y;
	int	coll_id;

	redraw_depart_cell(game);
	old_x = game->player_x_pos;
	old_y = game->player_y_pos;
	if (game->map[move_y][move_x] == 'C')
	{
		coll_id = game->colectible_ids[move_y][move_x];
		if (coll_id != -1)
		{
			game->colectible_img->instances[coll_id].enabled = false;
			game->colectible_ids[move_y][move_x] = -1;
		}
		game->map[move_y][move_x] = '0';
		game->colectible--;
		redraw_cell(game, move_x, move_y);
	}
	redraw_cell(game, move_x, move_y);
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
