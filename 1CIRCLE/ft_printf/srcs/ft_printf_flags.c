/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:12:42 by sunhkim           #+#    #+#             */
/*   Updated: 2021/01/30 19:35:42 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_star(t_flags *flags, va_list args)
{
	if (flags->star == 1)
		flags->width = va_arg(args, int);
	else if (flags->star == 2)
		flags->point = va_arg(args, int);
	else if (flags->star == 3)
	{
		flags->width = va_arg(args, int);
		flags->point = va_arg(args, int);
	}
	if (flags->width < 0)
	{
		flags->width = flags->width * -1;
		flags->minus = 1;
		flags->zero = 0;
	}
	if (flags->point < 0)
		flags->point = -1;
}

int		ft_by_type(t_flags *flags, va_list args)
{
	int count;

	count = 0;
	if (flags->type == 'd' || flags->type == 'i')
		count += ft_printf_d(flags, args);
	else if (flags->type == 'x' || flags->type == 'X')
		count += ft_printf_x(flags, args);
	else if (flags->type == 'c')
		count += ft_printf_c(flags, args);
	else if (flags->type == 's')
		count += ft_printf_s(flags, args);
	else if (flags->type == 'p')
		count += ft_printf_p(flags, args);
	else if (flags->type == 'u')
		count += ft_printf_u(flags, args);
	else if (flags->type == '%')
		count += ft_printf_percent(flags, args);
	else
		flags->len = 0;
	return (count);
}

int		ft_putflags(int i, char c)
{
	int count;

	count = 0;
	while (i-- > 0)
		count += ft_putchar(c);
	return (count);
}
