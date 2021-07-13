/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 21:05:14 by sunhkim           #+#    #+#             */
/*   Updated: 2021/05/21 18:09:06 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct	s_node
{
	t_node		*prev;
	t_node		*next;
	int			num;
}				t_node;

typedef struct	s_stack
{
	t_node	*head;
	t_node	*tail;
	size_t	size;
	size_t	high;
	size_t	low;
}				t_stack;

typedef struct	s_info
{
	t_stack	a;
	t_stack	b;
}				t_info;

/*
** swap.c
*/



/*
** push.c
*/



/*
** rotate.c
*/



/*
** rrotate.c
*/


/*
** node.c
*/

size_t	ft_list_size(t_node *node);
void	ft_list_add_back(t_node **head, t_node *new_node);
void	ft_list_add_front(t_node **head, t_node *new_node);
t_node	*ft_node_last(t_node *node);
t_node	*ft_node_new(int num);

#endif