/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:11:36 by sunhkim           #+#    #+#             */
/*   Updated: 2021/01/28 21:26:52 by sunhkim          ###   ########.fr       */
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
char			*get_blanks(int strlen, t_flags *flags);
void			add_prec(char **str, size_t *strlen, t_flags *flags);
int				print_buffer(char *str, char *blank, t_flags *flags);

/*
** print_cs.c
*/

int				print_char(int c, t_flags *flags);
int				print_str(char *str, t_flags *flags);

/*
** print_diu.c
*/

int				print_int(int num, t_flags *flags);
int				print_uint(unsigned int num, t_flags *flags);

/*
** print_pxX.c
*/

void			put_pointer_sign(char **str);
int				print_pointer(unsigned long address, t_flags *flags);
int				print_ocint(unsigned int num, t_flags *flags);

#endif
