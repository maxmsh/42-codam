/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 22:24:52 by mmosheuv          #+#    #+#             */
/*   Updated: 2026/02/23 14:48:13 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *dest, t_stack *src, t_operation op)
{
	t_node	*tmp;
	int		ret;

	if (!src || !src->top)
		return ;
	tmp = src->top;
	src->top = src->top->next;
	src->size--;
	tmp->next = dest->top;
	dest->top = tmp;
	dest->size++;
	if (op == PA)
		ret = write(1, "pa\n", 3);
	else if (op == PB)
		ret = write(1, "pb\n", 3);
	else
		return ;
	(void)ret;
}

void	rotate(t_stack *stack, t_operation op)
{
	t_node	*first;
	t_node	*last;
	int		ret;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	stack->top = stack->top->next;
	last = ft_lstlast(stack->top);
	last->next = first;
	first->next = NULL;
	if (op == RA)
		ret = write(1, "ra\n", 3);
	else if (op == RB)
		ret = write(1, "rb\n", 3);
	else if (op == RR)
		ret = write(1, "rr\n", 3);
	else
		return ;
	(void)ret;
}

void	reverse_rotate(t_stack *stack, t_operation op)
{
	t_node	*second_last;
	t_node	*last;
	int		ret;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	second_last = stack->top;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = stack->top;
	stack->top = last;
	if (op == RRA)
		ret = write(1, "rra\n", 4);
	else if (op == RRB)
		ret = write(1, "rrb\n", 4);
	else if (op == RRR)
		ret = write(1, "rrr\n", 4);
	else
		return ;
	(void)ret;
}

void	swap(t_stack *stack, t_operation op)
{
	int	tmp;
	int	ret;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	tmp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = tmp;
	if (op == SA)
		ret = write(1, "sa\n", 3);
	else if (op == SB)
		ret = write(1, "sb\n", 3);
	else if (op == SS)
		ret = write(1, "ss\n", 3);
	(void)ret;
}
