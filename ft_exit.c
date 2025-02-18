/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:54:14 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/17 21:16:13 by cnamoune         ###   ########.fr       */
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
		ft_putstr_fd(ERROR_MAP, 2);
	else if (code_error == 3)
		ft_putstr_fd(ERROR_PEC, 2);
	else if (code_error == 4)
		ft_putstr_fd(ERROR_MEMORY, 2);
	else if (code_error == 5)
		ft_putstr_fd(ERROR_PATH, 2);
	else if (code_error == 6)
		ft_putstr_fd(ERROR_TRASH, 2);
	else if (code_error == 7)
		ft_putstr_fd(ERROR_MLX, 2);
	exit(EXIT_FAILURE);
}

