/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:43:49 by sunhkim           #+#    #+#             */
/*   Updated: 2021/05/12 17:43:50 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calc_floor(t_back_line *line, t_vector *vec)
{
	if (vec->side == X_PLANE && vec->r_dir_x > 0)
	{
		line->flr_x_wall = vec->map_x;
		line->flr_y_wall = vec->map_y + line->wall_x;
	}
	else if (vec->side == X_PLANE && vec->r_dir_x < 0)
	{
		line->flr_x_wall = vec->map_x + 1.0;
		line->flr_y_wall = vec->map_y + line->wall_x;
	}
	else if (vec->side == Y_PLANE && vec->r_dir_y > 0)
	{
		line->flr_x_wall = vec->map_x + line->wall_x;
		line->flr_y_wall = vec->map_y;
	}
	else
	{
		line->flr_x_wall = vec->map_x + line->wall_x;
		line->flr_y_wall = vec->map_y + 1.0;
	}
}

void	coord_floor_color(int x, t_back_line *line, t_info *info)
{
	int		y;

	if (line->draw_end < 0)
		line->draw_end = info->conf.win_height;
	y = line->draw_end + 1;
	while (y < info->conf.win_height)
	{
		info->buf[y][x] = info->conf.cf_color[1];
		info->buf[info->conf.win_height - y - 1][x] = info->conf.cf_color[0];
		y++;
	}
}
