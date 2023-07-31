/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:05:32 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/30 10:05:37 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Envia la string al file descriptor especificado seguido de un salto l�nea.
void	ft_putendl_fd(char *s, int fd)
{
	write (fd, s, ft_strlen(s));
	write (fd, "\n", 1);
}
