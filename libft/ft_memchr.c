/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:23:41 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/20 12:23:43 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//The C library function void *memchr(const void *str, int c, size_t n) 
//searches for the first occurrence of the character c (an unsigned char) 
//in the first n bytes of the string pointed to, by the argument str.
void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*str2;

	str2 = (unsigned char *)str;
	while (n > 0)
	{
		if (*str2 == (unsigned char)c)
			return (str2);
		str2++;
		n--;
	}
	return (NULL);
}

// int main () {
//    const char str[] = "http://www.tutorialspoint.com";
//    const char ch = '.';
//    char *ret;

//    ret = ft_memchr(str, ch, strlen(str));

//    printf("String after |%c| is - |%s|\n", ch, ret);

//    return(0);
// }