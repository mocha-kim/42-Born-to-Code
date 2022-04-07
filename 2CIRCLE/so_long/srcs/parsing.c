/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:22:42 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/07 15:58:19 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/gnl.h"
#include "../includes/utils.h"
# include <fcntl.h>

int	parse_map(char *path)
{
	int fd;
	int flag;
	char *line;

	if (!ft_endcmp(path, ".ber"))
		return (ft_print_error("invalid map filename extension"));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_print_error("map file open failed"));
	while (get_next_line(fd, &line))
	{
		flag = parse_line(line);
		free(line);
	}
	
}

int parse_line(char *line)
{

}