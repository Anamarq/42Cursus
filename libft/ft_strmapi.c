/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:58:06 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/30 18:58:08 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//A cada caracter de la string s, aplica la
//funcion f dando como parametros el indice de cada
//caracter dentro de s y el propio caracter.Genera
//una nueva string con el resultado del uso sucesivo de f 
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*mapi;

	i = 0;
	mapi = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!mapi)
	{
		free(mapi);
		return (NULL);
	}
	while (s[i] != '\0')
	{
		mapi[i] = f(i, s[i]);
		++i;
	}
	mapi[i] = '\0';
	return (mapi);
}

//char f(unsigned int i, char c)
//{
//	int		dif;
//	char	str;
//
//	dif = 32;
//	if (c >= 'a' && c <= 'z')
//	{
//		str = c - dif;
//	}
//	return (str);
//}
//int main()
//{
//	printf("%s\n", ft_strmapi("holaa", *f));
//}