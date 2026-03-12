/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 00:25:48 by mmosheuv          #+#    #+#             */
/*   Updated: 2026/02/23 17:21:27 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *str)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (!ft_isspace(*str) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (ft_isspace(*str))
			in_word = 0;
		str++;
	}
	return (count);
}

static char	*copy_word(char *str, int len)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

int	word_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] && !ft_isspace(str[len]))
		len++;
	return (len);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		(write(2, "Error\n", 6));
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(char *str)
{
	char	**result;
	int		words;
	int		i;
	int		len;

	words = count_words(str);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if (*str)
		{
			len = word_len(str);
			result[i++] = copy_word(str, len);
			str += len;
		}
	}
	result[i] = NULL;
	return (result);
}
