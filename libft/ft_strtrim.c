/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:35:01 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/29 18:35:03 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Elimina todos los caracteres de la string ’set’ 
//desde el principio y desde el final de ’s1’, 
//hasta encontrar un caracter no perteneciente a ’set’. 
//La string resultante se devuelve con una reserva de malloc(3)

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*sub;
	size_t		i;
	size_t		longi;

	i = 0;
	longi = ft_strlen(s1);
	if (!set)
		return ((char *)s1);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		++i;
	while (longi > 0 && ft_strchr(set, s1[longi]))
		--longi;
	sub = ft_substr(s1, i, (longi - i + 1));
	return (sub);
}

// int main() {
//    char *str = "Helloworld";
//    char *str2 = "llowo";
//    char *result;
//    result = ft_strtrim(str, str2);
//    printf("The string : %s", result);
//    return 0;
// }
