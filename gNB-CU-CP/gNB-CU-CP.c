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
#include "jansson.h"
#include "sirik_core.h"


__gnb_cu_cp_t * __gnb_cu_cp = NULL;




int gnb_cu_cp__init_config( int argc, char* argv[])
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
		__gnb_cu_cp->ID = json_integer_value( json_id);
	}
	
	json_t * json_bearercontextcount = json_object_get( json_config, "BearerContextCount");
	
	if(json_bearercontextcount)
	{
		__gnb_cu_cp->BearerContextCount = json_integer_value( json_bearercontextcount);
	}
	else
	{
		__gnb_cu_cp->BearerContextCount = 1000;
	}



	json_t * json_name = json_object_get( json_config, "Name");
	
	if( json_name)
	{
		int vl = json_string_length( json_name);
		char * v = (char*)json_string_value( json_name);		
	
		if( vl > 0)
		{
			memcpy( __gnb_cu_cp->Name.val, v, vl);
			__gnb_cu_cp->Name.len 		= vl;
			__gnb_cu_cp->Name.isset		= 1;;			
		}
	}


	json_t * json_log_path = json_object_get( json_config, "Log_Path");
	
	if( json_log_path)
	{
		int vl = json_string_length( json_log_path);
		char * v = (char*)json_string_value( json_log_path);		
	
		if( vl > 0)
		{
			memcpy( __gnb_cu_cp->LogPath, v, vl);
		}
		else
		{
			memcpy( __gnb_cu_cp->LogPath, "./logs/", 7);
		}
	}
	else
	{
		memcpy( __gnb_cu_cp->LogPath, "./logs/", 7);
	}



	json_t * json_f1ap = json_object_get( json_config, "F1AP_Server");

	
	if( json_f1ap)
	{
		json_t * json_f1ap_ips = json_object_get( json_f1ap, "IPs");
		
		if( json_f1ap_ips)
		{
			if( json_is_array(json_f1ap_ips))
			{
				int ip_count = json_array_size( json_f1ap_ips);
				int i = 0;
				
				for( i = 0; i < ip_count; i++)
				{
					json_t * ip = json_array_get( json_f1ap_ips, i);
					
					if( ip)
					{
						int vl = json_string_length( ip);
						char * v = (char*)json_string_value( ip);
						
						if( vl > 0)
						{
							memcpy( __gnb_cu_cp->f1ap_ips[__gnb_cu_cp->f1ap_ips_count], v, vl);
							__gnb_cu_cp->f1ap_ips_count++;
						}
					}	
				}
			}
		}
		
		
		json_t * json_port = json_object_get( json_f1ap, "Port");
	
		if(json_port)
		{
			__gnb_cu_cp->f1ap_port = json_integer_value( json_port);
		}
	}



	json_t * json_e1ap_servers 	= json_object_get( json_config, "E1AP_Servers");
	__gnb_cu_cp->E1AP_NodeCount = 0;
	
	if(json_e1ap_servers)
	{
		if( json_is_array(json_e1ap_servers))
		{
			int json_e1ap_servers_count = json_array_size( json_e1ap_servers);
			int i = 0;

			for( i = 0; i < json_e1ap_servers_count; i++)
			{
				json_t * e1ap = json_array_get( json_e1ap_servers, i);
				
				if( e1ap && __gnb_cu_cp->E1AP_NodeCount < 10)
				{
					json_t * json_e1ap_ips = json_object_get( e1ap, "IPs");
					json_t * json_e1ap_port = json_object_get( e1ap, "Port");
					
					if( json_e1ap_ips && json_e1ap_port)
					{
						__gnb_cu_up_t * gnb_cu_up = &__gnb_cu_cp->E1AP_Node[__gnb_cu_cp->E1AP_NodeCount];
	
						if( json_is_array(json_e1ap_ips))
						{
							int ip_count = json_array_size( json_e1ap_ips);
							int i = 0;
							
							for( i = 0; i < ip_count; i++)
							{
								json_t * ip = json_array_get( json_e1ap_ips, i);
								
								if( ip && gnb_cu_up->e1ap_ips_count < 4)
								{
									int vl = json_string_length( ip);
									char * v = (char*)json_string_value( ip);
									
									if( vl > 0)
									{
										memcpy( gnb_cu_up->e1ap_ips[gnb_cu_up->e1ap_ips_count], v, vl);
										gnb_cu_up->e1ap_ips_count++;
									}
								}
							}	
						}
					
	
						gnb_cu_up->e1ap_port = json_integer_value( json_e1ap_port);
						__gnb_cu_cp->E1AP_NodeCount++;
				
					}
				}
			}
			
		}
	}
	
}





void Init__F1AP();

int main( int argc, char* argv[])
{
	printf( "GNU-CU-CP 1.0.0.0\n");
	
	if(!__gnb_cu_cp)
	{
		__gnb_cu_cp = (__gnb_cu_cp_t*)malloc( sizeof(__gnb_cu_cp_t));
		memset( __gnb_cu_cp, 0, sizeof(__gnb_cu_cp_t));
		
		if( gnb_cu_cp__init_config( argc, argv) == 0)
		{
			printf("init config failed\n");
			exit(0);
		}
		
		if( __gnb_cu_cp->f1ap_ips_count == 0)
		{
			printf("F1AP IPs Not Configured\n\n");
			exit(0);			
		}
		
		if( __gnb_cu_cp->f1ap_port == 0)
		{
			printf("F1AP Port Not Configured\n");
			exit(0);			
		}

		__gnb_cu_cp->duHead 	= NULL;
		__gnb_cu_cp->duCurrent 	= NULL;
		pthread_mutex_init( &__gnb_cu_cp->duLock, NULL);		
		
		__gnb_cu_cp->idProvider 			= __si_idProvider_create( 1001, UINT32_MAX - __gnb_cu_cp->BearerContextCount, __gnb_cu_cp->BearerContextCount);
		__gnb_cu_cp->bearer_context__pool 	= __si_pool_create( "bearer_context__pool", sizeof(__gnb_bearer_context_t), __gnb_cu_cp->BearerContextCount, 0);

		Init__E1AP();
		Init__F1AP();

		__si_core_wait();
	}

	// cat /proc/net/sctp/eps 
	// lsof -R | grep 
}