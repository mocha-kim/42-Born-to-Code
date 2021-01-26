/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:18:47 by sunhkim           #+#    #+#             */
/*   Updated: 2021/01/26 22:33:39 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_arg(va_list ap, t_flags flags)
{
	int		result;
	char	type;

	result = 0;
	type = flags.type;
		
	if (type == 'c')
		result = print_char(va_arg(ap, int), &flags);
	else if (type == 's')
		result = print_str(va_arg(ap, char *), &flags);
	if (type == 'p')
		result = print_pointer(va_arg(ap, int), &flags);
	if (type == 'd' || type == 'i')
		result = print_int(va_arg(ap, int), &flags);
	if (type == 'u')
		result = print_int(va_arg(ap, unsigned int), &flags);
	if (type == 'x' || type == 'X')
		result = print_int_oc(va_arg(ap, unsigned int), &flags);
	if (type == '%')
		result = print_char('%', &flags);
	return (result - 1);
}

void	treat_flag(va_list ap, char *str, int idx, t_flags *flags)
{
	if (str[idx] == '-')
		flags->minus = 1;
	else if (str[idx] == '0')
		flags->zero = 1;
	else if (str[idx] == '.')
		flags->dot = 0;
	else if (str[idx] == '*')
	{
		if (flags->dot == -1)
		{
			flags->width = va_arg(ap, int);
			if (flags->width < 0)
			{
				flags->minus = 1;
				flags->width *= -1;
			}
		}
		else
			flags->dot = va_arg(ap, int);
	}
	else if (ft_isdigit(str[idx]))
	{
		flags->dot == -1 ? (flags->width = flags->width * 10 + str[idx] - 48)
			: (flags->dot = flags->dot * 10 + str[idx] - 48);
	}
}

void	check_flag(t_flags *flags)
{
	if (flags->minus && flags->zero)
		flags->zero = 0;
/*
**	if (flags->type == '%' || flags->type == 'c' || flags->type == 's')
**		flags->zero = 0;
*/
}

int		parse_str(va_list ap, char *str)
{
	int		i;
	int		result;
	t_flags	flags;

	i = -1;
	result = 0;
	while (str[++i] != 0)
	{
		if (str[i] == '%')
		{
			flags = init_flags();
			i++;
			while (str[++i]!= 0 && !ft_strchr("cspdiuxX%", str[i]))
				treat_flag(ap, str, i, &flags);
			flags.type = str[i];
			check_flag(&flags);
			result += print_arg(ap, flags);
		}
		else
			ft_putchar(str[i]);
		result++;
	}
	return (result);
}

int		ft_printf(const char *str, ...)
{
	int		result;
	char	*save;
	va_list	ap;

	save = ft_strdup(str);
	va_start(ap, str);
	result = parse_str(ap, save);
	va_end(ap);
	return (result);
}
