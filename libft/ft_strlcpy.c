/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:06:15 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/25 18:06:16 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//The strlcpy() function returns the total length 
//of the string that would have been copied if 
//there was unlimited space. This might or might not 
//be equal to the length of the string actually copied, 
//depending on whether there was enough space.
//1) copio de la fuente al destino hasta llegar al max o copiarlo todo
//2) Añadir \0 si he llegado al final
//3) Aumentar contador hasta que llegue alfinal de la src (origen)

//unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	p;

	p = 0;
	if (size > 0)
	{
		while ((src[p]) && (p < size - 1))
		{
			dst[p] = src[p];
			p++;
		}
		dst[p] = '\0';
	}
	return (ft_strlen(src));
}

/*int main()
{
	char str1[10];
	//char str2[] = "HOLA MUNDO";

	printf("MIA %zu %s\n", ft_strlcpy(str1, str2, 0), str1);
	//printf("OFICIAL %zu %s\n", strlcpy(str3, str4, 11), str3);
	return 0;
}*/
// int main(void)
// {
// 	char src[40] = "Esto es una prueba";
// 	char dest[19];
// 	int length;
// 	int cont = 0;
// 	length = ft_strlcpy(dest, src, 90);
// 	printf("%d ", length);
// 	while (dest[cont])
// 	{
// 		printf("%c", dest[cont]);
// 		cont++;
// 	}
// }
