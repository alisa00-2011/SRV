#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <inttypes.h>
#include <errno.h>
#include <sys/neutrino.h>

void server(void )
{
	int rcvid;
	int chid;
	char message[512];
	
	char ref[] = "";
	
	chid = ChannelCreate(0);
	printf("Server started; ChID: %d; PID: %d \n", chid, getpid());
	
	while(1)
	{
		rcvid = MsgReceive(chid, message, sizeof(message), NULL);
		
		if (message[0] == 22) {
			MsgReply(rcvid, EOK, message, sizeof(message));
			continue;
		}
		
		printf("\nMessage received; RcvID: %X; message: \"%s\"\n", rcvid, message);
				
		strcat(message, " received by server");
		MsgReply(rcvid, EOK, message, sizeof(message));
		
		printf("Answer sent: \"%s\". \n\n", message);
	}
}

int main(void)
{
	printf("\nLAB3 Alisa Filimonova | SERVER \n");
	server();
	return(0);
}