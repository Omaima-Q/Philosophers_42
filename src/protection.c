/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:10:45 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/06/10 18:10:51 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	set_bool(t_mtx	*mutex, bool *dst, bool value)
{
	handle_mutex(mutex, LOCK);
	*dst = value;
	handle_mutex(mutex, UNLOCK);
}

bool	get_bool(t_mtx *mutex, bool *value)
{
	bool	retrieved;

	handle_mutex(mutex, LOCK);
	retrieved = *value;
	handle_mutex(mutex, UNLOCK);
	return (retrieved);
}

void	set_long(t_mtx *mutex, long *dst, long value)
{
	handle_mutex(mutex, LOCK);
	*dst = value;
	handle_mutex(mutex, UNLOCK);
}

long	get_long(t_mtx *mutex, long *value)
{
	long	retrieve;

	handle_mutex(mutex, LOCK);
	retrieve = *value;
	handle_mutex(mutex, UNLOCK);
	return (retrieve);
}
