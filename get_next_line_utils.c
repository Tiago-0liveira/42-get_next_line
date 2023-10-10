/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 01:13:46 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/10/03 15:09:57 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*gnl_ft_strcpy(char *dst, char *src)
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

char	*gnl_ft_strjoin(char *str1, char *str2)
{
	char	*r;

	if (!str1)
	{
		str1 = malloc(sizeof(char) * 1);
		if (!str1)
			return (NULL);
		str1[0] = '\0';
	}
	r = malloc(gnl_ft_strlen(str1) + gnl_ft_strlen(str2) + 1);
	if (!r)
		return (NULL);
	gnl_ft_strcpy(r, str1);
	gnl_ft_strcpy(r + gnl_ft_strlen(str1), str2);
	free(str1);
	return (r);
}

char	*gnl_ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[gnl_ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*gnl_ft_strcpy_unl(char *dest, char *src)
{
	int	i;

	if (!dest || !src)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i++] = '\n';
	dest[i] = '\0';
	return (dest);
}
