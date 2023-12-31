/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:00:27 by cglandus          #+#    #+#             */
/*   Updated: 2023/12/31 16:47:51 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!(s1 && s2))
		return (NULL);
	s3 = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (!s3)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}

char	*join(char *s1, char *s2)
{
	char	*str;

	if (!s1)
		s1 = ft_calloc(1, 1);
	str = ft_strjoin_gnl(s1, s2);
	free(s1);
	return (str);
}
