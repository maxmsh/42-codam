/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:05:50 by mmosheuv          #+#    #+#             */
/*   Updated: 2025/10/22 18:58:15 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	size_t	len;
	char	*dst;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	dst = (char *)malloc(sizeof(*str) * (len + 1));
	if (dst == 0)
		return (NULL);
	else
	{
		while (i < len)
		{
			dst[i] = str[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (dst);
}
