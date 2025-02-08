/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:41:53 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/08 00:55:14 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct	s_list
{
	int	x_len;
	int	y_len;
}				t_map_dimension;

int		ft_strlen(const char *s);
int		ft_strrstr(char *str);

void	ft_putstr_fd(char *str, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_exit(int code_error);
void	scan_map(char *argv);

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*extract_line(char *buffer);
char	*update_buffer(char *buffer);
char	*read_and_store(char *buffer, int fd);
char	*get_next_line(int fd);