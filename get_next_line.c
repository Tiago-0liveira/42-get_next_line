/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 01:12:08 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/07/27 01:48:08 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = read_next_line(fd, buf);
	if (!buf)
		return (NULL);
	line = get_line_and_clean(buf);
	if (!line)
	{
		free(buf);
		return (NULL);
	}
	if (buf[0] != '\0')
	{
		tmp = malloc(ft_strlen(buf) + 1);
		if (!tmp)
		{
			free(buf);
			return (NULL);
		}
		ft_strcpy(tmp, buf);
		free(buf);
		buf = tmp;
	}
	return (line);
}

char	*get_line_and_clean(char *line)
{
	int		i;
	int		j;
	char	*r;

	j = ft_strchr(line, '\n') - line;
	if (j <= 0)
		return (NULL);
	r = malloc(j + 2);
	if (!r)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i])
	{
		r[i] = line[i];
		i++;
	}
	ft_strcpy(r + i, "\n");
	ft_strcpy(line, line + i + 1);
	return (r);
}
/* we're using only part of the memory that we allocated to the line variable,
we must treat that afterwards */
#include <stdio.h>

int main() {

	int fd = open("in.txt", O_RDONLY);

	char *r;
	while ((r = get_next_line(fd))) {
		printf("%s|\n", r);
		free(r);
	}
}