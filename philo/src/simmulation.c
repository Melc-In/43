/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simmulation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:41:23 by cglandus          #+#    #+#             */
/*   Updated: 2024/04/27 06:54:49 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_man(t_philo *philo)
{
	int	i;

	i = 0;
	philo->first_time = get_time();
	if (philo->first_time == -1)
		return ;
	while (i < philo->forks)
	{
		philo->man[i].forks_mtx = philo->forks_mtx;
		philo->man[i].first_time = &philo->first_time;
		philo->man[i].print_mtx = &philo->print_mtx;
		philo->man[i].dead_mtx = &philo->dead_mtx;
		philo->man[i].eat_mtx = &philo->eat_mtx;
		philo->man[i].dead = &philo->dead;
		philo->man[i].nb_philo = philo->forks;
		philo->man[i].ttd = philo->ttd;
		philo->man[i].tte = philo->tte;
		philo->man[i].tts = philo->tts;
		philo->man[i].n_toeat = philo->n_toeat;
		philo->man[i].full = &philo->full;
		philo->man[i].must_eat = philo->must_eat;
		philo->man[i].last_meal = philo->first_time;
		philo->man[i].who = i;
		i++;
	}
}

int	is_dead(t_philo *philo)
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
			time = get_time();
			while (i < philo->forks)
			{
				pthread_mutex_lock(&philo->dead_mtx);
				if (time - philo->man[i].last_meal >= philo->ttd)
				{
					philo->dead = 1;
					pthread_mutex_unlock(&philo->dead_mtx);
					usleep(500);
					p_print(&philo->man[i], "died");
					return (1);
				}
				pthread_mutex_unlock(&philo->dead_mtx);
				i++;
			}
			i = 0;
			pthread_mutex_lock(&philo->dead_mtx);
			if ((philo->full == philo->n_toeat) && philo->must_eat)
			{
				pthread_mutex_unlock(&philo->dead_mtx);
				return (1);
			}
			pthread_mutex_unlock(&philo->dead_mtx);
		}
	}
	return (0);
}

void	eat_sleep(t_greec *man)
{
	int	waited;

	waited = get_time() - man->last_meal;
	if (man->tte + waited > man->ttd)
		usleep((man->ttd - waited) * 1000);
	else
		usleep(man->tte * 1000);
}

void	sleesleep(t_greec *man)
{
	if (man->tte + man->tts > man->ttd)
		usleep(man->ttd * 1000);
	else
		usleep(man->tts * 1000);
}

void	chores(t_greec *man, int action)
{
	if (action == 1)
	{
		pthread_mutex_lock(&man->forks_mtx[(man->who + 1) % man->nb_philo]);
		pthread_mutex_lock(&man->forks_mtx[man->who]);
		if (get_val(*man->dead, man->dead_mtx) == 1)
		{
			pthread_mutex_unlock(&man->forks_mtx[man->who]);
			pthread_mutex_unlock(&man->forks_mtx[(man->who + 1) % man->nb_philo]);
			return ;
		}
		p_print(man, "has taken a fork");
		p_print(man, "has taken a fork");
		pthread_mutex_lock(man->eat_mtx);
		man->last_meal = get_time();
		pthread_mutex_unlock(man->eat_mtx);
		p_print(man, "is eating");
		eat_sleep(man);
		pthread_mutex_unlock(&man->forks_mtx[man->who]);
		pthread_mutex_unlock(&man->forks_mtx[(man->who + 1) % man->nb_philo]);
	}
	else if (action == 2)
	{
		if (get_val(*man->dead, man->dead_mtx) == 1)
			return ;
		p_print(man, "is sleeping");
		sleesleep(man);
	}
	else if (action == 3 && (get_val(*man->dead, man->dead_mtx) == 0))
		p_print(man, "is thinking");
}

static void	*routine(void *param)
{
	t_greec	*man;

	man = param;
	if ((man->who + 1) % 2 == 1)
		usleep(1000);
	while (1)
	{
		chores(man, 1);
		if (get_val(*man->dead, man->dead_mtx) == 1)
			return (NULL);
		chores(man, 2);
		if (get_val(*man->dead, man->dead_mtx) == 1)
			return (NULL);
		chores(man, 3);
		if (get_val(*man->dead, man->dead_mtx) == 1)
			return (NULL);
		pthread_mutex_lock(man->dead_mtx);
		if ((*man->full == man->n_toeat) && man->must_eat)
		{
			pthread_mutex_unlock(man->dead_mtx);
			return (NULL);
		}
		pthread_mutex_unlock(man->dead_mtx);
	}
	return (NULL);
}

void	start_simm(t_philo *philo)
{
	int			i;

	i = 0;
	init_man(philo);
	while (i < philo->forks)
	{
		if (pthread_create(&philo->man[i].thread, NULL,
				&routine, &philo->man[i]) != 0)
			return ;
		i++;
	}
	is_dead(philo);
	i = 0;
	while (i < philo->forks)
	{
		if (pthread_join(philo->man[i].thread, NULL) != 0)
			return ;
		i++;
	}
}
