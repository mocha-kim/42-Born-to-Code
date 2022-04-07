/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:19:17 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/07 16:16:21 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/utils.h"

int	main(int argc, char *argv[])
{
	int flag;

	if (argc != 2)
		return (ft_print_error("invalid argument number"));
	flag = parse_map(argv[1]);
	if (flag)
	{
		
	}
	return (0);
}