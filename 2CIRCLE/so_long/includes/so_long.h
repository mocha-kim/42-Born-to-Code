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
#include "../includes/utils.h"

# define TILE	64
# define WIN_WIDTH	2560
# define WIN_HEIGHT	1440

# define LEFT	0
# define RIGHT	1

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

typedef struct	s_position
{
	int	x;
	int	y;
}				t_position;

typedef struct	s_info
{
	void	*mlx;
	void	*win;
	t_position	pos;
	int	direction;
	char	*map;
	int	height;
	int	width;
	int	win_h;
	int	win_w;
	int	target_num;
	int	step_count;
	void	*back_img;
	void	*wall_img;
	void	*target_img;
	void	*player_r_img;
	void	*player_l_img;
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
int	check_elememts(t_info *info, int i, int *p, int *t, int *e);

/* game.c */
void	put_img(t_info *info, int h, int w);
void	draw_init_background(t_info *info);
void	draw(t_info *info);
void	clear_game(t_info *info);
void	exit_game(t_info *info);

/* move.c */
int	key_press(int keycode, t_info *info);
int	move(t_info *info, t_position pre);

#endif