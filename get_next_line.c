/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 01:12:08 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/10/02 15:44:51 by tiagoliv         ###   ########.fr       */
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
	if (!line || (!ft_strchr(buf, '\n') && !ft_strchr(line, '\n')))
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
	else if (ft_strchr(line, '\n') == NULL)
	{
		r = malloc(ft_strlen(line) + 1);
		ft_strcpy(r, line);
		return (r);
	}
	else
		i = (int)(ft_strchr(line, '\n') - line);
	r = malloc(i + 2);
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

/* int main()
{
	int fd = open("test.txt", O_RDONLY);

	
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
} */