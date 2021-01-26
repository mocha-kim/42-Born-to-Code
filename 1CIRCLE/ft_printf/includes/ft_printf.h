/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:11:36 by sunhkim           #+#    #+#             */
/*   Updated: 2021/01/26 22:39:17 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_flags
{
	int			minus;
	int			zero;
	int			dot;
	int			star;
	int			width;
	char		type;
}				t_flags;

/*
** ft_printf.c
*/

int				ft_printf(const char *str, ...);
int				parse_str(va_list ap, char *str);
int				print_arg(va_list ap, t_flags flags);
void			treat_flag(va_list ap, char *str, int idx, t_flags *flags);
void			check_flag();

/*
** ft_printf_util.c
*/

t_flags			init_flags();
int				put_blanks(int start, int end, t_flags *flags);

/*
** print_cs.c
*/

int			print_char(int c, t_flags *flags);
int			print_buffer(char **buffer, char *str, int strlen, t_flags *flags);
int			print_str(char *str, t_flags *flags);

/*
** print_
*/

/*
** print_
*/


#endif
