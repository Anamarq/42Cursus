/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:57:19 by anamarqu          #+#    #+#             */
/*   Updated: 2022/10/07 12:57:20 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdlib.h>
# include<unistd.h>
# include<stdarg.h>
# include<limits.h>

int		ft_printf(char const *str, ...);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *string);
int		ft_putnbr_base(unsigned long long nbr, char *base);
int		ft_print_void(unsigned long long n);
int		ft_print_unsigned(long int n);
int		ft_print_number(int n);
int		ft_print_caracter(char c);
int		ft_print_string(char *s);

#endif