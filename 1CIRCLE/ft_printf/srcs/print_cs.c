/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:52:48 by sunhkim           #+#    #+#             */
/*   Updated: 2021/01/26 22:42:13 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_char(int c, t_flags *flags)
{
	int		result;

	result = 0;
	if (flags->minus)
		ft_putchar(c);
	result += put_blanks(1, flags->width, flags);
	if (!(flags->minus))
		ft_putchar(c);
}

int		print_buffer(char **buffer, char *str, int strlen, t_flags *flags)
{
	int		i;
	int		result;

	i = 0;
	while (i < strlen)
	{
		*buffer[i] = str[i];
		i++;
	}
	buffer[i] = 0;
	if (flags->minus)
		ft_putstr(*buffer);
	result += put_blanks(strlen, flags->width, flags);
	if (!(flags->minus))
		ft_putstr(*buffer);
	return (result + strlen);
}

int		print_str(char *str, t_flags *flags)
{
	int		result;
	size_t	strlen;
	char	*buffer;

	result = 0;
	if (!str)
		str = "(null)";
	if (flags->dot == -1 || ft_strlen(str) < (size_t)flags->dot)
		strlen = ft_strlen(str);
	if (!(buffer = (char *)malloc(sizeof(char) * (strlen + 1))))
		return (0);
	result = print_buffer(&buffer, str, strlen, flags);
	free(buffer);
	return (result);
}
