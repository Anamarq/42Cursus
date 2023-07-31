/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:04:51 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/23 15:04:52 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//The C library function void *memset(void *str, int c, size_t n) copies 
//the character c (an unsigned char) to the first n characters 
//of the string pointed to, by the argument str.
void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*str2;
	size_t			cnt;

	str2 = (unsigned char *)str;
	cnt = 0;
	while (cnt < n)
	{
		str2[cnt] = (unsigned char)c;
		++cnt;
	}
	return (str);
}

// int main () {
//    char str[50];
//    strcpy(str,"This is string.h library function");
//    puts(str);
//    ft_memset(str,'$',7);
//    puts(str);
//    return(0);
// }