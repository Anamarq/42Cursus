/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:14:06 by anamarqu          #+#    #+#             */
/*   Updated: 2022/10/12 19:14:07 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_base_recursive(unsigned long long nbr, char *base, int *longi)
{
	char	towrite;
	int		res;

	++*longi;
	if (nbr >= 16)
	{
		res = nbr % 16;
		write_base_recursive (nbr / 16, base, longi);
	}
	else
	{
		res = nbr;
	}
	towrite = (base)[res];
	write (1, &towrite, 1);
}

int	ft_putnbr_base(unsigned long long nbr, char *base)
{
	int	longi;

	longi = 0;
	if (nbr < 0)
		nbr += 4294967295;
	write_base_recursive (nbr, base, &longi);
	return (longi);
}

int	ft_print_void(unsigned long long n)
{
	int	longi;

	longi = 2;
	write(1, "0x", 2);
	longi += ft_putnbr_base(n, "0123456789abcdef");
	return (longi);
}
