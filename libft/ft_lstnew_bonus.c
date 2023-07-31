/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:12:55 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/30 19:12:58 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Crea un nuevo nodo utilizando malloc(3).La
//variable miembro content se inicializa con el
//contenido del parametro content.La variable next, con NULL.
t_list	*ft_lstnew(void *content)
{
	t_list	*nodo;

	nodo = (t_list *)malloc(1 * sizeof(t_list));
	if (!nodo)
	{
		free(nodo);
		return (0);
	}
	nodo->content = content;
	nodo->next = NULL;
	return (nodo);
}
