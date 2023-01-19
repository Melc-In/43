/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:02:10 by cglandus          #+#    #+#             */
/*   Updated: 2023/01/19 18:16:04 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_that_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	line = calloc(i + 1, 1);
	while (i + 1)
	{
		line[i] = str[i];
		i--;
	}
	return (line);
}

static char	*cut_stash(char *stash)
{
	char	*save;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (*stash == '\0')
	{
		free(stash);
		return (NULL);
	}
	save = ft_calloc(ft_strlen(ft_strchr(stash, '\n')), 1);
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	while (stash[i])
	{
		save[j] = stash[i];
		i++;
		j++;
	}
	free(stash);
	return (save);
}

static char	*get_line(char *stash, int fd)
{
	int		len;
	char	*line;

	line = calloc(BUFFER_SIZE + 1, 1);
	if (!line)
		return (NULL);
	len = read(fd, line, BUFFER_SIZE);
	if (len <= 0)
		stash = join(stash, line);
	while (len > 0)
	{
		stash = join(stash, line);
		if (ft_strchr(line, '\n'))
			break ;
		free(line);
		len = read(fd, line, BUFFER_SIZE);
	}
	free(line);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if ((fd < 0 || fd > 1023) || BUFFER_SIZE < 0)
		return (NULL);
	if (!ft_strchr(stash, '\n'))
		stash = get_line(stash, fd);
	if (ft_strlen(stash) == 0)
		return (NULL);
	line = get_that_line(stash);
	stash = cut_stash(stash);
	if (ft_strlen(stash) == 0)
		free(stash);
	return (line);
}
