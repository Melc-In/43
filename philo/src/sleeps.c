/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:56:49 by cglandus          #+#    #+#             */
/*   Updated: 2024/04/27 21:31:22 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_sleep(t_philo *philo)
{
	int	waited;

	pthread_mutex_lock(&philo->param->eat_mtx);
	waited = get_time() - philo->last_meal;
	pthread_mutex_unlock(&philo->param->eat_mtx);
	if ((philo->param->tte + waited) > philo->param->ttd)
		usleep((philo->param->ttd - waited) * 1000);
	else
		usleep(philo->param->tte * 1000);
}

void	sleesleep(t_philo *philo)
{
	if (philo->param->tte + philo->param->tts > philo->param->ttd)
		usleep(philo->param->ttd * 1000);
	else
		usleep(philo->param->tts * 1000);
}
