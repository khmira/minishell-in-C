/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <abadidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:44:38 by marvin            #+#    #+#             */
/*   Updated: 2022/04/14 22:32:53 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_finish(char **str, char **line)
{
	*line = bg_strdup(*str);
	if (!(*line))
		return (-1);
	free(*str);
	*str = NULL;
	return (0);
}

int	ft_remplissage(char **str, char **line, int len)
{
	char	*tmp;

	*line = bg_substr(*str, 0, len);
	if (!(*line))
		return (-1);
	tmp = bg_strdup((*str) + len + 1);
	if (!tmp)
		return (-1);
	free(*str);
	*str = bg_strdup(tmp);
	if (!(*str))
		return (-1);
	free(tmp);
	return (1);
}

int	ft_read(int fd, char **str)
{
	int		ret;
	char	*buff;
	char	*tmp;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	ret = read(fd, buff, BUFFER_SIZE);
	while (ret > 0)
	{
		buff[ret] = '\0';
		tmp = bg_strjoin((*str), buff);
		if (!tmp)
			return (-1);
		free(*str);
		*str = NULL;
		*str = bg_strdup(tmp);
		if (!(*str))
			return (-1);
		free(tmp);
		if (bg_strchr((*str), '\n'))
			break ;
	}
	free(buff);
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static char		*str;
	int				ret;
	int				len;

	len = 0;
	if (fd < 0 || BUFFER_SIZE < 0 || !line)
		return (-1);
	if (!str)
	{
		str = bg_strdup("");
		if (!str)
			return (-1);
	}
	ret = ft_read(fd, &str);
	if (ret < 0)
		return (-1);
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	if (str[len] == '\n')
	{
		return (ft_remplissage(&str, line, len));
	}
	else if (str[len] == '\0')
		return (ft_finish(&str, line));
	return (0);
}
