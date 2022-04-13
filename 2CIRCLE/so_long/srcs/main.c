/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:19:17 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/08 00:46:23 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/utils.h"

int	main(int argc, char *argv[])
{
	int flag;
	t_info info;

	if (argc != 2)
		return (ft_print_error("invalid argument number"));
	flag = read_map(&info, argv[1]);
	if (flag)
	{
		info->map = malloc(sizeof(int*) * (info->map_col + 1));
		if (!info->map)
			return (free_info_print_error(info, "malloc failed"));
		flag = parse_map(&info);
		if (!flag)
			return (0);
		// start game
	}
	return (0);
}