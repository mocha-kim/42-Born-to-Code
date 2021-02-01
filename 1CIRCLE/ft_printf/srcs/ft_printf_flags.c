/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:12:42 by sunhkim           #+#    #+#             */
/*   Updated: 2021/02/01 15:47:17 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->star = 0;
	flags->point = -1;
	flags->width = 0;
	flags->len = 0;
	flags->type = '\0';
}

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

int		ft_putflags(int i, char c)
{
	int count;

	count = 0;
	while (i-- > 0)
		count += ft_putchar(c);
	return (count);
}
