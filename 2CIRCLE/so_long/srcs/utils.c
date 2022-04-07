/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:19:08 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/07 15:29:25 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || !s)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

int	ft_endcmp(char *str, char *s)
{
	int size;
	int	i;

	size = ft_strlen(str) - 1;
	i = ft_strlen(s) - 1;
	while (i >= 0 && size >= 0)
	{
		if (str[size--] != s[i--])
			return (0);
	}
	return (1);
}