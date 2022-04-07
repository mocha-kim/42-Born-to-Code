/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:19:17 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/07 15:35:42 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/utils.h"

int print_error(char *description)
{
	ft_putstr_fd("Error\n:", STDERR_FILENO);
	ft_putstr_fd(description, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

int	main(int argc, char *argv[])
{
	int signal;

	if (argc != 3)
		return (print_error("map argument must be needed"));
	signal = parse_map(argv[2]);
	if (signal)
	{

	}
	return (0);
}