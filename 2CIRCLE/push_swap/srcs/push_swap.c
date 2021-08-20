/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:21:07 by sunhkim           #+#    #+#             */
/*   Updated: 2021/08/20 16:33:52 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_operation(t_list **buf, int option)
{
	if (option == DO_NOT)
		return ;
	if (option == SA)
		ft_lstadd_back(buf, ft_lstnew(ft_strdup("sa\n")));
	else if (option == SB)
		ft_lstadd_back(buf, ft_lstnew(ft_strdup("sb\n")));
	else if (option == SS)
		ft_lstadd_back(buf, ft_lstnew(ft_strdup("ss\n")));
	else if (option == RA)
		ft_lstadd_back(buf, ft_lstnew(ft_strdup("ra\n")));
	else if (option == RB)
		ft_lstadd_back(buf, ft_lstnew(ft_strdup("rb\n")));
	else if (option == RR)
		ft_lstadd_back(buf, ft_lstnew(ft_strdup("rr\n")));
	else if (option == RRA)
		ft_lstadd_back(buf, ft_lstnew(ft_strdup("rra\n")));
	else if (option == RRB)
		ft_lstadd_back(buf, ft_lstnew(ft_strdup("rrb\n")));
	else if (option == RRR)
		ft_lstadd_back(buf, ft_lstnew(ft_strdup("rrr\n")));
	else if (option == PA)
		ft_lstadd_back(buf, ft_lstnew(ft_strdup("pa\n")));
	else if (option == PB)
		ft_lstadd_back(buf, ft_lstnew(ft_strdup("pb\n")));
}

void	print_operation(t_list **buf)
{
	t_list	*tmp;

	tmp = *buf;
	while (tmp)
	{
		write(1, tmp->content, ft_strlen(tmp->content));
		tmp = tmp->next;
	}
}

void	push_swap(t_info *info)
{
	if (info->a.size == 1)
		return ;
	if (check_sorted_stack(&(info->a), 1, info->a.size))
		return ;
	if (info->a.size <= 5)
		solve_small(info);
	else
		solve(info);
	print_operation(&(info->buf));
}
