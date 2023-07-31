/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 09:59:53 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/30 09:59:57 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Envia el caracter al file descriptor especificado.
void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
