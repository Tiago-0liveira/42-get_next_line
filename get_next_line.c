/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 01:12:08 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/10/02 16:59:54 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line_and_clean(char *line);

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = read_next_line(fd, buf);
	if (!buf || buf[0] == '\0')
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	line = get_line_and_clean(buf);
	if (!line || (!gnl_ft_strchr(buf, '\n') && !gnl_ft_strchr(line, '\n')))
	{
		free(buf);
		buf = NULL;
		if (!line)
			return (NULL);
	}
	return (line);
}

static char	*get_line_and_clean(char *line)
{
	int		i;
	char	*r;

	if (line[0] == '\n')
		i = 0;
	else if (gnl_ft_strchr(line, '\n') == NULL)
	{
		r = malloc(gnl_ft_strlen(line) + 1);
		gnl_ft_strcpy(r, line);
		return (r);
	}
	else
		i = (int)(gnl_ft_strchr(line, '\n') - line);
	r = malloc(i + 2);
	if (!r)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i])
	{
		r[i] = line[i];
		i++;
	}
	gnl_ft_strcpy(r + i, "\n");
	gnl_ft_strcpy(line, line + i + 1);
	return (r);
}

char	*read_next_line(int fd, char *line)
{
	int		rv;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	rv = 1;
	while (!gnl_ft_strchr(line, '\n') && rv != 0)
	{
		rv = read(fd, buf, BUFFER_SIZE);
		if (rv == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rv] = '\0';
		line = gnl_ft_strjoin(line, buf);
	}
	free(buf);
	return (line);
}
