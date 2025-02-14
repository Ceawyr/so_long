/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 01:01:07 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/14 01:03:35 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup_map(char *s1)
{
	char	*dest;
	size_t	i;

	if (!s1)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		if (s1[i] != '1' && s1[i] != '0' && s1[i] != 'C' && s1[i] != 'E' 
			&& s1[i] != 'P' && s1[i] != '\n')
			{
				free(dest);
				return (NULL);
			}
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}