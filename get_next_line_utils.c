/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 01:13:46 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/09/28 19:35:57 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*r;

	if (!str1)
	{
		str1 = malloc(sizeof(char) * 1);
		str1[0] = '\0';
	}
	r = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!r)
		return (NULL);
	ft_strcpy(r, str1);
	ft_strcpy(r + ft_strlen(str1), str2);
	free(str1);
	return (r);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*read_next_line(int fd, char *line)
{
	int		rv;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	rv = 1;
	while (!ft_strchr(line, '\n') && rv != 0)
	{
		rv = read(fd, buf, BUFFER_SIZE);
		if (rv == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rv] = '\0';
		line = ft_strjoin(line, buf);
	}
	free(buf);
	return (line);
}
