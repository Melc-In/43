/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:44:38 by cglandus          #+#    #+#             */
/*   Updated: 2024/04/27 14:45:08 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (!(s1[i] == s2[i]))
		{
			if (s1[i] < 0)
				return (s2[i] - s1[i]);
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

static int	param_init(t_param *param, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_str_isdigit(argv[i]) || ft_atol(argv[i]) == 2147483648
			|| ft_atol(argv[i]) <= 0)
			return (0);
		i++;
	}
	if (i == 5 || i == 6)
	{
		param->forks = ft_atol(argv[1]);
		param->ttd = ft_atol(argv[2]);
		param->tte = ft_atol(argv[3]);
		param->tts = ft_atol(argv[4]);
		if (i == 6)
		{
			param->must_eat = 1;
			param->n_toeat = ft_atol(argv[5]);
		}
		return (1);
	}
	return (0);
}

static int	param_init_2(t_param *param)
{
	param->full = 0;
	param->dead = 0;
	param->first_time = get_time();
	if (param->first_time == -1)
		return (0);
	if (pthread_mutex_init(&param->print_mtx, NULL) != 0
		|| pthread_mutex_init(&param->dead_mtx, NULL) != 0
		|| pthread_mutex_init(&param->eat_mtx, NULL) != 0
		|| pthread_mutex_init(&param->full_mtx, NULL) != 0)
		return (0);
	return (1);
}

static int	philo_init(t_philo *philo, t_param *param)
{
	int	i;

	i = 0;
	if (!param_init_2(param))
		return (0);
	while (i < param->forks)
	{
		philo[i].param = param;
		if (pthread_mutex_init(&philo[i].lfork, NULL) != 0)
			return (0);
		philo[i].who = i + 1;
		philo[i].last_meal = get_time();
		i++;
	}
	i = 0;
	while (i < param->forks - 1)
	{
		philo[i].rfork = &philo[i + 1].lfork;
		i++;
	}
	philo[i].rfork = &philo[0].lfork;
	return (1);
}

int	main(int argc, char **argv)
{
	t_param	*param;
	t_philo	*philo;

	if (argc > 1)
	{
		param = (t_param *)ft_calloc(1, sizeof(t_param));
		if (!param)
			return (-1);
		param->n_toeat = -1;
		param->must_eat = 0;
		if (!param_init(param, argv))
		{
			free(param);
			return (-1);
		}
		philo = (t_philo *)ft_calloc(param->forks, sizeof(t_philo));
		if (!philo || !philo_init(philo, param))
		{
			if (philo)
				free(philo);
			return (-1);
		}
		start_simm(philo, param);
		destroy_simm(philo, param);
	}
	return (0);
}
