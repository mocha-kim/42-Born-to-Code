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
	int fd;
	int i;
	char *line;

	if (!ft_endcmp(path, ".ber"))
		return (ft_print_error("invalid map filename extension"));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_print_error("map file open failed"));
	i = 0;
	while (get_next_line(fd, &line))
	{
		ft_lstadd_back(&(info->map_buffer), ft_lstnew(ft_strdup(line)));
		free(line);
		i++;
	}
	if (ft_strlen(line) > 0)
	{
		ft_lstadd_back(&(info->map_buffer), ft_lstnew(ft_strdup(line)));
		i++;
	}
	free(line);
	info->height = i;
	return (1);
}

int	parse_map(t_info *info)
{
	int i;
	int success_flag;
	t_list *cur;

	success_flag = parse_first_last_line(info, info->map_buffer->content);
	if (!success_flag)
		return (free_info_print_error(info, "invalid map"));
	i = 1;
	cur = info->map_buffer->next;
	while (cur->next)
	{
		success_flag = check_line(info, cur->content);
		if (!success_flag)
			return (free_info_print_error(info, "invalid map"));
		parse_line(info, cur->content, i);
		cur = cur->next;
		i++;
	}
	success_flag = parse_first_last_line(info, cur->next->content);
	if (!success_flag)
		return (free_info_print_error(info, "invalid map"));
	return (1);
}

int parse_first_last_line(t_info *info, char *line)
{
	int	i;

	info->width = ft_strlen(info->map_buffer->content);
	i = 0;
	while (i < info->width)
	{
		if (line[i] != 1)
			return (0);
	}
	return (1);
}

int check_line(t_info *info, char *line)
{
	int i;

	if (line[0] != '1')
		return (0);
	i = 1;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'C'
		|| line[i] == 'E' || line[i] == 'P')
			i++;
		else
			return (0);
	}
	if (line[i - 1] != '1')
		return (0);
	if (info->map_row != i)
		return (0);
	return (1);
}

int	parse_line(t_info *info, char *line, int i)
{
	int j;

	j = 0;
	info->map[i] = malloc(sizeof(int) * (info->map_row + 1));
	if (!info->map[i])
		return (free_info_print_error(info, "malloc failed"));
	while (line[j])
	{
		if (line[j] == '0')
			info->map[i][j] = BACK;
		else if (line[j] == '1')
			info->map[i][j] = WALL;
		else if (line[j] == 'C')
			info->map[i][j] = PLAYER;
		else if (line[j] == 'E')
			info->map[i][j] = TARGET;
		else if (line[j] == 'P')
		{
			info->player.x = j;
			info->player.y = i;
			info->map[i][j] = PLAYER;
		}
		j++;
	}
	return (1);
}