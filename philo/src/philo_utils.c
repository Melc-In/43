/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:44:40 by cglandus          #+#    #+#             */
/*   Updated: 2024/04/24 23:06:38 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time(t_philo *philo)
{
	struct timeval	tv;
	int	curr_time;

	gettimeofday(&tv, NULL) 
	curr_time = philo->start_time - (tv.useci * 1000);
	return (curr_time);
}

void	destroy_m(t_philo *philo)
{
	if (philo->t)
		free(philo->t);
	if (philo->man)
		free(philo->man);
	pthread_mutex_destroy(philo->man->forks_mtx);
	pthread_mutex_destroy(philo->man->status_mtx);
	pthread_mutex_destroy(philo->man->print_mtx);
}
