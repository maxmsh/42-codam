/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:18:18 by mmosheuv          #+#    #+#             */
/*   Updated: 2025/10/22 17:15:21 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string_one;
	unsigned char	*string_two;
	size_t			i;

	i = 0;
	string_one = (unsigned char *)s1;
	string_two = (unsigned char *)s2;
	while (i < n)
	{
		if (string_one[i] > string_two[i])
			return (1);
		else if (string_one[i] < string_two[i])
			return (-1);
		i++;
	}
	return (0);
}
