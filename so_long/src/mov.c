/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:04:24 by cglandus          #+#    #+#             */
/*   Updated: 2024/03/03 22:58:09 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_player_r(t_mlx *m)
{
	if (m->map.player.x + 1 >= (int)m->map.len_x
		|| m->map.grid[m->map.player.y][m->map.player.x + 1] == '1')
		return (0);
	m->map.player.x += 1;
	if (m->map.grid[m->map.player.y][m->map.player.x] == 'C')
		m->map.grid[m->map.player.y][m->map.player.x] = '0';
	if (!(m->map.grid[m->map.player.y][m->map.player.x - 1] == 'E'))
		mlx_put_image_to_window(m->m, m->w, m->bg, (m->map.player.x - 1)
			* m->res.x, m->map.player.y * m->res.y);
	m->mov_count++;
	mlx_put_image_to_window(m->m, m->w, m->p, m->map.player.x * m->res.x,
		m->map.player.y * m->res.y);
	if (m->map.grid[m->map.player.y][m->map.player.x] == 'E')
	{
		if (!find_ellement(m->map, 'C'))
			mlx_loop_end(m->m);
	}
	return (1);
}

static int	move_player_l(t_mlx *m)
{
	if (m->map.player.x <= 0 || m->map.grid[m->map.player.y][m->map.player.x
		- 1] == '1')
		return (0);
	m->map.player.x -= 1;
	if (m->map.grid[m->map.player.y][m->map.player.x] == 'C')
		m->map.grid[m->map.player.y][m->map.player.x] = '0';
	if (!(m->map.grid[m->map.player.y][m->map.player.x + 1] == 'E'))
		mlx_put_image_to_window(m->m, m->w, m->bg, (m->map.player.x + 1)
			* m->res.x, m->map.player.y * m->res.y);
	m->mov_count++;
	mlx_put_image_to_window(m->m, m->w, m->p, m->map.player.x * m->res.x,
		m->map.player.y * m->res.y);
	if (m->map.grid[m->map.player.y][m->map.player.x] == 'E')
	{
		if (!find_ellement(m->map, 'C'))
			mlx_loop_end(m->m);
	}
	return (1);
}

static int	move_player_u(t_mlx *m)
{
	if (m->map.player.y <= 0 || m->map.grid[m->map.player.y
			- 1][m->map.player.x] == '1')
		return (0);
	m->map.player.y -= 1;
	if (m->map.grid[m->map.player.y][m->map.player.x] == 'C')
		m->map.grid[m->map.player.y][m->map.player.x] = '0';
	if (!(m->map.grid[m->map.player.y + 1][m->map.player.x] == 'E'))
		mlx_put_image_to_window(m->m, m->w, m->bg, m->map.player.x * m->res.x,
			(m->map.player.y + 1) * m->res.y);
	m->mov_count++;
	mlx_put_image_to_window(m->m, m->w, m->p, m->map.player.x * m->res.x,
		m->map.player.y * m->res.y);
	if (m->map.grid[m->map.player.y][m->map.player.x] == 'E')
	{
		if (!find_ellement(m->map, 'C'))
			mlx_loop_end(m->m);
	}
	return (1);
}

static int	move_player_d(t_mlx *m)
{
	if (m->map.player.y >= (int)m->map.len_y || m->map.grid[m->map.player.y
			+ 1][m->map.player.x] == '1')
		return (0);
	m->map.player.y += 1;
	if (m->map.grid[m->map.player.y][m->map.player.x] == 'C')
		m->map.grid[m->map.player.y][m->map.player.x] = '0';
	if (!(m->map.grid[m->map.player.y - 1][m->map.player.x] == 'E'))
		mlx_put_image_to_window(m->m, m->w, m->bg, m->map.player.x * m->res.x,
			(m->map.player.y - 1) * m->res.y);
	m->mov_count++;
	mlx_put_image_to_window(m->m, m->w, m->p, m->map.player.x * m->res.x,
		m->map.player.y * m->res.y);
	if (m->map.grid[m->map.player.y][m->map.player.x] == 'E')
	{
		if (!find_ellement(m->map, 'C'))
			mlx_loop_end(m->m);
	}
	return (1);
}

int	get_key(int key, void *mlx)
{
	t_mlx	*m;

	m = (t_mlx *)mlx;
	if (key == 41 || key == 20)
		mlx_loop_end(m->m);
	else if ((key == 79 || key == 7) && move_player_r(m))
		ft_printf("Movement Count : %d\n", m->mov_count);
	else if ((key == 80 || key == 4) && move_player_l(m))
		ft_printf("Movement Count : %d\n", m->mov_count);
	else if ((key == 81 || key == 22) && move_player_d(m))
		ft_printf("Movement Count : %d\n", m->mov_count);
	else if ((key == 82 || key == 26) && move_player_u(m))
		ft_printf("Movement Count : %d\n", m->mov_count);
	if (m->map.grid[m->map.player.y][m->map.player.x] != 'E')
	{
		mlx_put_image_to_window(m->m, m->w, m->bg, m->exit.x * m->res.x,
			m->exit.y * m->res.y);
		mlx_put_image_to_window(m->m, m->w, m->e, m->exit.x * m->res.x,
			m->exit.y * m->res.y);
	}
	return (0);
}
