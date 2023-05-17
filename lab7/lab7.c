#include <stdio.h>
#include <pthread.h>

int data_ready = 0;
int max_data = 2;
int produced = 0;
int concumed = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condvar = PTHREAD_COND_INITIALIZER;

void *consumer(void * notused)
{
	printf("CONSUMER: Started \n"); /*potrebitel*/
	
	while(1)
	{	
		pthread_mutex_lock(&mutex);
		printf("COSCUMER: Searching for data \n");
		
		while(!data_ready)
		{
			printf("CONSUMER: Waiting for data \n");
			pthread_cond_wait(&condvar, &mutex);
			printf("CONSUMER: Data available \n");
		}
		
		printf("CONSUMER: Consumed data from PRODUCER, pkg-%d \n", concumed); /*ot proizvoditelia*/
		
		data_ready--;
		concumed++;
		
		pthread_cond_signal(&condvar);
		pthread_mutex_unlock(&mutex);
		
		sleep(3);
	}
}

void *producer(void * notused)
{
	printf("PRODUCER: Started\n");
	
	while(1)
	{
		sleep(2);
		
		pthread_mutex_lock(&mutex);
	
		printf("PRODUCER: Checking if data pkg max \n");
	
		while(data_ready == max_data)
		{
			printf("PRODUCER: Data ready, waiting for consuming \n");
			pthread_cond_wait(&condvar, &mutex);
		}
		
		printf("PRODUCER: Generated data pkg-%d \n\n", produced);
		
		data_ready++;
		produced++;
	
		pthread_cond_signal(&condvar);
		pthread_mutex_unlock(&mutex);
	}
}

int main(){
	printf("Start \n");
	
	pthread_create(NULL, NULL, consumer, NULL);
	pthread_create(NULL, NULL, producer, NULL);
	
	sleep(10);
	return(0);
}
