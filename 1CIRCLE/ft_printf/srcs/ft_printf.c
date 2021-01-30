/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:13:08 by sunhkim           #+#    #+#             */
/*   Updated: 2021/01/30 21:01:30 by sunhkim          ###   ########.fr       */
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
