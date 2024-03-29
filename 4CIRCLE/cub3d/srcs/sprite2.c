/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:44:09 by sunhkim           #+#    #+#             */
/*   Updated: 2021/05/12 17:44:11 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calc_sprite_pos(t_sprt_line *sprt, int *order, t_info *info, int i)
{
	double	inv_det;

	sprt->x = info->sprite[order[i]].x - info->pos_x;
	sprt->y = info->sprite[order[i]].y - info->pos_y;
	inv_det = 1.0 / (info->pln_x * info->dir_y - info->dir_x * info->pln_y);
	sprt->trns_x = inv_det * (info->dir_y * sprt->x - info->dir_x * sprt->y);
	sprt->trns_y = inv_det * (-info->pln_y * sprt->x + info->pln_x * sprt->y);
	sprt->scrn_x = (int)((info->conf.win_width / 2)
				* (1 + sprt->trns_x / sprt->trns_y));
}

void	calc_sprite_line(t_sprt_line *sprt, t_info *info)
{
	sprt->v_mv_screen = (int)(V_MOVE / sprt->trns_y);
	sprt->height = (int)fabs((info->conf.win_height / sprt->trns_y) / V_DIV);
	sprt->draw_strt_y = -sprt->height / 2 + info->conf.win_height
						/ 2 + sprt->v_mv_screen;
	if (sprt->draw_strt_y < 0)
		sprt->draw_strt_y = 0;
	sprt->draw_end_y = sprt->height / 2 + info->conf.win_height
						/ 2 + sprt->v_mv_screen;
	if (sprt->draw_end_y >= info->conf.win_height)
		sprt->draw_end_y = info->conf.win_height - 1;
	sprt->width = (int)fabs((info->conf.win_height / sprt->trns_y) / U_DIV);
	sprt->draw_strt_x = -sprt->width / 2 + sprt->scrn_x;
	if (sprt->draw_strt_x < 0)
		sprt->draw_strt_x = 0;
	sprt->draw_end_x = sprt->width / 2 + sprt->scrn_x;
	if (sprt->draw_end_x >= info->conf.win_width)
		sprt->draw_end_x = info->conf.win_width - 1;
}

void	coord_sprite_tex(t_info *info, int *order, t_sprt_line *sprt, int i)
{
	int	stripe;
	int	y;
	int	d;

	stripe = sprt->draw_strt_x - 1;
	while (++stripe < sprt->draw_end_x)
	{
		sprt->tex_x = (int)((256 * (stripe - (-sprt->width / 2 + sprt->scrn_x))
					* TEX_WIDTH / sprt->width) / 256);
		if (sprt->trns_y > 0 && stripe > 0 && stripe < info->conf.win_width
					&& sprt->trns_y < info->z_buf[stripe])
		{
			y = sprt->draw_strt_y - 1;
			while (++y < sprt->draw_end_y)
			{
				d = (y - sprt->v_mv_screen) * 256 - info->conf.win_height * 128
					+ sprt->height * 128;
				sprt->tex_y = ((d * TEX_HEIGHT) / sprt->height) / 256;
				sprt->color = info->texture[info->sprite[order[i]].texture]
							[TEX_WIDTH * sprt->tex_y + sprt->tex_x];
				if ((sprt->color & 0x00FFFFFF) != 0)
					info->buf[y][stripe] = sprt->color;
			}
		}
	}
}
