/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 01:35:52 by cglandus          #+#    #+#             */
/*   Updated: 2024/03/04 20:56:46 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_walls(t_mlx *m, size_t i, size_t j)
{
	while (m->map.grid[i])
	{
		j = 0;
		while (m->map.grid[i][j])
		{
			if (m->map.grid[i][j] == '1')
				mlx_put_image_to_window(m->m, m->w, m->wa,
					j * m->res.x, i * m->res.y);
			else if (m->map.grid[i][j] == 'E')
				mlx_put_image_to_window(m->m, m->w, m->e,
					j * m->res.x, i * m->res.y);
			else if (m->map.grid[i][j] == 'C')
				mlx_put_image_to_window(m->m, m->w, m->c,
					j * m->res.x, i * m->res.y);
			else if (m->map.grid[i][j] == 'P')
				mlx_put_image_to_window(m->m, m->w, m->p,
					j * m->res.x, i * m->res.y);
			j++;
		}
		i++;
	}
}

static void	put_first_frame(t_mlx *m)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (m->map.grid[i])
	{
		j = 0;
		while (m->map.grid[i][j])
		{
			mlx_put_image_to_window(m->m, m->w, m->bg,
				j * m->res.x, i * m->res.y);
			j++;
		}
		i++;
	}
	put_walls(m, 0, 0);
}

static int	cross(int key, void	*window)
{
	if (key == 0)
		mlx_loop_end(window);
	return (0);
}

void	render_so_long(t_mlx *m)
{
	mlx_on_event(m->m, m->w, MLX_KEYDOWN, get_key, m);
	mlx_on_event(m->m, m->w, MLX_WINDOW_EVENT, cross, m->m);
	put_first_frame(m);
	mlx_loop(m->m);
}
