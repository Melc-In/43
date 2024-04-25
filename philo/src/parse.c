/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:22:43 by cglandus          #+#    #+#             */
/*   Updated: 2024/04/25 05:30:26 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n--)
		*temp++ = c;
	return (s);
}

static void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb > UINT_MAX && size != 0)
		return (NULL);
	if (nmemb == 0 && size > UINT_MAX)
	{
		ptr = malloc(size * nmemb);
		if (!ptr)
			return (NULL);
		ft_bzero(ptr, nmemb * size);
		return (ptr);
	}
	if (nmemb * size > SIZE_MAX
		|| nmemb >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	if (nmemb < 0 || size > UINT_MAX
		|| size * nmemb < 0)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

int	ft_str_isdigit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	int				i;
	int				sign;
	long			result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32
		|| (str[i] == '0' && (str[i + 1] >= '0'
				&& str[i + 1] <= '9')))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (result > INT_MAX && sign != -1)
		return (2147483648);
	return (result * sign);
}
