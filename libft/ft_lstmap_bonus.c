/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:15:37 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/30 19:15:38 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Itera la lista lst y aplica la funcion f al 
//contenido de cada nodo.Crea una lista resultante
//de la aplicacion correcta y sucesiva de la funcion
//f sobre cada nodo.La funcion del se utiliza
//para eliminar el contenido de un nodo, si hace falta.

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new_ft;
	t_list	*final_lst;

	if (!lst || !f)
		return (0);
	final_lst = 0;
	while (lst != 0)
	{
		new_ft = ft_lstnew(f(lst->content));
		if (!new_ft)
		{
			ft_lstclear(&lst, del);
			return (0);
		}
		ft_lstadd_back(&final_lst, new_ft);
		lst = lst->next;
	}
	return (final_lst);
}
