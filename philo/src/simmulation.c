/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simmulation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:41:23 by cglandus          #+#    #+#             */
/*   Updated: 2024/04/24 23:06:36 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//left fork -> i | right fork -> (i + 1) % nb_philosophers
static void	routine(void *param)
{
	t_philo	*philo;

	philo = param;
	
}

void	start_simm(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->forks)
	{
		if (pthread_create(philo->t[i], NULL, &routine, philo) != 0)
			return ;
		i++;
	}
	i = 0;
	while (i < philo->forks)
	{
		if (pthread_join(philo->t[i], NULL) != 0)
			return ;
		i++;
	}
}
