/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:44:40 by cglandus          #+#    #+#             */
/*   Updated: 2024/04/27 18:28:56 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time(void)
{
	struct timeval	timestamp;
	int				curr_time;

	if (gettimeofday(&timestamp, NULL))
		return (-1);
	curr_time = (timestamp.tv_sec * 1000) + (timestamp.tv_usec / 1000);
	return (curr_time);
}

int	get_val(int value, pthread_mutex_t *m)
{
	int	val;

	pthread_mutex_lock(m);
	val = value;
	pthread_mutex_unlock(m);
	return (val);
}

void	p_print(t_philo *philo, char *mess)
{
	int	time;

	time = get_time();
	if (ft_strcmp(mess, "is eating") == 0)
	{
		pthread_mutex_lock(&philo->param->eat_mtx);
		philo->last_meal = time;
		pthread_mutex_unlock(&philo->param->eat_mtx);
	}
	if (time != -1)
	{
		pthread_mutex_lock(&philo->param->print_mtx);
		printf("%d %d %s\n", time - philo->param->first_time, philo->who, mess);
		pthread_mutex_unlock(&philo->param->print_mtx);
	}
}

void	destroy_simm(t_philo *philo, t_param *param)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&param->print_mtx);
	pthread_mutex_destroy(&param->dead_mtx);
	pthread_mutex_destroy(&param->eat_mtx);
	pthread_mutex_destroy(&param->full_mtx);
	while (i < param->forks)
	{
		pthread_mutex_destroy(&philo[i].lfork);
		i++;
	}
	if (param)
		free(param);
	if (philo)
		free(philo);
}
