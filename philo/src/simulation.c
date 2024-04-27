/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:41:23 by cglandus          #+#    #+#             */
/*   Updated: 2024/04/27 18:42:43 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_routine(void *arg)
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
			time = get_time();
			while (i < param->forks)
			{
				//pthread_mutex_lock(&param->eat_mtx);
				if (philo[i].last_meal != -1
					&& (time - philo[i].last_meal >= param->ttd))
				{
					//pthread_mutex_unlock(&param->eat_mtx);
					pthread_mutex_lock(&param->dead_mtx);
					param->dead = 1;
					pthread_mutex_unlock(&param->dead_mtx);
					usleep(500);
					p_print(&philo[i], "died");
					return (1);
				}
				//else
					//pthread_mutex_unlock(&param->eat_mtx);
				i++;
				pthread_mutex_lock(&param->full_mtx);
				if ((param->full == param->forks) && param->must_eat)
				{
					pthread_mutex_unlock(&param->full_mtx);
					return (1);
				}
				pthread_mutex_unlock(&param->full_mtx);
			}
			i = 0;
			pthread_mutex_lock(&param->full_mtx);
			if ((param->full == param->forks) && param->must_eat)
			{
				pthread_mutex_unlock(&param->full_mtx);
				return (1);
			}
			pthread_mutex_unlock(&param->full_mtx);
		}
	}
	return (0);
}

void	eat_sleep(t_philo *philo)
{
	//int	waited;

//	pthread_mutex_lock(&philo->param->eat_mtx);
	//waited = get_time() - philo->last_meal;
	//pthread_mutex_unlock(&philo->param->eat_mtx);
//	if ((philo->param->tte + waited) > philo->param->ttd)
		//usleep((philo->param->ttd - waited) * 1000);
	//else
	usleep(philo->param->tte * 1000);
}

void	sleesleep(t_philo *philo)
{
	if (philo->param->tte + philo->param->tts > philo->param->ttd)
		usleep(philo->param->ttd * 1000);
	else
		usleep(philo->param->tts * 1000);
}

static void	chores(t_philo *philo, int action)
{
	if (action == 1)
	{
		pthread_mutex_lock(philo->rfork);
		pthread_mutex_lock(&philo->lfork);
		if (get_val(philo->param->dead, &philo->param->dead_mtx) == 1)
		{
			pthread_mutex_unlock(&philo->lfork);
			pthread_mutex_unlock(philo->rfork);
			return ;
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
	}
	else if (action == 2)
	{
		if (get_val(philo->param->dead, &philo->param->dead_mtx) == 1)
			return ;
		p_print(philo, "is sleeping");
		sleesleep(philo);
	}
	else if (action == 3
		&& (get_val(philo->param->dead, &philo->param->dead_mtx) == 0))
		p_print(philo, "is thinking");
}

static void	*routine(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = arg;
	i = 0;
	if ((philo->who + 1) % 2 == 0)
		usleep(1000);
	while (1)
	{
		chores(philo, 1);
		//pthread_mutex_lock(&philo->param->dead_mtx);
		//if (philo->param->dead)
		//{
			//pthread_mutex_unlock(&philo->param->dead_mtx);
			//return (NULL);
		//}
		//pthread_mutex_unlock(&philo->param->dead_mtx);
		if (get_val(philo->param->dead, &philo->param->dead_mtx) == 1)
			return (NULL);
		chores(philo, 2);
		if (get_val(philo->param->dead, &philo->param->dead_mtx) == 1)
			return (NULL);
		chores(philo, 3);
		if (get_val(philo->param->dead, &philo->param->dead_mtx) == 1)
			return (NULL);
		if ((i == philo->param->n_toeat - 1) && philo->param->must_eat)
		{
			pthread_mutex_lock(&philo->param->eat_mtx);
			philo->last_meal = -1;
			pthread_mutex_unlock(&philo->param->eat_mtx);
			pthread_mutex_lock(&philo->param->full_mtx);
			philo->param->full += 1;
			pthread_mutex_unlock(&philo->param->full_mtx);
			return (NULL);
		}
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
