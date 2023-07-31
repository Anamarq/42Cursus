/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:14:45 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/30 19:14:46 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Toma como parametro un nodo lst y libera la
//memoria del contenido utilizando la funcion del
//dada como parametro, ademas de liberar el nodo.La
//memoria de next no debe liberarse.

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}
