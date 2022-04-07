/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:37:25 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/07 16:15:43 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
#define GNL_H

# include "utils.h"

# define BUFFER_SIZE 128

int				get_next_line(int fd, char **line);
int				save_line(char **dest, char *src, char **save);

#endif