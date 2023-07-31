/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:12:26 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/30 19:12:27 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_data
{
	char	**table;
	int		w;
	int		p;
	int		start;
}	t_data;

static size_t	ft_count_words(char const *s, char c)
{
	size_t	p;
	size_t	w;

	w = 0;
	p = 0;
	while (s[p] && s[p] == c)
		p++;
	while (s[p])
	{
		if (s[p] == c && s[p + 1] != c && s[p + 1] != '\0')
			w++;
		p++;
	}
	return (w + 1);
}

char	**ft_split(char const *s, char c)
{
	t_data	d;

	d.w = 0;
	d.p = 0;
	d.start = 0;
	if (s == NULL)
		return (NULL);
	d.table = (char **) malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (d.table == NULL)
	{
		free(d.table);
		return (NULL);
	}
	while (s[d.p] && d.w < (int)ft_count_words(s, c))
	{
		while (s[d.p] && s[d.p] == c)
			d.p++;
		d.start = d.p;
		while (s[d.p] && s[d.p] != c)
			d.p++;
		if (d.start != d.p)
			d.table[d.w++] = ft_substr(s, d.start, d.p - d.start);
	}
	d.table[d.w] = NULL;
	return (d.table);
}
