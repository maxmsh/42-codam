/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 23:28:24 by mmosheuv          #+#    #+#             */
/*   Updated: 2026/02/23 15:03:22 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_stack(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->size <= 5)
		sort_small(a, b);
	else if (a->size > 5)
		sort_radix(a, b);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		swap(a, SA);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if ((first > second) && (second < third) && (first < third))
		swap(a, SA);
	else if ((first > second) && (second < third) && (first > third))
		rotate(a, RA);
	else if ((first < second) && (second > third) && (first > third))
		reverse_rotate(a, RRA);
	else if ((first > second) && (second > third))
	{
		swap(a, SA);
		reverse_rotate(a, RRA);
	}
	else if ((first < second) && (second > third) && (first < third))
	{
		swap(a, SA);
		rotate(a, RA);
	}
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	min_pos;

	if (is_sorted(a))
		return ;
	assign_index(a);
	min_pos = find_min_pos(a);
	if (min_pos == 1)
		rotate(a, RA);
	else if (min_pos == 2)
	{
		rotate(a, RA);
		rotate(a, RA);
	}
	else if (min_pos == 3)
		reverse_rotate(a, RRA);
	push(b, a, PB);
	sort_three(a);
	push(a, b, PA);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min_pos;

	if (is_sorted(a))
		return ;
	assign_index(a);
	min_pos = find_min_pos(a);
	while (min_pos == 1 || min_pos == 2)
	{
		rotate(a, RA);
		min_pos--;
	}
	while (min_pos == 3 || min_pos == 4)
	{
		reverse_rotate(a, RRA);
		min_pos++;
	}
	push(b, a, PB);
	sort_four(a, b);
	push(a, b, PA);
}
