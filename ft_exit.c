/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:54:14 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/08 00:38:28 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(int code_error)
{
	if (code_error == 0)
		ft_putstr_fd("Not a .ber file.\n", 2);
	else if (code_error == 1)
		ft_putstr_fd("Map format is not valid.\n", 2);
	else if (code_error == 2)
		ft_putstr_fd("Map as to start with wall the top/left .ber file.\n", 2);
	exit(EXIT_FAILURE);
}