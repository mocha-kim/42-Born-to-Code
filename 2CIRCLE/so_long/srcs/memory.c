/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 00:30:06 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/27 01:02:38 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/utils.h"

void	init_info(t_info *i)
{
	i->pos.x = 0;
	i->pos.y = 0;
	i->height = 0;
	i->width = 0;
}

void	init_mlx(t_info *i)
{
	int	w;
	int	h;
	
	i->mlx = mlx_init();
	i->win = mlx_new_window(i->mlx, i->width * 64, i->height * 64, "mlx_project");

	i->back_img = mlx_xpm_file_to_image(i->mlx, "./sprites/back.xpm", &w, &h);
	i->wall_img = mlx_xpm_file_to_image(i->mlx, "./sprites/wall.xpm", &w, &h);
	i->target_img = mlx_xpm_file_to_image(i->mlx, "./sprites/box.xpm", &w, &h);
	i->player_img = mlx_xpm_file_to_image(i->mlx, "./sprites/king.xpm", &w, &h);
	i->exit_img = mlx_xpm_file_to_image(i->mlx, "./sprites/door.xpm", &w, &h);
}

int free_info_print_error(t_info *info, char *str)
{
	if (info->map)
		free(info->map);
	return (ft_print_error(str));
}