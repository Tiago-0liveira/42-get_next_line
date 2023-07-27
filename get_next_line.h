/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 01:12:06 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/07/27 01:20:46 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*get_line_and_clean(char *line);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dst, char *src);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strchr(char *s, int c);
char	*read_next_line(int fd, char *line);

#endif
