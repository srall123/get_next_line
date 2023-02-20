/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srall <srall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:05:42 by srall             #+#    #+#             */
/*   Updated: 2023/02/20 01:50:56 by srall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		nl_include(const char *s)
{
	if (!s)
		return 0;
	while(*s)
	{
		if (*s++ == '\n')
			return 1;
	}
	return 0;
}

char	*ft_joint(char *temp, char *buf)
{
	char	*res = NULL;
	int		i = 0, j = 0, len = 0;

	while (temp[i])
		i++;
	while (buf[j])
		j++;
	res = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!res)
		return (NULL);
	while (len < i + j + 1)
		res[len++] = 0;
	i = 0, j = 0, len = 0;
	while (temp[i])
		res[len++] = temp[i++];
	free(temp); // cannot assign NULL after free, subfunction inner.
	while (buf[j])
		res[len++] = buf[j++];
	res[len] = '\0';
	return (res);
}

char	*ft_line(char *temp)
{
	char	*line = NULL;
	int		i = 0;

	if (!temp[i])
		return (NULL);
	while (temp[i])
	{
		if (temp[i++] == '\n')
			break ;
	}
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (temp[i] && temp[i] != '\n')
	{
		line[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_staticstr(char *temp)
{
	char	*staticstr = NULL;
	int		i = 0, j = 0;

	if (!temp[i])
		return NULL;
	while (temp[i])
		i++;
	while (temp[j] && temp[j] != '\n')
		j++;
	staticstr = (char *)malloc(sizeof(char) * (i - j + 1));
	if (!staticstr)
		return (NULL);
	if (temp[j] == '\n')
		j++;
	i = 0;
	while (temp[j])
		staticstr[i++] = temp[j++];
	staticstr[i] = '\0';
	return (staticstr);
}
