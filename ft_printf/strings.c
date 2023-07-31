/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:16:40 by anamarqu          #+#    #+#             */
/*   Updated: 2022/10/12 19:16:41 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_caracter(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_string(char *s)
{
	int	longi;

	longi = 0;
	if (s != NULL)
	{
		longi = ft_strlen(s);
		write(1, s, longi);
	}
	else
	{
		write(1, "(null)", 6);
		longi = 6;
	}
	return (longi);
}
