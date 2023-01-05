/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:02:10 by cglandus          #+#    #+#             */
/*   Updated: 2023/01/05 19:57:38 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(static char *stash, int fd)
{
	int		len;
	char 	*line;

	save = calloc(BUFFER_SIZE + 1);
	if (!save)
		return (NULL);
	len = read(fd, line, BUFFER_SIZE);
	while (len > 0)
	{
		if (ft_strchr(len, '\n'))

		len = read(fd, line, BUFFER_SIZE);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char *stash;


	if ((fd < 0 || fd > 1023) || BUFFER_SIZE < 0)
		return (NULL);
}
