/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:06:31 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/10 19:02:50 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	y;

	y = 0;
	i = ft_strlen(src);
	if (size == 0)
		return (i);
	while (y < size - 1 && src[y] != '\0')
	{
		dst[y] = src[y];
		y++;
	}
	dst[y] = '\0';
	return (i);
}
