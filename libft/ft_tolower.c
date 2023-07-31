/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:30:55 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/19 14:30:56 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	int		dif;

	dif = 32;
	if (c >= 'A' && c <= 'Z')
	{
		c += dif;
	}
	return (c);
}

// int main () {
//    int i = 0;
//    char str[] = "TUTORIALS POINT";

//    while( str[i] ) {
//       putchar(ft_tolower(str[i]));
//       i++;
//    }

//    return(0);
// }