/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:05:28 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/06/10 18:05:53 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		data.error_flag = 0;
		// Initializes an error flag within the data structure to 0, indicating no error initially.
		parse_input(&data, argv);
		if (!data.error_flag)
		// Checks whether an error was detected during input parsing (error_flag remains 0).
		// If no error, proceeds to initialize and run the simulation.
		{
			data_init(&data);
			sim_start(&data);
			free_things(&data);
		}
		else
			return (1);
	}
	else
		error_msg("Input Error\n"
			YELLOW "Please enter: ./philo <no. of philos> <time_to_die>"
			" <time_to_eat> <time_to_sleep> <max_meals> (optional)\n"
			"For example: ./philo 5 800 200 200 7" RESET);
	return (0);
}
