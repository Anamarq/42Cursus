/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:33:32 by anamarqu          #+#    #+#             */
/*   Updated: 2022/11/06 15:33:32 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<stdio.h>
# include <fcntl.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *string);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start,
			size_t len);
int		ft_ind(const char *str, char c);
char	*get_next_line(int fd);

#endif
