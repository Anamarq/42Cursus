/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:01:43 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/30 10:01:47 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Envia la string s al file descriptor especificado.
void	ft_putstr_fd(char *s, int fd)
{
	write (fd, s, ft_strlen(s));
}
