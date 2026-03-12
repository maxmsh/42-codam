/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:52:16 by mmosheuv          #+#    #+#             */
/*   Updated: 2025/10/31 19:38:13 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	product;
	void	*buf;

	product = (nmemb * size);
	if (product == 0)
		return (malloc(1));
	if (product / size != nmemb)
		return (NULL);
	buf = malloc(product);
	if (!buf)
		return (NULL);
	ft_bzero(buf, product);
	return (buf);
}
