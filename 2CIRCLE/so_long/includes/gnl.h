/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:37:25 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/07 23:06:53 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "utils.h"

# define BUFFER_SIZE 128
# define OPEN_MAX 1024

char	*ft_get_line(char *save);
char	*ft_save(char *save);
char	*ft_read_and_save(int fd, char *save);
char	*get_next_line(int fd);

#endif