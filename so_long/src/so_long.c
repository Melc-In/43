/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 03:28:45 by cglandus          #+#    #+#             */
/*   Updated: 2024/03/03 21:59:23 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx	m;
	char	*parse_err;

	init_map(&m.map);
	parse_err = parsing(argc, argv[1], &m.map);
	if (parse_err)
	{
		free_map(m.map.grid);
		ft_printf("Error\n%s\n", parse_err);
	}
	else
	{
		init_display(&m);
		init_exit(&m);
		render_so_long(&m);
		destroy_all(&m);
	}
	if (parse_err)
		return (1);
	return (0);
}
