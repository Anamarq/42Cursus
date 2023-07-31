/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:15:01 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/30 19:15:02 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Elimina y libera el nodo lst dado y todos los
//consecutivos de ese nodo, utilizando la funcion del y free(3).
//Al final, el puntero a la lista debe ser NULL.

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;

	ptr = NULL;
	if (lst)
	{
		while (*lst)
		{
			ptr = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = ptr;
		}
		free(ptr);
	}
}
