/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:04:24 by cglandus          #+#    #+#             */
/*   Updated: 2024/02/29 01:15:02 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void move_player_r(t_mlx *m)
{
    int pp;
    int np;

    pp = m->map->player->x;
    np = m->map->player->x + 1;
    if (m->map->player->x >= (int)m->map->len_x)
        return ;
    if (m->map->grid[np][m->map->player->y] == '1')
        return ;
    if (m->map->grid[np][m->map->player->y] == 'E')
    {
        mlx_put_image_to_window(m->m, m->w, m->bg, pp * m->res.x, m->map->player->y * m->res.y);
        mlx_put_image_to_window(m->m, m->w, m->p, np * m->res.x, m->map->player->y * m->res.y);
        return;
    }
    m->map->grid[pp][m->map->player->y] = '0';
    m->map->grid[np][m->map->player->y] = 'P';
    m->map->player->x = np;
}

static void move_player_l(t_mlx *m)
{
    int pp;
    int np;

    pp = m->map->player->x;
    np = m->map->player->x - 1;
    if (m->map->player->x <= 0)
        return ;
    if (m->map->grid[np][m->map->player->y] == '1')
        return ;
    if (m->map->grid[np][m->map->player->y] == 'E')
    {
        mlx_put_image_to_window(m->m, m->w, m->bg, pp * m->res.x, m->map->player->y * m->res.y);
        mlx_put_image_to_window(m->m, m->w, m->p, np * m->res.x, m->map->player->y * m->res.y);
        return;
    }
    m->map->grid[pp][m->map->player->y] = '0';
    m->map->grid[np][m->map->player->y] = 'P';
    m->map->player->x = np;
}

static void move_player_u(t_mlx *m)
{
    int pp;
    int np;

    pp = m->map->player->y;
    np = m->map->player->y - 1;
    if (m->map->player->y <= 0)
        return ;
    if (m->map->grid[m->map->player->x][np] == '1')
        return ;
    if (m->map->grid[m->map->player->x][np] == 'E')
    {
        mlx_put_image_to_window(m->m, m->w, m->bg, m->map->player->x * m->res.x, pp * m->res.y);
        mlx_put_image_to_window(m->m, m->w, m->p, m->map->player->x * m->res.x, np * m->res.y);
        return;
    }
    m->map->grid[map->player->x][pp] = '0';
    m->map->grid[map->player->x][np] = 'P';
    m->map->player->y = np;
}

static void move_player_d(t_mlx *m)
{
    int pp;
    int np;

    pp = m->map->player->y;
    np = m->map->player->y + 1;
    if (m->map->player->y >= (int)m->map->len_y)
        return ;
    if (m->map->grid[m->map->player->x][np] == '1')
        return ;
    if (m->map->grid[m->map->player->x][np] == 'E')
    {
        mlx_put_image_to_window(m->m, m->w, m->bg, m->map->player->x * m->res.x, pp * m->res.y);
        mlx_put_image_to_window(m->m, m->w, m->p, m->map->player->x * m->res.x, np * m->res.y);
        return;
    }
    m->map->grid[m->map->player->x][pp] = '0';
    m->map->grid[m->map->player->x][np] = 'P';
    m->map->player->y = np;
}

int get_key(int key, t_mlx *m)
{
    ft_printf("KEY : %d\n", key);
    if(key == 41 || key == 20)
        mlx_loop_end(m->m);
    if (key == 79)
        move_player_r(m);
    if (key == 80)
        move_player_l(m);
    if (key == 81)
        move_player_d(m);
    if (key == 82)
        move_player_u(m);
    if (key == 4)
        move_player_r(m);
    if (key == 7)
        move_player_l(m);
    if (key == 22)
        move_player_d(m);
    if (key == 26)
        move_player_u(m);
    if(key == 41)
        mlx_loop_end(m->m);
    return (0);
}
