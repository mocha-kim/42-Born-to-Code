/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:13:08 by sunhkim           #+#    #+#             */
/*   Updated: 2021/02/01 15:57:00 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_flag(const char f, t_flags *flags)
{
	if (f == '-')
	{
		flags->minus = 1;
		flags->zero = 0;
	}
	if (f == '0' && flags->minus != 1 && flags->point != 0)
		flags->zero = 1;
	if (f == '.')
		flags->point = (flags->point == -1) ? 0 : -2;
	if (f == '*')
	{
		if (flags->point == -1)
			flags->star = 1;
		else
			flags->star = (flags->star == 0) ? 2 : 3;
	}
}

int		read_flags(t_flags *flags, const char *str)
{
	int i;

	i = 0;
	while (str[i] == '-' || str[i] == '*' || str[i] == '.' || ft_isnum(str[i]))
	{
		check_flag(str[i], flags);
		if (ft_isnum(str[i]))
			while (ft_isnum(str[i]))
			{
				if (flags->point == -1)
					flags->width = (flags->width * 10) + (str[i] - '0');
				if (flags->point >= 0)
					flags->point = (flags->point * 10) + (str[i] - '0');
				i++;
			}
		else
			i++;
	}
	flags->type = str[i];
	flags->len = i;
	return (i);
}

int		ft_by_type(t_flags *flags, va_list args)
{
	int count;

	count = 0;
	if (flags->type == 'c')
		count += ft_printf_c(flags, args);
	else if (flags->type == 's')
		count += ft_printf_s(flags, args);
	else if (flags->type == 'd' || flags->type == 'i')
		count += ft_printf_d(flags, args);
	else if (flags->type == 'p')
		count += ft_printf_p(flags, args);
	else if (flags->type == 'u')
		count += ft_printf_u(flags, args);
	else if (flags->type == 'x' || flags->type == 'X')
		count += ft_printf_x(flags, args);
	else if (flags->type == '%')
		count += ft_printf_percent(flags, args);
	else
		flags->len = 0;
	return (count);
}

int		ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;
	t_flags	flags;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			init_flags(&flags);
			str++;
			read_flags(&flags, str);
			count += ft_by_type(&flags, args);
			str = str + flags.len;
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (count);
}
