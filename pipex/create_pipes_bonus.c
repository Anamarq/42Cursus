/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:53:07 by anamarqu          #+#    #+#             */
/*   Updated: 2023/04/07 17:53:08 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

typedef struct bonus
{
	int		pip[2];
	t_fds	fd;
	char	**argv;
	char	**envp;
	int		argc;
}	t_bonus;

//El proceso padre se encargará de cerrar los descriptores 
//y esperar a los hijos.
void	parentb(int *pip, t_fds fd, pid_t *pids, int npid)
{
	int	status;
	int	i;

	i = 0;
	close(pip[0]);
	close(pip[1]);
	close(fd.fd_in);
	close(fd.fd_out);
	while (i < npid)
	{
		waitpid(pids[npid], &status, 0);
		++i;
	}
}

//Crear una tubería separada (un par de descriptores de archivo) 
//para cada proceso secundario. De esa manera, el primer hijo 
//puede escribir en su propia tubería, el segundo puede leer en 
//la tubería del primero y escribir en la suya propia, y así sucesivamente.
int	next_childs(t_bonus tb, pid_t *pids)
{
	int	i;

	i = 3;
	while (i < tb.argc - 2 && pids[i - 3] > 0)
	{
		pids[i - 2] = fork();
		if (pids[i - 2] == -1)
			return (-1);
		else if (pids[i - 2] == 0)
			return (childn(tb.pip, tb.argv, tb.envp, i));
		++i;
	}
	pids[i - 2] = fork();
	if (pids[i - 2] == -1)
		return (-1);
	else if (pids[i - 2] == 0)
		return (childlast(tb.pip, tb.fd.fd_out, tb.argv[tb.argc - 2], tb.envp));
	else if (pids[i - 2] > 0)
		parentb(tb.pip, tb.fd, pids, i - 2);
	return (0);
}

//Para varios comandos. Crear varios hijos, una pipe por hijo.
//Para el hijo 1 se lee el archivo de entrada.
//Para los siguientes es el inicio y final de la pipe.
//Los pids los guardo en un array. Uno por cada comando
//
//Crear una tubería separada (un par de descriptores de archivo) 
//para cada proceso secundario. De esa manera, el primer hijo 
//puede escribir en su propia tubería, el segundo puede leer en 
//la tubería del primero y escribir en la suya propia, y así sucesivamente.
int	pipesb(t_fds fd, char **argv, char **envp, int argc)
{
	t_bonus	tb;
	pid_t	*pids;

	pids = malloc((argc - 3) * sizeof(*pids));
	if (!pids)
		return (-1);
	tb.fd = fd;
	tb.argv = argv;
	tb.envp = envp;
	tb.argc = argc;
	if (pipe(tb.pip) == -1)
		return (-1);
	pids[0] = fork();
	if (pids[0] == -1)
		return (-1);
	if (pids[0] == 0)
		return (child1(tb.pip, fd.fd_in, argv[2], envp));
	else if (pids[0] > 0)
		return (next_childs(tb, pids));
	return (0);
}
