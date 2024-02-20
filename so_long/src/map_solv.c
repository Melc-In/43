/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 01:40:01 by cglandus          #+#    #+#             */
/*   Updated: 2024/02/20 23:51:15 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*test fct to see pathfinding state
static void pmap(char **map, size_t len)
{
    size_t i;

    i = 0;
    if (!map)
        return ;
    while (i < len && map[i])
    {
        ft_printf("%s\n", map[i]);
        i++;
    }
}*/

static void path_tester(char **map, int x, int y, int *coll_found, char c)
{
    if (map[x][y] == '1' || x == -1 || y == -1)
        return ;
    if (map[x][y] == c)
        (*coll_found)++;
    map[x][y] = '1';
    path_tester(map, x + 1, y, coll_found, c);
    path_tester(map, x - 1, y, coll_found, c);
    path_tester(map, x, y + 1, coll_found, c);
    path_tester(map, x, y - 1, coll_found, c);
}

static char **map_dup(t_map *map)
{
    char    **cpy;
    size_t  i;

    cpy = (char **)ft_calloc(map->len_y + 1, sizeof(char *));
    if (!cpy)
        return (NULL);
    i = 0;
    while (i < map->len_y)
    {
        cpy[i] = ft_strdup(map->grid[i]);
        i++;
    }
    return (cpy);
}

char    *map_solv(t_map *map)
{
    int     reachable_coll;
    char    **map_cpy;

    reachable_coll = 0;
    map_cpy = map_dup(map);
    if (!map_cpy)
        return("ALLOCATION FAIL");
    path_tester(map_cpy, map->player.x, map->player.y, &reachable_coll, 'C');
    free_map(map_cpy);
    if (reachable_coll != map->coll)
    {
        return ("Map is not solvable (One or more collectibles are not reachable)");
    }
    reachable_coll = 0;
    map_cpy = map_dup(map);
    if (!map_cpy)
        return("ALLOCATION FAIL");
    path_tester(map_cpy, map->player.x, map->player.y, &reachable_coll, 'E');
    free_map(map_cpy);
    if (reachable_coll != 1)
    {
        return ("Map is not solvable (Exit is not reachable)");
    }
    return (NULL);
}
