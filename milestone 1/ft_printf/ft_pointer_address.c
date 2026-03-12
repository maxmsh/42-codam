/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_address.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 04:18:01 by mmosheuv          #+#    #+#             */
/*   Updated: 2025/12/01 15:54:31 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Function returns the address of a pointer as a number, 
// which starts with '0x'.
// If no address was found, (nil) is written instead. 
// The written characters are stored in the "word_count" variable.

int	ft_pointer_address(size_t address)
{
	if (address == 0)
		return (write(1, "(nil)", 5));
	return (write(1, "0x", 2) + ft_printlong(address, HEX_LOWER));
}
