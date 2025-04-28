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
#include "gNB-CU-UP.h"
#include "jansson.h"
#include "sirik_core.h"


__gnb_cu_up_t * __gnb_cu_up = NULL;


void E1AP_Handle__GNB_CU_CP_E1Setup_ProcedureCode( SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupRequest * obj_GNB_CU_CP_E1SetupRequest, SI_E1APNode * ngNode)
{
	SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupResponse * obj_GNB_CU_CP_E1SetupResponse = (SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupResponse*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupResponse));
	memset( obj_GNB_CU_CP_E1SetupResponse, 0, sizeof( SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupResponse));

	obj_GNB_CU_CP_E1SetupResponse->transactionID = obj_GNB_CU_CP_E1SetupRequest->transactionID;
	obj_GNB_CU_CP_E1SetupResponse->transactionID_isset = 1;

	obj_GNB_CU_CP_E1SetupResponse->gNBCUUPID = __gnb_cu_up->ID;
	obj_GNB_CU_CP_E1SetupResponse->gNBCUUPID_isset = 1;

	obj_GNB_CU_CP_E1SetupResponse->cNSupport = CNSupport_c_5gc_val;
	obj_GNB_CU_CP_E1SetupResponse->cNSupport_isset = 1;

	if( __gnb_cu_up->Name.isset == 1)
	{
		__si_e1ap_init_GNB_CU_UP_Name2( &obj_GNB_CU_CP_E1SetupResponse->gNBCUUPName, __gnb_cu_up->Name.val, __gnb_cu_up->Name.len);
		obj_GNB_CU_CP_E1SetupResponse->gNBCUUPName_isset = 1;
	}
	


	if( __gnb_cu_up->supported_plmn_count > 0)
	{
		__si_e1ap_init_SupportedPLMNs_List( &obj_GNB_CU_CP_E1SetupResponse->supportedPLMNs);
			
		int i = 0;
		
		for( i = 0; i < __gnb_cu_up->supported_plmn_count; i++)
		{
			SI_E1AP_DT_SupportedPLMNs_Item * obj_SupportedPLMNs_Item = (SI_E1AP_DT_SupportedPLMNs_Item*) __si_allocM( sizeof(SI_E1AP_DT_SupportedPLMNs_Item));
			memset( obj_SupportedPLMNs_Item, 0, sizeof( SI_E1AP_DT_SupportedPLMNs_Item));

			__si_e1ap_init_PLMN_Identity2( &obj_SupportedPLMNs_Item->pLMN_Identity, __gnb_cu_up->supported_plmn[i].PLMN, 3);

			obj_SupportedPLMNs_Item->isPresent_slice_Support_List = 0;
			obj_SupportedPLMNs_Item->isPresent_nR_CGI_Support_List = 0;
			obj_SupportedPLMNs_Item->isPresent_qoS_Parameters_Support_List = 0;

			__si_linked_list_add( obj_GNB_CU_CP_E1SetupResponse->supportedPLMNs->SupportedPLMNs_Item, (uint8_t*)obj_SupportedPLMNs_Item);
		}
			
		obj_GNB_CU_CP_E1SetupResponse->supportedPLMNs_isset = 1;
	}

	__si_e1ap_send_GNB_CU_CP_E1SetupResponse( obj_GNB_CU_CP_E1SetupResponse, ngNode);
	__si_e1ap_memfree_pdu_GNB_CU_CP_E1SetupResponse( obj_GNB_CU_CP_E1SetupResponse);	
}


void E1AP_ReceiveMessage( uint8_t procedureCode, uint8_t messageType, void * msg, SI_E1APNode * ngNode)
{
	switch( procedureCode)
	{
		case __si_e1ap__id_gNB_CU_CP_E1Setup_ProcedureCode:
			{
				E1AP_Handle__GNB_CU_CP_E1Setup_ProcedureCode( (SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupRequest*)msg, ngNode);
			}
			break;
		default:
			printf("received message procedureCode=%d Type=%d\n", procedureCode, messageType);
			break;
	}	
}


int gnb_cu_up__init_config( int argc, char* argv[])
{
	json_error_t error;
	memset( &error, 0, sizeof( json_error_t));
	json_t * json_config = json_load_file( argv[1], 0, &error);
	
	if(!json_config)
	{
		printf("error in json %s file at line=%d column=%d position=%d  %d\n", argv[1], error.line, error.column, error.position, __LINE__);
		return 0;
	}
	
	json_t * json_id = json_object_get( json_config, "ID");
	
	if(json_id)
	{
		__gnb_cu_up->ID = json_integer_value( json_id);
	}
	
	json_t * json_bearercontextcount = json_object_get( json_config, "BearerContextCount");
	
	if(json_bearercontextcount)
	{
		__gnb_cu_up->BearerContextCount = json_integer_value( json_bearercontextcount);
	}
	else
	{
		__gnb_cu_up->BearerContextCount = 1000;
	}
	
	

	
	json_t * json_name = json_object_get( json_config, "Name");
	
	if( json_name)
	{
		int vl = json_string_length( json_name);
		char * v = (char*)json_string_value( json_name);		
	
		if( vl > 0)
		{
			memcpy( __gnb_cu_up->Name.val, v, vl);
			__gnb_cu_up->Name.len 		= vl;
			__gnb_cu_up->Name.isset		= 1;;			
		}
	}
	
	
	json_t * json_log_path = json_object_get( json_config, "Log_Path");
	
	if( json_log_path)
	{
		int vl = json_string_length( json_log_path);
		char * v = (char*)json_string_value( json_log_path);		
	
		if( vl > 0)
		{
			memcpy( __gnb_cu_up->LogPath, v, vl);
		}
		else
		{
			memcpy( __gnb_cu_up->LogPath, "./logs/", 7);
		}
	}
	else
	{
		memcpy( __gnb_cu_up->LogPath, "./logs/", 7);
	}
	
	
	json_t * json_e1ap = json_object_get( json_config, "E1AP_Server");

	
	if( json_e1ap)
	{
		json_t * json_e1ap_ips = json_object_get( json_e1ap, "IPs");
		
		if( json_e1ap_ips)
		{
			if( json_is_array(json_e1ap_ips))
			{
				int ip_count = json_array_size( json_e1ap_ips);
				int i = 0;
				
				for( i = 0; i < ip_count; i++)
				{
					json_t * ip = json_array_get( json_e1ap_ips, i);
					
					if( ip)
					{
						int vl = json_string_length( ip);
						char * v = (char*)json_string_value( ip);
						
						if( vl > 0)
						{
							memcpy( __gnb_cu_up->e1ap_ips[__gnb_cu_up->e1ap_ips_count], v, vl);
							__gnb_cu_up->e1ap_ips_count++;
						}
					}	
				}
			}
		}
		
		
		json_t * json_port = json_object_get( json_e1ap, "Port");
	
		if(json_port)
		{
			__gnb_cu_up->e1ap_port = json_integer_value( json_port);
		}
	}
	
	
	
	json_t * json_supported_plmns = json_object_get( json_config, "Supported_PLMNs");
	
	if( json_supported_plmns)
	{
		if( json_is_array(json_supported_plmns))
		{
			int json_supported_plmns_count = json_array_size( json_supported_plmns);
			int i = 0;
			
			for( i = 0; i < json_supported_plmns_count; i++)
			{
				json_t * plmn = json_array_get( json_supported_plmns, i);
				
				if( plmn)
				{
					json_t * plmn_id = json_object_get( plmn, "PLMN-ID");
					
					
					if( plmn_id > 0)
					{
						int vl = json_string_length( plmn_id);
						char * v = (char*)json_string_value( plmn_id);
						
						if( vl > 0 && __gnb_cu_up->supported_plmn_count < maxnoofSPLMNs_const)
						{
							__si_ascii_to_hex( v, vl, __gnb_cu_up->supported_plmn[__gnb_cu_up->supported_plmn_count].PLMN, 3);
							__gnb_cu_up->supported_plmn_count++;
						}
					}	
				}
			}
			
		}
	}
	
	return 1;
}


int main( int argc, char* argv[])
{
	printf( "GNU-CU-CP 1.0.0.0\n");
	

	
	if(!__gnb_cu_up)
	{
		__gnb_cu_up = (__gnb_cu_up_t*)malloc( sizeof(__gnb_cu_up_t));
		memset( __gnb_cu_up, 0, sizeof(__gnb_cu_up_t));
		
		if( gnb_cu_up__init_config( argc, argv) == 0)
		{
			printf("init config failed\n");
			exit(0);
		}

		if( __gnb_cu_up->e1ap_ips_count == 0)
		{
			printf("E1AP IPs Not Configured\n\n");
			exit(0);			
		}
		
		if( __gnb_cu_up->e1ap_port == 0)
		{
			printf("E1AP Port Not Configured\n");
			exit(0);			
		}
		
		
		__gnb_cu_up->bearer_context__pool = 	__si_pool_create( "bearer_context__pool", sizeof(__gnb_bearer_context_t), __gnb_cu_up->BearerContextCount, 0);

		E1AP__InitStack( __gnb_cu_up->LogPath);
		E1AP__SetHost( __gnb_cu_up->e1ap_ips[0], (strlen( __gnb_cu_up->e1ap_ips[1]) > 0) ? __gnb_cu_up->e1ap_ips[1] : NULL, __gnb_cu_up->e1ap_port);
		E1AP__SetOnMessageRecv( E1AP_ReceiveMessage);
		E1AP__StartStack();
	
		__si_core_wait();
	}

	// cat /proc/net/sctp/eps 
	// lsof -R | grep 
}














