/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkadri <rkadri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 03:31:48 by rkadri            #+#    #+#             */
/*   Updated: 2026/07/26 03:41:28 by rkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	parser_config(int argc, char **argv, t_config config)
{
	int	idx;

	idx = 0;
	while (idx < argc)
	{
		printf("%s", *(argv + idx));
		idx++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc != 9)
	{
		fprintf(stderr,
			"[USAGE]: ./codexion <number_of_coders> <time_to_burnout> <time_to_compile> <time_to_debug> <time_to_refactor> <number_of_compiles_required> <dongle_cooldown> <fifo|edf>\n");
		return (1);
	}
	printf("%s\n", *argv);
	return (0);
}
