/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:14:25 by cglandus          #+#    #+#             */
/*   Updated: 2022/10/12 17:55:21 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, t_size n)
{
	char		*s2;
	t_size		i;

	s2 = (char *)s;
	i = 0;
	while (n--)
	{
		if (s2[i] == c)
			return (s2 + i);
		i++;
	}
	return (T_NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	int	tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	printf("%s\n", (char *)ft_memchr(tab, -1, 7));
	printf("/////////////\n");
	printf("%s\n", (char *)memchr(tab, -1, 7));
	return (0);
}*/
