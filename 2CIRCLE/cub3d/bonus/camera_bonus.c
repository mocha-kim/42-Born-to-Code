/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:39:26 by sunhkim           #+#    #+#             */
/*   Updated: 2021/05/12 17:39:28 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	move_vertical(t_info *info, int direction)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = info->pos_x + direction * info->dir_x * info->mv_speed;
	tmp_y = info->pos_y + direction * info->dir_y * info->mv_speed;
	if (direction == 1)
	{
		if (!ft_strrchr("14", info->conf.map[tmp_x][(int)info->pos_y]))
			info->pos_x += info->dir_x * info->mv_speed;
		if (!ft_strrchr("14", info->conf.map[(int)info->pos_x][tmp_y]))
			info->pos_y += info->dir_y * info->mv_speed;
	}
	if (direction == -1)
	{
		if (!ft_strrchr("14", info->conf.map[tmp_x][(int)info->pos_y]))
			info->pos_x -= info->dir_x * info->mv_speed;
		if (!ft_strrchr("14", info->conf.map[(int)info->pos_x][tmp_y]))
			info->pos_y -= info->dir_y * info->mv_speed;
	}
}

void	move_horizontal(t_info *info, int direction)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = info->pos_x + direction * info->pln_x * info->mv_speed;
	tmp_y = info->pos_y + direction * info->pln_y * info->mv_speed;
	if (direction == 1)
	{
		if (!ft_strrchr("14", info->conf.map[tmp_x][tmp_y]))
		{
			info->pos_x += info->pln_x * info->mv_speed;
			info->pos_y += info->pln_y * info->mv_speed;
		}
	}
	if (direction == -1)
	{
		if (!ft_strrchr("14", info->conf.map[tmp_x][tmp_y]))
		{
			info->pos_x -= info->pln_x * info->mv_speed;
			info->pos_y -= info->pln_y * info->mv_speed;
		}
	}
}

void	rotate(t_info *info, int direction)
{
	double	old_dir_x;
	double	old_pln_x;
	double	tmp_x;
	double	tmp_y;

	old_dir_x = info->dir_x;
	tmp_x = info->dir_x * cos(direction * info->rot_speed);
	tmp_y = info->dir_y * sin(direction * info->rot_speed);
	info->dir_x = tmp_x - tmp_y;
	tmp_x = old_dir_x * sin(direction * info->rot_speed);
	tmp_y = info->dir_y * cos(direction * info->rot_speed);
	info->dir_y = tmp_x + tmp_y;
	old_pln_x = info->pln_x;
	tmp_x = info->pln_x * cos(direction * info->rot_speed);
	tmp_y = info->pln_y * sin(direction * info->rot_speed);
	info->pln_x = tmp_x - tmp_y;
	tmp_x = old_pln_x * sin(direction * info->rot_speed);
	tmp_y = info->pln_y * cos(direction * info->rot_speed);
	info->pln_y = tmp_x + tmp_y;
}
