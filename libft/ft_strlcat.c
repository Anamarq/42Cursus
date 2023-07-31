/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:39:18 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/21 16:39:20 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat( char *dst, const char *src, size_t size )
{
	unsigned int	sdest;
	unsigned int	ssrc;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		++i;
	while (src[j] != '\0')
		++j;
	sdest = i;
	ssrc = j;
	if (size == 0 || sdest >= size)
		return (size + ssrc);
	j = 0;
	while ((src[j] != '\0') && (j < size - sdest - 1))
	{
		dst[i] = src[j];
		++i;
		++j;
	}
	dst[i] = '\0';
	return (sdest + ssrc);
}
// int main () {
//    char src[50] = "This is source";
//    char dest[50] = "This is destination";
//    char src2[50] = "This is source";
//    char dest2[50] = "This is destination";

//    int i = ft_strlcat(dest, src, 25);
//    int j = strlcat(dest2, src2, 25 );
//    printf("Final destination string : %s, size: %i \n", dest, i);
//    printf("Final destination string real : %s, size: %i", dest2, j);

//    return(0);
// }