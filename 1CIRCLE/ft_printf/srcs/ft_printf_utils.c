/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:55:51 by sunhkim           #+#    #+#             */
/*   Updated: 2021/01/27 20:09:55 by sunhkim          ###   ########.fr       */
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

char	*get_blanks(int strlen, t_flags *flags)
{
	int		i;
	int		zero;
	int		width;
	char	*result;

	width = flags->width;
	if (strlen >= width || width == -1)
		return (NULL);
	if (!(result = (char *)malloc(sizeof(char) * (width - strlen + 2))))
		return (NULL);
	i = 0;
	zero = flags->zero;
	while (i < width - strlen + 1)
	{
		if (zero)
			result[i] = '0';
		else
			result[i] = ' ';
		i++;
	}
	result[i] = 0;
	return (result);
}

int		print_buffer(char *str, char *blanks, t_flags *flags)
{
	int		result;
	char	*buffer;

	if (!blanks)
	{
		if (flags->minus)
			buffer = ft_strjoin(str, blanks);
		else
			buffer = ft_strjoin(blanks, str);
	}
	else
		buffer = ft_strdup(str);
	ft_putstr(buffer);
	result = ft_strlen(buffer);
	free(buffer);
	return (result);
}
