/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:32:34 by cglandus          #+#    #+#             */
/*   Updated: 2022/10/05 03:41:44 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_pos;
	int			cheap_trigger;

	cheap_trigger = 0;
	while (s++)
	{
		if (*s == c)
			last_pos = &s;
			cheap_trigger = 1;
	}
	if (*s == '\0' == c)
		return (s);
	if (cheap_trigger)
		return (last_pos);
	return (t_NULL);
}
