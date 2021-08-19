/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:40:51 by sunhkim           #+#    #+#             */
/*   Updated: 2021/08/19 17:10:56 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** sa : swap a - swap the first 2 elements at the top of stack a.
** Do nothing if there is only one or no elements.
** sb : swap b - swap the first 2 elements at the top of stack b.
** Do nothing if there is only one or no elements.
*/

void	swap_sx(t_list **buf, t_stack *stack, int opt)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	if (!stack->top)
		return ;
	tmp = stack->top->num;
	stack->top->num = stack->top->next->num;
	stack->top->next->num = tmp;
	add_operation(buf, opt);
}

/*
** ss : sa and sb at the same time.
*/

void	swap_ss(t_list **buf, t_stack *a, t_stack *b)
{
	swap_sx(buf, a, DO_NOT);
	swap_sx(buf, b, DO_NOT);
	add_operation(buf, SS);
}