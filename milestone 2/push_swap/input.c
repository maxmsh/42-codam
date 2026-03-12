/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 00:13:59 by mmosheuv          #+#    #+#             */
/*   Updated: 2026/02/23 17:23:56 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+') || (str[i] == '-'))
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	has_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_input(int argc, char **argv)
{
	int		i;
	long	num;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (write(2, "Error\n", 6), 0);
		num = ft_atol(argv[i]);
		if ((num > INT_MAX) || (num < INT_MIN))
			return (write(2, "Error\n", 6), 0);
		i++;
	}
	if (has_duplicates(argc, argv))
		return (write(2, "Error\n", 6));
	return (1);
}

char	**parse_args(int argc, char **argv, int *new_argc)
{
	char	**result;
	char	**split;
	int		i;

	if (argc != 2)
		return (*new_argc = argc, argv);
	split = ft_split(argv[1]);
	if (!split)
		return (*new_argc = 0, NULL);
	i = 0;
	while (split[i])
		i++;
	*new_argc = i + 1;
	result = malloc(sizeof(char *) * (*new_argc + 1));
	if (!result)
		return (free(split), *new_argc = 0, NULL);
	result[0] = argv[0];
	i = -1;
	while (split[++i])
		result[i + 1] = split[i];
	result[i + 1] = NULL;
	return (free(split), result);
}

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 1;
	while (args[i])
		free(args[i++]);
	free(args);
}
