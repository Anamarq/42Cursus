/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:49:33 by anamarqu          #+#    #+#             */
/*   Updated: 2023/03/28 12:49:35 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//Leer archivos entrada y salida. Para múltiples comandos.
void	read_files_multiple(int argc, char **argv, t_fds *fd)
{
	fd->fd_out = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0000644);
	if (fd->fd_out < 0)
	{
		perror("Error reading output file");
		exit (1);
	}
	fd->fd_in = open(argv[1], O_RDONLY);
	if (fd->fd_in < 0)
	{
		perror("Error reading output file");
		exit (1);
	}
}

//Leemos los archivos de entrada y salida. En este caso el de entrada
//es el temporal
void	read_files_heredoc2(t_cmds *cmds, char **argv, t_fds *fd)
{
	fd->fd_in = open("hdc_file", O_RDONLY);
	if (fd->fd_in < 0)
	{
		perror("Error reading input file");
		exit(1);
	}
	fd->fd_out = open(argv[5], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd->fd_out < 0)
	{
		perror("Error opening output file");
		exit (1);
	}
	cmds->cmd1 = argv[3];
	cmds->cmd2 = argv[4];
}

//Abrir un archivo temporal.
//Ir leyendo con get next line y y escribirlo en el archivo temporal. 
//Si se encuentra con EOF termina
void	read_files_heredoc(t_cmds *cmds, char **argv, t_fds *fd)
{
	int		fdtmp;
	char	*line;

	fdtmp = open("hdc_file", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fdtmp < 0)
	{
		perror("Error creating temporary file");
		exit(1);
	}
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (ft_strcmp(argv[2], line) == 1)
		{
			free(line);
			break ;
		}
		write(fdtmp, line, ft_strlen(line));
		write(fdtmp, "\n", 1);
		free(line);
	}
	close(fdtmp);
	read_files_heredoc2(cmds, argv, fd);
}

// Open a temporary file with O_CREAT, O_WRONLY, O_TRUNC and 644 permissions.
// Read each line of the standard input in a loop.
// Compare each line with the LIMITER, the second argument we received:
// if the line is identical to the limiter, exit the loop,
// if the line is different, write it to our temporary file.
// Close the temporary file.
// Open the temporary file with the O_RDONLY mode.
// Dup2 the temporary file’s fd to the standard input.
// Start pipex.
int	main(int argc, char **argv, char **envp)
{
	int		pip[2];
	t_fds	fd;
	t_cmds	cmds;

	if (argc < 5)
	{
		perror("Wrong number of arguments");
		return (-1);
	}
	else if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		read_files_heredoc(&cmds, argv, &fd);
		if (pipe(pip) == -1)
			return (-1);
		return (pipes(pip, fd, cmds, envp));
	}
	else
	{
		if (ft_strcmp(argv[1], "/dev/random") == 1)
			return (-1);
		read_files_multiple(argc, argv, &fd);
		return (pipesb(fd, argv, envp, argc));
	}
}
