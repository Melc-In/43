/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 02:31:18 by cglandus          #+#    #+#             */
/*   Updated: 2022/11/11 05:01:23 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nb_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
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
	size_t	i[3];
	
	array = malloc(nb_words(s, c) + 1);
	if (!array)
		return (T_NULL);
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (s[i[0]])
	{
		if (word_len(s, c, i[0]) > i[0])
		{
			array[i[1]] = malloc(word_len(s, c, i[0]));
			if (!array[i[1]])
				return (T_NULL);
			while (s[i[0]] != c)
			{
				array[i[1]][i[2]] = s[i[0]];
				i[2]++;
				i[0]++;
			}
			i[2] = 0;
			i[1]++;
		}
		i[0]++;
	}
	array[i[1]] = malloc(1);
	array[i[1]][0] = '\0';
	return (array);
}
/*
#include <stdio.h>

int	main()
{
	char	*s = "hehe,   ha, 123456789,,,,";
	char	**arr;
	int		i;

	arr = ft_split(s, ',');
	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		printf("/////////\n");
		i++;
	}
	return (0);
}*/
