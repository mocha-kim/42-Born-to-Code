#include "../includes/cub3d_bonus.h"

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

void	coord_floor_tex(int x, t_back_line *line, t_vector *vec, t_info *info)
{
	int		y;
	int		tex_tmp;
	double	weight;

	if (info->conf.tex_path[T_F] == 0 && info->conf.tex_path[T_C] == 0)
		return ;
	if (line->draw_end < 0)
		line->draw_end = info->conf.win_height;
	y = line->draw_end + 1;
	while (y < info->conf.win_height)
	{
		weight = (info->conf.win_height / (2.0 * y - info->conf.win_height))
				/ vec->prp_wal_dst;
		line->flr_tex_x = (int)((weight * line->flr_x_wall + (1.0 - weight)
							* info->pos_x) * TEX_WIDTH) % TEX_WIDTH;
		line->flr_tex_y = (int)((weight * line->flr_y_wall + (1.0 - weight)
							* info->pos_y) * TEX_HEIGHT) % TEX_HEIGHT;
		tex_tmp = TEX_WIDTH * line->flr_tex_y + line->flr_tex_x;
		if (info->conf.tex_path[T_F] != 0)
			info->buf[y][x] = info->texture[T_F][tex_tmp];
		if (info->conf.tex_path[T_C] != 0)
			info->buf[info->conf.win_height
			- y][x] = info->texture[T_C][tex_tmp];
		y++;
	}
}

void	coord_floor_color(int x, t_back_line *line, t_info *info)
{
	int		y;

	if (info->conf.cf_color[0] == -1 && info->conf.cf_color[1] == -1)
		return ;
	if (line->draw_end < 0)
		line->draw_end = info->conf.win_height;
	y = line->draw_end + 1;
	while (y < info->conf.win_height)
	{
		if (info->conf.cf_color[1] != -1)
			info->buf[y][x] = info->conf.cf_color[1];
		if (info->conf.cf_color[0] != -1)
			info->buf[info->conf.win_height - y
			- 1][x] = info->conf.cf_color[0];
		y++;
	}
}
