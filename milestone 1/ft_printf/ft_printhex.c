/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:46:22 by mmosheuv          #+#    #+#             */
/*   Updated: 2025/12/01 14:48:10 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// This function prints a hexidecimal value by making use of recursion.
// Its length is saved and returned. 

int	ft_printhex(unsigned int numb, const char *symbols)
{
	int				length;
	unsigned int	base;

	length = 0;
	base = ft_strlen(symbols);
	if (numb >= base)
		length += ft_printhex(numb / base, symbols);
	length++;
	write(1, &symbols[numb % base], 1);
	return (length);
}
