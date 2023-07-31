/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:59:53 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/22 16:59:57 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//char *strstr(const char *haystack, const char *needle) function 
//finds the first occurrence of the substring needle in the 
//string haystack. The terminating '\0' characters are not compared.

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
// char	*ft_strnstr(const char *b, const char *l, size_t len)
// {
// 	size_t	p1;
// 	size_t	p2;

// 	p1 = 0;
// 	p2 = 0;
// 	if (!*l)
// 		return ((char *)&b[p1]);
// 	while (b[p1] != '\0' && p1 < len)
// 	{
// 		p2 = 0;
// 		while (b[p1 + p2] != '\0' && b[p1 + p2] == l[p2] && p1 + p2 < len)
// 		{
// 			if (l[p2 + 1] == '\0')
// 				return ((char *)&b[p1]);
// 			p2++;
// 		}
// 		p1++;
// 	}
// 	return (0);
// }

// int main () {
//    char haystack[20] = "PruebamEjemploPi";
//    char needle[10] = "mplo";
//    char *ret;

//    ret = ft_strnstr(haystack, needle, 13);

//    printf("The substring is: %s\n", ret);

//    char haystack2[20] = "PruebamEjemploPi";
//    char needle2[10] = "mplo";
//    char *ret2;

//    ret2 = strnstr(haystack2, needle2, 13);

//    printf("The substring is: %s\n", ret2);

// //    char haystack3[20] = "PruebamEjemploPi";
// //    char needle3[10] = "mplo";
// //    char *ret3;

// //    ret3 = ft_sstrnstr(haystack3, needle3, 13);

// //    printf("The substring is: %s\n", ret3);
// //    return(0);
// }