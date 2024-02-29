/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 01:50:44 by cglandus          #+#    #+#             */
/*   Updated: 2024/02/29 01:14:55 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char    *msize_init(t_map *map, int fd)
{
    char    *line;

    line = get_next_line(fd);
    if (!line)
        return ("Corruption (GNL FAIL)");
    map->len_x = ft_strlen(line) - 1;
    while (line)
    {
        map->len_y++;
        free(line);
        line = get_next_line(fd);
    }
    return (NULL);
}

static char    *map_builder(t_map *map, int fd)
{
    char    *line;
    size_t  i;
    int     err;

    i = 0;
    err = 0;
    map->grid = (char **)ft_calloc(map->len_y + 1, sizeof(char *));
    if (!map->grid)
        return ("ALLOCATION FAIL");
    line = get_next_line(fd);
    if (!line)
        return ("Corruption (GNL FAIL)");
    while (line)
    {
        if (i != map->len_y - 1)
        {
            if (map->len_x != ft_strlen(line) - 1)
                err = 1;
            if (ft_strlen(line) != 0)
                line[ft_strlen(line) - 1] = '\0';
            map->grid[i] = line;
            line = get_next_line(fd);
        }
        else
        {
            if (map->len_x != ft_strlen(line) && line[map->len_x] != '\0' 
                && line[map->len_x] != '\n')
                err = 1;
            map->grid[i] = line;
            line = get_next_line(fd);
        }
        i++;
    }
    if (err)
        return ("Map not rectangular");
    return (NULL);
}

char    *map_init(t_map *map, char *map_info, int fd)
{
    char    *err_mess;

    err_mess = msize_init(map, fd);
    if (err_mess)
        return (err_mess);
    close(fd);
    fd = open(map_info, O_RDWR);
    if (fd < 0)
        return (strerror(errno));
    err_mess = map_builder(map, fd);
    if (err_mess)
        return (err_mess);
    close(fd);
    err_mess = map_check(map);
    if (err_mess)
        return (err_mess);
    err_mess = map_solv(map);
    return (err_mess);  
}
