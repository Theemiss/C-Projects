#include "fact.h"

/**
 * 
 * 
 * 
 */


void* factor(struct ThreadData* td) 
{
    struct ThreadData* data=(struct ThreadData*) td;
    int start=data->start;
    int stop=data->stop;
    int* array=data->array;
    int i;
    for (i=start; i<stop  ; i++) {
        res *= x;
		x++;
    }

    return NULL;
}

int main(int argc,char **argv) 
{
	if (argc < 3)
	{
		printf("Usage: %s numbertofact(n) numberofthreads(t)\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	int NUMTHREADS = atoi(argv[2]);
	int array = atoi(argv[1]);
    pthread_t thread[NUMTHREADS];
    struct ThreadData data[NUMTHREADS];
    int i;
    /*
        this has the effect of rounding up the number of tasks
        per thread, which is useful in case ARRAYSIZE does not
        divide evenly by NUMTHREADS.
    */
    int tasksPerThread=(array+NUMTHREADS-2)/NUMTHREADS;

    /* Divide work for threads, prepare parameters */
    for (i=0; i<NUMTHREADS; i++) {
        data[i].start=i*tasksPerThread + 1;
        data[i].stop=(i+1)*tasksPerThread + 1;
        data[i].array=array;
    }
    /* the last thread must not go past the end of the array */
    data[NUMTHREADS-1].stop=array;

    /* Launch Threads */
    for (i=0; i<NUMTHREADS; i++) {
        pthread_create(&thread[i], NULL, factor, &data[i]);
    }

    /* Wait for Threads to Finish */
    for (i=0; i<NUMTHREADS; i++) {
        pthread_join(thread[i], NULL);
    }


    printf("%s != %d \n",argv[1],res);

    return 0;
}