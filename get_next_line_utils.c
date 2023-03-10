/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srall <srall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:05:42 by srall             #+#    #+#             */
/*   Updated: 2023/02/21 03:14:40 by srall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// 检查缓冲区buff中是否包含'\n'，用于结束读区的循环。
// cCheck if the buffer buff contains '\n', for ending the reading loop.
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

// 连接两个输入参数串；
// joint two strings as argumens
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
	free(temp); // assign NULL after free, invalid. subfunction inner.
	while (buf[j])
		res[len++] = buf[j++];
	res[len] = '\0';
	return (res);
}

// 返回连接后的临时串，将储存在staticstr的静态串或连接之后的临时串temp与buff缓存串连接
// The function concatenates a static string or a temporary string with the buffer string,
//  and returns the concatenated string.
char	*gettempstr(int fd, char *buff, char *staticstr)
{
	char	*temp = NULL;
	int		num_read = BUFFER_SIZE;

	if (!staticstr) // In order to avoid segmentation fault when the first read.
	{
		if (!(temp = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		temp[0] = '\0';
	}
	while (num_read == BUFFER_SIZE && !nl_include(buff)) // num_read == BUFFER_SIZE, EOF for breaking out the loop
	{
		if ((num_read = read(fd, buff, BUFFER_SIZE)) < 0)
			return (NULL);
		buff[num_read] = '\0';
		if (!staticstr)
			temp = ft_joint(temp, buff);
		else
		{
			temp = ft_joint(staticstr, buff);
			// staticstr is not NULL，free in ft_joint, then NULL in here.
			// otherwise every loop joint the staticstr&buff, then double free error ocurred in ft_joint.
			// staticstr不为空，连接后就free，立即在ft_joint的外部赋NULL，否则每次都是staticstr和buff的连接，ft_joint会导致double free出错；
			// 出错原因：赋NULL应在这个函数执行，在ft_joint函数内部赋NULL无效；
			// 注意：其实在ft_joint函数内部的free其实是多余的，因为static char*类型储存在静态储存区无需显式free。
			staticstr = NULL;
		}
		// 公用ft_joint函数，只在第一次循环连接staticstr和buff，free NULL之后的循环都是temp的buff，很巧妙。
		// The shared ft_joint function only concatenates staticstr and buff in the first loop.
		// In the subsequent loops, it concatenates temp and buff.
		if (!temp) // protect, ft_joint malloc failed
			return (NULL);
	}
	return (temp);
}

// 提取临时串中包含第一个'\n'前的字符串作为行串返回，若临时串无数据则返回NULL。
// Extracts the string containing the first '\n' in the temporary string as the line string to be returned.
// Returns NULL if the temporary string is empty.
char	*ft_line(char *temp)
{
	char	*line = NULL;
	int		i = 0;

	if (!temp[i])
		return (NULL);
	while (temp[i])
	{
		if (temp[i++] == '\n') // If it is '\n', make sure to allocate one more;
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

// 提取临时串中第一个'\n'后的字符串作为静态串返回，若临时串无数据则返回NULL。
// Extracts the string after the first occurrence of '\n' in the temporary string and returns it as the static string.
// If the temporary string is empty, it returns NULL.
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
