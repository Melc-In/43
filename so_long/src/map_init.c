/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 01:50:44 by cglandus          #+#    #+#             */
/*   Updated: 2024/02/19 01:42:09 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//tempfonction to test parsing
static void print_map(t_map *map)
{
    size_t i;

    i = 0;
    ft_printf("MAP :\n\n");
    if (!map)
        return ;
    while (i < map->len_y)
    {
        ft_printf("row (%d) : %s\n", (int)i, map->grid[i]);
        i++;
    }
}

static char    *msize_init(t_map *map, int fd)
{
    char    *line;
    int     err;

    err = 0;
    line = get_next_line(fd);
    if (!line)
        return ("Corruption (GNL FAIL)");
    map->len_x = ft_strlen(line) - 1;
    while (line)
    {
        if (map->len_x != ft_strlen(line) - 1)
            err = 1;
        map->len_y++;
        free(line);
        line = get_next_line(fd);
    }
    if (err)
        return ("Map not rectangular");
    return (NULL);
}

static char    *map_builder(t_map *map, int fd)
{
    char    *line;
    int     i;

    i = 0;
    map->grid = (char **)ft_calloc(map->len_y + 1, sizeof(char *));
    if (!map->grid)
        return ("ALLOCATION FAIL");
    line = get_next_line(fd);
    if (!line)
        return ("Corruption (GNL FAIL)");
    while (line)
    {
        if (ft_strlen(line) != 0)
            line[ft_strlen(line) - 1] = 0;
        map->grid[i] = line;
        line = get_next_line(fd);
        i++;
    }
    print_map(map);
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
