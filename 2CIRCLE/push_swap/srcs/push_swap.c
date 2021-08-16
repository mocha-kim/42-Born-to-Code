/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:21:07 by sunhkim           #+#    #+#             */
/*   Updated: 2021/08/16 16:44:06 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_operation(int option)
{
	if (option == DO_NOT)
		return ;
	if (option == SA)
		write(1, "sa\n", 4);
	else if (option == SB)
		write(1, "sb\n", 4);
	else if (option == RA)
		write(1, "ra\n", 4);
	else if (option == RB)
		write(1, "rb\n", 4);
	else if (option == RRA)
		write(1, "rra\n", 5);
	else if (option == RRB)
		write(1, "rrb\n", 5);
	else
		return ;
}

void	push_swap(t_info *info)
{
	if (info->a.size == 1)
		return ;
	if (check_sorted_stack(&(info->a), 1))
		return ;
	if (info->a.size <= 5)
		solve_small(info);
	else if (info->a.size <= 100)
		solve_medium(info, 0);
	else
		solve_large(info);
}