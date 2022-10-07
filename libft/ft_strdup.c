/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:45:43 by cglandus          #+#    #+#             */
/*   Updated: 2022/10/07 02:43:28 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_cpy;
	int		i;

	i = 0;
	s_cpy = malloc(ft_strlen((char *)s) * sizeof(char) + 1);
	if (!s_cpy)
		return (s_cpy);
	while (s[i])
	{
		s_cpy[i] = s[i];
		i++;
	}
	return (s_cpy);
}
