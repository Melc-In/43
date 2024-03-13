/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:47:14 by cglandus          #+#    #+#             */
/*   Updated: 2024/03/03 22:57:26 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*check_walls(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->grid[0][i])
	{
		if (map->grid[0][i] != '1')
			return ("Missing a wall(s) topside of the map");
		else if (map->grid[map->len_y - 1][i] != '1')
			return ("Missing a wall(s) botside of the map");
		i++;
	}
	i = 1;
	if (map->len_y <= 0)
		return ("Invalid map (single line)");
	while (map->grid[i])
	{
		if (map->grid[i][0] != '1')
			return ("Missing wall(s) on left side");
		else if (map->grid[i][map->len_x - 1] != '1')
			return ("Missing wall(s) on right side");
		i++;
	}
	return (NULL);
}

static char	*player_check(t_map *map)
{
	size_t	i;
	size_t	j;
	int		nb_el;

	i = 0;
	nb_el = 0;
	while (i < map->len_y)
	{
		j = 0;
		while (j++ < map->len_x)
		{
			if (map->grid[i][j] == 'P')
			{
				map->player.x = j;
				map->player.y = i;
				nb_el++;
			}
		}
		i++;
	}
	if (nb_el > 1)
		return ("Too many players");
	else if (nb_el < 1)
		return ("Missing player");
	return (NULL);
}

static char	*exit_check(t_map *map)
{
	size_t	i;
	size_t	j;
	int		nb_el;

	i = 0;
	nb_el = 0;
	while (i < map->len_y)
	{
		j = 0;
		while (j < map->len_x)
		{
			if (map->grid[i][j] == 'E')
				nb_el++;
			if (map->grid[i][j] != '1' && map->grid[i][j] != '0'
				&& map->grid[i][j] != 'C' && map->grid[i][j] != 'E'
				&& map->grid[i][j] != 'P')
				return ("Found unexpected elements in map");
			j++;
		}
		i++;
	}
	if (nb_el > 1 || nb_el < 1)
		return ("Missing or too many exits");
	return (NULL);
}

static char	*collectibles_check(t_map *map)
{
	size_t	i;
	size_t	j;
	int		nb_el;

	i = 0;
	nb_el = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == 'C')
				nb_el++;
			j++;
		}
		i++;
	}
	map->coll = nb_el;
	if (nb_el >= 1)
		return (NULL);
	return ("Missing collectible(s)");
}

char	*map_check(t_map *map)
{
	char	*err_mess;

	err_mess = check_walls(map);
	if (err_mess)
		return (err_mess);
	err_mess = collectibles_check(map);
	if (err_mess)
		return (err_mess);
	err_mess = player_check(map);
	if (err_mess)
		return (err_mess);
	err_mess = exit_check(map);
	return (err_mess);
}
