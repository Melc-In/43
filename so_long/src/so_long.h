/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:51:02 by cglandus          #+#    #+#             */
/*   Updated: 2024/03/02 23:24:32 by cglandus         ###   ########.fr       */
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
	int	x;
	int	y;
}	t_coo;

typedef struct s_map
{
	char	**grid;
	t_coo	player;
	size_t	len_x;
	size_t	len_y;
	int		coll;
}	t_map;

typedef struct s_mlx
{
	t_map	map;
	t_coo	res;
	t_coo	exit;
	void	*m;
	void	*w;
	void	*bg;
	void	*wa;
	void	*e;
	void	*c;
	void	*p;
	int		mov_count;
}	t_mlx;

char	*parsing(int argc, char *str, t_map *map);
void	render_so_long(t_mlx *m);

char	*map_init(t_map *map, char *map_info, int fd);
char	*map_check(t_map *map);
char	*map_solv(t_map *map);

void	init_map(t_map *map);
void	free_map(char **map);
void	init_display(t_mlx  *m);
void	init_exit(t_mlx *m);
int		find_ellement(t_map map, char el);
void	destroy_all(t_mlx *m);

int		get_key(int key, void *mlx);

#endif
