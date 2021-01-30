/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:11:36 by sunhkim           #+#    #+#             */
/*   Updated: 2021/01/30 19:34:42 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

typedef	struct	s_flags{
	int		minus;
	int		zero;
	int		star;
	int		point;
	int		width;
	int		len;
	char	type;
}				t_flags;

/*
** ft_printf.c
*/

int				ft_printf(const char *str, ...);
int				read_flags(t_flags *flags, const char *str);
void			check_flag(const char f, t_flags *flags);
void			init_flags(t_flags *flags);

/*
** ft_printf_utils.c
*/

int				ft_putchar(char c);
int				ft_putnbr(int n);
int				ft_isnum(int c);
int				ft_numlen(int num);
int				ft_strlen(char *s);

/*
** ft_printf_utils2.c
*/

int				ft_padding(int n, char c);
int				ft_count_digit(unsigned long int n);
char			*ft_itoa_base(unsigned long int n, char type);

/*
** ft_printf_flags.c
*/

void			ft_printf_star(t_flags *flags, va_list args);
int				ft_by_type(t_flags *flags, va_list args);
int				ft_putflags(int i, char c);

/*
** ft_printf_cs.c
*/

int				ft_printf_c(t_flags *flags, va_list args);
int				ft_printf_s(t_flags *flags, va_list args);
int				ft_printf_percent(t_flags *flags, va_list args);

/*
** ft_printf_d.c
*/

int				ft_printf_d(t_flags *flags, va_list args);

/*
** ft_printf_u.c
*/

int				ft_printf_u(t_flags *flags, va_list args);

/*
** ft_printf_p.c
*/

int				ft_printf_p(t_flags *flags, va_list args);

/*
** ft_printf_x.c
*/

int				ft_printf_x(t_flags *flags, va_list argd);

#endif
