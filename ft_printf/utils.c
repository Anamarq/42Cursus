/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:18:52 by anamarqu          #+#    #+#             */
/*   Updated: 2022/10/07 12:18:53 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

///STRLEN
size_t	ft_strlen(const char *str)
{
	int	cont;

	cont = 0;
	while (str[cont] != '\0')
	{
		++ cont;
	}
	return (cont);
}
//STRDUP

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
