/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:53:20 by mmosheuv          #+#    #+#             */
/*   Updated: 2025/12/01 15:59:26 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printlong(size_t numb, const char *symbols)
{
	int				length;
	unsigned int	base;

	length = 0;
	base = ft_strlen(symbols);
	if (numb >= base)
		length += ft_printlong(numb / base, symbols);
	length++;
	write(1, &symbols[numb % base], 1);
	return (length);
}
