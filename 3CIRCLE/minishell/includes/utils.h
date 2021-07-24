/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:45:02 by yoahn             #+#    #+#             */
/*   Updated: 2021/07/14 15:35:27 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "error.h"
# include "env.h"
# include <fcntl.h>

/*
** utils.c
*/

int			custom_putchar(int c);
int			skip_whitespace(const char *str, int *i);
void		free_program(t_dlist **programs);
char		*ft_strjoin_null(char const *s1, char const *s2);
char		*split_and_join(char *str, int i, int j);

/*
** utils2.c
*/

t_history	*ft_historynew(char *save);
void		ft_historyadd_front(t_history **lst, t_history *new);
void		ft_historydelone(t_history *lst, void (*del)(void *));
void		ft_historyclear(t_history **lst, void (*del)(void *));
void		ft_strdel2(char **str);

/*
** utils3.c
*/

void		init_state(void);
void		free_state(void);

#endif
