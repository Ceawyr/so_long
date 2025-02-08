/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:41:16 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/07 23:05:55 by cnamoune         ###   ########.fr       */
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
	if (argc != 2)
		return (0);
	is_this_map(argv[1]);
	scan_map(argv[1]);
}
