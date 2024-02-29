/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 01:35:52 by cglandus          #+#    #+#             */
/*   Updated: 2024/02/29 01:14:57 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int cross(int event, void* param)
{
    if(event == 0)
        mlx_loop_end(param);
    return (0);
}

static void    put_walls(t_mlx *m, size_t i, size_t j)
{
    while (m->map->grid[i])
    {
        j = 0;
        while (m->map->grid[i][j])
        {
            if (m->map->grid[i][j] == '1')
                mlx_put_image_to_window(m->m, m->w, m->wa, j * m->res.x, i * m->res.y);
            else if (m->map->grid[i][j] == 'E')
                mlx_put_image_to_window(m->m, m->w, m->e, j * m->res.x, i * m->res.y);
            else if (m->map->grid[i][j] == 'C')
                mlx_put_image_to_window(m->m, m->w, m->c, j * m->res.x, i * m->res.y);
            else if (m->map->grid[i][j] == 'P')
                mlx_put_image_to_window(m->m, m->w, m->p, j * m->res.x, i * m->res.y);
            j++;
        }
        i++;
    }
}

static void    put_first_frame(t_mlx *m)
{
    size_t  i;
    size_t  j;

    i = 0;
    j = 0;
    while (m->map->grid[i])
    {
        j = 0;
        while (m->map->grid[i][j])
        {
            mlx_put_image_to_window(m->m, m->w, m->bg, j * m->res.x, i * m->res.y);
            j++;
        }
        i++;
    }
    put_walls(m, 0, 0);
}

void    render_so_long(t_mlx *m)
{
    mlx_on_event(m->m, m->w, MLX_KEYDOWN, get_key, m->m);
    mlx_on_event(m->m, m->w, MLX_WINDOW_EVENT, cross, m->m);
    put_first_frame(m, m->map);
    mlx_put_image_to_window(m->m, m->bg, m->wa, 0, 0);
    mlx_loop(m->m);
}
