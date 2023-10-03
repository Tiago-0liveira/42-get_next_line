/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 01:12:06 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/10/03 15:12:46 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char		*get_next_line(int fd);
char		*read_next_line(int fd, char *line);
int			gnl_ft_strlen(char *str);
char		*gnl_ft_strcpy(char *dst, char *src);
char		*gnl_ft_strjoin(char *str1, char *str2);
char		*gnl_ft_strchr(char *s, int c);

#endif
