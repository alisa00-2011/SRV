#include<stdio.h>
#include<time.h>
#include<sync.h>
#include<sys/neutrino.h>

barrier_t barrier;

void *thread1(void * not_used){
	time_t now;
	char buf[27];
	time(&now);
	printf("Stream 1, start time %s\n", ctime_r(&now, buf));
	printf("Filimonova Alisa\n");
	sleep(3);
	barrier_wait(&barrier);
	time(&now);
	printf("barier v potoke 1, vremy srabativania %s\n", ctime_r(&now, buf));
}

void *thread2(void * not_used){
	time_t now;
	char buf[27];
	time(&now);
	printf("Stream 2, start time %s\n", ctime_r(&now, buf));
	printf("I992\n");
	sleep(3);
	barrier_wait(&barrier);
	time(&now);
	printf("barier v potoke 2, vremy srabativania %s\n", ctime_r(&now, buf));
}

main(){
		time_t now;
		char buf[27];
	barrier_init(&barrier, NULL, 3);
	printf("Start\n");
	pthread_create(NULL, NULL, thread1, NULL);
	pthread_create(NULL, NULL, thread2, NULL);
		time(&now);
		printf("Main(): oshidanie y bariora, vremia %s\n", ctime_r(&now, buf));
		barrier_wait(&barrier);
		time(&now);
		printf("barier v main() , vremia srabativania %s\n", ctime_r(&now, buf));
	sleep(5);
}