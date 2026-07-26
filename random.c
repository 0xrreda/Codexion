/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkadri <rkadri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 02:36:24 by rkadri            #+#    #+#             */
/*   Updated: 2026/07/26 03:46:25 by rkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int				MAILS = 0;
pthread_mutex_t	mutexi = PTHREAD_MUTEX_INITIALIZER;

void	*routing(void *arg)
{
	// printf("thread %d is saying hi...\n", *(int *)arg);
	// sleep(2);
	for (int i = 0; i < 10000000; i++)
	{
		pthread_mutex_lock(&mutexi);
		MAILS += 1;
		pthread_mutex_unlock(&mutexi);
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	pthread_t	t[5];
	int			*a;
	int			r;

	r = 1;
	for (int i = 0; i < 5; i++)
	{
		a = malloc(sizeof(int));
		*a = i;
		pthread_create(&t[i], NULL, routing, a);
	}
	for (int i = 0; i < 5; i++)
	{
		pthread_join(t[i], NULL);
	}
	printf("new mails: %d\n\n", MAILS);
	return (0);
}
