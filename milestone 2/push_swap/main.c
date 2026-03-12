/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 23:15:13 by mmosheuv          #+#    #+#             */
/*   Updated: 2026/02/19 03:53:46 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	**args;
	int		new_argc;
	int		i;

	args = parse_args(argc, argv, &new_argc);
	if (!validate_input(new_argc, args))
	{
		if (argc == 2 && args)
			free_args(args);
		return (1);
	}
	init_stack(&a);
	init_stack(&b);
	i = new_argc - 1;
	while (i >= 1)
		ft_lstadd_front(&a.top, ft_lstnew(ft_atoi(args[i--])));
	a.size = new_argc - 1;
	sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	if (argc == 2)
		free_args(args);
	return (0);
}
