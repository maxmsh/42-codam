/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:44:46 by mmosheuv          #+#    #+#             */
/*   Updated: 2025/12/12 16:57:42 by mmosheuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// int main(void)
// {
//     int    fd;
//     char    *rslt;

//     fd = open("test.txt", O_RDONLY);
//     rslt = get_next_line(fd);
//     printf("line -> %s\n", rslt);
//     free(rslt);
//     close(fd);
// 	return (0);
// }

int	main(void)
{
	int fd;
	char *putito;
	size_t c = 0;

	fd = open("test.txt", O_RDONLY);
	putito = get_next_line(fd);
	while (putito)
	{
		printf("line %zu -> %s\n", c, putito);
		free(putito);
		putito = get_next_line(fd);
		c++;
	}
	close(fd);
}