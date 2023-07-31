/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:34:54 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/29 16:34:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Reserva (con malloc(3)) y devuelve una substring de
//la string ’s’. La substring empieza desde el índice ’start’ y
//tiene una longitud máxima ’len’.

char	*ft_substr(char const *s, unsigned int start,
size_t len)
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

// int main() {
//    char *str = "Helloworld";
//    char *result;
//    result = ft_substr(str, 7, 9);
//    printf("The string : %s", result);
//    return 0;
// }