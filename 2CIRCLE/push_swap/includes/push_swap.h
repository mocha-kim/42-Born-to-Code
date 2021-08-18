/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 21:05:14 by sunhkim           #+#    #+#             */
/*   Updated: 2021/08/18 19:53:42 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

# define DO_NOT 0
# define SA 1
# define SB 2
# define RA 3
# define RB 4
# define RRA 5
# define RRB 6

typedef struct			s_node
{
	struct s_node		*prev;
	struct s_node		*next;
	int					num;
}						t_node;

typedef struct			s_stack
{
	t_node				*top;
	int					size;
}						t_stack;

typedef struct			s_info
{
	t_stack				a;
	t_stack				b;
}						t_info;

typedef struct			s_sort
{
	int					ra_num;
	int					rb_num;
	int					pa_num;
	int					pb_num;
}						t_sort;


/*
**		main.c
*/

void					init_info(t_info *info);
void					clear_info(t_info *info);

/*
** push_swap.c
*/

void					print_operation(int option);
void					push_swap(t_info *info);

/*
** swap.c
*/

void					swap_sx(t_stack *stack, int opt);
void					swap_ss(t_stack *a, t_stack *b);

/*
** push.c
*/

void					push_pa(t_stack *a, t_stack *b);
void					push_pb(t_stack *a, t_stack *b);

/*
** rotate.c
*/

void					rotate_rx(t_stack *stack, int opt);
void					rotate_rr(t_stack *a, t_stack *b);
void					r_rotate_rx(t_stack *stack, int opt);
void					r_rotate_rr(t_stack *a, t_stack *b);

/*
** solve_small.c
*/

void					solve_small(t_info *info);

/*
** solve.c
*/

void		print_debug(t_info *info);
int						solve(t_info *info);
void					sort_a(t_info *info, int size);
void					sort_b(t_info *info, int size);

/*
** stack.c
*/

int						check_sorted_stack(t_stack *stack, int dir, int size);
void					find_min(int *min, t_stack *stack, int size);
void					find_max(int *max, t_stack *stack, int size);
void					find_min_max(int *min, int *max, t_stack *stack, int size);

/*
** args.c
*/

int						check_save_args(int argc, char *argv[], t_info *info);

/*
** utils1.c
*/

size_t					ft_list_size(t_node *node);
void					ft_list_add_back(t_node **head, t_node *new_node);
void					ft_list_add_front(t_node **head, t_node *new_node);
t_node					*ft_node_last(t_node *node);
t_node					*ft_node_new(int num);

/*
** utils2.c
*/

void					ft_list_clear(t_node **head);
int						ft_isdigit(int c);
int						ft_isnum(char *str);
int						ft_atoi(const char *str);
size_t					ft_strlen(const char *s);

/*
** utils3.c
*/

size_t					ft_strlcpy(char *dst, const char *src, size_t dstsize);
char					**ft_split(char const *s, char c);

#endif