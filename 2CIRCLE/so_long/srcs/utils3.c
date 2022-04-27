/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:51:33 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/27 00:41:14 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
		}
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || !s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

int ft_print_error(char *str)
{
	ft_putstr_fd("Error\n:", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (0);
}

int	check_file_name(char *path)
{
	int	i;

	i = ft_strlen(path) - 1;
	if (path[i--] != 'r')
		return (ft_print_error("invalid map extension"));
	if (path[i--] != 'e')
		return (ft_print_error("invalid map extension"));
	if (path[i--] != 'b')
		return (ft_print_error("invalid map extension"));
	if (path[i--] != '.')
		return (ft_print_error("invalid map extension"));
	return (1);
}