#include<stdio.h>
#include<pthread.h>
#include<inttypes.h>
#include<errno.h>
#include<sys/neutrino.h>

int main(void)
{
	int coid;
	long serv_pid;
	
	char smsg[20];
	char rmsg[200];
		
	printf("\nLAB3 Alisa Filimonova | CLIENT\nWrite server PID: ");
	scanf("%ld", &serv_pid);
	printf("Server PID: %ld; ", serv_pid);
	
	coid = ConnectAttach(0, serv_pid, 1, 0, 0);
	
	printf("Connection ID: %d \nType message: ", coid);
	scanf("%s", &smsg);
	
	if (MsgSend(coid, smsg, strlen(smsg)+1, rmsg, sizeof(rmsg)) == -1)
		printf("Error MsgSend \n");
	
	printf("Message \"%s\" sent\n", smsg);
	printf("Got answer: \"%s\"\n\n", rmsg);
	
	return(0);
}