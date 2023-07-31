/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:33:10 by anamarqu          #+#    #+#             */
/*   Updated: 2022/10/02 15:33:12 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Anade el nodo new al final de la lista lst.
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	ptr = *lst;
	if (new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			ptr = ft_lstlast(*lst);
			ptr->next = new;
		}
	}
}
