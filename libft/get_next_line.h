/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <abadidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:44:56 by marvin            #+#    #+#             */
/*   Updated: 2022/04/14 22:32:53 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# define BUFFER_SIZE 1000000

char	*bg_strchr(const char *str, int c);
size_t	bg_strlen(const char *str);
char	*bg_strdup(const char *s1);
char	*bg_strjoin(char const *s1, char const *s2);
char	*bg_substr(char const *s, unsigned int start, size_t len);
int		get_next_line(int fd, char **line);

#endif