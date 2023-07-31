/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:35:37 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/29 16:35:39 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Reserva (con malloc(3)) y devuelve una nueva
//string, formada por la concatenación de ’s1’ y ’s2’.

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

// int main() {
//    char *str = "Helloworld";
//    char *str2 = "Es Jueves";
//    char *result;
//    result = ft_strjoin(str, str2);
//    printf("The string : %s", result);
//    return 0;
// }
