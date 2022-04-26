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
# define SO_LONG_H

# define BACK 0
# define WALL 1
# define PLAYER 2
# define TARGET 3
# define EXIT 4

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

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
	t_position	player;
	char	*map_buffer;
	int	*map;
	int	height;
	int	width;
	void	*back_img;
	void	*wall_img;
	void	*target_img;
	void	*player_img;
	void	*exit_img;
}				t_info;

/* memory.c */
int	init_info(t_info *info);
int free_info_print_error(t_info *info, char *str);

/* parsing.c */
int read_map(t_info *info, char *path);
int	check_map(t_info *info);
int	check_wall(t_info *info);
int check_elememts(t_info *info);

/* game.c */
void	set_img(t_info *info);

#endif