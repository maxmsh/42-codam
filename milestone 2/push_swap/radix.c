/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 03:56:15 by mmosheuv          #+#    #+#             */
/*   Updated: 2026/02/19 04:43:29 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = stack->top;
	while (current)
	{
		index = 0;
		compare = stack->top;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	sort_radix(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	bit;
	int	i;
	int	size;

	assign_index(a);
	max_bits = get_max_bits(a);
	bit = 0;
	while (bit < max_bits)
	{
		size = a->size;
		i = 0;
		while (i < size)
		{
			if (((a->top->index >> bit) & 1) == 0)
				push(b, a, PB);
			else
				rotate(a, RA);
			i++;
		}
		while (b->size > 0)
			push(a, b, PA);
		bit++;
	}
}
