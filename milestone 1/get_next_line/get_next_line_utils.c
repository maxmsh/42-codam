/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:43:54 by mmosheuv          #+#    #+#             */
/*   Updated: 2025/12/12 20:33:34 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	result = malloc(i + j + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}

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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

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

int	ft_strlen(const char *s)
{
	int	c;

	c = 0;
	if (s[c] == 0)
		return (0);
	while (s && s[c] != '\0')
		c++;
	return (c);
}
