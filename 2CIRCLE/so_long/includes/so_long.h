/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:22:06 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/07 16:03:00 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

typedef struct	s_position
{
	int	x;
	int	y;
}				t_position;

typedef struct	s_info
{
	t_position	*targets;
	t_position	map_exit;
	t_position	start;
	int	**map;
}				t_info;

int	parse_map(char *path);

#endif