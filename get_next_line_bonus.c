/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srall <srall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:04:09 by srall             #+#    #+#             */
/*   Updated: 2023/02/21 03:12:03 by srall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	int i = 0;
	char		*buff = NULL, *temp = NULL, *line = NULL;
	static char	*staticstr[4096]; // add the multi fd.

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0
        || !(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (NULL);
	while (i < BUFFER_SIZE + 1)
		buff[i++] = 0;
	temp = gettempstr(fd, buff, staticstr[fd]);
	free(buff);
	if (!temp)
		return (NULL);
    line = ft_line(temp);
	staticstr[fd] = ft_staticstr(temp);
	free(temp);
	return (line);
}
