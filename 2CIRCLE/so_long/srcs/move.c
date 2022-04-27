/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:08:01 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/27 16:10:47 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/utils.h"

int	key_press(int keycode, t_info *info)
{
	t_position	pre_pos;
	int	flag;

	pre_pos.x = info->pos.x;
	pre_pos.y = info->pos.y;
	if (keycode == KEY_W)
		info->pos.y--;
	else if (keycode == KEY_S)
		info->pos.y++;
	else if (keycode == KEY_A)
	{
		info->pos.x--;
		info->direction = LEFT;
	}
	else if (keycode == KEY_D)
	{
		info->pos.x++;
		info->direction = RIGHT;
	}
	if (keycode == KEY_ESC)
		exit_game(info);
	flag = move(info, pre_pos);
	if (!flag)
		return (1);
	draw(info);
	return (1);
}

int	move(t_info *info, t_position pre)
{
	if (info->map[info->pos.y * info->width + info->pos.x] == '1')
	{
		info->pos.x = pre.x;
		info->pos.y = pre.y;
		return (0);
	}
	else if (info->map[info->pos.y * info->width + info->pos.x] == 'C')
	{
		info->target_num--;
	}
	ft_putstr_fd("step: ", STDOUT_FILENO);
	ft_putnbr_fd(info->step_count, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	info->step_count++;
	if (info->target_num == 0 && info->map[info->pos.y * info->width + info->pos.x] == 'E')
		clear_game(info);
	info->map[pre.y * info->width + pre.x] = '0';
	info->map[info->pos.y * info->width + info->pos.x] = 'P';
	return (1);
}