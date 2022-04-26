/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:19:17 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/08 00:46:23 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/utils.h"

int				key_press(int keycode, t_info *info)
{
	static int a = 0;

	if (keycode == KEY_W)
		info->player->y++;
	else if (keycode == KEY_S)
		info->player->y--;
	else if (keycode == KEY_A)
		info->player->x--;
	else if (keycode == KEY_D)
		info->player->x++;
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	flag;
	t_info	info;

	if (argc != 2)
		return (ft_print_error("invalid argument number"));
	flag = read_map(&info, argv[1]);
	if (flag)
	{
		info->map = malloc(sizeof(int*) * (info->map_col + 1));
		if (!info->map)
			return (free_info_print_error(info, "malloc failed"));
		flag = parse_map(&info);
		if (!flag)
			return (0);
		// start game
		mlx = mlx_init();
		win = mlx_new_window(mlx, 500, 500, "mlx_project");
		mlx_hook(win, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
		mlx_loop(mlx);
	}
	return (0);
}