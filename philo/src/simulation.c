/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:41:23 by cglandus          #+#    #+#             */
/*   Updated: 2024/04/27 21:31:17 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	chores(t_philo *philo, int action)
{
	if (action == 1)
	{
		if (eating(philo))
			return ;
	}
	else if (action == 2)
	{
		if (get_val(&philo->param->dead, &philo->param->dead_mtx) == 1)
			return ;
		p_print(philo, "is sleeping");
		sleesleep(philo);
	}
	else if (action == 3
		&& (get_val(&philo->param->dead, &philo->param->dead_mtx)) == 0)
		p_print(philo, "is thinking");
}

static void	*routine(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	i = 0;
	if ((philo->who + 1) % 2 == 0)
		usleep(1000);
	while (1)
	{
		chores(philo, 1);
		if (get_val(&philo->param->dead, &philo->param->dead_mtx) == 1)
			return (NULL);
		chores(philo, 2);
		if (get_val(&philo->param->dead, &philo->param->dead_mtx) == 1)
			return (NULL);
		chores(philo, 3);
		if (get_val(&philo->param->dead, &philo->param->dead_mtx) == 1)
			return (NULL);
		if ((i == philo->param->n_toeat - 1) && philo->param->must_eat)
			return (are_full(philo));
		i++;
	}
	return (NULL);
}

void	start_simm(t_philo *philo, t_param *param)
{
	int			i;

	i = 0;
	if (param->forks == 1)
	{
		one_philo(philo);
		return ;
	}
	while (i < param->forks)
	{
		if (pthread_create(&philo[i].thread, NULL,
				&routine, &philo[i]) != 0)
			return ;
		i++;
	}
	is_dead(philo, param);
	i = 0;
	while (i < param->forks)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return ;
		i++;
	}
}
