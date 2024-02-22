/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 03:28:45 by cglandus          #+#    #+#             */
/*   Updated: 2024/02/22 22:36:38 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_map   map;
    t_mlx   m;
    char    *parse_err;

    init_map(&map);
    parse_err = parsing(argc, argv[1], &map);
    if (parse_err)
    {
        free_map(map.grid);
        ft_printf("Error\n%s\n", parse_err);
    }
    else
    {
        init_display(&m, &map);
        render_so_long(&m, &map);
        destroy_all(&m, &map);
    }
    if (parse_err)
        return (1);
    return (0);
}
