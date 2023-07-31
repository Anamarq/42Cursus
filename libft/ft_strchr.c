/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:59:41 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/23 15:59:44 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The C library function char *strchr(const char *str, int c) searches for 
//the first occurrence of the character c (an unsigned char) 
//in the string pointed to by the argument str.

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != (unsigned char)c)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return ((char *)str);
}

// int main () {
//    const char str[] = "http://www.tutorialspoint.com";
//    const char ch = '.';
//    char *ret;
//    ret = ft_strchr(str, ch);
//    printf("String after |%c| is - |%s|\n", ch, ret);
//    return(0);
// }