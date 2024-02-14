/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 01:50:44 by cglandus          #+#    #+#             */
/*   Updated: 2024/02/14 03:18:41 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//tempfonction to test parsing
static void print_map(char **map)
{
    int i;

    i = 0;
    ft_printf("MAP :\n\n");
    if (!map)
        return ;
    while (i < (int)ft_strlen(map[i]))
    {
        ft_printf("row (%d) : %s\n", i, map[i]);
        i++;
    }
}

char	*map_check(t_map *map)
{
    map->n_co = 1;
    return ("BOOM CHECK");
}

char    *msize_init(t_map *map, int fd)
{
    size_t  sx;
    size_t  sy;
    char    *line;

    line = get_next_line(fd);
    if (!line)
        return ;
    sy = ft_strlen(get_next_line);
    return ("BOOM SIZE");
}

char    *map_builder(t_map *map, int fd)
{
    char *line;
	//int	nb_co;
	//int	nb_pl;
	//int	nb_ex;
    int i;

    i = 0;
    line = get_next_line(fd);
	while (line)
    {
        map->grid[i] = line;
        free(line);
        line = get_next_line(fd);
        i++;
    }
    print_map(map->grid);
    return ("BOOM BUILD")
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
    return (err_mess);  
}
