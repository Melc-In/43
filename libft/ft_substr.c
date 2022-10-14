/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:42:21 by cglandus          #+#    #+#             */
/*   Updated: 2022/10/14 18:15:59 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, t_size len)
{
	char			*ss;
	unsigned int	i;

	i = 0;
	if (len + start > ft_strlen(s))
		ss = malloc(len + 1 - ((start + len) - ft_strlen(s)));
	else
		ss = malloc((len + 1) * sizeof(char));
	if (!ss)
		return (T_NULL);
	while (s[i + start] && i + start  < len + start)
	{
		ss[i] = s[i + start];
		i++;
	}
	ss[i] = '\0';
	return (ss);
}
/*
#include <stdio.h>

int	main()
{
	char const		test[] = "heheheha35";
	unsigned int	start;
	t_size			l;

	start = 0;
	l = 6;	
	printf("%s\n", ft_substr(test, start, l));
	return (0);
}*/
