/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 01:35:52 by cglandus          #+#    #+#             */
/*   Updated: 2024/02/21 23:56:06 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int cross(int event, void* param)
{
    if(event == 0)
        mlx_loop_end(param);
    return (0);
}

static int get_key(int key, void* mlx)
{
    ft_printf("KEY : %d\n", key);
    if(key == 41)
        mlx_loop_end(mlx);
    if (key == 79)
        //droite
    if (key == 80)
        //gauche
    if (key == 81)
        //bas
    if (key == 82)
        //haut
    if (key == 4)
        //gauche A
    if (key == 7)
        //droite D
    if (key == 22)
        //bas S
    if (key == 26)
        //haut W
    if(key == 41)
        mlx_loop_end(mlx);
    return (0);
}

void    render_so_long(t_map *map)
{
    map->len_x = 1; //silence warning
    void* mlx = mlx_init();
    void* win = mlx_new_window(mlx, 400, 400, "Hello world!");
    void    *img;

    img = mlx_new_image(mlx, 100, 100);
    mlx_set_image_pixel(mlx, img, 42, 10, 0xFFEB5C24);
    mlx_on_event(mlx, win, MLX_KEYDOWN, get_key, mlx);
    mlx_on_event(mlx, win, MLX_WINDOW_EVENT, cross, mlx);
    mlx_loop(mlx);

    mlx_destroy_image(mlx, img);
    mlx_destroy_window(mlx, win);
    mlx_destroy_display(mlx);
}