/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:11:36 by sunhkim           #+#    #+#             */
/*   Updated: 2021/01/21 18:46:10 by sunhkim          ###   ########.fr       */
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

int				ft_printf(const char *str, ...);
int				parse_str(va_list ap, char *str);
int				print_arg(va_list ap, t_flags flags);
t_flags			init_flags();
void			treat_flag(char *str, int idx, t_flags *flags);

#endif
