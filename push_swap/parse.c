/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:37:22 by cglandus          #+#    #+#             */
/*   Updated: 2023/07/31 02:12:05 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	check_args(char *arg)
{
	t_size	i;

	i = 0;
	if ((ft_strlen(arg) == 1))
	{
		if (ft_isdigit(ft_atoi(arg[i])))
		{
			// mettre le digit dans la pile
			return (1);
		}
		return (0);
	}
	else
	{
		if (arg[0] == '"')
		{
			i++;
			while (arg[i])	
		}
	}
}

int	parsing(int n_args, char **args)
{
	t_size	i;

	i = 1;
	if (n_args < 2)
		return (0);
	while (args[i])
	{
		if (check_args(args[i]))
			return (1);
		i++;
	}	
}

