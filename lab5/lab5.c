#include<stdio.h>
#include<pthread.h>
#include<inttypes.h>
#include<errno.h>
#include<sys/neutrino.h>

#define NSEC_TO_SEC 1000000000LL // 1 sekyuda billion nanosekynd

void * long_thread(void *_thread_lifetime)
{
	int thread_lifetime;
	thread_lifetime = *((int*)_thread_lifetime);
	
	printf("THREAD  : Started, lifetime %d seconds\n", thread_lifetime);
	sleep(thread_lifetime);
	printf("THREAD  : Ended\n");
}

int main(int argc, char* argv[])
{
	int retval;
	pthread_t thread_id;
	uint64_t timeout;
	struct sigevent event;
	
	int thread_lifetime = 10;
	int first_check = 5;
	int second_check = 10;
	
	event.sigev_notify = SIGEV_UNBLOCK;
	
	// Time arguments
	if (argc > 1)
		thread_lifetime = atoi(argv[1]);
	if (argc > 2)
		first_check = atoi(argv[2]);
	if (argc > 3)
		second_check = atoi(argv[3]);
	
	// Header
	printf("I992_Filimonova_Alisa_LR5_Timer\n");
	
	// Create thread
	
	pthread_create(&thread_id, NULL, long_thread, (void*)&thread_lifetime);
	
	timeout = first_check * NSEC_TO_SEC;
	
	printf("TIMER 1 : Started, %d second(s) \n", first_check);
	TimerTimeout(CLOCK_REALTIME, _NTO_TIMEOUT_JOIN, &event, &timeout, NULL);	
	retval = pthread_join(thread_id, NULL);
	printf("TIMER 1 : Ended\n");
	
	if (retval == ETIMEDOUT)
		printf("STATUS  : Thread %d alive\n", thread_id);
	else
		printf("STATUS  : Thread %d ended\n", thread_id);
		
	timeout = second_check * NSEC_TO_SEC;
	
	printf("TIMER 2 : Started, %d second(s) \n", second_check);
	TimerTimeout(CLOCK_REALTIME, _NTO_TIMEOUT_JOIN, &event, &timeout, NULL);
	retval = pthread_join(thread_id, NULL);
	printf("TIMER 2 : Ended\n");
	
	if (retval == ETIMEDOUT)
		printf("STATUS  : Thread %d alive\n", thread_id);
	else
		printf("STATUS  : Thread %d ended\n", thread_id);
	
	return(1);
}