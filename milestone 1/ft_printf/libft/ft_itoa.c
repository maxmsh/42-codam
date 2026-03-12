/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:50:38 by mmosheuv          #+#    #+#             */
/*   Updated: 2025/10/23 19:04:59 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	repeat_itoa(char *s, int i, int numb)
{
	if (numb >= 10)
	{
		repeat_itoa(s, i - 1, numb / 10);
	}
	s[i] = (numb % 10) + '0';
}

static int	check_neg(int *n, int *dig_num)
{
	if (*n < 0)
	{
		*n *= -1;
		(*dig_num)++;
		return (-1);
	}
	else
		return (1);
}

static char	*exceptions(int n)
{
	char	*res;

	if (n == 0)
	{
		res = malloc(2);
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	if (n == -2147483648)
	{
		res = malloc(12);
		if (!res)
			return (0);
		res[0] = '-';
		res[1] = '2';
		repeat_itoa(res + 2, 8, 147483648);
		res[11] = '\0';
		return (res);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	int		i;
	int		sign;
	int		dig_num;
	char	*res;

	if (n == 0 || n == -2147483648)
		return (exceptions(n));
	sign = 1;
	dig_num = 0;
	sign = check_neg(&n, &dig_num);
	i = n;
	while (i > 0)
	{
		dig_num++;
		i /= 10;
	}
	i = 0;
	res = malloc((dig_num + 1) * sizeof(char));
	if (!res)
		return (0);
	repeat_itoa(res, dig_num - 1, n);
	res[dig_num] = '\0';
	if (sign < 0)
		res[0] = '-';
	return (res);
}
