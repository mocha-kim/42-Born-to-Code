/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:40:42 by sunhkim           #+#    #+#             */
/*   Updated: 2021/05/12 17:40:44 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	calc_line(t_back_line *line, t_vector *vec, t_info *info)
{
	if (vec->side == X_PLANE)
	{
		vec->prp_wal_dst = (vec->map_x - info->pos_x + (1 - vec->step_x) / 2);
		vec->prp_wal_dst /= vec->r_dir_x;
	}
	else
	{
		vec->prp_wal_dst = (vec->map_y - info->pos_y + (1 - vec->step_y) / 2);
		vec->prp_wal_dst /= vec->r_dir_y;
	}
	line->l_height = (int)(info->conf.win_height / vec->prp_wal_dst);
	line->draw_strt = -(line->l_height) / 2 + info->conf.win_height / 2;
	if (line->draw_strt < 0)
		line->draw_strt = 0;
	line->draw_end = line->l_height / 2 + info->conf.win_height / 2;
	if (line->draw_end >= info->conf.win_height)
		line->draw_end = info->conf.win_height - 1;
}

void	calc_wall(t_back_line *line, t_vector *vec, t_info *info)
{
	if (vec->side == X_PLANE && vec->step_x == 1)
		line->tex_num = T_EA;
	else if (vec->side == X_PLANE && vec->step_x == -1)
		line->tex_num = T_WE;
	else if (vec->side == Y_PLANE && vec->step_y == 1)
		line->tex_num = T_SO;
	else
		line->tex_num = T_NO;
	if (vec->side == 0)
		line->wall_x = info->pos_y + vec->prp_wal_dst * vec->r_dir_y;
	else
		line->wall_x = info->pos_x + vec->prp_wal_dst * vec->r_dir_x;
	line->wall_x -= floor(line->wall_x);
	line->tex_x = (int)(line->wall_x * (double)TEX_WIDTH);
	if (vec->side == 0 && vec->r_dir_x > 0)
		line->tex_x = TEX_WIDTH - line->tex_x - 1;
	if (vec->side == 1 && vec->r_dir_y < 0)
		line->tex_x = TEX_WIDTH - line->tex_x - 1;
}

void	coord_wall_tex(int x, t_back_line *line, t_info *info)
{
	double	step;
	double	tex_pos;
	int		tex_tmp;
	int		y;

	step = 1.0 * TEX_HEIGHT / line->l_height;
	tex_pos = (line->draw_strt - info->conf.win_height
				/ 2 + line->l_height / 2) * step;
	y = line->draw_strt;
	while (y < line->draw_end)
	{
		line->tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
		tex_pos += step;
		tex_tmp = TEX_WIDTH * line->tex_y + line->tex_x;
		line->color = info->texture[line->tex_num][tex_tmp];
		info->buf[y][x] = line->color;
		y++;
	}
}
