/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 03:28:45 by cglandus          #+#    #+#             */
/*   Updated: 2024/02/14 21:18:26 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_map   map;
    char    *parse_err;

    parse_err = parsing(argc, argv[1], &map);
    if (parse_err)
    {
        ft_printf("Error\n%s\n", parse_err);
        return (1);
    }
    //render(&map);
    return (0);
}
