/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:00:10 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/23 16:00:12 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The C library function char *strrchr(const char *str, int c) searches for
//the last occurrence of the character c (an unsigned char)
//in the string pointed to by the argument str.

#include "libft.h"

static int	ft_search_pos(char *str, char c)
{
	int	n;
	int	pos;

	n = 0;
	pos = -1;
	while (str[n] != '\0')
	{
		if (str[n] == c)
		{
			pos = n;
		}
		n++;
	}
	if (c == '\0')
		pos = n;
	return (pos);
}

char	*ft_strrchr(const char *str, int c)
{
	int		n;
	int		pos;

	pos = ft_search_pos((char *)str, c);
	n = 0;
	if (pos >= 0)
	{
		while (n < pos)
		{
			++str;
			++n;
		}
		return ((char *)str);
	}
	return (NULL);
}
