#include "header.h"

/**
 * main - Main Program
 *
 * Descreption: Mutex Thread Count up
 * Compiled with gcc *.c -pthread - o counter 
 * Return: (int) 0 On Succes 1 on Failer
 */

int counter = 0;
int th_counter = 0;
pthread_mutex_t lock;
int main(int argc, char **argv)
{
	int n, x;
	/* Controle Output */
    if (argc < 3)
	{
		printf("Usage: %s x n\n",argv[0]);
		exit(EXIT_FAILURE);
	}
    x = atoi(argv[1]);
	n = atoi(argv[2]);
	pthread_t thread[x];
	/* initialize mutex */
	if (pthread_mutex_init(&lock, NULL) != 0) 
	{ 
        printf("\n mutex init has failed\n"); 
        return (1);
	}
	/* creating x  Threads  */
	for (int i = 0;i < x;i++)
	{
		pthread_create(&thread[i], NULL, count, &n);
		th_counter += 1;
		if (th_counter % 2 == 1)
		{
			printf("%d\n",counter);
		}
	}
	/* Wait for Threads to Finish */
	for (int i=0; i < x; i++)
	{
        pthread_join(thread[i], NULL);
    }
	pthread_mutex_destroy(&lock);
	printf("Last Counter is %d \n",counter);
    return (0);
}
void * count(int *n)
{
	/* Aquire lock */
	pthread_mutex_lock(&lock);

	int *num = (int *) n;
	/* increase count by n */
	for (int i = 0;i < *num;i++)
	{
		counter++;
		
	}
	 /** release lock */
	pthread_mutex_unlock(&lock);

	return NULL;
}