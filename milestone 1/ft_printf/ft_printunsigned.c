/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 05:39:20 by mmosheuv          #+#    #+#             */
/*   Updated: 2025/11/28 21:14:14 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// This function recursively prints an unsigned
// value to the standard output. 

int	ft_printunsigned(unsigned int num)
{
	int	len;

	len = 0;
	if (num / 10 > 0)
		len += ft_printunsigned(num / 10);
	ft_putchar_fd((num % 10) + '0', 1);
	len++;
	return (len);
}
