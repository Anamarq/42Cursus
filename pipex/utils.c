/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:39:19 by anamarqu          #+#    #+#             */
/*   Updated: 2023/03/23 17:39:20 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *str)
{
	int	cont;

	cont = 0;
	while (str[cont] != '\0')
	{
		++cont;
	}
	return (cont);
}

char	*ft_strdup(const char *string)
{
	char	*copy;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(string);
	copy = (char *) malloc((size + 1) * sizeof(char));
	if (!copy)
	{
		free(copy);
		return (NULL);
	}
	if (string != NULL)
	{
		while (string[i] != '\0')
		{
			copy[i] = string[i];
			++i;
		}
		copy[i] = '\0';
		return (copy);
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			i;

	i = 0;
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	sub = (char *) malloc((len + 1) * sizeof(char));
	if (sub)
	{
		while (i < len && s[i + start] != '\0')
		{
			sub[i] = s[i + start];
			++i;
		}
		sub[i] = '\0';
		return (sub);
	}
	free(sub);
	return (NULL);
}

//Strnstr
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && i < len)
	{
		j = 0;
		while ((j + i < len)
			&& (*(haystack + j) == needle[j]) && *(haystack + j) != '\0')
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack);
			++j;
		}
		++haystack;
		++i;
	}
	return (0);
}

//JOIN
char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	unsigned int	i;

	i = 0;
	res = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if ((s1 != NULL) && (s2 != NULL) && (res))
	{
		while (s1[i] != '\0')
		{
			res[i] = s1[i];
			++i;
		}
		while (*s2 != '\0')
		{
			res[i] = *s2;
			++s2;
			++i;
		}
		res[i] = '\0';
		return (res);
	}
	free(res);
	return (NULL);
}
