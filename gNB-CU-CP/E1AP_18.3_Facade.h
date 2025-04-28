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

#include "sirik_core.h"
#include "libAsn.h"
#include "E1AP_18.3.h"
//#include "lib_node.h"
//#include "ASN_Transport.h"

#ifndef SIRIK_E1AP_H
#define SIRIK_E1AP_H


#pragma pack(4)
typedef struct __si_e1ap_node
{
	SI_Socket * siSocket;
	//uint * RANClient;
	int NodeType;
	uint8_t * transportEng;
	uint8_t * client;
} SI_E1APNode;


typedef void (*fp_e1ap_on_message)( uint8_t procedureCode, uint8_t messageType, void * msg, SI_E1APNode * ngNode);

void __si_e1ap_handle_message( SI_E1APNode * s1apNode, SI_SocketSCTPBuffer * sctpBuffer);

int __si_e1ap_sendmsg( uint8_t * buffer, uint32_t len, SI_E1APNode * ngNode);
void __si_e1ap_app_message_handler( uint8_t procedureCode, uint8_t messageType, void * msg, SI_E1APNode * ngNode);
void 	__si_e1ap_set_message_handler( fp_e1ap_on_message handler);

//int __si_e1ap_transport__init( ASNTransport_t * f1ap_ASNTransport);





int __si_e1ap_send_Reset( SI_E1AP_DT_PDU_Reset * objReset, SI_E1APNode * e1apNode);
int __si_e1ap_send_ResetAcknowledge( SI_E1AP_DT_PDU_ResetAcknowledge * objResetAcknowledge, SI_E1APNode * e1apNode);
int __si_e1ap_send_ErrorIndication( SI_E1AP_DT_PDU_ErrorIndication * objErrorIndication, SI_E1APNode * e1apNode);
int __si_e1ap_send_GNB_CU_UP_E1SetupRequest( SI_E1AP_DT_PDU_GNB_CU_UP_E1SetupRequest * objGNB_CU_UP_E1SetupRequest, SI_E1APNode * e1apNode);
int __si_e1ap_send_GNB_CU_UP_E1SetupResponse( SI_E1AP_DT_PDU_GNB_CU_UP_E1SetupResponse * objGNB_CU_UP_E1SetupResponse, SI_E1APNode * e1apNode);
int __si_e1ap_send_GNB_CU_UP_E1SetupFailure( SI_E1AP_DT_PDU_GNB_CU_UP_E1SetupFailure * objGNB_CU_UP_E1SetupFailure, SI_E1APNode * e1apNode);
int __si_e1ap_send_GNB_CU_CP_E1SetupRequest( SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupRequest * objGNB_CU_CP_E1SetupRequest, SI_E1APNode * e1apNode);
int __si_e1ap_send_GNB_CU_CP_E1SetupResponse( SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupResponse * objGNB_CU_CP_E1SetupResponse, SI_E1APNode * e1apNode);
int __si_e1ap_send_GNB_CU_CP_E1SetupFailure( SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupFailure * objGNB_CU_CP_E1SetupFailure, SI_E1APNode * e1apNode);
int __si_e1ap_send_GNB_CU_UP_ConfigurationUpdate( SI_E1AP_DT_PDU_GNB_CU_UP_ConfigurationUpdate * objGNB_CU_UP_ConfigurationUpdate, SI_E1APNode * e1apNode);
int __si_e1ap_send_GNB_CU_UP_ConfigurationUpdateAcknowledge( SI_E1AP_DT_PDU_GNB_CU_UP_ConfigurationUpdateAcknowledge * objGNB_CU_UP_ConfigurationUpdateAcknowledge, SI_E1APNode * e1apNode);
int __si_e1ap_send_GNB_CU_UP_ConfigurationUpdateFailure( SI_E1AP_DT_PDU_GNB_CU_UP_ConfigurationUpdateFailure * objGNB_CU_UP_ConfigurationUpdateFailure, SI_E1APNode * e1apNode);
int __si_e1ap_send_GNB_CU_CP_ConfigurationUpdate( SI_E1AP_DT_PDU_GNB_CU_CP_ConfigurationUpdate * objGNB_CU_CP_ConfigurationUpdate, SI_E1APNode * e1apNode);
int __si_e1ap_send_GNB_CU_CP_ConfigurationUpdateAcknowledge( SI_E1AP_DT_PDU_GNB_CU_CP_ConfigurationUpdateAcknowledge * objGNB_CU_CP_ConfigurationUpdateAcknowledge, SI_E1APNode * e1apNode);
int __si_e1ap_send_GNB_CU_CP_ConfigurationUpdateFailure( SI_E1AP_DT_PDU_GNB_CU_CP_ConfigurationUpdateFailure * objGNB_CU_CP_ConfigurationUpdateFailure, SI_E1APNode * e1apNode);
int __si_e1ap_send_E1ReleaseRequest( SI_E1AP_DT_PDU_E1ReleaseRequest * objE1ReleaseRequest, SI_E1APNode * e1apNode);
int __si_e1ap_send_E1ReleaseResponse( SI_E1AP_DT_PDU_E1ReleaseResponse * objE1ReleaseResponse, SI_E1APNode * e1apNode);
int __si_e1ap_send_BearerContextSetupRequest( SI_E1AP_DT_PDU_BearerContextSetupRequest * objBearerContextSetupRequest, SI_E1APNode * e1apNode);
int __si_e1ap_send_BearerContextSetupResponse( SI_E1AP_DT_PDU_BearerContextSetupResponse * objBearerContextSetupResponse, SI_E1APNode * e1apNode);
int __si_e1ap_send_BearerContextSetupFailure( SI_E1AP_DT_PDU_BearerContextSetupFailure * objBearerContextSetupFailure, SI_E1APNode * e1apNode);
int __si_e1ap_send_BearerContextModificationRequest( SI_E1AP_DT_PDU_BearerContextModificationRequest * objBearerContextModificationRequest, SI_E1APNode * e1apNode);
int __si_e1ap_send_BearerContextModificationResponse( SI_E1AP_DT_PDU_BearerContextModificationResponse * objBearerContextModificationResponse, SI_E1APNode * e1apNode);
int __si_e1ap_send_BearerContextModificationFailure( SI_E1AP_DT_PDU_BearerContextModificationFailure * objBearerContextModificationFailure, SI_E1APNode * e1apNode);
int __si_e1ap_send_BearerContextModificationRequired( SI_E1AP_DT_PDU_BearerContextModificationRequired * objBearerContextModificationRequired, SI_E1APNode * e1apNode);
int __si_e1ap_send_BearerContextModificationConfirm( SI_E1AP_DT_PDU_BearerContextModificationConfirm * objBearerContextModificationConfirm, SI_E1APNode * e1apNode);
int __si_e1ap_send_BearerContextReleaseCommand( SI_E1AP_DT_PDU_BearerContextReleaseCommand * objBearerContextReleaseCommand, SI_E1APNode * e1apNode);
int __si_e1ap_send_BearerContextReleaseComplete( SI_E1AP_DT_PDU_BearerContextReleaseComplete * objBearerContextReleaseComplete, SI_E1APNode * e1apNode);
int __si_e1ap_send_BearerContextReleaseRequest( SI_E1AP_DT_PDU_BearerContextReleaseRequest * objBearerContextReleaseRequest, SI_E1APNode * e1apNode);
int __si_e1ap_send_BearerContextInactivityNotification( SI_E1AP_DT_PDU_BearerContextInactivityNotification * objBearerContextInactivityNotification, SI_E1APNode * e1apNode);
int __si_e1ap_send_DLDataNotification( SI_E1AP_DT_PDU_DLDataNotification * objDLDataNotification, SI_E1APNode * e1apNode);
int __si_e1ap_send_ULDataNotification( SI_E1AP_DT_PDU_ULDataNotification * objULDataNotification, SI_E1APNode * e1apNode);
int __si_e1ap_send_DataUsageReport( SI_E1AP_DT_PDU_DataUsageReport * objDataUsageReport, SI_E1APNode * e1apNode);
int __si_e1ap_send_GNB_CU_UP_CounterCheckRequest( SI_E1AP_DT_PDU_GNB_CU_UP_CounterCheckRequest * objGNB_CU_UP_CounterCheckRequest, SI_E1APNode * e1apNode);
int __si_e1ap_send_GNB_CU_UP_StatusIndication( SI_E1AP_DT_PDU_GNB_CU_UP_StatusIndication * objGNB_CU_UP_StatusIndication, SI_E1APNode * e1apNode);
int __si_e1ap_send_PrivateMessage( SI_E1AP_DT_PDU_PrivateMessage * objPrivateMessage, SI_E1APNode * e1apNode);
int __si_e1ap_send_GNB_CU_CPMeasurementResultsInformation( SI_E1AP_DT_PDU_GNB_CU_CPMeasurementResultsInformation * objGNB_CU_CPMeasurementResultsInformation, SI_E1APNode * e1apNode);
int __si_e1ap_send_MRDC_DataUsageReport( SI_E1AP_DT_PDU_MRDC_DataUsageReport * objMRDC_DataUsageReport, SI_E1APNode * e1apNode);
int __si_e1ap_send_DeactivateTrace( SI_E1AP_DT_PDU_DeactivateTrace * objDeactivateTrace, SI_E1APNode * e1apNode);
int __si_e1ap_send_TraceStart( SI_E1AP_DT_PDU_TraceStart * objTraceStart, SI_E1APNode * e1apNode);
int __si_e1ap_send_ResourceStatusRequest( SI_E1AP_DT_PDU_ResourceStatusRequest * objResourceStatusRequest, SI_E1APNode * e1apNode);
int __si_e1ap_send_ResourceStatusResponse( SI_E1AP_DT_PDU_ResourceStatusResponse * objResourceStatusResponse, SI_E1APNode * e1apNode);
int __si_e1ap_send_ResourceStatusFailure( SI_E1AP_DT_PDU_ResourceStatusFailure * objResourceStatusFailure, SI_E1APNode * e1apNode);
int __si_e1ap_send_ResourceStatusUpdate( SI_E1AP_DT_PDU_ResourceStatusUpdate * objResourceStatusUpdate, SI_E1APNode * e1apNode);
int __si_e1ap_send_IAB_UPTNLAddressUpdate( SI_E1AP_DT_PDU_IAB_UPTNLAddressUpdate * objIAB_UPTNLAddressUpdate, SI_E1APNode * e1apNode);
int __si_e1ap_send_IAB_UPTNLAddressUpdateAcknowledge( SI_E1AP_DT_PDU_IAB_UPTNLAddressUpdateAcknowledge * objIAB_UPTNLAddressUpdateAcknowledge, SI_E1APNode * e1apNode);
int __si_e1ap_send_IAB_UPTNLAddressUpdateFailure( SI_E1AP_DT_PDU_IAB_UPTNLAddressUpdateFailure * objIAB_UPTNLAddressUpdateFailure, SI_E1APNode * e1apNode);
int __si_e1ap_send_CellTrafficTrace( SI_E1AP_DT_PDU_CellTrafficTrace * objCellTrafficTrace, SI_E1APNode * e1apNode);
int __si_e1ap_send_EarlyForwardingSNTransfer( SI_E1AP_DT_PDU_EarlyForwardingSNTransfer * objEarlyForwardingSNTransfer, SI_E1APNode * e1apNode);
int __si_e1ap_send_IABPSKNotification( SI_E1AP_DT_PDU_IABPSKNotification * objIABPSKNotification, SI_E1APNode * e1apNode);
int __si_e1ap_send_BCBearerContextSetupRequest( SI_E1AP_DT_PDU_BCBearerContextSetupRequest * objBCBearerContextSetupRequest, SI_E1APNode * e1apNode);
int __si_e1ap_send_BCBearerContextSetupResponse( SI_E1AP_DT_PDU_BCBearerContextSetupResponse * objBCBearerContextSetupResponse, SI_E1APNode * e1apNode);
int __si_e1ap_send_BCBearerContextSetupFailure( SI_E1AP_DT_PDU_BCBearerContextSetupFailure * objBCBearerContextSetupFailure, SI_E1APNode * e1apNode);
int __si_e1ap_send_BCBearerContextModificationRequest( SI_E1AP_DT_PDU_BCBearerContextModificationRequest * objBCBearerContextModificationRequest, SI_E1APNode * e1apNode);
int __si_e1ap_send_BCBearerContextModificationResponse( SI_E1AP_DT_PDU_BCBearerContextModificationResponse * objBCBearerContextModificationResponse, SI_E1APNode * e1apNode);
int __si_e1ap_send_BCBearerContextModificationFailure( SI_E1AP_DT_PDU_BCBearerContextModificationFailure * objBCBearerContextModificationFailure, SI_E1APNode * e1apNode);
int __si_e1ap_send_BCBearerContextModificationRequired( SI_E1AP_DT_PDU_BCBearerContextModificationRequired * objBCBearerContextModificationRequired, SI_E1APNode * e1apNode);
int __si_e1ap_send_BCBearerContextModificationConfirm( SI_E1AP_DT_PDU_BCBearerContextModificationConfirm * objBCBearerContextModificationConfirm, SI_E1APNode * e1apNode);
int __si_e1ap_send_BCBearerContextReleaseCommand( SI_E1AP_DT_PDU_BCBearerContextReleaseCommand * objBCBearerContextReleaseCommand, SI_E1APNode * e1apNode);
int __si_e1ap_send_BCBearerContextReleaseComplete( SI_E1AP_DT_PDU_BCBearerContextReleaseComplete * objBCBearerContextReleaseComplete, SI_E1APNode * e1apNode);
int __si_e1ap_send_BCBearerContextReleaseRequest( SI_E1AP_DT_PDU_BCBearerContextReleaseRequest * objBCBearerContextReleaseRequest, SI_E1APNode * e1apNode);
int __si_e1ap_send_MCBearerContextSetupRequest( SI_E1AP_DT_PDU_MCBearerContextSetupRequest * objMCBearerContextSetupRequest, SI_E1APNode * e1apNode);
int __si_e1ap_send_MCBearerContextSetupResponse( SI_E1AP_DT_PDU_MCBearerContextSetupResponse * objMCBearerContextSetupResponse, SI_E1APNode * e1apNode);
int __si_e1ap_send_MCBearerContextSetupFailure( SI_E1AP_DT_PDU_MCBearerContextSetupFailure * objMCBearerContextSetupFailure, SI_E1APNode * e1apNode);
int __si_e1ap_send_MCBearerContextModificationRequest( SI_E1AP_DT_PDU_MCBearerContextModificationRequest * objMCBearerContextModificationRequest, SI_E1APNode * e1apNode);
int __si_e1ap_send_MCBearerContextModificationResponse( SI_E1AP_DT_PDU_MCBearerContextModificationResponse * objMCBearerContextModificationResponse, SI_E1APNode * e1apNode);
int __si_e1ap_send_MCBearerContextModificationFailure( SI_E1AP_DT_PDU_MCBearerContextModificationFailure * objMCBearerContextModificationFailure, SI_E1APNode * e1apNode);
int __si_e1ap_send_MCBearerContextModificationRequired( SI_E1AP_DT_PDU_MCBearerContextModificationRequired * objMCBearerContextModificationRequired, SI_E1APNode * e1apNode);
int __si_e1ap_send_MCBearerContextModificationConfirm( SI_E1AP_DT_PDU_MCBearerContextModificationConfirm * objMCBearerContextModificationConfirm, SI_E1APNode * e1apNode);
int __si_e1ap_send_MCBearerNotification( SI_E1AP_DT_PDU_MCBearerNotification * objMCBearerNotification, SI_E1APNode * e1apNode);
int __si_e1ap_send_MCBearerContextReleaseCommand( SI_E1AP_DT_PDU_MCBearerContextReleaseCommand * objMCBearerContextReleaseCommand, SI_E1APNode * e1apNode);
int __si_e1ap_send_MCBearerContextReleaseComplete( SI_E1AP_DT_PDU_MCBearerContextReleaseComplete * objMCBearerContextReleaseComplete, SI_E1APNode * e1apNode);
int __si_e1ap_send_MCBearerContextReleaseRequest( SI_E1AP_DT_PDU_MCBearerContextReleaseRequest * objMCBearerContextReleaseRequest, SI_E1APNode * e1apNode);





#endif