/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:53:44 by cglandus          #+#    #+#             */
/*   Updated: 2024/04/27 20:52:20 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->rfork);
	pthread_mutex_lock(&philo->lfork);
	if (get_val(&philo->param->dead, &philo->param->dead_mtx) == 1)
	{
		pthread_mutex_unlock(&philo->lfork);
		pthread_mutex_unlock(philo->rfork);
		return (1);
	}
	p_print(philo, "has taken a fork");
	p_print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->param->eat_mtx);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->param->eat_mtx);
	p_print(philo, "is eating");
	eat_sleep(philo);
	pthread_mutex_unlock(&philo->lfork);
	pthread_mutex_unlock(philo->rfork);
	return (0);
}

void	*are_full(t_philo *philo)
{
	pthread_mutex_lock(&philo->param->eat_mtx);
	philo->last_meal = -1;
	pthread_mutex_unlock(&philo->param->eat_mtx);
	pthread_mutex_lock(&philo->param->full_mtx);
	philo->param->full += 1;
	pthread_mutex_unlock(&philo->param->full_mtx);
	return (NULL);
}

static void	*one_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	p_print(philo, "has taken a fork");
	usleep(philo->param->ttd * 1000);
	p_print(philo, "has died");
	return (NULL);
}

void	one_philo(t_philo *philo)
{
	if (pthread_create(&philo[0].thread, NULL, &one_routine, &philo[0]) != 0)
		return ;
	if (pthread_join(philo[0].thread, NULL) != 0)
		return ;
}
