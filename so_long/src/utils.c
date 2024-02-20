/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:35:00 by cglandus          #+#    #+#             */
/*   Updated: 2024/02/20 18:40:25 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_values(t_map *map)
{
    map->player.x = 0;
    map->player.y = 0;
    map->grid = NULL;
    map->len_x = 0;
    map->len_y = 0;
}

void free_map(char **map)
{
    int i;

    i = 0;
    if (map)
    {
        while (map[i])
        {
            free(map[i]);
            i++;
        }
        free(map);
    }
}