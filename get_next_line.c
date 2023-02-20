/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srall <srall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:04:09 by srall             #+#    #+#             */
/*   Updated: 2023/02/20 01:53:58 by srall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gettempstr(int fd, char *buff, char *staticstr)
{
	char	*temp = NULL;
	int		num_read = BUFFER_SIZE;

	if (!staticstr)
	{
		if (!(temp = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		temp[0] = '\0';
	}
	while (num_read == BUFFER_SIZE && !nl_include(buff)) // num_read == BUFFER_SIZE为了避免EOF之后还在一直循环
	{
		if ((num_read = read(fd, buff, BUFFER_SIZE)) < 0)
			return (NULL);
		buff[num_read] = '\0';
		if (!staticstr)
			temp = ft_joint(temp, buff);
		else
			temp = ft_joint(staticstr, buff);
		staticstr = NULL; // double free without this line, WHY is invalid if i assign NULL in ft_joint????
		/*当调用ft_joint(staticstr, buff);的时候，注意ft_joint内部的free其实是多余的，因为这个一个static char*类型，储存在静态储存区无需进行显式free。
		 *但是，因为在这个我们想公用一个ft_joint，在下次循环的时候进入到temp的joint里面，所以free它之后赋NULL，很巧妙。
		 *同时，在ft_joint修改了temp=NULL，其实是无效的，子函数无法修改值。
		 *所以才需要在这里添加NULL。*/
		if (!temp) // protect, ft_joint malloc failed
			return (NULL);
	}
	return (temp);
}

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
/*
char	*get_next_line(int fd)
{
	char	*buf = NULL, *temp = NULL, *line = NULL;
	int		ret = BUFFER_SIZE;
	static char *staticstr; // can't initialize for the later calling

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0
        || !(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (NULL);
	if (!staticstr)
	{
		if (!(temp = (char *)malloc(sizeof(char) * 1)))
        {
            free(buf);
			return (NULL);
        }
		temp[0] = '\0';
	}
	while (ret == BUFFER_SIZE && !nl_include(buf))
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) < 0)
			return (NULL);
		buf[ret] = '\0';
		if (!staticstr)
			temp = joint(temp, buf);
		else
			temp = joint(staticstr, buf);
		if (!temp)
			return (NULL);
	}
	free(buf);
	line = ft_line(temp);
	staticstr = ft_staticstr(temp);
	return (line);
}
 */
