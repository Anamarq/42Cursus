/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:08:04 by anamarqu          #+#    #+#             */
/*   Updated: 2023/03/28 13:08:05 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<fcntl.h>
# include<string.h>

typedef struct files
{
	int	fd_in;
	int	fd_out;
}	t_fds;

typedef struct cmds
{
	char	*cmd1;
	char	*cmd2;
}	t_cmds;

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *string);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int		child1(int *pip, int fd_in, char *cmd, char **envp);
int		child2(int *pip, int fd_out, char *cmd, char **envp);
char	*get_cmd_path(char *cmd, char **envp);
int		pipes(int *pip, t_fds fd, t_cmds cmd, char **envp);
//bonus
int		childlast(int *pip, int fd_out, char *cmd, char **envp);
int		pipesb(t_fds fd, char **argv, char **envp, int argc);
int		childn(int *pip, char **argv, char **envp, int n);
//hereDoc
int		ft_strcmp(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_ind(const char *str, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
#endif