/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 00:30:06 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/08 00:34:45 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/utils.h"

int free_info_print_error(t_info *info, char *str)
{
	int i;

	i = 0;
	if (info->map)
	{
		while (info->map[i])
		{
			if (info->map[i])
				free(info->map[i]);
			i++;
		}
		free(info->map);
	}
	if (info->map_buffer)
		ft_lstclear(&info->map_buffer);
	return (ft_print_error(str));
}