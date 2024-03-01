/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:04:24 by cglandus          #+#    #+#             */
/*   Updated: 2024/03/01 01:59:40 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void move_player_r(t_mlx *m)
{
    if (m->map.player.x + 1 >= (int)m->map.len_x 
        || m->map.grid[m->map.player.y][m->map.player.x + 1] == '1')
        return ;
    m->map.player.x += 1;
    if (m->map.grid[m->map.player.y][m->map.player.x] == 'C')
        m->map.grid[m->map.player.y][m->map.player.x] = '0';
    if (!(m->map.grid[m->map.player.y][m->map.player.x - 1] == 'E'))
        mlx_put_image_to_window(m->m, m->w, m->bg, (m->map.player.x - 1) * m->res.x, m->map.player.y * m->res.y);
    mlx_put_image_to_window(m->m, m->w, m->p, m->map.player.x * m->res.x, m->map.player.y * m->res.y);
    if (m->map.grid[m->map.player.y][m->map.player.x] == 'E')
    {
        if (!coll_in_map(m->map))
            mlx_loop_end(m->m);
    }
}

static void move_player_l(t_mlx *m)
{
    if (m->map.player.x <= 0 
        || m->map.grid[m->map.player.y][m->map.player.x - 1] == '1')
        return ;
    m->map.player.x -= 1;
    if (m->map.grid[m->map.player.y][m->map.player.x] == 'C')
        m->map.grid[m->map.player.y][m->map.player.x] = '0';
    if (!(m->map.grid[m->map.player.y][m->map.player.x + 1] == 'E'))
        mlx_put_image_to_window(m->m, m->w, m->bg, (m->map.player.x + 1) * m->res.x, m->map.player.y * m->res.y);
    mlx_put_image_to_window(m->m, m->w, m->p, m->map.player.x * m->res.x, m->map.player.y * m->res.y);
    if (m->map.grid[m->map.player.y][m->map.player.x] == 'E')
    {
        if (!coll_in_map(m->map))
            mlx_loop_end(m->m);
    }
}

static void move_player_u(t_mlx *m)
{
    if (m->map.player.y <= 0 
    || m->map.grid[m->map.player.y - 1][m->map.player.x] == '1')
        return ;
    m->map.player.y -= 1;
    if (m->map.grid[m->map.player.y][m->map.player.x] == 'C')
        m->map.grid[m->map.player.y][m->map.player.x] = '0';
    if (!(m->map.grid[m->map.player.y + 1][m->map.player.x] == 'E'))
        mlx_put_image_to_window(m->m, m->w, m->bg, m->map.player.x * m->res.x, (m->map.player.y + 1) * m->res.y);
    mlx_put_image_to_window(m->m, m->w, m->p, m->map.player.x * m->res.x, m->map.player.y * m->res.y);
    if (m->map.grid[m->map.player.y][m->map.player.x] == 'E')
    {
        if (!coll_in_map(m->map))
            mlx_loop_end(m->m);
    }
}

static void move_player_d(t_mlx *m)
{
    if (m->map.player.y >= (int)m->map.len_y
        || m->map.grid[m->map.player.y  + 1][m->map.player.x] == '1')
        return ;
    m->map.player.y += 1;
    if (m->map.grid[m->map.player.y][m->map.player.x] == 'C')
        m->map.grid[m->map.player.y][m->map.player.x] = '0';
    if (!(m->map.grid[m->map.player.y - 1][m->map.player.x] == 'E'))
        mlx_put_image_to_window(m->m, m->w, m->bg, m->map.player.x * m->res.x, (m->map.player.y - 1) * m->res.y);
    mlx_put_image_to_window(m->m, m->w, m->p, m->map.player.x * m->res.x, m->map.player.y * m->res.y);
    if (m->map.grid[m->map.player.y][m->map.player.x] == 'E')
    {
        if (!coll_in_map(m->map))
            mlx_loop_end(m->m);
    }
}

int get_key(int key, void *data)
{
    t_mlx *m;
    int i;
    int j;

    m = (t_mlx *) data;
    i = 0;
    while (m->map.grid[i])
    {
        j = 0;
        while (m->map.grid[i][j])
        {
            if (m->map.grid[i][j] == 'E')
                mlx_put_image_to_window(m->m, m->w, m->e, j * m->res.x, i * m->res.y);
            j++;
        }
        i++;
    }
    if(key == 41 || key == 20)
        mlx_loop_end(m->m);
    if (key == 79 || key == 7)
        move_player_r(m);
    if (key == 80 || key == 4)
        move_player_l(m);
    if (key == 81 || key == 22)
        move_player_d(m);
    if (key == 82 || key == 26)
        move_player_u(m);
    return (0);
}
