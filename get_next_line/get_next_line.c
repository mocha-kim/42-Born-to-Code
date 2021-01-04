/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:04:55 by sunhkim           #+#    #+#             */
/*   Updated: 2021/01/04 16:15:13 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		s1_len;
	char	*result;

	s1_len = 0;
	while (s1[s1_len] != 0)
		s1_len++;
	if (!(result = (char *)malloc(sizeof(char) * (s1_len + 1))))
		return (0);
	i = 0;
	while (i < s1_len)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	ft_strdel(char **as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
	}
	return ;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		if (!(substr = malloc(sizeof(char))))
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (!(substr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len && s[i] != 0)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

int		read_line(char **line, int fd, char **backup, int reader)
{
	char	*tmp;
	int		line_len;

	line_len = 0;
	while (backup[fd][line_len] != '\n' && backup[fd][line_len] != '\0')
		line_len++;
	if (backup[fd][line_len] == '\n')
	{
		*line = ft_substr(backup[fd], 0, line_len);
		tmp = ft_strdup(backup[fd] + line_len + 1);
		free(backup[fd]);
		backup[fd] = tmp;
		if (backup[fd][0] == '\0')
			ft_strdel(line);
	}
	else
	{
		*line = ft_strdup(*backup);
		ft_strdel(line);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	char		*buffer[BUFFER_SIZE + 1];
	char		*tmp;
	int			reader;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((reader = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[reader] = '\0';
		if (!backup[fd])
			backup[fd] = ft_strnew(BUFFER_SIZE);
		tmp = ft_strjoin(backup[fd], buffer);
		free(backup[fd]);
		backup[fd] = tmp;
		if (ft_strchr(backup[fd], '\n'))
			break ;
	}
	if (reader < 0)
		return (-1);
	else if (reader == 0 && backup[fd] == NULL)
		return (0);
	else
		return (read_line(line, fd, backup, reader));
}
