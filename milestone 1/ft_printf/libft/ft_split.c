/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:21:23 by mmosheuv          #+#    #+#             */
/*   Updated: 2025/11/03 22:27:12 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_array(char **arr, int j, int p)
{
	int	i;

	i = 0;
	while (i < j)
		free(arr[i++]);
	while (p >= 0)
		free(arr[p--]);
	free(arr);
}

static int	stramount(const char *s, char c)
{
	int	i;
	int	amt;

	i = 0;
	amt = 0;
	if (s[i] != c && s[i] != '\0')
		amt++;
	while (s[i] != '\0')
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
			amt++;
		i++;
	}
	return (amt);
}

static char	*copy_word(const char *s, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (0);
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static int	fill_array(char **result, char const *s, char c)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 0;
	index = -1;
	while (s[i])
	{
		if (s[i] != c && index < 0)
			index = i;
		if ((s[i] == c || s[i + 1] == '\0') && index >= 0)
		{
			result[j] = copy_word(s, index, i + (s[i] != c));
			if (!result[j])
			{
				free_array(result, j, i);
				return (0);
			}
			index = -1;
			j++;
		}
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (0);
	result = (char **)ft_calloc((stramount(s, c) + 1), sizeof(char *));
	if (!result)
		return (0);
	if (!fill_array(result, s, c))
		return (0);
	return (result);
}
