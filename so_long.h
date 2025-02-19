/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:41:53 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/19 22:47:13 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "MLX42/include/MLX42/MLX42.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# define ERROR_MAP "Map as to be rectangle and 5x3 minimum\n"
# define ERROR_MEMORY "Memory allocation failed.\n"
# define ERROR_PEC "One player, One exit and at least one collectible\n"
# define ERROR_PATH "Player can't reach the exit or get all collectible\n"
# define ERROR_TRASH "Map contain trash\n"
# define ERROR_MLX "Issues with MLX Librairy\n"

typedef struct	s_game
{
	char			**map;
	int				player_x_pos;
	int				player_y_pos;
	int				x;
	int				y;
	int				z;
	int				fd;
	int				player;
	int				colectible;
	int				exit;
	int				player_id;
	mlx_t			*mlx;
	mlx_image_t		*tree_img;
	mlx_image_t		*player_img;
	mlx_image_t		*player_up;
	mlx_image_t		*player_left;
	mlx_image_t		*player_right;
	mlx_image_t		*exit_img;
	mlx_image_t		*colectible_img;
	mlx_image_t		*floor_img;
}				t_game;

typedef struct	s_assets
{
	mlx_texture_t	*tree_texture;
	mlx_texture_t	*floor_texture;
	mlx_texture_t	*exit_texture;
	mlx_texture_t	*colect_textur;
	mlx_texture_t	*player_texture;
	mlx_texture_t	*p_back_texture;
	mlx_texture_t	*p_right_texture;
	mlx_texture_t	*p_left_texture;
}				t_assets;

int		ft_strlen(const char *s);
int		ft_strrstr(char *str);

void	texture_to_picture(t_game *map, t_assets *assets);
void	image_to_window(t_game *map);
void	init_mlx(t_game *map);
void	free_tab(char **argv);
void	ft_putstr_fd(char *str, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_exit(int code_error);
void	scan_map(char *argv);
void	free_gnl(int fd, char *line);
void	is_map_valid(t_game *map);
void	is_it_praticable(t_game *map);
void	map_copy(char **map, char **visited);
void	ft_exit_map(t_game *map, t_assets *assets, int code_error);
void	key_handler(mlx_key_data_t keydata, void *param);
void	free_images(t_game *map, t_assets *assets);

t_assets	*create_assets(void);

t_game	get_map_size(char *argv);

char	*ft_strdup_map(char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*extract_line(char *buffer);
char	*update_buffer(char *buffer);
char	*read_and_store(char *buffer, int fd);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
