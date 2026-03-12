/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:06:36 by mmosheuv          #+#    #+#             */
/*   Updated: 2025/12/01 15:13:58 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// This function prints an integer and updates the amount
// of printed characters in the variable print_size.

int	ft_printdigit(int n)
{
	char	*str;
	int		value;

	ft_putnbr_fd(n, 1);
	str = ft_itoa(n);
	if (!str)
		return (-1);
	value = ft_strlen(str);
	free(str);
	return (value);
}
