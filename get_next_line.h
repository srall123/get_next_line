/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srall <srall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:03:59 by srall             #+#    #+#             */
/*   Updated: 2023/02/20 18:17:04 by srall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

// get_next_line_utils.c
int		nl_include(const char *s);
char	*ft_joint(char *temp, char *buf);
char	*ft_line(char *temp);
char	*ft_staticstr(char *temp);
char	*gettempstr(int fd, char *buff, char *staticstr);
// get_next_line.c
char	*get_next_line(int fd);

#endif
