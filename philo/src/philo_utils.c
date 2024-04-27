/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:44:40 by cglandus          #+#    #+#             */
/*   Updated: 2024/04/27 07:56:08 by cglandus         ###   ########.fr       */
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

void	p_print(t_greec *man, char *mess)
{
	int	time;

	time = get_time();
	if (ft_strcmp(mess, "is eating") == 0)
		man->last_meal = time;
	if (time != -1)
	{
		pthread_mutex_lock(man->print_mtx);
		printf("%d %d %s\n", time - *man->first_time, man->who + 1, mess);
		pthread_mutex_unlock(man->print_mtx);
	}
}

void	*unlock_forks(pthread_mutex_t *f1, pthread_mutex_t *f2)
{
	pthread_mutex_unlock(f1);
	pthread_mutex_unlock(f2);
	return (NULL);
}

void	destroy_simm(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&philo->print_mtx);
	pthread_mutex_destroy(&philo->dead_mtx);
	pthread_mutex_destroy(&philo->eat_mtx);
	pthread_mutex_destroy(&philo->full_mtx);
	while (i < philo->forks)
	{
		pthread_mutex_destroy(&philo->forks_mtx[i]);
		i++;
	}
	if (philo->forks_mtx)
		free(philo->forks_mtx);
	if (philo->man)
		free(philo->man);
}
