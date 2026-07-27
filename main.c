/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkadri <rkadri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 03:31:48 by rkadri            #+#    #+#             */
/*   Updated: 2026/07/26 22:44:42 by rkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	main(int argc, char *argv[])
{
	t_config	config;
	char		*parser_config_status;

	if (argc != 9)
	{
		fprintf(stderr,
				"[USAGE]: ./codexion <number_of_coders> <time_to_burnout> "
				"<time_to_compile> <time_to_debug> <time_to_refactor> "
				"<number_of_compiles_required> <dongle_cooldown> <fifo|edf>\n");
		return (1);
	}
	parser_config_status = parse_config(argv + 1, &config);
	if (strcmp(parser_config_status, "success"))
	{
		fprintf(stderr, "[ERROR]: %s\n", parser_config_status);
		return (1);
	}
	return (0);
}
