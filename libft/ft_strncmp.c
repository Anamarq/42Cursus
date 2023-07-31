/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:48:01 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/22 16:48:02 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Compares up to num characters of the C string str1 
//to those of the C string str2.
//This function starts comparing the first character 
//of each string. If they are equal to each other, 
//it continues with the following pairs until the characters differ, 
//until a terminating null-character is reached, 
//or until num characters match in both strings, whichever happens first.
//Devuelve Mayor que 0 si the first character that does not match 
//has a greater value in str1 than in str2

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0')
			return (0);
		++i;
	}
	return (0);
}
// int	ft_strncmp(char *s1, char *s2, unsigned int n)
// {
// 	unsigned int	i;

// 	i = 1;
// 	while ((*s1 == *s2) && (*s1 != '\0') && (i < n))
// 	{
// 		++s1;
// 		++s2;
// 		++i;
// 	}
// 	return (*s1 - *s2);
// }
// int main () {
//    char str1[15] = "Adios";
//    char str2[15] = "Adioeaa";
//    int ret;

//    ret = ft_strncmp(str1, str2, 5);

//    if(ret < 0) {
//       printf("str1 is less than str2: %d", ret);
//    } else if(ret > 0) {
//       printf("str2 is less than str1: %d", ret);
//    } else {
//       printf("str1 is equal to str2: %d", ret);
//    }

// 	char str12[15] = "Adios";
//    char str22[15] = "Adioeaa";
//    int ret2 = strncmp(str12, str22, 5);

// 	if(ret2 < 0) {
//       printf("R str1 is less than str2: %d", ret2);
//    } else if(ret2 > 0) {
//       printf("R str2 is less than str1: %d", ret2);
//    } else {
//       printf("R str1 is equal to str2: %d", ret2);
//    }

//    return(0);
// }
