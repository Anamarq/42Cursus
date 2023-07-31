/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:57:06 by anamarqu          #+#    #+#             */
/*   Updated: 2023/03/23 16:57:07 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//Fork: Padre reciba el pid ddel hijo. Hijo recibe 0. -1 en caso de error
//Si el padre acaba sin esperar a su hijo, este se convierte en huérfano.
//zombie es un proceso que termina sus tareas pero sigue esperando al padre,
//es decir, no termina su ejecución.
//pid_t wait(int *status);
//pid_t waitpid(pid_t pid, int *status, int options);
//WIFEXITED(status) Devuelve true si el hijo acaba bien
//WEXITSTATUS(status) Devuelve el código del hijo
//int dup(int oldfd);
//int dup2(int oldfd, int newfd);
//El primer parámetro es el path que se saca del envp del main. 
//El segundo son los parámetros (ej ls -l) 
//El tercero es el puntero de entorno, que contiene la info del sistema,
// incluyendo el path. vendrá
//
int	main(int argc, char **argv, char **envp)
{
	int		pip[2];
	t_fds	fd;
	t_cmds	cmds;

	if (argc != 5)
	{
		perror("Wrong number of arguments");
		exit (1);
	}
	cmds.cmd1 = argv[2];
	cmds.cmd2 = argv[3];
	if (ft_strcmp(argv[1], "/dev/random") == 1)
		return (-1);
	fd.fd_in = open(argv[1], O_RDONLY);
	fd.fd_out = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0000644);
	if (fd.fd_out < 0 || fd.fd_in < 0)
	{
		perror("Error reading file");
		exit (1);
	}
	if (pipe(pip) == -1)
		return (-1);
	return (pipes(pip, fd, cmds, envp));
}
//hay que comprobar que las paths sean válidas. 
//Mirar lo que hay en el PATH de envp.
