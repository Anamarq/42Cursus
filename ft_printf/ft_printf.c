/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:21:24 by anamarqu          #+#    #+#             */
/*   Updated: 2022/10/07 12:21:26 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_arg(va_list parametros, char c, int *longi)
{
	if (c == 'i' || c == 'd')
		*longi += ft_print_number(va_arg(parametros, int));
	else if (c == 'c')
		*longi += ft_print_caracter(va_arg(parametros, int));
	else if (c == 's')
		*longi += ft_print_string(va_arg(parametros, char *));
	else if (c == 'u')
		*longi = *longi + ft_print_unsigned(va_arg
				(parametros, unsigned int));
	else if (c == 'X')
		*longi += ft_putnbr_base(va_arg
				(parametros, unsigned int), "0123456789ABCDEF");
	else if (c == 'x')
		*longi += ft_putnbr_base(va_arg
				(parametros, unsigned int), "0123456789abcdef");
	else if (c == 'p')
		*longi += ft_print_void(va_arg(parametros, unsigned long long));
	else if (c == '%')
	{
		write(1, "%%", 1);
		++*longi;
	}
}

int	ft_printf(char const *str, ...)
{
	int		p;
	va_list	parametros;
	int		longi;

	p = 0;
	longi = 0;
	va_start(parametros, str);
	while (str[p] != '\0')
	{
		while (str[p] != '%' && (str[p] != '\0'))
		{
			write(1, &str[p], 1);
			++longi;
			p++;
		}
		if (str[p] == '%')
		{
			p++;
			ft_print_arg(parametros, str[p], &longi);
			p++;
		}
	}
	va_end(parametros);
	return (longi);
}
