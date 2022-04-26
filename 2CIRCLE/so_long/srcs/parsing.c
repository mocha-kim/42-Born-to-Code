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
#include "../includes/utils.h"
#include <fcntl.h>

int read_map(t_info *info, char *path)
{	
	int	fd;
	int	flag;
	char *line;

	fd = open(path, O_RDONLY);
	if (fd < -1)
		return (free_info_print_error(info, "file open failed"));
	flag = read_first_line(info, fd);
	while (flag)
	{
		info->height++;
		flag = get_next_line(fd, &line);
		if (flag != -1)
		{
			if (ft_strlen(line) != info->width)
				return (free_info_print_error(info, "invalid map"));
			info->map = ft_strjoin_free(info->map, line);
		}
	}
	close(fd);
	ft_remove_newline(&(info->map));
	return (1);
}

int	read_first_line(t_info *info, int fd)
{
	int	flag;
	char *line;

	flag = get_next_line(fd, &line);
	if (flag == -1)
		return (free_info_print_error(info, "gnl failed"));
	info->height++;
	info->width = ft_strlen(line);
	info->map = ft_strdup(line);
	free(line);
	return (1);
}

int	check_map(t_info *info)
{
	int	i;
	int	p;
	int	t;
	int	e;
	int	flag;

	printf("check : %d * %d / %d\n", info->height, info->width, ft_strlen(info->map));
	i = 0;
	p = 0;
	t = 0;
	e = 0;
	while (info->map[i])
	{
		flag = check_wall(info, i);
		if (!flag)
			return (0);
		check_elememts(info->map[i], &p, &t, &e);
		i++;
	}
	if (p != 1 || t < 1 || e != 1)
		return (free_info_print_error(info, "invalid map"));
	return (1);
}

int	check_wall(t_info *info, int i)
{
	if (i < info->width)
	{
		if (info->map[i] != '1')
			return (free_info_print_error(info, "invalid map"));
	}
	else if (i % info->width == 0 || i % info->width == info->width - 1)
	{
		if (info->map[i] != '1')
			return (free_info_print_error(info, "invalid map"));
	}
	else if (i > ft_strlen(info->map) - info->width)
	{
		if (info->map[i] != '1')
			return (free_info_print_error(info, "invalid map"));
	}
	return (1);
}

void	check_elememts(char map, int *p, int *t, int *e)
{
	if (map == 'P')
		(*p)++;
	else if (map == 'C')
		(*t)++;
	else if (map == 'E')
		(*e)++;
}