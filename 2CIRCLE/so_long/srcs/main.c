/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:19:17 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/27 01:07:13 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/utils.h"

int	key_press(int keycode, t_info *info)
{
	int	x;
	int	y;

	x = info->pos.x;
	y = info->pos.y;
	if (keycode == KEY_W)
		info->pos.y++;
	else if (keycode == KEY_S)
		info->pos.y--;
	else if (keycode == KEY_A)
		info->pos.x--;
	else if (keycode == KEY_D)
		info->pos.x++;
	else if (keycode == KEY_ESC)
		exit_game(info);
	info->map[y * info->width + x] = '0';
	info->map[info->pos.y * info->width + info->pos.x] = 'P';
	draw(info);
	return (1);
}

int	main(int argc, char *argv[])
{
	int	flag;
	t_info	info;

	if (argc != 2)
		return (ft_print_error("invalid argument number"));
	init_info(&info);
	flag = check_file_name(argv[1]);
	if (!flag)
		return (0);
	flag = read_map(&info, argv[1]);
	if (flag)
	{
		flag = check_map(&info);
		if (!flag)
			return (0);
		// start game
		init_mlx(&info);
		mlx_hook(info.win, X_EVENT_KEY_RELEASE, 0, &key_press, &info);
		mlx_loop(info.mlx);
	}
	return (0);
}