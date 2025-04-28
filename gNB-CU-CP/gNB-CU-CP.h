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


#ifndef	gNB_CU_CP
#define	gNB_CU_CP


#include "jansson.h"
#include "sirik_core.h"


#pragma pack(4)
typedef struct __gnb_bearer_context
{
	uint64_t gNB_CU_CP__UE_ID;
	uint64_t gNB_CU_UP__UE_E1AP_ID;
	uint64_t gNB_DU_CP__UE_F1AP_ID;
	
	
} __gnb_bearer_context_t;



typedef struct __gnb_cu_up_supported_plmn 
{
		u_char PLMN[4];

} __gnb_cu_up_supported_plmn_t;


typedef struct __gnb_cu_up 
{
	char 			e1ap_ips[4][20];
	uint32_t 		e1ap_ips_count;
	uint32_t 		e1ap_port;
	uint8_t			TransactionID;
	pthread_mutex_t	TransactionIDLock;
} __gnb_cu_up_t;


typedef struct __si_f1ap_node SI_F1APNode;


typedef struct __gnb_du 
{
	struct __gnb_du * Next;

	long gNBDUID;
	SI_LinkedList * UEContexts;
	SI_F1APNode * f1Node;
	
} __gnb_du_t;


typedef struct __gnb_cu_cp 
{
	uint32_t 			ID;
	__si_string140_t 	Name;

	char 		f1ap_ips[4][20];
	uint32_t 	f1ap_ips_count;
	uint32_t 	f1ap_port;

	__gnb_cu_up_t E1AP_Node[10];
	int E1AP_NodeCount;
	
	__gnb_cu_up_supported_plmn_t supported_plmn[12];
	int supported_plmn_count;

	uint32_t BearerContextCount;
	si_sirik_pool_t * bearer_context__pool;
	SI_IdProvider 	* idProvider;
	
	__gnb_du_t * duHead;
	__gnb_du_t * duCurrent;
	pthread_mutex_t duLock;
	
	
	char LogPath[249];

} __gnb_cu_cp_t;


__gnb_cu_cp_t * __gnb_cu_cp;



// E1AP
void Init__E1AP();





// F1AP
void Init__F1AP();




#endif









