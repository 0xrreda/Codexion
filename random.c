#include <pthread.h>
#include <stdio.h>

int		n = 100;

void	*worker(void *arg)
{
	printf("thread %ld\n", *(long *)arg);
	return (NULL);
}

int	main(void)
{
	pthread_t	t;
	long		i;

	i = 0;
	while (1)
	{
		pthread_create(&t, NULL, worker, &i);
		i++;
	}
	return (0);
}
