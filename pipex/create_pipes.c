/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:51:21 by anamarqu          #+#    #+#             */
/*   Updated: 2023/03/31 17:51:23 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//El proceso padre se encargará de cerrar los descriptores 
//y esperar a los hijos.
void	parent(int *pip, t_fds fd, pid_t pid1, pid_t pid2)
{
	int	status;

	close(pip[0]);
	close(pip[1]);
	close(fd.fd_in);
	close(fd.fd_out);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
}

//Utiliza fork para clonar el proceso. Crea 2 hijos.
int	pipes(int *pip, t_fds fd, t_cmds cmd, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 == -1)
	{
		perror("Error al crear pid");
		exit(1);
	}
	if (pid1 == 0)
		return (child1(pip, fd.fd_in, cmd.cmd1, envp));
	else if (pid1 > 0)
	{
		pid2 = fork();
		if (pid2 == -1)
		{
			perror("Error al crear pid");
			exit(1);
		}
		else if (pid2 == 0)
			return (child2(pip, fd.fd_out, cmd.cmd2, envp));
		else if (pid2 > 0)
			parent(pip, fd, pid1, pid2);
	}
	return (0);
}
