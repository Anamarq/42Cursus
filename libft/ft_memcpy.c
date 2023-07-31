/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:05:00 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/20 10:05:03 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Copies the values of num bytes from the location pointed to by source 
//directly to the memory block pointed to by destination.
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest2;
	const char	*src2;
	size_t		cnt;

	dest2 = (char *)dest;
	src2 = (char *)src;
	cnt = 0;
	if (n == 0 || dest2 == src2)
		return (dest);
	while (cnt < n)
	{
		*dest2 = *src2;
		dest2++;
		src2++;
		++cnt;
	}
	return (dest);
}

// int main () {
//    const char src[50] = "http://www.tutorialspoint.com";
//    char dest[50];
//    strcpy(dest,"Heloooo!!");
//    printf("Before memcpy dest = %s\n", dest);
//    ft_memcpy(dest, src, strlen(src)+1);
//    printf("After memcpy dest = %s\n", dest); 
//    return(0);
// }