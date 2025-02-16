/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:41:53 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/16 23:37:56 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "MLX42.h"

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

typedef struct	s_list
{
	char		**map;
	int			player_x_pos;
	int			player_y_pos;
	int			x;
	int			y;
	int			z;
	int			fd;
	int			player;
	int			colectible;
	int			exit;
	mlx_t		*mlx;
	mlx_image_t	*wall_img;
	mlx_image_t	*player_img;
	mlx_image_t	*exit_img;
	mlx_image_t	*colectible_img;
	mlx_image_t	*floor_img;
}				t_game;

int		ft_strlen(const char *s);
int		ft_strrstr(char *str);

void	free_tab(char **argv);
void	ft_putstr_fd(char *str, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_exit(int code_error);
void	scan_map(char *argv);
void	free_gnl(int fd, char *line);
void	is_map_valid(t_game *map);
void	is_it_praticable(t_game *map);
void	map_copy(char **map, char **visited);

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