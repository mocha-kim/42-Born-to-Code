/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:40:19 by sunhkim           #+#    #+#             */
/*   Updated: 2021/05/12 17:40:22 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	calc_score(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->sprite_num)
	{
		if ((int)info->pos_x == (int)info->sprite[i].x
		&& (int)info->pos_y == (int)info->sprite[i].y
		&& info->sprite[i].texture == T_S)
		{
			info->sprite[i].x = info->sprite[info->sprite_num - 1].x;
			info->sprite[i].y = info->sprite[info->sprite_num - 1].y;
			info->sprite[i].texture = info->sprite[info->sprite_num
			- 1].texture;
			info->sprite_num--;
			info->score++;
			break ;
		}
		i++;
	}
}

void		draw_score(t_info *info)
{
	char	*score;

	calc_score(info);
	score = ft_itoa(info->score);
	mlx_string_put(info->mlx, info->win, info->conf.win_width - 100,
	info->conf.win_height - 10, 0xFFFFFF, "score : ");
	mlx_string_put(info->mlx, info->win, info->conf.win_width - 45,
	info->conf.win_height - 10, 0xFFFFFF, score);
	free(score);
}
