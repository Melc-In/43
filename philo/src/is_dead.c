/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:55:30 by cglandus          #+#    #+#             */
/*   Updated: 2024/04/27 21:02:21 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_philos(t_philo *philo, t_param *param, int i, int time)
{
	pthread_mutex_lock(&param->eat_mtx);
	if (philo[i].last_meal != -1
		&& (time - philo[i].last_meal >= param->ttd))
	{
		pthread_mutex_unlock(&param->eat_mtx);
		pthread_mutex_lock(&param->dead_mtx);
		param->dead = 1;
		pthread_mutex_unlock(&param->dead_mtx);
		usleep(500);
		p_print(&philo[i], "died");
		return (1);
	}
	else
		pthread_mutex_unlock(&param->eat_mtx);
	pthread_mutex_lock(&param->full_mtx);
	if ((param->full == param->forks) && param->must_eat)
	{
		pthread_mutex_unlock(&param->full_mtx);
		return (1);
	}
	pthread_mutex_unlock(&param->full_mtx);
	return (0);
}

static int	all_eat(t_param *param)
{
	pthread_mutex_lock(&param->full_mtx);
	if ((param->full == param->forks) && param->must_eat)
	{
		pthread_mutex_unlock(&param->full_mtx);
		return (1);
	}
	pthread_mutex_unlock(&param->full_mtx);
	return (0);
}

int	is_dead(t_philo *philo, t_param *param)
{
	int	time;
	int	i;

	time = get_time();
	if (time != -1)
	{
		usleep(100);
		i = 0;
		while (1)
		{
			usleep(1000);
			time = get_time();
			while (i < param->forks)
			{
				if (check_philos(philo, param, i, time))
					return (1);
				i++;
			}
			i = 0;
			if (all_eat(param))
				return (1);
		}
	}
	return (0);
}
