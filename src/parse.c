/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:07:23 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/06/10 18:07:30 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/philo.h"

static bool	whitespace(char c)
{
	return (c == '+' || (c >= 9 && c <= 13) || 32 == c);
}

// we use bool here to enforces the return value to be either true or false, 
// reducing possible bugs compared to returning an integer with ambiguous meaning.

static bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

// Using static allows the variable to keep its value between function calls.

static long	ft_atol(const char *s)
{
	long	res;

	while (whitespace(*s))
		s++;
	if (*s == '-')
		return (0);
	if (!is_digit(*s))
	{
		error_msg("Input Error: Digit values only");
		return (0);
	}
	res = 0;
	while (is_digit(*s))
		res = (res * 10) + (*s++ - '0');
	return (res);
}

static long	check_int_range(t_data *data, char *argv)
{
	long	input;

	input = ft_atol(argv);
	if (input > INT_MAX)
	{
		error_msg("Input Error: The value cannot exceed 2147483647");
		data->error_flag = 1;
	}
	if (input < 1)
	{
		error_msg("Input Error: Positive values only");
		data->error_flag = 1;
	}
	return (input);
}

void	parse_input(t_data *data, char **argv)
{
	data->ph_total = check_int_range(data, argv[1]);
	if (data->ph_total > PH_MAX || data->ph_total < 1)
	{
		error_msg("Input Error: Total number of philos must be 1 - 200");
		data->error_flag = 1;
	}
	data->time_to_die = check_int_range(data, argv[2]) * 1000;
	data->time_to_eat = check_int_range(data, argv[3]) * 1000;
	data->time_to_sleep = check_int_range(data, argv[4]) * 1000;
	if (data->time_to_die < 60000 || data->time_to_sleep < 60000
		|| data->time_to_eat < 60000)
	{
		error_msg("Input Error: Each of the 'time_to' values must exceed 60");
		data->error_flag = 1;
	}
	if (argv[5])
		data->meals_total = check_int_range(data, argv[5]);
	else
		data->meals_total = -1;
}
