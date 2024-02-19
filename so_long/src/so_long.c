/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 03:28:45 by cglandus          #+#    #+#             */
/*   Updated: 2024/02/19 01:41:26 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void    init_values(t_map *map)
{
    map->player.x = 0;
    map->player.y = 0;
    map->grid = NULL;
    map->len_x = 0;
    map->len_y = 0;
}

int main(int argc, char **argv)
{
    t_map   map;
    int     i;
    char    *parse_err;

    init_values(&map);
    parse_err = parsing(argc, argv[1], &map);
    if (parse_err)
        ft_printf("Error\n%s\n", parse_err);
    else
        render_so_long(&map);
    i = 0;
    if (map.grid)
    {
        while (map.grid[i])
        {
            free(map.grid[i]);
            i++;
        }
        free(map.grid);
    }
    if (parse_err)
        return (1);
    return (0);
}
