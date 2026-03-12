/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 22:57:05 by mmosheuv          #+#    #+#             */
/*   Updated: 2026/02/23 15:02:53 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_stack *stack)
{
	t_node	*current;
	int		min;
	int		min_pos;
	int		pos;

	current = stack->top;
	min = current->value;
	min_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

int	get_max_bits(t_stack *stack)
{
	int	max_index;
	int	bits;

	max_index = stack->size - 1;
	bits = 0;
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}
