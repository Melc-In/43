/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:02:10 by cglandus          #+#    #+#             */
/*   Updated: 2023/01/18 13:55:55 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*join(char *dest, char *src)
{
	char	*str;

	if (!dest)
		dest = malloc(1);
	str = ft_strjoin(dest, src);
	free(dest);
	return (str);
}

static char	*get_that_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	line = malloc(i + 1);
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
		return (NULL);
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
	int		swtch;

	line = calloc(BUFFER_SIZE + 1, 1);
	if (!line)
		return (NULL);
	swtch = 0;
	len = read(fd, line, BUFFER_SIZE);
	line[len] = '\0';
	stash = join(stash, line);
	while (len > 0)
	{
		if (ft_strchr(line, '\n'))
			break ;
		if (swtch == 1)
			stash = join(stash, line);
		ft_bzero(line, len);
		len = read(fd, line, BUFFER_SIZE);
		line[len] = '\0';
		swtch = 1;
	}
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
	return (line);
}
