/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:39:58 by cglandus          #+#    #+#             */
/*   Updated: 2024/02/20 23:54:32 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	fd = open(arg, O_RDWR);
	if (fd < 0)
		return (strerror(errno));
	return (map_init(map, arg, fd));
}
