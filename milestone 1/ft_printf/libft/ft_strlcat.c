/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:43:31 by mmosheuv          #+#    #+#             */
/*   Updated: 2025/10/29 19:00:15 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;

	i = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (size < dstlen)
		return (srclen + size);
	else
	{
		while (src[i] && dstlen + 1 < size)
		{
			dst[dstlen + i] = src[i];
			i++;
			size--;
		}
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
