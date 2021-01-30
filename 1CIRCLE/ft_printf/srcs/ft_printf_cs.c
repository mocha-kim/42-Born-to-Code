/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:12:07 by sunhkim           #+#    #+#             */
/*   Updated: 2021/01/30 19:30:17 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_c(t_flags *flags, va_list args)
{
	int		count;
	char	c;

	ft_printf_star(flags, args);
	c = va_arg(args, int);
	count = 0;
	if (flags->minus == 1)
		count = ft_putchar(c) + ft_padding(flags->width - 1, ' ');
	else
		count = ft_padding(flags->width - 1, ' ') + ft_putchar(c);
	return (count);
}

int	ft_printf_s(t_flags *flags, va_list args)
{
	int		count;
	char	*str;
	int		size;
	int		pad_size;

	ft_printf_star(flags, args);
	str = va_arg(args, char *);
	count = 0;
	if (flags->point == 0 && flags->width == 0)
		return (0);
	if (str == NULL)
		str = "(null)";
	size = (flags->point > ft_strlen(str) || flags->point == -1)
			? ft_strlen(str) : flags->point;
	pad_size = flags->width - size;
	if (!flags->minus)
		count += ft_padding(pad_size, flags->zero ? '0' : ' ');
	while (size-- && *str)
		count += ft_putchar(*str++);
	if (flags->minus)
		count += ft_padding(pad_size, ' ');
	return (count);
}

int	ft_printf_percent(t_flags *flags, va_list args)
{
	int		count;

	ft_printf_star(flags, args);
	count = 0;
	if (flags->minus)
		count += ft_putchar('%');
	count += ft_padding(flags->width - 1, flags->zero ? '0' : ' ');
	if (!flags->minus)
		count += ft_putchar('%');
	return (count);
}
