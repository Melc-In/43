/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:22:59 by cglandus          #+#    #+#             */
/*   Updated: 2022/10/07 02:15:16 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	void	*null;

	null = (void *)0;
	while (*s++)
		if (*s == c)
			return ((char *)s);
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	return (null);
}
