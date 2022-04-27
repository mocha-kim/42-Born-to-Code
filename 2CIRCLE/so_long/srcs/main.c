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

int	main(int argc, char *argv[])
{
	int	flag;
	t_info	info;

	if (argc != 2)
		return (ft_print_error("invalid argument number"));
	init_info(&info);
	flag = read_map(&info, argv[1]);
	if (flag)
	{
		flag = check_map(&info);
		if (!flag)
			return (0);
		init_mlx(&info);
		draw_init_background(&info);
		draw(&info);
		mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
		mlx_loop(info.mlx);
	}
	return (0);
}