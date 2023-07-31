/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:15:31 by anamarqu          #+#    #+#             */
/*   Updated: 2022/10/12 19:15:33 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_number(int n)
{
	char	*nc;
	int		longi;

	nc = ft_itoa(n);
	longi = ft_print_string(nc);
	free(nc);
	return (longi);
}

int	ft_unsigned_recursive(long int n, int *longi)
{
	char	towrite;

	if (n < 0)
		n += 4294967296;
	if (n > 9)
	{
		ft_unsigned_recursive(n / 10, longi);
	}
	++*longi;
	towrite = n % 10 + '0';
	write(1, &towrite, 1);
	return (*longi);
}

int	ft_print_unsigned(long int n)
{
	int	longi;

	longi = 0;
	ft_unsigned_recursive(n, &longi);
	return (longi);
}
