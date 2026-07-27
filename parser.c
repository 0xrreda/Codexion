/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkadri <rkadri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 02:58:40 by rkadri            #+#    #+#             */
/*   Updated: 2026/07/28 03:01:51 by rkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	parse_int(char *str, int *out)
{
	long	nbr;

	if (!str || !(*str))
		return (0);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			return (0);
		str++;
	}
	if (!*str)
		return (0);
	nbr = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		nbr = (nbr * 10) + (*str - '0');
		if (nbr < INT_MIN || nbr > INT_MAX)
			return (0);
		str++;
	}
	if (nbr == 0)
		return (0);
	return (*out = (int)nbr, 1);
}

char	*parse_config(char **argv, t_config *config)
{
	if (!parse_int(argv[0], &config->number_of_coders))
		return ("invalid number_of_coders expected a valid positive integer");
	if (!parse_int(argv[1], &config->time_to_burnout))
		return ("invalid time_to_burnout expected a valid positive integer");
	if (!parse_int(argv[2], &config->time_to_compile))
		return ("invalid time_to_compile expected a valid positive integer");
	if (!parse_int(argv[3], &config->time_to_debug))
		return ("invalid time_to_debug expected a valid positive integer");
	if (!parse_int(argv[4], &config->time_to_refactor))
		return ("invalid time_to_refactor expected a valid positive integer");
	if (!parse_int(argv[5], &config->number_of_compiles_required))
		return ("invalid number_of_compiles_required expected a valid positive integer");
	if (!parse_int(argv[6], &config->dongle_cooldown))
		return ("invalid dongle_cooldown expected a valid positive integer");
	if (!strcmp(argv[7], "fifo") || !strcmp(argv[7], "edf"))
		config->scheduler = argv[7];
	else
		return ("invalid scheduler expected 'fifo' or 'edf'");
	return ("success");
}
