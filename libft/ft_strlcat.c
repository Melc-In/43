/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:32:28 by cglandus          #+#    #+#             */
/*   Updated: 2022/10/07 03:36:25 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size	strlcat(char *dest, const char *src, t_size n)
{
	t_size	i;
	t_size	j;

	i = 0;
	j = 0;
	while (dest[j])
		j++;
	while (i < n && src[i] != '\0')
	{
		dest[j + i] = src[i];
		i++;
	}
	while(dest[j])
		j++;
	if (dest[j] != '\0')
		dest[j] = '\0';
	return (ft_strlen(dest) + ft_strlen((char *)src));
}
