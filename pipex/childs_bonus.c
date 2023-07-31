/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:19:21 by anamarqu          #+#    #+#             */
/*   Updated: 2023/03/31 20:19:22 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//Este hijo se encarga del último comando.
//Buscar el path válido con get_cmd_path.
//cmd_args es el comando
//execve(cmd_path, cmd_args, envp) ejecuta el comando
int	childlast(int *pip, int fd_out, char *cmd, char **envp)
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

//Este hijo se encarga de los comandos intermedios.
//Buscar el path válido con get_cmd_path.
//cmd_args es el comando
//execve(cmd_path, cmd_args, envp) ejecuta el comando
int	childn(int *pip, char **argv, char **envp, int n)
{
	char	*cmd_path;
	char	**cmd_args;

	dup2(pip[0], 0);
	dup2(pip[1], 1);
	close(pip[0]);
	close(pip[1]);
	cmd_args = ft_split(argv[n], ' ');
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
