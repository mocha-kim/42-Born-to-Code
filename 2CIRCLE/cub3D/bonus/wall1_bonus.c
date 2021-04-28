/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall1_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:56:51 by sunhkim           #+#    #+#             */
/*   Updated: 2021/04/28 19:56:52 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	calc_vars(int x, t_vector *vec, t_info *info)
{
	double	camera_x;

	camera_x = 2 * x / (double)info->conf.win_width - 1;
	vec->r_dir_x = info->dir_x + info->pln_x * camera_x;
	vec->r_dir_y = info->dir_y + info->pln_y * camera_x;
	vec->map_x = (int)info->pos_x;
	vec->map_y = (int)info->pos_y;
	vec->dlt_dst_x = fabs(1 / vec->r_dir_x);
	vec->dlt_dst_y = fabs(1 / vec->r_dir_y);
}

void	calc_dists(t_vector *vec, t_info *info)
{
	if (vec->r_dir_x < 0)
	{
		vec->step_x = -1;
		vec->side_dst_x = (info->pos_x - vec->map_x) * vec->dlt_dst_x;
	}
	else
	{
		vec->step_x = 1;
		vec->side_dst_x = (vec->map_x + 1.0 - info->pos_x) * vec->dlt_dst_x;
	}
	if (vec->r_dir_y < 0)
	{
		vec->step_y = -1;
		vec->side_dst_y = (info->pos_y - vec->map_y) * vec->dlt_dst_y;
	}
	else
	{
		vec->step_y = 1;
		vec->side_dst_y = (vec->map_y + 1.0 - info->pos_y) * vec->dlt_dst_y;
	}
}

void	ray_cast(t_vector *vec, t_info *info)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (vec->side_dst_x < vec->side_dst_y)
		{
			vec->side_dst_x += vec->dlt_dst_x;
			vec->map_x += vec->step_x;
			vec->side = X_PLANE;
		}
		else
		{
			vec->side_dst_y += vec->dlt_dst_y;
			vec->map_y += vec->step_y;
			vec->side = Y_PLANE;
		}
		if (info->conf.map[vec->map_x][vec->map_y] == '1')
			hit = 1;
	}
}

void	calc_back(t_info *info)
{
	t_vector	vec;
	t_back_line	line;
	int			x;

	x = 0;
	while (x < info->conf.win_width)
	{
		calc_vars(x, &vec, info);
		calc_dists(&vec, info);
		ray_cast(&vec, info);
		calc_line(&line, &vec, info);
		calc_wall(&line, &vec, info);
		coord_wall_tex(x, &line, info);
		calc_floor(&line, &vec);
		coord_floor_tex(x, &line, &vec, info);
		coord_floor_color(x, &line, info);
		info->z_buf[x] = vec.p_wall_dst;
		x++;
	}
}
