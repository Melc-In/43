/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simmulation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:41:23 by cglandus          #+#    #+#             */
/*   Updated: 2024/04/25 05:30:22 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//left fork -> i | right fork -> (i + 1) % nb_philosophers
static void	*routine(void *param)
{
	t_philo	*philo;
	int		i;

	philo = param;
	i = 0;
	while (i < 3)
	{
		printf("%d %d is alive\n", get_time() - philo->first_time, philo->who);
		i++;
		usleep(200000);
	}
	return (NULL);
}

void	start_simm(t_philo *philo)
{
	int	i;

	i = 0;
	philo->first_time = get_time();
	if (philo->first_time == -1)
		return ;
	while (i < philo->forks)
	{
		philo->who = 0;
		if (pthread_create(&philo->man[i].thread, NULL, &routine, philo) != 0)
			return ;
		i++;
	}
	i = 0;
	while (i < philo->forks)
	{
		if (pthread_join(philo->man[i].thread, NULL) != 0)
			return ;
		i++;
	}
}
