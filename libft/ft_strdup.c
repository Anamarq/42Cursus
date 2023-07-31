/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:33:25 by anamarqu          #+#    #+#             */
/*   Updated: 2022/09/29 16:33:28 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//The function strdup() is used to duplicate a string. 
//It returns a pointer to null-terminated byte string.

char	*ft_strdup(const char *string)
{
	char	*copy;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(string);
	copy = (char *) malloc((size + 1) * sizeof(char));
	if (!copy)
	{
		free(copy);
		return (NULL);
	}
	if (string != NULL)
	{
		while (string[i] != '\0')
		{
			copy[i] = string[i];
			++i;
		}
		copy[i] = '\0';
		return (copy);
	}
	return (NULL);
}

// int main() {
//    char *str = "Helloworld";
//    char *result;
//    result = ft_strdup(str);
//    printf("The string : %s", result);
//    return 0;
// }
