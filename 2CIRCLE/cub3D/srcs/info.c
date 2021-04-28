/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 20:44:56 by sunhkim           #+#    #+#             */
/*   Updated: 2021/04/28 20:44:57 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ptr_init(t_info *info)
{
	info->buf = 0;
	info->texture = 0;
	info->z_buf = 0;
	info->img.img_ptr = 0;
	info->img.data = 0;
	info->mlx = 0;
	info->win = 0;
	info->sprite = 0;
}

void	dir_init(t_info *info)
{
	if (info->conf.dir == 'N')
	{
		info->dir_y = -1;
		info->pln_x = 0.66;
	}
	else if (info->conf.dir == 'S')
	{
		info->dir_y = 1;
		info->pln_x = -0.66;
	}
	else if (info->conf.dir == 'W')
	{
		info->dir_x = -1;
		info->pln_y = -0.66;
	}
	else
	{
		info->dir_x = 1;
		info->pln_y = 0.66;
	}
}

int		buf_init(t_info *info)
{
	int i;
	int j;

	info->buf = (int**)malloc(sizeof(int*) * info->conf.win_height);
	if (!(info->buf))
		return (-1);
	i = 0;
	while (i < info->conf.win_height)
	{
		info->buf[i] = (int*)malloc((sizeof(int) * info->conf.win_width));
		if (!(info->buf[i]))
		{
			buf_free(info, i);
			return (-1);
		}
		j = 0;
		while (j < info->conf.win_width)
		{
			info->buf[i][j] = 0;
			j++;
		}
		i++;
	}
	return (0);
}

void	key_init(t_info *info)
{
	info->key.right = 0;
	info->key.left = 0;
	info->key.w = 0;
	info->key.s = 0;
	info->key.a = 0;
	info->key.d = 0;
}

int		info_init(t_info *info)
{
	info->pos_x = info->conf.pos_x + 0.5;
	info->pos_y = info->conf.pos_y + 0.5;
	info->dir_x = 0;
	info->dir_y = 0;
	info->pln_x = 0;
	info->pln_y = 0;
	info->score = 0;
	dir_init(info);
	info->move_speed = 0.05;
	info->rot_speed = 0.05;
	key_init(info);
	if (buf_init(info) == -1 || tex_init(info) == -1)
		return (-1);
	info->z_buf = (double*)malloc(sizeof(double) * info->conf.win_width);
	return (0);
}
