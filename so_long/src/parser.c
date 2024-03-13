/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:39:58 by cglandus          #+#    #+#             */
/*   Updated: 2024/03/03 23:24:30 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	fd_checker(char *img_info)
{
	int	fd;

	fd = open(img_info, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

static int	img_check(void)
{
	if (!fd_checker("./src/img/walls.png"))
		return (0);
	if (!fd_checker("./src/img/exit.png"))
		return (0);
	if (!fd_checker("./src/img/collectibles.png"))
		return (0);
	if (!fd_checker("./src/img/player.png"))
		return (0);
	if (!fd_checker("./src/img/background.png"))
		return (0);
	return (1);
}

char	*parsing(int argc, char *arg, t_map *map)
{
	size_t	len;
	int		fd;

	if (argc < 2)
		return ("Missing map as argument !");
	len = ft_strlen(arg);
	if (len < 4)
		return ("Wrong argument format !");
	if (ft_strncmp(arg + len - 4, ".ber", 5))
		return ("Wrong file extension !");
	if (!img_check())
		return ("Missing Texture(s)");
	fd = open(arg, O_RDWR);
	if (fd < 0)
		return (strerror(errno));
	return (map_init(map, arg, fd));
}
