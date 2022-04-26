/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info->c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:37:21 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/26 16:10:47 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_img(t_info *info)
{
	int		hei;
	int		wid;

	hei = 0;
	while (hei < info->height)
	{
		wid = 0;
		while (wid < info->width)
		{
			if (info->str_line[hei * info->width + wid] == WALL)
				mlx_put_image_to_window(info->mlx, info->win, info->wall_img , wid * 64, hei * 64);
			else if (info->str_line[hei * info->width + wid] == TARGET)
				mlx_put_image_to_window(info->mlx, info->win, info->target_img, wid * 64, hei * 64);
			else if (info->str_line[hei * info->width + wid] == PLAYER)
				mlx_put_image_to_window(info->mlx, info->win, info->player_img, wid * 64, hei * 64);
			else if (info->str_line[hei * info->width + wid] == EXIT)
				mlx_put_image_to_window(info->mlx, info->win, info->exit_img, wid * 64, hei * 64);
			else
				mlx_put_image_to_window(info->mlx, info->win, info->back_img, wid * 64, hei * 64);
			wid++;
		}
		hei++;
	}
}