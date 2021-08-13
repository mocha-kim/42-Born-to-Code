/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_large.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:17:31 by sunhkim           #+#    #+#             */
/*   Updated: 2021/08/13 16:14:25 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	solve_large(t_info *info)
{
	if (info->a.size == 1)
		return ;
	else if (info->a.size == 2)
	{
		if (info->a.top->num > info->a.top->next->num)
			swap_sx(&(info->a), SA);
		return ;
	}
}