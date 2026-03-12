/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 01:23:21 by mmosheuv          #+#    #+#             */
/*   Updated: 2026/02/19 07:20:48 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_operation
{
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}					t_operation;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

void				push(t_stack *dest, t_stack *src, t_operation op);
void				swap(t_stack *stack, t_operation op);
void				rotate(t_stack *stack, t_operation op);
void				reverse_rotate(t_stack *stack, t_operation op);
void				sort_stack(t_stack *a, t_stack *b);
void				sort_small(t_stack *a, t_stack *b);
void				sort_three(t_stack *a);
void				sort_four(t_stack *a, t_stack *b);
void				sort_five(t_stack *a, t_stack *b);
void				sort_radix(t_stack *a, t_stack *b);
void				assign_index(t_stack *stack);
void				init_stack(t_stack *stack);
void				free_stack(t_stack *stack);
int					get_position(t_stack *s, int value);
int					is_sorted(t_stack *stack);
t_node				*ft_lstnew(int value);
void				ft_lstadd_front(t_node **head, t_node *new_node);
t_node				*ft_lstlast(t_node *head);
int					validate_input(int argc, char **argv);
char				**parse_args(int argc, char **argv, int *new_argc);
void				free_args(char **args);
int					ft_isdigit(int c);
int					ft_isspace(int c);
int					ft_atoi(const char *str);
long				ft_atol(const char *str);
char				**ft_split(char *str);
int					find_min_pos(t_stack *stack);
int					get_max_bits(t_stack *stack);

#endif