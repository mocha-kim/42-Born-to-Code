/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 00:30:06 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/08 00:34:45 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/utils.h"

int	init_info(t_info *info)
{
	int	img_width;
	int	img_height;
	
	info->player.x = 0;
	info->player.y = 0;
	info->height = 0;
	info->width = 0;

	back_img = mlx_xpm_file_to_image(mlx, "./images/land.xpm", &img_width, &img_height);
	wall_img = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &img_width, &img_height);
	enemy_img = mlx_xpm_file_to_image(mlx, "./images/chara.xpm", &img_width, &img_height);
	player_img = mlx_xpm_file_to_image(mlx, "./images/chest.xpm", &img_width, &img_height);
	exit_img = mlx_xpm_file_to_image(mlx, "./images/chest_open.xpm", &img_width, &img_height);
}

int free_info_print_error(t_info *info, char *str)
{
	int i;

	i = 0;
	if (info->map)
	{
		while (info->map[i])
		{
			if (info->map[i])
				free(info->map[i]);
			i++;
		}
		free(info->map);
	}
	if (info->map_buffer)
		ft_lstclear(&info->map_buffer);
	return (ft_print_error(str));
}