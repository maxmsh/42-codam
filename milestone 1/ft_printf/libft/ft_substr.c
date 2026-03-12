/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:31:11 by mmosheuv          #+#    #+#             */
/*   Updated: 2025/10/29 18:26:40 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char			*str;
	int				i;
	unsigned int	strlen;

	strlen = 0;
	i = 0;
	while (s[strlen])
		strlen++;
	if (start >= strlen)
		return (ft_strdup(""));
	if (start + len > strlen)
		len = strlen - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s[start + i] != '\0' && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
