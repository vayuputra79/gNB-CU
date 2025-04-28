#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <semaphore.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <unistd.h>
#include <signal.h>
#include <limits.h>
#include <poll.h>
#include <sys/epoll.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <error.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <net/if.h> 
#include <resolv.h>

#include "sirik_socket.h"
#include "E1AP_18.3.h"
#include "E1AP_18.3_Stack.h"
#include "E1AP_test.h"


int e1ap_server_onconnect( SI_Socket * siSocket)
{
	printf("Connected\n");

	SI_E1APNode * e1Node = (SI_E1APNode *) siSocket->transportEng;

	if(!e1Node)
	{
		__si_malloc2( sizeof( SI_E1APNode), (uint8_t **)&e1Node);
		siSocket->transportEng 	= (uint8_t *) e1Node;
		e1Node->transportEng 	= (uint8_t *) siSocket;
	}
	e1Node->siSocket = siSocket;
	


	__si_e1ap__Send_GNB_CU_UP_E1SetupRequest_Prototype( e1Node);
	__si_e1ap__Send_GNB_CU_CP_ConfigurationUpdateAcknowledge_Prototype( e1Node);

	
	return 0;
}	

void E1AP_ReceiveMessage( uint8_t procedureCode, uint8_t messageType, void * msg, SI_E1APNode * ngNode)
{
	printf("Received Message With procedureCode=%u\n", procedureCode);
}

int main( int argc, char* argv[])
{
	printf( "E1AP Server\n");
	E1AP__InitStack( "./e1ap_c_logs/");
	E1AP__SetHost( "192.168.149.76", NULL, 0);
	E1AP__AddServer( "192.168.149.72", NULL, 38462);
	E1AP__SetOnConnect( e1ap_server_onconnect);
	E1AP__SetOnMessageRecv( E1AP_ReceiveMessage);
	E1AP__StartStack();

	// cat /proc/net/sctp/eps 
	// lsof -R | grep 
		
	__si_core_wait();
}

