/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:21:08 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/23 15:21:09 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//The bzero() function shall place n zero-valued 
//bytes in the area pointed to by s.
void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*str2;
	size_t			cnt;

	str2 = (unsigned char *)s;
	cnt = 0;
	while (cnt < n)
	{
		str2[cnt] = '\0';
		++cnt;
	}
	return (s);
}

// int main () {
//    char str[50];
//    strcpy(str,"This is string.h library function");
//    puts(str);
//    ft_bzero(str,7);
//    puts(str);
//    return(0);
// }
