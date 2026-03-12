/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:47:45 by mmosheuv          #+#    #+#             */
/*   Updated: 2025/10/22 17:14:53 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdest;

	csrc = ((unsigned char *)src);
	cdest = ((unsigned char *)dest);
	if (!src && !dest)
		return (NULL);
	if (dest > src)
	{
		while (n--)
			cdest[n] = csrc[n];
		return (cdest);
	}
	else
		return (ft_memcpy(dest, src, n));
}
