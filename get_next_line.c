/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srall <srall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:04:09 by srall             #+#    #+#             */
/*   Updated: 2023/02/21 02:47:31 by srall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// 函数原型：文件描述符fd，返回读取数据行。如果读取结束或发生错误，返回 NULL。
// prototype: argument fd is file descriptor, return the data line.
// if EOF or error, then return NULL.
char	*get_next_line(int fd)
{
	int i = 0;
	char		*buff = NULL, *temp = NULL, *line = NULL;
	static char	*staticstr;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0
        || !(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (NULL);
	while (i < BUFFER_SIZE + 1)
		buff[i++] = 0;
	temp = gettempstr(fd, buff, staticstr);
	free(buff);
	if (!temp)
		return (NULL);
    line = ft_line(temp);
	staticstr = ft_staticstr(temp);
	free(temp);
	return (line);
}
