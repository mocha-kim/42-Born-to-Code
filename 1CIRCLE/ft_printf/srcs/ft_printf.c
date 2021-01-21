/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:18:47 by sunhkim           #+#    #+#             */
/*   Updated: 2021/01/21 18:52:15 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"

t_flags	init_flags()
{
	t_flags flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.dot = 0;
	flags.star = 0;
	flags.width = 0;
	flags.type = 0;
	return (flags);
}

int		print_arg(va_list ap, t_flags flags)
{
	int		result;

	result = 0;
	return (result);
}

void	treat_flag(char *str, int idx, t_flags *flags)
{
	if (str[idx] == '-')
	{
	}
	else if (str[idx] == '0')
	{
	}
	else if (str[idx] == '.')
	{
	}
	else if (str[idx] == '*')
	{
	}
	else if (str[idx] == 'o')
	{
	}
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
		printf("%d\n", i);
		if (str[i] == '%')
		{
			flags = init_flags();
			i++;
			while (str[i]!= 0 && !ft_strchr("cspdiuxX%", str[i]))
			{
				treat_flag(str, i, &flags);
				i++;
			}
			flags.type = str[i];
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
