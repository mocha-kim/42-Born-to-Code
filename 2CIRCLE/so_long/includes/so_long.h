/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:22:06 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/08 00:42:11 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "list.h"

#define BACK 0
#define WALL 1
#define PLAYER 2
#define TARGET 3
#define EXIT 4

typedef struct	s_position
{
	int	x;
	int	y;
}				t_position;

typedef struct	s_info
{
	void		*mlx;
	void		*win;
	t_position	player;
	t_list	*map_buffer;
	int	**map;
	int	height;
	int	width;
	void	*back_img;
	void	*wall_img;
	void	*enemy_img;
	void	*player_img;
	void	*exit_img;
}				t_info;

/* memory.c */
int free_info_print_error(t_info *info, char *str);

/* parsing.c */
int read_map(t_info *info, char *path);
int	parse_map(t_info *info);
int check_line(t_info *info, char *line);
int parse_line(t_info *info, char *line, int i);
int parse_first_last_line(t_info *info, char *line);

#endif