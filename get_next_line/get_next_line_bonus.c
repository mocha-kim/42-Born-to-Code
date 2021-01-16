/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:04:55 by sunhkim           #+#    #+#             */
/*   Updated: 2021/01/14 17:23:56 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char *str)
{
	int		i;
	int		len;
	char	*result;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*get_save(char *save)
{
	int		i;
	int		tmplen;
	int		savelen;
	char	*result;

	tmplen = 0;
	while (save[tmplen] && save[tmplen] != '\n')
		tmplen++;
	if (save[tmplen] == '\0')
	{
		free(save);
		return (0);
	}
	savelen = ft_strlen(save);
	if (!(result = (char *)malloc(sizeof(char) * (savelen + 1))))
		return (0);
	i = 0;
	while (save[tmplen + 1])
	{
		result[i++] = save[tmplen + 1];
		tmplen++;
	}
	result[i] = '\0';
	free(save);
	return (result);
}

int		free_return(char *buff)
{
	free(buff);
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	int			i;
	char		*buff;
	static char	*save[256];

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	i = 1;
	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (i != 0 && !has_newline(save[fd]))
	{
		if ((i = read(fd, buff, BUFFER_SIZE)) < 0)
			return (free_return(buff));
		buff[i] = '\0';
		if (!(save[fd] = join_save_buff(save[fd], buff)))
			return (free_return(buff));
	}
	free(buff);
	*line = get_line(save[fd]);
	save[fd] = get_save(save[fd]);
	if (save[fd] == NULL)
		return (0);
	return (1);
}
