/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:02:10 by cglandus          #+#    #+#             */
/*   Updated: 2024/02/04 00:18:11 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_that_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash || ft_strlen(stash) == 0)
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	line = ft_calloc(i + 2, 1);
	while (i + 1)
	{
		line[i] = stash[i];
		i--;
	}
	return (line);
}

static char	*cutter(char *stash, char *save, int i)
{
	int	j;

	j = 0;
	while (stash[i])
	{
		save[j] = stash[i];
		i++;
		j++;
	}
	free(stash);
	return (save);
}

static char	*cut_stash(char *stash)
{
	char	*save;
	int		i;

	save = NULL;
	i = 0;
	if (*stash == '\0')
	{
		free(stash);
		return (NULL);
	}
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	if (i == 0)
		save = ft_calloc(1, 1);
	else if (stash[i])
		save = ft_calloc(ft_strlen(ft_strchr(stash, '\n')), 1);
	else
		save = ft_calloc(1, 1);
	save = cutter(stash, save, i);
	return (save);
}

static char	*get_line(char *stash, int fd)
{
	int		len;
	char	*line;

	line = ft_calloc(BUFFER_SIZE + 1, 1);
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
		line = ft_calloc(BUFFER_SIZE + 1, 1);
		len = read(fd, line, BUFFER_SIZE);
	}
	free(line);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_strchr(stash, '\n'))
		stash = get_line(stash, fd);
	line = get_that_line(stash);
	stash = cut_stash(stash);
	if ((line && ft_strlen(line) == 0) || !line)
	{
		free(stash);
		return (NULL);
	}
	if (!stash)
		return (NULL);
	return (line);
}

#include <stdio.h>
/*
int	main()
{
	int i;
	char	*line = NULL;

	i = 0;
	line = get_next_line(0);
	while (line && i < 1)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(0);
		i++;
	}
	if (line)
		free(line);
	return (0);
}*/
