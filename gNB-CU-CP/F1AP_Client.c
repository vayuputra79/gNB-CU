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
#include "F1AP_18.4.h"
#include "F1AP_18.4_Stack.h"




int f1ap_server_onconnect( SI_Socket * siSocket)
{
	printf("Connected\n");

	SI_F1APNode * f1Node = (SI_F1APNode *) siSocket->transportEng;

	if(!f1Node)
	{
		__si_malloc2( sizeof( SI_F1APNode), (uint8_t **)&f1Node);
		siSocket->transportEng 	= (uint8_t *) f1Node;
		f1Node->transportEng 	= (uint8_t *) siSocket;
	}
	f1Node->siSocket = siSocket;
	


	SI_F1AP_DT_PDU_F1SetupRequest * oF1SetupRequest = (SI_F1AP_DT_PDU_F1SetupRequest *) __si_allocM( sizeof( SI_F1AP_DT_PDU_F1SetupRequest)); 
	memset( oF1SetupRequest, 0, sizeof( SI_F1AP_DT_PDU_F1SetupRequest));
	
	oF1SetupRequest->transactionID = 7;
	oF1SetupRequest->transactionID_isset = 1;

	oF1SetupRequest->gNBDUID = 2;
	oF1SetupRequest->gNBDUID_isset = 1;
	
	__si_f1ap_init_RRC_Version( &oF1SetupRequest->gNBDURRCVersion);
	oF1SetupRequest->gNBDURRCVersion_isset = 1;

	__si_f1ap_init_RRCVersion_latest_RRC_Version2( &oF1SetupRequest->gNBDURRCVersion->latest_RRC_Version, "\xFF", 1, 3);


	__si_f1ap_send_F1SetupRequest( oF1SetupRequest, f1Node);
	__si_f1ap_memfree_pdu_F1SetupRequest( oF1SetupRequest);

	return 0;
}


void F1AP_Send__InitialULRRCMessageTransfer( SI_F1APNode * f1Node)
{
	SI_F1AP_DT_PDU_InitialULRRCMessageTransfer * objInitialULRRCMessageTransfer = (SI_F1AP_DT_PDU_InitialULRRCMessageTransfer *)__si_allocM(sizeof(SI_F1AP_DT_PDU_InitialULRRCMessageTransfer));
	memset( objInitialULRRCMessageTransfer, 0, sizeof(SI_F1AP_DT_PDU_InitialULRRCMessageTransfer));
	
	objInitialULRRCMessageTransfer->gNBDUUEF1APID = 1;
	objInitialULRRCMessageTransfer->gNBDUUEF1APID_isset = 1;
	
	objInitialULRRCMessageTransfer->cRNTI = 1;
	objInitialULRRCMessageTransfer->cRNTI_isset = 1;

	//SI_F1AP_DT_NRCGI * nRCGI;
	//objInitialULRRCMessageTransfer->nRCGI
	// SI_F1AP_DT_PLMN_Identity * pLMN_Identity;
	// SI_F1AP_DT_NRCellIdentity * nRCellIdentity;
	__si_f1ap_init_NRCGI( &objInitialULRRCMessageTransfer->nRCGI);
	__si_f1ap_init_PLMN_Identity2( &objInitialULRRCMessageTransfer->nRCGI->pLMN_Identity, "\x11\x11\x11", 3);
	__si_f1ap_init_NRCellIdentity2( &objInitialULRRCMessageTransfer->nRCGI->nRCellIdentity, "\x11\x11\x11\x11\x11", 5, 36);
	objInitialULRRCMessageTransfer->nRCGI_isset = 1;

	// ID = id-RRCContainer, PRESENCE = mandatory L:10856
	//SI_F1AP_DT_RRCContainer * rRCContainer;
	unsigned char bytes[] = {0x15, 0x0, 0xf9, 0x0, 0x60, 0x29, 0x23, 0x8, 0x1a, 0x78, 0xc1, 0x80, 0x2f, 0xa0, 0xd9, 0xf2, 0xd8, 0x36, 0x0, 0x0, 0x48};
	__si_f1ap_init_RRCContainer2( &objInitialULRRCMessageTransfer->rRCContainer, bytes, 21);
	objInitialULRRCMessageTransfer->rRCContainer_isset = 1;
	
	objInitialULRRCMessageTransfer->transactionID = 1;
	objInitialULRRCMessageTransfer->transactionID_isset = 1;
	
	__si_f1ap_send_InitialULRRCMessageTransfer( objInitialULRRCMessageTransfer, f1Node);
	__si_f1ap_memfree_pdu_InitialULRRCMessageTransfer( objInitialULRRCMessageTransfer);		
}


void F1AP_Send__ULRRCMessageTransfer( SI_F1APNode * f1Node)
{
	SI_F1AP_DT_PDU_ULRRCMessageTransfer * objULRRCMessageTransfer = (SI_F1AP_DT_PDU_ULRRCMessageTransfer *)__si_allocM(sizeof(SI_F1AP_DT_PDU_ULRRCMessageTransfer));
	memset( objULRRCMessageTransfer, 0, sizeof(SI_F1AP_DT_PDU_ULRRCMessageTransfer));
	
	objULRRCMessageTransfer->gNBDUUEF1APID = 1;
	objULRRCMessageTransfer->gNBDUUEF1APID_isset = 1;

	objULRRCMessageTransfer->gNBCUUEF1APID = 1;
	objULRRCMessageTransfer->gNBCUUEF1APID_isset = 1;

	objULRRCMessageTransfer->sRBID = 1;
	objULRRCMessageTransfer->sRBID_isset = 1;
	
	unsigned char bytes[] = {0x6c, 0x0, 0x28, 0x2a, 0xa3, 0x63, 0x5a, 0x12, 0xd8};
	__si_f1ap_init_RRCContainer2( &objULRRCMessageTransfer->rRCContainer, bytes, 9);
	objULRRCMessageTransfer->rRCContainer_isset = 1;

	
	__si_f1ap_send_ULRRCMessageTransfer( objULRRCMessageTransfer, f1Node);
	__si_f1ap_memfree_pdu_ULRRCMessageTransfer( objULRRCMessageTransfer);	
}


void F1AP_Send__RRCDeliveryReport( SI_F1APNode * f1Node)
{
	SI_F1AP_DT_PDU_RRCDeliveryReport * objRRCDeliveryReport = (SI_F1AP_DT_PDU_RRCDeliveryReport*)__si_allocM(sizeof(SI_F1AP_DT_PDU_RRCDeliveryReport));
	memset( objRRCDeliveryReport, 0, sizeof(SI_F1AP_DT_PDU_RRCDeliveryReport));

	objRRCDeliveryReport->gNBDUUEF1APID = 1;
	objRRCDeliveryReport->gNBDUUEF1APID_isset = 1;

	objRRCDeliveryReport->gNBCUUEF1APID = 1;
	objRRCDeliveryReport->gNBCUUEF1APID_isset = 1;

	objRRCDeliveryReport->sRBID = 1;
	objRRCDeliveryReport->sRBID_isset = 1;
	
	__si_f1ap_init_RRCDeliveryStatus( &objRRCDeliveryReport->rRCDeliveryStatus);
	objRRCDeliveryReport->rRCDeliveryStatus->delivery_status = 1;
	objRRCDeliveryReport->rRCDeliveryStatus->triggering_message = 1;
	objRRCDeliveryReport->rRCDeliveryStatus_isset = 1;

	__si_f1ap_send_RRCDeliveryReport( objRRCDeliveryReport, f1Node);
	__si_f1ap_memfree_pdu_RRCDeliveryReport( objRRCDeliveryReport);	
}


void F1AP_Send__AccessSuccess( SI_F1APNode * f1Node)
{
	SI_F1AP_DT_PDU_AccessSuccess * objAccessSuccess = (SI_F1AP_DT_PDU_AccessSuccess*)__si_allocM(sizeof(SI_F1AP_DT_PDU_AccessSuccess));
	memset( objAccessSuccess, 0, sizeof(SI_F1AP_DT_PDU_AccessSuccess));

	objAccessSuccess->gNBCUUEF1APID = 1;
	objAccessSuccess->gNBCUUEF1APID_isset = 1;

	objAccessSuccess->gNBDUUEF1APID = 1;
	objAccessSuccess->gNBDUUEF1APID_isset = 1;

	__si_f1ap_init_NRCGI( &objAccessSuccess->nRCGI);
	__si_f1ap_init_PLMN_Identity2( &objAccessSuccess->nRCGI->pLMN_Identity, "\x11\x11\x11", 3);
	__si_f1ap_init_NRCellIdentity2( &objAccessSuccess->nRCGI->nRCellIdentity, "\x11\x11\x11\x11\x11", 5, 36);
	objAccessSuccess->nRCGI_isset = 1;
	
	__si_f1ap_send_AccessSuccess( objAccessSuccess, f1Node);
	__si_f1ap_memfree_pdu_AccessSuccess( objAccessSuccess);	
}




void F1AP_Handle__F1Setup_SuccessResponse( SI_F1AP_DT_PDU_F1SetupResponse * objF1SetupResponse, SI_F1APNode * f1Node)
{
	F1AP_Send__InitialULRRCMessageTransfer( f1Node);
	// F1AP_Send__ULRRCMessageTransfer( f1Node);
	// F1AP_Send__RRCDeliveryReport( f1Node);
	// F1AP_Send__AccessSuccess( f1Node);
}


void F1AP_Send__UEContextSetupResponse( SI_F1APNode * f1Node)
{
	SI_F1AP_DT_PDU_UEContextSetupResponse* objUEContextSetupResponse = (SI_F1AP_DT_PDU_UEContextSetupResponse *)__si_allocM( sizeof(SI_F1AP_DT_PDU_UEContextSetupResponse));
	memset( objUEContextSetupResponse, 0, sizeof(SI_F1AP_DT_PDU_UEContextSetupResponse));

	objUEContextSetupResponse->gNBCUUEF1APID = 1;
	objUEContextSetupResponse->gNBCUUEF1APID_isset = 1;

	objUEContextSetupResponse->gNBDUUEF1APID = 1;
	objUEContextSetupResponse->gNBDUUEF1APID_isset = 1;

	__si_f1ap_init_DUtoCURRCInformation( &objUEContextSetupResponse->dUtoCURRCInformation);
	objUEContextSetupResponse->dUtoCURRCInformation_isset = 1;

	__si_f1ap_send_UEContextSetupResponse( objUEContextSetupResponse, f1Node);
	__si_f1ap_memfree_pdu_UEContextSetupResponse( objUEContextSetupResponse);	
}


void F1AP_Send__UEContextSetupFailure( SI_F1APNode * f1Node)
{
	SI_F1AP_DT_PDU_UEContextSetupFailure * objUEContextSetupFailure = (SI_F1AP_DT_PDU_UEContextSetupFailure *)__si_allocM( sizeof(SI_F1AP_DT_PDU_UEContextSetupFailure));
	memset( objUEContextSetupFailure, 0, sizeof(SI_F1AP_DT_PDU_UEContextSetupFailure));

	objUEContextSetupFailure->gNBCUUEF1APID = 1;
	objUEContextSetupFailure->gNBCUUEF1APID_isset = 1;

	objUEContextSetupFailure->gNBDUUEF1APID = 1;
	objUEContextSetupFailure->gNBDUUEF1APID_isset = 1;

	//SI_F1AP_DT_Cause * cause;
	__si_f1ap_init_Cause( &objUEContextSetupFailure->cause);
	objUEContextSetupFailure->cause->SelectedChoice = 0;
	objUEContextSetupFailure->cause->u.radioNetwork = CauseRadioNetwork_unspecified_val;
	objUEContextSetupFailure->cause_isset = 1;


	__si_f1ap_send_UEContextSetupFailure( objUEContextSetupFailure, f1Node);
	__si_f1ap_memfree_pdu_UEContextSetupFailure( objUEContextSetupFailure);
}


void F1AP_Send__UEContextReleaseRequest( SI_F1APNode * f1Node)
{
	SI_F1AP_DT_PDU_UEContextReleaseRequest * objUEContextReleaseRequest = (SI_F1AP_DT_PDU_UEContextReleaseRequest *)__si_allocM( sizeof(SI_F1AP_DT_PDU_UEContextReleaseRequest));
	memset( objUEContextReleaseRequest, 0, sizeof(SI_F1AP_DT_PDU_UEContextReleaseRequest));

	objUEContextReleaseRequest->gNBCUUEF1APID = 1;
	objUEContextReleaseRequest->gNBCUUEF1APID_isset = 1;

	objUEContextReleaseRequest->gNBDUUEF1APID = 1;
	objUEContextReleaseRequest->gNBDUUEF1APID_isset = 1;

	//SI_F1AP_DT_Cause * cause;
	__si_f1ap_init_Cause( &objUEContextReleaseRequest->cause);
	objUEContextReleaseRequest->cause->SelectedChoice = 0;
	objUEContextReleaseRequest->cause->u.radioNetwork = CauseRadioNetwork_unspecified_val;
	objUEContextReleaseRequest->cause_isset = 1;

	__si_f1ap_send_UEContextReleaseRequest( objUEContextReleaseRequest, f1Node);
	__si_f1ap_memfree_pdu_UEContextReleaseRequest( objUEContextReleaseRequest);
}


void F1AP_Send__UEContextReleaseComplete( SI_F1APNode * f1Node)
{
	SI_F1AP_DT_PDU_UEContextReleaseComplete * objUEContextReleaseComplete = (SI_F1AP_DT_PDU_UEContextReleaseComplete *)__si_allocM( sizeof(SI_F1AP_DT_PDU_UEContextReleaseComplete));
	memset( objUEContextReleaseComplete, 0, sizeof(SI_F1AP_DT_PDU_UEContextReleaseComplete));

	objUEContextReleaseComplete->gNBCUUEF1APID = 1;
	objUEContextReleaseComplete->gNBCUUEF1APID_isset = 1;

	objUEContextReleaseComplete->gNBDUUEF1APID = 1;
	objUEContextReleaseComplete->gNBDUUEF1APID_isset = 1;

	__si_f1ap_send_UEContextReleaseComplete( objUEContextReleaseComplete, f1Node);
	__si_f1ap_memfree_pdu_UEContextReleaseComplete( objUEContextReleaseComplete);
}

void F1AP_Handle__UEContextSetupRequest( SI_F1AP_DT_PDU_UEContextSetupRequest * objUEContextSetupRequest, SI_F1APNode * f1Node)
{
	F1AP_Send__UEContextSetupResponse( f1Node);
	F1AP_Send__UEContextSetupFailure( f1Node);
	F1AP_Send__UEContextReleaseRequest( f1Node);
	__si_f1ap_memfree_pdu_UEContextSetupRequest( objUEContextSetupRequest);	
}


void F1AP_Handle__UEContextReleaseCommand( SI_F1AP_DT_PDU_UEContextReleaseCommand * objUEContextReleaseCommand, SI_F1APNode * f1Node)
{
	F1AP_Send__UEContextReleaseComplete( f1Node);
	__si_f1ap_memfree_pdu_UEContextReleaseCommand( objUEContextReleaseCommand);	
}


void F1AP_ReceiveMessage( uint8_t procedureCode, uint8_t messageType, void * msg, SI_F1APNode * f1Node)
{
	printf("Received Message With procedureCode=%u  messageType=%u\n", procedureCode, messageType);

	switch( procedureCode)
	{
		case __si_f1ap__id_Reset_ProcedureCode:
			break;
		case __si_f1ap__id_F1Setup_ProcedureCode:
			//__si_f1ap_debug_pdu_F1SetupFailure( (SI_F1AP_DT_PDU_F1SetupFailure *) msg);
			// printf("Received Message With procedureCode=%u  messageType=%u  |%d\n", procedureCode, messageType, __LINE__);
			
			if( messageType == 2) {
				F1AP_Handle__F1Setup_SuccessResponse( (SI_F1AP_DT_PDU_F1SetupResponse*)msg, f1Node);
			}
			
			break;
		case __si_f1ap__id_ErrorIndication_ProcedureCode:
			break;
		case __si_f1ap__id_gNBDUConfigurationUpdate_ProcedureCode:
			break;
		case __si_f1ap__id_gNBCUConfigurationUpdate_ProcedureCode:
			break;
		case __si_f1ap__id_UEContextSetup_ProcedureCode:
			//F1AP_Handle__UEContextSetupRequest( (SI_F1AP_DT_PDU_UEContextSetupRequest*)msg, f1Node);
			break;
		case __si_f1ap__id_UEContextRelease_ProcedureCode:
			//F1AP_Handle__UEContextReleaseCommand( (SI_F1AP_DT_PDU_UEContextReleaseCommand*)msg, f1Node);
			break;
		case __si_f1ap__id_UEContextModification_ProcedureCode:
			break;
		case __si_f1ap__id_UEContextModificationRequired_ProcedureCode:
			break;
		case __si_f1ap__id_procedure_code_9_not_to_be_used_ProcedureCode:
			break;
		case __si_f1ap__id_UEContextReleaseRequest_ProcedureCode:
			break;
		case __si_f1ap__id_InitialULRRCMessageTransfer_ProcedureCode:
			break;
		case __si_f1ap__id_DLRRCMessageTransfer_ProcedureCode:
			break;
		case __si_f1ap__id_ULRRCMessageTransfer_ProcedureCode:
			break;
		case __si_f1ap__id_privateMessage_ProcedureCode:
			break;
		case __si_f1ap__id_UEInactivityNotification_ProcedureCode:
			break;
		case __si_f1ap__id_GNBDUResourceCoordination_ProcedureCode:
			break;
		case __si_f1ap__id_SystemInformationDeliveryCommand_ProcedureCode:
			break;
		case __si_f1ap__id_Paging_ProcedureCode:
			break;
		case __si_f1ap__id_Notify_ProcedureCode:
			break;
		case __si_f1ap__id_WriteReplaceWarning_ProcedureCode:
			break;
		case __si_f1ap__id_PWSCancel_ProcedureCode:
			break;
		case __si_f1ap__id_PWSRestartIndication_ProcedureCode:
			break;
		case __si_f1ap__id_PWSFailureIndication_ProcedureCode:
			break;
		case __si_f1ap__id_GNBDUStatusIndication_ProcedureCode:
			break;
		case __si_f1ap__id_RRCDeliveryReport_ProcedureCode:
			break;
		case __si_f1ap__id_F1Removal_ProcedureCode:
			break;
		case __si_f1ap__id_NetworkAccessRateReduction_ProcedureCode:
			break;
		case __si_f1ap__id_TraceStart_ProcedureCode:
			break;
		case __si_f1ap__id_DeactivateTrace_ProcedureCode:
			break;
		case __si_f1ap__id_DUCURadioInformationTransfer_ProcedureCode:
			break;
		case __si_f1ap__id_CUDURadioInformationTransfer_ProcedureCode:
			break;
		case __si_f1ap__id_BAPMappingConfiguration_ProcedureCode:
			break;
		case __si_f1ap__id_GNBDUResourceConfiguration_ProcedureCode:
			break;
		case __si_f1ap__id_IABTNLAddressAllocation_ProcedureCode:
			break;
		case __si_f1ap__id_IABUPConfigurationUpdate_ProcedureCode:
			break;
		case __si_f1ap__id_resourceStatusReportingInitiation_ProcedureCode:
			break;
		case __si_f1ap__id_resourceStatusReporting_ProcedureCode:
			break;
		case __si_f1ap__id_accessAndMobilityIndication_ProcedureCode:
			break;
		case __si_f1ap__id_accessSuccess_ProcedureCode:
			break;
		case __si_f1ap__id_cellTrafficTrace_ProcedureCode:
			break;
		case __si_f1ap__id_PositioningMeasurementExchange_ProcedureCode:
			break;
		case __si_f1ap__id_PositioningAssistanceInformationControl_ProcedureCode:
			break;
		case __si_f1ap__id_PositioningAssistanceInformationFeedback_ProcedureCode:
			break;
		case __si_f1ap__id_PositioningMeasurementReport_ProcedureCode:
			break;
		case __si_f1ap__id_PositioningMeasurementAbort_ProcedureCode:
			break;
		case __si_f1ap__id_PositioningMeasurementFailureIndication_ProcedureCode:
			break;
		case __si_f1ap__id_PositioningMeasurementUpdate_ProcedureCode:
			break;
		case __si_f1ap__id_TRPInformationExchange_ProcedureCode:
			break;
		case __si_f1ap__id_PositioningInformationExchange_ProcedureCode:
			break;
		case __si_f1ap__id_PositioningActivation_ProcedureCode:
			break;
		case __si_f1ap__id_PositioningDeactivation_ProcedureCode:
			break;
		case __si_f1ap__id_E_CIDMeasurementInitiation_ProcedureCode:
			break;
		case __si_f1ap__id_E_CIDMeasurementFailureIndication_ProcedureCode:
			break;
		case __si_f1ap__id_E_CIDMeasurementReport_ProcedureCode:
			break;
		case __si_f1ap__id_E_CIDMeasurementTermination_ProcedureCode:
			break;
		case __si_f1ap__id_PositioningInformationUpdate_ProcedureCode:
			break;
		case __si_f1ap__id_ReferenceTimeInformationReport_ProcedureCode:
			break;
		case __si_f1ap__id_ReferenceTimeInformationReportingControl_ProcedureCode:
			break;
		case __si_f1ap__id_BroadcastContextSetup_ProcedureCode:
			break;
		case __si_f1ap__id_BroadcastContextRelease_ProcedureCode:
			break;
		case __si_f1ap__id_BroadcastContextReleaseRequest_ProcedureCode:
			break;
		case __si_f1ap__id_BroadcastContextModification_ProcedureCode:
			break;
		case __si_f1ap__id_MulticastGroupPaging_ProcedureCode:
			break;
		case __si_f1ap__id_MulticastContextSetup_ProcedureCode:
			break;
		case __si_f1ap__id_MulticastContextRelease_ProcedureCode:
			break;
		case __si_f1ap__id_MulticastContextReleaseRequest_ProcedureCode:
			break;
		case __si_f1ap__id_MulticastContextModification_ProcedureCode:
			break;
		case __si_f1ap__id_MulticastDistributionSetup_ProcedureCode:
			break;
		case __si_f1ap__id_MulticastDistributionRelease_ProcedureCode:
			break;
		case __si_f1ap__id_PDCMeasurementInitiation_ProcedureCode:
			break;
		case __si_f1ap__id_PDCMeasurementReport_ProcedureCode:
			break;
		case __si_f1ap__id_procedure_code_72_not_to_be_used_ProcedureCode:
			break;
		case __si_f1ap__id_procedure_code_73_not_to_be_used_ProcedureCode:
			break;
		case __si_f1ap__id_procedure_code_74_not_to_be_used_ProcedureCode:
			break;
		case __si_f1ap__id_pRSConfigurationExchange_ProcedureCode:
			break;
		case __si_f1ap__id_measurementPreconfiguration_ProcedureCode:
			break;
		case __si_f1ap__id_measurementActivation_ProcedureCode:
			break;
		case __si_f1ap__id_QoEInformationTransfer_ProcedureCode:
			break;
		case __si_f1ap__id_PDCMeasurementTerminationCommand_ProcedureCode:
			break;
		case __si_f1ap__id_PDCMeasurementFailureIndication_ProcedureCode:
			break;
		case __si_f1ap__id_PosSystemInformationDeliveryCommand_ProcedureCode:
			break;
		case __si_f1ap__id_DUCUCellSwitchNotification_ProcedureCode:
			break;
		case __si_f1ap__id_CUDUCellSwitchNotification_ProcedureCode:
			break;
		case __si_f1ap__id_DUCUTAInformationTransfer_ProcedureCode:
			break;
		case __si_f1ap__id_CUDUTAInformationTransfer_ProcedureCode:
			break;
		case __si_f1ap__id_QoEInformationTransferControl_ProcedureCode:
			break;
		case __si_f1ap__id_RachIndication_ProcedureCode:
			break;
		case __si_f1ap__id_TimingSynchronisationStatus_ProcedureCode:
			break;
		case __si_f1ap__id_TimingSynchronisationStatusReport_ProcedureCode:
			break;
		case __si_f1ap__id_MIABF1SetupTriggering_ProcedureCode:
			break;
		case __si_f1ap__id_MIABF1SetupOutcomeNotification_ProcedureCode:
			break;
		case __si_f1ap__id_MulticastContextNotification_ProcedureCode:
			break;
		case __si_f1ap__id_MulticastCommonConfiguration_ProcedureCode:
			break;
		case __si_f1ap__id_BroadcastTransportResourceRequest_ProcedureCode:
			break;
		case __si_f1ap__id_DUCUAccessAndMobilityIndication_ProcedureCode:
			break;
		case __si_f1ap__id_SRSInformationReservationNotification_ProcedureCode:
			break;
		default:
			__si_log( SI_STK_LOG, 0, SI_LOG_CRITICAL, "Unknown ProcedureCode=%d, dropping request <%s|%s|%d>", procedureCode, __FILE__, __FUNCTION__, __LINE__);
			break;
	}
}



int main( int argc, char* argv[])
{
	printf( "F1AP Client\n");
	F1AP__InitStack( "./f1ap_c_logs/");
	F1AP__SetHost( "192.168.149.74", NULL, 0);
	F1AP__AddServer( "192.168.149.72", NULL, 38472);
	F1AP__SetOnConnect( f1ap_server_onconnect);
	F1AP__SetOnMessageRecv( F1AP_ReceiveMessage);
	F1AP__StartStack();

	// cat /proc/net/sctp/eps 
	// lsof -R | grep 
		
	__si_core_wait();
}

