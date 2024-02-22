/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:51:02 by cglandus          #+#    #+#             */
/*   Updated: 2024/02/22 22:36:39 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../MacroLibX/includes/mlx.h"
#include "../libft/libft.h"
#include "fcntl.h"
#include "errno.h"
#include "string.h"

typedef struct s_coo
{
    int x;
    int y;
}   t_coo;

typedef struct s_map
{
    int     coll;
	char    **grid;
	size_t	len_x;
    size_t	len_y;
    t_coo     player;
}   t_map;

typedef struct s_mlx
{
    void    *m;
    void    *w;
    void    *bg;
    void    *wa;
    void    *e;
    void    *c;
    void    *p;
    t_coo   res;
}   t_mlx;   

char    *parsing(int argc, char *str, t_map *map);
void    render_so_long(t_mlx *m, t_map *map);

char    *map_init(t_map *map, char *map_info, int fd);
char	*map_check(t_map *map);
char    *map_solv(t_map *map);

void    init_map(t_map *map);
void    free_map(char **map);
void    init_display(t_mlx  *m, t_map *map);
void    destroy_all(t_mlx *m, t_map *map);

int get_key(int key, void* mlx);

#endif