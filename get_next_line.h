/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srall <srall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:03:59 by srall             #+#    #+#             */
/*   Updated: 2023/02/19 04:55:24 by srall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> // for debug

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

int		nl_include(const char *s);
char	*ft_joint(char *temp, char *buf);
char	*ft_line(char *temp);
char	*ft_staticstr(char *temp);

char	*get_next_line(int fd);

#endif
