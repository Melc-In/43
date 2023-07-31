/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:37:22 by cglandus          #+#    #+#             */
/*   Updated: 2023/07/31 09:36:11 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static int	check_stack(s_list stack)
//{
//}

static int	quote_handler(char *arg, size_t i)
{
	char	*splited_arg;
	size_t	i;

	i = -1;
	splited_arg = ft_strtrim(arg, "\"");
	splited_arg = ft_split(arg, arg[i + 1]);
	if (!splited_arg)
		return (0);
	while (arg[i++])
	{
		if(!ft_isdigit(arg[i]))
			return (0);
	}
	ft_putstr_fd(splited_arg, 1);
	return (1);
}

static int	check_args(char *arg)
{
	if ((ft_strlen(arg) == 1))
	{
		if (ft_isdigit(ft_atoi(arg[0])))
		{
			//add to stack + check if the digit isnt already in ??
			return (1);
		}
		return (0);
	}
	else if (arg[i] == '"')
	{
		if (quote_handler(arg, i))
			return (1);
	}
	return (0);
}

int	parsing(char **args)
{
	size_t	i;

	i = 1;
	while (args[i])
	{
		if (check_args(args[i]))
			return (1);
		else
			return (0);
		i++;
	}	
}
