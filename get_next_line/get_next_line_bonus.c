/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:34:19 by anamarqu          #+#    #+#             */
/*   Updated: 2022/11/09 11:34:21 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE	100
#endif
//FUNcion que devuelve:
//Si todo va bien: la línea leída
//En caso de fallo o si la lectura termina: NULL

//2 casos: si es la primera vez que se lee (buffer vacío)
//o si no lo es. en el buffer se almacena lo que lee

//variable estática es una variable que ha sido ubicada estáticamente
//y cuyo tiempo de vida se extiende durante toda la ejecución del programa.

static char	*ft_conect(char *buffer, char *tab)
{
	char	*buff_aux;

	buff_aux = ft_strjoin(buffer, tab);
	free (buffer);
	return (buff_aux);
}

static char	*ft_readline(char *buffer, int fd)
{
	char	*buff_aux;
	int		br;

	buff_aux = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	br = 1;
	while (ft_ind(buffer, '\n') == -1 && br > 0)
	{
		br = read(fd, buff_aux, BUFFER_SIZE);
		if (br == -1)
		{
			free(buffer);
			free(buff_aux);
			return (NULL);
		}
		buff_aux[br] = '\0';
		buffer = ft_conect(buffer, buff_aux);
	}
	if (ft_strlen(buffer) == 0)
	{
		free (buff_aux);
		free (buffer);
		return (NULL);
	}
	free(buff_aux);
	return (buffer);
}

static char	*ft_next_buffer(char *buffer)
{
	char	*buff;

	buff = ft_substr(buffer, ft_ind(buffer, '\n') + 1,
			ft_strlen(&buffer[ft_ind(buffer, '\n') + 1]) + 1);
	free (buffer);
	return (buff);
}

char	*ft_free_buffer(char **buffer, int fd)
{
	free (buffer[fd]);
	buffer[fd] = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*buff_aux;

	if (read(fd, 0, 0))
		return (ft_free_buffer(buffer, fd));
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	buffer[fd] = ft_readline(buffer[fd], fd);
	if (!buffer[fd] || fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free_buffer(buffer, fd));
	if (buffer[fd] != NULL && ft_ind(buffer[fd], '\n') != -1)
	{
		buff_aux = ft_substr(buffer[fd], 0, ft_ind(buffer[fd], '\n') + 1);
		buffer[fd] = ft_next_buffer(buffer[fd]);
		return (buff_aux);
	}
	buff_aux = buffer[fd];
	buffer[fd] = NULL;
	return (buff_aux);
}
