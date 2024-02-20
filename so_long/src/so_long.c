/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 03:28:45 by cglandus          #+#    #+#             */
/*   Updated: 2024/02/20 23:55:31 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_map   map;
    char    *parse_err;

    init_values(&map);
    parse_err = parsing(argc, argv[1], &map);
    if (parse_err)
        ft_printf("Error\n%s\n", parse_err);
    else
        render_so_long(&map);
    free_map(map.grid);
    if (parse_err)
        return (1);
    return (0);
}
