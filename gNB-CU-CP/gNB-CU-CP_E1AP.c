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

#include "E1AP_18.3.h"
#include "E1AP_18.3_Stack.h"
#include "gNB-CU-CP.h"




void E1AP_Send_GNB_CU_UP_E1SetupRequest( SI_E1APNode * e1Node)
{
	SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupRequest * obj_GNB_CU_CP_E1SetupRequest = (SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupRequest*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupRequest));
	memset( obj_GNB_CU_CP_E1SetupRequest, 0, sizeof( SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupRequest));

	obj_GNB_CU_CP_E1SetupRequest->transactionID = 1;
	obj_GNB_CU_CP_E1SetupRequest->transactionID_isset = 1;

	if( __gnb_cu_cp->Name.isset == 1)
	{
		__si_e1ap_init_GNB_CU_CP_Name2( &obj_GNB_CU_CP_E1SetupRequest->gNBCUCPName, __gnb_cu_cp->Name.val, __gnb_cu_cp->Name.len);
		obj_GNB_CU_CP_E1SetupRequest->gNBCUCPName_isset = 1;
	}
	
	__si_e1ap_send_GNB_CU_CP_E1SetupRequest( obj_GNB_CU_CP_E1SetupRequest, e1Node);
	__si_e1ap_memfree_pdu_GNB_CU_CP_E1SetupRequest( obj_GNB_CU_CP_E1SetupRequest);
}








void E1AP_ReceiveMessage( uint8_t procedureCode, uint8_t messageType, void * msg, SI_E1APNode * ngNode)
{
	printf("Received Message With procedureCode=%u\n", procedureCode);
}


int e1ap_server_onconnect( SI_Socket * siSocket)
{
	SI_E1APNode * e1Node = (SI_E1APNode *) siSocket->transportEng;
	if(!e1Node)
	{
		__si_malloc2( sizeof( SI_E1APNode), (uint8_t **)&e1Node);
		siSocket->transportEng 	= (uint8_t *) e1Node;
		e1Node->transportEng 	= (uint8_t *) siSocket;
	}
	e1Node->siSocket = siSocket;
	
	E1AP_Send_GNB_CU_UP_E1SetupRequest( e1Node);
	return 1;
}



void Init__E1AP()
{
	E1AP__InitStack( __gnb_cu_cp->LogPath);
	E1AP__SetHost( __gnb_cu_cp->f1ap_ips[0], (strlen( __gnb_cu_cp->f1ap_ips[1]) > 0) ? __gnb_cu_cp->f1ap_ips[1] : NULL, 0);
	
	int i = 0;
	for( i = 0; i < __gnb_cu_cp->E1AP_NodeCount; i++)
	{
		__gnb_cu_up_t * gnb_cu_up = &__gnb_cu_cp->E1AP_Node[i];
		E1AP__AddServer( gnb_cu_up->e1ap_ips[0], (strlen( gnb_cu_up->e1ap_ips[1]) > 0) ? gnb_cu_up->e1ap_ips[1] : NULL, gnb_cu_up->e1ap_port);
	}
	
	E1AP__SetOnConnect( e1ap_server_onconnect);
	E1AP__SetOnMessageRecv( E1AP_ReceiveMessage);
	E1AP__StartStack();
}		