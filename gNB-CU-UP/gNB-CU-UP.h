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


#ifndef	gNB_CU_UP
#define	gNB_CU_UP

#include "jansson.h"
#include "E1AP_18.3.h"
#include "sirik_core.h"


#pragma pack(4)
typedef struct __gnb_bearer_context
{
	uint64_t gNB_CU_UP__UE_E1AP_ID;
	uint64_t gNB_CU_CP__UE_E1AP_ID;
	
} __gnb_bearer_context_t;
 


typedef struct __gnb_cu_up_supported_plmn 
{
		u_char PLMN[4];

} __gnb_cu_up_supported_plmn_t;


typedef struct __gnb_cu_up 
{
	uint32_t 			ID;
	__si_string140_t 	Name;

	char e1ap_ips[4][20];
	uint32_t e1ap_ips_count;
	uint32_t e1ap_port;
	
	uint8_t				TransactionID;
	pthread_mutex_t		TransactionIDLock;

	__gnb_cu_up_supported_plmn_t supported_plmn[maxnoofSPLMNs_const];
	int supported_plmn_count;

	uint32_t BearerContextCount;
	si_sirik_pool_t * bearer_context__pool;
	
	char LogPath[249];

} __gnb_cu_up_t;


__gnb_cu_up_t * __gnb_cu_up;



#endif


