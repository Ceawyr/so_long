/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:18:20 by cnamoune          #+#    #+#             */
/*   Updated: 2025/02/10 19:14:33 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	count_word(const char *s, char c)
{
	int		i;
	size_t	count;

	count = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && i == 0)
		{
			count++;
			i = 1;
		}
		else if (*s == c)
			i = 0;
		s++;
	}
	return (count);
}

static int	safe_malloc(char **tab, int i, size_t word)
{
	int	j;

	j = 0;
	tab[i] = malloc(word);
	if (tab[i] == NULL)
	{
		while (j < i)
		{
			free(tab[j]);
			j++;
		}
		free(tab);
		return (1);
	}
	return (0);
}

static int	fill_word(char **tab, const char *s, char c)
{
	size_t		word_len;
	int			i;
	const char	*start;

	i = 0;
	while (*s)
	{
		word_len = 0;
		while (*s == c && *s)
			s++;
		start = s;
		while (*s != c && *s)
		{
			word_len++;
			s++;
		}
		if (word_len > 0)
		{
			if (safe_malloc(tab, i, word_len + 1))
				return (1);
			ft_strlcpy(tab[i], start, word_len + 1);
			i++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char		**tab;
	size_t		word;

	if (s == NULL)
		return (NULL);
	word = 0;
	word = count_word(s, c);
	tab = malloc((word + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab[word] = NULL;
	if (fill_word(tab, s, c))
		return (NULL);
	return (tab);
}
