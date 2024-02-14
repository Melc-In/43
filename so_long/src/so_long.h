/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:51:02 by cglandus          #+#    #+#             */
/*   Updated: 2024/02/14 21:18:25 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../MacroLibX/includes/mlx.h"
#include "../libft/libft.h"
#include "fcntl.h"
#include "errno.h"
#include "string.h"

typedef struct s_map
{
    int     px;
    int     py;
    int     ex;
    int     ey;
    int     n_co;
	char    **grid;
	size_t	size_x;
    size_t	size_y;
}			t_map;

char    *parsing(int argc, char *str, t_map *map);
char    *map_check(t_map *map);
char    *map_init(t_map *map, char *map_info, int fd);
char    *map_builder(t_map *map, int fd);

#endif