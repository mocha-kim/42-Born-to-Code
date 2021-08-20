/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:40:47 by sunhkim           #+#    #+#             */
/*   Updated: 2021/08/20 16:34:15 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_pa(t_list **buf, t_stack *a, t_stack *b)
{
	t_node	*node;

	if (b->size == 0)
		return ;
	node = b->top;
	if (b->size == 1)
		b->top = NULL;
	else
	{
		b->top = b->top->next;
		b->top->prev = NULL;
	}
	node->next = NULL;
	b->size--;
	if (a->size >= 1)
	{
		node->next = a->top;
		a->top->prev = node;
	}
	a->top = node;
	a->size++;
	add_operation(buf, PA);
}

void	push_pb(t_list **buf, t_stack *a, t_stack *b)
{
	t_node	*node;

	if (a->size == 0)
		return ;
	node = a->top;
	if (a->size == 1)
		a->top = NULL;
	else
	{
		a->top = a->top->next;
		a->top->prev = NULL;
	}
	node->next = NULL;
	a->size--;
	if (b->size >= 1)
	{
		node->next = b->top;
		b->top->prev = node;
	}
	b->top = node;
	b->size++;
	add_operation(buf, PB);
}
