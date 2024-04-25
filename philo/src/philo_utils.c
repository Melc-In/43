/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:44:40 by cglandus          #+#    #+#             */
/*   Updated: 2024/04/25 05:30:27 by cglandus         ###   ########.fr       */
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

void	destroy_simm(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->forks)
	{
		pthread_mutex_destroy(&philo->forks_mtx[i]);
		pthread_mutex_destroy(&philo->man[i].status_mtx);
		i++;
	}
	if (philo->man)
		free(philo->man);
	pthread_mutex_destroy(&philo->print_mtx);
}
