/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 01:40:01 by cglandus          #+#    #+#             */
/*   Updated: 2024/03/03 23:32:28 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	path_floodc(char **map, int x, int y, int *coll_found)
{
	if (map[y][x] == '1' || x == -1 || y == -1)
		return ;
	if (map[y][x] == 'C')
		(*coll_found)++;
	map[y][x] = '1';
	path_floodc(map, x + 1, y, coll_found);
	path_floodc(map, x - 1, y, coll_found);
	path_floodc(map, x, y + 1, coll_found);
	path_floodc(map, x, y - 1, coll_found);
}

static void	path_floode(char **map, int x, int y, int *coll_found)
{
	if (map[y][x] == '1' || x == -1 || y == -1)
		return ;
	if (map[y][x] == 'E')
		(*coll_found)++;
	map[y][x] = '1';
	path_floode(map, x + 1, y, coll_found);
	path_floode(map, x - 1, y, coll_found);
	path_floode(map, x, y + 1, coll_found);
	path_floode(map, x, y - 1, coll_found);
}

static char	**map_dup(t_map *map)
{
	char	**cpy;
	size_t	i;

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

char	*map_solv(t_map *map)
{
	int		reachable_elements;
	char	**map_cpy;

	reachable_elements = 0;
	map_cpy = map_dup(map);
	if (!map_cpy)
		return ("ALLOCATION FAIL");
	path_floodc(map_cpy, map->player.x, map->player.y, &reachable_elements);
	free_map(map_cpy);
	if (reachable_elements != map->coll)
		return ("Map not solvable (One/more collectibles are not reachable)");
	reachable_elements = 0;
	map_cpy = map_dup(map);
	if (!map_cpy)
		return ("ALLOCATION FAIL");
	path_floode(map_cpy, map->player.x, map->player.y, &reachable_elements);
	free_map(map_cpy);
	if (reachable_elements != 1)
		return ("Map is not solvable (Exit is not reachable)");
	return (NULL);
}
