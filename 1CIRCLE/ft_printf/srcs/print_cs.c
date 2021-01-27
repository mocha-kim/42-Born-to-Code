/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:52:48 by sunhkim           #+#    #+#             */
/*   Updated: 2021/01/27 19:28:00 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_char(int c, t_flags *flags)
{
	int		result;
	char	*blanks;

	result = 1;
	if (flags->minus)
		ft_putchar(c);
	if (!(blanks = get_blanks(1, flags)))
	{
		ft_putstr(blanks);
		result += ft_strlen(blanks);
	}
	if (!(flags->minus))
		ft_putchar(c);
	return (result);
}

int		print_str(char *str, t_flags *flags)
{
	int		result;
	size_t	strlen;
	char	*tmpstr;
	char	*blanks;

	result = 0;
	if (!str)
		str = "(null)";
	strlen = flags->width;
	if (flags->dot == -1 || ft_strlen(str) < (size_t)flags->dot)
		strlen = ft_strlen(str);
	blanks = get_blanks(strlen, flags);
	if (!(tmpstr = (char *)malloc(sizeof(char) * (strlen + 1))))
		return (0);
	result = print_buffer(tmpstr, blanks, flags);
	free(tmpstr);
	free(blanks);
	return (result);
}
