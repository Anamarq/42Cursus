/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:18:17 by anamarqu          #+#    #+#             */
/*   Updated: 2023/03/28 13:18:18 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//Buscar donde se encuentre PATH con strsntr. 
//Una vez encontrado, guardar el path con substr
// Guardar en paths los distintos paths. Es una tabla de strings
char	**look_4_paths(char **envp)
{
	int		i;
	char	*envp_path;
	char	**paths;

	i = 0;
	while (envp[i])
	{
		envp_path = ft_strnstr(envp[i], "PATH=", 5);
		if (envp_path)
		{
			envp_path = ft_substr(envp_path, 5, ft_strlen(envp_path));
			break ;
		}
		i++;
	}
	paths = ft_split(envp_path, ':');
	free(envp_path);
	return (paths);
}

//Añadir la barra para path válido
void	add_bar(char **paths)
{
	int		i;
	char	*tmp;

	i = 0;
	while (paths[i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		free(tmp);
		i++;
	}
}

// Añadir a cada path nuestro comando para testear si va
// Mietras que haya un path que testear while..
// Añadir comando al final
// Mirar si es accesible y ejecutable
// if access Hemos encontrado el camino correcto. Si no, liberar
char	*test_paths(char **paths, char *cmd)
{
	int		i;
	char	*cmd_path;

	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	perror("Wrong path");
	return (NULL);
}

//Buscar el path válido
char	*get_cmd_path(char *cmd, char **envp)
{
	char	**paths;

	paths = look_4_paths(envp);
	add_bar(paths);
	return (test_paths(paths, cmd));
}
