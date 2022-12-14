/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 02:31:18 by cglandus          #+#    #+#             */
/*   Updated: 2022/11/14 01:57:30 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nb_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while ((s[i] != c) && s[i])
				i++;
			count++;
			continue ;
		}
		i++;
	}
	return (count);
}

static size_t	word_len(char const *s, char c, size_t start)
{
	size_t	i;

	i = 0;
	while (s[start] != c && s[start])
	{
		i++;
		start++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i[2];

	if (!s)
		return (T_NULL);
	array = (char **)ft_calloc(nb_words(s, c) + 1, sizeof(char *));
	if (!array)
		return (T_NULL);
	i[0] = 0;
	i[1] = 0;
	while (s[i[0]])
	{
		if (word_len(s, c, i[0]) > 0)
		{
			array[i[1]] = ft_substr(s, i[0], word_len(s, c, i[0]));
			i[0] += word_len(s, c, i[0]);
			i[1]++;
		}
		else
			i[0]++;
	}
	return (array);
}
