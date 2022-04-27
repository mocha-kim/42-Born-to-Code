/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:37:21 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/26 16:10:47 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>

void	put_img(t_info *info, int h, int w)
{
	if (info->map[h * info->width + w] == '1')
		mlx_put_image_to_window(info->mlx, info->win,
			info->wall_img, w * TILE, h * TILE);
	else if (info->map[h * info->width + w] == 'C')
		mlx_put_image_to_window(info->mlx, info->win,
			info->target_img, w * TILE, h * TILE);
	else if (info->map[h * info->width + w] == 'P')
	{
		if (info->direction == LEFT)
			mlx_put_image_to_window(info->mlx, info->win,
				info->player_l_img, w * TILE, h * TILE);
		else
			mlx_put_image_to_window(info->mlx, info->win,
				info->player_r_img, w * TILE, h * TILE);
	}
	else if (info->map[h * info->width + w] == 'E')
		mlx_put_image_to_window(info->mlx, info->win,
			info->exit_img, w * TILE, h * TILE);
	else
		mlx_put_image_to_window(info->mlx, info->win,
			info->back_img, w * TILE, h * TILE);
}

void	draw_init_background(t_info *info)
{
	int		h;
	int		w;

	h = 0;
	while (h < info->height)
	{
		w = 0;
		while (w < info->width)
		{
			if (info->map[h * info->width + w] == '1')
				mlx_put_image_to_window(info->mlx, info->win,
					info->wall_img, w * TILE, h * TILE);
			else
				mlx_put_image_to_window(info->mlx, info->win,
					info->back_img, w * TILE, h * TILE);
			w++;
		}
		h++;
	}
}

void	draw(t_info *info)
{
	int		h;
	int		w;

	h = 0;
	while (h < info->height)
	{
		w = 0;
		while (w < info->width)
		{
			put_img(info, h, w);
			w++;
		}
		h++;
	}
}

void	clear_game(t_info *info)
{
	ft_putstr_fd("Game Clear! Total Step: ", STDOUT_FILENO);
	ft_putnbr_fd(info->step_count, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	exit_game(info);
}

void	exit_game(t_info *info)
{
	if (info->map)
		free(info->map);
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
}
