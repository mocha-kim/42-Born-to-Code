/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 21:05:14 by sunhkim           #+#    #+#             */
/*   Updated: 2021/08/20 15:47:08 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define DO_NOT 0
# define SA 1
# define SB 2
# define SS 3
# define RA 4
# define RB 5
# define RR 6
# define RRA 7
# define RRB 8
# define RRR 9
# define PA 10
# define PB 11

typedef struct 			s_list
{
	struct s_list		*next;
	char				*content;
}						t_list;

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
	t_list				*buf;
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

void					add_operation(t_list **buf, int option);
void					print_operation(t_list **buf);
void					push_swap(t_info *info);

/*
** swap.c
*/

void					swap_sx(t_list **buf, t_stack *stack, int opt);
void					swap_ss(t_list **buf, t_stack *a, t_stack *b);

/*
** push.c
*/

void					push_pa(t_list **buf, t_stack *a, t_stack *b);
void					push_pb(t_list **buf, t_stack *a, t_stack *b);

/*
** rotate.c
*/

void					rotate_rx(t_list **buf, t_stack *stack, int opt);
void					rotate_rr(t_list **buf, t_stack *a, t_stack *b);
void					r_rotate_rx(t_list **buf, t_stack *stack, int opt);
void					r_rotate_rr(t_list **buf, t_stack *a, t_stack *b);

/*
** solve_small.c
*/

void					solve_small(t_info *info);

/*
** solve.c
*/

int						find_pivots(t_stack *stack, int *p1, int *p2, int size);
void					init_sort_info(t_sort *sort);
int						solve(t_info *info);

/*
** sort_a.c
*/

void					sort_a(t_info *info, int size);

/*
** sort_b.c
*/

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
t_list					*ft_lstnew(char *content);
void					ft_lstadd_back(t_list **lst, t_list *new);
void					ft_lstclear(t_list **lst);

/*
** utils3.c
*/

size_t					ft_strlcpy(char *dst, const char *src, size_t dstsize);
char					**ft_split(char const *s, char c);

/*
** utils4.c
*/

char					*ft_strdup(const char *s1);
int						ft_isdigit(int c);
int						ft_isnum(char *str);
int						ft_atoi(const char *str);
size_t					ft_strlen(const char *s);

#endif