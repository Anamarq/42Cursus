/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:32:44 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/20 13:32:58 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//The C library function int 
//memcmp(const void *str1, const void *str2, size_t n)) 
//compares the first n bytes of 
//memory area str1 and memory area str2.

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			cnt;
	unsigned char	*str1_2;
	unsigned char	*str2_2;

	str1_2 = (unsigned char *) str1;
	str2_2 = (unsigned char *) str2;
	cnt = 0;
	while (cnt < n)
	{
		if (*str1_2 != *str2_2)
			return (*str1_2 - *str2_2);
		++cnt;
		++str1_2;
		++str2_2;
	}
	return (0);
}

// int main () {
//    char str1[15];
//    char str2[15];
//    int ret;
//    memcpy(str1, "abcdef", 6);
//    memcpy(str2, "cBCDEF", 6);
//    ret =ft_memcmp("teste", "testex", 6);
//    if(ret > 0) {
//       printf("str2 is less than str1");
//    } else if(ret < 0) {
//       printf("str1 is less than str2");
//    } else {
//       printf("str1 is equal to str2");
//    }
//    return(0);
// }