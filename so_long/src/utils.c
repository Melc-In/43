/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:35:00 by cglandus          #+#    #+#             */
/*   Updated: 2024/02/22 22:36:37 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_map(t_map *map)
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

void    init_display(t_mlx  *m, t_map *map)
{
    m->m = mlx_init();
    m->res.x = 64;
    m->res.y = 64;
    m->w = mlx_new_window(m->m, map->len_x * m->res.x, map->len_y * m->res.y, "./so_long");
    m->wa = mlx_png_file_to_image(m->m, "./src/img/walls.png", &m->res.x, &m->res.y);
    m->e = mlx_png_file_to_image(m->m, "./src/img/exit.png", &m->res.x, &m->res.y);
    m->c = mlx_png_file_to_image(m->m, "./src/img/collectibles.png", &m->res.x, &m->res.y);
    m->p = mlx_png_file_to_image(m->m, "./src/img/player.png", &m->res.x, &m->res.y);
    m->bg = mlx_png_file_to_image(m->m, "./src/img/background.png", &m->res.x, &m->res.y);
}

void    destroy_all(t_mlx *m, t_map *map)
{
    if (!m->m || !map || !map->grid)
        return ;
    free_map(map->grid);
    mlx_destroy_image(m->m, m->wa);
    mlx_destroy_image(m->m, m->c);
    mlx_destroy_image(m->m, m->e);
    mlx_destroy_image(m->m, m->p);
    mlx_destroy_image(m->m, m->bg);
    mlx_destroy_window(m->m, m->w);
    mlx_destroy_display(m->m);
}