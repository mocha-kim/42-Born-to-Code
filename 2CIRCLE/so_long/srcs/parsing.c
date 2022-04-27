/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:22:42 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/27 00:50:06 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/gnl.h"
#include <fcntl.h>

int	read_map(t_info *info, char *path)
{	
	int		fd;
	int		flag;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (free_info_print_error(info, "file open failed"));
	flag = read_first_line(info, fd, &line);
	if (!flag)
		return (0);
	while (line)
	{
		info->height++;
		line = get_next_line(fd);
		if (line)
		{
			if (ft_strlen_without_nl(line) != info->width)
				return (free_info_print_error(info, "invalid map(not rect)"));
			info->map = ft_strjoin_free(info->map, line);
		}
	}
	close(fd);
	ft_remove_newline(&(info->map));
	return (1);
}

int	read_first_line(t_info *info, int fd, char **line)
{
	*line = get_next_line(fd);
	if (*line == NULL)
		return (free_info_print_error(info, "gnl failed"));
	info->width = ft_strlen(*line) - 1;
	info->map = ft_strdup(*line);
	free(*line);
	return (1);
}

int	check_map(t_info *info)
{
	int	i;
	int	p;
	int	e;
	int	flag;

	i = 0;
	p = 0;
	e = 0;
	while (info->map[i])
	{
		flag = check_wall(info, i);
		if (!flag)
			return (0);
		flag = check_elememts(info, i, &p, &e);
		if (!flag)
			return (0);
		i++;
	}
	if (p != 1 || info->target_num < 1 || e != 1)
		return (free_info_print_error(info, "invalid map(invalid elements)"));
	return (1);
}

int	check_wall(t_info *info, int i)
{
	if (i < info->width)
	{
		if (info->map[i] != '1')
			return (free_info_print_error(info, "invalid map(not surrounded)"));
	}
	else if (i % info->width == 0 || i % info->width == info->width - 1)
	{
		if (info->map[i] != '1')
			return (free_info_print_error(info, "invalid map(not surrounded)"));
	}
	else if (i > ft_strlen(info->map) - info->width)
	{
		if (info->map[i] != '1')
			return (free_info_print_error(info, "invalid map(not surrounded)"));
	}
	return (1);
}

int	check_elememts(t_info *info, int i, int *p, int *e)
{
	if (info->map[i] == 'P')
	{
		info->pos.x = i % info->width;
		info->pos.y = i / info->width;
		(*p)++;
	}
	else if (info->map[i] == 'C')
		info->target_num++;
	else if (info->map[i] == 'E')
	{
		info->exit_pos = i;
		(*e)++;
	}
	else if (info->map[i] != '0' && info->map[i] != '1')
		return (free_info_print_error(info, "invalid map(invalid elements)"));
	return (1);
}
