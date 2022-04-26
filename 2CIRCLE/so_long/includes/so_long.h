/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:22:06 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/27 01:02:37 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx/mlx.h"
#include <stdio.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct	s_position
{
	int	x;
	int	y;
}				t_position;

typedef struct	s_info
{
	void		*mlx;
	void		*win;
	t_position	pos;
	char	*map;
	int	height;
	int	width;
	void	*back_img;
	void	*wall_img;
	void	*target_img;
	void	*player_img;
	void	*exit_img;
}				t_info;

/* memory.c */
void	init_info(t_info *info);
void	init_mlx(t_info *i);
int free_info_print_error(t_info *info, char *str);

/* parsing.c */
int read_map(t_info *info, char *path);
int	read_first_line(t_info *info, int fd);
int	check_map(t_info *info);
int	check_wall(t_info *info, int i);
void	check_elememts(char map, int *p, int *t, int *e);

/* game.c */
void	put_img(t_info *info, int h, int w);
void	draw(t_info *info);
void	clear_game(t_info *info);
void	exit_game(t_info *info);

#endif