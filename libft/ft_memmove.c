/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:40:50 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/25 18:40:52 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*src2;

	i = 0;
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	if (dst2 == NULL && src2 == NULL)
		return (0);
	while (i < len)
	{
		if (dst < src)
			dst2[i] = src2[i];
		else
			dst2[len - i - 1] = src2[len - i - 1];
		i++;
	}
	return (dst2);
}

// int main () {
//    char dest[] = "oldstring";
//    const char src[]  = "123456";
//    printf("MEMMOVE %s", memmove(dest, src, 4));
//    printf("\nFT_MEMMOVE %s", ft_memmove(dest, src, 4));
//    return(0);
// }
