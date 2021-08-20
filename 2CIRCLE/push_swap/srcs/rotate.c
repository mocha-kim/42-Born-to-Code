/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:40:54 by sunhkim           #+#    #+#             */
/*   Updated: 2021/08/20 16:34:36 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_rx(t_list **buf, t_stack *stack, int opt)
{
	t_node	*tmp;
	t_node	*last;

	if (stack->size < 2)
		return ;
	tmp = stack->top;
	last = ft_node_last(stack->top);
	stack->top = stack->top->next;
	tmp->next = NULL;
	tmp->prev = last;
	last->next = tmp;
	stack->top->prev = NULL;
	add_operation(buf, opt);
}

void	rotate_rr(t_list **buf, t_stack *a, t_stack *b)
{
	rotate_rx(buf, a, DO_NOT);
	rotate_rx(buf, b, DO_NOT);
	add_operation(buf, RR);
}

void	r_rotate_rx(t_list **buf, t_stack *stack, int opt)
{
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	tmp = ft_node_last(stack->top);
	if (tmp->prev)
		tmp->prev->next = NULL;
	tmp->prev = NULL;
	ft_list_add_front(&stack->top, tmp);
	add_operation(buf, opt);
}

void	r_rotate_rr(t_list **buf, t_stack *a, t_stack *b)
{
	r_rotate_rx(buf, a, DO_NOT);
	r_rotate_rx(buf, b, DO_NOT);
	add_operation(buf, RRR);
}
