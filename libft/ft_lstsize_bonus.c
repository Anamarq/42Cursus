/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:13:51 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/30 19:13:54 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Cuenta el numero de nodos de una lista.

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (lst)
	{
		count++;
		while (lst->next)
		{
			lst = lst->next;
			count++;
		}
	}
	return (count);
}
