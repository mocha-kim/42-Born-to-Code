/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:40:54 by sunhkim           #+#    #+#             */
/*   Updated: 2021/08/13 15:12:11 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** rotate.c
** ra : rotate stack - shift up all elements of stack stack by 1. The first element becomes the last one.
** rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
** rr : ra and rb at the same time.
*/

void	rotate_rx(t_stack *stack, int opt)
{
	t_node *tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->top;
	stack->top = stack->top->next;
	tmp->next = NULL;
	stack->top->prev = NULL;
	ft_list_add_back(&stack->top, tmp);
	print_operation(opt);
}

void	rotate_rr(t_stack *a, t_stack *b)
{
	rotate_rx(a, DO_NOT);
	rotate_rx(b, DO_NOT);
	write(1, "rr\n", 4);
}

/*
** rra : reverse rotate stack - shift down all elements of stack stack by 1. The last element becomes the first one.
** rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
** rrr : rra and rrb at the same time.
*/

void	r_rotate_rx(t_stack *stack, int opt)
{
	t_node *tmp;

	if (stack->size < 2)
		return ;
	tmp = ft_node_last(stack->top);
	if (tmp->prev)
		tmp->prev->next = NULL;
	tmp->prev = NULL;
	ft_list_add_front(&stack->top, tmp);
	print_operation(opt);
}

void	r_rotate_rr(t_stack *a, t_stack *b)
{
	r_rotate_rx(a, DO_NOT);
	r_rotate_rx(b, DO_NOT);
	write(1, "rrr\n", 5);
}