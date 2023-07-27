/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 01:12:08 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/07/27 17:58:05 by tiagoliv         ###   ########.fr       */
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
	//printf("buf:%s|\n", buf);
	if (!buf || buf[0] == '\0')
	{
		if (buf != NULL)
		{
			free(buf);
			buf = NULL;
		}
		return (NULL);
	}
	line = get_line_and_clean(buf);
	//printf("lllline:%s|\n", buf);
	if (!line)
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	if (!ft_strchr(buf, '\n') && !ft_strchr(line, '\n'))
	{
		free(buf);
		buf = NULL;
	} 
	else if (buf[0] != '\0')
	{
		tmp = malloc(ft_strlen(buf) + 1);
		if (!tmp)
		{
			free(buf);
			free(line);
			return (NULL);
		}
		ft_strcpy(tmp, buf);
		//printf("tmp:%s|\n", tmp);
		free(buf);
		buf = tmp;
	}
	//printf("buf:%s|\n", buf);
	return (line);
}

char	*get_line_and_clean(char *line)
{
	int		i;
	int		j;
	char	*r;

	if (line == NULL)
		return NULL;
	if (line[0] == '\n')
		j = 0;
	else if (ft_strchr(line, '\n') == NULL)
	{
		r = malloc(ft_strlen(line) + 1);
		ft_strcpy(r, line);
		return r;
	}
	else
		j = (int) (ft_strchr(line, '\n') - line);
	if (j < 0)
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

//#define TEST
#ifdef TEST

#include <stdio.h>
#include <string.h>
int main() {

	int fd = open("in.txt", O_RDONLY);
	char *r;
	
	while ((r = get_next_line(fd))) {
		printf("%s|\n", r);
		free(r);
		r = NULL;
	}
	free(r);
	
}

#endif