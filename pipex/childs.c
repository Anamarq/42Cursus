/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:50:05 by anamarqu          #+#    #+#             */
/*   Updated: 2023/03/31 17:50:06 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//Este hijo se encarga del primer comando.
//Buscar el path válido con get_cmd_path.
//cmd_args es el comando
//execve(cmd_path, cmd_args, envp) ejecuta el comando
int	child1(int *pip, int fd_in, char *cmd, char **envp)
{
	char	*cmd_path;
	char	**cmd_args;

	dup2(fd_in, 0);
	dup2(pip[1], 1);
	close(pip[0]);
	close(pip[1]);
	cmd_args = ft_split(cmd, ' ');
	cmd_path = get_cmd_path(cmd_args[0], envp);
	if (!cmd_path)
	{
		perror("Error al buscar cmd");
		exit(1);
	}
	execve(cmd_path, cmd_args, envp);
	free(cmd_path);
	free(cmd_args);
	return (0);
}

//Este hijo se encarga del segundo comando.
//Buscar el path válido con get_cmd_path.
//cmd_args es el comando
//execve(cmd_path, cmd_args, envp) ejecuta el comando
int	child2(int *pip, int fd_out, char *cmd, char **envp)
{
	char	*cmd_path;
	char	**cmd_args;

	dup2(pip[0], 0);
	dup2(fd_out, 1);
	close(pip[0]);
	close(pip[1]);
	cmd_args = ft_split(cmd, ' ');
	cmd_path = get_cmd_path(cmd_args[0], envp);
	if (!cmd_path)
	{
		perror("Error al buscar cmd");
		exit(1);
	}
	execve(cmd_path, cmd_args, envp);
	free(cmd_path);
	free(cmd_args);
	return (0);
}
