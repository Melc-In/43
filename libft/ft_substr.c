/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:42:21 by cglandus          #+#    #+#             */
/*   Updated: 2022/11/11 01:24:53 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ss;
	unsigned int	i;

	i = 0;
	if (!s)
		return (T_NULL);
	if (len == 0 || start > (unsigned int)ft_strlen(s))
		return ((char *)ft_calloc(1, 1));
	if (len + start > ft_strlen(s))
		ss = malloc(len + 1 - ((start + len) - ft_strlen(s)));
	else
		ss = malloc(len + 1);
	if (!ss)
		return (T_NULL);
	while (s[i + start] && i + start < len + start)
	{
		ss[i] = s[i + start];
		i++;
	}
	ss[i] = '\0';
	return (ss);
}
