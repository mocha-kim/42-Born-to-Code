/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:22:42 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/08 00:48:22 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/gnl.h"
#include "../includes/utils.h"
#include <fcntl.h>

int read_map(t_info *info, char *path)
{	
	int  fd;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd < -1)
		return (free_info_print_error(info, "file open failed"));
	line = get_next_line(fd);
	info->height = 0;
	info->width = ft_strlen(line) - 1;
	info->map_buffer = ft_strdup_without_newline(line);
	free(line);
	while (line)
	{
		info->hei++;
		line = get_next_line(fd);
		if (line)
		{
			info->map_buffer = ft_strjoin_without_newline(info->map_buffer, line);
		}
	}
	close(fd);
	return (1);
}

int	check_map(t_info *info)
{
	int	i;
	int	p;
	int	t;
	int	e;

	if (game->hei * game->wid != ft_strlen(game->str_line))
		return (free_info_print_error(info, "invalid map"));
	i = 0;
	p = 0;
	t = 0;
	e = 0;
	while (i < ft_strlen(info->map_buffer))
	{
		check_wall(info);
		check_elememts(info->map[i], &p, &t, &e);
		i++;
	}
	return (1);
}

int	check_wall(t_info *info)
{
	if (i < info->width)
	{
		if (info->map[i] != WALL)
			return (free_info_print_error(info, "invalid map"));
	}
	else if (i % info->width == 0 || i % info->width == info->width - 1)
	{
		if (info->map[i] != WALL)
			return (free_info_print_error(info, "invalid map"));
	}
	else if (i > ft_strlen(info->map_buffer) - info->width)
	{
		if (info->map[i] != WALL)
			return (free_info_print_error(info, "invalid map"));
	}
}

void	check_elememts(int map, int *p, int *t, int *e)
{
	if (map == PLAYER)
		(*p)++;
	else if (map == TARGET)
		(*t)++;
	else if (map == EXIT)
		(*e)++;
}