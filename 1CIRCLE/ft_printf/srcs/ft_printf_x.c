/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:26:17 by sunhkim           #+#    #+#             */
/*   Updated: 2021/01/30 19:34:44 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_printf_xa(t_flags *flags, int len, char *number)
{
	int count;

	count = 0;
	if (flags->minus == 0 && flags->zero == 1 && flags->point == -1)
		count += ft_putflags(flags->width - len, '0');
	else if (flags->minus == 0 && flags->zero == 1)
		count += ft_putflags(flags->width - len, ' ');
	else if (flags->minus == 0 && flags->zero == 0)
		count += ft_putflags(flags->width - len, ' ');
	count += ft_printf(number);
	if (flags->minus == 1)
		count += ft_putflags(flags->width - len, ' ');
	return (count);
}

static int	ft_printf_xb(t_flags *flags, int len, char *number)
{
	int count;

	count = 0;
	if (flags->minus == 0)
		count += ft_putflags(flags->width - flags->point, ' ');
	count += ft_putflags(flags->point - len, '0');
	count += ft_printf(number);
	if (flags->minus == 1)
		count += ft_putflags(flags->width - flags->point, ' ');
	return (count);
}

int			ft_printf_x(t_flags *flags, va_list args)
{
	int		count;
	int		dec;
	int		len;
	char	*number;

	ft_printf_star(flags, args);
	dec = va_arg(args, int);
	number = ft_itoa_base((unsigned int)dec, flags->type);
	count = 0;
	len = ft_strlen(number);
	if (flags->point == 0 && dec == 0)
		count += ft_putflags(flags->width, ' ');
	else if (flags->len == 0 || (len >= flags->width && len >= flags->point))
		count += ft_printf(number);
	else if (flags->point > len && flags->point >= flags->width)
		count += ft_putflags(flags->point - len, '0') + ft_printf(number);
	else if (flags->width >= len && len > flags->point)
		count += ft_printf_xa(flags, len, number);
	else if (flags->width > flags->point && flags->point >= len)
		count += ft_printf_xb(flags, len, number);
	free(number);
	return (count);
}
