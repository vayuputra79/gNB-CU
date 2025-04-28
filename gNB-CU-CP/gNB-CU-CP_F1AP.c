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

#include "F1AP_18.4.h"
#include "F1AP_18.4_Stack.h"
#include "gNB-CU-CP.h"


void F1AP_Send__F1SetupFailure( SI_F1AP_DT_PDU_F1SetupRequest * objF1SetupRequest, SI_F1APNode * ngNode)
{
	SI_F1AP_DT_PDU_F1SetupFailure * objF1SetupFailure = (SI_F1AP_DT_PDU_F1SetupFailure*)__si_allocM( sizeof(SI_F1AP_DT_PDU_F1SetupFailure));
	memset( objF1SetupFailure, 0, sizeof(SI_F1AP_DT_PDU_F1SetupFailure));
	
	objF1SetupFailure->transactionID			= objF1SetupRequest->transactionID;
	objF1SetupFailure->transactionID_isset		= 1;

	__si_f1ap_init_Cause( &objF1SetupFailure->cause);
	objF1SetupFailure->cause->SelectedChoice 	= 0;
	objF1SetupFailure->cause->u.radioNetwork 	= CauseRadioNetwork_unspecified_val;
	objF1SetupFailure->cause_isset 				= 1;
	
	// objF1SetupFailure->timeToWait				= 5;
	// objF1SetupFailure->timeToWait_isset 		= 1;


	__si_f1ap_send_F1SetupFailure( objF1SetupFailure, ngNode);
	__si_f1ap_memfree_pdu_F1SetupFailure( objF1SetupFailure);	
}


void F1AP_Handle__F1SetupRequest( SI_F1AP_DT_PDU_F1SetupRequest * objF1SetupRequest, SI_F1APNode * ngNode)
{
	// if( objF1SetupRequest->gNBDUID_isset == 1)
	// {
		// F1AP_Send__F1SetupFailure( objF1SetupRequest, ngNode);
		// __si_f1ap_memfree_pdu_F1SetupRequest( objF1SetupRequest);
		// return;
	// }
	

	SI_F1AP_DT_PDU_F1SetupResponse * objF1SetupResponse = (SI_F1AP_DT_PDU_F1SetupResponse *)__si_allocM( sizeof(SI_F1AP_DT_PDU_F1SetupResponse));
	memset( objF1SetupResponse, 0, sizeof(SI_F1AP_DT_PDU_F1SetupResponse));
	
	objF1SetupResponse->transactionID 			= objF1SetupRequest->transactionID;
	objF1SetupResponse->transactionID_isset 	= 1;

	__si_f1ap_init_RRC_Version( &objF1SetupResponse->gNBCURRCVersion);
	__si_f1ap_init_RRCVersion_latest_RRC_Version2( &objF1SetupResponse->gNBCURRCVersion->latest_RRC_Version, "\xFF", 1, 3);
	objF1SetupResponse->gNBCURRCVersion->latest_RRC_Version->bitslen = 3;
	objF1SetupResponse->gNBCURRCVersion_isset	= 1;
	
	
	__gnb_du_t * gnb_du = __gnb_cu_cp->duHead;
	int bFound = 0;

	while(gnb_du)
	{
		if( gnb_du->gNBDUID == objF1SetupRequest->gNBDUID)
		{
			bFound = 1;
			gnb_du->f1Node = ngNode;
			break;
		}
		
		gnb_du = gnb_du->Next;
	}


	if( bFound == 0)
	{
		pthread_mutex_lock( &__gnb_cu_cp->duLock);
		
		gnb_du = (__gnb_du_t*)__si_allocM(sizeof(__gnb_du_t));
		memset( gnb_du, 0, sizeof(__gnb_du_t));
		
		gnb_du->gNBDUID 	= objF1SetupRequest->gNBDUID;
		gnb_du->UEContexts	= __si_linked_list_allocate();
		gnb_du->f1Node		= ngNode;

		if(!__gnb_cu_cp->duHead)
		{
			__gnb_cu_cp->duHead = __gnb_cu_cp->duCurrent = gnb_du;
		}
		else
		{
			__gnb_cu_cp->duCurrent->Next = gnb_du;
			__gnb_cu_cp->duCurrent = gnb_du;
		}
		
		pthread_mutex_unlock( &__gnb_cu_cp->duLock);
	}


	__si_f1ap_send_F1SetupResponse( objF1SetupResponse, ngNode);
	__si_f1ap_memfree_pdu_F1SetupResponse( objF1SetupResponse);
	__si_f1ap_memfree_pdu_F1SetupRequest( objF1SetupRequest);
}


void F1AP_Send__UEContextSetupRequest( SI_F1APNode * ngNode)
{
	SI_F1AP_DT_PDU_UEContextSetupRequest * objUEContextSetupRequest = (SI_F1AP_DT_PDU_UEContextSetupRequest *)__si_allocM( sizeof(SI_F1AP_DT_PDU_UEContextSetupRequest));
	memset( objUEContextSetupRequest, 0, sizeof(SI_F1AP_DT_PDU_UEContextSetupRequest));

	objUEContextSetupRequest->gNBCUUEF1APID = 1;
	objUEContextSetupRequest->gNBCUUEF1APID_isset = 1;

	objUEContextSetupRequest->gNBDUUEF1APID = 1;
	objUEContextSetupRequest->gNBDUUEF1APID_isset = 1;

	__si_f1ap_init_NRCGI( &objUEContextSetupRequest->spCellID);
	__si_f1ap_init_PLMN_Identity2( &objUEContextSetupRequest->spCellID->pLMN_Identity, "\x11\x11\x11", 3);
	__si_f1ap_init_NRCellIdentity2( &objUEContextSetupRequest->spCellID->nRCellIdentity, "\x11\x11\x11\x11\x11", 5, 36);
	objUEContextSetupRequest->spCellID_isset;
	
	objUEContextSetupRequest->servCellIndex = 1;
	objUEContextSetupRequest->servCellIndex_isset = 1;
	
	//SI_F1AP_DT_CUtoDURRCInformation * cUtoDURRCInformation;
	__si_f1ap_init_CUtoDURRCInformation( &objUEContextSetupRequest->cUtoDURRCInformation);
	objUEContextSetupRequest->cUtoDURRCInformation_isset = 1;
	
	
	__si_f1ap_send_UEContextSetupRequest( objUEContextSetupRequest, ngNode);
	__si_f1ap_memfree_pdu_UEContextSetupRequest( objUEContextSetupRequest);	
}


void F1AP_Handle__InitialULRRCMessageTransfer( SI_F1AP_DT_PDU_InitialULRRCMessageTransfer * objInitialULRRCMessageTransfer, SI_F1APNode * ngNode)
{
	if( objInitialULRRCMessageTransfer->gNBDUUEF1APID_isset == 0)
	{
		printf("validation error %s|%d\n", __FILE__, __LINE__);
		__si_f1ap_memfree_pdu_InitialULRRCMessageTransfer( objInitialULRRCMessageTransfer);
		return;
	}
	

	if( objInitialULRRCMessageTransfer->nRCGI_isset == 0)
	{
		printf("validation error %s|%d\n", __FILE__, __LINE__);
		__si_f1ap_memfree_pdu_InitialULRRCMessageTransfer( objInitialULRRCMessageTransfer);
		return;
	}

	
	if( objInitialULRRCMessageTransfer->cRNTI_isset == 0)
	{
		printf("validation error %s|%d\n", __FILE__, __LINE__);
		__si_f1ap_memfree_pdu_InitialULRRCMessageTransfer( objInitialULRRCMessageTransfer);
		return;
	}
	
	
	if( objInitialULRRCMessageTransfer->rRCContainer_isset == 0)
	{
		printf("validation error %s|%d\n", __FILE__, __LINE__);
		__si_f1ap_memfree_pdu_InitialULRRCMessageTransfer( objInitialULRRCMessageTransfer);
		return;
	}
	
	
	if( objInitialULRRCMessageTransfer->transactionID_isset == 0)
	{
		printf("validation error %s|%d\n", __FILE__, __LINE__);
		__si_f1ap_memfree_pdu_InitialULRRCMessageTransfer( objInitialULRRCMessageTransfer);
		return;
	}
	
	__gnb_bearer_context_t * bContext = (__gnb_bearer_context_t*)__si_pool_allocate( __gnb_cu_cp->bearer_context__pool);
	memset( bContext, 0, sizeof( __gnb_bearer_context_t));
	
	bContext->gNB_CU_CP__UE_ID		 	= (__si_pool_index( (uint8_t*)bContext) + 1001);
	bContext->gNB_CU_UP__UE_E1AP_ID		= 0;
	bContext->gNB_DU_CP__UE_F1AP_ID		= objInitialULRRCMessageTransfer->gNBDUUEF1APID;
	
	
	// printf( "gNB_CU_CP__UE_ID=%lu gNB_DU_CP__UE_F1AP_ID=%lu  %s|%d\n", 
		// bContext->gNB_CU_CP__UE_ID, bContext->gNB_DU_CP__UE_F1AP_ID, __FILE__, __LINE__);
	
	
	SI_F1AP_DT_PDU_DLRRCMessageTransfer * objDLRRCMessageTransfer = (SI_F1AP_DT_PDU_DLRRCMessageTransfer *)__si_allocM( sizeof(SI_F1AP_DT_PDU_DLRRCMessageTransfer));
	memset( objDLRRCMessageTransfer, 0, sizeof(SI_F1AP_DT_PDU_DLRRCMessageTransfer));
	
	objDLRRCMessageTransfer->gNBDUUEF1APID 			= objInitialULRRCMessageTransfer->gNBDUUEF1APID;
	objDLRRCMessageTransfer->gNBDUUEF1APID_isset 	= 1;

	objDLRRCMessageTransfer->gNBCUUEF1APID 			= bContext->gNB_CU_CP__UE_ID;
	objDLRRCMessageTransfer->gNBCUUEF1APID_isset 	= 1;

	objDLRRCMessageTransfer->sRBID 					= 1;
	objDLRRCMessageTransfer->sRBID_isset 			= 1;
	
	unsigned char bytes[] = {0x6c, 0x0, 0x28, 0x2a, 0xa3, 0x63, 0x5a, 0x12, 0xd8};
	__si_f1ap_init_RRCContainer2( &objDLRRCMessageTransfer->rRCContainer, bytes, 9);
	objDLRRCMessageTransfer->rRCContainer_isset = 1;
	
	__si_f1ap_send_DLRRCMessageTransfer( objDLRRCMessageTransfer, ngNode);
	__si_f1ap_memfree_pdu_DLRRCMessageTransfer( objDLRRCMessageTransfer);
	__si_f1ap_memfree_pdu_InitialULRRCMessageTransfer( objInitialULRRCMessageTransfer);
}



void F1AP_Send__UEContextReleaseCommand( SI_F1APNode * ngNode)
{
	SI_F1AP_DT_PDU_UEContextReleaseCommand * objUEContextReleaseCommand = (SI_F1AP_DT_PDU_UEContextReleaseCommand *)__si_allocM( sizeof(SI_F1AP_DT_PDU_UEContextReleaseCommand));
	memset( objUEContextReleaseCommand, 0, sizeof(SI_F1AP_DT_PDU_UEContextReleaseCommand));
	
	objUEContextReleaseCommand->gNBCUUEF1APID = 1;
	objUEContextReleaseCommand->gNBCUUEF1APID_isset = 1;

	objUEContextReleaseCommand->gNBDUUEF1APID = 1;
	objUEContextReleaseCommand->gNBDUUEF1APID_isset = 1;

	//SI_F1AP_DT_Cause * cause;
	__si_f1ap_init_Cause( &objUEContextReleaseCommand->cause);
	objUEContextReleaseCommand->cause->SelectedChoice = 0;
	objUEContextReleaseCommand->cause->u.radioNetwork = CauseRadioNetwork_unspecified_val;
	objUEContextReleaseCommand->cause_isset = 1;
	
	__si_f1ap_send_UEContextReleaseCommand( objUEContextReleaseCommand, ngNode);
	__si_f1ap_memfree_pdu_UEContextReleaseCommand( objUEContextReleaseCommand);	
	//printf("  Sent UEContextReleaseCommand\n");
}


void F1AP_Handle__ULRRCMessageTransfer( SI_F1AP_DT_PDU_ULRRCMessageTransfer * objULRRCMessageTransfer, SI_F1APNode * ngNode)
{
	F1AP_Send__UEContextSetupRequest( ngNode);
	__si_f1ap_memfree_pdu_ULRRCMessageTransfer( objULRRCMessageTransfer);
}


void F1AP_Handle__UEContextReleaseRequest( SI_F1AP_DT_PDU_UEContextReleaseRequest * objUEContextReleaseRequest, SI_F1APNode * ngNode)
{
	F1AP_Send__UEContextReleaseCommand( ngNode);
	__si_f1ap_memfree_pdu_UEContextReleaseRequest( objUEContextReleaseRequest);	
}


void F1AP_ReceiveMessage( uint8_t procedureCode, uint8_t messageType, void * msg, SI_F1APNode * ngNode)
{
	printf("procedureCode=%d   messageType=%d   %s|%d\n", procedureCode, messageType, __FILE__, __LINE__);
	
	switch( procedureCode)
	{
		case id_F1Setup_ProcedureCode:
			F1AP_Handle__F1SetupRequest( (SI_F1AP_DT_PDU_F1SetupRequest*)msg, ngNode);
			break;
		case id_InitialULRRCMessageTransfer_ProcedureCode:
			F1AP_Handle__InitialULRRCMessageTransfer( (SI_F1AP_DT_PDU_InitialULRRCMessageTransfer*)msg, ngNode);
			break;
		case id_ULRRCMessageTransfer_ProcedureCode:
			//F1AP_Handle__ULRRCMessageTransfer( (SI_F1AP_DT_PDU_ULRRCMessageTransfer*)msg, ngNode);
			break;
		case id_UEContextRelease_ProcedureCode:
			break;
		case id_UEContextReleaseRequest_ProcedureCode:
			//printf("  handle UEContextRelease\n");
			//F1AP_Handle__UEContextReleaseRequest( (SI_F1AP_DT_PDU_UEContextReleaseRequest*)msg, ngNode);
			break;
		default:
			printf("procedureCode=%d   messageType=%d   %s|%d\n", procedureCode, messageType, __FILE__, __LINE__);
			break;
	}
}


void Init__F1AP()
{
	F1AP__InitStack( __gnb_cu_cp->LogPath);
	F1AP__SetHost( __gnb_cu_cp->f1ap_ips[0], (strlen( __gnb_cu_cp->f1ap_ips[1]) > 0) ? __gnb_cu_cp->f1ap_ips[1] : NULL, __gnb_cu_cp->f1ap_port);
	F1AP__SetOnMessageRecv( F1AP_ReceiveMessage);
	F1AP__StartStack();
}
