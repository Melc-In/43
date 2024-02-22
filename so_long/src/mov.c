/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:04:24 by cglandus          #+#    #+#             */
/*   Updated: 2024/02/22 22:37:54 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void move_player_r(t_mlx *m, t_map *map)
{
    int pp;
    int np;

    pp = map->player.x;
    np = map->player.x + 1;
    if (map->player.x >= map->len_x)
        return ;
    if (map->grid[np][map->player.y] == '1')
        return ;
    if (map->grid[np][map->player.y] == 'E')
    {
        mlx_put_image_to_window(m->m, m->w, m->bg, pp * m->res.x, map->player.y * m->res.y);
        mlx_put_image_to_window(m->m, m->w, m->p, np * m->res.x, map->player.y * m->res.y);
        return;
    }
    map->grid[pp][map->player.y] = '0';
    map->grid[np][map->player.y] = 'P';
    map->player.x = np;
}

static void move_player_l(t_mlx m, t_map map)
{
    int pp;
    int np;

    pp = map->player.x;
    np = map->player.x - 1;
    if (map->player.x <= 0)
        return ;
    if (map->grid[np][map->player.y] == '1')
        return ;
    if (map->grid[np][map->player.y] == 'E')
    {
        mlx_put_image_to_window(m->m, m->w, m->bg, pp * m->res.x, map->player.y * m->res.y);
        mlx_put_image_to_window(m->m, m->w, m->p, np * m->res.x, map->player.y * m->res.y);
        return;
    }
    map->grid[pp][map->player.y] = '0';
    map->grid[np][map->player.y] = 'P';
    map->player.x = np;
}

static void move_player_u(t_mlx m, t_map map)
{
    int pp;
    int np;

    pp = map->player.y;
    np = map->player.y - 1;
    if (map->player.y <= 0)
        return ;
    if (map->grid[map->player.x][np] == '1')
        return ;
    if (map->grid[map->player.x][np] == 'E')
    {
        mlx_put_image_to_window(m->m, m->w, m->bg, map->player.x * m->res.x, pp * m->res.y);
        mlx_put_image_to_window(m->m, m->w, m->p, map->player.x * m->res.x, np * m->res.y);
        return;
    }
    map->grid[map->player.x][pp] = '0';
    map->grid[map->player.x][np] = 'P';
    map->player.y = np;
}

static void move_player_d(t_mlx m, t_map map)
{
    int pp;
    int np;

    pp = map->player.y;
    np = map->player.y + 1;
    if (map->player.y >= map->len_y)
        return ;
    if (map->grid[map->player.x][np] == '1')
        return ;
    if (map->grid[map->player.x][np] == 'E')
    {
        mlx_put_image_to_window(m->m, m->w, m->bg, map->player.x * m->res.x, pp * m->res.y);
        mlx_put_image_to_window(m->m, m->w, m->p, map->player.x * m->res.x, np * m->res.y);
        return;
    }
    map->grid[map->player.x][pp] = '0';
    map->grid[map->player.x][np] = 'P';
    map->player.y = np;
}

int get_key(int key, t_mlx m, t_map *map)
{
    ft_printf("KEY : %d\n", key);
    if(key == 41 || key == 20)
        mlx_loop_end(m, map);
    if (key == 79)
        move_player_r(m, map)
    if (key == 80)
        move_player_l(m, map)
    if (key == 81)
        move_player_d(m, map)
    if (key == 82)
        move_player_u(m, map)
    if (key == 4)
        move_player_r(m, map)
    if (key == 7)
        move_player_l(m, map)
    if (key == 22)
        move_player_d(mlx, map)
    if (key == 26)
        move_player_u(mlp)
    if(key == 41)
        mlx_loop_end(mlx);
    return
}
