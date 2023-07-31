/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:35:29 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/25 19:35:30 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Count numero de elementos
//size tamaño elementos

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		*array;
	size_t	cnt;

	array = (int *)malloc(size * count);
	if (!array)
	{
		free(array);
		return (NULL);
	}
	cnt = 0;
	if (array)
		ft_bzero(array, size * count);
	return (array);
}

// void print_int_array(int *array)
// {
// 	int	i;
// 	int	max;
// 	char c;

// 	i = 0;
// 	max = ft_strlen(array);
// 	while(i < max)
// 	{
// 		c = array[i] + '0';
// 		write(1, &c, 1);
// 		++i;
// 	}
// }

// int main()
// {
// 	print_int_array(ft_calloc(10, 20));
// }