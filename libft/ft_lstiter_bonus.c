/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:15:18 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/30 19:15:19 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Itera la lista lst y aplica la funcion f en el contenido de cada nodo.

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	if (lst)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
