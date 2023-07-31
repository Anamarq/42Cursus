/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:57:31 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/30 18:57:34 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//A cada caracter de la string s, aplica la funcion
//f dando como parametros el indice de cada
//caracter dentro de s y la direccion del propio
//caracter, que podra modificarse si es necesario.

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		f(i, s);
		++i;
		++s;
	}
}

//void f(unsigned int i, char* c)
//{
//	int		dif;
//
//	dif = 32;
//	if (c[i] >= 'a' && c[i] <= 'z')
//	{
//		c[i] -= dif;
//	}
//}
//
//int main()
//{
//	char str[] = "holaa";
//	ft_striteri(str, *f);
//	printf("%s\n", str);
//}