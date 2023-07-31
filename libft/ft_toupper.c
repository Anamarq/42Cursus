/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:22:15 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/19 14:22:18 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	int		dif;

	dif = 32;
	if (c >= 'a' && c <= 'z')
	{
		c -= dif;
	}
	return (c);
}
// int main () {
//    int i = 0;
//    char str[] = "tuturials pointy";

//    while( str[i] ) {
//       putchar(ft_toupper(str[i]));
//       i++;
//    }

//    return(0);
// }
