/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:05:57 by mmosheuv          #+#    #+#             */
/*   Updated: 2025/12/12 20:52:15 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Reads line from file and stores characters untill it find a \n */
static char	*read_and_store(int fd, char *stash)
{
	int		readbyte;
	char	*buff;
	char	*nl_pos;
	char	*temp;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	nl_pos = ft_strchr(stash, '\n');
	while (!nl_pos)
	{
		readbyte = read(fd, buff, BUFFER_SIZE);
		if (readbyte < 0)
			return (free(stash), free(buff), NULL);
		if (readbyte == 0)
			break ;
		buff[readbyte] = '\0';
		temp = stash;
		stash = ft_strjoin(stash, buff);
		free(temp);
		nl_pos = ft_strchr(stash, '\n');
	}
	return (free(buff), stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*nl_pos;
	char		*temp;
	char		*line;
	int			len;

	stash = read_and_store(fd, stash);
	if (!stash)
		return (NULL);
	if (stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	nl_pos = ft_strchr(stash, '\n');
	if (nl_pos)
		len = (nl_pos - stash) + 1;
	else
		len = ft_strlen(stash);
	line = ft_substr(stash, 0, len);
	temp = stash;
	stash = ft_substr(stash, len, ft_strlen(stash) - len);
	free(temp);
	return (line);
}
