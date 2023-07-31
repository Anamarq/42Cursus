/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:29:24 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/21 16:29:25 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	cont;

	cont = 0;
	while (str[cont] != '\0')
	{
		++ cont;
	}
	return (cont);
}
// int main () {
//    char str[50];
//    int len;
//    strcpy(str, "This is tutorialspoint.com");
//    len = ft_strlen(str);
//    printf("Length of |%s| is |%d|\n", str, len);
//    return(0);
// }