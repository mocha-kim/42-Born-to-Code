/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:55:51 by sunhkim           #+#    #+#             */
/*   Updated: 2021/01/26 22:39:19 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags init_flags()
{
	t_flags flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	flags.star = -1;
	flags.width = -1;
	flags.type = 0;
	return (flags);
}

int		put_blanks(int start, int end, t_flags *flags)
{
	int		result;
	int		zero;

	result = 0;
	zero = flags->zero;
	while (start <= end)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		result++;
		start++;
	}
	return (result);
}
