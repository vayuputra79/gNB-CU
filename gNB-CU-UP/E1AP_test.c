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
#include "E1AP_test.h"





// CHOICE  L:11113
void __si_e1ap__set_testdata__PrivateIE_ID( SI_E1AP_DT_PrivateIE_ID ** pPrivateIE_ID)
{
	SI_E1AP_DT_PrivateIE_ID * obj_PrivateIE_ID = (SI_E1AP_DT_PrivateIE_ID*) __si_allocM( sizeof(SI_E1AP_DT_PrivateIE_ID));
	memset( obj_PrivateIE_ID, 0, sizeof( SI_E1AP_DT_PrivateIE_ID));

	obj_PrivateIE_ID->SelectedChoice = 0;

	// L:2784

	switch( obj_PrivateIE_ID->SelectedChoice)
	{
		case 0:
			obj_PrivateIE_ID->u.local = __getTestINTEGER( 0, 0);    // L:2816
			break;
		case 1:
			obj_PrivateIE_ID->u.global = __getTestINTEGER( 0, 0);    // L:2816
			break;
	}

	*pPrivateIE_ID = obj_PrivateIE_ID;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__ActivityInformation( SI_E1AP_DT_ActivityInformation ** pActivityInformation)
{
	SI_E1AP_DT_ActivityInformation * obj_ActivityInformation = (SI_E1AP_DT_ActivityInformation*) __si_allocM( sizeof(SI_E1AP_DT_ActivityInformation));
	memset( obj_ActivityInformation, 0, sizeof( SI_E1AP_DT_ActivityInformation));

	obj_ActivityInformation->SelectedChoice = 0;

	// L:2784

	switch( obj_ActivityInformation->SelectedChoice)
	{
		case 0:
			__si_e1ap__set_testdata__DRB_Activity_List( &obj_ActivityInformation->u.dRB_Activity_List);  // L:2910  ,  Parser:SEQUENCE_OF, DRB-Activity-List
			break;
		case 1:
			__si_e1ap__set_testdata__PDU_Session_Resource_Activity_List( &obj_ActivityInformation->u.pDU_Session_Resource_Activity_List);  // L:2910  ,  Parser:SEQUENCE_OF, PDU-Session-Resource-Activity-List
			break;
		case 2:
			obj_ActivityInformation->u.uE_Activity = UE_Activity_active_val;  // TODO: set enum   L:2894  ,  Parser:ENUMERATED, UE-Activity
			break;
		case 3:
			__si_e1ap__set_testdata__PDU_ActivityInformation_ExtIEs( &obj_ActivityInformation->u.choice_extension);    // L:2871
			break;
	}

	*pActivityInformation = obj_ActivityInformation;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__AlternativeQoSParaSetList( SI_E1AP_DT_AlternativeQoSParaSetList ** pAlternativeQoSParaSetList)
{
	SI_E1AP_DT_AlternativeQoSParaSetList * obj_AlternativeQoSParaSetList = NULL; 
	__si_e1ap_init_AlternativeQoSParaSetList( &obj_AlternativeQoSParaSetList);

	// L:1260
	SI_E1AP_DT_AlternativeQoSParaSetItem * objAlternativeQoSParaSetItem = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__AlternativeQoSParaSetItem( &objAlternativeQoSParaSetItem);  // L:1395

	// L:1419
	__si_linked_list_add( obj_AlternativeQoSParaSetList->AlternativeQoSParaSetItem, (uint8_t*)objAlternativeQoSParaSetItem);

	*pAlternativeQoSParaSetList = obj_AlternativeQoSParaSetList;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__AlternativeQoSParaSetItem( SI_E1AP_DT_AlternativeQoSParaSetItem ** pAlternativeQoSParaSetItem)
{
	SI_E1AP_DT_AlternativeQoSParaSetItem * obj_AlternativeQoSParaSetItem = (SI_E1AP_DT_AlternativeQoSParaSetItem*) __si_allocM( sizeof(SI_E1AP_DT_AlternativeQoSParaSetItem));
	memset( obj_AlternativeQoSParaSetItem, 0, sizeof( SI_E1AP_DT_AlternativeQoSParaSetItem));

	// L:486
	obj_AlternativeQoSParaSetItem->alternativeQoSParameterIndex = __getTestINTEGER( 1, 8);    // L:533

	obj_AlternativeQoSParaSetItem->guaranteedFlowBitRateDL = __getTestINTEGER( 0, 4000000000000);    // L:533
	obj_AlternativeQoSParaSetItem->isPresent_guaranteedFlowBitRateDL = 1;

	obj_AlternativeQoSParaSetItem->guaranteedFlowBitRateUL = __getTestINTEGER( 0, 4000000000000);    // L:533
	obj_AlternativeQoSParaSetItem->isPresent_guaranteedFlowBitRateUL = 1;

	obj_AlternativeQoSParaSetItem->packetDelayBudget = __getTestINTEGER( 0, 1023);    // L:533
	obj_AlternativeQoSParaSetItem->isPresent_packetDelayBudget = 1;

	__si_e1ap__set_testdata__PacketErrorRate( &obj_AlternativeQoSParaSetItem->packetErrorRate);    // L:584
	obj_AlternativeQoSParaSetItem->isPresent_packetErrorRate = 1;


	*pAlternativeQoSParaSetItem = obj_AlternativeQoSParaSetItem;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__BCBearerContextToSetup( SI_E1AP_DT_BCBearerContextToSetup ** pBCBearerContextToSetup)
{
	SI_E1AP_DT_BCBearerContextToSetup * obj_BCBearerContextToSetup = (SI_E1AP_DT_BCBearerContextToSetup*) __si_allocM( sizeof(SI_E1AP_DT_BCBearerContextToSetup));
	memset( obj_BCBearerContextToSetup, 0, sizeof( SI_E1AP_DT_BCBearerContextToSetup));

	// L:486
	__si_e1ap__set_testdata__SNSSAI( &obj_BCBearerContextToSetup->snssai);    // L:584

	__si_e1ap__set_testdata__BCBearerContextNGU_TNLInfoat5GC( &obj_BCBearerContextToSetup->bcBearerContextNGU_TNLInfoat5GC);    // L:588
	obj_BCBearerContextToSetup->isPresent_bcBearerContextNGU_TNLInfoat5GC = 1;

	__si_e1ap__set_testdata__BCMRBSetupConfiguration( &obj_BCBearerContextToSetup->bcMRBToSetupList);    // L:580

	obj_BCBearerContextToSetup->selected_erequestedAction = RequestedAction4AvailNGUTermination_apply_available_configuration_val;   // L:529
	obj_BCBearerContextToSetup->isPresent_requestedAction = 1;


	*pBCBearerContextToSetup = obj_BCBearerContextToSetup;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__BCBearerContextNGU_TNLInfoat5GC( SI_E1AP_DT_BCBearerContextNGU_TNLInfoat5GC ** pBCBearerContextNGU_TNLInfoat5GC)
{
	SI_E1AP_DT_BCBearerContextNGU_TNLInfoat5GC * obj_BCBearerContextNGU_TNLInfoat5GC = (SI_E1AP_DT_BCBearerContextNGU_TNLInfoat5GC*) __si_allocM( sizeof(SI_E1AP_DT_BCBearerContextNGU_TNLInfoat5GC));
	memset( obj_BCBearerContextNGU_TNLInfoat5GC, 0, sizeof( SI_E1AP_DT_BCBearerContextNGU_TNLInfoat5GC));

	obj_BCBearerContextNGU_TNLInfoat5GC->SelectedChoice = 0;

	// L:2784

	switch( obj_BCBearerContextNGU_TNLInfoat5GC->SelectedChoice)
	{
		case 0:
			obj_BCBearerContextNGU_TNLInfoat5GC->u.locationindependent = MBSNGUInformationAt5GC_multicast_val;  // TODO: set enum   L:2894  ,  Parser:CHOICE, MBSNGUInformationAt5GC
			break;
		case 1:
			__si_e1ap__set_testdata__LocationDependentMBSNGUInformationAt5GC( &obj_BCBearerContextNGU_TNLInfoat5GC->u.locationdependent);  // L:2910  ,  Parser:SEQUENCE_OF, LocationDependentMBSNGUInformationAt5GC
			break;
		case 2:
			__si_e1ap__set_testdata__PDU_BCBearerContextNGU_TNLInfoat5GC_ExtIEs( &obj_BCBearerContextNGU_TNLInfoat5GC->u.choice_extension);    // L:2871
			break;
	}

	*pBCBearerContextNGU_TNLInfoat5GC = obj_BCBearerContextNGU_TNLInfoat5GC;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__BCMRBSetupConfiguration( SI_E1AP_DT_BCMRBSetupConfiguration ** pBCMRBSetupConfiguration)
{
	SI_E1AP_DT_BCMRBSetupConfiguration * obj_BCMRBSetupConfiguration = NULL; 
	__si_e1ap_init_BCMRBSetupConfiguration( &obj_BCMRBSetupConfiguration);

	// L:1260
	SI_E1AP_DT_BCMRBSetupConfiguration_Item * objBCMRBSetupConfiguration_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__BCMRBSetupConfiguration_Item( &objBCMRBSetupConfiguration_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_BCMRBSetupConfiguration->BCMRBSetupConfiguration_Item, (uint8_t*)objBCMRBSetupConfiguration_Item);

	*pBCMRBSetupConfiguration = obj_BCMRBSetupConfiguration;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__BCMRBSetupConfiguration_Item( SI_E1AP_DT_BCMRBSetupConfiguration_Item ** pBCMRBSetupConfiguration_Item)
{
	SI_E1AP_DT_BCMRBSetupConfiguration_Item * obj_BCMRBSetupConfiguration_Item = (SI_E1AP_DT_BCMRBSetupConfiguration_Item*) __si_allocM( sizeof(SI_E1AP_DT_BCMRBSetupConfiguration_Item));
	memset( obj_BCMRBSetupConfiguration_Item, 0, sizeof( SI_E1AP_DT_BCMRBSetupConfiguration_Item));

	// L:486
	obj_BCMRBSetupConfiguration_Item->mrb_ID = __getTestINTEGER( 1, 512);    // L:533

	__si_e1ap__set_testdata__PDCP_Configuration( &obj_BCMRBSetupConfiguration_Item->mbs_pdcp_config);    // L:584

	__si_e1ap__set_testdata__QoS_Flow_QoS_Parameter_List( &obj_BCMRBSetupConfiguration_Item->qoS_Flow_QoS_Parameter_List);    // L:580

	__si_e1ap__set_testdata__QoSFlowLevelQoSParameters( &obj_BCMRBSetupConfiguration_Item->qoSFlowLevelQoSParameters);    // L:584
	obj_BCMRBSetupConfiguration_Item->isPresent_qoSFlowLevelQoSParameters = 1;


	*pBCMRBSetupConfiguration_Item = obj_BCMRBSetupConfiguration_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__BCBearerContextToSetupResponse( SI_E1AP_DT_BCBearerContextToSetupResponse ** pBCBearerContextToSetupResponse)
{
	SI_E1AP_DT_BCBearerContextToSetupResponse * obj_BCBearerContextToSetupResponse = (SI_E1AP_DT_BCBearerContextToSetupResponse*) __si_allocM( sizeof(SI_E1AP_DT_BCBearerContextToSetupResponse));
	memset( obj_BCBearerContextToSetupResponse, 0, sizeof( SI_E1AP_DT_BCBearerContextToSetupResponse));

	// L:486
	__si_e1ap__set_testdata__BCBearerContextNGU_TNLInfoatNGRAN( &obj_BCBearerContextToSetupResponse->bcBearerContextNGU_TNLInfoatNGRAN);    // L:588
	obj_BCBearerContextToSetupResponse->isPresent_bcBearerContextNGU_TNLInfoatNGRAN = 1;

	__si_e1ap__set_testdata__BCMRBSetupResponseList( &obj_BCBearerContextToSetupResponse->bcMRBSetupResponseList);    // L:580

	__si_e1ap__set_testdata__BCMRBFailedList( &obj_BCBearerContextToSetupResponse->bcMRBFailedList);    // L:580
	obj_BCBearerContextToSetupResponse->isPresent_bcMRBFailedList = 1;

	__si_e1ap__set_testdata__BCMRBSetupConfiguration( &obj_BCBearerContextToSetupResponse->availableBCMRBConfig);    // L:580
	obj_BCBearerContextToSetupResponse->isPresent_availableBCMRBConfig = 1;


	*pBCBearerContextToSetupResponse = obj_BCBearerContextToSetupResponse;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__BCBearerContextNGU_TNLInfoatNGRAN( SI_E1AP_DT_BCBearerContextNGU_TNLInfoatNGRAN ** pBCBearerContextNGU_TNLInfoatNGRAN)
{
	SI_E1AP_DT_BCBearerContextNGU_TNLInfoatNGRAN * obj_BCBearerContextNGU_TNLInfoatNGRAN = (SI_E1AP_DT_BCBearerContextNGU_TNLInfoatNGRAN*) __si_allocM( sizeof(SI_E1AP_DT_BCBearerContextNGU_TNLInfoatNGRAN));
	memset( obj_BCBearerContextNGU_TNLInfoatNGRAN, 0, sizeof( SI_E1AP_DT_BCBearerContextNGU_TNLInfoatNGRAN));

	obj_BCBearerContextNGU_TNLInfoatNGRAN->SelectedChoice = 0;

	// L:2784

	switch( obj_BCBearerContextNGU_TNLInfoatNGRAN->SelectedChoice)
	{
		case 0:
			obj_BCBearerContextNGU_TNLInfoatNGRAN->u.locationindependent = MBSNGUInformationAtNGRAN_unicast_val;  // TODO: set enum   L:2894  ,  Parser:CHOICE, MBSNGUInformationAtNGRAN
			break;
		case 1:
			__si_e1ap__set_testdata__LocationDependentMBSNGUInformationAtNGRAN( &obj_BCBearerContextNGU_TNLInfoatNGRAN->u.locationdependent);  // L:2910  ,  Parser:SEQUENCE_OF, LocationDependentMBSNGUInformationAtNGRAN
			break;
		case 2:
			__si_e1ap__set_testdata__PDU_BCBearerContextNGU_TNLInfoatNGRAN_ExtIEs( &obj_BCBearerContextNGU_TNLInfoatNGRAN->u.choice_extension);    // L:2871
			break;
	}

	*pBCBearerContextNGU_TNLInfoatNGRAN = obj_BCBearerContextNGU_TNLInfoatNGRAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__BCMRBSetupResponseList( SI_E1AP_DT_BCMRBSetupResponseList ** pBCMRBSetupResponseList)
{
	SI_E1AP_DT_BCMRBSetupResponseList * obj_BCMRBSetupResponseList = NULL; 
	__si_e1ap_init_BCMRBSetupResponseList( &obj_BCMRBSetupResponseList);

	// L:1260
	SI_E1AP_DT_BCMRBSetupResponseList_Item * objBCMRBSetupResponseList_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__BCMRBSetupResponseList_Item( &objBCMRBSetupResponseList_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_BCMRBSetupResponseList->BCMRBSetupResponseList_Item, (uint8_t*)objBCMRBSetupResponseList_Item);

	*pBCMRBSetupResponseList = obj_BCMRBSetupResponseList;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__BCMRBSetupResponseList_Item( SI_E1AP_DT_BCMRBSetupResponseList_Item ** pBCMRBSetupResponseList_Item)
{
	SI_E1AP_DT_BCMRBSetupResponseList_Item * obj_BCMRBSetupResponseList_Item = (SI_E1AP_DT_BCMRBSetupResponseList_Item*) __si_allocM( sizeof(SI_E1AP_DT_BCMRBSetupResponseList_Item));
	memset( obj_BCMRBSetupResponseList_Item, 0, sizeof( SI_E1AP_DT_BCMRBSetupResponseList_Item));

	// L:486
	obj_BCMRBSetupResponseList_Item->mrb_ID = __getTestINTEGER( 1, 512);    // L:533

	__si_e1ap__set_testdata__QoS_Flow_List( &obj_BCMRBSetupResponseList_Item->qosflow_setup);    // L:580

	__si_e1ap__set_testdata__QoS_Flow_Failed_List( &obj_BCMRBSetupResponseList_Item->qosflow_failed);    // L:580
	obj_BCMRBSetupResponseList_Item->isPresent_qosflow_failed = 1;

	__si_e1ap__set_testdata__BCBearerContextF1U_TNLInfoatCU( &obj_BCMRBSetupResponseList_Item->bcBearerContextF1U_TNLInfoatCU);    // L:588


	*pBCMRBSetupResponseList_Item = obj_BCMRBSetupResponseList_Item;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__BCBearerContextF1U_TNLInfoatCU( SI_E1AP_DT_BCBearerContextF1U_TNLInfoatCU ** pBCBearerContextF1U_TNLInfoatCU)
{
	SI_E1AP_DT_BCBearerContextF1U_TNLInfoatCU * obj_BCBearerContextF1U_TNLInfoatCU = (SI_E1AP_DT_BCBearerContextF1U_TNLInfoatCU*) __si_allocM( sizeof(SI_E1AP_DT_BCBearerContextF1U_TNLInfoatCU));
	memset( obj_BCBearerContextF1U_TNLInfoatCU, 0, sizeof( SI_E1AP_DT_BCBearerContextF1U_TNLInfoatCU));

	obj_BCBearerContextF1U_TNLInfoatCU->SelectedChoice = 0;

	// L:2784

	switch( obj_BCBearerContextF1U_TNLInfoatCU->SelectedChoice)
	{
		case 0:
			__si_e1ap__set_testdata__MBSF1UInformationAtCU( &obj_BCBearerContextF1U_TNLInfoatCU->u.locationindependent);  // L:2910  ,  Parser:SEQUENCE, MBSF1UInformationAtCU
			break;
		case 1:
			__si_e1ap__set_testdata__LocationDependentMBSF1UInformationAtCU( &obj_BCBearerContextF1U_TNLInfoatCU->u.locationdependent);  // L:2910  ,  Parser:SEQUENCE_OF, LocationDependentMBSF1UInformationAtCU
			break;
		case 2:
			__si_e1ap__set_testdata__PDU_BCBearerContextF1U_TNLInfoatCU_ExtIEs( &obj_BCBearerContextF1U_TNLInfoatCU->u.choice_extension);    // L:2871
			break;
	}

	*pBCBearerContextF1U_TNLInfoatCU = obj_BCBearerContextF1U_TNLInfoatCU;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__BCMRBFailedList( SI_E1AP_DT_BCMRBFailedList ** pBCMRBFailedList)
{
	SI_E1AP_DT_BCMRBFailedList * obj_BCMRBFailedList = NULL; 
	__si_e1ap_init_BCMRBFailedList( &obj_BCMRBFailedList);

	// L:1260
	SI_E1AP_DT_BCMRBFailedList_Item * objBCMRBFailedList_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__BCMRBFailedList_Item( &objBCMRBFailedList_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_BCMRBFailedList->BCMRBFailedList_Item, (uint8_t*)objBCMRBFailedList_Item);

	*pBCMRBFailedList = obj_BCMRBFailedList;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__BCMRBFailedList_Item( SI_E1AP_DT_BCMRBFailedList_Item ** pBCMRBFailedList_Item)
{
	SI_E1AP_DT_BCMRBFailedList_Item * obj_BCMRBFailedList_Item = (SI_E1AP_DT_BCMRBFailedList_Item*) __si_allocM( sizeof(SI_E1AP_DT_BCMRBFailedList_Item));
	memset( obj_BCMRBFailedList_Item, 0, sizeof( SI_E1AP_DT_BCMRBFailedList_Item));

	// L:486
	obj_BCMRBFailedList_Item->mrb_ID = __getTestINTEGER( 1, 512);    // L:533

	__si_e1ap__set_testdata__Cause( &obj_BCMRBFailedList_Item->cause);    // L:588


	*pBCMRBFailedList_Item = obj_BCMRBFailedList_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__BCBearerContextToModify( SI_E1AP_DT_BCBearerContextToModify ** pBCBearerContextToModify)
{
	SI_E1AP_DT_BCBearerContextToModify * obj_BCBearerContextToModify = (SI_E1AP_DT_BCBearerContextToModify*) __si_allocM( sizeof(SI_E1AP_DT_BCBearerContextToModify));
	memset( obj_BCBearerContextToModify, 0, sizeof( SI_E1AP_DT_BCBearerContextToModify));

	// L:486
	__si_e1ap__set_testdata__BCBearerContextNGU_TNLInfoat5GC( &obj_BCBearerContextToModify->bcBearerContextNGU_TNLInfoat5GC);    // L:588
	obj_BCBearerContextToModify->isPresent_bcBearerContextNGU_TNLInfoat5GC = 1;

	__si_e1ap__set_testdata__BCMRBSetupConfiguration( &obj_BCBearerContextToModify->bcMRBToSetupList);    // L:580
	obj_BCBearerContextToModify->isPresent_bcMRBToSetupList = 1;

	__si_e1ap__set_testdata__BCMRBModifyConfiguration( &obj_BCBearerContextToModify->bcMRBToModifyList);    // L:580
	obj_BCBearerContextToModify->isPresent_bcMRBToModifyList = 1;

	__si_e1ap__set_testdata__BCMRBRemoveConfiguration( &obj_BCBearerContextToModify->bcMRBToRemoveList);    // L:580
	obj_BCBearerContextToModify->isPresent_bcMRBToRemoveList = 1;


	*pBCBearerContextToModify = obj_BCBearerContextToModify;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__BCBearerContextNGU_TNLInfoatNGRAN_Request( SI_E1AP_DT_BCBearerContextNGU_TNLInfoatNGRAN_Request ** pBCBearerContextNGU_TNLInfoatNGRAN_Request)
{
	SI_E1AP_DT_BCBearerContextNGU_TNLInfoatNGRAN_Request * obj_BCBearerContextNGU_TNLInfoatNGRAN_Request = (SI_E1AP_DT_BCBearerContextNGU_TNLInfoatNGRAN_Request*) __si_allocM( sizeof(SI_E1AP_DT_BCBearerContextNGU_TNLInfoatNGRAN_Request));
	memset( obj_BCBearerContextNGU_TNLInfoatNGRAN_Request, 0, sizeof( SI_E1AP_DT_BCBearerContextNGU_TNLInfoatNGRAN_Request));

	obj_BCBearerContextNGU_TNLInfoatNGRAN_Request->SelectedChoice = 0;

	// L:2784

	switch( obj_BCBearerContextNGU_TNLInfoatNGRAN_Request->SelectedChoice)
	{
		case 0:
			obj_BCBearerContextNGU_TNLInfoatNGRAN_Request->u.locationindependent = MBSNGUInformationAtNGRAN_Request_true_val;  // TODO: set enum   L:2894  ,  Parser:ENUMERATED, MBSNGUInformationAtNGRAN-Request
			break;
		case 1:
			__si_e1ap__set_testdata__MBSNGUInformationAtNGRAN_Request_List( &obj_BCBearerContextNGU_TNLInfoatNGRAN_Request->u.locationdependent);  // L:2910  ,  Parser:SEQUENCE_OF, MBSNGUInformationAtNGRAN-Request-List
			break;
		case 2:
			__si_e1ap__set_testdata__PDU_BCBearerContextNGU_TNLInfoatNGRAN_Request_ExtIEs( &obj_BCBearerContextNGU_TNLInfoatNGRAN_Request->u.choice_extension);    // L:2871
			break;
	}

	*pBCBearerContextNGU_TNLInfoatNGRAN_Request = obj_BCBearerContextNGU_TNLInfoatNGRAN_Request;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__BCMRBModifyConfiguration( SI_E1AP_DT_BCMRBModifyConfiguration ** pBCMRBModifyConfiguration)
{
	SI_E1AP_DT_BCMRBModifyConfiguration * obj_BCMRBModifyConfiguration = NULL; 
	__si_e1ap_init_BCMRBModifyConfiguration( &obj_BCMRBModifyConfiguration);

	// L:1260
	SI_E1AP_DT_BCMRBModifyConfiguration_Item * objBCMRBModifyConfiguration_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__BCMRBModifyConfiguration_Item( &objBCMRBModifyConfiguration_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_BCMRBModifyConfiguration->BCMRBModifyConfiguration_Item, (uint8_t*)objBCMRBModifyConfiguration_Item);

	*pBCMRBModifyConfiguration = obj_BCMRBModifyConfiguration;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__BCMRBModifyConfiguration_Item( SI_E1AP_DT_BCMRBModifyConfiguration_Item ** pBCMRBModifyConfiguration_Item)
{
	SI_E1AP_DT_BCMRBModifyConfiguration_Item * obj_BCMRBModifyConfiguration_Item = (SI_E1AP_DT_BCMRBModifyConfiguration_Item*) __si_allocM( sizeof(SI_E1AP_DT_BCMRBModifyConfiguration_Item));
	memset( obj_BCMRBModifyConfiguration_Item, 0, sizeof( SI_E1AP_DT_BCMRBModifyConfiguration_Item));

	// L:486
	obj_BCMRBModifyConfiguration_Item->mrb_ID = __getTestINTEGER( 1, 512);    // L:533

	__si_e1ap__set_testdata__BCBearerContextF1U_TNLInfoatDU( &obj_BCMRBModifyConfiguration_Item->bcBearerContextF1U_TNLInfoatDU);    // L:588
	obj_BCMRBModifyConfiguration_Item->isPresent_bcBearerContextF1U_TNLInfoatDU = 1;

	__si_e1ap__set_testdata__PDCP_Configuration( &obj_BCMRBModifyConfiguration_Item->mbs_pdcp_config);    // L:584
	obj_BCMRBModifyConfiguration_Item->isPresent_mbs_pdcp_config = 1;

	__si_e1ap__set_testdata__QoS_Flow_QoS_Parameter_List( &obj_BCMRBModifyConfiguration_Item->qoS_Flow_QoS_Parameter_List);    // L:580
	obj_BCMRBModifyConfiguration_Item->isPresent_qoS_Flow_QoS_Parameter_List = 1;

	__si_e1ap__set_testdata__QoSFlowLevelQoSParameters( &obj_BCMRBModifyConfiguration_Item->qoSFlowLevelQoSParameters);    // L:584
	obj_BCMRBModifyConfiguration_Item->isPresent_qoSFlowLevelQoSParameters = 1;


	*pBCMRBModifyConfiguration_Item = obj_BCMRBModifyConfiguration_Item;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__BCBearerContextF1U_TNLInfoatDU( SI_E1AP_DT_BCBearerContextF1U_TNLInfoatDU ** pBCBearerContextF1U_TNLInfoatDU)
{
	SI_E1AP_DT_BCBearerContextF1U_TNLInfoatDU * obj_BCBearerContextF1U_TNLInfoatDU = (SI_E1AP_DT_BCBearerContextF1U_TNLInfoatDU*) __si_allocM( sizeof(SI_E1AP_DT_BCBearerContextF1U_TNLInfoatDU));
	memset( obj_BCBearerContextF1U_TNLInfoatDU, 0, sizeof( SI_E1AP_DT_BCBearerContextF1U_TNLInfoatDU));

	obj_BCBearerContextF1U_TNLInfoatDU->SelectedChoice = 0;

	// L:2784

	switch( obj_BCBearerContextF1U_TNLInfoatDU->SelectedChoice)
	{
		case 0:
			__si_e1ap__set_testdata__MBSF1UInformationAtDU( &obj_BCBearerContextF1U_TNLInfoatDU->u.locationindependent);  // L:2910  ,  Parser:SEQUENCE, MBSF1UInformationAtDU
			break;
		case 1:
			__si_e1ap__set_testdata__LocationDependentMBSF1UInformationAtDU( &obj_BCBearerContextF1U_TNLInfoatDU->u.locationdependent);  // L:2910  ,  Parser:SEQUENCE_OF, LocationDependentMBSF1UInformationAtDU
			break;
		case 2:
			__si_e1ap__set_testdata__PDU_BCBearerContextF1U_TNLInfoatDU_ExtIEs( &obj_BCBearerContextF1U_TNLInfoatDU->u.choice_extension);    // L:2871
			break;
	}

	*pBCBearerContextF1U_TNLInfoatDU = obj_BCBearerContextF1U_TNLInfoatDU;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__BCMRBRemoveConfiguration( SI_E1AP_DT_BCMRBRemoveConfiguration ** pBCMRBRemoveConfiguration)
{
	SI_E1AP_DT_BCMRBRemoveConfiguration * obj_BCMRBRemoveConfiguration = NULL; 
	__si_e1ap_init_BCMRBRemoveConfiguration( &obj_BCMRBRemoveConfiguration);

	// L:1260
	SI_E1AP_DT_MRB_ID * objMRB_ID = NULL;
	objMRB_ID = (SI_E1AP_DT_MRB_ID*)__si_allocM(sizeof(SI_E1AP_DT_MRB_ID)); // L:1383
	objMRB_ID->data = 1;

	// L:1419
	__si_linked_list_add( obj_BCMRBRemoveConfiguration->MRB_ID, (uint8_t*)objMRB_ID);

	*pBCMRBRemoveConfiguration = obj_BCMRBRemoveConfiguration;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__BCBearerContextToModifyResponse( SI_E1AP_DT_BCBearerContextToModifyResponse ** pBCBearerContextToModifyResponse)
{
	SI_E1AP_DT_BCBearerContextToModifyResponse * obj_BCBearerContextToModifyResponse = (SI_E1AP_DT_BCBearerContextToModifyResponse*) __si_allocM( sizeof(SI_E1AP_DT_BCBearerContextToModifyResponse));
	memset( obj_BCBearerContextToModifyResponse, 0, sizeof( SI_E1AP_DT_BCBearerContextToModifyResponse));

	// L:486
	__si_e1ap__set_testdata__BCBearerContextNGU_TNLInfoatNGRAN( &obj_BCBearerContextToModifyResponse->bcBearerContextNGU_TNLInfoatNGRAN);    // L:588
	obj_BCBearerContextToModifyResponse->isPresent_bcBearerContextNGU_TNLInfoatNGRAN = 1;

	__si_e1ap__set_testdata__BCMRBSetupModifyResponseList( &obj_BCBearerContextToModifyResponse->bcMRBSetupModifyResponseList);    // L:580

	__si_e1ap__set_testdata__BCMRBFailedList( &obj_BCBearerContextToModifyResponse->bcMRBFailedList);    // L:580
	obj_BCBearerContextToModifyResponse->isPresent_bcMRBFailedList = 1;

	__si_e1ap__set_testdata__BCMRBSetupConfiguration( &obj_BCBearerContextToModifyResponse->availableBCMRBConfig);    // L:580
	obj_BCBearerContextToModifyResponse->isPresent_availableBCMRBConfig = 1;


	*pBCBearerContextToModifyResponse = obj_BCBearerContextToModifyResponse;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__BCMRBSetupModifyResponseList( SI_E1AP_DT_BCMRBSetupModifyResponseList ** pBCMRBSetupModifyResponseList)
{
	SI_E1AP_DT_BCMRBSetupModifyResponseList * obj_BCMRBSetupModifyResponseList = NULL; 
	__si_e1ap_init_BCMRBSetupModifyResponseList( &obj_BCMRBSetupModifyResponseList);

	// L:1260
	SI_E1AP_DT_BCMRBSetupModifyResponseList_Item * objBCMRBSetupModifyResponseList_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__BCMRBSetupModifyResponseList_Item( &objBCMRBSetupModifyResponseList_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_BCMRBSetupModifyResponseList->BCMRBSetupModifyResponseList_Item, (uint8_t*)objBCMRBSetupModifyResponseList_Item);

	*pBCMRBSetupModifyResponseList = obj_BCMRBSetupModifyResponseList;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__BCMRBSetupModifyResponseList_Item( SI_E1AP_DT_BCMRBSetupModifyResponseList_Item ** pBCMRBSetupModifyResponseList_Item)
{
	SI_E1AP_DT_BCMRBSetupModifyResponseList_Item * obj_BCMRBSetupModifyResponseList_Item = (SI_E1AP_DT_BCMRBSetupModifyResponseList_Item*) __si_allocM( sizeof(SI_E1AP_DT_BCMRBSetupModifyResponseList_Item));
	memset( obj_BCMRBSetupModifyResponseList_Item, 0, sizeof( SI_E1AP_DT_BCMRBSetupModifyResponseList_Item));

	// L:486
	obj_BCMRBSetupModifyResponseList_Item->mrb_ID = __getTestINTEGER( 1, 512);    // L:533

	__si_e1ap__set_testdata__QoS_Flow_List( &obj_BCMRBSetupModifyResponseList_Item->qosflow_setup);    // L:580
	obj_BCMRBSetupModifyResponseList_Item->isPresent_qosflow_setup = 1;

	__si_e1ap__set_testdata__QoS_Flow_Failed_List( &obj_BCMRBSetupModifyResponseList_Item->qosflow_failed);    // L:580
	obj_BCMRBSetupModifyResponseList_Item->isPresent_qosflow_failed = 1;

	__si_e1ap__set_testdata__BCBearerContextF1U_TNLInfoatCU( &obj_BCMRBSetupModifyResponseList_Item->bcBearerContextF1U_TNLInfoatCU);    // L:588
	obj_BCMRBSetupModifyResponseList_Item->isPresent_bcBearerContextF1U_TNLInfoatCU = 1;


	*pBCMRBSetupModifyResponseList_Item = obj_BCMRBSetupModifyResponseList_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__BCBearerContextToModifyRequired( SI_E1AP_DT_BCBearerContextToModifyRequired ** pBCBearerContextToModifyRequired)
{
	SI_E1AP_DT_BCBearerContextToModifyRequired * obj_BCBearerContextToModifyRequired = (SI_E1AP_DT_BCBearerContextToModifyRequired*) __si_allocM( sizeof(SI_E1AP_DT_BCBearerContextToModifyRequired));
	memset( obj_BCBearerContextToModifyRequired, 0, sizeof( SI_E1AP_DT_BCBearerContextToModifyRequired));

	// L:486
	__si_e1ap__set_testdata__BCMRBRemoveConfiguration( &obj_BCBearerContextToModifyRequired->bcMRBToRemoveList);    // L:580
	obj_BCBearerContextToModifyRequired->isPresent_bcMRBToRemoveList = 1;


	*pBCBearerContextToModifyRequired = obj_BCBearerContextToModifyRequired;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__BCBearerContextToModifyConfirm( SI_E1AP_DT_BCBearerContextToModifyConfirm ** pBCBearerContextToModifyConfirm)
{
	SI_E1AP_DT_BCBearerContextToModifyConfirm * obj_BCBearerContextToModifyConfirm = (SI_E1AP_DT_BCBearerContextToModifyConfirm*) __si_allocM( sizeof(SI_E1AP_DT_BCBearerContextToModifyConfirm));
	memset( obj_BCBearerContextToModifyConfirm, 0, sizeof( SI_E1AP_DT_BCBearerContextToModifyConfirm));

	// L:486

	*pBCBearerContextToModifyConfirm = obj_BCBearerContextToModifyConfirm;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__Cause( SI_E1AP_DT_Cause ** pCause)
{
	SI_E1AP_DT_Cause * obj_Cause = (SI_E1AP_DT_Cause*) __si_allocM( sizeof(SI_E1AP_DT_Cause));
	memset( obj_Cause, 0, sizeof( SI_E1AP_DT_Cause));

	obj_Cause->SelectedChoice = 0;

	// L:2784

	switch( obj_Cause->SelectedChoice)
	{
		case 0:
			obj_Cause->u.radioNetwork = CauseRadioNetwork_unspecified_val;  // TODO: set enum   L:2894  ,  Parser:ENUMERATED, CauseRadioNetwork
			break;
		case 1:
			obj_Cause->u.transport = CauseTransport_unspecified_val;  // TODO: set enum   L:2894  ,  Parser:ENUMERATED, CauseTransport
			break;
		case 2:
			obj_Cause->u.protocol = CauseProtocol_transfer_syntax_error_val;  // TODO: set enum   L:2894  ,  Parser:ENUMERATED, CauseProtocol
			break;
		case 3:
			obj_Cause->u.misc = CauseMisc_control_processing_overload_val;  // TODO: set enum   L:2894  ,  Parser:ENUMERATED, CauseMisc
			break;
		case 4:
			__si_e1ap__set_testdata__PDU_Cause_ExtIEs( &obj_Cause->u.choice_extension);    // L:2871
			break;
	}

	*pCause = obj_Cause;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__Cell_Group_Information( SI_E1AP_DT_Cell_Group_Information ** pCell_Group_Information)
{
	SI_E1AP_DT_Cell_Group_Information * obj_Cell_Group_Information = NULL; 
	__si_e1ap_init_Cell_Group_Information( &obj_Cell_Group_Information);

	// L:1260
	SI_E1AP_DT_Cell_Group_Information_Item * objCell_Group_Information_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__Cell_Group_Information_Item( &objCell_Group_Information_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_Cell_Group_Information->Cell_Group_Information_Item, (uint8_t*)objCell_Group_Information_Item);

	*pCell_Group_Information = obj_Cell_Group_Information;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__Cell_Group_Information_Item( SI_E1AP_DT_Cell_Group_Information_Item ** pCell_Group_Information_Item)
{
	SI_E1AP_DT_Cell_Group_Information_Item * obj_Cell_Group_Information_Item = (SI_E1AP_DT_Cell_Group_Information_Item*) __si_allocM( sizeof(SI_E1AP_DT_Cell_Group_Information_Item));
	memset( obj_Cell_Group_Information_Item, 0, sizeof( SI_E1AP_DT_Cell_Group_Information_Item));

	// L:486
	obj_Cell_Group_Information_Item->cell_Group_ID = __getTestINTEGER( 0, 3);    // L:533

	obj_Cell_Group_Information_Item->selected_euL_Configuration = UL_Configuration_no_data_val;   // L:529
	obj_Cell_Group_Information_Item->isPresent_uL_Configuration = 1;

	obj_Cell_Group_Information_Item->selected_edL_TX_Stop = DL_TX_Stop_stop_val;   // L:529
	obj_Cell_Group_Information_Item->isPresent_dL_TX_Stop = 1;

	obj_Cell_Group_Information_Item->selected_erAT_Type = RAT_Type_e_UTRA_val;   // L:529
	obj_Cell_Group_Information_Item->isPresent_rAT_Type = 1;


	*pCell_Group_Information_Item = obj_Cell_Group_Information_Item;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__CP_TNL_Information( SI_E1AP_DT_CP_TNL_Information ** pCP_TNL_Information)
{
	SI_E1AP_DT_CP_TNL_Information * obj_CP_TNL_Information = (SI_E1AP_DT_CP_TNL_Information*) __si_allocM( sizeof(SI_E1AP_DT_CP_TNL_Information));
	memset( obj_CP_TNL_Information, 0, sizeof( SI_E1AP_DT_CP_TNL_Information));


	obj_CP_TNL_Information->SelectedChoice = 1;
	//printf( "obj_CP_TNL_Information=->SC %d %d\n", obj_CP_TNL_Information->SelectedChoice, __LINE__);
	// L:2784

	switch( obj_CP_TNL_Information->SelectedChoice)
	{
		case 0:
				__si_e1ap_init_TransportLayerAddress2( &obj_CP_TNL_Information->u.endpoint_IP_Address, "6", 1, 1);  // L:2837
				obj_CP_TNL_Information->u.endpoint_IP_Address->bitslen = 1; //   L:2838
			break;
		case 1:
			__si_e1ap__set_testdata__PDU_CP_TNL_Information_ExtIEs( &obj_CP_TNL_Information->u.choice_extension);    // L:2871
			break;
	}

	*pCP_TNL_Information = obj_CP_TNL_Information;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__CriticalityDiagnostics( SI_E1AP_DT_CriticalityDiagnostics ** pCriticalityDiagnostics)
{
	SI_E1AP_DT_CriticalityDiagnostics * obj_CriticalityDiagnostics = (SI_E1AP_DT_CriticalityDiagnostics*) __si_allocM( sizeof(SI_E1AP_DT_CriticalityDiagnostics));
	memset( obj_CriticalityDiagnostics, 0, sizeof( SI_E1AP_DT_CriticalityDiagnostics));

	// L:486
	obj_CriticalityDiagnostics->procedureCode = __getTestINTEGER( 0, 255);    // L:533
	obj_CriticalityDiagnostics->isPresent_procedureCode = 1;

	obj_CriticalityDiagnostics->selected_etriggeringMessage = TriggeringMessage_initiating_message_val;   // L:529
	obj_CriticalityDiagnostics->isPresent_triggeringMessage = 1;

	obj_CriticalityDiagnostics->selected_eprocedureCriticality = Criticality_reject_val;   // L:529
	obj_CriticalityDiagnostics->isPresent_procedureCriticality = 1;

	obj_CriticalityDiagnostics->transactionID = __getTestINTEGER( 0, 255);    // L:533
	obj_CriticalityDiagnostics->isPresent_transactionID = 1;


	*pCriticalityDiagnostics = obj_CriticalityDiagnostics;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DAPSRequestInfo( SI_E1AP_DT_DAPSRequestInfo ** pDAPSRequestInfo)
{
	SI_E1AP_DT_DAPSRequestInfo * obj_DAPSRequestInfo = (SI_E1AP_DT_DAPSRequestInfo*) __si_allocM( sizeof(SI_E1AP_DT_DAPSRequestInfo));
	memset( obj_DAPSRequestInfo, 0, sizeof( SI_E1AP_DT_DAPSRequestInfo));

	// L:486
	obj_DAPSRequestInfo->selected_edapsIndicator = DAPSRequestInfo_dapsIndicator_daps_HO_required_val;   // L:529


	*pDAPSRequestInfo = obj_DAPSRequestInfo;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__Data_Forwarding_Information_Request( SI_E1AP_DT_Data_Forwarding_Information_Request ** pData_Forwarding_Information_Request)
{
	SI_E1AP_DT_Data_Forwarding_Information_Request * obj_Data_Forwarding_Information_Request = (SI_E1AP_DT_Data_Forwarding_Information_Request*) __si_allocM( sizeof(SI_E1AP_DT_Data_Forwarding_Information_Request));
	memset( obj_Data_Forwarding_Information_Request, 0, sizeof( SI_E1AP_DT_Data_Forwarding_Information_Request));

	// L:486
	obj_Data_Forwarding_Information_Request->selected_edata_Forwarding_Request = Data_Forwarding_Request_uL_val;   // L:529

	__si_e1ap__set_testdata__QoS_Flow_Mapping_List( &obj_Data_Forwarding_Information_Request->qoS_Flows_Forwarded_On_Fwd_Tunnels);    // L:580
	obj_Data_Forwarding_Information_Request->isPresent_qoS_Flows_Forwarded_On_Fwd_Tunnels = 1;


	*pData_Forwarding_Information_Request = obj_Data_Forwarding_Information_Request;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__Data_Forwarding_Information( SI_E1AP_DT_Data_Forwarding_Information ** pData_Forwarding_Information)
{
	SI_E1AP_DT_Data_Forwarding_Information * obj_Data_Forwarding_Information = (SI_E1AP_DT_Data_Forwarding_Information*) __si_allocM( sizeof(SI_E1AP_DT_Data_Forwarding_Information));
	memset( obj_Data_Forwarding_Information, 0, sizeof( SI_E1AP_DT_Data_Forwarding_Information));

	// L:486
	__si_e1ap__set_testdata__UP_TNL_Information( &obj_Data_Forwarding_Information->uL_Data_Forwarding);    // L:588
	obj_Data_Forwarding_Information->isPresent_uL_Data_Forwarding = 1;

	__si_e1ap__set_testdata__UP_TNL_Information( &obj_Data_Forwarding_Information->dL_Data_Forwarding);    // L:588
	obj_Data_Forwarding_Information->isPresent_dL_Data_Forwarding = 1;


	*pData_Forwarding_Information = obj_Data_Forwarding_Information;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DataForwardingtoE_UTRANInformationList( SI_E1AP_DT_DataForwardingtoE_UTRANInformationList ** pDataForwardingtoE_UTRANInformationList)
{
	SI_E1AP_DT_DataForwardingtoE_UTRANInformationList * obj_DataForwardingtoE_UTRANInformationList = NULL; 
	__si_e1ap_init_DataForwardingtoE_UTRANInformationList( &obj_DataForwardingtoE_UTRANInformationList);

	// L:1260
	SI_E1AP_DT_DataForwardingtoE_UTRANInformationListItem * objDataForwardingtoE_UTRANInformationListItem = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DataForwardingtoE_UTRANInformationListItem( &objDataForwardingtoE_UTRANInformationListItem);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DataForwardingtoE_UTRANInformationList->DataForwardingtoE_UTRANInformationListItem, (uint8_t*)objDataForwardingtoE_UTRANInformationListItem);

	*pDataForwardingtoE_UTRANInformationList = obj_DataForwardingtoE_UTRANInformationList;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DataForwardingtoE_UTRANInformationListItem( SI_E1AP_DT_DataForwardingtoE_UTRANInformationListItem ** pDataForwardingtoE_UTRANInformationListItem)
{
	SI_E1AP_DT_DataForwardingtoE_UTRANInformationListItem * obj_DataForwardingtoE_UTRANInformationListItem = (SI_E1AP_DT_DataForwardingtoE_UTRANInformationListItem*) __si_allocM( sizeof(SI_E1AP_DT_DataForwardingtoE_UTRANInformationListItem));
	memset( obj_DataForwardingtoE_UTRANInformationListItem, 0, sizeof( SI_E1AP_DT_DataForwardingtoE_UTRANInformationListItem));

	// L:486
	__si_e1ap__set_testdata__UP_TNL_Information( &obj_DataForwardingtoE_UTRANInformationListItem->data_forwarding_tunnel_information);    // L:588

	__si_e1ap__set_testdata__QoS_Flows_to_be_forwarded_List( &obj_DataForwardingtoE_UTRANInformationListItem->qoS_Flows_to_be_forwarded_List);    // L:580


	*pDataForwardingtoE_UTRANInformationListItem = obj_DataForwardingtoE_UTRANInformationListItem;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DataUsageperPDUSessionReport_pDU_session_Timed_Report_List( SI_E1AP_DT_DataUsageperPDUSessionReport_pDU_session_Timed_Report_List ** pDataUsageperPDUSessionReport_pDU_session_Timed_Report_List)
{
	SI_E1AP_DT_DataUsageperPDUSessionReport_pDU_session_Timed_Report_List * obj_DataUsageperPDUSessionReport_pDU_session_Timed_Report_List = NULL; 
	__si_e1ap_init_DataUsageperPDUSessionReport_pDU_session_Timed_Report_List( &obj_DataUsageperPDUSessionReport_pDU_session_Timed_Report_List);

	// L:1260
	SI_E1AP_DT_MRDC_Data_Usage_Report_Item * objMRDC_Data_Usage_Report_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__MRDC_Data_Usage_Report_Item( &objMRDC_Data_Usage_Report_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DataUsageperPDUSessionReport_pDU_session_Timed_Report_List->MRDC_Data_Usage_Report_Item, (uint8_t*)objMRDC_Data_Usage_Report_Item);

	*pDataUsageperPDUSessionReport_pDU_session_Timed_Report_List = obj_DataUsageperPDUSessionReport_pDU_session_Timed_Report_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__Data_Usage_per_PDU_Session_Report( SI_E1AP_DT_Data_Usage_per_PDU_Session_Report ** pData_Usage_per_PDU_Session_Report)
{
	SI_E1AP_DT_Data_Usage_per_PDU_Session_Report * obj_Data_Usage_per_PDU_Session_Report = (SI_E1AP_DT_Data_Usage_per_PDU_Session_Report*) __si_allocM( sizeof(SI_E1AP_DT_Data_Usage_per_PDU_Session_Report));
	memset( obj_Data_Usage_per_PDU_Session_Report, 0, sizeof( SI_E1AP_DT_Data_Usage_per_PDU_Session_Report));

	// L:486
	obj_Data_Usage_per_PDU_Session_Report->selected_esecondaryRATType = DataUsageperPDUSessionReport_secondaryRATType_nR_val;   // L:529

	__si_e1ap__set_testdata__DataUsageperPDUSessionReport_pDU_session_Timed_Report_List( &obj_Data_Usage_per_PDU_Session_Report->pDU_session_Timed_Report_List);    // L:580


	*pData_Usage_per_PDU_Session_Report = obj_Data_Usage_per_PDU_Session_Report;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__Data_Usage_per_QoS_Flow_List( SI_E1AP_DT_Data_Usage_per_QoS_Flow_List ** pData_Usage_per_QoS_Flow_List)
{
	SI_E1AP_DT_Data_Usage_per_QoS_Flow_List * obj_Data_Usage_per_QoS_Flow_List = NULL; 
	__si_e1ap_init_Data_Usage_per_QoS_Flow_List( &obj_Data_Usage_per_QoS_Flow_List);

	// L:1260
	SI_E1AP_DT_Data_Usage_per_QoS_Flow_Item * objData_Usage_per_QoS_Flow_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__Data_Usage_per_QoS_Flow_Item( &objData_Usage_per_QoS_Flow_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_Data_Usage_per_QoS_Flow_List->Data_Usage_per_QoS_Flow_Item, (uint8_t*)objData_Usage_per_QoS_Flow_Item);

	*pData_Usage_per_QoS_Flow_List = obj_Data_Usage_per_QoS_Flow_List;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DataUsageperQoSFlowItem_qoS_Flow_Timed_Report_List( SI_E1AP_DT_DataUsageperQoSFlowItem_qoS_Flow_Timed_Report_List ** pDataUsageperQoSFlowItem_qoS_Flow_Timed_Report_List)
{
	SI_E1AP_DT_DataUsageperQoSFlowItem_qoS_Flow_Timed_Report_List * obj_DataUsageperQoSFlowItem_qoS_Flow_Timed_Report_List = NULL; 
	__si_e1ap_init_DataUsageperQoSFlowItem_qoS_Flow_Timed_Report_List( &obj_DataUsageperQoSFlowItem_qoS_Flow_Timed_Report_List);

	// L:1260
	SI_E1AP_DT_MRDC_Data_Usage_Report_Item * objMRDC_Data_Usage_Report_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__MRDC_Data_Usage_Report_Item( &objMRDC_Data_Usage_Report_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DataUsageperQoSFlowItem_qoS_Flow_Timed_Report_List->MRDC_Data_Usage_Report_Item, (uint8_t*)objMRDC_Data_Usage_Report_Item);

	*pDataUsageperQoSFlowItem_qoS_Flow_Timed_Report_List = obj_DataUsageperQoSFlowItem_qoS_Flow_Timed_Report_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__Data_Usage_per_QoS_Flow_Item( SI_E1AP_DT_Data_Usage_per_QoS_Flow_Item ** pData_Usage_per_QoS_Flow_Item)
{
	SI_E1AP_DT_Data_Usage_per_QoS_Flow_Item * obj_Data_Usage_per_QoS_Flow_Item = (SI_E1AP_DT_Data_Usage_per_QoS_Flow_Item*) __si_allocM( sizeof(SI_E1AP_DT_Data_Usage_per_QoS_Flow_Item));
	memset( obj_Data_Usage_per_QoS_Flow_Item, 0, sizeof( SI_E1AP_DT_Data_Usage_per_QoS_Flow_Item));

	// L:486
	obj_Data_Usage_per_QoS_Flow_Item->qoS_Flow_Identifier = __getTestINTEGER( 0, 63);    // L:533

	obj_Data_Usage_per_QoS_Flow_Item->selected_esecondaryRATType = DataUsageperQoSFlowItem_secondaryRATType_nR_val;   // L:529

	__si_e1ap__set_testdata__DataUsageperQoSFlowItem_qoS_Flow_Timed_Report_List( &obj_Data_Usage_per_QoS_Flow_Item->qoS_Flow_Timed_Report_List);    // L:580


	*pData_Usage_per_QoS_Flow_Item = obj_Data_Usage_per_QoS_Flow_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__Data_Usage_Report_List( SI_E1AP_DT_Data_Usage_Report_List ** pData_Usage_Report_List)
{
	SI_E1AP_DT_Data_Usage_Report_List * obj_Data_Usage_Report_List = NULL; 
	__si_e1ap_init_Data_Usage_Report_List( &obj_Data_Usage_Report_List);

	// L:1260
	SI_E1AP_DT_Data_Usage_Report_Item * objData_Usage_Report_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__Data_Usage_Report_Item( &objData_Usage_Report_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_Data_Usage_Report_List->Data_Usage_Report_Item, (uint8_t*)objData_Usage_Report_Item);

	*pData_Usage_Report_List = obj_Data_Usage_Report_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__Data_Usage_Report_Item( SI_E1AP_DT_Data_Usage_Report_Item ** pData_Usage_Report_Item)
{
	SI_E1AP_DT_Data_Usage_Report_Item * obj_Data_Usage_Report_Item = (SI_E1AP_DT_Data_Usage_Report_Item*) __si_allocM( sizeof(SI_E1AP_DT_Data_Usage_Report_Item));
	memset( obj_Data_Usage_Report_Item, 0, sizeof( SI_E1AP_DT_Data_Usage_Report_Item));

	// L:486
	obj_Data_Usage_Report_Item->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	obj_Data_Usage_Report_Item->selected_erAT_Type = RAT_Type_e_UTRA_val;   // L:529

	__si_e1ap__set_testdata__DRB_Usage_Report_List( &obj_Data_Usage_Report_Item->dRB_Usage_Report_List);    // L:580


	*pData_Usage_Report_Item = obj_Data_Usage_Report_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DLDiscarding( SI_E1AP_DT_DLDiscarding ** pDLDiscarding)
{
	SI_E1AP_DT_DLDiscarding * obj_DLDiscarding = (SI_E1AP_DT_DLDiscarding*) __si_allocM( sizeof(SI_E1AP_DT_DLDiscarding));
	memset( obj_DLDiscarding, 0, sizeof( SI_E1AP_DT_DLDiscarding));

	// L:486
	__si_e1ap__set_testdata__PDCP_Count( &obj_DLDiscarding->dLDiscardingCountVal);    // L:584


	*pDLDiscarding = obj_DLDiscarding;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DLUPTNLAddressToUpdateItem( SI_E1AP_DT_DLUPTNLAddressToUpdateItem ** pDLUPTNLAddressToUpdateItem)
{
	SI_E1AP_DT_DLUPTNLAddressToUpdateItem * obj_DLUPTNLAddressToUpdateItem = (SI_E1AP_DT_DLUPTNLAddressToUpdateItem*) __si_allocM( sizeof(SI_E1AP_DT_DLUPTNLAddressToUpdateItem));
	memset( obj_DLUPTNLAddressToUpdateItem, 0, sizeof( SI_E1AP_DT_DLUPTNLAddressToUpdateItem));

	// L:486
	__si_e1ap_init_TransportLayerAddress2( &obj_DLUPTNLAddressToUpdateItem->oldTNLAdress, "1", 1, 1);  // L:574
	obj_DLUPTNLAddressToUpdateItem->oldTNLAdress->bitslen = 1; //   L:575

	__si_e1ap_init_TransportLayerAddress2( &obj_DLUPTNLAddressToUpdateItem->newTNLAdress, "3", 1, 1);  // L:574
	obj_DLUPTNLAddressToUpdateItem->newTNLAdress->bitslen = 1; //   L:575


	*pDLUPTNLAddressToUpdateItem = obj_DLUPTNLAddressToUpdateItem;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_Activity_List( SI_E1AP_DT_DRB_Activity_List ** pDRB_Activity_List)
{
	SI_E1AP_DT_DRB_Activity_List * obj_DRB_Activity_List = NULL; 
	__si_e1ap_init_DRB_Activity_List( &obj_DRB_Activity_List);

	// L:1260
	SI_E1AP_DT_DRB_Activity_Item * objDRB_Activity_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_Activity_Item( &objDRB_Activity_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_Activity_List->DRB_Activity_Item, (uint8_t*)objDRB_Activity_Item);

	*pDRB_Activity_List = obj_DRB_Activity_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_Activity_Item( SI_E1AP_DT_DRB_Activity_Item ** pDRB_Activity_Item)
{
	SI_E1AP_DT_DRB_Activity_Item * obj_DRB_Activity_Item = (SI_E1AP_DT_DRB_Activity_Item*) __si_allocM( sizeof(SI_E1AP_DT_DRB_Activity_Item));
	memset( obj_DRB_Activity_Item, 0, sizeof( SI_E1AP_DT_DRB_Activity_Item));

	// L:486
	obj_DRB_Activity_Item->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	obj_DRB_Activity_Item->selected_edRB_Activity = DRB_Activity_active_val;   // L:529


	*pDRB_Activity_Item = obj_DRB_Activity_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_Confirm_Modified_List_EUTRAN( SI_E1AP_DT_DRB_Confirm_Modified_List_EUTRAN ** pDRB_Confirm_Modified_List_EUTRAN)
{
	SI_E1AP_DT_DRB_Confirm_Modified_List_EUTRAN * obj_DRB_Confirm_Modified_List_EUTRAN = NULL; 
	__si_e1ap_init_DRB_Confirm_Modified_List_EUTRAN( &obj_DRB_Confirm_Modified_List_EUTRAN);

	// L:1260
	SI_E1AP_DT_DRB_Confirm_Modified_Item_EUTRAN * objDRB_Confirm_Modified_Item_EUTRAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_Confirm_Modified_Item_EUTRAN( &objDRB_Confirm_Modified_Item_EUTRAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_Confirm_Modified_List_EUTRAN->DRB_Confirm_Modified_Item_EUTRAN, (uint8_t*)objDRB_Confirm_Modified_Item_EUTRAN);

	*pDRB_Confirm_Modified_List_EUTRAN = obj_DRB_Confirm_Modified_List_EUTRAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_Confirm_Modified_Item_EUTRAN( SI_E1AP_DT_DRB_Confirm_Modified_Item_EUTRAN ** pDRB_Confirm_Modified_Item_EUTRAN)
{
	SI_E1AP_DT_DRB_Confirm_Modified_Item_EUTRAN * obj_DRB_Confirm_Modified_Item_EUTRAN = (SI_E1AP_DT_DRB_Confirm_Modified_Item_EUTRAN*) __si_allocM( sizeof(SI_E1AP_DT_DRB_Confirm_Modified_Item_EUTRAN));
	memset( obj_DRB_Confirm_Modified_Item_EUTRAN, 0, sizeof( SI_E1AP_DT_DRB_Confirm_Modified_Item_EUTRAN));

	// L:486
	obj_DRB_Confirm_Modified_Item_EUTRAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__Cell_Group_Information( &obj_DRB_Confirm_Modified_Item_EUTRAN->cell_Group_Information);    // L:580
	obj_DRB_Confirm_Modified_Item_EUTRAN->isPresent_cell_Group_Information = 1;


	*pDRB_Confirm_Modified_Item_EUTRAN = obj_DRB_Confirm_Modified_Item_EUTRAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_Confirm_Modified_List_NG_RAN( SI_E1AP_DT_DRB_Confirm_Modified_List_NG_RAN ** pDRB_Confirm_Modified_List_NG_RAN)
{
	SI_E1AP_DT_DRB_Confirm_Modified_List_NG_RAN * obj_DRB_Confirm_Modified_List_NG_RAN = NULL; 
	__si_e1ap_init_DRB_Confirm_Modified_List_NG_RAN( &obj_DRB_Confirm_Modified_List_NG_RAN);

	// L:1260
	SI_E1AP_DT_DRB_Confirm_Modified_Item_NG_RAN * objDRB_Confirm_Modified_Item_NG_RAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_Confirm_Modified_Item_NG_RAN( &objDRB_Confirm_Modified_Item_NG_RAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_Confirm_Modified_List_NG_RAN->DRB_Confirm_Modified_Item_NG_RAN, (uint8_t*)objDRB_Confirm_Modified_Item_NG_RAN);

	*pDRB_Confirm_Modified_List_NG_RAN = obj_DRB_Confirm_Modified_List_NG_RAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_Confirm_Modified_Item_NG_RAN( SI_E1AP_DT_DRB_Confirm_Modified_Item_NG_RAN ** pDRB_Confirm_Modified_Item_NG_RAN)
{
	SI_E1AP_DT_DRB_Confirm_Modified_Item_NG_RAN * obj_DRB_Confirm_Modified_Item_NG_RAN = (SI_E1AP_DT_DRB_Confirm_Modified_Item_NG_RAN*) __si_allocM( sizeof(SI_E1AP_DT_DRB_Confirm_Modified_Item_NG_RAN));
	memset( obj_DRB_Confirm_Modified_Item_NG_RAN, 0, sizeof( SI_E1AP_DT_DRB_Confirm_Modified_Item_NG_RAN));

	// L:486
	obj_DRB_Confirm_Modified_Item_NG_RAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__Cell_Group_Information( &obj_DRB_Confirm_Modified_Item_NG_RAN->cell_Group_Information);    // L:580
	obj_DRB_Confirm_Modified_Item_NG_RAN->isPresent_cell_Group_Information = 1;


	*pDRB_Confirm_Modified_Item_NG_RAN = obj_DRB_Confirm_Modified_Item_NG_RAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_Failed_List_EUTRAN( SI_E1AP_DT_DRB_Failed_List_EUTRAN ** pDRB_Failed_List_EUTRAN)
{
	SI_E1AP_DT_DRB_Failed_List_EUTRAN * obj_DRB_Failed_List_EUTRAN = NULL; 
	__si_e1ap_init_DRB_Failed_List_EUTRAN( &obj_DRB_Failed_List_EUTRAN);

	// L:1260
	SI_E1AP_DT_DRB_Failed_Item_EUTRAN * objDRB_Failed_Item_EUTRAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_Failed_Item_EUTRAN( &objDRB_Failed_Item_EUTRAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_Failed_List_EUTRAN->DRB_Failed_Item_EUTRAN, (uint8_t*)objDRB_Failed_Item_EUTRAN);

	*pDRB_Failed_List_EUTRAN = obj_DRB_Failed_List_EUTRAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_Failed_Item_EUTRAN( SI_E1AP_DT_DRB_Failed_Item_EUTRAN ** pDRB_Failed_Item_EUTRAN)
{
	SI_E1AP_DT_DRB_Failed_Item_EUTRAN * obj_DRB_Failed_Item_EUTRAN = (SI_E1AP_DT_DRB_Failed_Item_EUTRAN*) __si_allocM( sizeof(SI_E1AP_DT_DRB_Failed_Item_EUTRAN));
	memset( obj_DRB_Failed_Item_EUTRAN, 0, sizeof( SI_E1AP_DT_DRB_Failed_Item_EUTRAN));

	// L:486
	obj_DRB_Failed_Item_EUTRAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__Cause( &obj_DRB_Failed_Item_EUTRAN->cause);    // L:588


	*pDRB_Failed_Item_EUTRAN = obj_DRB_Failed_Item_EUTRAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_Failed_Mod_List_EUTRAN( SI_E1AP_DT_DRB_Failed_Mod_List_EUTRAN ** pDRB_Failed_Mod_List_EUTRAN)
{
	SI_E1AP_DT_DRB_Failed_Mod_List_EUTRAN * obj_DRB_Failed_Mod_List_EUTRAN = NULL; 
	__si_e1ap_init_DRB_Failed_Mod_List_EUTRAN( &obj_DRB_Failed_Mod_List_EUTRAN);

	// L:1260
	SI_E1AP_DT_DRB_Failed_Mod_Item_EUTRAN * objDRB_Failed_Mod_Item_EUTRAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_Failed_Mod_Item_EUTRAN( &objDRB_Failed_Mod_Item_EUTRAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_Failed_Mod_List_EUTRAN->DRB_Failed_Mod_Item_EUTRAN, (uint8_t*)objDRB_Failed_Mod_Item_EUTRAN);

	*pDRB_Failed_Mod_List_EUTRAN = obj_DRB_Failed_Mod_List_EUTRAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_Failed_Mod_Item_EUTRAN( SI_E1AP_DT_DRB_Failed_Mod_Item_EUTRAN ** pDRB_Failed_Mod_Item_EUTRAN)
{
	SI_E1AP_DT_DRB_Failed_Mod_Item_EUTRAN * obj_DRB_Failed_Mod_Item_EUTRAN = (SI_E1AP_DT_DRB_Failed_Mod_Item_EUTRAN*) __si_allocM( sizeof(SI_E1AP_DT_DRB_Failed_Mod_Item_EUTRAN));
	memset( obj_DRB_Failed_Mod_Item_EUTRAN, 0, sizeof( SI_E1AP_DT_DRB_Failed_Mod_Item_EUTRAN));

	// L:486
	obj_DRB_Failed_Mod_Item_EUTRAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__Cause( &obj_DRB_Failed_Mod_Item_EUTRAN->cause);    // L:588


	*pDRB_Failed_Mod_Item_EUTRAN = obj_DRB_Failed_Mod_Item_EUTRAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_Failed_List_NG_RAN( SI_E1AP_DT_DRB_Failed_List_NG_RAN ** pDRB_Failed_List_NG_RAN)
{
	SI_E1AP_DT_DRB_Failed_List_NG_RAN * obj_DRB_Failed_List_NG_RAN = NULL; 
	__si_e1ap_init_DRB_Failed_List_NG_RAN( &obj_DRB_Failed_List_NG_RAN);

	// L:1260
	SI_E1AP_DT_DRB_Failed_Item_NG_RAN * objDRB_Failed_Item_NG_RAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_Failed_Item_NG_RAN( &objDRB_Failed_Item_NG_RAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_Failed_List_NG_RAN->DRB_Failed_Item_NG_RAN, (uint8_t*)objDRB_Failed_Item_NG_RAN);

	*pDRB_Failed_List_NG_RAN = obj_DRB_Failed_List_NG_RAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_Failed_Item_NG_RAN( SI_E1AP_DT_DRB_Failed_Item_NG_RAN ** pDRB_Failed_Item_NG_RAN)
{
	SI_E1AP_DT_DRB_Failed_Item_NG_RAN * obj_DRB_Failed_Item_NG_RAN = (SI_E1AP_DT_DRB_Failed_Item_NG_RAN*) __si_allocM( sizeof(SI_E1AP_DT_DRB_Failed_Item_NG_RAN));
	memset( obj_DRB_Failed_Item_NG_RAN, 0, sizeof( SI_E1AP_DT_DRB_Failed_Item_NG_RAN));

	// L:486
	obj_DRB_Failed_Item_NG_RAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__Cause( &obj_DRB_Failed_Item_NG_RAN->cause);    // L:588


	*pDRB_Failed_Item_NG_RAN = obj_DRB_Failed_Item_NG_RAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_Failed_Mod_List_NG_RAN( SI_E1AP_DT_DRB_Failed_Mod_List_NG_RAN ** pDRB_Failed_Mod_List_NG_RAN)
{
	SI_E1AP_DT_DRB_Failed_Mod_List_NG_RAN * obj_DRB_Failed_Mod_List_NG_RAN = NULL; 
	__si_e1ap_init_DRB_Failed_Mod_List_NG_RAN( &obj_DRB_Failed_Mod_List_NG_RAN);

	// L:1260
	SI_E1AP_DT_DRB_Failed_Mod_Item_NG_RAN * objDRB_Failed_Mod_Item_NG_RAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_Failed_Mod_Item_NG_RAN( &objDRB_Failed_Mod_Item_NG_RAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_Failed_Mod_List_NG_RAN->DRB_Failed_Mod_Item_NG_RAN, (uint8_t*)objDRB_Failed_Mod_Item_NG_RAN);

	*pDRB_Failed_Mod_List_NG_RAN = obj_DRB_Failed_Mod_List_NG_RAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_Failed_Mod_Item_NG_RAN( SI_E1AP_DT_DRB_Failed_Mod_Item_NG_RAN ** pDRB_Failed_Mod_Item_NG_RAN)
{
	SI_E1AP_DT_DRB_Failed_Mod_Item_NG_RAN * obj_DRB_Failed_Mod_Item_NG_RAN = (SI_E1AP_DT_DRB_Failed_Mod_Item_NG_RAN*) __si_allocM( sizeof(SI_E1AP_DT_DRB_Failed_Mod_Item_NG_RAN));
	memset( obj_DRB_Failed_Mod_Item_NG_RAN, 0, sizeof( SI_E1AP_DT_DRB_Failed_Mod_Item_NG_RAN));

	// L:486
	obj_DRB_Failed_Mod_Item_NG_RAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__Cause( &obj_DRB_Failed_Mod_Item_NG_RAN->cause);    // L:588


	*pDRB_Failed_Mod_Item_NG_RAN = obj_DRB_Failed_Mod_Item_NG_RAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_Failed_To_Modify_List_EUTRAN( SI_E1AP_DT_DRB_Failed_To_Modify_List_EUTRAN ** pDRB_Failed_To_Modify_List_EUTRAN)
{
	SI_E1AP_DT_DRB_Failed_To_Modify_List_EUTRAN * obj_DRB_Failed_To_Modify_List_EUTRAN = NULL; 
	__si_e1ap_init_DRB_Failed_To_Modify_List_EUTRAN( &obj_DRB_Failed_To_Modify_List_EUTRAN);

	// L:1260
	SI_E1AP_DT_DRB_Failed_To_Modify_Item_EUTRAN * objDRB_Failed_To_Modify_Item_EUTRAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_Failed_To_Modify_Item_EUTRAN( &objDRB_Failed_To_Modify_Item_EUTRAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_Failed_To_Modify_List_EUTRAN->DRB_Failed_To_Modify_Item_EUTRAN, (uint8_t*)objDRB_Failed_To_Modify_Item_EUTRAN);

	*pDRB_Failed_To_Modify_List_EUTRAN = obj_DRB_Failed_To_Modify_List_EUTRAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_Failed_To_Modify_Item_EUTRAN( SI_E1AP_DT_DRB_Failed_To_Modify_Item_EUTRAN ** pDRB_Failed_To_Modify_Item_EUTRAN)
{
	SI_E1AP_DT_DRB_Failed_To_Modify_Item_EUTRAN * obj_DRB_Failed_To_Modify_Item_EUTRAN = (SI_E1AP_DT_DRB_Failed_To_Modify_Item_EUTRAN*) __si_allocM( sizeof(SI_E1AP_DT_DRB_Failed_To_Modify_Item_EUTRAN));
	memset( obj_DRB_Failed_To_Modify_Item_EUTRAN, 0, sizeof( SI_E1AP_DT_DRB_Failed_To_Modify_Item_EUTRAN));

	// L:486
	obj_DRB_Failed_To_Modify_Item_EUTRAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__Cause( &obj_DRB_Failed_To_Modify_Item_EUTRAN->cause);    // L:588


	*pDRB_Failed_To_Modify_Item_EUTRAN = obj_DRB_Failed_To_Modify_Item_EUTRAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_Failed_To_Modify_List_NG_RAN( SI_E1AP_DT_DRB_Failed_To_Modify_List_NG_RAN ** pDRB_Failed_To_Modify_List_NG_RAN)
{
	SI_E1AP_DT_DRB_Failed_To_Modify_List_NG_RAN * obj_DRB_Failed_To_Modify_List_NG_RAN = NULL; 
	__si_e1ap_init_DRB_Failed_To_Modify_List_NG_RAN( &obj_DRB_Failed_To_Modify_List_NG_RAN);

	// L:1260
	SI_E1AP_DT_DRB_Failed_To_Modify_Item_NG_RAN * objDRB_Failed_To_Modify_Item_NG_RAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_Failed_To_Modify_Item_NG_RAN( &objDRB_Failed_To_Modify_Item_NG_RAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_Failed_To_Modify_List_NG_RAN->DRB_Failed_To_Modify_Item_NG_RAN, (uint8_t*)objDRB_Failed_To_Modify_Item_NG_RAN);

	*pDRB_Failed_To_Modify_List_NG_RAN = obj_DRB_Failed_To_Modify_List_NG_RAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_Failed_To_Modify_Item_NG_RAN( SI_E1AP_DT_DRB_Failed_To_Modify_Item_NG_RAN ** pDRB_Failed_To_Modify_Item_NG_RAN)
{
	SI_E1AP_DT_DRB_Failed_To_Modify_Item_NG_RAN * obj_DRB_Failed_To_Modify_Item_NG_RAN = (SI_E1AP_DT_DRB_Failed_To_Modify_Item_NG_RAN*) __si_allocM( sizeof(SI_E1AP_DT_DRB_Failed_To_Modify_Item_NG_RAN));
	memset( obj_DRB_Failed_To_Modify_Item_NG_RAN, 0, sizeof( SI_E1AP_DT_DRB_Failed_To_Modify_Item_NG_RAN));

	// L:486
	obj_DRB_Failed_To_Modify_Item_NG_RAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__Cause( &obj_DRB_Failed_To_Modify_Item_NG_RAN->cause);    // L:588


	*pDRB_Failed_To_Modify_Item_NG_RAN = obj_DRB_Failed_To_Modify_Item_NG_RAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_Measurement_Results_Information_List( SI_E1AP_DT_DRB_Measurement_Results_Information_List ** pDRB_Measurement_Results_Information_List)
{
	SI_E1AP_DT_DRB_Measurement_Results_Information_List * obj_DRB_Measurement_Results_Information_List = NULL; 
	__si_e1ap_init_DRB_Measurement_Results_Information_List( &obj_DRB_Measurement_Results_Information_List);

	// L:1260
	SI_E1AP_DT_DRB_Measurement_Results_Information_Item * objDRB_Measurement_Results_Information_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_Measurement_Results_Information_Item( &objDRB_Measurement_Results_Information_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_Measurement_Results_Information_List->DRB_Measurement_Results_Information_Item, (uint8_t*)objDRB_Measurement_Results_Information_Item);

	*pDRB_Measurement_Results_Information_List = obj_DRB_Measurement_Results_Information_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_Measurement_Results_Information_Item( SI_E1AP_DT_DRB_Measurement_Results_Information_Item ** pDRB_Measurement_Results_Information_Item)
{
	SI_E1AP_DT_DRB_Measurement_Results_Information_Item * obj_DRB_Measurement_Results_Information_Item = (SI_E1AP_DT_DRB_Measurement_Results_Information_Item*) __si_allocM( sizeof(SI_E1AP_DT_DRB_Measurement_Results_Information_Item));
	memset( obj_DRB_Measurement_Results_Information_Item, 0, sizeof( SI_E1AP_DT_DRB_Measurement_Results_Information_Item));

	// L:486
	obj_DRB_Measurement_Results_Information_Item->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	obj_DRB_Measurement_Results_Information_Item->uL_D1_Result = __getTestINTEGER( 0, 10000);    // L:533
	obj_DRB_Measurement_Results_Information_Item->isPresent_uL_D1_Result = 1;


	*pDRB_Measurement_Results_Information_Item = obj_DRB_Measurement_Results_Information_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_Modified_List_EUTRAN( SI_E1AP_DT_DRB_Modified_List_EUTRAN ** pDRB_Modified_List_EUTRAN)
{
	SI_E1AP_DT_DRB_Modified_List_EUTRAN * obj_DRB_Modified_List_EUTRAN = NULL; 
	__si_e1ap_init_DRB_Modified_List_EUTRAN( &obj_DRB_Modified_List_EUTRAN);

	// L:1260
	SI_E1AP_DT_DRB_Modified_Item_EUTRAN * objDRB_Modified_Item_EUTRAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_Modified_Item_EUTRAN( &objDRB_Modified_Item_EUTRAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_Modified_List_EUTRAN->DRB_Modified_Item_EUTRAN, (uint8_t*)objDRB_Modified_Item_EUTRAN);

	*pDRB_Modified_List_EUTRAN = obj_DRB_Modified_List_EUTRAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_Modified_Item_EUTRAN( SI_E1AP_DT_DRB_Modified_Item_EUTRAN ** pDRB_Modified_Item_EUTRAN)
{
	SI_E1AP_DT_DRB_Modified_Item_EUTRAN * obj_DRB_Modified_Item_EUTRAN = (SI_E1AP_DT_DRB_Modified_Item_EUTRAN*) __si_allocM( sizeof(SI_E1AP_DT_DRB_Modified_Item_EUTRAN));
	memset( obj_DRB_Modified_Item_EUTRAN, 0, sizeof( SI_E1AP_DT_DRB_Modified_Item_EUTRAN));

	// L:486
	obj_DRB_Modified_Item_EUTRAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__UP_TNL_Information( &obj_DRB_Modified_Item_EUTRAN->s1_DL_UP_TNL_Information);    // L:588
	obj_DRB_Modified_Item_EUTRAN->isPresent_s1_DL_UP_TNL_Information = 1;

	__si_e1ap__set_testdata__PDCP_SN_Status_Information( &obj_DRB_Modified_Item_EUTRAN->pDCP_SN_Status_Information);    // L:584
	obj_DRB_Modified_Item_EUTRAN->isPresent_pDCP_SN_Status_Information = 1;

	__si_e1ap__set_testdata__UP_Parameters( &obj_DRB_Modified_Item_EUTRAN->uL_UP_Transport_Parameters);    // L:580
	obj_DRB_Modified_Item_EUTRAN->isPresent_uL_UP_Transport_Parameters = 1;


	*pDRB_Modified_Item_EUTRAN = obj_DRB_Modified_Item_EUTRAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_Modified_List_NG_RAN( SI_E1AP_DT_DRB_Modified_List_NG_RAN ** pDRB_Modified_List_NG_RAN)
{
	SI_E1AP_DT_DRB_Modified_List_NG_RAN * obj_DRB_Modified_List_NG_RAN = NULL; 
	__si_e1ap_init_DRB_Modified_List_NG_RAN( &obj_DRB_Modified_List_NG_RAN);

	// L:1260
	SI_E1AP_DT_DRB_Modified_Item_NG_RAN * objDRB_Modified_Item_NG_RAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_Modified_Item_NG_RAN( &objDRB_Modified_Item_NG_RAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_Modified_List_NG_RAN->DRB_Modified_Item_NG_RAN, (uint8_t*)objDRB_Modified_Item_NG_RAN);

	*pDRB_Modified_List_NG_RAN = obj_DRB_Modified_List_NG_RAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_Modified_Item_NG_RAN( SI_E1AP_DT_DRB_Modified_Item_NG_RAN ** pDRB_Modified_Item_NG_RAN)
{
	SI_E1AP_DT_DRB_Modified_Item_NG_RAN * obj_DRB_Modified_Item_NG_RAN = (SI_E1AP_DT_DRB_Modified_Item_NG_RAN*) __si_allocM( sizeof(SI_E1AP_DT_DRB_Modified_Item_NG_RAN));
	memset( obj_DRB_Modified_Item_NG_RAN, 0, sizeof( SI_E1AP_DT_DRB_Modified_Item_NG_RAN));

	// L:486
	obj_DRB_Modified_Item_NG_RAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__UP_Parameters( &obj_DRB_Modified_Item_NG_RAN->uL_UP_Transport_Parameters);    // L:580
	obj_DRB_Modified_Item_NG_RAN->isPresent_uL_UP_Transport_Parameters = 1;

	__si_e1ap__set_testdata__PDCP_SN_Status_Information( &obj_DRB_Modified_Item_NG_RAN->pDCP_SN_Status_Information);    // L:584
	obj_DRB_Modified_Item_NG_RAN->isPresent_pDCP_SN_Status_Information = 1;

	__si_e1ap__set_testdata__QoS_Flow_List( &obj_DRB_Modified_Item_NG_RAN->flow_Setup_List);    // L:580
	obj_DRB_Modified_Item_NG_RAN->isPresent_flow_Setup_List = 1;

	__si_e1ap__set_testdata__QoS_Flow_Failed_List( &obj_DRB_Modified_Item_NG_RAN->flow_Failed_List);    // L:580
	obj_DRB_Modified_Item_NG_RAN->isPresent_flow_Failed_List = 1;


	*pDRB_Modified_Item_NG_RAN = obj_DRB_Modified_Item_NG_RAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRBRemovedItem_qoS_Flow_Removed_List( SI_E1AP_DT_DRBRemovedItem_qoS_Flow_Removed_List ** pDRBRemovedItem_qoS_Flow_Removed_List)
{
	SI_E1AP_DT_DRBRemovedItem_qoS_Flow_Removed_List * obj_DRBRemovedItem_qoS_Flow_Removed_List = NULL; 
	__si_e1ap_init_DRBRemovedItem_qoS_Flow_Removed_List( &obj_DRBRemovedItem_qoS_Flow_Removed_List);

	// L:1260
	SI_E1AP_DT_QoS_Flow_Removed_Item * objQoS_Flow_Removed_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__QoS_Flow_Removed_Item( &objQoS_Flow_Removed_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRBRemovedItem_qoS_Flow_Removed_List->QoS_Flow_Removed_Item, (uint8_t*)objQoS_Flow_Removed_Item);

	*pDRBRemovedItem_qoS_Flow_Removed_List = obj_DRBRemovedItem_qoS_Flow_Removed_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_Removed_Item( SI_E1AP_DT_DRB_Removed_Item ** pDRB_Removed_Item)
{
	SI_E1AP_DT_DRB_Removed_Item * obj_DRB_Removed_Item = (SI_E1AP_DT_DRB_Removed_Item*) __si_allocM( sizeof(SI_E1AP_DT_DRB_Removed_Item));
	memset( obj_DRB_Removed_Item, 0, sizeof( SI_E1AP_DT_DRB_Removed_Item));

	// L:486
	obj_DRB_Removed_Item->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	obj_DRB_Removed_Item->selected_edRB_Released_In_Session = DRBRemovedItem_dRB_Released_In_Session_released_in_session_val;   // L:529
	obj_DRB_Removed_Item->isPresent_dRB_Released_In_Session = 1;

	__si_e1ap_init_DRBRemovedItem_dRB_Accumulated_Session_Time2( &obj_DRB_Removed_Item->dRB_Accumulated_Session_Time, "\x18\x23\x20\x11\x07", 5);    // L:545
	obj_DRB_Removed_Item->isPresent_dRB_Accumulated_Session_Time = 1;

	__si_e1ap__set_testdata__DRBRemovedItem_qoS_Flow_Removed_List( &obj_DRB_Removed_Item->qoS_Flow_Removed_List);    // L:580
	obj_DRB_Removed_Item->isPresent_qoS_Flow_Removed_List = 1;


	*pDRB_Removed_Item = obj_DRB_Removed_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_Required_To_Modify_List_EUTRAN( SI_E1AP_DT_DRB_Required_To_Modify_List_EUTRAN ** pDRB_Required_To_Modify_List_EUTRAN)
{
	SI_E1AP_DT_DRB_Required_To_Modify_List_EUTRAN * obj_DRB_Required_To_Modify_List_EUTRAN = NULL; 
	__si_e1ap_init_DRB_Required_To_Modify_List_EUTRAN( &obj_DRB_Required_To_Modify_List_EUTRAN);

	// L:1260
	SI_E1AP_DT_DRB_Required_To_Modify_Item_EUTRAN * objDRB_Required_To_Modify_Item_EUTRAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_Required_To_Modify_Item_EUTRAN( &objDRB_Required_To_Modify_Item_EUTRAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_Required_To_Modify_List_EUTRAN->DRB_Required_To_Modify_Item_EUTRAN, (uint8_t*)objDRB_Required_To_Modify_Item_EUTRAN);

	*pDRB_Required_To_Modify_List_EUTRAN = obj_DRB_Required_To_Modify_List_EUTRAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_Required_To_Modify_Item_EUTRAN( SI_E1AP_DT_DRB_Required_To_Modify_Item_EUTRAN ** pDRB_Required_To_Modify_Item_EUTRAN)
{
	SI_E1AP_DT_DRB_Required_To_Modify_Item_EUTRAN * obj_DRB_Required_To_Modify_Item_EUTRAN = (SI_E1AP_DT_DRB_Required_To_Modify_Item_EUTRAN*) __si_allocM( sizeof(SI_E1AP_DT_DRB_Required_To_Modify_Item_EUTRAN));
	memset( obj_DRB_Required_To_Modify_Item_EUTRAN, 0, sizeof( SI_E1AP_DT_DRB_Required_To_Modify_Item_EUTRAN));

	// L:486
	obj_DRB_Required_To_Modify_Item_EUTRAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__UP_TNL_Information( &obj_DRB_Required_To_Modify_Item_EUTRAN->s1_DL_UP_TNL_Information);    // L:588
	obj_DRB_Required_To_Modify_Item_EUTRAN->isPresent_s1_DL_UP_TNL_Information = 1;

	__si_e1ap__set_testdata__GNB_CU_UP_CellGroupRelatedConfiguration( &obj_DRB_Required_To_Modify_Item_EUTRAN->gNB_CU_UP_CellGroupRelatedConfiguration);    // L:580
	obj_DRB_Required_To_Modify_Item_EUTRAN->isPresent_gNB_CU_UP_CellGroupRelatedConfiguration = 1;

	__si_e1ap__set_testdata__Cause( &obj_DRB_Required_To_Modify_Item_EUTRAN->cause);    // L:588
	obj_DRB_Required_To_Modify_Item_EUTRAN->isPresent_cause = 1;


	*pDRB_Required_To_Modify_Item_EUTRAN = obj_DRB_Required_To_Modify_Item_EUTRAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_Required_To_Modify_List_NG_RAN( SI_E1AP_DT_DRB_Required_To_Modify_List_NG_RAN ** pDRB_Required_To_Modify_List_NG_RAN)
{
	SI_E1AP_DT_DRB_Required_To_Modify_List_NG_RAN * obj_DRB_Required_To_Modify_List_NG_RAN = NULL; 
	__si_e1ap_init_DRB_Required_To_Modify_List_NG_RAN( &obj_DRB_Required_To_Modify_List_NG_RAN);

	// L:1260
	SI_E1AP_DT_DRB_Required_To_Modify_Item_NG_RAN * objDRB_Required_To_Modify_Item_NG_RAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_Required_To_Modify_Item_NG_RAN( &objDRB_Required_To_Modify_Item_NG_RAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_Required_To_Modify_List_NG_RAN->DRB_Required_To_Modify_Item_NG_RAN, (uint8_t*)objDRB_Required_To_Modify_Item_NG_RAN);

	*pDRB_Required_To_Modify_List_NG_RAN = obj_DRB_Required_To_Modify_List_NG_RAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_Required_To_Modify_Item_NG_RAN( SI_E1AP_DT_DRB_Required_To_Modify_Item_NG_RAN ** pDRB_Required_To_Modify_Item_NG_RAN)
{
	SI_E1AP_DT_DRB_Required_To_Modify_Item_NG_RAN * obj_DRB_Required_To_Modify_Item_NG_RAN = (SI_E1AP_DT_DRB_Required_To_Modify_Item_NG_RAN*) __si_allocM( sizeof(SI_E1AP_DT_DRB_Required_To_Modify_Item_NG_RAN));
	memset( obj_DRB_Required_To_Modify_Item_NG_RAN, 0, sizeof( SI_E1AP_DT_DRB_Required_To_Modify_Item_NG_RAN));

	// L:486
	obj_DRB_Required_To_Modify_Item_NG_RAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__GNB_CU_UP_CellGroupRelatedConfiguration( &obj_DRB_Required_To_Modify_Item_NG_RAN->gNB_CU_UP_CellGroupRelatedConfiguration);    // L:580
	obj_DRB_Required_To_Modify_Item_NG_RAN->isPresent_gNB_CU_UP_CellGroupRelatedConfiguration = 1;

	__si_e1ap__set_testdata__QoS_Flow_List( &obj_DRB_Required_To_Modify_Item_NG_RAN->flow_To_Remove);    // L:580
	obj_DRB_Required_To_Modify_Item_NG_RAN->isPresent_flow_To_Remove = 1;

	__si_e1ap__set_testdata__Cause( &obj_DRB_Required_To_Modify_Item_NG_RAN->cause);    // L:588
	obj_DRB_Required_To_Modify_Item_NG_RAN->isPresent_cause = 1;


	*pDRB_Required_To_Modify_Item_NG_RAN = obj_DRB_Required_To_Modify_Item_NG_RAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_Setup_List_EUTRAN( SI_E1AP_DT_DRB_Setup_List_EUTRAN ** pDRB_Setup_List_EUTRAN)
{
	SI_E1AP_DT_DRB_Setup_List_EUTRAN * obj_DRB_Setup_List_EUTRAN = NULL; 
	__si_e1ap_init_DRB_Setup_List_EUTRAN( &obj_DRB_Setup_List_EUTRAN);

	// L:1260
	SI_E1AP_DT_DRB_Setup_Item_EUTRAN * objDRB_Setup_Item_EUTRAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_Setup_Item_EUTRAN( &objDRB_Setup_Item_EUTRAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_Setup_List_EUTRAN->DRB_Setup_Item_EUTRAN, (uint8_t*)objDRB_Setup_Item_EUTRAN);

	*pDRB_Setup_List_EUTRAN = obj_DRB_Setup_List_EUTRAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_Setup_Item_EUTRAN( SI_E1AP_DT_DRB_Setup_Item_EUTRAN ** pDRB_Setup_Item_EUTRAN)
{
	SI_E1AP_DT_DRB_Setup_Item_EUTRAN * obj_DRB_Setup_Item_EUTRAN = (SI_E1AP_DT_DRB_Setup_Item_EUTRAN*) __si_allocM( sizeof(SI_E1AP_DT_DRB_Setup_Item_EUTRAN));
	memset( obj_DRB_Setup_Item_EUTRAN, 0, sizeof( SI_E1AP_DT_DRB_Setup_Item_EUTRAN));

	// L:486
	obj_DRB_Setup_Item_EUTRAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__UP_TNL_Information( &obj_DRB_Setup_Item_EUTRAN->s1_DL_UP_TNL_Information);    // L:588

	__si_e1ap__set_testdata__Data_Forwarding_Information( &obj_DRB_Setup_Item_EUTRAN->data_Forwarding_Information_Response);    // L:584
	obj_DRB_Setup_Item_EUTRAN->isPresent_data_Forwarding_Information_Response = 1;

	__si_e1ap__set_testdata__UP_Parameters( &obj_DRB_Setup_Item_EUTRAN->uL_UP_Transport_Parameters);    // L:580

	obj_DRB_Setup_Item_EUTRAN->selected_es1_DL_UP_Unchanged = DRBSetupItemEUTRAN_s1_DL_UP_Unchanged_true_val;   // L:529
	obj_DRB_Setup_Item_EUTRAN->isPresent_s1_DL_UP_Unchanged = 1;


	*pDRB_Setup_Item_EUTRAN = obj_DRB_Setup_Item_EUTRAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_Setup_Mod_List_EUTRAN( SI_E1AP_DT_DRB_Setup_Mod_List_EUTRAN ** pDRB_Setup_Mod_List_EUTRAN)
{
	SI_E1AP_DT_DRB_Setup_Mod_List_EUTRAN * obj_DRB_Setup_Mod_List_EUTRAN = NULL; 
	__si_e1ap_init_DRB_Setup_Mod_List_EUTRAN( &obj_DRB_Setup_Mod_List_EUTRAN);

	// L:1260
	SI_E1AP_DT_DRB_Setup_Mod_Item_EUTRAN * objDRB_Setup_Mod_Item_EUTRAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_Setup_Mod_Item_EUTRAN( &objDRB_Setup_Mod_Item_EUTRAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_Setup_Mod_List_EUTRAN->DRB_Setup_Mod_Item_EUTRAN, (uint8_t*)objDRB_Setup_Mod_Item_EUTRAN);

	*pDRB_Setup_Mod_List_EUTRAN = obj_DRB_Setup_Mod_List_EUTRAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_Setup_Mod_Item_EUTRAN( SI_E1AP_DT_DRB_Setup_Mod_Item_EUTRAN ** pDRB_Setup_Mod_Item_EUTRAN)
{
	SI_E1AP_DT_DRB_Setup_Mod_Item_EUTRAN * obj_DRB_Setup_Mod_Item_EUTRAN = (SI_E1AP_DT_DRB_Setup_Mod_Item_EUTRAN*) __si_allocM( sizeof(SI_E1AP_DT_DRB_Setup_Mod_Item_EUTRAN));
	memset( obj_DRB_Setup_Mod_Item_EUTRAN, 0, sizeof( SI_E1AP_DT_DRB_Setup_Mod_Item_EUTRAN));

	// L:486
	obj_DRB_Setup_Mod_Item_EUTRAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__UP_TNL_Information( &obj_DRB_Setup_Mod_Item_EUTRAN->s1_DL_UP_TNL_Information);    // L:588

	__si_e1ap__set_testdata__Data_Forwarding_Information( &obj_DRB_Setup_Mod_Item_EUTRAN->data_Forwarding_Information_Response);    // L:584
	obj_DRB_Setup_Mod_Item_EUTRAN->isPresent_data_Forwarding_Information_Response = 1;

	__si_e1ap__set_testdata__UP_Parameters( &obj_DRB_Setup_Mod_Item_EUTRAN->uL_UP_Transport_Parameters);    // L:580


	*pDRB_Setup_Mod_Item_EUTRAN = obj_DRB_Setup_Mod_Item_EUTRAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_Setup_List_NG_RAN( SI_E1AP_DT_DRB_Setup_List_NG_RAN ** pDRB_Setup_List_NG_RAN)
{
	SI_E1AP_DT_DRB_Setup_List_NG_RAN * obj_DRB_Setup_List_NG_RAN = NULL; 
	__si_e1ap_init_DRB_Setup_List_NG_RAN( &obj_DRB_Setup_List_NG_RAN);

	// L:1260
	SI_E1AP_DT_DRB_Setup_Item_NG_RAN * objDRB_Setup_Item_NG_RAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_Setup_Item_NG_RAN( &objDRB_Setup_Item_NG_RAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_Setup_List_NG_RAN->DRB_Setup_Item_NG_RAN, (uint8_t*)objDRB_Setup_Item_NG_RAN);

	*pDRB_Setup_List_NG_RAN = obj_DRB_Setup_List_NG_RAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_Setup_Item_NG_RAN( SI_E1AP_DT_DRB_Setup_Item_NG_RAN ** pDRB_Setup_Item_NG_RAN)
{
	SI_E1AP_DT_DRB_Setup_Item_NG_RAN * obj_DRB_Setup_Item_NG_RAN = (SI_E1AP_DT_DRB_Setup_Item_NG_RAN*) __si_allocM( sizeof(SI_E1AP_DT_DRB_Setup_Item_NG_RAN));
	memset( obj_DRB_Setup_Item_NG_RAN, 0, sizeof( SI_E1AP_DT_DRB_Setup_Item_NG_RAN));

	// L:486
	obj_DRB_Setup_Item_NG_RAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__Data_Forwarding_Information( &obj_DRB_Setup_Item_NG_RAN->dRB_data_Forwarding_Information_Response);    // L:584
	obj_DRB_Setup_Item_NG_RAN->isPresent_dRB_data_Forwarding_Information_Response = 1;

	__si_e1ap__set_testdata__UP_Parameters( &obj_DRB_Setup_Item_NG_RAN->uL_UP_Transport_Parameters);    // L:580

	__si_e1ap__set_testdata__QoS_Flow_List( &obj_DRB_Setup_Item_NG_RAN->flow_Setup_List);    // L:580

	__si_e1ap__set_testdata__QoS_Flow_Failed_List( &obj_DRB_Setup_Item_NG_RAN->flow_Failed_List);    // L:580
	obj_DRB_Setup_Item_NG_RAN->isPresent_flow_Failed_List = 1;


	*pDRB_Setup_Item_NG_RAN = obj_DRB_Setup_Item_NG_RAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_Setup_Mod_List_NG_RAN( SI_E1AP_DT_DRB_Setup_Mod_List_NG_RAN ** pDRB_Setup_Mod_List_NG_RAN)
{
	SI_E1AP_DT_DRB_Setup_Mod_List_NG_RAN * obj_DRB_Setup_Mod_List_NG_RAN = NULL; 
	__si_e1ap_init_DRB_Setup_Mod_List_NG_RAN( &obj_DRB_Setup_Mod_List_NG_RAN);

	// L:1260
	SI_E1AP_DT_DRB_Setup_Mod_Item_NG_RAN * objDRB_Setup_Mod_Item_NG_RAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_Setup_Mod_Item_NG_RAN( &objDRB_Setup_Mod_Item_NG_RAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_Setup_Mod_List_NG_RAN->DRB_Setup_Mod_Item_NG_RAN, (uint8_t*)objDRB_Setup_Mod_Item_NG_RAN);

	*pDRB_Setup_Mod_List_NG_RAN = obj_DRB_Setup_Mod_List_NG_RAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_Setup_Mod_Item_NG_RAN( SI_E1AP_DT_DRB_Setup_Mod_Item_NG_RAN ** pDRB_Setup_Mod_Item_NG_RAN)
{
	SI_E1AP_DT_DRB_Setup_Mod_Item_NG_RAN * obj_DRB_Setup_Mod_Item_NG_RAN = (SI_E1AP_DT_DRB_Setup_Mod_Item_NG_RAN*) __si_allocM( sizeof(SI_E1AP_DT_DRB_Setup_Mod_Item_NG_RAN));
	memset( obj_DRB_Setup_Mod_Item_NG_RAN, 0, sizeof( SI_E1AP_DT_DRB_Setup_Mod_Item_NG_RAN));

	// L:486
	obj_DRB_Setup_Mod_Item_NG_RAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__Data_Forwarding_Information( &obj_DRB_Setup_Mod_Item_NG_RAN->dRB_data_Forwarding_Information_Response);    // L:584
	obj_DRB_Setup_Mod_Item_NG_RAN->isPresent_dRB_data_Forwarding_Information_Response = 1;

	__si_e1ap__set_testdata__UP_Parameters( &obj_DRB_Setup_Mod_Item_NG_RAN->uL_UP_Transport_Parameters);    // L:580

	__si_e1ap__set_testdata__QoS_Flow_List( &obj_DRB_Setup_Mod_Item_NG_RAN->flow_Setup_List);    // L:580

	__si_e1ap__set_testdata__QoS_Flow_Failed_List( &obj_DRB_Setup_Mod_Item_NG_RAN->flow_Failed_List);    // L:580
	obj_DRB_Setup_Mod_Item_NG_RAN->isPresent_flow_Failed_List = 1;


	*pDRB_Setup_Mod_Item_NG_RAN = obj_DRB_Setup_Mod_Item_NG_RAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_Status_Item( SI_E1AP_DT_DRB_Status_Item ** pDRB_Status_Item)
{
	SI_E1AP_DT_DRB_Status_Item * obj_DRB_Status_Item = (SI_E1AP_DT_DRB_Status_Item*) __si_allocM( sizeof(SI_E1AP_DT_DRB_Status_Item));
	memset( obj_DRB_Status_Item, 0, sizeof( SI_E1AP_DT_DRB_Status_Item));

	// L:486
	obj_DRB_Status_Item->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__PDCP_Count( &obj_DRB_Status_Item->pDCP_DL_Count);    // L:584
	obj_DRB_Status_Item->isPresent_pDCP_DL_Count = 1;

	__si_e1ap__set_testdata__PDCP_Count( &obj_DRB_Status_Item->pDCP_UL_Count);    // L:584
	obj_DRB_Status_Item->isPresent_pDCP_UL_Count = 1;


	*pDRB_Status_Item = obj_DRB_Status_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRBs_Subject_To_Counter_Check_List_EUTRAN( SI_E1AP_DT_DRBs_Subject_To_Counter_Check_List_EUTRAN ** pDRBs_Subject_To_Counter_Check_List_EUTRAN)
{
	SI_E1AP_DT_DRBs_Subject_To_Counter_Check_List_EUTRAN * obj_DRBs_Subject_To_Counter_Check_List_EUTRAN = NULL; 
	__si_e1ap_init_DRBs_Subject_To_Counter_Check_List_EUTRAN( &obj_DRBs_Subject_To_Counter_Check_List_EUTRAN);

	// L:1260
	SI_E1AP_DT_DRBs_Subject_To_Counter_Check_Item_EUTRAN * objDRBs_Subject_To_Counter_Check_Item_EUTRAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRBs_Subject_To_Counter_Check_Item_EUTRAN( &objDRBs_Subject_To_Counter_Check_Item_EUTRAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRBs_Subject_To_Counter_Check_List_EUTRAN->DRBs_Subject_To_Counter_Check_Item_EUTRAN, (uint8_t*)objDRBs_Subject_To_Counter_Check_Item_EUTRAN);

	*pDRBs_Subject_To_Counter_Check_List_EUTRAN = obj_DRBs_Subject_To_Counter_Check_List_EUTRAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRBs_Subject_To_Counter_Check_Item_EUTRAN( SI_E1AP_DT_DRBs_Subject_To_Counter_Check_Item_EUTRAN ** pDRBs_Subject_To_Counter_Check_Item_EUTRAN)
{
	SI_E1AP_DT_DRBs_Subject_To_Counter_Check_Item_EUTRAN * obj_DRBs_Subject_To_Counter_Check_Item_EUTRAN = (SI_E1AP_DT_DRBs_Subject_To_Counter_Check_Item_EUTRAN*) __si_allocM( sizeof(SI_E1AP_DT_DRBs_Subject_To_Counter_Check_Item_EUTRAN));
	memset( obj_DRBs_Subject_To_Counter_Check_Item_EUTRAN, 0, sizeof( SI_E1AP_DT_DRBs_Subject_To_Counter_Check_Item_EUTRAN));

	// L:486
	obj_DRBs_Subject_To_Counter_Check_Item_EUTRAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__PDCP_Count( &obj_DRBs_Subject_To_Counter_Check_Item_EUTRAN->pDCP_UL_Count);    // L:584

	__si_e1ap__set_testdata__PDCP_Count( &obj_DRBs_Subject_To_Counter_Check_Item_EUTRAN->pDCP_DL_Count);    // L:584


	*pDRBs_Subject_To_Counter_Check_Item_EUTRAN = obj_DRBs_Subject_To_Counter_Check_Item_EUTRAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRBs_Subject_To_Counter_Check_List_NG_RAN( SI_E1AP_DT_DRBs_Subject_To_Counter_Check_List_NG_RAN ** pDRBs_Subject_To_Counter_Check_List_NG_RAN)
{
	SI_E1AP_DT_DRBs_Subject_To_Counter_Check_List_NG_RAN * obj_DRBs_Subject_To_Counter_Check_List_NG_RAN = NULL; 
	__si_e1ap_init_DRBs_Subject_To_Counter_Check_List_NG_RAN( &obj_DRBs_Subject_To_Counter_Check_List_NG_RAN);

	// L:1260
	SI_E1AP_DT_DRBs_Subject_To_Counter_Check_Item_NG_RAN * objDRBs_Subject_To_Counter_Check_Item_NG_RAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRBs_Subject_To_Counter_Check_Item_NG_RAN( &objDRBs_Subject_To_Counter_Check_Item_NG_RAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRBs_Subject_To_Counter_Check_List_NG_RAN->DRBs_Subject_To_Counter_Check_Item_NG_RAN, (uint8_t*)objDRBs_Subject_To_Counter_Check_Item_NG_RAN);

	*pDRBs_Subject_To_Counter_Check_List_NG_RAN = obj_DRBs_Subject_To_Counter_Check_List_NG_RAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRBs_Subject_To_Counter_Check_Item_NG_RAN( SI_E1AP_DT_DRBs_Subject_To_Counter_Check_Item_NG_RAN ** pDRBs_Subject_To_Counter_Check_Item_NG_RAN)
{
	SI_E1AP_DT_DRBs_Subject_To_Counter_Check_Item_NG_RAN * obj_DRBs_Subject_To_Counter_Check_Item_NG_RAN = (SI_E1AP_DT_DRBs_Subject_To_Counter_Check_Item_NG_RAN*) __si_allocM( sizeof(SI_E1AP_DT_DRBs_Subject_To_Counter_Check_Item_NG_RAN));
	memset( obj_DRBs_Subject_To_Counter_Check_Item_NG_RAN, 0, sizeof( SI_E1AP_DT_DRBs_Subject_To_Counter_Check_Item_NG_RAN));

	// L:486
	obj_DRBs_Subject_To_Counter_Check_Item_NG_RAN->pDU_Session_ID = __getTestINTEGER( 0, 255);    // L:533

	obj_DRBs_Subject_To_Counter_Check_Item_NG_RAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__PDCP_Count( &obj_DRBs_Subject_To_Counter_Check_Item_NG_RAN->pDCP_UL_Count);    // L:584

	__si_e1ap__set_testdata__PDCP_Count( &obj_DRBs_Subject_To_Counter_Check_Item_NG_RAN->pDCP_DL_Count);    // L:584


	*pDRBs_Subject_To_Counter_Check_Item_NG_RAN = obj_DRBs_Subject_To_Counter_Check_Item_NG_RAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRBs_Subject_To_Early_Forwarding_List( SI_E1AP_DT_DRBs_Subject_To_Early_Forwarding_List ** pDRBs_Subject_To_Early_Forwarding_List)
{
	SI_E1AP_DT_DRBs_Subject_To_Early_Forwarding_List * obj_DRBs_Subject_To_Early_Forwarding_List = NULL; 
	__si_e1ap_init_DRBs_Subject_To_Early_Forwarding_List( &obj_DRBs_Subject_To_Early_Forwarding_List);

	// L:1260
	SI_E1AP_DT_DRBs_Subject_To_Early_Forwarding_Item * objDRBs_Subject_To_Early_Forwarding_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRBs_Subject_To_Early_Forwarding_Item( &objDRBs_Subject_To_Early_Forwarding_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRBs_Subject_To_Early_Forwarding_List->DRBs_Subject_To_Early_Forwarding_Item, (uint8_t*)objDRBs_Subject_To_Early_Forwarding_Item);

	*pDRBs_Subject_To_Early_Forwarding_List = obj_DRBs_Subject_To_Early_Forwarding_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRBs_Subject_To_Early_Forwarding_Item( SI_E1AP_DT_DRBs_Subject_To_Early_Forwarding_Item ** pDRBs_Subject_To_Early_Forwarding_Item)
{
	SI_E1AP_DT_DRBs_Subject_To_Early_Forwarding_Item * obj_DRBs_Subject_To_Early_Forwarding_Item = (SI_E1AP_DT_DRBs_Subject_To_Early_Forwarding_Item*) __si_allocM( sizeof(SI_E1AP_DT_DRBs_Subject_To_Early_Forwarding_Item));
	memset( obj_DRBs_Subject_To_Early_Forwarding_Item, 0, sizeof( SI_E1AP_DT_DRBs_Subject_To_Early_Forwarding_Item));

	// L:486
	obj_DRBs_Subject_To_Early_Forwarding_Item->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__PDCP_Count( &obj_DRBs_Subject_To_Early_Forwarding_Item->dLCountValue);    // L:584


	*pDRBs_Subject_To_Early_Forwarding_Item = obj_DRBs_Subject_To_Early_Forwarding_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_To_Modify_List_EUTRAN( SI_E1AP_DT_DRB_To_Modify_List_EUTRAN ** pDRB_To_Modify_List_EUTRAN)
{
	SI_E1AP_DT_DRB_To_Modify_List_EUTRAN * obj_DRB_To_Modify_List_EUTRAN = NULL; 
	__si_e1ap_init_DRB_To_Modify_List_EUTRAN( &obj_DRB_To_Modify_List_EUTRAN);

	// L:1260
	SI_E1AP_DT_DRB_To_Modify_Item_EUTRAN * objDRB_To_Modify_Item_EUTRAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_To_Modify_Item_EUTRAN( &objDRB_To_Modify_Item_EUTRAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_To_Modify_List_EUTRAN->DRB_To_Modify_Item_EUTRAN, (uint8_t*)objDRB_To_Modify_Item_EUTRAN);

	*pDRB_To_Modify_List_EUTRAN = obj_DRB_To_Modify_List_EUTRAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_To_Modify_Item_EUTRAN( SI_E1AP_DT_DRB_To_Modify_Item_EUTRAN ** pDRB_To_Modify_Item_EUTRAN)
{
	SI_E1AP_DT_DRB_To_Modify_Item_EUTRAN * obj_DRB_To_Modify_Item_EUTRAN = (SI_E1AP_DT_DRB_To_Modify_Item_EUTRAN*) __si_allocM( sizeof(SI_E1AP_DT_DRB_To_Modify_Item_EUTRAN));
	memset( obj_DRB_To_Modify_Item_EUTRAN, 0, sizeof( SI_E1AP_DT_DRB_To_Modify_Item_EUTRAN));

	// L:486
	obj_DRB_To_Modify_Item_EUTRAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__PDCP_Configuration( &obj_DRB_To_Modify_Item_EUTRAN->pDCP_Configuration);    // L:584
	obj_DRB_To_Modify_Item_EUTRAN->isPresent_pDCP_Configuration = 1;

	__si_e1ap__set_testdata__EUTRAN_QoS( &obj_DRB_To_Modify_Item_EUTRAN->eUTRAN_QoS);    // L:584
	obj_DRB_To_Modify_Item_EUTRAN->isPresent_eUTRAN_QoS = 1;

	__si_e1ap__set_testdata__UP_TNL_Information( &obj_DRB_To_Modify_Item_EUTRAN->s1_UL_UP_TNL_Information);    // L:588
	obj_DRB_To_Modify_Item_EUTRAN->isPresent_s1_UL_UP_TNL_Information = 1;

	__si_e1ap__set_testdata__Data_Forwarding_Information( &obj_DRB_To_Modify_Item_EUTRAN->data_Forwarding_Information);    // L:584
	obj_DRB_To_Modify_Item_EUTRAN->isPresent_data_Forwarding_Information = 1;

	obj_DRB_To_Modify_Item_EUTRAN->selected_epDCP_SN_Status_Request = PDCP_SN_Status_Request_requested_val;   // L:529
	obj_DRB_To_Modify_Item_EUTRAN->isPresent_pDCP_SN_Status_Request = 1;

	__si_e1ap__set_testdata__PDCP_SN_Status_Information( &obj_DRB_To_Modify_Item_EUTRAN->pDCP_SN_Status_Information);    // L:584
	obj_DRB_To_Modify_Item_EUTRAN->isPresent_pDCP_SN_Status_Information = 1;

	__si_e1ap__set_testdata__UP_Parameters( &obj_DRB_To_Modify_Item_EUTRAN->dL_UP_Parameters);    // L:580
	obj_DRB_To_Modify_Item_EUTRAN->isPresent_dL_UP_Parameters = 1;

	__si_e1ap__set_testdata__Cell_Group_Information( &obj_DRB_To_Modify_Item_EUTRAN->cell_Group_To_Add);    // L:580
	obj_DRB_To_Modify_Item_EUTRAN->isPresent_cell_Group_To_Add = 1;

	__si_e1ap__set_testdata__Cell_Group_Information( &obj_DRB_To_Modify_Item_EUTRAN->cell_Group_To_Modify);    // L:580
	obj_DRB_To_Modify_Item_EUTRAN->isPresent_cell_Group_To_Modify = 1;

	__si_e1ap__set_testdata__Cell_Group_Information( &obj_DRB_To_Modify_Item_EUTRAN->cell_Group_To_Remove);    // L:580
	obj_DRB_To_Modify_Item_EUTRAN->isPresent_cell_Group_To_Remove = 1;

	obj_DRB_To_Modify_Item_EUTRAN->dRB_Inactivity_Timer = __getTestINTEGER( 1, 7200);    // L:533
	obj_DRB_To_Modify_Item_EUTRAN->isPresent_dRB_Inactivity_Timer = 1;


	*pDRB_To_Modify_Item_EUTRAN = obj_DRB_To_Modify_Item_EUTRAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_To_Modify_List_NG_RAN( SI_E1AP_DT_DRB_To_Modify_List_NG_RAN ** pDRB_To_Modify_List_NG_RAN)
{
	SI_E1AP_DT_DRB_To_Modify_List_NG_RAN * obj_DRB_To_Modify_List_NG_RAN = NULL; 
	__si_e1ap_init_DRB_To_Modify_List_NG_RAN( &obj_DRB_To_Modify_List_NG_RAN);

	// L:1260
	SI_E1AP_DT_DRB_To_Modify_Item_NG_RAN * objDRB_To_Modify_Item_NG_RAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_To_Modify_Item_NG_RAN( &objDRB_To_Modify_Item_NG_RAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_To_Modify_List_NG_RAN->DRB_To_Modify_Item_NG_RAN, (uint8_t*)objDRB_To_Modify_Item_NG_RAN);

	*pDRB_To_Modify_List_NG_RAN = obj_DRB_To_Modify_List_NG_RAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_To_Modify_Item_NG_RAN( SI_E1AP_DT_DRB_To_Modify_Item_NG_RAN ** pDRB_To_Modify_Item_NG_RAN)
{
	SI_E1AP_DT_DRB_To_Modify_Item_NG_RAN * obj_DRB_To_Modify_Item_NG_RAN = (SI_E1AP_DT_DRB_To_Modify_Item_NG_RAN*) __si_allocM( sizeof(SI_E1AP_DT_DRB_To_Modify_Item_NG_RAN));
	memset( obj_DRB_To_Modify_Item_NG_RAN, 0, sizeof( SI_E1AP_DT_DRB_To_Modify_Item_NG_RAN));

	// L:486
	obj_DRB_To_Modify_Item_NG_RAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__SDAP_Configuration( &obj_DRB_To_Modify_Item_NG_RAN->sDAP_Configuration);    // L:584
	obj_DRB_To_Modify_Item_NG_RAN->isPresent_sDAP_Configuration = 1;

	__si_e1ap__set_testdata__PDCP_Configuration( &obj_DRB_To_Modify_Item_NG_RAN->pDCP_Configuration);    // L:584
	obj_DRB_To_Modify_Item_NG_RAN->isPresent_pDCP_Configuration = 1;

	__si_e1ap__set_testdata__Data_Forwarding_Information( &obj_DRB_To_Modify_Item_NG_RAN->dRB_Data_Forwarding_Information);    // L:584
	obj_DRB_To_Modify_Item_NG_RAN->isPresent_dRB_Data_Forwarding_Information = 1;

	obj_DRB_To_Modify_Item_NG_RAN->selected_epDCP_SN_Status_Request = PDCP_SN_Status_Request_requested_val;   // L:529
	obj_DRB_To_Modify_Item_NG_RAN->isPresent_pDCP_SN_Status_Request = 1;

	__si_e1ap__set_testdata__PDCP_SN_Status_Information( &obj_DRB_To_Modify_Item_NG_RAN->pdcp_SN_Status_Information);    // L:584
	obj_DRB_To_Modify_Item_NG_RAN->isPresent_pdcp_SN_Status_Information = 1;

	__si_e1ap__set_testdata__UP_Parameters( &obj_DRB_To_Modify_Item_NG_RAN->dL_UP_Parameters);    // L:580
	obj_DRB_To_Modify_Item_NG_RAN->isPresent_dL_UP_Parameters = 1;

	__si_e1ap__set_testdata__Cell_Group_Information( &obj_DRB_To_Modify_Item_NG_RAN->cell_Group_To_Add);    // L:580
	obj_DRB_To_Modify_Item_NG_RAN->isPresent_cell_Group_To_Add = 1;

	__si_e1ap__set_testdata__Cell_Group_Information( &obj_DRB_To_Modify_Item_NG_RAN->cell_Group_To_Modify);    // L:580
	obj_DRB_To_Modify_Item_NG_RAN->isPresent_cell_Group_To_Modify = 1;

	__si_e1ap__set_testdata__Cell_Group_Information( &obj_DRB_To_Modify_Item_NG_RAN->cell_Group_To_Remove);    // L:580
	obj_DRB_To_Modify_Item_NG_RAN->isPresent_cell_Group_To_Remove = 1;

	__si_e1ap__set_testdata__QoS_Flow_QoS_Parameter_List( &obj_DRB_To_Modify_Item_NG_RAN->flow_Mapping_Information);    // L:580
	obj_DRB_To_Modify_Item_NG_RAN->isPresent_flow_Mapping_Information = 1;

	obj_DRB_To_Modify_Item_NG_RAN->dRB_Inactivity_Timer = __getTestINTEGER( 1, 7200);    // L:533
	obj_DRB_To_Modify_Item_NG_RAN->isPresent_dRB_Inactivity_Timer = 1;


	*pDRB_To_Modify_Item_NG_RAN = obj_DRB_To_Modify_Item_NG_RAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_To_Remove_List_EUTRAN( SI_E1AP_DT_DRB_To_Remove_List_EUTRAN ** pDRB_To_Remove_List_EUTRAN)
{
	SI_E1AP_DT_DRB_To_Remove_List_EUTRAN * obj_DRB_To_Remove_List_EUTRAN = NULL; 
	__si_e1ap_init_DRB_To_Remove_List_EUTRAN( &obj_DRB_To_Remove_List_EUTRAN);

	// L:1260
	SI_E1AP_DT_DRB_To_Remove_Item_EUTRAN * objDRB_To_Remove_Item_EUTRAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_To_Remove_Item_EUTRAN( &objDRB_To_Remove_Item_EUTRAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_To_Remove_List_EUTRAN->DRB_To_Remove_Item_EUTRAN, (uint8_t*)objDRB_To_Remove_Item_EUTRAN);

	*pDRB_To_Remove_List_EUTRAN = obj_DRB_To_Remove_List_EUTRAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_To_Remove_Item_EUTRAN( SI_E1AP_DT_DRB_To_Remove_Item_EUTRAN ** pDRB_To_Remove_Item_EUTRAN)
{
	SI_E1AP_DT_DRB_To_Remove_Item_EUTRAN * obj_DRB_To_Remove_Item_EUTRAN = (SI_E1AP_DT_DRB_To_Remove_Item_EUTRAN*) __si_allocM( sizeof(SI_E1AP_DT_DRB_To_Remove_Item_EUTRAN));
	memset( obj_DRB_To_Remove_Item_EUTRAN, 0, sizeof( SI_E1AP_DT_DRB_To_Remove_Item_EUTRAN));

	// L:486
	obj_DRB_To_Remove_Item_EUTRAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533


	*pDRB_To_Remove_Item_EUTRAN = obj_DRB_To_Remove_Item_EUTRAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_Required_To_Remove_List_EUTRAN( SI_E1AP_DT_DRB_Required_To_Remove_List_EUTRAN ** pDRB_Required_To_Remove_List_EUTRAN)
{
	SI_E1AP_DT_DRB_Required_To_Remove_List_EUTRAN * obj_DRB_Required_To_Remove_List_EUTRAN = NULL; 
	__si_e1ap_init_DRB_Required_To_Remove_List_EUTRAN( &obj_DRB_Required_To_Remove_List_EUTRAN);

	// L:1260
	SI_E1AP_DT_DRB_Required_To_Remove_Item_EUTRAN * objDRB_Required_To_Remove_Item_EUTRAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_Required_To_Remove_Item_EUTRAN( &objDRB_Required_To_Remove_Item_EUTRAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_Required_To_Remove_List_EUTRAN->DRB_Required_To_Remove_Item_EUTRAN, (uint8_t*)objDRB_Required_To_Remove_Item_EUTRAN);

	*pDRB_Required_To_Remove_List_EUTRAN = obj_DRB_Required_To_Remove_List_EUTRAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_Required_To_Remove_Item_EUTRAN( SI_E1AP_DT_DRB_Required_To_Remove_Item_EUTRAN ** pDRB_Required_To_Remove_Item_EUTRAN)
{
	SI_E1AP_DT_DRB_Required_To_Remove_Item_EUTRAN * obj_DRB_Required_To_Remove_Item_EUTRAN = (SI_E1AP_DT_DRB_Required_To_Remove_Item_EUTRAN*) __si_allocM( sizeof(SI_E1AP_DT_DRB_Required_To_Remove_Item_EUTRAN));
	memset( obj_DRB_Required_To_Remove_Item_EUTRAN, 0, sizeof( SI_E1AP_DT_DRB_Required_To_Remove_Item_EUTRAN));

	// L:486
	obj_DRB_Required_To_Remove_Item_EUTRAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__Cause( &obj_DRB_Required_To_Remove_Item_EUTRAN->cause);    // L:588


	*pDRB_Required_To_Remove_Item_EUTRAN = obj_DRB_Required_To_Remove_Item_EUTRAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_To_Remove_List_NG_RAN( SI_E1AP_DT_DRB_To_Remove_List_NG_RAN ** pDRB_To_Remove_List_NG_RAN)
{
	SI_E1AP_DT_DRB_To_Remove_List_NG_RAN * obj_DRB_To_Remove_List_NG_RAN = NULL; 
	__si_e1ap_init_DRB_To_Remove_List_NG_RAN( &obj_DRB_To_Remove_List_NG_RAN);

	// L:1260
	SI_E1AP_DT_DRB_To_Remove_Item_NG_RAN * objDRB_To_Remove_Item_NG_RAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_To_Remove_Item_NG_RAN( &objDRB_To_Remove_Item_NG_RAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_To_Remove_List_NG_RAN->DRB_To_Remove_Item_NG_RAN, (uint8_t*)objDRB_To_Remove_Item_NG_RAN);

	*pDRB_To_Remove_List_NG_RAN = obj_DRB_To_Remove_List_NG_RAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_To_Remove_Item_NG_RAN( SI_E1AP_DT_DRB_To_Remove_Item_NG_RAN ** pDRB_To_Remove_Item_NG_RAN)
{
	SI_E1AP_DT_DRB_To_Remove_Item_NG_RAN * obj_DRB_To_Remove_Item_NG_RAN = (SI_E1AP_DT_DRB_To_Remove_Item_NG_RAN*) __si_allocM( sizeof(SI_E1AP_DT_DRB_To_Remove_Item_NG_RAN));
	memset( obj_DRB_To_Remove_Item_NG_RAN, 0, sizeof( SI_E1AP_DT_DRB_To_Remove_Item_NG_RAN));

	// L:486
	obj_DRB_To_Remove_Item_NG_RAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533


	*pDRB_To_Remove_Item_NG_RAN = obj_DRB_To_Remove_Item_NG_RAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_Required_To_Remove_List_NG_RAN( SI_E1AP_DT_DRB_Required_To_Remove_List_NG_RAN ** pDRB_Required_To_Remove_List_NG_RAN)
{
	SI_E1AP_DT_DRB_Required_To_Remove_List_NG_RAN * obj_DRB_Required_To_Remove_List_NG_RAN = NULL; 
	__si_e1ap_init_DRB_Required_To_Remove_List_NG_RAN( &obj_DRB_Required_To_Remove_List_NG_RAN);

	// L:1260
	SI_E1AP_DT_DRB_Required_To_Remove_Item_NG_RAN * objDRB_Required_To_Remove_Item_NG_RAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_Required_To_Remove_Item_NG_RAN( &objDRB_Required_To_Remove_Item_NG_RAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_Required_To_Remove_List_NG_RAN->DRB_Required_To_Remove_Item_NG_RAN, (uint8_t*)objDRB_Required_To_Remove_Item_NG_RAN);

	*pDRB_Required_To_Remove_List_NG_RAN = obj_DRB_Required_To_Remove_List_NG_RAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_Required_To_Remove_Item_NG_RAN( SI_E1AP_DT_DRB_Required_To_Remove_Item_NG_RAN ** pDRB_Required_To_Remove_Item_NG_RAN)
{
	SI_E1AP_DT_DRB_Required_To_Remove_Item_NG_RAN * obj_DRB_Required_To_Remove_Item_NG_RAN = (SI_E1AP_DT_DRB_Required_To_Remove_Item_NG_RAN*) __si_allocM( sizeof(SI_E1AP_DT_DRB_Required_To_Remove_Item_NG_RAN));
	memset( obj_DRB_Required_To_Remove_Item_NG_RAN, 0, sizeof( SI_E1AP_DT_DRB_Required_To_Remove_Item_NG_RAN));

	// L:486
	obj_DRB_Required_To_Remove_Item_NG_RAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__Cause( &obj_DRB_Required_To_Remove_Item_NG_RAN->cause);    // L:588


	*pDRB_Required_To_Remove_Item_NG_RAN = obj_DRB_Required_To_Remove_Item_NG_RAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_To_Setup_List_EUTRAN( SI_E1AP_DT_DRB_To_Setup_List_EUTRAN ** pDRB_To_Setup_List_EUTRAN)
{
	SI_E1AP_DT_DRB_To_Setup_List_EUTRAN * obj_DRB_To_Setup_List_EUTRAN = NULL; 
	__si_e1ap_init_DRB_To_Setup_List_EUTRAN( &obj_DRB_To_Setup_List_EUTRAN);

	// L:1260
	SI_E1AP_DT_DRB_To_Setup_Item_EUTRAN * objDRB_To_Setup_Item_EUTRAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_To_Setup_Item_EUTRAN( &objDRB_To_Setup_Item_EUTRAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_To_Setup_List_EUTRAN->DRB_To_Setup_Item_EUTRAN, (uint8_t*)objDRB_To_Setup_Item_EUTRAN);

	*pDRB_To_Setup_List_EUTRAN = obj_DRB_To_Setup_List_EUTRAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_To_Setup_Item_EUTRAN( SI_E1AP_DT_DRB_To_Setup_Item_EUTRAN ** pDRB_To_Setup_Item_EUTRAN)
{
	SI_E1AP_DT_DRB_To_Setup_Item_EUTRAN * obj_DRB_To_Setup_Item_EUTRAN = (SI_E1AP_DT_DRB_To_Setup_Item_EUTRAN*) __si_allocM( sizeof(SI_E1AP_DT_DRB_To_Setup_Item_EUTRAN));
	memset( obj_DRB_To_Setup_Item_EUTRAN, 0, sizeof( SI_E1AP_DT_DRB_To_Setup_Item_EUTRAN));

	// L:486
	obj_DRB_To_Setup_Item_EUTRAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__PDCP_Configuration( &obj_DRB_To_Setup_Item_EUTRAN->pDCP_Configuration);    // L:584

	__si_e1ap__set_testdata__EUTRAN_QoS( &obj_DRB_To_Setup_Item_EUTRAN->eUTRAN_QoS);    // L:584

	__si_e1ap__set_testdata__UP_TNL_Information( &obj_DRB_To_Setup_Item_EUTRAN->s1_UL_UP_TNL_Information);    // L:588

	__si_e1ap__set_testdata__Data_Forwarding_Information_Request( &obj_DRB_To_Setup_Item_EUTRAN->data_Forwarding_Information_Request);    // L:584
	obj_DRB_To_Setup_Item_EUTRAN->isPresent_data_Forwarding_Information_Request = 1;

	__si_e1ap__set_testdata__Cell_Group_Information( &obj_DRB_To_Setup_Item_EUTRAN->cell_Group_Information);    // L:580

	__si_e1ap__set_testdata__UP_Parameters( &obj_DRB_To_Setup_Item_EUTRAN->dL_UP_Parameters);    // L:580
	obj_DRB_To_Setup_Item_EUTRAN->isPresent_dL_UP_Parameters = 1;

	obj_DRB_To_Setup_Item_EUTRAN->dRB_Inactivity_Timer = __getTestINTEGER( 1, 7200);    // L:533
	obj_DRB_To_Setup_Item_EUTRAN->isPresent_dRB_Inactivity_Timer = 1;

	__si_e1ap__set_testdata__UP_TNL_Information( &obj_DRB_To_Setup_Item_EUTRAN->existing_Allocated_S1_DL_UP_TNL_Info);    // L:588
	obj_DRB_To_Setup_Item_EUTRAN->isPresent_existing_Allocated_S1_DL_UP_TNL_Info = 1;


	*pDRB_To_Setup_Item_EUTRAN = obj_DRB_To_Setup_Item_EUTRAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_To_Setup_Mod_List_EUTRAN( SI_E1AP_DT_DRB_To_Setup_Mod_List_EUTRAN ** pDRB_To_Setup_Mod_List_EUTRAN)
{
	SI_E1AP_DT_DRB_To_Setup_Mod_List_EUTRAN * obj_DRB_To_Setup_Mod_List_EUTRAN = NULL; 
	__si_e1ap_init_DRB_To_Setup_Mod_List_EUTRAN( &obj_DRB_To_Setup_Mod_List_EUTRAN);

	// L:1260
	SI_E1AP_DT_DRB_To_Setup_Mod_Item_EUTRAN * objDRB_To_Setup_Mod_Item_EUTRAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_To_Setup_Mod_Item_EUTRAN( &objDRB_To_Setup_Mod_Item_EUTRAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_To_Setup_Mod_List_EUTRAN->DRB_To_Setup_Mod_Item_EUTRAN, (uint8_t*)objDRB_To_Setup_Mod_Item_EUTRAN);

	*pDRB_To_Setup_Mod_List_EUTRAN = obj_DRB_To_Setup_Mod_List_EUTRAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_To_Setup_Mod_Item_EUTRAN( SI_E1AP_DT_DRB_To_Setup_Mod_Item_EUTRAN ** pDRB_To_Setup_Mod_Item_EUTRAN)
{
	SI_E1AP_DT_DRB_To_Setup_Mod_Item_EUTRAN * obj_DRB_To_Setup_Mod_Item_EUTRAN = (SI_E1AP_DT_DRB_To_Setup_Mod_Item_EUTRAN*) __si_allocM( sizeof(SI_E1AP_DT_DRB_To_Setup_Mod_Item_EUTRAN));
	memset( obj_DRB_To_Setup_Mod_Item_EUTRAN, 0, sizeof( SI_E1AP_DT_DRB_To_Setup_Mod_Item_EUTRAN));

	// L:486
	obj_DRB_To_Setup_Mod_Item_EUTRAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__PDCP_Configuration( &obj_DRB_To_Setup_Mod_Item_EUTRAN->pDCP_Configuration);    // L:584

	__si_e1ap__set_testdata__EUTRAN_QoS( &obj_DRB_To_Setup_Mod_Item_EUTRAN->eUTRAN_QoS);    // L:584

	__si_e1ap__set_testdata__UP_TNL_Information( &obj_DRB_To_Setup_Mod_Item_EUTRAN->s1_UL_UP_TNL_Information);    // L:588

	__si_e1ap__set_testdata__Data_Forwarding_Information_Request( &obj_DRB_To_Setup_Mod_Item_EUTRAN->data_Forwarding_Information_Request);    // L:584
	obj_DRB_To_Setup_Mod_Item_EUTRAN->isPresent_data_Forwarding_Information_Request = 1;

	__si_e1ap__set_testdata__Cell_Group_Information( &obj_DRB_To_Setup_Mod_Item_EUTRAN->cell_Group_Information);    // L:580

	__si_e1ap__set_testdata__UP_Parameters( &obj_DRB_To_Setup_Mod_Item_EUTRAN->dL_UP_Parameters);    // L:580
	obj_DRB_To_Setup_Mod_Item_EUTRAN->isPresent_dL_UP_Parameters = 1;

	obj_DRB_To_Setup_Mod_Item_EUTRAN->dRB_Inactivity_Timer = __getTestINTEGER( 1, 7200);    // L:533
	obj_DRB_To_Setup_Mod_Item_EUTRAN->isPresent_dRB_Inactivity_Timer = 1;


	*pDRB_To_Setup_Mod_Item_EUTRAN = obj_DRB_To_Setup_Mod_Item_EUTRAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_To_Setup_List_NG_RAN( SI_E1AP_DT_DRB_To_Setup_List_NG_RAN ** pDRB_To_Setup_List_NG_RAN)
{
	SI_E1AP_DT_DRB_To_Setup_List_NG_RAN * obj_DRB_To_Setup_List_NG_RAN = NULL; 
	__si_e1ap_init_DRB_To_Setup_List_NG_RAN( &obj_DRB_To_Setup_List_NG_RAN);

	// L:1260
	SI_E1AP_DT_DRB_To_Setup_Item_NG_RAN * objDRB_To_Setup_Item_NG_RAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_To_Setup_Item_NG_RAN( &objDRB_To_Setup_Item_NG_RAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_To_Setup_List_NG_RAN->DRB_To_Setup_Item_NG_RAN, (uint8_t*)objDRB_To_Setup_Item_NG_RAN);

	*pDRB_To_Setup_List_NG_RAN = obj_DRB_To_Setup_List_NG_RAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_To_Setup_Item_NG_RAN( SI_E1AP_DT_DRB_To_Setup_Item_NG_RAN ** pDRB_To_Setup_Item_NG_RAN)
{
	SI_E1AP_DT_DRB_To_Setup_Item_NG_RAN * obj_DRB_To_Setup_Item_NG_RAN = (SI_E1AP_DT_DRB_To_Setup_Item_NG_RAN*) __si_allocM( sizeof(SI_E1AP_DT_DRB_To_Setup_Item_NG_RAN));
	memset( obj_DRB_To_Setup_Item_NG_RAN, 0, sizeof( SI_E1AP_DT_DRB_To_Setup_Item_NG_RAN));

	// L:486
	obj_DRB_To_Setup_Item_NG_RAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__SDAP_Configuration( &obj_DRB_To_Setup_Item_NG_RAN->sDAP_Configuration);    // L:584

	__si_e1ap__set_testdata__PDCP_Configuration( &obj_DRB_To_Setup_Item_NG_RAN->pDCP_Configuration);    // L:584

	__si_e1ap__set_testdata__Cell_Group_Information( &obj_DRB_To_Setup_Item_NG_RAN->cell_Group_Information);    // L:580

	__si_e1ap__set_testdata__QoS_Flow_QoS_Parameter_List( &obj_DRB_To_Setup_Item_NG_RAN->qos_flow_Information_To_Be_Setup);    // L:580

	__si_e1ap__set_testdata__Data_Forwarding_Information_Request( &obj_DRB_To_Setup_Item_NG_RAN->dRB_Data_Forwarding_Information_Request);    // L:584
	obj_DRB_To_Setup_Item_NG_RAN->isPresent_dRB_Data_Forwarding_Information_Request = 1;

	obj_DRB_To_Setup_Item_NG_RAN->dRB_Inactivity_Timer = __getTestINTEGER( 1, 7200);    // L:533
	obj_DRB_To_Setup_Item_NG_RAN->isPresent_dRB_Inactivity_Timer = 1;

	__si_e1ap__set_testdata__PDCP_SN_Status_Information( &obj_DRB_To_Setup_Item_NG_RAN->pDCP_SN_Status_Information);    // L:584
	obj_DRB_To_Setup_Item_NG_RAN->isPresent_pDCP_SN_Status_Information = 1;


	*pDRB_To_Setup_Item_NG_RAN = obj_DRB_To_Setup_Item_NG_RAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_To_Setup_Mod_List_NG_RAN( SI_E1AP_DT_DRB_To_Setup_Mod_List_NG_RAN ** pDRB_To_Setup_Mod_List_NG_RAN)
{
	SI_E1AP_DT_DRB_To_Setup_Mod_List_NG_RAN * obj_DRB_To_Setup_Mod_List_NG_RAN = NULL; 
	__si_e1ap_init_DRB_To_Setup_Mod_List_NG_RAN( &obj_DRB_To_Setup_Mod_List_NG_RAN);

	// L:1260
	SI_E1AP_DT_DRB_To_Setup_Mod_Item_NG_RAN * objDRB_To_Setup_Mod_Item_NG_RAN = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_To_Setup_Mod_Item_NG_RAN( &objDRB_To_Setup_Mod_Item_NG_RAN);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_To_Setup_Mod_List_NG_RAN->DRB_To_Setup_Mod_Item_NG_RAN, (uint8_t*)objDRB_To_Setup_Mod_Item_NG_RAN);

	*pDRB_To_Setup_Mod_List_NG_RAN = obj_DRB_To_Setup_Mod_List_NG_RAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_To_Setup_Mod_Item_NG_RAN( SI_E1AP_DT_DRB_To_Setup_Mod_Item_NG_RAN ** pDRB_To_Setup_Mod_Item_NG_RAN)
{
	SI_E1AP_DT_DRB_To_Setup_Mod_Item_NG_RAN * obj_DRB_To_Setup_Mod_Item_NG_RAN = (SI_E1AP_DT_DRB_To_Setup_Mod_Item_NG_RAN*) __si_allocM( sizeof(SI_E1AP_DT_DRB_To_Setup_Mod_Item_NG_RAN));
	memset( obj_DRB_To_Setup_Mod_Item_NG_RAN, 0, sizeof( SI_E1AP_DT_DRB_To_Setup_Mod_Item_NG_RAN));

	// L:486
	obj_DRB_To_Setup_Mod_Item_NG_RAN->dRB_ID = __getTestINTEGER( 1, 32);    // L:533

	__si_e1ap__set_testdata__SDAP_Configuration( &obj_DRB_To_Setup_Mod_Item_NG_RAN->sDAP_Configuration);    // L:584

	__si_e1ap__set_testdata__PDCP_Configuration( &obj_DRB_To_Setup_Mod_Item_NG_RAN->pDCP_Configuration);    // L:584

	__si_e1ap__set_testdata__Cell_Group_Information( &obj_DRB_To_Setup_Mod_Item_NG_RAN->cell_Group_Information);    // L:580

	__si_e1ap__set_testdata__QoS_Flow_QoS_Parameter_List( &obj_DRB_To_Setup_Mod_Item_NG_RAN->flow_Mapping_Information);    // L:580

	__si_e1ap__set_testdata__Data_Forwarding_Information_Request( &obj_DRB_To_Setup_Mod_Item_NG_RAN->dRB_Data_Forwarding_Information_Request);    // L:584
	obj_DRB_To_Setup_Mod_Item_NG_RAN->isPresent_dRB_Data_Forwarding_Information_Request = 1;

	obj_DRB_To_Setup_Mod_Item_NG_RAN->dRB_Inactivity_Timer = __getTestINTEGER( 1, 7200);    // L:533
	obj_DRB_To_Setup_Mod_Item_NG_RAN->isPresent_dRB_Inactivity_Timer = 1;

	__si_e1ap__set_testdata__PDCP_SN_Status_Information( &obj_DRB_To_Setup_Mod_Item_NG_RAN->pDCP_SN_Status_Information);    // L:584
	obj_DRB_To_Setup_Mod_Item_NG_RAN->isPresent_pDCP_SN_Status_Information = 1;


	*pDRB_To_Setup_Mod_Item_NG_RAN = obj_DRB_To_Setup_Mod_Item_NG_RAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_Usage_Report_List( SI_E1AP_DT_DRB_Usage_Report_List ** pDRB_Usage_Report_List)
{
	SI_E1AP_DT_DRB_Usage_Report_List * obj_DRB_Usage_Report_List = NULL; 
	__si_e1ap_init_DRB_Usage_Report_List( &obj_DRB_Usage_Report_List);

	// L:1260
	SI_E1AP_DT_DRB_Usage_Report_Item * objDRB_Usage_Report_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_Usage_Report_Item( &objDRB_Usage_Report_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_Usage_Report_List->DRB_Usage_Report_Item, (uint8_t*)objDRB_Usage_Report_Item);

	*pDRB_Usage_Report_List = obj_DRB_Usage_Report_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRB_Usage_Report_Item( SI_E1AP_DT_DRB_Usage_Report_Item ** pDRB_Usage_Report_Item)
{
	SI_E1AP_DT_DRB_Usage_Report_Item * obj_DRB_Usage_Report_Item = (SI_E1AP_DT_DRB_Usage_Report_Item*) __si_allocM( sizeof(SI_E1AP_DT_DRB_Usage_Report_Item));
	memset( obj_DRB_Usage_Report_Item, 0, sizeof( SI_E1AP_DT_DRB_Usage_Report_Item));

	// L:486
	__si_e1ap_init_DRBUsageReportItem_startTimeStamp2( &obj_DRB_Usage_Report_Item->startTimeStamp, "\x10\x23\x22\x03", 4);    // L:545

	__si_e1ap_init_DRBUsageReportItem_endTimeStamp2( &obj_DRB_Usage_Report_Item->endTimeStamp, "\x19\x22\x24\x06", 4);    // L:545

	obj_DRB_Usage_Report_Item->usageCountUL = __getTestINTEGER( 0, 18446744073709552000);    // L:533

	obj_DRB_Usage_Report_Item->usageCountDL = __getTestINTEGER( 0, 18446744073709552000);    // L:533


	*pDRB_Usage_Report_Item = obj_DRB_Usage_Report_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__Dynamic5QIDescriptor( SI_E1AP_DT_Dynamic5QIDescriptor ** pDynamic5QIDescriptor)
{
	SI_E1AP_DT_Dynamic5QIDescriptor * obj_Dynamic5QIDescriptor = (SI_E1AP_DT_Dynamic5QIDescriptor*) __si_allocM( sizeof(SI_E1AP_DT_Dynamic5QIDescriptor));
	memset( obj_Dynamic5QIDescriptor, 0, sizeof( SI_E1AP_DT_Dynamic5QIDescriptor));

	// L:486
	obj_Dynamic5QIDescriptor->qoSPriorityLevel = __getTestINTEGER( 0, 127);    // L:533

	obj_Dynamic5QIDescriptor->packetDelayBudget = __getTestINTEGER( 0, 1023);    // L:533

	__si_e1ap__set_testdata__PacketErrorRate( &obj_Dynamic5QIDescriptor->packetErrorRate);    // L:584

	obj_Dynamic5QIDescriptor->fiveQI = __getTestINTEGER( 0, 255);    // L:533
	obj_Dynamic5QIDescriptor->isPresent_fiveQI = 1;

	obj_Dynamic5QIDescriptor->selected_edelayCritical = Dynamic5QIDescriptor_delayCritical_delay_critical_val;   // L:529
	obj_Dynamic5QIDescriptor->isPresent_delayCritical = 1;

	obj_Dynamic5QIDescriptor->averagingWindow = __getTestINTEGER( 0, 4095);    // L:533
	obj_Dynamic5QIDescriptor->isPresent_averagingWindow = 1;

	obj_Dynamic5QIDescriptor->maxDataBurstVolume = __getTestINTEGER( 0, 4095);    // L:533
	obj_Dynamic5QIDescriptor->isPresent_maxDataBurstVolume = 1;


	*pDynamic5QIDescriptor = obj_Dynamic5QIDescriptor;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__EarlyForwardingCOUNTInfo( SI_E1AP_DT_EarlyForwardingCOUNTInfo ** pEarlyForwardingCOUNTInfo)
{
	SI_E1AP_DT_EarlyForwardingCOUNTInfo * obj_EarlyForwardingCOUNTInfo = (SI_E1AP_DT_EarlyForwardingCOUNTInfo*) __si_allocM( sizeof(SI_E1AP_DT_EarlyForwardingCOUNTInfo));
	memset( obj_EarlyForwardingCOUNTInfo, 0, sizeof( SI_E1AP_DT_EarlyForwardingCOUNTInfo));

	obj_EarlyForwardingCOUNTInfo->SelectedChoice = 0;

	// L:2784

	switch( obj_EarlyForwardingCOUNTInfo->SelectedChoice)
	{
		case 0:
			__si_e1ap__set_testdata__FirstDLCount( &obj_EarlyForwardingCOUNTInfo->u.firstDLCount);  // L:2910  ,  Parser:SEQUENCE, FirstDLCount
			break;
		case 1:
			__si_e1ap__set_testdata__DLDiscarding( &obj_EarlyForwardingCOUNTInfo->u.dLDiscardingCount);  // L:2910  ,  Parser:SEQUENCE, DLDiscarding
			break;
		case 2:
			__si_e1ap__set_testdata__PDU_EarlyForwardingCOUNTInfo_ExtIEs( &obj_EarlyForwardingCOUNTInfo->u.choice_Extension);    // L:2871
			break;
	}

	*pEarlyForwardingCOUNTInfo = obj_EarlyForwardingCOUNTInfo;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__ECNMarkingorCongestionInformationReportingRequest( SI_E1AP_DT_ECNMarkingorCongestionInformationReportingRequest ** pECNMarkingorCongestionInformationReportingRequest)
{
	SI_E1AP_DT_ECNMarkingorCongestionInformationReportingRequest * obj_ECNMarkingorCongestionInformationReportingRequest = (SI_E1AP_DT_ECNMarkingorCongestionInformationReportingRequest*) __si_allocM( sizeof(SI_E1AP_DT_ECNMarkingorCongestionInformationReportingRequest));
	memset( obj_ECNMarkingorCongestionInformationReportingRequest, 0, sizeof( SI_E1AP_DT_ECNMarkingorCongestionInformationReportingRequest));

	obj_ECNMarkingorCongestionInformationReportingRequest->SelectedChoice = 0;

	// L:2784

	switch( obj_ECNMarkingorCongestionInformationReportingRequest->SelectedChoice)
	{
		case 0:
			obj_ECNMarkingorCongestionInformationReportingRequest->u.eCNMarkingatNGRAN = ECNMarkingorCongestionInformationReportingRequest_eCNMarkingatNGRAN_ul_val;  // TODO: set enum   L:2894  ,  Parser:ENUMERATED, ECNMarkingorCongestionInformationReportingRequest_eCNMarkingatNGRAN
			break;
		case 1:
			obj_ECNMarkingorCongestionInformationReportingRequest->u.eCNMarkingatUPF = ECNMarkingorCongestionInformationReportingRequest_eCNMarkingatUPF_ul_val;  // TODO: set enum   L:2894  ,  Parser:ENUMERATED, ECNMarkingorCongestionInformationReportingRequest_eCNMarkingatUPF
			break;
		case 2:
			obj_ECNMarkingorCongestionInformationReportingRequest->u.congestionInformation = ECNMarkingorCongestionInformationReportingRequest_congestionInformation_ul_val;  // TODO: set enum   L:2894  ,  Parser:ENUMERATED, ECNMarkingorCongestionInformationReportingRequest_congestionInformation
			break;
		case 3:
			__si_e1ap__set_testdata__PDU_ECNMarkingorCongestionInformationReportingRequest_ExtIEs( &obj_ECNMarkingorCongestionInformationReportingRequest->u.choice_extension);    // L:2871
			break;
	}

	*pECNMarkingorCongestionInformationReportingRequest = obj_ECNMarkingorCongestionInformationReportingRequest;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__EHC_Common_Parameters( SI_E1AP_DT_EHC_Common_Parameters ** pEHC_Common_Parameters)
{
	SI_E1AP_DT_EHC_Common_Parameters * obj_EHC_Common_Parameters = (SI_E1AP_DT_EHC_Common_Parameters*) __si_allocM( sizeof(SI_E1AP_DT_EHC_Common_Parameters));
	memset( obj_EHC_Common_Parameters, 0, sizeof( SI_E1AP_DT_EHC_Common_Parameters));

	// L:486
	obj_EHC_Common_Parameters->selected_eehc_CID_Length = EHCCommonParameters_ehc_CID_Length_bits7_val;   // L:529


	*pEHC_Common_Parameters = obj_EHC_Common_Parameters;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__EHC_Downlink_Parameters( SI_E1AP_DT_EHC_Downlink_Parameters ** pEHC_Downlink_Parameters)
{
	SI_E1AP_DT_EHC_Downlink_Parameters * obj_EHC_Downlink_Parameters = (SI_E1AP_DT_EHC_Downlink_Parameters*) __si_allocM( sizeof(SI_E1AP_DT_EHC_Downlink_Parameters));
	memset( obj_EHC_Downlink_Parameters, 0, sizeof( SI_E1AP_DT_EHC_Downlink_Parameters));

	// L:486
	obj_EHC_Downlink_Parameters->selected_edrb_ContinueEHC_DL = EHCDownlinkParameters_drb_ContinueEHC_DL_true_val;   // L:529


	*pEHC_Downlink_Parameters = obj_EHC_Downlink_Parameters;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__EHC_Uplink_Parameters( SI_E1AP_DT_EHC_Uplink_Parameters ** pEHC_Uplink_Parameters)
{
	SI_E1AP_DT_EHC_Uplink_Parameters * obj_EHC_Uplink_Parameters = (SI_E1AP_DT_EHC_Uplink_Parameters*) __si_allocM( sizeof(SI_E1AP_DT_EHC_Uplink_Parameters));
	memset( obj_EHC_Uplink_Parameters, 0, sizeof( SI_E1AP_DT_EHC_Uplink_Parameters));

	// L:486
	obj_EHC_Uplink_Parameters->selected_edrb_ContinueEHC_UL = EHCUplinkParameters_drb_ContinueEHC_UL_true_val;   // L:529


	*pEHC_Uplink_Parameters = obj_EHC_Uplink_Parameters;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__EHC_Parameters( SI_E1AP_DT_EHC_Parameters ** pEHC_Parameters)
{
	SI_E1AP_DT_EHC_Parameters * obj_EHC_Parameters = (SI_E1AP_DT_EHC_Parameters*) __si_allocM( sizeof(SI_E1AP_DT_EHC_Parameters));
	memset( obj_EHC_Parameters, 0, sizeof( SI_E1AP_DT_EHC_Parameters));

	// L:486
	__si_e1ap__set_testdata__EHC_Common_Parameters( &obj_EHC_Parameters->ehc_Common);    // L:584

	__si_e1ap__set_testdata__EHC_Downlink_Parameters( &obj_EHC_Parameters->ehc_Downlink);    // L:584
	obj_EHC_Parameters->isPresent_ehc_Downlink = 1;

	__si_e1ap__set_testdata__EHC_Uplink_Parameters( &obj_EHC_Parameters->ehc_Uplink);    // L:584
	obj_EHC_Parameters->isPresent_ehc_Uplink = 1;


	*pEHC_Parameters = obj_EHC_Parameters;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__Endpoint_IP_address_and_port( SI_E1AP_DT_Endpoint_IP_address_and_port ** pEndpoint_IP_address_and_port)
{
	SI_E1AP_DT_Endpoint_IP_address_and_port * obj_Endpoint_IP_address_and_port = (SI_E1AP_DT_Endpoint_IP_address_and_port*) __si_allocM( sizeof(SI_E1AP_DT_Endpoint_IP_address_and_port));
	memset( obj_Endpoint_IP_address_and_port, 0, sizeof( SI_E1AP_DT_Endpoint_IP_address_and_port));

	// L:486
	__si_e1ap_init_TransportLayerAddress2( &obj_Endpoint_IP_address_and_port->endpoint_IP_Address, "3", 1, 1);  // L:574
	obj_Endpoint_IP_address_and_port->endpoint_IP_Address->bitslen = 1; //   L:575

	__si_e1ap_init_PortNumber2( &obj_Endpoint_IP_address_and_port->portNumber, "85", 2, 16);  // L:574
	obj_Endpoint_IP_address_and_port->portNumber->bitslen = 16; //   L:575


	*pEndpoint_IP_address_and_port = obj_Endpoint_IP_address_and_port;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__EUTRANAllocationAndRetentionPriority( SI_E1AP_DT_EUTRANAllocationAndRetentionPriority ** pEUTRANAllocationAndRetentionPriority)
{
	SI_E1AP_DT_EUTRANAllocationAndRetentionPriority * obj_EUTRANAllocationAndRetentionPriority = (SI_E1AP_DT_EUTRANAllocationAndRetentionPriority*) __si_allocM( sizeof(SI_E1AP_DT_EUTRANAllocationAndRetentionPriority));
	memset( obj_EUTRANAllocationAndRetentionPriority, 0, sizeof( SI_E1AP_DT_EUTRANAllocationAndRetentionPriority));

	// L:486
	obj_EUTRANAllocationAndRetentionPriority->priorityLevel = __getTestINTEGER( 0, 15);    // L:533

	obj_EUTRANAllocationAndRetentionPriority->selected_epre_emptionCapability = Pre_emptionCapability_shall_not_trigger_pre_emption_val;   // L:529

	obj_EUTRANAllocationAndRetentionPriority->selected_epre_emptionVulnerability = Pre_emptionVulnerability_not_pre_emptable_val;   // L:529


	*pEUTRANAllocationAndRetentionPriority = obj_EUTRANAllocationAndRetentionPriority;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__ECGI( SI_E1AP_DT_ECGI ** pECGI)
{
	SI_E1AP_DT_ECGI * obj_ECGI = (SI_E1AP_DT_ECGI*) __si_allocM( sizeof(SI_E1AP_DT_ECGI));
	memset( obj_ECGI, 0, sizeof( SI_E1AP_DT_ECGI));

	// L:486
	__si_e1ap_init_PLMN_Identity2( &obj_ECGI->pLMN_Identity, "\x13\x21\x14", 3);    // L:545

	__si_e1ap_init_E_UTRAN_Cell_Identity2( &obj_ECGI->eUTRAN_Cell_Identity, "5567", 4, 28);  // L:574
	obj_ECGI->eUTRAN_Cell_Identity->bitslen = 28; //   L:575


	*pECGI = obj_ECGI;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__ECGI_Support_List( SI_E1AP_DT_ECGI_Support_List ** pECGI_Support_List)
{
	SI_E1AP_DT_ECGI_Support_List * obj_ECGI_Support_List = NULL; 
	__si_e1ap_init_ECGI_Support_List( &obj_ECGI_Support_List);

	// L:1260
	SI_E1AP_DT_ECGI_Support_Item * objECGI_Support_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__ECGI_Support_Item( &objECGI_Support_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_ECGI_Support_List->ECGI_Support_Item, (uint8_t*)objECGI_Support_Item);

	*pECGI_Support_List = obj_ECGI_Support_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__ECGI_Support_Item( SI_E1AP_DT_ECGI_Support_Item ** pECGI_Support_Item)
{
	SI_E1AP_DT_ECGI_Support_Item * obj_ECGI_Support_Item = (SI_E1AP_DT_ECGI_Support_Item*) __si_allocM( sizeof(SI_E1AP_DT_ECGI_Support_Item));
	memset( obj_ECGI_Support_Item, 0, sizeof( SI_E1AP_DT_ECGI_Support_Item));

	// L:486
	__si_e1ap__set_testdata__ECGI( &obj_ECGI_Support_Item->eCGI);    // L:584


	*pECGI_Support_Item = obj_ECGI_Support_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__EUTRAN_QoS_Support_List( SI_E1AP_DT_EUTRAN_QoS_Support_List ** pEUTRAN_QoS_Support_List)
{
	SI_E1AP_DT_EUTRAN_QoS_Support_List * obj_EUTRAN_QoS_Support_List = NULL; 
	__si_e1ap_init_EUTRAN_QoS_Support_List( &obj_EUTRAN_QoS_Support_List);

	// L:1260
	SI_E1AP_DT_EUTRAN_QoS_Support_Item * objEUTRAN_QoS_Support_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__EUTRAN_QoS_Support_Item( &objEUTRAN_QoS_Support_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_EUTRAN_QoS_Support_List->EUTRAN_QoS_Support_Item, (uint8_t*)objEUTRAN_QoS_Support_Item);

	*pEUTRAN_QoS_Support_List = obj_EUTRAN_QoS_Support_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__EUTRAN_QoS_Support_Item( SI_E1AP_DT_EUTRAN_QoS_Support_Item ** pEUTRAN_QoS_Support_Item)
{
	SI_E1AP_DT_EUTRAN_QoS_Support_Item * obj_EUTRAN_QoS_Support_Item = (SI_E1AP_DT_EUTRAN_QoS_Support_Item*) __si_allocM( sizeof(SI_E1AP_DT_EUTRAN_QoS_Support_Item));
	memset( obj_EUTRAN_QoS_Support_Item, 0, sizeof( SI_E1AP_DT_EUTRAN_QoS_Support_Item));

	// L:486
	__si_e1ap__set_testdata__EUTRAN_QoS( &obj_EUTRAN_QoS_Support_Item->eUTRAN_QoS);    // L:584


	*pEUTRAN_QoS_Support_Item = obj_EUTRAN_QoS_Support_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__EUTRAN_QoS( SI_E1AP_DT_EUTRAN_QoS ** pEUTRAN_QoS)
{
	SI_E1AP_DT_EUTRAN_QoS * obj_EUTRAN_QoS = (SI_E1AP_DT_EUTRAN_QoS*) __si_allocM( sizeof(SI_E1AP_DT_EUTRAN_QoS));
	memset( obj_EUTRAN_QoS, 0, sizeof( SI_E1AP_DT_EUTRAN_QoS));

	// L:486
	obj_EUTRAN_QoS->qCI = __getTestINTEGER( 0, 255);    // L:533

	__si_e1ap__set_testdata__EUTRANAllocationAndRetentionPriority( &obj_EUTRAN_QoS->eUTRANallocationAndRetentionPriority);    // L:584

	__si_e1ap__set_testdata__GBR_QosInformation( &obj_EUTRAN_QoS->gbrQosInformation);    // L:584
	obj_EUTRAN_QoS->isPresent_gbrQosInformation = 1;


	*pEUTRAN_QoS = obj_EUTRAN_QoS;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__ExtendedSliceSupportList( SI_E1AP_DT_ExtendedSliceSupportList ** pExtendedSliceSupportList)
{
	SI_E1AP_DT_ExtendedSliceSupportList * obj_ExtendedSliceSupportList = NULL; 
	__si_e1ap_init_ExtendedSliceSupportList( &obj_ExtendedSliceSupportList);

	// L:1260
	SI_E1AP_DT_Slice_Support_Item * objSlice_Support_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__Slice_Support_Item( &objSlice_Support_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_ExtendedSliceSupportList->Slice_Support_Item, (uint8_t*)objSlice_Support_Item);

	*pExtendedSliceSupportList = obj_ExtendedSliceSupportList;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__FirstDLCount( SI_E1AP_DT_FirstDLCount ** pFirstDLCount)
{
	SI_E1AP_DT_FirstDLCount * obj_FirstDLCount = (SI_E1AP_DT_FirstDLCount*) __si_allocM( sizeof(SI_E1AP_DT_FirstDLCount));
	memset( obj_FirstDLCount, 0, sizeof( SI_E1AP_DT_FirstDLCount));

	// L:486
	__si_e1ap__set_testdata__PDCP_Count( &obj_FirstDLCount->firstDLCountVal);    // L:584


	*pFirstDLCount = obj_FirstDLCount;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__F1U_TNL_InfoAdded_List( SI_E1AP_DT_F1U_TNL_InfoAdded_List ** pF1U_TNL_InfoAdded_List)
{
	SI_E1AP_DT_F1U_TNL_InfoAdded_List * obj_F1U_TNL_InfoAdded_List = NULL; 
	__si_e1ap_init_F1U_TNL_InfoAdded_List( &obj_F1U_TNL_InfoAdded_List);

	// L:1260
	SI_E1AP_DT_F1U_TNL_InfoAdded_Item * objF1U_TNL_InfoAdded_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__F1U_TNL_InfoAdded_Item( &objF1U_TNL_InfoAdded_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_F1U_TNL_InfoAdded_List->F1U_TNL_InfoAdded_Item, (uint8_t*)objF1U_TNL_InfoAdded_Item);

	*pF1U_TNL_InfoAdded_List = obj_F1U_TNL_InfoAdded_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__F1U_TNL_InfoAdded_Item( SI_E1AP_DT_F1U_TNL_InfoAdded_Item ** pF1U_TNL_InfoAdded_Item)
{
	SI_E1AP_DT_F1U_TNL_InfoAdded_Item * obj_F1U_TNL_InfoAdded_Item = (SI_E1AP_DT_F1U_TNL_InfoAdded_Item*) __si_allocM( sizeof(SI_E1AP_DT_F1U_TNL_InfoAdded_Item));
	memset( obj_F1U_TNL_InfoAdded_Item, 0, sizeof( SI_E1AP_DT_F1U_TNL_InfoAdded_Item));

	// L:486
	__si_e1ap_init_BroadcastF1U_ContextReferenceE12( &obj_F1U_TNL_InfoAdded_Item->broadcastF1U_ContextReferenceE1, "\x14\x14\x13\x20", 4);    // L:545

	__si_e1ap__set_testdata__BCBearerContextF1U_TNLInfoatCU( &obj_F1U_TNL_InfoAdded_Item->bcBearerContextF1U_TNLInfoatCU);    // L:588


	*pF1U_TNL_InfoAdded_Item = obj_F1U_TNL_InfoAdded_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__F1U_TNL_InfoToAdd_List( SI_E1AP_DT_F1U_TNL_InfoToAdd_List ** pF1U_TNL_InfoToAdd_List)
{
	SI_E1AP_DT_F1U_TNL_InfoToAdd_List * obj_F1U_TNL_InfoToAdd_List = NULL; 
	__si_e1ap_init_F1U_TNL_InfoToAdd_List( &obj_F1U_TNL_InfoToAdd_List);

	// L:1260
	SI_E1AP_DT_F1U_TNL_InfoToAdd_Item * objF1U_TNL_InfoToAdd_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__F1U_TNL_InfoToAdd_Item( &objF1U_TNL_InfoToAdd_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_F1U_TNL_InfoToAdd_List->F1U_TNL_InfoToAdd_Item, (uint8_t*)objF1U_TNL_InfoToAdd_Item);

	*pF1U_TNL_InfoToAdd_List = obj_F1U_TNL_InfoToAdd_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__F1U_TNL_InfoToAdd_Item( SI_E1AP_DT_F1U_TNL_InfoToAdd_Item ** pF1U_TNL_InfoToAdd_Item)
{
	SI_E1AP_DT_F1U_TNL_InfoToAdd_Item * obj_F1U_TNL_InfoToAdd_Item = (SI_E1AP_DT_F1U_TNL_InfoToAdd_Item*) __si_allocM( sizeof(SI_E1AP_DT_F1U_TNL_InfoToAdd_Item));
	memset( obj_F1U_TNL_InfoToAdd_Item, 0, sizeof( SI_E1AP_DT_F1U_TNL_InfoToAdd_Item));

	// L:486
	__si_e1ap_init_BroadcastF1U_ContextReferenceE12( &obj_F1U_TNL_InfoToAdd_Item->broadcastF1U_ContextReferenceE1, "\x18\x17\x21\x07", 4);    // L:545


	*pF1U_TNL_InfoToAdd_Item = obj_F1U_TNL_InfoToAdd_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__F1U_TNL_InfoAddedOrModified_List( SI_E1AP_DT_F1U_TNL_InfoAddedOrModified_List ** pF1U_TNL_InfoAddedOrModified_List)
{
	SI_E1AP_DT_F1U_TNL_InfoAddedOrModified_List * obj_F1U_TNL_InfoAddedOrModified_List = NULL; 
	__si_e1ap_init_F1U_TNL_InfoAddedOrModified_List( &obj_F1U_TNL_InfoAddedOrModified_List);

	// L:1260
	SI_E1AP_DT_F1U_TNL_InfoAddedOrModified_Item * objF1U_TNL_InfoAddedOrModified_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__F1U_TNL_InfoAddedOrModified_Item( &objF1U_TNL_InfoAddedOrModified_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_F1U_TNL_InfoAddedOrModified_List->F1U_TNL_InfoAddedOrModified_Item, (uint8_t*)objF1U_TNL_InfoAddedOrModified_Item);

	*pF1U_TNL_InfoAddedOrModified_List = obj_F1U_TNL_InfoAddedOrModified_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__F1U_TNL_InfoAddedOrModified_Item( SI_E1AP_DT_F1U_TNL_InfoAddedOrModified_Item ** pF1U_TNL_InfoAddedOrModified_Item)
{
	SI_E1AP_DT_F1U_TNL_InfoAddedOrModified_Item * obj_F1U_TNL_InfoAddedOrModified_Item = (SI_E1AP_DT_F1U_TNL_InfoAddedOrModified_Item*) __si_allocM( sizeof(SI_E1AP_DT_F1U_TNL_InfoAddedOrModified_Item));
	memset( obj_F1U_TNL_InfoAddedOrModified_Item, 0, sizeof( SI_E1AP_DT_F1U_TNL_InfoAddedOrModified_Item));

	// L:486
	__si_e1ap_init_BroadcastF1U_ContextReferenceE12( &obj_F1U_TNL_InfoAddedOrModified_Item->broadcastF1U_ContextReferenceE1, "\x03\x06\x11\x11", 4);    // L:545

	__si_e1ap__set_testdata__BCBearerContextF1U_TNLInfoatCU( &obj_F1U_TNL_InfoAddedOrModified_Item->bcBearerContextF1U_TNLInfoatCU);    // L:588
	obj_F1U_TNL_InfoAddedOrModified_Item->isPresent_bcBearerContextF1U_TNLInfoatCU = 1;


	*pF1U_TNL_InfoAddedOrModified_Item = obj_F1U_TNL_InfoAddedOrModified_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__F1U_TNL_InfoToAddOrModify_List( SI_E1AP_DT_F1U_TNL_InfoToAddOrModify_List ** pF1U_TNL_InfoToAddOrModify_List)
{
	SI_E1AP_DT_F1U_TNL_InfoToAddOrModify_List * obj_F1U_TNL_InfoToAddOrModify_List = NULL; 
	__si_e1ap_init_F1U_TNL_InfoToAddOrModify_List( &obj_F1U_TNL_InfoToAddOrModify_List);

	// L:1260
	SI_E1AP_DT_F1U_TNL_InfoToAddOrModify_Item * objF1U_TNL_InfoToAddOrModify_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__F1U_TNL_InfoToAddOrModify_Item( &objF1U_TNL_InfoToAddOrModify_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_F1U_TNL_InfoToAddOrModify_List->F1U_TNL_InfoToAddOrModify_Item, (uint8_t*)objF1U_TNL_InfoToAddOrModify_Item);

	*pF1U_TNL_InfoToAddOrModify_List = obj_F1U_TNL_InfoToAddOrModify_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__F1U_TNL_InfoToAddOrModify_Item( SI_E1AP_DT_F1U_TNL_InfoToAddOrModify_Item ** pF1U_TNL_InfoToAddOrModify_Item)
{
	SI_E1AP_DT_F1U_TNL_InfoToAddOrModify_Item * obj_F1U_TNL_InfoToAddOrModify_Item = (SI_E1AP_DT_F1U_TNL_InfoToAddOrModify_Item*) __si_allocM( sizeof(SI_E1AP_DT_F1U_TNL_InfoToAddOrModify_Item));
	memset( obj_F1U_TNL_InfoToAddOrModify_Item, 0, sizeof( SI_E1AP_DT_F1U_TNL_InfoToAddOrModify_Item));

	// L:486
	__si_e1ap_init_BroadcastF1U_ContextReferenceE12( &obj_F1U_TNL_InfoToAddOrModify_Item->broadcastF1U_ContextReferenceE1, "\x24\x02\x19\x22", 4);    // L:545

	__si_e1ap__set_testdata__BCBearerContextF1U_TNLInfoatDU( &obj_F1U_TNL_InfoToAddOrModify_Item->bcBearerContextF1U_TNLInfoatDU);    // L:588
	obj_F1U_TNL_InfoToAddOrModify_Item->isPresent_bcBearerContextF1U_TNLInfoatDU = 1;


	*pF1U_TNL_InfoToAddOrModify_Item = obj_F1U_TNL_InfoToAddOrModify_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__F1U_TNL_InfoToRelease_List( SI_E1AP_DT_F1U_TNL_InfoToRelease_List ** pF1U_TNL_InfoToRelease_List)
{
	SI_E1AP_DT_F1U_TNL_InfoToRelease_List * obj_F1U_TNL_InfoToRelease_List = NULL; 
	__si_e1ap_init_F1U_TNL_InfoToRelease_List( &obj_F1U_TNL_InfoToRelease_List);

	// L:1260
	SI_E1AP_DT_F1U_TNL_InfoToRelease_Item * objF1U_TNL_InfoToRelease_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__F1U_TNL_InfoToRelease_Item( &objF1U_TNL_InfoToRelease_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_F1U_TNL_InfoToRelease_List->F1U_TNL_InfoToRelease_Item, (uint8_t*)objF1U_TNL_InfoToRelease_Item);

	*pF1U_TNL_InfoToRelease_List = obj_F1U_TNL_InfoToRelease_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__F1U_TNL_InfoToRelease_Item( SI_E1AP_DT_F1U_TNL_InfoToRelease_Item ** pF1U_TNL_InfoToRelease_Item)
{
	SI_E1AP_DT_F1U_TNL_InfoToRelease_Item * obj_F1U_TNL_InfoToRelease_Item = (SI_E1AP_DT_F1U_TNL_InfoToRelease_Item*) __si_allocM( sizeof(SI_E1AP_DT_F1U_TNL_InfoToRelease_Item));
	memset( obj_F1U_TNL_InfoToRelease_Item, 0, sizeof( SI_E1AP_DT_F1U_TNL_InfoToRelease_Item));

	// L:486
	__si_e1ap_init_BroadcastF1U_ContextReferenceE12( &obj_F1U_TNL_InfoToRelease_Item->broadcastF1U_ContextReferenceE1, "\x17\x19\x08\x08", 4);    // L:545


	*pF1U_TNL_InfoToRelease_Item = obj_F1U_TNL_InfoToRelease_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__GlobalMBSSessionID( SI_E1AP_DT_GlobalMBSSessionID ** pGlobalMBSSessionID)
{
	SI_E1AP_DT_GlobalMBSSessionID * obj_GlobalMBSSessionID = (SI_E1AP_DT_GlobalMBSSessionID*) __si_allocM( sizeof(SI_E1AP_DT_GlobalMBSSessionID));
	memset( obj_GlobalMBSSessionID, 0, sizeof( SI_E1AP_DT_GlobalMBSSessionID));

	// L:486
	__si_e1ap_init_GlobalMBSSessionID_tmgi2( &obj_GlobalMBSSessionID->tmgi, "\x19\x22\x07\x01\x07\x17", 6);    // L:545

	__si_e1ap_init_NID2( &obj_GlobalMBSSessionID->nid, "717770", 6, 44);  // L:574
	obj_GlobalMBSSessionID->nid->bitslen = 44; //   L:575
	obj_GlobalMBSSessionID->isPresent_nid = 1;


	*pGlobalMBSSessionID = obj_GlobalMBSSessionID;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__Extended_GNB_CU_CP_Name( SI_E1AP_DT_Extended_GNB_CU_CP_Name ** pExtended_GNB_CU_CP_Name)
{
	SI_E1AP_DT_Extended_GNB_CU_CP_Name * obj_Extended_GNB_CU_CP_Name = (SI_E1AP_DT_Extended_GNB_CU_CP_Name*) __si_allocM( sizeof(SI_E1AP_DT_Extended_GNB_CU_CP_Name));
	memset( obj_Extended_GNB_CU_CP_Name, 0, sizeof( SI_E1AP_DT_Extended_GNB_CU_CP_Name));

	// L:486
	__si_e1ap_init_GNB_CU_CP_NameVisibleString2( &obj_Extended_GNB_CU_CP_Name->gNB_CU_CP_NameVisibleString, "2", 1);    // L:557
	obj_Extended_GNB_CU_CP_Name->isPresent_gNB_CU_CP_NameVisibleString = 1;

	__si_e1ap_init_GNB_CU_CP_NameUTF8String2( &obj_Extended_GNB_CU_CP_Name->gNB_CU_CP_NameUTF8String, "n", 1);    // L:557
	obj_Extended_GNB_CU_CP_Name->isPresent_gNB_CU_CP_NameUTF8String = 1;


	*pExtended_GNB_CU_CP_Name = obj_Extended_GNB_CU_CP_Name;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__GNB_CU_UP_CellGroupRelatedConfiguration( SI_E1AP_DT_GNB_CU_UP_CellGroupRelatedConfiguration ** pGNB_CU_UP_CellGroupRelatedConfiguration)
{
	SI_E1AP_DT_GNB_CU_UP_CellGroupRelatedConfiguration * obj_GNB_CU_UP_CellGroupRelatedConfiguration = NULL; 
	__si_e1ap_init_GNB_CU_UP_CellGroupRelatedConfiguration( &obj_GNB_CU_UP_CellGroupRelatedConfiguration);

	// L:1260
	SI_E1AP_DT_GNB_CU_UP_CellGroupRelatedConfiguration_Item * objGNB_CU_UP_CellGroupRelatedConfiguration_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__GNB_CU_UP_CellGroupRelatedConfiguration_Item( &objGNB_CU_UP_CellGroupRelatedConfiguration_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_GNB_CU_UP_CellGroupRelatedConfiguration->GNB_CU_UP_CellGroupRelatedConfiguration_Item, (uint8_t*)objGNB_CU_UP_CellGroupRelatedConfiguration_Item);

	*pGNB_CU_UP_CellGroupRelatedConfiguration = obj_GNB_CU_UP_CellGroupRelatedConfiguration;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__GNB_CU_UP_CellGroupRelatedConfiguration_Item( SI_E1AP_DT_GNB_CU_UP_CellGroupRelatedConfiguration_Item ** pGNB_CU_UP_CellGroupRelatedConfiguration_Item)
{
	SI_E1AP_DT_GNB_CU_UP_CellGroupRelatedConfiguration_Item * obj_GNB_CU_UP_CellGroupRelatedConfiguration_Item = (SI_E1AP_DT_GNB_CU_UP_CellGroupRelatedConfiguration_Item*) __si_allocM( sizeof(SI_E1AP_DT_GNB_CU_UP_CellGroupRelatedConfiguration_Item));
	memset( obj_GNB_CU_UP_CellGroupRelatedConfiguration_Item, 0, sizeof( SI_E1AP_DT_GNB_CU_UP_CellGroupRelatedConfiguration_Item));

	// L:486
	obj_GNB_CU_UP_CellGroupRelatedConfiguration_Item->cell_Group_ID = __getTestINTEGER( 0, 3);    // L:533

	__si_e1ap__set_testdata__UP_TNL_Information( &obj_GNB_CU_UP_CellGroupRelatedConfiguration_Item->uP_TNL_Information);    // L:588

	obj_GNB_CU_UP_CellGroupRelatedConfiguration_Item->selected_euL_Configuration = UL_Configuration_no_data_val;   // L:529
	obj_GNB_CU_UP_CellGroupRelatedConfiguration_Item->isPresent_uL_Configuration = 1;


	*pGNB_CU_UP_CellGroupRelatedConfiguration_Item = obj_GNB_CU_UP_CellGroupRelatedConfiguration_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__GNB_CU_UP_MBS_Support_Info( SI_E1AP_DT_GNB_CU_UP_MBS_Support_Info ** pGNB_CU_UP_MBS_Support_Info)
{
	SI_E1AP_DT_GNB_CU_UP_MBS_Support_Info * obj_GNB_CU_UP_MBS_Support_Info = (SI_E1AP_DT_GNB_CU_UP_MBS_Support_Info*) __si_allocM( sizeof(SI_E1AP_DT_GNB_CU_UP_MBS_Support_Info));
	memset( obj_GNB_CU_UP_MBS_Support_Info, 0, sizeof( SI_E1AP_DT_GNB_CU_UP_MBS_Support_Info));

	// L:486
	__si_e1ap__set_testdata__MBS_Support_Info_ToAdd_List( &obj_GNB_CU_UP_MBS_Support_Info->mbs_Support_Info_ToAdd_List);    // L:580
	obj_GNB_CU_UP_MBS_Support_Info->isPresent_mbs_Support_Info_ToAdd_List = 1;

	__si_e1ap__set_testdata__MBS_Support_Info_ToRemove_List( &obj_GNB_CU_UP_MBS_Support_Info->mbs_Support_Info_ToRemove_List);    // L:580
	obj_GNB_CU_UP_MBS_Support_Info->isPresent_mbs_Support_Info_ToRemove_List = 1;


	*pGNB_CU_UP_MBS_Support_Info = obj_GNB_CU_UP_MBS_Support_Info;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__Extended_GNB_CU_UP_Name( SI_E1AP_DT_Extended_GNB_CU_UP_Name ** pExtended_GNB_CU_UP_Name)
{
	SI_E1AP_DT_Extended_GNB_CU_UP_Name * obj_Extended_GNB_CU_UP_Name = (SI_E1AP_DT_Extended_GNB_CU_UP_Name*) __si_allocM( sizeof(SI_E1AP_DT_Extended_GNB_CU_UP_Name));
	memset( obj_Extended_GNB_CU_UP_Name, 0, sizeof( SI_E1AP_DT_Extended_GNB_CU_UP_Name));

	// L:486
	__si_e1ap_init_GNB_CU_UP_NameVisibleString2( &obj_Extended_GNB_CU_UP_Name->gNB_CU_UP_NameVisibleString, "Y", 1);    // L:557
	obj_Extended_GNB_CU_UP_Name->isPresent_gNB_CU_UP_NameVisibleString = 1;

	__si_e1ap_init_GNB_CU_UP_NameUTF8String2( &obj_Extended_GNB_CU_UP_Name->gNB_CU_UP_NameUTF8String, "d", 1);    // L:557
	obj_Extended_GNB_CU_UP_Name->isPresent_gNB_CU_UP_NameUTF8String = 1;


	*pExtended_GNB_CU_UP_Name = obj_Extended_GNB_CU_UP_Name;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__GNB_CU_CP_TNLA_Setup_Item( SI_E1AP_DT_GNB_CU_CP_TNLA_Setup_Item ** pGNB_CU_CP_TNLA_Setup_Item)
{
	SI_E1AP_DT_GNB_CU_CP_TNLA_Setup_Item * obj_GNB_CU_CP_TNLA_Setup_Item = (SI_E1AP_DT_GNB_CU_CP_TNLA_Setup_Item*) __si_allocM( sizeof(SI_E1AP_DT_GNB_CU_CP_TNLA_Setup_Item));
	memset( obj_GNB_CU_CP_TNLA_Setup_Item, 0, sizeof( SI_E1AP_DT_GNB_CU_CP_TNLA_Setup_Item));

	// L:486
	__si_e1ap__set_testdata__CP_TNL_Information( &obj_GNB_CU_CP_TNLA_Setup_Item->tNLAssociationTransportLayerAddress);    // L:588


	*pGNB_CU_CP_TNLA_Setup_Item = obj_GNB_CU_CP_TNLA_Setup_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__GNB_CU_CP_TNLA_Failed_To_Setup_Item( SI_E1AP_DT_GNB_CU_CP_TNLA_Failed_To_Setup_Item ** pGNB_CU_CP_TNLA_Failed_To_Setup_Item)
{
	SI_E1AP_DT_GNB_CU_CP_TNLA_Failed_To_Setup_Item * obj_GNB_CU_CP_TNLA_Failed_To_Setup_Item = (SI_E1AP_DT_GNB_CU_CP_TNLA_Failed_To_Setup_Item*) __si_allocM( sizeof(SI_E1AP_DT_GNB_CU_CP_TNLA_Failed_To_Setup_Item));
	memset( obj_GNB_CU_CP_TNLA_Failed_To_Setup_Item, 0, sizeof( SI_E1AP_DT_GNB_CU_CP_TNLA_Failed_To_Setup_Item));

	// L:486
	__si_e1ap__set_testdata__CP_TNL_Information( &obj_GNB_CU_CP_TNLA_Failed_To_Setup_Item->tNLAssociationTransportLayerAddress);    // L:588

	__si_e1ap__set_testdata__Cause( &obj_GNB_CU_CP_TNLA_Failed_To_Setup_Item->cause);    // L:588


	*pGNB_CU_CP_TNLA_Failed_To_Setup_Item = obj_GNB_CU_CP_TNLA_Failed_To_Setup_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__GNB_CU_CP_TNLA_To_Add_Item( SI_E1AP_DT_GNB_CU_CP_TNLA_To_Add_Item ** pGNB_CU_CP_TNLA_To_Add_Item)
{
	SI_E1AP_DT_GNB_CU_CP_TNLA_To_Add_Item * obj_GNB_CU_CP_TNLA_To_Add_Item = (SI_E1AP_DT_GNB_CU_CP_TNLA_To_Add_Item*) __si_allocM( sizeof(SI_E1AP_DT_GNB_CU_CP_TNLA_To_Add_Item));
	memset( obj_GNB_CU_CP_TNLA_To_Add_Item, 0, sizeof( SI_E1AP_DT_GNB_CU_CP_TNLA_To_Add_Item));

	// L:486
	__si_e1ap__set_testdata__CP_TNL_Information( &obj_GNB_CU_CP_TNLA_To_Add_Item->tNLAssociationTransportLayerAddress);    // L:588

	obj_GNB_CU_CP_TNLA_To_Add_Item->selected_etNLAssociationUsage = TNLAssociationUsage_ue_val;   // L:529


	*pGNB_CU_CP_TNLA_To_Add_Item = obj_GNB_CU_CP_TNLA_To_Add_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__GNB_CU_CP_TNLA_To_Remove_Item( SI_E1AP_DT_GNB_CU_CP_TNLA_To_Remove_Item ** pGNB_CU_CP_TNLA_To_Remove_Item)
{
	SI_E1AP_DT_GNB_CU_CP_TNLA_To_Remove_Item * obj_GNB_CU_CP_TNLA_To_Remove_Item = (SI_E1AP_DT_GNB_CU_CP_TNLA_To_Remove_Item*) __si_allocM( sizeof(SI_E1AP_DT_GNB_CU_CP_TNLA_To_Remove_Item));
	memset( obj_GNB_CU_CP_TNLA_To_Remove_Item, 0, sizeof( SI_E1AP_DT_GNB_CU_CP_TNLA_To_Remove_Item));

	// L:486
	__si_e1ap__set_testdata__CP_TNL_Information( &obj_GNB_CU_CP_TNLA_To_Remove_Item->tNLAssociationTransportLayerAddress);    // L:588


	*pGNB_CU_CP_TNLA_To_Remove_Item = obj_GNB_CU_CP_TNLA_To_Remove_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__GNB_CU_CP_TNLA_To_Update_Item( SI_E1AP_DT_GNB_CU_CP_TNLA_To_Update_Item ** pGNB_CU_CP_TNLA_To_Update_Item)
{
	SI_E1AP_DT_GNB_CU_CP_TNLA_To_Update_Item * obj_GNB_CU_CP_TNLA_To_Update_Item = (SI_E1AP_DT_GNB_CU_CP_TNLA_To_Update_Item*) __si_allocM( sizeof(SI_E1AP_DT_GNB_CU_CP_TNLA_To_Update_Item));
	memset( obj_GNB_CU_CP_TNLA_To_Update_Item, 0, sizeof( SI_E1AP_DT_GNB_CU_CP_TNLA_To_Update_Item));

	// L:486
	__si_e1ap__set_testdata__CP_TNL_Information( &obj_GNB_CU_CP_TNLA_To_Update_Item->tNLAssociationTransportLayerAddress);    // L:588

	obj_GNB_CU_CP_TNLA_To_Update_Item->selected_etNLAssociationUsage = TNLAssociationUsage_ue_val;   // L:529
	obj_GNB_CU_CP_TNLA_To_Update_Item->isPresent_tNLAssociationUsage = 1;


	*pGNB_CU_CP_TNLA_To_Update_Item = obj_GNB_CU_CP_TNLA_To_Update_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__GNB_CU_UP_TNLA_To_Remove_Item( SI_E1AP_DT_GNB_CU_UP_TNLA_To_Remove_Item ** pGNB_CU_UP_TNLA_To_Remove_Item)
{
	SI_E1AP_DT_GNB_CU_UP_TNLA_To_Remove_Item * obj_GNB_CU_UP_TNLA_To_Remove_Item = (SI_E1AP_DT_GNB_CU_UP_TNLA_To_Remove_Item*) __si_allocM( sizeof(SI_E1AP_DT_GNB_CU_UP_TNLA_To_Remove_Item));
	memset( obj_GNB_CU_UP_TNLA_To_Remove_Item, 0, sizeof( SI_E1AP_DT_GNB_CU_UP_TNLA_To_Remove_Item));

	// L:486
	__si_e1ap__set_testdata__CP_TNL_Information( &obj_GNB_CU_UP_TNLA_To_Remove_Item->tNLAssociationTransportLayerAddress);    // L:588

	__si_e1ap__set_testdata__CP_TNL_Information( &obj_GNB_CU_UP_TNLA_To_Remove_Item->tNLAssociationTransportLayerAddressgNBCUCP);    // L:588
	obj_GNB_CU_UP_TNLA_To_Remove_Item->isPresent_tNLAssociationTransportLayerAddressgNBCUCP = 1;


	*pGNB_CU_UP_TNLA_To_Remove_Item = obj_GNB_CU_UP_TNLA_To_Remove_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__GBR_QosInformation( SI_E1AP_DT_GBR_QosInformation ** pGBR_QosInformation)
{
	SI_E1AP_DT_GBR_QosInformation * obj_GBR_QosInformation = (SI_E1AP_DT_GBR_QosInformation*) __si_allocM( sizeof(SI_E1AP_DT_GBR_QosInformation));
	memset( obj_GBR_QosInformation, 0, sizeof( SI_E1AP_DT_GBR_QosInformation));

	// L:486
	obj_GBR_QosInformation->e_RAB_MaximumBitrateDL = __getTestINTEGER( 0, 4000000000000);    // L:533

	obj_GBR_QosInformation->e_RAB_MaximumBitrateUL = __getTestINTEGER( 0, 4000000000000);    // L:533

	obj_GBR_QosInformation->e_RAB_GuaranteedBitrateDL = __getTestINTEGER( 0, 4000000000000);    // L:533

	obj_GBR_QosInformation->e_RAB_GuaranteedBitrateUL = __getTestINTEGER( 0, 4000000000000);    // L:533


	*pGBR_QosInformation = obj_GBR_QosInformation;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__GBR_QoSFlowInformation( SI_E1AP_DT_GBR_QoSFlowInformation ** pGBR_QoSFlowInformation)
{
	SI_E1AP_DT_GBR_QoSFlowInformation * obj_GBR_QoSFlowInformation = (SI_E1AP_DT_GBR_QoSFlowInformation*) __si_allocM( sizeof(SI_E1AP_DT_GBR_QoSFlowInformation));
	memset( obj_GBR_QoSFlowInformation, 0, sizeof( SI_E1AP_DT_GBR_QoSFlowInformation));

	// L:486
	obj_GBR_QoSFlowInformation->maxFlowBitRateDownlink = __getTestINTEGER( 0, 4000000000000);    // L:533

	obj_GBR_QoSFlowInformation->maxFlowBitRateUplink = __getTestINTEGER( 0, 4000000000000);    // L:533

	obj_GBR_QoSFlowInformation->guaranteedFlowBitRateDownlink = __getTestINTEGER( 0, 4000000000000);    // L:533

	obj_GBR_QoSFlowInformation->guaranteedFlowBitRateUplink = __getTestINTEGER( 0, 4000000000000);    // L:533

	obj_GBR_QoSFlowInformation->maxPacketLossRateDownlink = __getTestINTEGER( 0, 1000);    // L:533
	obj_GBR_QoSFlowInformation->isPresent_maxPacketLossRateDownlink = 1;

	obj_GBR_QoSFlowInformation->maxPacketLossRateUplink = __getTestINTEGER( 0, 1000);    // L:533
	obj_GBR_QoSFlowInformation->isPresent_maxPacketLossRateUplink = 1;


	*pGBR_QoSFlowInformation = obj_GBR_QoSFlowInformation;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__GTPTLAs( SI_E1AP_DT_GTPTLAs ** pGTPTLAs)
{
	SI_E1AP_DT_GTPTLAs * obj_GTPTLAs = NULL; 
	__si_e1ap_init_GTPTLAs( &obj_GTPTLAs);

	// L:1260
	SI_E1AP_DT_GTPTLA_Item * objGTPTLA_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__GTPTLA_Item( &objGTPTLA_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_GTPTLAs->GTPTLA_Item, (uint8_t*)objGTPTLA_Item);

	*pGTPTLAs = obj_GTPTLAs;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__GTPTLA_Item( SI_E1AP_DT_GTPTLA_Item ** pGTPTLA_Item)
{
	SI_E1AP_DT_GTPTLA_Item * obj_GTPTLA_Item = (SI_E1AP_DT_GTPTLA_Item*) __si_allocM( sizeof(SI_E1AP_DT_GTPTLA_Item));
	memset( obj_GTPTLA_Item, 0, sizeof( SI_E1AP_DT_GTPTLA_Item));

	// L:486
	__si_e1ap_init_TransportLayerAddress2( &obj_GTPTLA_Item->gTPTransportLayerAddresses, "2", 1, 1);  // L:574
	obj_GTPTLA_Item->gTPTransportLayerAddresses->bitslen = 1; //   L:575


	*pGTPTLA_Item = obj_GTPTLA_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__GTPTunnel( SI_E1AP_DT_GTPTunnel ** pGTPTunnel)
{
	SI_E1AP_DT_GTPTunnel * obj_GTPTunnel = (SI_E1AP_DT_GTPTunnel*) __si_allocM( sizeof(SI_E1AP_DT_GTPTunnel));
	memset( obj_GTPTunnel, 0, sizeof( SI_E1AP_DT_GTPTunnel));

	// L:486
	__si_e1ap_init_TransportLayerAddress2( &obj_GTPTunnel->transportLayerAddress, "5", 1, 1);  // L:574
	obj_GTPTunnel->transportLayerAddress->bitslen = 1; //   L:575

	__si_e1ap_init_GTP_TEID2( &obj_GTPTunnel->gTP_TEID, "\x20\x06\x17\x16", 4);    // L:545


	*pGTPTunnel = obj_GTPTunnel;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__HW_CapacityIndicator( SI_E1AP_DT_HW_CapacityIndicator ** pHW_CapacityIndicator)
{
	SI_E1AP_DT_HW_CapacityIndicator * obj_HW_CapacityIndicator = (SI_E1AP_DT_HW_CapacityIndicator*) __si_allocM( sizeof(SI_E1AP_DT_HW_CapacityIndicator));
	memset( obj_HW_CapacityIndicator, 0, sizeof( SI_E1AP_DT_HW_CapacityIndicator));

	// L:486
	obj_HW_CapacityIndicator->offeredThroughput = __getTestINTEGER( 1, 16777216);    // L:533

	obj_HW_CapacityIndicator->availableThroughput = __getTestINTEGER( 0, 100);    // L:533


	*pHW_CapacityIndicator = obj_HW_CapacityIndicator;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__ImmediateMDT( SI_E1AP_DT_ImmediateMDT ** pImmediateMDT)
{
	SI_E1AP_DT_ImmediateMDT * obj_ImmediateMDT = (SI_E1AP_DT_ImmediateMDT*) __si_allocM( sizeof(SI_E1AP_DT_ImmediateMDT));
	memset( obj_ImmediateMDT, 0, sizeof( SI_E1AP_DT_ImmediateMDT));

	// L:486
	__si_e1ap_init_MeasurementsToActivate2( &obj_ImmediateMDT->measurementsToActivate, "6", 1, 8);  // L:574
	obj_ImmediateMDT->measurementsToActivate->bitslen = 8; //   L:575

	__si_e1ap__set_testdata__M4Configuration( &obj_ImmediateMDT->measurementFour);    // L:584
	obj_ImmediateMDT->isPresent_measurementFour = 1;

	__si_e1ap__set_testdata__M6Configuration( &obj_ImmediateMDT->measurementSix);    // L:584
	obj_ImmediateMDT->isPresent_measurementSix = 1;

	__si_e1ap__set_testdata__M7Configuration( &obj_ImmediateMDT->measurementSeven);    // L:584
	obj_ImmediateMDT->isPresent_measurementSeven = 1;


	*pImmediateMDT = obj_ImmediateMDT;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__IAB_Donor_CU_UPPSKInfo_Item( SI_E1AP_DT_IAB_Donor_CU_UPPSKInfo_Item ** pIAB_Donor_CU_UPPSKInfo_Item)
{
	SI_E1AP_DT_IAB_Donor_CU_UPPSKInfo_Item * obj_IAB_Donor_CU_UPPSKInfo_Item = (SI_E1AP_DT_IAB_Donor_CU_UPPSKInfo_Item*) __si_allocM( sizeof(SI_E1AP_DT_IAB_Donor_CU_UPPSKInfo_Item));
	memset( obj_IAB_Donor_CU_UPPSKInfo_Item, 0, sizeof( SI_E1AP_DT_IAB_Donor_CU_UPPSKInfo_Item));

	// L:486
	__si_e1ap_init_IAB_donor_CU_UPPSK2( &obj_IAB_Donor_CU_UPPSKInfo_Item->iAB_donor_CU_UPPSK, "\x16\x15\x09\x09\x05", 5);    // L:540

	__si_e1ap_init_TransportLayerAddress2( &obj_IAB_Donor_CU_UPPSKInfo_Item->iAB_donor_CU_UPIPAddress, "3", 1, 1);  // L:574
	obj_IAB_Donor_CU_UPPSKInfo_Item->iAB_donor_CU_UPIPAddress->bitslen = 1; //   L:575

	__si_e1ap_init_TransportLayerAddress2( &obj_IAB_Donor_CU_UPPSKInfo_Item->iAB_DUIPAddress, "3", 1, 1);  // L:574
	obj_IAB_Donor_CU_UPPSKInfo_Item->iAB_DUIPAddress->bitslen = 1; //   L:575


	*pIAB_Donor_CU_UPPSKInfo_Item = obj_IAB_Donor_CU_UPPSKInfo_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__LocationDependentMBSNGUInformationAt5GC( SI_E1AP_DT_LocationDependentMBSNGUInformationAt5GC ** pLocationDependentMBSNGUInformationAt5GC)
{
	SI_E1AP_DT_LocationDependentMBSNGUInformationAt5GC * obj_LocationDependentMBSNGUInformationAt5GC = NULL; 
	__si_e1ap_init_LocationDependentMBSNGUInformationAt5GC( &obj_LocationDependentMBSNGUInformationAt5GC);

	// L:1260
	SI_E1AP_DT_LocationDependentMBSNGUInformationAt5GC_Item * objLocationDependentMBSNGUInformationAt5GC_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__LocationDependentMBSNGUInformationAt5GC_Item( &objLocationDependentMBSNGUInformationAt5GC_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_LocationDependentMBSNGUInformationAt5GC->LocationDependentMBSNGUInformationAt5GC_Item, (uint8_t*)objLocationDependentMBSNGUInformationAt5GC_Item);

	*pLocationDependentMBSNGUInformationAt5GC = obj_LocationDependentMBSNGUInformationAt5GC;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__LocationDependentMBSNGUInformationAt5GC_Item( SI_E1AP_DT_LocationDependentMBSNGUInformationAt5GC_Item ** pLocationDependentMBSNGUInformationAt5GC_Item)
{
	SI_E1AP_DT_LocationDependentMBSNGUInformationAt5GC_Item * obj_LocationDependentMBSNGUInformationAt5GC_Item = (SI_E1AP_DT_LocationDependentMBSNGUInformationAt5GC_Item*) __si_allocM( sizeof(SI_E1AP_DT_LocationDependentMBSNGUInformationAt5GC_Item));
	memset( obj_LocationDependentMBSNGUInformationAt5GC_Item, 0, sizeof( SI_E1AP_DT_LocationDependentMBSNGUInformationAt5GC_Item));

	// L:486
	obj_LocationDependentMBSNGUInformationAt5GC_Item->mbsAreaSession_ID = __getTestINTEGER( 0, 65535);    // L:533

	__si_e1ap__set_testdata__MBSNGUInformationAt5GC( &obj_LocationDependentMBSNGUInformationAt5GC_Item->mbsNGUInformationAt5GC);    // L:588


	*pLocationDependentMBSNGUInformationAt5GC_Item = obj_LocationDependentMBSNGUInformationAt5GC_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__LocationDependentMBSF1UInformationAtCU( SI_E1AP_DT_LocationDependentMBSF1UInformationAtCU ** pLocationDependentMBSF1UInformationAtCU)
{
	SI_E1AP_DT_LocationDependentMBSF1UInformationAtCU * obj_LocationDependentMBSF1UInformationAtCU = NULL; 
	__si_e1ap_init_LocationDependentMBSF1UInformationAtCU( &obj_LocationDependentMBSF1UInformationAtCU);

	// L:1260
	SI_E1AP_DT_LocationDependentMBSF1UInformationAtCU_Item * objLocationDependentMBSF1UInformationAtCU_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__LocationDependentMBSF1UInformationAtCU_Item( &objLocationDependentMBSF1UInformationAtCU_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_LocationDependentMBSF1UInformationAtCU->LocationDependentMBSF1UInformationAtCU_Item, (uint8_t*)objLocationDependentMBSF1UInformationAtCU_Item);

	*pLocationDependentMBSF1UInformationAtCU = obj_LocationDependentMBSF1UInformationAtCU;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__LocationDependentMBSF1UInformationAtCU_Item( SI_E1AP_DT_LocationDependentMBSF1UInformationAtCU_Item ** pLocationDependentMBSF1UInformationAtCU_Item)
{
	SI_E1AP_DT_LocationDependentMBSF1UInformationAtCU_Item * obj_LocationDependentMBSF1UInformationAtCU_Item = (SI_E1AP_DT_LocationDependentMBSF1UInformationAtCU_Item*) __si_allocM( sizeof(SI_E1AP_DT_LocationDependentMBSF1UInformationAtCU_Item));
	memset( obj_LocationDependentMBSF1UInformationAtCU_Item, 0, sizeof( SI_E1AP_DT_LocationDependentMBSF1UInformationAtCU_Item));

	// L:486
	obj_LocationDependentMBSF1UInformationAtCU_Item->mbsAreaSession_ID = __getTestINTEGER( 0, 65535);    // L:533

	__si_e1ap__set_testdata__UP_TNL_Information( &obj_LocationDependentMBSF1UInformationAtCU_Item->mbs_f1u_info_at_CU);    // L:588


	*pLocationDependentMBSF1UInformationAtCU_Item = obj_LocationDependentMBSF1UInformationAtCU_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__LocationDependentMBSF1UInformationAtDU( SI_E1AP_DT_LocationDependentMBSF1UInformationAtDU ** pLocationDependentMBSF1UInformationAtDU)
{
	SI_E1AP_DT_LocationDependentMBSF1UInformationAtDU * obj_LocationDependentMBSF1UInformationAtDU = NULL; 
	__si_e1ap_init_LocationDependentMBSF1UInformationAtDU( &obj_LocationDependentMBSF1UInformationAtDU);

	// L:1260
	SI_E1AP_DT_LocationDependentMBSF1UInformationAtDU_Item * objLocationDependentMBSF1UInformationAtDU_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__LocationDependentMBSF1UInformationAtDU_Item( &objLocationDependentMBSF1UInformationAtDU_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_LocationDependentMBSF1UInformationAtDU->LocationDependentMBSF1UInformationAtDU_Item, (uint8_t*)objLocationDependentMBSF1UInformationAtDU_Item);

	*pLocationDependentMBSF1UInformationAtDU = obj_LocationDependentMBSF1UInformationAtDU;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__LocationDependentMBSF1UInformationAtDU_Item( SI_E1AP_DT_LocationDependentMBSF1UInformationAtDU_Item ** pLocationDependentMBSF1UInformationAtDU_Item)
{
	SI_E1AP_DT_LocationDependentMBSF1UInformationAtDU_Item * obj_LocationDependentMBSF1UInformationAtDU_Item = (SI_E1AP_DT_LocationDependentMBSF1UInformationAtDU_Item*) __si_allocM( sizeof(SI_E1AP_DT_LocationDependentMBSF1UInformationAtDU_Item));
	memset( obj_LocationDependentMBSF1UInformationAtDU_Item, 0, sizeof( SI_E1AP_DT_LocationDependentMBSF1UInformationAtDU_Item));

	// L:486
	obj_LocationDependentMBSF1UInformationAtDU_Item->mbsAreaSession_ID = __getTestINTEGER( 0, 65535);    // L:533

	__si_e1ap__set_testdata__UP_TNL_Information( &obj_LocationDependentMBSF1UInformationAtDU_Item->mbs_f1u_info_at_DU);    // L:588


	*pLocationDependentMBSF1UInformationAtDU_Item = obj_LocationDependentMBSF1UInformationAtDU_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__LocationDependentMBSNGUInformationAtNGRAN( SI_E1AP_DT_LocationDependentMBSNGUInformationAtNGRAN ** pLocationDependentMBSNGUInformationAtNGRAN)
{
	SI_E1AP_DT_LocationDependentMBSNGUInformationAtNGRAN * obj_LocationDependentMBSNGUInformationAtNGRAN = NULL; 
	__si_e1ap_init_LocationDependentMBSNGUInformationAtNGRAN( &obj_LocationDependentMBSNGUInformationAtNGRAN);

	// L:1260
	SI_E1AP_DT_LocationDependentMBSNGUInformationAtNGRAN_Item * objLocationDependentMBSNGUInformationAtNGRAN_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__LocationDependentMBSNGUInformationAtNGRAN_Item( &objLocationDependentMBSNGUInformationAtNGRAN_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_LocationDependentMBSNGUInformationAtNGRAN->LocationDependentMBSNGUInformationAtNGRAN_Item, (uint8_t*)objLocationDependentMBSNGUInformationAtNGRAN_Item);

	*pLocationDependentMBSNGUInformationAtNGRAN = obj_LocationDependentMBSNGUInformationAtNGRAN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__LocationDependentMBSNGUInformationAtNGRAN_Item( SI_E1AP_DT_LocationDependentMBSNGUInformationAtNGRAN_Item ** pLocationDependentMBSNGUInformationAtNGRAN_Item)
{
	SI_E1AP_DT_LocationDependentMBSNGUInformationAtNGRAN_Item * obj_LocationDependentMBSNGUInformationAtNGRAN_Item = (SI_E1AP_DT_LocationDependentMBSNGUInformationAtNGRAN_Item*) __si_allocM( sizeof(SI_E1AP_DT_LocationDependentMBSNGUInformationAtNGRAN_Item));
	memset( obj_LocationDependentMBSNGUInformationAtNGRAN_Item, 0, sizeof( SI_E1AP_DT_LocationDependentMBSNGUInformationAtNGRAN_Item));

	// L:486
	obj_LocationDependentMBSNGUInformationAtNGRAN_Item->mbsAreaSession_ID = __getTestINTEGER( 0, 65535);    // L:533

	__si_e1ap__set_testdata__MBSNGUInformationAtNGRAN( &obj_LocationDependentMBSNGUInformationAtNGRAN_Item->mbsNGUInformationAtNGRAN);    // L:588


	*pLocationDependentMBSNGUInformationAtNGRAN_Item = obj_LocationDependentMBSNGUInformationAtNGRAN_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MaximumIPdatarate( SI_E1AP_DT_MaximumIPdatarate ** pMaximumIPdatarate)
{
	SI_E1AP_DT_MaximumIPdatarate * obj_MaximumIPdatarate = (SI_E1AP_DT_MaximumIPdatarate*) __si_allocM( sizeof(SI_E1AP_DT_MaximumIPdatarate));
	memset( obj_MaximumIPdatarate, 0, sizeof( SI_E1AP_DT_MaximumIPdatarate));

	// L:486
	obj_MaximumIPdatarate->selected_emaxIPrate = MaxIPrate_bitrate64kbs_val;   // L:529


	*pMaximumIPdatarate = obj_MaximumIPdatarate;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MBSF1UInformationAtCU( SI_E1AP_DT_MBSF1UInformationAtCU ** pMBSF1UInformationAtCU)
{
	SI_E1AP_DT_MBSF1UInformationAtCU * obj_MBSF1UInformationAtCU = (SI_E1AP_DT_MBSF1UInformationAtCU*) __si_allocM( sizeof(SI_E1AP_DT_MBSF1UInformationAtCU));
	memset( obj_MBSF1UInformationAtCU, 0, sizeof( SI_E1AP_DT_MBSF1UInformationAtCU));

	// L:486
	__si_e1ap__set_testdata__UP_TNL_Information( &obj_MBSF1UInformationAtCU->mbs_f1u_info_at_CU);    // L:588


	*pMBSF1UInformationAtCU = obj_MBSF1UInformationAtCU;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MBSF1UInformationAtDU( SI_E1AP_DT_MBSF1UInformationAtDU ** pMBSF1UInformationAtDU)
{
	SI_E1AP_DT_MBSF1UInformationAtDU * obj_MBSF1UInformationAtDU = (SI_E1AP_DT_MBSF1UInformationAtDU*) __si_allocM( sizeof(SI_E1AP_DT_MBSF1UInformationAtDU));
	memset( obj_MBSF1UInformationAtDU, 0, sizeof( SI_E1AP_DT_MBSF1UInformationAtDU));

	// L:486
	__si_e1ap__set_testdata__UP_TNL_Information( &obj_MBSF1UInformationAtDU->mbs_f1u_info_at_DU);    // L:588


	*pMBSF1UInformationAtDU = obj_MBSF1UInformationAtDU;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__MBSNGUInformationAt5GC( SI_E1AP_DT_MBSNGUInformationAt5GC ** pMBSNGUInformationAt5GC)
{
	SI_E1AP_DT_MBSNGUInformationAt5GC * obj_MBSNGUInformationAt5GC = (SI_E1AP_DT_MBSNGUInformationAt5GC*) __si_allocM( sizeof(SI_E1AP_DT_MBSNGUInformationAt5GC));
	memset( obj_MBSNGUInformationAt5GC, 0, sizeof( SI_E1AP_DT_MBSNGUInformationAt5GC));

	obj_MBSNGUInformationAt5GC->SelectedChoice = 0;

	// L:2784

	switch( obj_MBSNGUInformationAt5GC->SelectedChoice)
	{
		case 0:
			__si_e1ap__set_testdata__MBSNGUInformationAt5GC_Multicast( &obj_MBSNGUInformationAt5GC->u.multicast);  // L:2910  ,  Parser:SEQUENCE, MBSNGUInformationAt5GC-Multicast
			break;
		case 1:
			__si_e1ap__set_testdata__PDU_MBSNGUInformationAt5GC_ExtIEs( &obj_MBSNGUInformationAt5GC->u.choice_extension);    // L:2871
			break;
	}

	*pMBSNGUInformationAt5GC = obj_MBSNGUInformationAt5GC;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MBSNGUInformationAt5GC_Multicast( SI_E1AP_DT_MBSNGUInformationAt5GC_Multicast ** pMBSNGUInformationAt5GC_Multicast)
{
	SI_E1AP_DT_MBSNGUInformationAt5GC_Multicast * obj_MBSNGUInformationAt5GC_Multicast = (SI_E1AP_DT_MBSNGUInformationAt5GC_Multicast*) __si_allocM( sizeof(SI_E1AP_DT_MBSNGUInformationAt5GC_Multicast));
	memset( obj_MBSNGUInformationAt5GC_Multicast, 0, sizeof( SI_E1AP_DT_MBSNGUInformationAt5GC_Multicast));

	// L:486
	__si_e1ap_init_TransportLayerAddress2( &obj_MBSNGUInformationAt5GC_Multicast->ipmcAddress, "3", 1, 1);  // L:574
	obj_MBSNGUInformationAt5GC_Multicast->ipmcAddress->bitslen = 1; //   L:575

	__si_e1ap_init_TransportLayerAddress2( &obj_MBSNGUInformationAt5GC_Multicast->ipsourceAddress, "8", 1, 1);  // L:574
	obj_MBSNGUInformationAt5GC_Multicast->ipsourceAddress->bitslen = 1; //   L:575

	__si_e1ap_init_GTP_TEID2( &obj_MBSNGUInformationAt5GC_Multicast->gtpDLTEID, "\x20\x10\x01\x06", 4);    // L:545


	*pMBSNGUInformationAt5GC_Multicast = obj_MBSNGUInformationAt5GC_Multicast;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__MBSNGUInformationAtNGRAN( SI_E1AP_DT_MBSNGUInformationAtNGRAN ** pMBSNGUInformationAtNGRAN)
{
	SI_E1AP_DT_MBSNGUInformationAtNGRAN * obj_MBSNGUInformationAtNGRAN = (SI_E1AP_DT_MBSNGUInformationAtNGRAN*) __si_allocM( sizeof(SI_E1AP_DT_MBSNGUInformationAtNGRAN));
	memset( obj_MBSNGUInformationAtNGRAN, 0, sizeof( SI_E1AP_DT_MBSNGUInformationAtNGRAN));

	obj_MBSNGUInformationAtNGRAN->SelectedChoice = 0;

	// L:2784

	switch( obj_MBSNGUInformationAtNGRAN->SelectedChoice)
	{
		case 0:
			obj_MBSNGUInformationAtNGRAN->u.unicast = UP_TNL_Information_gTPTunnel_val;  // TODO: set enum   L:2894  ,  Parser:CHOICE, UP-TNL-Information
			break;
		case 1:
			__si_e1ap__set_testdata__PDU_MBSNGUInformationAtNGRAN_ExtIEs( &obj_MBSNGUInformationAtNGRAN->u.choice_extension);    // L:2871
			break;
	}

	*pMBSNGUInformationAtNGRAN = obj_MBSNGUInformationAtNGRAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__MBSNGUInformationAtNGRAN_Request_List( SI_E1AP_DT_MBSNGUInformationAtNGRAN_Request_List ** pMBSNGUInformationAtNGRAN_Request_List)
{
	SI_E1AP_DT_MBSNGUInformationAtNGRAN_Request_List * obj_MBSNGUInformationAtNGRAN_Request_List = NULL; 
	__si_e1ap_init_MBSNGUInformationAtNGRAN_Request_List( &obj_MBSNGUInformationAtNGRAN_Request_List);

	// L:1260
	SI_E1AP_DT_MBSNGUInformationAtNGRAN_Request_Item * objMBSNGUInformationAtNGRAN_Request_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__MBSNGUInformationAtNGRAN_Request_Item( &objMBSNGUInformationAtNGRAN_Request_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_MBSNGUInformationAtNGRAN_Request_List->MBSNGUInformationAtNGRAN_Request_Item, (uint8_t*)objMBSNGUInformationAtNGRAN_Request_Item);

	*pMBSNGUInformationAtNGRAN_Request_List = obj_MBSNGUInformationAtNGRAN_Request_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MBSNGUInformationAtNGRAN_Request_Item( SI_E1AP_DT_MBSNGUInformationAtNGRAN_Request_Item ** pMBSNGUInformationAtNGRAN_Request_Item)
{
	SI_E1AP_DT_MBSNGUInformationAtNGRAN_Request_Item * obj_MBSNGUInformationAtNGRAN_Request_Item = (SI_E1AP_DT_MBSNGUInformationAtNGRAN_Request_Item*) __si_allocM( sizeof(SI_E1AP_DT_MBSNGUInformationAtNGRAN_Request_Item));
	memset( obj_MBSNGUInformationAtNGRAN_Request_Item, 0, sizeof( SI_E1AP_DT_MBSNGUInformationAtNGRAN_Request_Item));

	// L:486
	obj_MBSNGUInformationAtNGRAN_Request_Item->mbsAreaSession_ID = __getTestINTEGER( 0, 65535);    // L:533

	obj_MBSNGUInformationAtNGRAN_Request_Item->selected_embsNGUInformationAtNGRAN_Request = MBSNGUInformationAtNGRAN_Request_true_val;   // L:529


	*pMBSNGUInformationAtNGRAN_Request_Item = obj_MBSNGUInformationAtNGRAN_Request_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MBSSessionAssociatedInfoNonSupportToSupport( SI_E1AP_DT_MBSSessionAssociatedInfoNonSupportToSupport ** pMBSSessionAssociatedInfoNonSupportToSupport)
{
	SI_E1AP_DT_MBSSessionAssociatedInfoNonSupportToSupport * obj_MBSSessionAssociatedInfoNonSupportToSupport = (SI_E1AP_DT_MBSSessionAssociatedInfoNonSupportToSupport*) __si_allocM( sizeof(SI_E1AP_DT_MBSSessionAssociatedInfoNonSupportToSupport));
	memset( obj_MBSSessionAssociatedInfoNonSupportToSupport, 0, sizeof( SI_E1AP_DT_MBSSessionAssociatedInfoNonSupportToSupport));

	// L:486
	obj_MBSSessionAssociatedInfoNonSupportToSupport->ue_Reference_ID = __getTestINTEGER( 0, 4294967295);    // L:533

	obj_MBSSessionAssociatedInfoNonSupportToSupport->pDU_Session_ID = __getTestINTEGER( 0, 255);    // L:533

	__si_e1ap__set_testdata__MBSSessionAssociatedInformationList( &obj_MBSSessionAssociatedInfoNonSupportToSupport->associatedQoSFlowInformationList);    // L:580


	*pMBSSessionAssociatedInfoNonSupportToSupport = obj_MBSSessionAssociatedInfoNonSupportToSupport;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MBSSessionAssociatedInformation( SI_E1AP_DT_MBSSessionAssociatedInformation ** pMBSSessionAssociatedInformation)
{
	SI_E1AP_DT_MBSSessionAssociatedInformation * obj_MBSSessionAssociatedInformation = (SI_E1AP_DT_MBSSessionAssociatedInformation*) __si_allocM( sizeof(SI_E1AP_DT_MBSSessionAssociatedInformation));
	memset( obj_MBSSessionAssociatedInformation, 0, sizeof( SI_E1AP_DT_MBSSessionAssociatedInformation));

	// L:486
	__si_e1ap__set_testdata__MBSSessionAssociatedInformationList( &obj_MBSSessionAssociatedInformation->mbsSessionAssociatedInformationList);    // L:580

	__si_e1ap__set_testdata__UP_TNL_Information( &obj_MBSSessionAssociatedInformation->mbsSessionForwardingAddress);    // L:588


	*pMBSSessionAssociatedInformation = obj_MBSSessionAssociatedInformation;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__MBSSessionAssociatedInformationList( SI_E1AP_DT_MBSSessionAssociatedInformationList ** pMBSSessionAssociatedInformationList)
{
	SI_E1AP_DT_MBSSessionAssociatedInformationList * obj_MBSSessionAssociatedInformationList = NULL; 
	__si_e1ap_init_MBSSessionAssociatedInformationList( &obj_MBSSessionAssociatedInformationList);

	// L:1260
	SI_E1AP_DT_MBSSessionAssociatedInformation_Item * objMBSSessionAssociatedInformation_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__MBSSessionAssociatedInformation_Item( &objMBSSessionAssociatedInformation_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_MBSSessionAssociatedInformationList->MBSSessionAssociatedInformation_Item, (uint8_t*)objMBSSessionAssociatedInformation_Item);

	*pMBSSessionAssociatedInformationList = obj_MBSSessionAssociatedInformationList;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MBSSessionAssociatedInformation_Item( SI_E1AP_DT_MBSSessionAssociatedInformation_Item ** pMBSSessionAssociatedInformation_Item)
{
	SI_E1AP_DT_MBSSessionAssociatedInformation_Item * obj_MBSSessionAssociatedInformation_Item = (SI_E1AP_DT_MBSSessionAssociatedInformation_Item*) __si_allocM( sizeof(SI_E1AP_DT_MBSSessionAssociatedInformation_Item));
	memset( obj_MBSSessionAssociatedInformation_Item, 0, sizeof( SI_E1AP_DT_MBSSessionAssociatedInformation_Item));

	// L:486
	obj_MBSSessionAssociatedInformation_Item->mbs_QoS_Flow_Identifier = __getTestINTEGER( 0, 63);    // L:533

	obj_MBSSessionAssociatedInformation_Item->associated_unicast_QoS_Flow_Identifier = __getTestINTEGER( 0, 63);    // L:533


	*pMBSSessionAssociatedInformation_Item = obj_MBSSessionAssociatedInformation_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__MBS_Support_Info_ToAdd_List( SI_E1AP_DT_MBS_Support_Info_ToAdd_List ** pMBS_Support_Info_ToAdd_List)
{
	SI_E1AP_DT_MBS_Support_Info_ToAdd_List * obj_MBS_Support_Info_ToAdd_List = NULL; 
	__si_e1ap_init_MBS_Support_Info_ToAdd_List( &obj_MBS_Support_Info_ToAdd_List);

	// L:1260
	SI_E1AP_DT_MBS_Support_Info_ToAdd_Item * objMBS_Support_Info_ToAdd_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__MBS_Support_Info_ToAdd_Item( &objMBS_Support_Info_ToAdd_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_MBS_Support_Info_ToAdd_List->MBS_Support_Info_ToAdd_Item, (uint8_t*)objMBS_Support_Info_ToAdd_Item);

	*pMBS_Support_Info_ToAdd_List = obj_MBS_Support_Info_ToAdd_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MBS_Support_Info_ToAdd_Item( SI_E1AP_DT_MBS_Support_Info_ToAdd_Item ** pMBS_Support_Info_ToAdd_Item)
{
	SI_E1AP_DT_MBS_Support_Info_ToAdd_Item * obj_MBS_Support_Info_ToAdd_Item = (SI_E1AP_DT_MBS_Support_Info_ToAdd_Item*) __si_allocM( sizeof(SI_E1AP_DT_MBS_Support_Info_ToAdd_Item));
	memset( obj_MBS_Support_Info_ToAdd_Item, 0, sizeof( SI_E1AP_DT_MBS_Support_Info_ToAdd_Item));

	// L:486
	__si_e1ap__set_testdata__GlobalMBSSessionID( &obj_MBS_Support_Info_ToAdd_Item->globalMBSSessionID);    // L:584


	*pMBS_Support_Info_ToAdd_Item = obj_MBS_Support_Info_ToAdd_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__MBS_Support_Info_ToRemove_List( SI_E1AP_DT_MBS_Support_Info_ToRemove_List ** pMBS_Support_Info_ToRemove_List)
{
	SI_E1AP_DT_MBS_Support_Info_ToRemove_List * obj_MBS_Support_Info_ToRemove_List = NULL; 
	__si_e1ap_init_MBS_Support_Info_ToRemove_List( &obj_MBS_Support_Info_ToRemove_List);

	// L:1260
	SI_E1AP_DT_MBS_Support_Info_ToRemove_Item * objMBS_Support_Info_ToRemove_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__MBS_Support_Info_ToRemove_Item( &objMBS_Support_Info_ToRemove_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_MBS_Support_Info_ToRemove_List->MBS_Support_Info_ToRemove_Item, (uint8_t*)objMBS_Support_Info_ToRemove_Item);

	*pMBS_Support_Info_ToRemove_List = obj_MBS_Support_Info_ToRemove_List;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__MBSSessionResourceNotification( SI_E1AP_DT_MBSSessionResourceNotification ** pMBSSessionResourceNotification)
{
	SI_E1AP_DT_MBSSessionResourceNotification * obj_MBSSessionResourceNotification = (SI_E1AP_DT_MBSSessionResourceNotification*) __si_allocM( sizeof(SI_E1AP_DT_MBSSessionResourceNotification));
	memset( obj_MBSSessionResourceNotification, 0, sizeof( SI_E1AP_DT_MBSSessionResourceNotification));

	obj_MBSSessionResourceNotification->SelectedChoice = 0;

	// L:2784

	switch( obj_MBSSessionResourceNotification->SelectedChoice)
	{
		case 0:
			__si_e1ap__set_testdata__MBS_DL_Data_Arrival( &obj_MBSSessionResourceNotification->u.mbs_DL_Data_Arrival);  // L:2910  ,  Parser:SEQUENCE, MBS-DL-Data-Arrival
			break;
		case 1:
			__si_e1ap__set_testdata__MCBearerContext_Inactivity( &obj_MBSSessionResourceNotification->u.inactivity);  // L:2910  ,  Parser:SEQUENCE, MCBearerContext-Inactivity
			break;
		case 2:
			__si_e1ap__set_testdata__PDU_MBSSessionResourceNotification_ExtIEs( &obj_MBSSessionResourceNotification->u.choice_extension);    // L:2871
			break;
	}

	*pMBSSessionResourceNotification = obj_MBSSessionResourceNotification;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MBS_DL_Data_Arrival( SI_E1AP_DT_MBS_DL_Data_Arrival ** pMBS_DL_Data_Arrival)
{
	SI_E1AP_DT_MBS_DL_Data_Arrival * obj_MBS_DL_Data_Arrival = (SI_E1AP_DT_MBS_DL_Data_Arrival*) __si_allocM( sizeof(SI_E1AP_DT_MBS_DL_Data_Arrival));
	memset( obj_MBS_DL_Data_Arrival, 0, sizeof( SI_E1AP_DT_MBS_DL_Data_Arrival));

	// L:486
	obj_MBS_DL_Data_Arrival->selected_edlDataArrival = MBSDLDataArrival_dlDataArrival_true_val;   // L:529

	obj_MBS_DL_Data_Arrival->ppi = __getTestINTEGER( 0, 7);    // L:533
	obj_MBS_DL_Data_Arrival->isPresent_ppi = 1;


	*pMBS_DL_Data_Arrival = obj_MBS_DL_Data_Arrival;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MCBearerContext_Inactivity( SI_E1AP_DT_MCBearerContext_Inactivity ** pMCBearerContext_Inactivity)
{
	SI_E1AP_DT_MCBearerContext_Inactivity * obj_MCBearerContext_Inactivity = (SI_E1AP_DT_MCBearerContext_Inactivity*) __si_allocM( sizeof(SI_E1AP_DT_MCBearerContext_Inactivity));
	memset( obj_MCBearerContext_Inactivity, 0, sizeof( SI_E1AP_DT_MCBearerContext_Inactivity));

	// L:486
	obj_MCBearerContext_Inactivity->selected_emcBearerContext_Inactivity_Indication = MCBearerContextInactivity_mcBearerContext_Inactivity_Indication_true_val;   // L:529


	*pMCBearerContext_Inactivity = obj_MCBearerContext_Inactivity;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MBS_Support_Info_ToRemove_Item( SI_E1AP_DT_MBS_Support_Info_ToRemove_Item ** pMBS_Support_Info_ToRemove_Item)
{
	SI_E1AP_DT_MBS_Support_Info_ToRemove_Item * obj_MBS_Support_Info_ToRemove_Item = (SI_E1AP_DT_MBS_Support_Info_ToRemove_Item*) __si_allocM( sizeof(SI_E1AP_DT_MBS_Support_Info_ToRemove_Item));
	memset( obj_MBS_Support_Info_ToRemove_Item, 0, sizeof( SI_E1AP_DT_MBS_Support_Info_ToRemove_Item));

	// L:486
	__si_e1ap__set_testdata__GlobalMBSSessionID( &obj_MBS_Support_Info_ToRemove_Item->globalMBSSessionID);    // L:584


	*pMBS_Support_Info_ToRemove_Item = obj_MBS_Support_Info_ToRemove_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MCBearerContextToSetup( SI_E1AP_DT_MCBearerContextToSetup ** pMCBearerContextToSetup)
{
	SI_E1AP_DT_MCBearerContextToSetup * obj_MCBearerContextToSetup = (SI_E1AP_DT_MCBearerContextToSetup*) __si_allocM( sizeof(SI_E1AP_DT_MCBearerContextToSetup));
	memset( obj_MCBearerContextToSetup, 0, sizeof( SI_E1AP_DT_MCBearerContextToSetup));

	// L:486
	__si_e1ap__set_testdata__SNSSAI( &obj_MCBearerContextToSetup->snssai);    // L:584

	__si_e1ap__set_testdata__MCMRBSetupConfiguration( &obj_MCBearerContextToSetup->mcMRBToSetupList);    // L:580
	obj_MCBearerContextToSetup->isPresent_mcMRBToSetupList = 1;

	obj_MCBearerContextToSetup->selected_erequestedAction = RequestedAction4AvailNGUTermination_apply_available_configuration_val;   // L:529
	obj_MCBearerContextToSetup->isPresent_requestedAction = 1;


	*pMCBearerContextToSetup = obj_MCBearerContextToSetup;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__MCMRBSetupConfiguration( SI_E1AP_DT_MCMRBSetupConfiguration ** pMCMRBSetupConfiguration)
{
	SI_E1AP_DT_MCMRBSetupConfiguration * obj_MCMRBSetupConfiguration = NULL; 
	__si_e1ap_init_MCMRBSetupConfiguration( &obj_MCMRBSetupConfiguration);

	// L:1260
	SI_E1AP_DT_MCMRBSetupConfiguration_Item * objMCMRBSetupConfiguration_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__MCMRBSetupConfiguration_Item( &objMCMRBSetupConfiguration_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_MCMRBSetupConfiguration->MCMRBSetupConfiguration_Item, (uint8_t*)objMCMRBSetupConfiguration_Item);

	*pMCMRBSetupConfiguration = obj_MCMRBSetupConfiguration;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MCMRBSetupConfiguration_Item( SI_E1AP_DT_MCMRBSetupConfiguration_Item ** pMCMRBSetupConfiguration_Item)
{
	SI_E1AP_DT_MCMRBSetupConfiguration_Item * obj_MCMRBSetupConfiguration_Item = (SI_E1AP_DT_MCMRBSetupConfiguration_Item*) __si_allocM( sizeof(SI_E1AP_DT_MCMRBSetupConfiguration_Item));
	memset( obj_MCMRBSetupConfiguration_Item, 0, sizeof( SI_E1AP_DT_MCMRBSetupConfiguration_Item));

	// L:486
	obj_MCMRBSetupConfiguration_Item->mrb_ID = __getTestINTEGER( 1, 512);    // L:533

	__si_e1ap__set_testdata__PDCP_Configuration( &obj_MCMRBSetupConfiguration_Item->mbs_pdcp_config);    // L:584

	__si_e1ap__set_testdata__QoS_Flow_QoS_Parameter_List( &obj_MCMRBSetupConfiguration_Item->qoS_Flow_QoS_Parameter_List);    // L:580

	__si_e1ap__set_testdata__QoSFlowLevelQoSParameters( &obj_MCMRBSetupConfiguration_Item->qoSFlowLevelQoSParameters);    // L:584
	obj_MCMRBSetupConfiguration_Item->isPresent_qoSFlowLevelQoSParameters = 1;


	*pMCMRBSetupConfiguration_Item = obj_MCMRBSetupConfiguration_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MCBearerContextToSetupResponse( SI_E1AP_DT_MCBearerContextToSetupResponse ** pMCBearerContextToSetupResponse)
{
	SI_E1AP_DT_MCBearerContextToSetupResponse * obj_MCBearerContextToSetupResponse = (SI_E1AP_DT_MCBearerContextToSetupResponse*) __si_allocM( sizeof(SI_E1AP_DT_MCBearerContextToSetupResponse));
	memset( obj_MCBearerContextToSetupResponse, 0, sizeof( SI_E1AP_DT_MCBearerContextToSetupResponse));

	// L:486
	__si_e1ap__set_testdata__MCBearerContextNGU_TNLInfoatNGRAN( &obj_MCBearerContextToSetupResponse->mcBearerContextNGU_TNLInfoatNGRAN);    // L:588
	obj_MCBearerContextToSetupResponse->isPresent_mcBearerContextNGU_TNLInfoatNGRAN = 1;

	__si_e1ap__set_testdata__MCMRBSetupResponseList( &obj_MCBearerContextToSetupResponse->mcMRBSetupResponseList);    // L:580
	obj_MCBearerContextToSetupResponse->isPresent_mcMRBSetupResponseList = 1;

	__si_e1ap__set_testdata__MCMRBFailedList( &obj_MCBearerContextToSetupResponse->mcMRBFailedList);    // L:580
	obj_MCBearerContextToSetupResponse->isPresent_mcMRBFailedList = 1;

	__si_e1ap__set_testdata__MCMRBSetupConfiguration( &obj_MCBearerContextToSetupResponse->availableMCMRBConfig);    // L:580
	obj_MCBearerContextToSetupResponse->isPresent_availableMCMRBConfig = 1;


	*pMCBearerContextToSetupResponse = obj_MCBearerContextToSetupResponse;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__MCBearerContextNGU_TNLInfoatNGRAN( SI_E1AP_DT_MCBearerContextNGU_TNLInfoatNGRAN ** pMCBearerContextNGU_TNLInfoatNGRAN)
{
	SI_E1AP_DT_MCBearerContextNGU_TNLInfoatNGRAN * obj_MCBearerContextNGU_TNLInfoatNGRAN = (SI_E1AP_DT_MCBearerContextNGU_TNLInfoatNGRAN*) __si_allocM( sizeof(SI_E1AP_DT_MCBearerContextNGU_TNLInfoatNGRAN));
	memset( obj_MCBearerContextNGU_TNLInfoatNGRAN, 0, sizeof( SI_E1AP_DT_MCBearerContextNGU_TNLInfoatNGRAN));

	obj_MCBearerContextNGU_TNLInfoatNGRAN->SelectedChoice = 0;

	// L:2784

	switch( obj_MCBearerContextNGU_TNLInfoatNGRAN->SelectedChoice)
	{
		case 0:
			obj_MCBearerContextNGU_TNLInfoatNGRAN->u.locationindependent = MBSNGUInformationAtNGRAN_unicast_val;  // TODO: set enum   L:2894  ,  Parser:CHOICE, MBSNGUInformationAtNGRAN
			break;
		case 1:
			__si_e1ap__set_testdata__LocationDependentMBSNGUInformationAtNGRAN( &obj_MCBearerContextNGU_TNLInfoatNGRAN->u.locationdependent);  // L:2910  ,  Parser:SEQUENCE_OF, LocationDependentMBSNGUInformationAtNGRAN
			break;
		case 2:
			__si_e1ap__set_testdata__PDU_MCBearerContextNGU_TNLInfoatNGRAN_ExtIEs( &obj_MCBearerContextNGU_TNLInfoatNGRAN->u.choice_extension);    // L:2871
			break;
	}

	*pMCBearerContextNGU_TNLInfoatNGRAN = obj_MCBearerContextNGU_TNLInfoatNGRAN;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__MCMRBSetupResponseList( SI_E1AP_DT_MCMRBSetupResponseList ** pMCMRBSetupResponseList)
{
	SI_E1AP_DT_MCMRBSetupResponseList * obj_MCMRBSetupResponseList = NULL; 
	__si_e1ap_init_MCMRBSetupResponseList( &obj_MCMRBSetupResponseList);

	// L:1260
	SI_E1AP_DT_MCMRBSetupResponseList_Item * objMCMRBSetupResponseList_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__MCMRBSetupResponseList_Item( &objMCMRBSetupResponseList_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_MCMRBSetupResponseList->MCMRBSetupResponseList_Item, (uint8_t*)objMCMRBSetupResponseList_Item);

	*pMCMRBSetupResponseList = obj_MCMRBSetupResponseList;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MCMRBSetupResponseList_Item( SI_E1AP_DT_MCMRBSetupResponseList_Item ** pMCMRBSetupResponseList_Item)
{
	SI_E1AP_DT_MCMRBSetupResponseList_Item * obj_MCMRBSetupResponseList_Item = (SI_E1AP_DT_MCMRBSetupResponseList_Item*) __si_allocM( sizeof(SI_E1AP_DT_MCMRBSetupResponseList_Item));
	memset( obj_MCMRBSetupResponseList_Item, 0, sizeof( SI_E1AP_DT_MCMRBSetupResponseList_Item));

	// L:486
	obj_MCMRBSetupResponseList_Item->mrb_ID = __getTestINTEGER( 1, 512);    // L:533

	__si_e1ap__set_testdata__QoS_Flow_List( &obj_MCMRBSetupResponseList_Item->qosflow_setup);    // L:580

	__si_e1ap__set_testdata__QoS_Flow_Failed_List( &obj_MCMRBSetupResponseList_Item->qosflow_failed);    // L:580
	obj_MCMRBSetupResponseList_Item->isPresent_qosflow_failed = 1;

	__si_e1ap_init_MBS_PDCP_COUNT2( &obj_MCMRBSetupResponseList_Item->mBS_PDCP_COUNT, "5504", 4, 32);  // L:574
	obj_MCMRBSetupResponseList_Item->mBS_PDCP_COUNT->bitslen = 32; //   L:575
	obj_MCMRBSetupResponseList_Item->isPresent_mBS_PDCP_COUNT = 1;


	*pMCMRBSetupResponseList_Item = obj_MCMRBSetupResponseList_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__MCMRBFailedList( SI_E1AP_DT_MCMRBFailedList ** pMCMRBFailedList)
{
	SI_E1AP_DT_MCMRBFailedList * obj_MCMRBFailedList = NULL; 
	__si_e1ap_init_MCMRBFailedList( &obj_MCMRBFailedList);

	// L:1260
	SI_E1AP_DT_MCMRBFailedList_Item * objMCMRBFailedList_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__MCMRBFailedList_Item( &objMCMRBFailedList_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_MCMRBFailedList->MCMRBFailedList_Item, (uint8_t*)objMCMRBFailedList_Item);

	*pMCMRBFailedList = obj_MCMRBFailedList;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MCMRBFailedList_Item( SI_E1AP_DT_MCMRBFailedList_Item ** pMCMRBFailedList_Item)
{
	SI_E1AP_DT_MCMRBFailedList_Item * obj_MCMRBFailedList_Item = (SI_E1AP_DT_MCMRBFailedList_Item*) __si_allocM( sizeof(SI_E1AP_DT_MCMRBFailedList_Item));
	memset( obj_MCMRBFailedList_Item, 0, sizeof( SI_E1AP_DT_MCMRBFailedList_Item));

	// L:486
	obj_MCMRBFailedList_Item->mrb_ID = __getTestINTEGER( 1, 512);    // L:533

	__si_e1ap__set_testdata__Cause( &obj_MCMRBFailedList_Item->cause);    // L:588


	*pMCMRBFailedList_Item = obj_MCMRBFailedList_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MCBearerContextToModify( SI_E1AP_DT_MCBearerContextToModify ** pMCBearerContextToModify)
{
	SI_E1AP_DT_MCBearerContextToModify * obj_MCBearerContextToModify = (SI_E1AP_DT_MCBearerContextToModify*) __si_allocM( sizeof(SI_E1AP_DT_MCBearerContextToModify));
	memset( obj_MCBearerContextToModify, 0, sizeof( SI_E1AP_DT_MCBearerContextToModify));

	// L:486
	__si_e1ap__set_testdata__MCBearerContextNGUTNLInfoat5GC( &obj_MCBearerContextToModify->mcBearerContextNGUTNLInfoat5GC);    // L:584
	obj_MCBearerContextToModify->isPresent_mcBearerContextNGUTNLInfoat5GC = 1;

	__si_e1ap__set_testdata__MCBearerContextNGUTnlInfoatNGRANRequest( &obj_MCBearerContextToModify->mcBearerContextNGUTnlInfoatNGRANRequest);    // L:584
	obj_MCBearerContextToModify->isPresent_mcBearerContextNGUTnlInfoatNGRANRequest = 1;

	__si_e1ap__set_testdata__MBSMulticastF1UContextDescriptor( &obj_MCBearerContextToModify->mbsMulticastF1UContextDescriptor);    // L:584
	obj_MCBearerContextToModify->isPresent_mbsMulticastF1UContextDescriptor = 1;

	obj_MCBearerContextToModify->selected_erequestedAction = RequestedAction4AvailNGUTermination_apply_available_configuration_val;   // L:529
	obj_MCBearerContextToModify->isPresent_requestedAction = 1;

	__si_e1ap__set_testdata__MCMRBSetupModifyConfiguration( &obj_MCBearerContextToModify->mcMRBToSetupModifyList);    // L:580
	obj_MCBearerContextToModify->isPresent_mcMRBToSetupModifyList = 1;

	__si_e1ap__set_testdata__MCMRBRemoveConfiguration( &obj_MCBearerContextToModify->mcMRBToRemoveList);    // L:580
	obj_MCBearerContextToModify->isPresent_mcMRBToRemoveList = 1;


	*pMCBearerContextToModify = obj_MCBearerContextToModify;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MCBearerContextNGUTNLInfoat5GC( SI_E1AP_DT_MCBearerContextNGUTNLInfoat5GC ** pMCBearerContextNGUTNLInfoat5GC)
{
	SI_E1AP_DT_MCBearerContextNGUTNLInfoat5GC * obj_MCBearerContextNGUTNLInfoat5GC = (SI_E1AP_DT_MCBearerContextNGUTNLInfoat5GC*) __si_allocM( sizeof(SI_E1AP_DT_MCBearerContextNGUTNLInfoat5GC));
	memset( obj_MCBearerContextNGUTNLInfoat5GC, 0, sizeof( SI_E1AP_DT_MCBearerContextNGUTNLInfoat5GC));

	// L:486
	__si_e1ap__set_testdata__MBSNGUInformationAt5GC( &obj_MCBearerContextNGUTNLInfoat5GC->mbsNGUInformationAt5GC);    // L:588

	obj_MCBearerContextNGUTNLInfoat5GC->mbsAreaSession_ID = __getTestINTEGER( 0, 65535);    // L:533
	obj_MCBearerContextNGUTNLInfoat5GC->isPresent_mbsAreaSession_ID = 1;


	*pMCBearerContextNGUTNLInfoat5GC = obj_MCBearerContextNGUTNLInfoat5GC;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MCBearerContextNGUTnlInfoatNGRANRequest( SI_E1AP_DT_MCBearerContextNGUTnlInfoatNGRANRequest ** pMCBearerContextNGUTnlInfoatNGRANRequest)
{
	SI_E1AP_DT_MCBearerContextNGUTnlInfoatNGRANRequest * obj_MCBearerContextNGUTnlInfoatNGRANRequest = (SI_E1AP_DT_MCBearerContextNGUTnlInfoatNGRANRequest*) __si_allocM( sizeof(SI_E1AP_DT_MCBearerContextNGUTnlInfoatNGRANRequest));
	memset( obj_MCBearerContextNGUTnlInfoatNGRANRequest, 0, sizeof( SI_E1AP_DT_MCBearerContextNGUTnlInfoatNGRANRequest));

	// L:486
	obj_MCBearerContextNGUTnlInfoatNGRANRequest->selected_engRANNGUTNLRequested = MCBearerContextNGUTnlInfoatNGRANRequest_ngRANNGUTNLRequested_requested_val;   // L:529

	obj_MCBearerContextNGUTnlInfoatNGRANRequest->mbsAreaSession_ID = __getTestINTEGER( 0, 65535);    // L:533
	obj_MCBearerContextNGUTnlInfoatNGRANRequest->isPresent_mbsAreaSession_ID = 1;


	*pMCBearerContextNGUTnlInfoatNGRANRequest = obj_MCBearerContextNGUTnlInfoatNGRANRequest;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__MCMRBSetupModifyConfiguration( SI_E1AP_DT_MCMRBSetupModifyConfiguration ** pMCMRBSetupModifyConfiguration)
{
	SI_E1AP_DT_MCMRBSetupModifyConfiguration * obj_MCMRBSetupModifyConfiguration = NULL; 
	__si_e1ap_init_MCMRBSetupModifyConfiguration( &obj_MCMRBSetupModifyConfiguration);

	// L:1260
	SI_E1AP_DT_MCMRBSetupModifyConfiguration_Item * objMCMRBSetupModifyConfiguration_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__MCMRBSetupModifyConfiguration_Item( &objMCMRBSetupModifyConfiguration_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_MCMRBSetupModifyConfiguration->MCMRBSetupModifyConfiguration_Item, (uint8_t*)objMCMRBSetupModifyConfiguration_Item);

	*pMCMRBSetupModifyConfiguration = obj_MCMRBSetupModifyConfiguration;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MCMRBSetupModifyConfiguration_Item( SI_E1AP_DT_MCMRBSetupModifyConfiguration_Item ** pMCMRBSetupModifyConfiguration_Item)
{
	SI_E1AP_DT_MCMRBSetupModifyConfiguration_Item * obj_MCMRBSetupModifyConfiguration_Item = (SI_E1AP_DT_MCMRBSetupModifyConfiguration_Item*) __si_allocM( sizeof(SI_E1AP_DT_MCMRBSetupModifyConfiguration_Item));
	memset( obj_MCMRBSetupModifyConfiguration_Item, 0, sizeof( SI_E1AP_DT_MCMRBSetupModifyConfiguration_Item));

	// L:486
	obj_MCMRBSetupModifyConfiguration_Item->mrb_ID = __getTestINTEGER( 1, 512);    // L:533

	__si_e1ap__set_testdata__MCBearerContextF1UTNLInfoatDU( &obj_MCMRBSetupModifyConfiguration_Item->f1uTNLatDU);    // L:584
	obj_MCMRBSetupModifyConfiguration_Item->isPresent_f1uTNLatDU = 1;

	__si_e1ap__set_testdata__PDCP_Configuration( &obj_MCMRBSetupModifyConfiguration_Item->mbs_pdcp_config);    // L:584
	obj_MCMRBSetupModifyConfiguration_Item->isPresent_mbs_pdcp_config = 1;

	__si_e1ap__set_testdata__QoS_Flow_QoS_Parameter_List( &obj_MCMRBSetupModifyConfiguration_Item->qoS_Flow_QoS_Parameter_List);    // L:580
	obj_MCMRBSetupModifyConfiguration_Item->isPresent_qoS_Flow_QoS_Parameter_List = 1;

	__si_e1ap__set_testdata__QoSFlowLevelQoSParameters( &obj_MCMRBSetupModifyConfiguration_Item->mrbQoS);    // L:584
	obj_MCMRBSetupModifyConfiguration_Item->isPresent_mrbQoS = 1;

	obj_MCMRBSetupModifyConfiguration_Item->selected_embs_PDCP_COUNT_Req = MBS_PDCP_COUNT_Req_true_val;   // L:529
	obj_MCMRBSetupModifyConfiguration_Item->isPresent_mbs_PDCP_COUNT_Req = 1;


	*pMCMRBSetupModifyConfiguration_Item = obj_MCMRBSetupModifyConfiguration_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MCBearerContextF1UTNLInfoatDU( SI_E1AP_DT_MCBearerContextF1UTNLInfoatDU ** pMCBearerContextF1UTNLInfoatDU)
{
	SI_E1AP_DT_MCBearerContextF1UTNLInfoatDU * obj_MCBearerContextF1UTNLInfoatDU = (SI_E1AP_DT_MCBearerContextF1UTNLInfoatDU*) __si_allocM( sizeof(SI_E1AP_DT_MCBearerContextF1UTNLInfoatDU));
	memset( obj_MCBearerContextF1UTNLInfoatDU, 0, sizeof( SI_E1AP_DT_MCBearerContextF1UTNLInfoatDU));

	// L:486
	__si_e1ap__set_testdata__UP_TNL_Information( &obj_MCBearerContextF1UTNLInfoatDU->mbsF1UInfoatDU);    // L:588

	__si_e1ap__set_testdata__MBSMulticastF1UContextDescriptor( &obj_MCBearerContextF1UTNLInfoatDU->mbsMulticastF1UContextDescriptor);    // L:584


	*pMCBearerContextF1UTNLInfoatDU = obj_MCBearerContextF1UTNLInfoatDU;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MBSMulticastF1UContextDescriptor( SI_E1AP_DT_MBSMulticastF1UContextDescriptor ** pMBSMulticastF1UContextDescriptor)
{
	SI_E1AP_DT_MBSMulticastF1UContextDescriptor * obj_MBSMulticastF1UContextDescriptor = (SI_E1AP_DT_MBSMulticastF1UContextDescriptor*) __si_allocM( sizeof(SI_E1AP_DT_MBSMulticastF1UContextDescriptor));
	memset( obj_MBSMulticastF1UContextDescriptor, 0, sizeof( SI_E1AP_DT_MBSMulticastF1UContextDescriptor));

	// L:486
	__si_e1ap_init_MulticastF1UContextReferenceE12( &obj_MBSMulticastF1UContextDescriptor->multicastF1UContextReferenceE1, "\x16\x01\x24\x22", 4);    // L:545

	obj_MBSMulticastF1UContextDescriptor->selected_emc_F1UCtxtusage = MBSMulticastF1UContextDescriptor_mc_F1UCtxtusage_ptm_val;   // L:529

	obj_MBSMulticastF1UContextDescriptor->mbsAreaSession = __getTestINTEGER( 0, 65535);    // L:533
	obj_MBSMulticastF1UContextDescriptor->isPresent_mbsAreaSession = 1;


	*pMBSMulticastF1UContextDescriptor = obj_MBSMulticastF1UContextDescriptor;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__MCMRBRemoveConfiguration( SI_E1AP_DT_MCMRBRemoveConfiguration ** pMCMRBRemoveConfiguration)
{
	SI_E1AP_DT_MCMRBRemoveConfiguration * obj_MCMRBRemoveConfiguration = NULL; 
	__si_e1ap_init_MCMRBRemoveConfiguration( &obj_MCMRBRemoveConfiguration);

	// L:1260
	SI_E1AP_DT_MRB_ID * objMRB_ID = NULL;
	objMRB_ID = (SI_E1AP_DT_MRB_ID*)__si_allocM(sizeof(SI_E1AP_DT_MRB_ID)); // L:1383
	objMRB_ID->data = 1;

	// L:1419
	__si_linked_list_add( obj_MCMRBRemoveConfiguration->MRB_ID, (uint8_t*)objMRB_ID);

	*pMCMRBRemoveConfiguration = obj_MCMRBRemoveConfiguration;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MCBearerContextToModifyResponse( SI_E1AP_DT_MCBearerContextToModifyResponse ** pMCBearerContextToModifyResponse)
{
	SI_E1AP_DT_MCBearerContextToModifyResponse * obj_MCBearerContextToModifyResponse = (SI_E1AP_DT_MCBearerContextToModifyResponse*) __si_allocM( sizeof(SI_E1AP_DT_MCBearerContextToModifyResponse));
	memset( obj_MCBearerContextToModifyResponse, 0, sizeof( SI_E1AP_DT_MCBearerContextToModifyResponse));

	// L:486
	__si_e1ap__set_testdata__MCBearerContextNGU_TNLInfoatNGRANModifyResponse( &obj_MCBearerContextToModifyResponse->mcBearerContextNGU_TNLInfoatNGRANModifyResponse);    // L:584
	obj_MCBearerContextToModifyResponse->isPresent_mcBearerContextNGU_TNLInfoatNGRANModifyResponse = 1;

	__si_e1ap__set_testdata__MBSMulticastF1UContextDescriptor( &obj_MCBearerContextToModifyResponse->mbsMulticastF1UContextDescriptor);    // L:584
	obj_MCBearerContextToModifyResponse->isPresent_mbsMulticastF1UContextDescriptor = 1;

	__si_e1ap__set_testdata__MCMRBSetupModifyResponseList( &obj_MCBearerContextToModifyResponse->mcMRBModifySetupResponseList);    // L:580
	obj_MCBearerContextToModifyResponse->isPresent_mcMRBModifySetupResponseList = 1;

	__si_e1ap__set_testdata__MCMRBFailedList( &obj_MCBearerContextToModifyResponse->mcMRBFailedList);    // L:580
	obj_MCBearerContextToModifyResponse->isPresent_mcMRBFailedList = 1;

	__si_e1ap__set_testdata__MCMRBSetupConfiguration( &obj_MCBearerContextToModifyResponse->availableMCMRBConfig);    // L:580
	obj_MCBearerContextToModifyResponse->isPresent_availableMCMRBConfig = 1;


	*pMCBearerContextToModifyResponse = obj_MCBearerContextToModifyResponse;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MCBearerContextNGU_TNLInfoatNGRANModifyResponse( SI_E1AP_DT_MCBearerContextNGU_TNLInfoatNGRANModifyResponse ** pMCBearerContextNGU_TNLInfoatNGRANModifyResponse)
{
	SI_E1AP_DT_MCBearerContextNGU_TNLInfoatNGRANModifyResponse * obj_MCBearerContextNGU_TNLInfoatNGRANModifyResponse = (SI_E1AP_DT_MCBearerContextNGU_TNLInfoatNGRANModifyResponse*) __si_allocM( sizeof(SI_E1AP_DT_MCBearerContextNGU_TNLInfoatNGRANModifyResponse));
	memset( obj_MCBearerContextNGU_TNLInfoatNGRANModifyResponse, 0, sizeof( SI_E1AP_DT_MCBearerContextNGU_TNLInfoatNGRANModifyResponse));

	// L:486
	__si_e1ap__set_testdata__MBSNGUInformationAtNGRAN( &obj_MCBearerContextNGU_TNLInfoatNGRANModifyResponse->mbs_NGU_InfoatNGRAN);    // L:588

	obj_MCBearerContextNGU_TNLInfoatNGRANModifyResponse->mbsAreaSession = __getTestINTEGER( 0, 65535);    // L:533
	obj_MCBearerContextNGU_TNLInfoatNGRANModifyResponse->isPresent_mbsAreaSession = 1;


	*pMCBearerContextNGU_TNLInfoatNGRANModifyResponse = obj_MCBearerContextNGU_TNLInfoatNGRANModifyResponse;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__MCMRBSetupModifyResponseList( SI_E1AP_DT_MCMRBSetupModifyResponseList ** pMCMRBSetupModifyResponseList)
{
	SI_E1AP_DT_MCMRBSetupModifyResponseList * obj_MCMRBSetupModifyResponseList = NULL; 
	__si_e1ap_init_MCMRBSetupModifyResponseList( &obj_MCMRBSetupModifyResponseList);

	// L:1260
	SI_E1AP_DT_MCMRBSetupModifyResponseList_Item * objMCMRBSetupModifyResponseList_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__MCMRBSetupModifyResponseList_Item( &objMCMRBSetupModifyResponseList_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_MCMRBSetupModifyResponseList->MCMRBSetupModifyResponseList_Item, (uint8_t*)objMCMRBSetupModifyResponseList_Item);

	*pMCMRBSetupModifyResponseList = obj_MCMRBSetupModifyResponseList;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MCMRBSetupModifyResponseList_Item( SI_E1AP_DT_MCMRBSetupModifyResponseList_Item ** pMCMRBSetupModifyResponseList_Item)
{
	SI_E1AP_DT_MCMRBSetupModifyResponseList_Item * obj_MCMRBSetupModifyResponseList_Item = (SI_E1AP_DT_MCMRBSetupModifyResponseList_Item*) __si_allocM( sizeof(SI_E1AP_DT_MCMRBSetupModifyResponseList_Item));
	memset( obj_MCMRBSetupModifyResponseList_Item, 0, sizeof( SI_E1AP_DT_MCMRBSetupModifyResponseList_Item));

	// L:486
	obj_MCMRBSetupModifyResponseList_Item->mrb_ID = __getTestINTEGER( 1, 512);    // L:533

	__si_e1ap__set_testdata__QoS_Flow_List( &obj_MCMRBSetupModifyResponseList_Item->qosflow_setup);    // L:580
	obj_MCMRBSetupModifyResponseList_Item->isPresent_qosflow_setup = 1;

	__si_e1ap__set_testdata__QoS_Flow_Failed_List( &obj_MCMRBSetupModifyResponseList_Item->qosflow_failed);    // L:580
	obj_MCMRBSetupModifyResponseList_Item->isPresent_qosflow_failed = 1;

	__si_e1ap__set_testdata__UP_TNL_Information( &obj_MCMRBSetupModifyResponseList_Item->mcBearerContextF1UTNLInfoatCU);    // L:588
	obj_MCMRBSetupModifyResponseList_Item->isPresent_mcBearerContextF1UTNLInfoatCU = 1;

	__si_e1ap_init_MBS_PDCP_COUNT2( &obj_MCMRBSetupModifyResponseList_Item->mBS_PDCP_COUNT, "3616", 4, 32);  // L:574
	obj_MCMRBSetupModifyResponseList_Item->mBS_PDCP_COUNT->bitslen = 32; //   L:575
	obj_MCMRBSetupModifyResponseList_Item->isPresent_mBS_PDCP_COUNT = 1;


	*pMCMRBSetupModifyResponseList_Item = obj_MCMRBSetupModifyResponseList_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MCBearerContextToModifyRequired( SI_E1AP_DT_MCBearerContextToModifyRequired ** pMCBearerContextToModifyRequired)
{
	SI_E1AP_DT_MCBearerContextToModifyRequired * obj_MCBearerContextToModifyRequired = (SI_E1AP_DT_MCBearerContextToModifyRequired*) __si_allocM( sizeof(SI_E1AP_DT_MCBearerContextToModifyRequired));
	memset( obj_MCBearerContextToModifyRequired, 0, sizeof( SI_E1AP_DT_MCBearerContextToModifyRequired));

	// L:486
	__si_e1ap__set_testdata__MBSMulticastF1UContextDescriptor( &obj_MCBearerContextToModifyRequired->mbsMulticastF1UContextDescriptor);    // L:584
	obj_MCBearerContextToModifyRequired->isPresent_mbsMulticastF1UContextDescriptor = 1;

	__si_e1ap__set_testdata__MCMRBRemoveConfiguration( &obj_MCBearerContextToModifyRequired->mcMRBToRemoveRequiredList);    // L:580
	obj_MCBearerContextToModifyRequired->isPresent_mcMRBToRemoveRequiredList = 1;

	__si_e1ap__set_testdata__MCMRBModifyRequiredConfiguration( &obj_MCBearerContextToModifyRequired->mcMRBToModifyRequiredList);    // L:580
	obj_MCBearerContextToModifyRequired->isPresent_mcMRBToModifyRequiredList = 1;


	*pMCBearerContextToModifyRequired = obj_MCBearerContextToModifyRequired;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__MCMRBModifyRequiredConfiguration( SI_E1AP_DT_MCMRBModifyRequiredConfiguration ** pMCMRBModifyRequiredConfiguration)
{
	SI_E1AP_DT_MCMRBModifyRequiredConfiguration * obj_MCMRBModifyRequiredConfiguration = NULL; 
	__si_e1ap_init_MCMRBModifyRequiredConfiguration( &obj_MCMRBModifyRequiredConfiguration);

	// L:1260
	SI_E1AP_DT_MCMRBModifyRequiredConfiguration_Item * objMCMRBModifyRequiredConfiguration_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__MCMRBModifyRequiredConfiguration_Item( &objMCMRBModifyRequiredConfiguration_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_MCMRBModifyRequiredConfiguration->MCMRBModifyRequiredConfiguration_Item, (uint8_t*)objMCMRBModifyRequiredConfiguration_Item);

	*pMCMRBModifyRequiredConfiguration = obj_MCMRBModifyRequiredConfiguration;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MCMRBModifyRequiredConfiguration_Item( SI_E1AP_DT_MCMRBModifyRequiredConfiguration_Item ** pMCMRBModifyRequiredConfiguration_Item)
{
	SI_E1AP_DT_MCMRBModifyRequiredConfiguration_Item * obj_MCMRBModifyRequiredConfiguration_Item = (SI_E1AP_DT_MCMRBModifyRequiredConfiguration_Item*) __si_allocM( sizeof(SI_E1AP_DT_MCMRBModifyRequiredConfiguration_Item));
	memset( obj_MCMRBModifyRequiredConfiguration_Item, 0, sizeof( SI_E1AP_DT_MCMRBModifyRequiredConfiguration_Item));

	// L:486
	obj_MCMRBModifyRequiredConfiguration_Item->mrb_ID = __getTestINTEGER( 1, 512);    // L:533

	__si_e1ap_init_MBS_PDCP_COUNT2( &obj_MCMRBModifyRequiredConfiguration_Item->mBS_PDCP_COUNT, "6489", 4, 32);  // L:574
	obj_MCMRBModifyRequiredConfiguration_Item->mBS_PDCP_COUNT->bitslen = 32; //   L:575
	obj_MCMRBModifyRequiredConfiguration_Item->isPresent_mBS_PDCP_COUNT = 1;


	*pMCMRBModifyRequiredConfiguration_Item = obj_MCMRBModifyRequiredConfiguration_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MCBearerContextToModifyConfirm( SI_E1AP_DT_MCBearerContextToModifyConfirm ** pMCBearerContextToModifyConfirm)
{
	SI_E1AP_DT_MCBearerContextToModifyConfirm * obj_MCBearerContextToModifyConfirm = (SI_E1AP_DT_MCBearerContextToModifyConfirm*) __si_allocM( sizeof(SI_E1AP_DT_MCBearerContextToModifyConfirm));
	memset( obj_MCBearerContextToModifyConfirm, 0, sizeof( SI_E1AP_DT_MCBearerContextToModifyConfirm));

	// L:486
	__si_e1ap__set_testdata__MBSMulticastF1UContextDescriptor( &obj_MCBearerContextToModifyConfirm->mbsMulticastF1UContextDescriptor);    // L:584
	obj_MCBearerContextToModifyConfirm->isPresent_mbsMulticastF1UContextDescriptor = 1;

	__si_e1ap__set_testdata__MCMRBModifyConfirmList( &obj_MCBearerContextToModifyConfirm->mcMRBModifyConfirmList);    // L:580
	obj_MCBearerContextToModifyConfirm->isPresent_mcMRBModifyConfirmList = 1;


	*pMCBearerContextToModifyConfirm = obj_MCBearerContextToModifyConfirm;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__MCMRBModifyConfirmList( SI_E1AP_DT_MCMRBModifyConfirmList ** pMCMRBModifyConfirmList)
{
	SI_E1AP_DT_MCMRBModifyConfirmList * obj_MCMRBModifyConfirmList = NULL; 
	__si_e1ap_init_MCMRBModifyConfirmList( &obj_MCMRBModifyConfirmList);

	// L:1260
	SI_E1AP_DT_MCMRBModifyConfirmList_Item * objMCMRBModifyConfirmList_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__MCMRBModifyConfirmList_Item( &objMCMRBModifyConfirmList_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_MCMRBModifyConfirmList->MCMRBModifyConfirmList_Item, (uint8_t*)objMCMRBModifyConfirmList_Item);

	*pMCMRBModifyConfirmList = obj_MCMRBModifyConfirmList;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MCMRBModifyConfirmList_Item( SI_E1AP_DT_MCMRBModifyConfirmList_Item ** pMCMRBModifyConfirmList_Item)
{
	SI_E1AP_DT_MCMRBModifyConfirmList_Item * obj_MCMRBModifyConfirmList_Item = (SI_E1AP_DT_MCMRBModifyConfirmList_Item*) __si_allocM( sizeof(SI_E1AP_DT_MCMRBModifyConfirmList_Item));
	memset( obj_MCMRBModifyConfirmList_Item, 0, sizeof( SI_E1AP_DT_MCMRBModifyConfirmList_Item));

	// L:486
	obj_MCMRBModifyConfirmList_Item->mrb_ID = __getTestINTEGER( 1, 512);    // L:533


	*pMCMRBModifyConfirmList_Item = obj_MCMRBModifyConfirmList_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MCForwardingResourceRequest( SI_E1AP_DT_MCForwardingResourceRequest ** pMCForwardingResourceRequest)
{
	SI_E1AP_DT_MCForwardingResourceRequest * obj_MCForwardingResourceRequest = (SI_E1AP_DT_MCForwardingResourceRequest*) __si_allocM( sizeof(SI_E1AP_DT_MCForwardingResourceRequest));
	memset( obj_MCForwardingResourceRequest, 0, sizeof( SI_E1AP_DT_MCForwardingResourceRequest));

	// L:486
	__si_e1ap_init_MCForwardingResourceID2( &obj_MCForwardingResourceRequest->mcForwardingResourceID, "\x03\x23", 2);    // L:545

	obj_MCForwardingResourceRequest->mbsAreaSession_ID = __getTestINTEGER( 0, 65535);    // L:533
	obj_MCForwardingResourceRequest->isPresent_mbsAreaSession_ID = 1;

	__si_e1ap__set_testdata__MRBForwardingResourceRequestList( &obj_MCForwardingResourceRequest->mrbForwardingResourceRequestList);    // L:580
	obj_MCForwardingResourceRequest->isPresent_mrbForwardingResourceRequestList = 1;


	*pMCForwardingResourceRequest = obj_MCForwardingResourceRequest;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__MRBForwardingResourceRequestList( SI_E1AP_DT_MRBForwardingResourceRequestList ** pMRBForwardingResourceRequestList)
{
	SI_E1AP_DT_MRBForwardingResourceRequestList * obj_MRBForwardingResourceRequestList = NULL; 
	__si_e1ap_init_MRBForwardingResourceRequestList( &obj_MRBForwardingResourceRequestList);

	// L:1260
	SI_E1AP_DT_MRBForwardingResourceRequest_Item * objMRBForwardingResourceRequest_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__MRBForwardingResourceRequest_Item( &objMRBForwardingResourceRequest_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_MRBForwardingResourceRequestList->MRBForwardingResourceRequest_Item, (uint8_t*)objMRBForwardingResourceRequest_Item);

	*pMRBForwardingResourceRequestList = obj_MRBForwardingResourceRequestList;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MRBForwardingResourceRequest_Item( SI_E1AP_DT_MRBForwardingResourceRequest_Item ** pMRBForwardingResourceRequest_Item)
{
	SI_E1AP_DT_MRBForwardingResourceRequest_Item * obj_MRBForwardingResourceRequest_Item = (SI_E1AP_DT_MRBForwardingResourceRequest_Item*) __si_allocM( sizeof(SI_E1AP_DT_MRBForwardingResourceRequest_Item));
	memset( obj_MRBForwardingResourceRequest_Item, 0, sizeof( SI_E1AP_DT_MRBForwardingResourceRequest_Item));

	// L:486
	obj_MRBForwardingResourceRequest_Item->mrb_ID = __getTestINTEGER( 1, 512);    // L:533

	obj_MRBForwardingResourceRequest_Item->selected_emrbProgressRequestType = MRB_ProgressInformationType_oldest_available_val;   // L:529
	obj_MRBForwardingResourceRequest_Item->isPresent_mrbProgressRequestType = 1;

	obj_MRBForwardingResourceRequest_Item->selected_emrbForwardingAddressRequest = MRBForwardingResourceRequestItem_mrbForwardingAddressRequest_request_val;   // L:529
	obj_MRBForwardingResourceRequest_Item->isPresent_mrbForwardingAddressRequest = 1;


	*pMRBForwardingResourceRequest_Item = obj_MRBForwardingResourceRequest_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MCForwardingResourceIndication( SI_E1AP_DT_MCForwardingResourceIndication ** pMCForwardingResourceIndication)
{
	SI_E1AP_DT_MCForwardingResourceIndication * obj_MCForwardingResourceIndication = (SI_E1AP_DT_MCForwardingResourceIndication*) __si_allocM( sizeof(SI_E1AP_DT_MCForwardingResourceIndication));
	memset( obj_MCForwardingResourceIndication, 0, sizeof( SI_E1AP_DT_MCForwardingResourceIndication));

	// L:486
	__si_e1ap_init_MCForwardingResourceID2( &obj_MCForwardingResourceIndication->mcForwardingResourceID, "\x09\x12", 2);    // L:545

	__si_e1ap__set_testdata__MRBForwardingResourceIndicationList( &obj_MCForwardingResourceIndication->mrbForwardingResourceIndicationList);    // L:580
	obj_MCForwardingResourceIndication->isPresent_mrbForwardingResourceIndicationList = 1;

	__si_e1ap__set_testdata__MBSSessionAssociatedInformation( &obj_MCForwardingResourceIndication->mbsSessionAssociatedInformation);    // L:584
	obj_MCForwardingResourceIndication->isPresent_mbsSessionAssociatedInformation = 1;


	*pMCForwardingResourceIndication = obj_MCForwardingResourceIndication;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__MRBForwardingResourceIndicationList( SI_E1AP_DT_MRBForwardingResourceIndicationList ** pMRBForwardingResourceIndicationList)
{
	SI_E1AP_DT_MRBForwardingResourceIndicationList * obj_MRBForwardingResourceIndicationList = NULL; 
	__si_e1ap_init_MRBForwardingResourceIndicationList( &obj_MRBForwardingResourceIndicationList);

	// L:1260
	SI_E1AP_DT_MRBForwardingResourceIndication_Item * objMRBForwardingResourceIndication_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__MRBForwardingResourceIndication_Item( &objMRBForwardingResourceIndication_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_MRBForwardingResourceIndicationList->MRBForwardingResourceIndication_Item, (uint8_t*)objMRBForwardingResourceIndication_Item);

	*pMRBForwardingResourceIndicationList = obj_MRBForwardingResourceIndicationList;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MRBForwardingResourceIndication_Item( SI_E1AP_DT_MRBForwardingResourceIndication_Item ** pMRBForwardingResourceIndication_Item)
{
	SI_E1AP_DT_MRBForwardingResourceIndication_Item * obj_MRBForwardingResourceIndication_Item = (SI_E1AP_DT_MRBForwardingResourceIndication_Item*) __si_allocM( sizeof(SI_E1AP_DT_MRBForwardingResourceIndication_Item));
	memset( obj_MRBForwardingResourceIndication_Item, 0, sizeof( SI_E1AP_DT_MRBForwardingResourceIndication_Item));

	// L:486
	obj_MRBForwardingResourceIndication_Item->mrb_ID = __getTestINTEGER( 1, 512);    // L:533

	__si_e1ap__set_testdata__MRB_ProgressInformation( &obj_MRBForwardingResourceIndication_Item->mrb_ProgressInformation);    // L:584
	obj_MRBForwardingResourceIndication_Item->isPresent_mrb_ProgressInformation = 1;

	__si_e1ap__set_testdata__UP_TNL_Information( &obj_MRBForwardingResourceIndication_Item->mrbForwardingAddress);    // L:588
	obj_MRBForwardingResourceIndication_Item->isPresent_mrbForwardingAddress = 1;


	*pMRBForwardingResourceIndication_Item = obj_MRBForwardingResourceIndication_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MCForwardingResourceResponse( SI_E1AP_DT_MCForwardingResourceResponse ** pMCForwardingResourceResponse)
{
	SI_E1AP_DT_MCForwardingResourceResponse * obj_MCForwardingResourceResponse = (SI_E1AP_DT_MCForwardingResourceResponse*) __si_allocM( sizeof(SI_E1AP_DT_MCForwardingResourceResponse));
	memset( obj_MCForwardingResourceResponse, 0, sizeof( SI_E1AP_DT_MCForwardingResourceResponse));

	// L:486
	__si_e1ap_init_MCForwardingResourceID2( &obj_MCForwardingResourceResponse->mcForwardingResourceID, "\x06\x04", 2);    // L:545

	__si_e1ap__set_testdata__MRBForwardingResourceResponseList( &obj_MCForwardingResourceResponse->mrbForwardingResourceResponseList);    // L:580
	obj_MCForwardingResourceResponse->isPresent_mrbForwardingResourceResponseList = 1;


	*pMCForwardingResourceResponse = obj_MCForwardingResourceResponse;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__MRBForwardingResourceResponseList( SI_E1AP_DT_MRBForwardingResourceResponseList ** pMRBForwardingResourceResponseList)
{
	SI_E1AP_DT_MRBForwardingResourceResponseList * obj_MRBForwardingResourceResponseList = NULL; 
	__si_e1ap_init_MRBForwardingResourceResponseList( &obj_MRBForwardingResourceResponseList);

	// L:1260
	SI_E1AP_DT_MRBForwardingResourceResponse_Item * objMRBForwardingResourceResponse_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__MRBForwardingResourceResponse_Item( &objMRBForwardingResourceResponse_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_MRBForwardingResourceResponseList->MRBForwardingResourceResponse_Item, (uint8_t*)objMRBForwardingResourceResponse_Item);

	*pMRBForwardingResourceResponseList = obj_MRBForwardingResourceResponseList;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MRBForwardingResourceResponse_Item( SI_E1AP_DT_MRBForwardingResourceResponse_Item ** pMRBForwardingResourceResponse_Item)
{
	SI_E1AP_DT_MRBForwardingResourceResponse_Item * obj_MRBForwardingResourceResponse_Item = (SI_E1AP_DT_MRBForwardingResourceResponse_Item*) __si_allocM( sizeof(SI_E1AP_DT_MRBForwardingResourceResponse_Item));
	memset( obj_MRBForwardingResourceResponse_Item, 0, sizeof( SI_E1AP_DT_MRBForwardingResourceResponse_Item));

	// L:486
	obj_MRBForwardingResourceResponse_Item->mrb_ID = __getTestINTEGER( 1, 512);    // L:533

	__si_e1ap__set_testdata__MRB_ProgressInformation( &obj_MRBForwardingResourceResponse_Item->mrb_ProgressInformation);    // L:584
	obj_MRBForwardingResourceResponse_Item->isPresent_mrb_ProgressInformation = 1;

	__si_e1ap__set_testdata__UP_TNL_Information( &obj_MRBForwardingResourceResponse_Item->mrbForwardingAddress);    // L:588
	obj_MRBForwardingResourceResponse_Item->isPresent_mrbForwardingAddress = 1;


	*pMRBForwardingResourceResponse_Item = obj_MRBForwardingResourceResponse_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MCForwardingResourceRelease( SI_E1AP_DT_MCForwardingResourceRelease ** pMCForwardingResourceRelease)
{
	SI_E1AP_DT_MCForwardingResourceRelease * obj_MCForwardingResourceRelease = (SI_E1AP_DT_MCForwardingResourceRelease*) __si_allocM( sizeof(SI_E1AP_DT_MCForwardingResourceRelease));
	memset( obj_MCForwardingResourceRelease, 0, sizeof( SI_E1AP_DT_MCForwardingResourceRelease));

	// L:486
	__si_e1ap_init_MCForwardingResourceID2( &obj_MCForwardingResourceRelease->mcForwardingResourceID, "\x09\x15", 2);    // L:545


	*pMCForwardingResourceRelease = obj_MCForwardingResourceRelease;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MCForwardingResourceReleaseIndication( SI_E1AP_DT_MCForwardingResourceReleaseIndication ** pMCForwardingResourceReleaseIndication)
{
	SI_E1AP_DT_MCForwardingResourceReleaseIndication * obj_MCForwardingResourceReleaseIndication = (SI_E1AP_DT_MCForwardingResourceReleaseIndication*) __si_allocM( sizeof(SI_E1AP_DT_MCForwardingResourceReleaseIndication));
	memset( obj_MCForwardingResourceReleaseIndication, 0, sizeof( SI_E1AP_DT_MCForwardingResourceReleaseIndication));

	// L:486
	__si_e1ap_init_MCForwardingResourceID2( &obj_MCForwardingResourceReleaseIndication->mcForwardingResourceID, "\x23\x13", 2);    // L:545


	*pMCForwardingResourceReleaseIndication = obj_MCForwardingResourceReleaseIndication;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MRB_ProgressInformation( SI_E1AP_DT_MRB_ProgressInformation ** pMRB_ProgressInformation)
{
	SI_E1AP_DT_MRB_ProgressInformation * obj_MRB_ProgressInformation = (SI_E1AP_DT_MRB_ProgressInformation*) __si_allocM( sizeof(SI_E1AP_DT_MRB_ProgressInformation));
	memset( obj_MRB_ProgressInformation, 0, sizeof( SI_E1AP_DT_MRB_ProgressInformation));

	// L:486
	__si_e1ap__set_testdata__MRB_ProgressInformationSNs( &obj_MRB_ProgressInformation->mrb_ProgressInformationSNs);    // L:588

	obj_MRB_ProgressInformation->selected_emrb_ProgressInformationType = MRB_ProgressInformationType_oldest_available_val;   // L:529


	*pMRB_ProgressInformation = obj_MRB_ProgressInformation;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__MRB_ProgressInformationSNs( SI_E1AP_DT_MRB_ProgressInformationSNs ** pMRB_ProgressInformationSNs)
{
	SI_E1AP_DT_MRB_ProgressInformationSNs * obj_MRB_ProgressInformationSNs = (SI_E1AP_DT_MRB_ProgressInformationSNs*) __si_allocM( sizeof(SI_E1AP_DT_MRB_ProgressInformationSNs));
	memset( obj_MRB_ProgressInformationSNs, 0, sizeof( SI_E1AP_DT_MRB_ProgressInformationSNs));

	obj_MRB_ProgressInformationSNs->SelectedChoice = 0;

	// L:2784

	switch( obj_MRB_ProgressInformationSNs->SelectedChoice)
	{
		case 0:
			obj_MRB_ProgressInformationSNs->u.pdcp_SN12 = __getTestINTEGER( 0, 4095);    // L:2816
			break;
		case 1:
			obj_MRB_ProgressInformationSNs->u.pdcp_SN18 = __getTestINTEGER( 0, 262143);    // L:2816
			break;
		case 2:
			__si_e1ap__set_testdata__PDU_MRB_ProgressInformationSNs_ExtIEs( &obj_MRB_ProgressInformationSNs->u.choice_extension);    // L:2871
			break;
	}

	*pMRB_ProgressInformationSNs = obj_MRB_ProgressInformationSNs;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MRDC_Data_Usage_Report_Item( SI_E1AP_DT_MRDC_Data_Usage_Report_Item ** pMRDC_Data_Usage_Report_Item)
{
	SI_E1AP_DT_MRDC_Data_Usage_Report_Item * obj_MRDC_Data_Usage_Report_Item = (SI_E1AP_DT_MRDC_Data_Usage_Report_Item*) __si_allocM( sizeof(SI_E1AP_DT_MRDC_Data_Usage_Report_Item));
	memset( obj_MRDC_Data_Usage_Report_Item, 0, sizeof( SI_E1AP_DT_MRDC_Data_Usage_Report_Item));

	// L:486
	__si_e1ap_init_MRDCDataUsageReportItem_startTimeStamp2( &obj_MRDC_Data_Usage_Report_Item->startTimeStamp, "\x11\x16\x21\x03", 4);    // L:545

	__si_e1ap_init_MRDCDataUsageReportItem_endTimeStamp2( &obj_MRDC_Data_Usage_Report_Item->endTimeStamp, "\x08\x03\x04\x20", 4);    // L:545

	obj_MRDC_Data_Usage_Report_Item->usageCountUL = __getTestINTEGER( 0, 18446744073709552000);    // L:533

	obj_MRDC_Data_Usage_Report_Item->usageCountDL = __getTestINTEGER( 0, 18446744073709552000);    // L:533


	*pMRDC_Data_Usage_Report_Item = obj_MRDC_Data_Usage_Report_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MRDC_Usage_Information( SI_E1AP_DT_MRDC_Usage_Information ** pMRDC_Usage_Information)
{
	SI_E1AP_DT_MRDC_Usage_Information * obj_MRDC_Usage_Information = (SI_E1AP_DT_MRDC_Usage_Information*) __si_allocM( sizeof(SI_E1AP_DT_MRDC_Usage_Information));
	memset( obj_MRDC_Usage_Information, 0, sizeof( SI_E1AP_DT_MRDC_Usage_Information));

	// L:486
	__si_e1ap__set_testdata__Data_Usage_per_PDU_Session_Report( &obj_MRDC_Usage_Information->data_Usage_per_PDU_Session_Report);    // L:584
	obj_MRDC_Usage_Information->isPresent_data_Usage_per_PDU_Session_Report = 1;

	__si_e1ap__set_testdata__Data_Usage_per_QoS_Flow_List( &obj_MRDC_Usage_Information->data_Usage_per_QoS_Flow_List);    // L:580
	obj_MRDC_Usage_Information->isPresent_data_Usage_per_QoS_Flow_List = 1;


	*pMRDC_Usage_Information = obj_MRDC_Usage_Information;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__M4Configuration( SI_E1AP_DT_M4Configuration ** pM4Configuration)
{
	SI_E1AP_DT_M4Configuration * obj_M4Configuration = (SI_E1AP_DT_M4Configuration*) __si_allocM( sizeof(SI_E1AP_DT_M4Configuration));
	memset( obj_M4Configuration, 0, sizeof( SI_E1AP_DT_M4Configuration));

	// L:486
	obj_M4Configuration->selected_em4period = M4period_ms1024_val;   // L:529

	obj_M4Configuration->selected_em4_links_to_log = Links_to_log_uplink_val;   // L:529


	*pM4Configuration = obj_M4Configuration;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__M6Configuration( SI_E1AP_DT_M6Configuration ** pM6Configuration)
{
	SI_E1AP_DT_M6Configuration * obj_M6Configuration = (SI_E1AP_DT_M6Configuration*) __si_allocM( sizeof(SI_E1AP_DT_M6Configuration));
	memset( obj_M6Configuration, 0, sizeof( SI_E1AP_DT_M6Configuration));

	// L:486
	obj_M6Configuration->selected_em6report_Interval = M6report_Interval_ms120_val;   // L:529

	obj_M6Configuration->selected_em6_links_to_log = Links_to_log_uplink_val;   // L:529


	*pM6Configuration = obj_M6Configuration;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__M7Configuration( SI_E1AP_DT_M7Configuration ** pM7Configuration)
{
	SI_E1AP_DT_M7Configuration * obj_M7Configuration = (SI_E1AP_DT_M7Configuration*) __si_allocM( sizeof(SI_E1AP_DT_M7Configuration));
	memset( obj_M7Configuration, 0, sizeof( SI_E1AP_DT_M7Configuration));

	// L:486
	obj_M7Configuration->m7period = __getTestINTEGER( 1, 60);    // L:533

	obj_M7Configuration->selected_em7_links_to_log = Links_to_log_uplink_val;   // L:529


	*pM7Configuration = obj_M7Configuration;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MDT_Configuration( SI_E1AP_DT_MDT_Configuration ** pMDT_Configuration)
{
	SI_E1AP_DT_MDT_Configuration * obj_MDT_Configuration = (SI_E1AP_DT_MDT_Configuration*) __si_allocM( sizeof(SI_E1AP_DT_MDT_Configuration));
	memset( obj_MDT_Configuration, 0, sizeof( SI_E1AP_DT_MDT_Configuration));

	// L:486
	obj_MDT_Configuration->selected_emdt_Activation = MDT_Activation_immediate_MDT_only_val;   // L:529

	__si_e1ap__set_testdata__MDTMode( &obj_MDT_Configuration->mDTMode);    // L:588


	*pMDT_Configuration = obj_MDT_Configuration;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__MDTMode( SI_E1AP_DT_MDTMode ** pMDTMode)
{
	SI_E1AP_DT_MDTMode * obj_MDTMode = (SI_E1AP_DT_MDTMode*) __si_allocM( sizeof(SI_E1AP_DT_MDTMode));
	memset( obj_MDTMode, 0, sizeof( SI_E1AP_DT_MDTMode));

	obj_MDTMode->SelectedChoice = 0;

	// L:2784

	switch( obj_MDTMode->SelectedChoice)
	{
		case 0:
			__si_e1ap__set_testdata__ImmediateMDT( &obj_MDTMode->u.immediateMDT);  // L:2910  ,  Parser:SEQUENCE, ImmediateMDT
			break;
		case 1:
			__si_e1ap__set_testdata__PDU_MDTMode_ExtIEs( &obj_MDTMode->u.choice_extension);    // L:2871
			break;
	}

	*pMDTMode = obj_MDTMode;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__MDTPLMNList( SI_E1AP_DT_MDTPLMNList ** pMDTPLMNList)
{
	SI_E1AP_DT_MDTPLMNList * obj_MDTPLMNList = NULL; 
	__si_e1ap_init_MDTPLMNList( &obj_MDTPLMNList);

	// L:1260
	SI_E1AP_DT_PLMN_Identity * objPLMN_Identity = NULL;

	// OCTETSTRING  , PLMN-Identity  // L:1348
	__si_e1ap_init_PLMN_Identity2( &objPLMN_Identity, "\x06\x16\x12", 3);


	// L:1419
	__si_linked_list_add( obj_MDTPLMNList->PLMN_Identity, (uint8_t*)objPLMN_Identity);

	*pMDTPLMNList = obj_MDTPLMNList;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__MDTPLMNModificationList( SI_E1AP_DT_MDTPLMNModificationList ** pMDTPLMNModificationList)
{
	SI_E1AP_DT_MDTPLMNModificationList * obj_MDTPLMNModificationList = NULL; 
	__si_e1ap_init_MDTPLMNModificationList( &obj_MDTPLMNModificationList);

	// L:1260
	SI_E1AP_DT_PLMN_Identity * objPLMN_Identity = NULL;

	// OCTETSTRING  , PLMN-Identity  // L:1348
	__si_e1ap_init_PLMN_Identity2( &objPLMN_Identity, "\x23\x05\x16", 3);


	// L:1419
	__si_linked_list_add( obj_MDTPLMNModificationList->PLMN_Identity, (uint8_t*)objPLMN_Identity);

	*pMDTPLMNModificationList = obj_MDTPLMNModificationList;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MT_SDT_Information( SI_E1AP_DT_MT_SDT_Information ** pMT_SDT_Information)
{
	SI_E1AP_DT_MT_SDT_Information * obj_MT_SDT_Information = (SI_E1AP_DT_MT_SDT_Information*) __si_allocM( sizeof(SI_E1AP_DT_MT_SDT_Information));
	memset( obj_MT_SDT_Information, 0, sizeof( SI_E1AP_DT_MT_SDT_Information));

	// L:486
	obj_MT_SDT_Information->mT_SDT_Data_Size = __getTestINTEGER( 1, 96000);    // L:533


	*pMT_SDT_Information = obj_MT_SDT_Information;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MBS_ServiceArea( SI_E1AP_DT_MBS_ServiceArea ** pMBS_ServiceArea)
{
	SI_E1AP_DT_MBS_ServiceArea * obj_MBS_ServiceArea = (SI_E1AP_DT_MBS_ServiceArea*) __si_allocM( sizeof(SI_E1AP_DT_MBS_ServiceArea));
	memset( obj_MBS_ServiceArea, 0, sizeof( SI_E1AP_DT_MBS_ServiceArea));

	// L:486
	__si_e1ap__set_testdata__MBS_ServiceAreaInformationList( &obj_MBS_ServiceArea->mBS_ServiceAreaInformationList);    // L:580
	obj_MBS_ServiceArea->isPresent_mBS_ServiceAreaInformationList = 1;


	*pMBS_ServiceArea = obj_MBS_ServiceArea;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MBS_ServiceAreaInformation( SI_E1AP_DT_MBS_ServiceAreaInformation ** pMBS_ServiceAreaInformation)
{
	SI_E1AP_DT_MBS_ServiceAreaInformation * obj_MBS_ServiceAreaInformation = (SI_E1AP_DT_MBS_ServiceAreaInformation*) __si_allocM( sizeof(SI_E1AP_DT_MBS_ServiceAreaInformation));
	memset( obj_MBS_ServiceAreaInformation, 0, sizeof( SI_E1AP_DT_MBS_ServiceAreaInformation));

	// L:486
	__si_e1ap__set_testdata__MBS_ServiceAreaCellList( &obj_MBS_ServiceAreaInformation->mBS_ServiceAreaCellList);    // L:580
	obj_MBS_ServiceAreaInformation->isPresent_mBS_ServiceAreaCellList = 1;

	__si_e1ap__set_testdata__MBS_ServiceAreaTAIList( &obj_MBS_ServiceAreaInformation->mBS_ServiceAreaTAIList);    // L:580
	obj_MBS_ServiceAreaInformation->isPresent_mBS_ServiceAreaTAIList = 1;


	*pMBS_ServiceAreaInformation = obj_MBS_ServiceAreaInformation;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__MBS_ServiceAreaCellList( SI_E1AP_DT_MBS_ServiceAreaCellList ** pMBS_ServiceAreaCellList)
{
	SI_E1AP_DT_MBS_ServiceAreaCellList * obj_MBS_ServiceAreaCellList = NULL; 
	__si_e1ap_init_MBS_ServiceAreaCellList( &obj_MBS_ServiceAreaCellList);

	// L:1260
	SI_E1AP_DT_NR_CGI * objNR_CGI = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__NR_CGI( &objNR_CGI);  // L:1395

	// L:1419
	__si_linked_list_add( obj_MBS_ServiceAreaCellList->NR_CGI, (uint8_t*)objNR_CGI);

	*pMBS_ServiceAreaCellList = obj_MBS_ServiceAreaCellList;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__MBS_ServiceAreaTAIList( SI_E1AP_DT_MBS_ServiceAreaTAIList ** pMBS_ServiceAreaTAIList)
{
	SI_E1AP_DT_MBS_ServiceAreaTAIList * obj_MBS_ServiceAreaTAIList = NULL; 
	__si_e1ap_init_MBS_ServiceAreaTAIList( &obj_MBS_ServiceAreaTAIList);

	// L:1260
	SI_E1AP_DT_MBS_ServiceAreaTAIList_Item * objMBS_ServiceAreaTAIList_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__MBS_ServiceAreaTAIList_Item( &objMBS_ServiceAreaTAIList_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_MBS_ServiceAreaTAIList->MBS_ServiceAreaTAIList_Item, (uint8_t*)objMBS_ServiceAreaTAIList_Item);

	*pMBS_ServiceAreaTAIList = obj_MBS_ServiceAreaTAIList;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MBS_ServiceAreaTAIList_Item( SI_E1AP_DT_MBS_ServiceAreaTAIList_Item ** pMBS_ServiceAreaTAIList_Item)
{
	SI_E1AP_DT_MBS_ServiceAreaTAIList_Item * obj_MBS_ServiceAreaTAIList_Item = (SI_E1AP_DT_MBS_ServiceAreaTAIList_Item*) __si_allocM( sizeof(SI_E1AP_DT_MBS_ServiceAreaTAIList_Item));
	memset( obj_MBS_ServiceAreaTAIList_Item, 0, sizeof( SI_E1AP_DT_MBS_ServiceAreaTAIList_Item));

	// L:486
	__si_e1ap_init_PLMN_Identity2( &obj_MBS_ServiceAreaTAIList_Item->plmn_ID, "\x15\x01\x17", 3);    // L:545

	__si_e1ap_init_FiveGS_TAC2( &obj_MBS_ServiceAreaTAIList_Item->fiveGS_TAC, "\x20\x19\x05", 3);    // L:545


	*pMBS_ServiceAreaTAIList_Item = obj_MBS_ServiceAreaTAIList_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__MBS_ServiceAreaInformationList( SI_E1AP_DT_MBS_ServiceAreaInformationList ** pMBS_ServiceAreaInformationList)
{
	SI_E1AP_DT_MBS_ServiceAreaInformationList * obj_MBS_ServiceAreaInformationList = NULL; 
	__si_e1ap_init_MBS_ServiceAreaInformationList( &obj_MBS_ServiceAreaInformationList);

	// L:1260
	SI_E1AP_DT_MBS_ServiceAreaInformationItem * objMBS_ServiceAreaInformationItem = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__MBS_ServiceAreaInformationItem( &objMBS_ServiceAreaInformationItem);  // L:1395

	// L:1419
	__si_linked_list_add( obj_MBS_ServiceAreaInformationList->MBS_ServiceAreaInformationItem, (uint8_t*)objMBS_ServiceAreaInformationItem);

	*pMBS_ServiceAreaInformationList = obj_MBS_ServiceAreaInformationList;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__MBS_ServiceAreaInformationItem( SI_E1AP_DT_MBS_ServiceAreaInformationItem ** pMBS_ServiceAreaInformationItem)
{
	SI_E1AP_DT_MBS_ServiceAreaInformationItem * obj_MBS_ServiceAreaInformationItem = (SI_E1AP_DT_MBS_ServiceAreaInformationItem*) __si_allocM( sizeof(SI_E1AP_DT_MBS_ServiceAreaInformationItem));
	memset( obj_MBS_ServiceAreaInformationItem, 0, sizeof( SI_E1AP_DT_MBS_ServiceAreaInformationItem));

	// L:486
	obj_MBS_ServiceAreaInformationItem->mBS_AreaSessionID = __getTestINTEGER( 0, 65535);    // L:533

	__si_e1ap__set_testdata__MBS_ServiceAreaInformation( &obj_MBS_ServiceAreaInformationItem->mBS_ServiceAreaInformation);    // L:584


	*pMBS_ServiceAreaInformationItem = obj_MBS_ServiceAreaInformationItem;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__NGRANAllocationAndRetentionPriority( SI_E1AP_DT_NGRANAllocationAndRetentionPriority ** pNGRANAllocationAndRetentionPriority)
{
	SI_E1AP_DT_NGRANAllocationAndRetentionPriority * obj_NGRANAllocationAndRetentionPriority = (SI_E1AP_DT_NGRANAllocationAndRetentionPriority*) __si_allocM( sizeof(SI_E1AP_DT_NGRANAllocationAndRetentionPriority));
	memset( obj_NGRANAllocationAndRetentionPriority, 0, sizeof( SI_E1AP_DT_NGRANAllocationAndRetentionPriority));

	// L:486
	obj_NGRANAllocationAndRetentionPriority->priorityLevel = __getTestINTEGER( 0, 15);    // L:533

	obj_NGRANAllocationAndRetentionPriority->selected_epre_emptionCapability = Pre_emptionCapability_shall_not_trigger_pre_emption_val;   // L:529

	obj_NGRANAllocationAndRetentionPriority->selected_epre_emptionVulnerability = Pre_emptionVulnerability_not_pre_emptable_val;   // L:529


	*pNGRANAllocationAndRetentionPriority = obj_NGRANAllocationAndRetentionPriority;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__NG_RAN_QoS_Support_List( SI_E1AP_DT_NG_RAN_QoS_Support_List ** pNG_RAN_QoS_Support_List)
{
	SI_E1AP_DT_NG_RAN_QoS_Support_List * obj_NG_RAN_QoS_Support_List = NULL; 
	__si_e1ap_init_NG_RAN_QoS_Support_List( &obj_NG_RAN_QoS_Support_List);

	// L:1260
	SI_E1AP_DT_NG_RAN_QoS_Support_Item * objNG_RAN_QoS_Support_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__NG_RAN_QoS_Support_Item( &objNG_RAN_QoS_Support_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_NG_RAN_QoS_Support_List->NG_RAN_QoS_Support_Item, (uint8_t*)objNG_RAN_QoS_Support_Item);

	*pNG_RAN_QoS_Support_List = obj_NG_RAN_QoS_Support_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__NG_RAN_QoS_Support_Item( SI_E1AP_DT_NG_RAN_QoS_Support_Item ** pNG_RAN_QoS_Support_Item)
{
	SI_E1AP_DT_NG_RAN_QoS_Support_Item * obj_NG_RAN_QoS_Support_Item = (SI_E1AP_DT_NG_RAN_QoS_Support_Item*) __si_allocM( sizeof(SI_E1AP_DT_NG_RAN_QoS_Support_Item));
	memset( obj_NG_RAN_QoS_Support_Item, 0, sizeof( SI_E1AP_DT_NG_RAN_QoS_Support_Item));

	// L:486
	__si_e1ap__set_testdata__Non_Dynamic5QIDescriptor( &obj_NG_RAN_QoS_Support_Item->non_Dynamic5QIDescriptor);    // L:584


	*pNG_RAN_QoS_Support_Item = obj_NG_RAN_QoS_Support_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__Non_Dynamic5QIDescriptor( SI_E1AP_DT_Non_Dynamic5QIDescriptor ** pNon_Dynamic5QIDescriptor)
{
	SI_E1AP_DT_Non_Dynamic5QIDescriptor * obj_Non_Dynamic5QIDescriptor = (SI_E1AP_DT_Non_Dynamic5QIDescriptor*) __si_allocM( sizeof(SI_E1AP_DT_Non_Dynamic5QIDescriptor));
	memset( obj_Non_Dynamic5QIDescriptor, 0, sizeof( SI_E1AP_DT_Non_Dynamic5QIDescriptor));

	// L:486
	obj_Non_Dynamic5QIDescriptor->fiveQI = __getTestINTEGER( 0, 255);    // L:533

	obj_Non_Dynamic5QIDescriptor->qoSPriorityLevel = __getTestINTEGER( 0, 127);    // L:533
	obj_Non_Dynamic5QIDescriptor->isPresent_qoSPriorityLevel = 1;

	obj_Non_Dynamic5QIDescriptor->averagingWindow = __getTestINTEGER( 0, 4095);    // L:533
	obj_Non_Dynamic5QIDescriptor->isPresent_averagingWindow = 1;

	obj_Non_Dynamic5QIDescriptor->maxDataBurstVolume = __getTestINTEGER( 0, 4095);    // L:533
	obj_Non_Dynamic5QIDescriptor->isPresent_maxDataBurstVolume = 1;


	*pNon_Dynamic5QIDescriptor = obj_Non_Dynamic5QIDescriptor;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__NPNSupportInfo( SI_E1AP_DT_NPNSupportInfo ** pNPNSupportInfo)
{
	SI_E1AP_DT_NPNSupportInfo * obj_NPNSupportInfo = (SI_E1AP_DT_NPNSupportInfo*) __si_allocM( sizeof(SI_E1AP_DT_NPNSupportInfo));
	memset( obj_NPNSupportInfo, 0, sizeof( SI_E1AP_DT_NPNSupportInfo));

	obj_NPNSupportInfo->SelectedChoice = 0;

	// L:2784

	switch( obj_NPNSupportInfo->SelectedChoice)
	{
		case 0:
			__si_e1ap__set_testdata__NPNSupportInfo_SNPN( &obj_NPNSupportInfo->u.sNPN);  // L:2910  ,  Parser:SEQUENCE, NPNSupportInfo-SNPN
			break;
		case 1:
			__si_e1ap__set_testdata__PDU_NPNSupportInfo_ExtIEs( &obj_NPNSupportInfo->u.choice_extension);    // L:2871
			break;
	}

	*pNPNSupportInfo = obj_NPNSupportInfo;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__NPNSupportInfo_SNPN( SI_E1AP_DT_NPNSupportInfo_SNPN ** pNPNSupportInfo_SNPN)
{
	SI_E1AP_DT_NPNSupportInfo_SNPN * obj_NPNSupportInfo_SNPN = (SI_E1AP_DT_NPNSupportInfo_SNPN*) __si_allocM( sizeof(SI_E1AP_DT_NPNSupportInfo_SNPN));
	memset( obj_NPNSupportInfo_SNPN, 0, sizeof( SI_E1AP_DT_NPNSupportInfo_SNPN));

	// L:486
	__si_e1ap_init_NID2( &obj_NPNSupportInfo_SNPN->nID, "108647", 6, 44);  // L:574
	obj_NPNSupportInfo_SNPN->nID->bitslen = 44; //   L:575


	*pNPNSupportInfo_SNPN = obj_NPNSupportInfo_SNPN;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__NPNContextInfo( SI_E1AP_DT_NPNContextInfo ** pNPNContextInfo)
{
	SI_E1AP_DT_NPNContextInfo * obj_NPNContextInfo = (SI_E1AP_DT_NPNContextInfo*) __si_allocM( sizeof(SI_E1AP_DT_NPNContextInfo));
	memset( obj_NPNContextInfo, 0, sizeof( SI_E1AP_DT_NPNContextInfo));

	obj_NPNContextInfo->SelectedChoice = 0;

	// L:2784

	switch( obj_NPNContextInfo->SelectedChoice)
	{
		case 0:
			__si_e1ap__set_testdata__NPNContextInfo_SNPN( &obj_NPNContextInfo->u.sNPN);  // L:2910  ,  Parser:SEQUENCE, NPNContextInfo-SNPN
			break;
		case 1:
			__si_e1ap__set_testdata__PDU_NPNContextInfo_ExtIEs( &obj_NPNContextInfo->u.choice_extension);    // L:2871
			break;
	}

	*pNPNContextInfo = obj_NPNContextInfo;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__NPNContextInfo_SNPN( SI_E1AP_DT_NPNContextInfo_SNPN ** pNPNContextInfo_SNPN)
{
	SI_E1AP_DT_NPNContextInfo_SNPN * obj_NPNContextInfo_SNPN = (SI_E1AP_DT_NPNContextInfo_SNPN*) __si_allocM( sizeof(SI_E1AP_DT_NPNContextInfo_SNPN));
	memset( obj_NPNContextInfo_SNPN, 0, sizeof( SI_E1AP_DT_NPNContextInfo_SNPN));

	// L:486
	__si_e1ap_init_NID2( &obj_NPNContextInfo_SNPN->nID, "313983", 6, 44);  // L:574
	obj_NPNContextInfo_SNPN->nID->bitslen = 44; //   L:575


	*pNPNContextInfo_SNPN = obj_NPNContextInfo_SNPN;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__NR_CGI( SI_E1AP_DT_NR_CGI ** pNR_CGI)
{
	SI_E1AP_DT_NR_CGI * obj_NR_CGI = (SI_E1AP_DT_NR_CGI*) __si_allocM( sizeof(SI_E1AP_DT_NR_CGI));
	memset( obj_NR_CGI, 0, sizeof( SI_E1AP_DT_NR_CGI));

	// L:486
	__si_e1ap_init_PLMN_Identity2( &obj_NR_CGI->pLMN_Identity, "\x17\x17\x21", 3);    // L:545

	__si_e1ap_init_NR_Cell_Identity2( &obj_NR_CGI->nR_Cell_Identity, "56933", 5, 36);  // L:574
	obj_NR_CGI->nR_Cell_Identity->bitslen = 36; //   L:575


	*pNR_CGI = obj_NR_CGI;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__NR_CGI_Support_List( SI_E1AP_DT_NR_CGI_Support_List ** pNR_CGI_Support_List)
{
	SI_E1AP_DT_NR_CGI_Support_List * obj_NR_CGI_Support_List = NULL; 
	__si_e1ap_init_NR_CGI_Support_List( &obj_NR_CGI_Support_List);

	// L:1260
	SI_E1AP_DT_NR_CGI_Support_Item * objNR_CGI_Support_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__NR_CGI_Support_Item( &objNR_CGI_Support_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_NR_CGI_Support_List->NR_CGI_Support_Item, (uint8_t*)objNR_CGI_Support_Item);

	*pNR_CGI_Support_List = obj_NR_CGI_Support_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__NR_CGI_Support_Item( SI_E1AP_DT_NR_CGI_Support_Item ** pNR_CGI_Support_Item)
{
	SI_E1AP_DT_NR_CGI_Support_Item * obj_NR_CGI_Support_Item = (SI_E1AP_DT_NR_CGI_Support_Item*) __si_allocM( sizeof(SI_E1AP_DT_NR_CGI_Support_Item));
	memset( obj_NR_CGI_Support_Item, 0, sizeof( SI_E1AP_DT_NR_CGI_Support_Item));

	// L:486
	__si_e1ap__set_testdata__NR_CGI( &obj_NR_CGI_Support_Item->nR_CGI);    // L:584


	*pNR_CGI_Support_Item = obj_NR_CGI_Support_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__Extended_NR_CGI_Support_List( SI_E1AP_DT_Extended_NR_CGI_Support_List ** pExtended_NR_CGI_Support_List)
{
	SI_E1AP_DT_Extended_NR_CGI_Support_List * obj_Extended_NR_CGI_Support_List = NULL; 
	__si_e1ap_init_Extended_NR_CGI_Support_List( &obj_Extended_NR_CGI_Support_List);

	// L:1260
	SI_E1AP_DT_Extended_NR_CGI_Support_Item * objExtended_NR_CGI_Support_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__Extended_NR_CGI_Support_Item( &objExtended_NR_CGI_Support_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_Extended_NR_CGI_Support_List->Extended_NR_CGI_Support_Item, (uint8_t*)objExtended_NR_CGI_Support_Item);

	*pExtended_NR_CGI_Support_List = obj_Extended_NR_CGI_Support_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__Extended_NR_CGI_Support_Item( SI_E1AP_DT_Extended_NR_CGI_Support_Item ** pExtended_NR_CGI_Support_Item)
{
	SI_E1AP_DT_Extended_NR_CGI_Support_Item * obj_Extended_NR_CGI_Support_Item = (SI_E1AP_DT_Extended_NR_CGI_Support_Item*) __si_allocM( sizeof(SI_E1AP_DT_Extended_NR_CGI_Support_Item));
	memset( obj_Extended_NR_CGI_Support_Item, 0, sizeof( SI_E1AP_DT_Extended_NR_CGI_Support_Item));

	// L:486
	__si_e1ap__set_testdata__NR_CGI( &obj_Extended_NR_CGI_Support_Item->nR_CGI);    // L:584


	*pExtended_NR_CGI_Support_Item = obj_Extended_NR_CGI_Support_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__N6JitterInformation( SI_E1AP_DT_N6JitterInformation ** pN6JitterInformation)
{
	SI_E1AP_DT_N6JitterInformation * obj_N6JitterInformation = (SI_E1AP_DT_N6JitterInformation*) __si_allocM( sizeof(SI_E1AP_DT_N6JitterInformation));
	memset( obj_N6JitterInformation, 0, sizeof( SI_E1AP_DT_N6JitterInformation));

	// L:486
	obj_N6JitterInformation->n6JitterLowerBound = __getTestINTEGER( -127, 127);    // L:533

	obj_N6JitterInformation->n6JitterUpperBound = __getTestINTEGER( -127, 127);    // L:533


	*pN6JitterInformation = obj_N6JitterInformation;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__PacketErrorRate( SI_E1AP_DT_PacketErrorRate ** pPacketErrorRate)
{
	SI_E1AP_DT_PacketErrorRate * obj_PacketErrorRate = (SI_E1AP_DT_PacketErrorRate*) __si_allocM( sizeof(SI_E1AP_DT_PacketErrorRate));
	memset( obj_PacketErrorRate, 0, sizeof( SI_E1AP_DT_PacketErrorRate));

	// L:486
	obj_PacketErrorRate->pER_Scalar = __getTestINTEGER( 0, 9);    // L:533

	obj_PacketErrorRate->pER_Exponent = __getTestINTEGER( 0, 9);    // L:533


	*pPacketErrorRate = obj_PacketErrorRate;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__PDCP_Configuration( SI_E1AP_DT_PDCP_Configuration ** pPDCP_Configuration)
{
	SI_E1AP_DT_PDCP_Configuration * obj_PDCP_Configuration = (SI_E1AP_DT_PDCP_Configuration*) __si_allocM( sizeof(SI_E1AP_DT_PDCP_Configuration));
	memset( obj_PDCP_Configuration, 0, sizeof( SI_E1AP_DT_PDCP_Configuration));

	// L:486
	obj_PDCP_Configuration->selected_epDCP_SN_Size_UL = PDCP_SN_Size_s_12_val;   // L:529

	obj_PDCP_Configuration->selected_epDCP_SN_Size_DL = PDCP_SN_Size_s_12_val;   // L:529

	obj_PDCP_Configuration->selected_erLC_Mode = RLC_Mode_rlc_tm_val;   // L:529

	__si_e1ap__set_testdata__ROHC_Parameters( &obj_PDCP_Configuration->rOHC_Parameters);    // L:588
	obj_PDCP_Configuration->isPresent_rOHC_Parameters = 1;

	__si_e1ap__set_testdata__T_ReorderingTimer( &obj_PDCP_Configuration->t_ReorderingTimer);    // L:584
	obj_PDCP_Configuration->isPresent_t_ReorderingTimer = 1;

	obj_PDCP_Configuration->selected_ediscardTimer = DiscardTimer_ms10_val;   // L:529
	obj_PDCP_Configuration->isPresent_discardTimer = 1;

	obj_PDCP_Configuration->selected_euLDataSplitThreshold = ULDataSplitThreshold_b0_val;   // L:529
	obj_PDCP_Configuration->isPresent_uLDataSplitThreshold = 1;

	obj_PDCP_Configuration->selected_epDCP_Duplication = PDCP_Duplication_true_val;   // L:529
	obj_PDCP_Configuration->isPresent_pDCP_Duplication = 1;

	obj_PDCP_Configuration->selected_epDCP_Reestablishment = PDCP_Reestablishment_true_val;   // L:529
	obj_PDCP_Configuration->isPresent_pDCP_Reestablishment = 1;

	obj_PDCP_Configuration->selected_epDCP_DataRecovery = PDCP_DataRecovery_true_val;   // L:529
	obj_PDCP_Configuration->isPresent_pDCP_DataRecovery = 1;

	obj_PDCP_Configuration->selected_eduplication_Activation = Duplication_Activation_active_val;   // L:529
	obj_PDCP_Configuration->isPresent_duplication_Activation = 1;

	obj_PDCP_Configuration->selected_eoutOfOrderDelivery = OutOfOrderDelivery_true_val;   // L:529
	obj_PDCP_Configuration->isPresent_outOfOrderDelivery = 1;


	*pPDCP_Configuration = obj_PDCP_Configuration;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__PDCP_Count( SI_E1AP_DT_PDCP_Count ** pPDCP_Count)
{
	SI_E1AP_DT_PDCP_Count * obj_PDCP_Count = (SI_E1AP_DT_PDCP_Count*) __si_allocM( sizeof(SI_E1AP_DT_PDCP_Count));
	memset( obj_PDCP_Count, 0, sizeof( SI_E1AP_DT_PDCP_Count));

	// L:486
	obj_PDCP_Count->pDCP_SN = __getTestINTEGER( 0, 262143);    // L:533

	obj_PDCP_Count->hFN = __getTestINTEGER( 0, 4294967295);    // L:533


	*pPDCP_Count = obj_PDCP_Count;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_Data_Usage_List( SI_E1AP_DT_PDU_Session_Resource_Data_Usage_List ** pPDU_Session_Resource_Data_Usage_List)
{
	SI_E1AP_DT_PDU_Session_Resource_Data_Usage_List * obj_PDU_Session_Resource_Data_Usage_List = NULL; 
	__si_e1ap_init_PDU_Session_Resource_Data_Usage_List( &obj_PDU_Session_Resource_Data_Usage_List);

	// L:1260
	SI_E1AP_DT_PDU_Session_Resource_Data_Usage_Item * objPDU_Session_Resource_Data_Usage_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__PDU_Session_Resource_Data_Usage_Item( &objPDU_Session_Resource_Data_Usage_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_PDU_Session_Resource_Data_Usage_List->PDU_Session_Resource_Data_Usage_Item, (uint8_t*)objPDU_Session_Resource_Data_Usage_Item);

	*pPDU_Session_Resource_Data_Usage_List = obj_PDU_Session_Resource_Data_Usage_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_Data_Usage_Item( SI_E1AP_DT_PDU_Session_Resource_Data_Usage_Item ** pPDU_Session_Resource_Data_Usage_Item)
{
	SI_E1AP_DT_PDU_Session_Resource_Data_Usage_Item * obj_PDU_Session_Resource_Data_Usage_Item = (SI_E1AP_DT_PDU_Session_Resource_Data_Usage_Item*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Session_Resource_Data_Usage_Item));
	memset( obj_PDU_Session_Resource_Data_Usage_Item, 0, sizeof( SI_E1AP_DT_PDU_Session_Resource_Data_Usage_Item));

	// L:486
	obj_PDU_Session_Resource_Data_Usage_Item->pDU_Session_ID = __getTestINTEGER( 0, 255);    // L:533

	__si_e1ap__set_testdata__MRDC_Usage_Information( &obj_PDU_Session_Resource_Data_Usage_Item->mRDC_Usage_Information);    // L:584


	*pPDU_Session_Resource_Data_Usage_Item = obj_PDU_Session_Resource_Data_Usage_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__PDCP_SN_Status_Information( SI_E1AP_DT_PDCP_SN_Status_Information ** pPDCP_SN_Status_Information)
{
	SI_E1AP_DT_PDCP_SN_Status_Information * obj_PDCP_SN_Status_Information = (SI_E1AP_DT_PDCP_SN_Status_Information*) __si_allocM( sizeof(SI_E1AP_DT_PDCP_SN_Status_Information));
	memset( obj_PDCP_SN_Status_Information, 0, sizeof( SI_E1AP_DT_PDCP_SN_Status_Information));

	// L:486
	__si_e1ap__set_testdata__DRBBStatusTransfer( &obj_PDCP_SN_Status_Information->pdcpStatusTransfer_UL);    // L:584

	__si_e1ap__set_testdata__PDCP_Count( &obj_PDCP_SN_Status_Information->pdcpStatusTransfer_DL);    // L:584


	*pPDCP_SN_Status_Information = obj_PDCP_SN_Status_Information;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DRBBStatusTransfer( SI_E1AP_DT_DRBBStatusTransfer ** pDRBBStatusTransfer)
{
	SI_E1AP_DT_DRBBStatusTransfer * obj_DRBBStatusTransfer = (SI_E1AP_DT_DRBBStatusTransfer*) __si_allocM( sizeof(SI_E1AP_DT_DRBBStatusTransfer));
	memset( obj_DRBBStatusTransfer, 0, sizeof( SI_E1AP_DT_DRBBStatusTransfer));

	// L:486
	__si_e1ap_init_DRBBStatusTransfer_receiveStatusofPDCPSDU2( &obj_DRBBStatusTransfer->receiveStatusofPDCPSDU, "0", 1, 1);  // L:574
	obj_DRBBStatusTransfer->receiveStatusofPDCPSDU->bitslen = 1; //   L:575
	obj_DRBBStatusTransfer->isPresent_receiveStatusofPDCPSDU = 1;

	__si_e1ap__set_testdata__PDCP_Count( &obj_DRBBStatusTransfer->countValue);    // L:584


	*pDRBBStatusTransfer = obj_DRBBStatusTransfer;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_Activity_List( SI_E1AP_DT_PDU_Session_Resource_Activity_List ** pPDU_Session_Resource_Activity_List)
{
	SI_E1AP_DT_PDU_Session_Resource_Activity_List * obj_PDU_Session_Resource_Activity_List = NULL; 
	__si_e1ap_init_PDU_Session_Resource_Activity_List( &obj_PDU_Session_Resource_Activity_List);

	// L:1260
	SI_E1AP_DT_PDU_Session_Resource_Activity_Item * objPDU_Session_Resource_Activity_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__PDU_Session_Resource_Activity_Item( &objPDU_Session_Resource_Activity_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_PDU_Session_Resource_Activity_List->PDU_Session_Resource_Activity_Item, (uint8_t*)objPDU_Session_Resource_Activity_Item);

	*pPDU_Session_Resource_Activity_List = obj_PDU_Session_Resource_Activity_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_Activity_Item( SI_E1AP_DT_PDU_Session_Resource_Activity_Item ** pPDU_Session_Resource_Activity_Item)
{
	SI_E1AP_DT_PDU_Session_Resource_Activity_Item * obj_PDU_Session_Resource_Activity_Item = (SI_E1AP_DT_PDU_Session_Resource_Activity_Item*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Session_Resource_Activity_Item));
	memset( obj_PDU_Session_Resource_Activity_Item, 0, sizeof( SI_E1AP_DT_PDU_Session_Resource_Activity_Item));

	// L:486
	obj_PDU_Session_Resource_Activity_Item->pDU_Session_ID = __getTestINTEGER( 0, 255);    // L:533

	obj_PDU_Session_Resource_Activity_Item->selected_epDU_Session_Resource_Activity = PDU_Session_Resource_Activity_active_val;   // L:529


	*pPDU_Session_Resource_Activity_Item = obj_PDU_Session_Resource_Activity_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_Confirm_Modified_List( SI_E1AP_DT_PDU_Session_Resource_Confirm_Modified_List ** pPDU_Session_Resource_Confirm_Modified_List)
{
	SI_E1AP_DT_PDU_Session_Resource_Confirm_Modified_List * obj_PDU_Session_Resource_Confirm_Modified_List = NULL; 
	__si_e1ap_init_PDU_Session_Resource_Confirm_Modified_List( &obj_PDU_Session_Resource_Confirm_Modified_List);

	// L:1260
	SI_E1AP_DT_PDU_Session_Resource_Confirm_Modified_Item * objPDU_Session_Resource_Confirm_Modified_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__PDU_Session_Resource_Confirm_Modified_Item( &objPDU_Session_Resource_Confirm_Modified_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_PDU_Session_Resource_Confirm_Modified_List->PDU_Session_Resource_Confirm_Modified_Item, (uint8_t*)objPDU_Session_Resource_Confirm_Modified_Item);

	*pPDU_Session_Resource_Confirm_Modified_List = obj_PDU_Session_Resource_Confirm_Modified_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_Confirm_Modified_Item( SI_E1AP_DT_PDU_Session_Resource_Confirm_Modified_Item ** pPDU_Session_Resource_Confirm_Modified_Item)
{
	SI_E1AP_DT_PDU_Session_Resource_Confirm_Modified_Item * obj_PDU_Session_Resource_Confirm_Modified_Item = (SI_E1AP_DT_PDU_Session_Resource_Confirm_Modified_Item*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Session_Resource_Confirm_Modified_Item));
	memset( obj_PDU_Session_Resource_Confirm_Modified_Item, 0, sizeof( SI_E1AP_DT_PDU_Session_Resource_Confirm_Modified_Item));

	// L:486
	obj_PDU_Session_Resource_Confirm_Modified_Item->pDU_Session_ID = __getTestINTEGER( 0, 255);    // L:533

	__si_e1ap__set_testdata__DRB_Confirm_Modified_List_NG_RAN( &obj_PDU_Session_Resource_Confirm_Modified_Item->dRB_Confirm_Modified_List_NG_RAN);    // L:580
	obj_PDU_Session_Resource_Confirm_Modified_Item->isPresent_dRB_Confirm_Modified_List_NG_RAN = 1;


	*pPDU_Session_Resource_Confirm_Modified_Item = obj_PDU_Session_Resource_Confirm_Modified_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_Failed_List( SI_E1AP_DT_PDU_Session_Resource_Failed_List ** pPDU_Session_Resource_Failed_List)
{
	SI_E1AP_DT_PDU_Session_Resource_Failed_List * obj_PDU_Session_Resource_Failed_List = NULL; 
	__si_e1ap_init_PDU_Session_Resource_Failed_List( &obj_PDU_Session_Resource_Failed_List);

	// L:1260
	SI_E1AP_DT_PDU_Session_Resource_Failed_Item * objPDU_Session_Resource_Failed_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__PDU_Session_Resource_Failed_Item( &objPDU_Session_Resource_Failed_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_PDU_Session_Resource_Failed_List->PDU_Session_Resource_Failed_Item, (uint8_t*)objPDU_Session_Resource_Failed_Item);

	*pPDU_Session_Resource_Failed_List = obj_PDU_Session_Resource_Failed_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_Failed_Item( SI_E1AP_DT_PDU_Session_Resource_Failed_Item ** pPDU_Session_Resource_Failed_Item)
{
	SI_E1AP_DT_PDU_Session_Resource_Failed_Item * obj_PDU_Session_Resource_Failed_Item = (SI_E1AP_DT_PDU_Session_Resource_Failed_Item*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Session_Resource_Failed_Item));
	memset( obj_PDU_Session_Resource_Failed_Item, 0, sizeof( SI_E1AP_DT_PDU_Session_Resource_Failed_Item));

	// L:486
	obj_PDU_Session_Resource_Failed_Item->pDU_Session_ID = __getTestINTEGER( 0, 255);    // L:533

	__si_e1ap__set_testdata__Cause( &obj_PDU_Session_Resource_Failed_Item->cause);    // L:588


	*pPDU_Session_Resource_Failed_Item = obj_PDU_Session_Resource_Failed_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_Failed_Mod_List( SI_E1AP_DT_PDU_Session_Resource_Failed_Mod_List ** pPDU_Session_Resource_Failed_Mod_List)
{
	SI_E1AP_DT_PDU_Session_Resource_Failed_Mod_List * obj_PDU_Session_Resource_Failed_Mod_List = NULL; 
	__si_e1ap_init_PDU_Session_Resource_Failed_Mod_List( &obj_PDU_Session_Resource_Failed_Mod_List);

	// L:1260
	SI_E1AP_DT_PDU_Session_Resource_Failed_Mod_Item * objPDU_Session_Resource_Failed_Mod_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__PDU_Session_Resource_Failed_Mod_Item( &objPDU_Session_Resource_Failed_Mod_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_PDU_Session_Resource_Failed_Mod_List->PDU_Session_Resource_Failed_Mod_Item, (uint8_t*)objPDU_Session_Resource_Failed_Mod_Item);

	*pPDU_Session_Resource_Failed_Mod_List = obj_PDU_Session_Resource_Failed_Mod_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_Failed_Mod_Item( SI_E1AP_DT_PDU_Session_Resource_Failed_Mod_Item ** pPDU_Session_Resource_Failed_Mod_Item)
{
	SI_E1AP_DT_PDU_Session_Resource_Failed_Mod_Item * obj_PDU_Session_Resource_Failed_Mod_Item = (SI_E1AP_DT_PDU_Session_Resource_Failed_Mod_Item*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Session_Resource_Failed_Mod_Item));
	memset( obj_PDU_Session_Resource_Failed_Mod_Item, 0, sizeof( SI_E1AP_DT_PDU_Session_Resource_Failed_Mod_Item));

	// L:486
	obj_PDU_Session_Resource_Failed_Mod_Item->pDU_Session_ID = __getTestINTEGER( 0, 255);    // L:533

	__si_e1ap__set_testdata__Cause( &obj_PDU_Session_Resource_Failed_Mod_Item->cause);    // L:588


	*pPDU_Session_Resource_Failed_Mod_Item = obj_PDU_Session_Resource_Failed_Mod_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_Failed_To_Modify_List( SI_E1AP_DT_PDU_Session_Resource_Failed_To_Modify_List ** pPDU_Session_Resource_Failed_To_Modify_List)
{
	SI_E1AP_DT_PDU_Session_Resource_Failed_To_Modify_List * obj_PDU_Session_Resource_Failed_To_Modify_List = NULL; 
	__si_e1ap_init_PDU_Session_Resource_Failed_To_Modify_List( &obj_PDU_Session_Resource_Failed_To_Modify_List);

	// L:1260
	SI_E1AP_DT_PDU_Session_Resource_Failed_To_Modify_Item * objPDU_Session_Resource_Failed_To_Modify_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__PDU_Session_Resource_Failed_To_Modify_Item( &objPDU_Session_Resource_Failed_To_Modify_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_PDU_Session_Resource_Failed_To_Modify_List->PDU_Session_Resource_Failed_To_Modify_Item, (uint8_t*)objPDU_Session_Resource_Failed_To_Modify_Item);

	*pPDU_Session_Resource_Failed_To_Modify_List = obj_PDU_Session_Resource_Failed_To_Modify_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_Failed_To_Modify_Item( SI_E1AP_DT_PDU_Session_Resource_Failed_To_Modify_Item ** pPDU_Session_Resource_Failed_To_Modify_Item)
{
	SI_E1AP_DT_PDU_Session_Resource_Failed_To_Modify_Item * obj_PDU_Session_Resource_Failed_To_Modify_Item = (SI_E1AP_DT_PDU_Session_Resource_Failed_To_Modify_Item*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Session_Resource_Failed_To_Modify_Item));
	memset( obj_PDU_Session_Resource_Failed_To_Modify_Item, 0, sizeof( SI_E1AP_DT_PDU_Session_Resource_Failed_To_Modify_Item));

	// L:486
	obj_PDU_Session_Resource_Failed_To_Modify_Item->pDU_Session_ID = __getTestINTEGER( 0, 255);    // L:533

	__si_e1ap__set_testdata__Cause( &obj_PDU_Session_Resource_Failed_To_Modify_Item->cause);    // L:588


	*pPDU_Session_Resource_Failed_To_Modify_Item = obj_PDU_Session_Resource_Failed_To_Modify_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_Modified_List( SI_E1AP_DT_PDU_Session_Resource_Modified_List ** pPDU_Session_Resource_Modified_List)
{
	SI_E1AP_DT_PDU_Session_Resource_Modified_List * obj_PDU_Session_Resource_Modified_List = NULL; 
	__si_e1ap_init_PDU_Session_Resource_Modified_List( &obj_PDU_Session_Resource_Modified_List);

	// L:1260
	SI_E1AP_DT_PDU_Session_Resource_Modified_Item * objPDU_Session_Resource_Modified_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__PDU_Session_Resource_Modified_Item( &objPDU_Session_Resource_Modified_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_PDU_Session_Resource_Modified_List->PDU_Session_Resource_Modified_Item, (uint8_t*)objPDU_Session_Resource_Modified_Item);

	*pPDU_Session_Resource_Modified_List = obj_PDU_Session_Resource_Modified_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_Modified_Item( SI_E1AP_DT_PDU_Session_Resource_Modified_Item ** pPDU_Session_Resource_Modified_Item)
{
	SI_E1AP_DT_PDU_Session_Resource_Modified_Item * obj_PDU_Session_Resource_Modified_Item = (SI_E1AP_DT_PDU_Session_Resource_Modified_Item*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Session_Resource_Modified_Item));
	memset( obj_PDU_Session_Resource_Modified_Item, 0, sizeof( SI_E1AP_DT_PDU_Session_Resource_Modified_Item));

	// L:486
	obj_PDU_Session_Resource_Modified_Item->pDU_Session_ID = __getTestINTEGER( 0, 255);    // L:533

	__si_e1ap__set_testdata__UP_TNL_Information( &obj_PDU_Session_Resource_Modified_Item->nG_DL_UP_TNL_Information);    // L:588
	obj_PDU_Session_Resource_Modified_Item->isPresent_nG_DL_UP_TNL_Information = 1;

	__si_e1ap__set_testdata__SecurityResult( &obj_PDU_Session_Resource_Modified_Item->securityResult);    // L:584
	obj_PDU_Session_Resource_Modified_Item->isPresent_securityResult = 1;

	__si_e1ap__set_testdata__Data_Forwarding_Information( &obj_PDU_Session_Resource_Modified_Item->pDU_Session_Data_Forwarding_Information_Response);    // L:584
	obj_PDU_Session_Resource_Modified_Item->isPresent_pDU_Session_Data_Forwarding_Information_Response = 1;

	__si_e1ap__set_testdata__DRB_Setup_List_NG_RAN( &obj_PDU_Session_Resource_Modified_Item->dRB_Setup_List_NG_RAN);    // L:580
	obj_PDU_Session_Resource_Modified_Item->isPresent_dRB_Setup_List_NG_RAN = 1;

	__si_e1ap__set_testdata__DRB_Failed_List_NG_RAN( &obj_PDU_Session_Resource_Modified_Item->dRB_Failed_List_NG_RAN);    // L:580
	obj_PDU_Session_Resource_Modified_Item->isPresent_dRB_Failed_List_NG_RAN = 1;

	__si_e1ap__set_testdata__DRB_Modified_List_NG_RAN( &obj_PDU_Session_Resource_Modified_Item->dRB_Modified_List_NG_RAN);    // L:580
	obj_PDU_Session_Resource_Modified_Item->isPresent_dRB_Modified_List_NG_RAN = 1;

	__si_e1ap__set_testdata__DRB_Failed_To_Modify_List_NG_RAN( &obj_PDU_Session_Resource_Modified_Item->dRB_Failed_To_Modify_List_NG_RAN);    // L:580
	obj_PDU_Session_Resource_Modified_Item->isPresent_dRB_Failed_To_Modify_List_NG_RAN = 1;


	*pPDU_Session_Resource_Modified_Item = obj_PDU_Session_Resource_Modified_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_Required_To_Modify_List( SI_E1AP_DT_PDU_Session_Resource_Required_To_Modify_List ** pPDU_Session_Resource_Required_To_Modify_List)
{
	SI_E1AP_DT_PDU_Session_Resource_Required_To_Modify_List * obj_PDU_Session_Resource_Required_To_Modify_List = NULL; 
	__si_e1ap_init_PDU_Session_Resource_Required_To_Modify_List( &obj_PDU_Session_Resource_Required_To_Modify_List);

	// L:1260
	SI_E1AP_DT_PDU_Session_Resource_Required_To_Modify_Item * objPDU_Session_Resource_Required_To_Modify_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__PDU_Session_Resource_Required_To_Modify_Item( &objPDU_Session_Resource_Required_To_Modify_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_PDU_Session_Resource_Required_To_Modify_List->PDU_Session_Resource_Required_To_Modify_Item, (uint8_t*)objPDU_Session_Resource_Required_To_Modify_Item);

	*pPDU_Session_Resource_Required_To_Modify_List = obj_PDU_Session_Resource_Required_To_Modify_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_Required_To_Modify_Item( SI_E1AP_DT_PDU_Session_Resource_Required_To_Modify_Item ** pPDU_Session_Resource_Required_To_Modify_Item)
{
	SI_E1AP_DT_PDU_Session_Resource_Required_To_Modify_Item * obj_PDU_Session_Resource_Required_To_Modify_Item = (SI_E1AP_DT_PDU_Session_Resource_Required_To_Modify_Item*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Session_Resource_Required_To_Modify_Item));
	memset( obj_PDU_Session_Resource_Required_To_Modify_Item, 0, sizeof( SI_E1AP_DT_PDU_Session_Resource_Required_To_Modify_Item));

	// L:486
	obj_PDU_Session_Resource_Required_To_Modify_Item->pDU_Session_ID = __getTestINTEGER( 0, 255);    // L:533

	__si_e1ap__set_testdata__UP_TNL_Information( &obj_PDU_Session_Resource_Required_To_Modify_Item->nG_DL_UP_TNL_Information);    // L:588
	obj_PDU_Session_Resource_Required_To_Modify_Item->isPresent_nG_DL_UP_TNL_Information = 1;

	__si_e1ap__set_testdata__DRB_Required_To_Modify_List_NG_RAN( &obj_PDU_Session_Resource_Required_To_Modify_Item->dRB_Required_To_Modify_List_NG_RAN);    // L:580
	obj_PDU_Session_Resource_Required_To_Modify_Item->isPresent_dRB_Required_To_Modify_List_NG_RAN = 1;

	__si_e1ap__set_testdata__DRB_Required_To_Remove_List_NG_RAN( &obj_PDU_Session_Resource_Required_To_Modify_Item->dRB_Required_To_Remove_List_NG_RAN);    // L:580
	obj_PDU_Session_Resource_Required_To_Modify_Item->isPresent_dRB_Required_To_Remove_List_NG_RAN = 1;


	*pPDU_Session_Resource_Required_To_Modify_Item = obj_PDU_Session_Resource_Required_To_Modify_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_Setup_List( SI_E1AP_DT_PDU_Session_Resource_Setup_List ** pPDU_Session_Resource_Setup_List)
{
	SI_E1AP_DT_PDU_Session_Resource_Setup_List * obj_PDU_Session_Resource_Setup_List = NULL; 
	__si_e1ap_init_PDU_Session_Resource_Setup_List( &obj_PDU_Session_Resource_Setup_List);

	// L:1260
	SI_E1AP_DT_PDU_Session_Resource_Setup_Item * objPDU_Session_Resource_Setup_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__PDU_Session_Resource_Setup_Item( &objPDU_Session_Resource_Setup_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_PDU_Session_Resource_Setup_List->PDU_Session_Resource_Setup_Item, (uint8_t*)objPDU_Session_Resource_Setup_Item);

	*pPDU_Session_Resource_Setup_List = obj_PDU_Session_Resource_Setup_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_Setup_Item( SI_E1AP_DT_PDU_Session_Resource_Setup_Item ** pPDU_Session_Resource_Setup_Item)
{
	SI_E1AP_DT_PDU_Session_Resource_Setup_Item * obj_PDU_Session_Resource_Setup_Item = (SI_E1AP_DT_PDU_Session_Resource_Setup_Item*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Session_Resource_Setup_Item));
	memset( obj_PDU_Session_Resource_Setup_Item, 0, sizeof( SI_E1AP_DT_PDU_Session_Resource_Setup_Item));

	// L:486
	obj_PDU_Session_Resource_Setup_Item->pDU_Session_ID = __getTestINTEGER( 0, 255);    // L:533

	__si_e1ap__set_testdata__SecurityResult( &obj_PDU_Session_Resource_Setup_Item->securityResult);    // L:584
	obj_PDU_Session_Resource_Setup_Item->isPresent_securityResult = 1;

	__si_e1ap__set_testdata__UP_TNL_Information( &obj_PDU_Session_Resource_Setup_Item->nG_DL_UP_TNL_Information);    // L:588

	__si_e1ap__set_testdata__Data_Forwarding_Information( &obj_PDU_Session_Resource_Setup_Item->pDU_Session_Data_Forwarding_Information_Response);    // L:584
	obj_PDU_Session_Resource_Setup_Item->isPresent_pDU_Session_Data_Forwarding_Information_Response = 1;

	obj_PDU_Session_Resource_Setup_Item->selected_enG_DL_UP_Unchanged = PDUSessionResourceSetupItem_nG_DL_UP_Unchanged_true_val;   // L:529
	obj_PDU_Session_Resource_Setup_Item->isPresent_nG_DL_UP_Unchanged = 1;

	__si_e1ap__set_testdata__DRB_Setup_List_NG_RAN( &obj_PDU_Session_Resource_Setup_Item->dRB_Setup_List_NG_RAN);    // L:580

	__si_e1ap__set_testdata__DRB_Failed_List_NG_RAN( &obj_PDU_Session_Resource_Setup_Item->dRB_Failed_List_NG_RAN);    // L:580
	obj_PDU_Session_Resource_Setup_Item->isPresent_dRB_Failed_List_NG_RAN = 1;


	*pPDU_Session_Resource_Setup_Item = obj_PDU_Session_Resource_Setup_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_Setup_Mod_List( SI_E1AP_DT_PDU_Session_Resource_Setup_Mod_List ** pPDU_Session_Resource_Setup_Mod_List)
{
	SI_E1AP_DT_PDU_Session_Resource_Setup_Mod_List * obj_PDU_Session_Resource_Setup_Mod_List = NULL; 
	__si_e1ap_init_PDU_Session_Resource_Setup_Mod_List( &obj_PDU_Session_Resource_Setup_Mod_List);

	// L:1260
	SI_E1AP_DT_PDU_Session_Resource_Setup_Mod_Item * objPDU_Session_Resource_Setup_Mod_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__PDU_Session_Resource_Setup_Mod_Item( &objPDU_Session_Resource_Setup_Mod_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_PDU_Session_Resource_Setup_Mod_List->PDU_Session_Resource_Setup_Mod_Item, (uint8_t*)objPDU_Session_Resource_Setup_Mod_Item);

	*pPDU_Session_Resource_Setup_Mod_List = obj_PDU_Session_Resource_Setup_Mod_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_Setup_Mod_Item( SI_E1AP_DT_PDU_Session_Resource_Setup_Mod_Item ** pPDU_Session_Resource_Setup_Mod_Item)
{
	SI_E1AP_DT_PDU_Session_Resource_Setup_Mod_Item * obj_PDU_Session_Resource_Setup_Mod_Item = (SI_E1AP_DT_PDU_Session_Resource_Setup_Mod_Item*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Session_Resource_Setup_Mod_Item));
	memset( obj_PDU_Session_Resource_Setup_Mod_Item, 0, sizeof( SI_E1AP_DT_PDU_Session_Resource_Setup_Mod_Item));

	// L:486
	obj_PDU_Session_Resource_Setup_Mod_Item->pDU_Session_ID = __getTestINTEGER( 0, 255);    // L:533

	__si_e1ap__set_testdata__SecurityResult( &obj_PDU_Session_Resource_Setup_Mod_Item->securityResult);    // L:584
	obj_PDU_Session_Resource_Setup_Mod_Item->isPresent_securityResult = 1;

	__si_e1ap__set_testdata__UP_TNL_Information( &obj_PDU_Session_Resource_Setup_Mod_Item->nG_DL_UP_TNL_Information);    // L:588

	__si_e1ap__set_testdata__Data_Forwarding_Information( &obj_PDU_Session_Resource_Setup_Mod_Item->pDU_Session_Data_Forwarding_Information_Response);    // L:584
	obj_PDU_Session_Resource_Setup_Mod_Item->isPresent_pDU_Session_Data_Forwarding_Information_Response = 1;

	__si_e1ap__set_testdata__DRB_Setup_Mod_List_NG_RAN( &obj_PDU_Session_Resource_Setup_Mod_Item->dRB_Setup_Mod_List_NG_RAN);    // L:580

	__si_e1ap__set_testdata__DRB_Failed_Mod_List_NG_RAN( &obj_PDU_Session_Resource_Setup_Mod_Item->dRB_Failed_Mod_List_NG_RAN);    // L:580
	obj_PDU_Session_Resource_Setup_Mod_Item->isPresent_dRB_Failed_Mod_List_NG_RAN = 1;


	*pPDU_Session_Resource_Setup_Mod_Item = obj_PDU_Session_Resource_Setup_Mod_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_To_Modify_List( SI_E1AP_DT_PDU_Session_Resource_To_Modify_List ** pPDU_Session_Resource_To_Modify_List)
{
	SI_E1AP_DT_PDU_Session_Resource_To_Modify_List * obj_PDU_Session_Resource_To_Modify_List = NULL; 
	__si_e1ap_init_PDU_Session_Resource_To_Modify_List( &obj_PDU_Session_Resource_To_Modify_List);

	// L:1260
	SI_E1AP_DT_PDU_Session_Resource_To_Modify_Item * objPDU_Session_Resource_To_Modify_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__PDU_Session_Resource_To_Modify_Item( &objPDU_Session_Resource_To_Modify_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_PDU_Session_Resource_To_Modify_List->PDU_Session_Resource_To_Modify_Item, (uint8_t*)objPDU_Session_Resource_To_Modify_Item);

	*pPDU_Session_Resource_To_Modify_List = obj_PDU_Session_Resource_To_Modify_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_To_Modify_Item( SI_E1AP_DT_PDU_Session_Resource_To_Modify_Item ** pPDU_Session_Resource_To_Modify_Item)
{
	SI_E1AP_DT_PDU_Session_Resource_To_Modify_Item * obj_PDU_Session_Resource_To_Modify_Item = (SI_E1AP_DT_PDU_Session_Resource_To_Modify_Item*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Session_Resource_To_Modify_Item));
	memset( obj_PDU_Session_Resource_To_Modify_Item, 0, sizeof( SI_E1AP_DT_PDU_Session_Resource_To_Modify_Item));

	// L:486
	obj_PDU_Session_Resource_To_Modify_Item->pDU_Session_ID = __getTestINTEGER( 0, 255);    // L:533

	__si_e1ap__set_testdata__SecurityIndication( &obj_PDU_Session_Resource_To_Modify_Item->securityIndication);    // L:584
	obj_PDU_Session_Resource_To_Modify_Item->isPresent_securityIndication = 1;

	obj_PDU_Session_Resource_To_Modify_Item->pDU_Session_Resource_DL_AMBR = __getTestINTEGER( 0, 4000000000000);    // L:533
	obj_PDU_Session_Resource_To_Modify_Item->isPresent_pDU_Session_Resource_DL_AMBR = 1;

	__si_e1ap__set_testdata__UP_TNL_Information( &obj_PDU_Session_Resource_To_Modify_Item->nG_UL_UP_TNL_Information);    // L:588
	obj_PDU_Session_Resource_To_Modify_Item->isPresent_nG_UL_UP_TNL_Information = 1;

	__si_e1ap__set_testdata__Data_Forwarding_Information_Request( &obj_PDU_Session_Resource_To_Modify_Item->pDU_Session_Data_Forwarding_Information_Request);    // L:584
	obj_PDU_Session_Resource_To_Modify_Item->isPresent_pDU_Session_Data_Forwarding_Information_Request = 1;

	__si_e1ap__set_testdata__Data_Forwarding_Information( &obj_PDU_Session_Resource_To_Modify_Item->pDU_Session_Data_Forwarding_Information);    // L:584
	obj_PDU_Session_Resource_To_Modify_Item->isPresent_pDU_Session_Data_Forwarding_Information = 1;

	obj_PDU_Session_Resource_To_Modify_Item->pDU_Session_Inactivity_Timer = __getTestINTEGER( 1, 7200);    // L:533
	obj_PDU_Session_Resource_To_Modify_Item->isPresent_pDU_Session_Inactivity_Timer = 1;

	obj_PDU_Session_Resource_To_Modify_Item->networkInstance = __getTestINTEGER( 1, 256);    // L:533
	obj_PDU_Session_Resource_To_Modify_Item->isPresent_networkInstance = 1;

	__si_e1ap__set_testdata__DRB_To_Setup_List_NG_RAN( &obj_PDU_Session_Resource_To_Modify_Item->dRB_To_Setup_List_NG_RAN);    // L:580
	obj_PDU_Session_Resource_To_Modify_Item->isPresent_dRB_To_Setup_List_NG_RAN = 1;

	__si_e1ap__set_testdata__DRB_To_Modify_List_NG_RAN( &obj_PDU_Session_Resource_To_Modify_Item->dRB_To_Modify_List_NG_RAN);    // L:580
	obj_PDU_Session_Resource_To_Modify_Item->isPresent_dRB_To_Modify_List_NG_RAN = 1;

	__si_e1ap__set_testdata__DRB_To_Remove_List_NG_RAN( &obj_PDU_Session_Resource_To_Modify_Item->dRB_To_Remove_List_NG_RAN);    // L:580
	obj_PDU_Session_Resource_To_Modify_Item->isPresent_dRB_To_Remove_List_NG_RAN = 1;


	*pPDU_Session_Resource_To_Modify_Item = obj_PDU_Session_Resource_To_Modify_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_To_Remove_List( SI_E1AP_DT_PDU_Session_Resource_To_Remove_List ** pPDU_Session_Resource_To_Remove_List)
{
	SI_E1AP_DT_PDU_Session_Resource_To_Remove_List * obj_PDU_Session_Resource_To_Remove_List = NULL; 
	__si_e1ap_init_PDU_Session_Resource_To_Remove_List( &obj_PDU_Session_Resource_To_Remove_List);

	// L:1260
	SI_E1AP_DT_PDU_Session_Resource_To_Remove_Item * objPDU_Session_Resource_To_Remove_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__PDU_Session_Resource_To_Remove_Item( &objPDU_Session_Resource_To_Remove_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_PDU_Session_Resource_To_Remove_List->PDU_Session_Resource_To_Remove_Item, (uint8_t*)objPDU_Session_Resource_To_Remove_Item);

	*pPDU_Session_Resource_To_Remove_List = obj_PDU_Session_Resource_To_Remove_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_To_Remove_Item( SI_E1AP_DT_PDU_Session_Resource_To_Remove_Item ** pPDU_Session_Resource_To_Remove_Item)
{
	SI_E1AP_DT_PDU_Session_Resource_To_Remove_Item * obj_PDU_Session_Resource_To_Remove_Item = (SI_E1AP_DT_PDU_Session_Resource_To_Remove_Item*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Session_Resource_To_Remove_Item));
	memset( obj_PDU_Session_Resource_To_Remove_Item, 0, sizeof( SI_E1AP_DT_PDU_Session_Resource_To_Remove_Item));

	// L:486
	obj_PDU_Session_Resource_To_Remove_Item->pDU_Session_ID = __getTestINTEGER( 0, 255);    // L:533


	*pPDU_Session_Resource_To_Remove_Item = obj_PDU_Session_Resource_To_Remove_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_To_Setup_List( SI_E1AP_DT_PDU_Session_Resource_To_Setup_List ** pPDU_Session_Resource_To_Setup_List)
{
	SI_E1AP_DT_PDU_Session_Resource_To_Setup_List * obj_PDU_Session_Resource_To_Setup_List = NULL; 
	__si_e1ap_init_PDU_Session_Resource_To_Setup_List( &obj_PDU_Session_Resource_To_Setup_List);

	// L:1260
	SI_E1AP_DT_PDU_Session_Resource_To_Setup_Item * objPDU_Session_Resource_To_Setup_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__PDU_Session_Resource_To_Setup_Item( &objPDU_Session_Resource_To_Setup_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_PDU_Session_Resource_To_Setup_List->PDU_Session_Resource_To_Setup_Item, (uint8_t*)objPDU_Session_Resource_To_Setup_Item);

	*pPDU_Session_Resource_To_Setup_List = obj_PDU_Session_Resource_To_Setup_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_To_Setup_Item( SI_E1AP_DT_PDU_Session_Resource_To_Setup_Item ** pPDU_Session_Resource_To_Setup_Item)
{
	SI_E1AP_DT_PDU_Session_Resource_To_Setup_Item * obj_PDU_Session_Resource_To_Setup_Item = (SI_E1AP_DT_PDU_Session_Resource_To_Setup_Item*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Session_Resource_To_Setup_Item));
	memset( obj_PDU_Session_Resource_To_Setup_Item, 0, sizeof( SI_E1AP_DT_PDU_Session_Resource_To_Setup_Item));

	// L:486
	obj_PDU_Session_Resource_To_Setup_Item->pDU_Session_ID = __getTestINTEGER( 0, 255);    // L:533

	obj_PDU_Session_Resource_To_Setup_Item->selected_epDU_Session_Type = PDU_Session_Type_ipv4_val;   // L:529

	__si_e1ap__set_testdata__SNSSAI( &obj_PDU_Session_Resource_To_Setup_Item->sNSSAI);    // L:584

	__si_e1ap__set_testdata__SecurityIndication( &obj_PDU_Session_Resource_To_Setup_Item->securityIndication);    // L:584

	obj_PDU_Session_Resource_To_Setup_Item->pDU_Session_Resource_DL_AMBR = __getTestINTEGER( 0, 4000000000000);    // L:533
	obj_PDU_Session_Resource_To_Setup_Item->isPresent_pDU_Session_Resource_DL_AMBR = 1;

	__si_e1ap__set_testdata__UP_TNL_Information( &obj_PDU_Session_Resource_To_Setup_Item->nG_UL_UP_TNL_Information);    // L:588

	__si_e1ap__set_testdata__Data_Forwarding_Information_Request( &obj_PDU_Session_Resource_To_Setup_Item->pDU_Session_Data_Forwarding_Information_Request);    // L:584
	obj_PDU_Session_Resource_To_Setup_Item->isPresent_pDU_Session_Data_Forwarding_Information_Request = 1;

	obj_PDU_Session_Resource_To_Setup_Item->pDU_Session_Inactivity_Timer = __getTestINTEGER( 1, 7200);    // L:533
	obj_PDU_Session_Resource_To_Setup_Item->isPresent_pDU_Session_Inactivity_Timer = 1;

	__si_e1ap__set_testdata__UP_TNL_Information( &obj_PDU_Session_Resource_To_Setup_Item->existing_Allocated_NG_DL_UP_TNL_Info);    // L:588
	obj_PDU_Session_Resource_To_Setup_Item->isPresent_existing_Allocated_NG_DL_UP_TNL_Info = 1;

	obj_PDU_Session_Resource_To_Setup_Item->networkInstance = __getTestINTEGER( 1, 256);    // L:533
	obj_PDU_Session_Resource_To_Setup_Item->isPresent_networkInstance = 1;

	__si_e1ap__set_testdata__DRB_To_Setup_List_NG_RAN( &obj_PDU_Session_Resource_To_Setup_Item->dRB_To_Setup_List_NG_RAN);    // L:580


	*pPDU_Session_Resource_To_Setup_Item = obj_PDU_Session_Resource_To_Setup_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_To_Setup_Mod_List( SI_E1AP_DT_PDU_Session_Resource_To_Setup_Mod_List ** pPDU_Session_Resource_To_Setup_Mod_List)
{
	SI_E1AP_DT_PDU_Session_Resource_To_Setup_Mod_List * obj_PDU_Session_Resource_To_Setup_Mod_List = NULL; 
	__si_e1ap_init_PDU_Session_Resource_To_Setup_Mod_List( &obj_PDU_Session_Resource_To_Setup_Mod_List);

	// L:1260
	SI_E1AP_DT_PDU_Session_Resource_To_Setup_Mod_Item * objPDU_Session_Resource_To_Setup_Mod_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__PDU_Session_Resource_To_Setup_Mod_Item( &objPDU_Session_Resource_To_Setup_Mod_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_PDU_Session_Resource_To_Setup_Mod_List->PDU_Session_Resource_To_Setup_Mod_Item, (uint8_t*)objPDU_Session_Resource_To_Setup_Mod_Item);

	*pPDU_Session_Resource_To_Setup_Mod_List = obj_PDU_Session_Resource_To_Setup_Mod_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__PDU_Session_Resource_To_Setup_Mod_Item( SI_E1AP_DT_PDU_Session_Resource_To_Setup_Mod_Item ** pPDU_Session_Resource_To_Setup_Mod_Item)
{
	SI_E1AP_DT_PDU_Session_Resource_To_Setup_Mod_Item * obj_PDU_Session_Resource_To_Setup_Mod_Item = (SI_E1AP_DT_PDU_Session_Resource_To_Setup_Mod_Item*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Session_Resource_To_Setup_Mod_Item));
	memset( obj_PDU_Session_Resource_To_Setup_Mod_Item, 0, sizeof( SI_E1AP_DT_PDU_Session_Resource_To_Setup_Mod_Item));

	// L:486
	obj_PDU_Session_Resource_To_Setup_Mod_Item->pDU_Session_ID = __getTestINTEGER( 0, 255);    // L:533

	obj_PDU_Session_Resource_To_Setup_Mod_Item->selected_epDU_Session_Type = PDU_Session_Type_ipv4_val;   // L:529

	__si_e1ap__set_testdata__SNSSAI( &obj_PDU_Session_Resource_To_Setup_Mod_Item->sNSSAI);    // L:584

	__si_e1ap__set_testdata__SecurityIndication( &obj_PDU_Session_Resource_To_Setup_Mod_Item->securityIndication);    // L:584

	obj_PDU_Session_Resource_To_Setup_Mod_Item->pDU_Session_Resource_AMBR = __getTestINTEGER( 0, 4000000000000);    // L:533
	obj_PDU_Session_Resource_To_Setup_Mod_Item->isPresent_pDU_Session_Resource_AMBR = 1;

	__si_e1ap__set_testdata__UP_TNL_Information( &obj_PDU_Session_Resource_To_Setup_Mod_Item->nG_UL_UP_TNL_Information);    // L:588

	__si_e1ap__set_testdata__Data_Forwarding_Information_Request( &obj_PDU_Session_Resource_To_Setup_Mod_Item->pDU_Session_Data_Forwarding_Information_Request);    // L:584
	obj_PDU_Session_Resource_To_Setup_Mod_Item->isPresent_pDU_Session_Data_Forwarding_Information_Request = 1;

	obj_PDU_Session_Resource_To_Setup_Mod_Item->pDU_Session_Inactivity_Timer = __getTestINTEGER( 1, 7200);    // L:533
	obj_PDU_Session_Resource_To_Setup_Mod_Item->isPresent_pDU_Session_Inactivity_Timer = 1;

	__si_e1ap__set_testdata__DRB_To_Setup_Mod_List_NG_RAN( &obj_PDU_Session_Resource_To_Setup_Mod_Item->dRB_To_Setup_Mod_List_NG_RAN);    // L:580


	*pPDU_Session_Resource_To_Setup_Mod_Item = obj_PDU_Session_Resource_To_Setup_Mod_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__PDU_Session_To_Notify_List( SI_E1AP_DT_PDU_Session_To_Notify_List ** pPDU_Session_To_Notify_List)
{
	SI_E1AP_DT_PDU_Session_To_Notify_List * obj_PDU_Session_To_Notify_List = NULL; 
	__si_e1ap_init_PDU_Session_To_Notify_List( &obj_PDU_Session_To_Notify_List);

	// L:1260
	SI_E1AP_DT_PDU_Session_To_Notify_Item * objPDU_Session_To_Notify_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__PDU_Session_To_Notify_Item( &objPDU_Session_To_Notify_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_PDU_Session_To_Notify_List->PDU_Session_To_Notify_Item, (uint8_t*)objPDU_Session_To_Notify_Item);

	*pPDU_Session_To_Notify_List = obj_PDU_Session_To_Notify_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__PDU_Session_To_Notify_Item( SI_E1AP_DT_PDU_Session_To_Notify_Item ** pPDU_Session_To_Notify_Item)
{
	SI_E1AP_DT_PDU_Session_To_Notify_Item * obj_PDU_Session_To_Notify_Item = (SI_E1AP_DT_PDU_Session_To_Notify_Item*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Session_To_Notify_Item));
	memset( obj_PDU_Session_To_Notify_Item, 0, sizeof( SI_E1AP_DT_PDU_Session_To_Notify_Item));

	// L:486
	obj_PDU_Session_To_Notify_Item->pDU_Session_ID = __getTestINTEGER( 0, 255);    // L:533

	__si_e1ap__set_testdata__QoS_Flow_List( &obj_PDU_Session_To_Notify_Item->qoS_Flow_List);    // L:580


	*pPDU_Session_To_Notify_Item = obj_PDU_Session_To_Notify_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__PDUSetQoSParameters( SI_E1AP_DT_PDUSetQoSParameters ** pPDUSetQoSParameters)
{
	SI_E1AP_DT_PDUSetQoSParameters * obj_PDUSetQoSParameters = (SI_E1AP_DT_PDUSetQoSParameters*) __si_allocM( sizeof(SI_E1AP_DT_PDUSetQoSParameters));
	memset( obj_PDUSetQoSParameters, 0, sizeof( SI_E1AP_DT_PDUSetQoSParameters));

	// L:486
	__si_e1ap__set_testdata__PDUSetQoSInformation( &obj_PDUSetQoSParameters->ulPDUSetQoSInformation);    // L:584
	obj_PDUSetQoSParameters->isPresent_ulPDUSetQoSInformation = 1;

	__si_e1ap__set_testdata__PDUSetQoSInformation( &obj_PDUSetQoSParameters->dlPDUSetQoSInformation);    // L:584
	obj_PDUSetQoSParameters->isPresent_dlPDUSetQoSInformation = 1;


	*pPDUSetQoSParameters = obj_PDUSetQoSParameters;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__PDUSetQoSInformation( SI_E1AP_DT_PDUSetQoSInformation ** pPDUSetQoSInformation)
{
	SI_E1AP_DT_PDUSetQoSInformation * obj_PDUSetQoSInformation = (SI_E1AP_DT_PDUSetQoSInformation*) __si_allocM( sizeof(SI_E1AP_DT_PDUSetQoSInformation));
	memset( obj_PDUSetQoSInformation, 0, sizeof( SI_E1AP_DT_PDUSetQoSInformation));

	// L:486
	obj_PDUSetQoSInformation->pduSetDelayBudget = __getTestINTEGER( 1, 65535);    // L:533
	obj_PDUSetQoSInformation->isPresent_pduSetDelayBudget = 1;

	__si_e1ap__set_testdata__PacketErrorRate( &obj_PDUSetQoSInformation->pduSetErrorRate);    // L:584
	obj_PDUSetQoSInformation->isPresent_pduSetErrorRate = 1;

	obj_PDUSetQoSInformation->selected_epduSetIntegratedHandlingInformation = PDUSetQoSInformation_pduSetIntegratedHandlingInformation_true_val;   // L:529
	obj_PDUSetQoSInformation->isPresent_pduSetIntegratedHandlingInformation = 1;


	*pPDUSetQoSInformation = obj_PDUSetQoSInformation;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__QoS_Characteristics( SI_E1AP_DT_QoS_Characteristics ** pQoS_Characteristics)
{
	SI_E1AP_DT_QoS_Characteristics * obj_QoS_Characteristics = (SI_E1AP_DT_QoS_Characteristics*) __si_allocM( sizeof(SI_E1AP_DT_QoS_Characteristics));
	memset( obj_QoS_Characteristics, 0, sizeof( SI_E1AP_DT_QoS_Characteristics));

	obj_QoS_Characteristics->SelectedChoice = 0;

	// L:2784

	switch( obj_QoS_Characteristics->SelectedChoice)
	{
		case 0:
			__si_e1ap__set_testdata__Non_Dynamic5QIDescriptor( &obj_QoS_Characteristics->u.non_Dynamic_5QI);  // L:2910  ,  Parser:SEQUENCE, Non-Dynamic5QIDescriptor
			break;
		case 1:
			__si_e1ap__set_testdata__Dynamic5QIDescriptor( &obj_QoS_Characteristics->u.dynamic_5QI);  // L:2910  ,  Parser:SEQUENCE, Dynamic5QIDescriptor
			break;
		case 2:
			__si_e1ap__set_testdata__PDU_QoS_Characteristics_ExtIEs( &obj_QoS_Characteristics->u.choice_extension);    // L:2871
			break;
	}

	*pQoS_Characteristics = obj_QoS_Characteristics;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__QoS_Flow_List( SI_E1AP_DT_QoS_Flow_List ** pQoS_Flow_List)
{
	SI_E1AP_DT_QoS_Flow_List * obj_QoS_Flow_List = NULL; 
	__si_e1ap_init_QoS_Flow_List( &obj_QoS_Flow_List);

	// L:1260
	SI_E1AP_DT_QoS_Flow_Item * objQoS_Flow_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__QoS_Flow_Item( &objQoS_Flow_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_QoS_Flow_List->QoS_Flow_Item, (uint8_t*)objQoS_Flow_Item);

	*pQoS_Flow_List = obj_QoS_Flow_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__QoS_Flow_Item( SI_E1AP_DT_QoS_Flow_Item ** pQoS_Flow_Item)
{
	SI_E1AP_DT_QoS_Flow_Item * obj_QoS_Flow_Item = (SI_E1AP_DT_QoS_Flow_Item*) __si_allocM( sizeof(SI_E1AP_DT_QoS_Flow_Item));
	memset( obj_QoS_Flow_Item, 0, sizeof( SI_E1AP_DT_QoS_Flow_Item));

	// L:486
	obj_QoS_Flow_Item->qoS_Flow_Identifier = __getTestINTEGER( 0, 63);    // L:533


	*pQoS_Flow_Item = obj_QoS_Flow_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__QoS_Flow_Failed_List( SI_E1AP_DT_QoS_Flow_Failed_List ** pQoS_Flow_Failed_List)
{
	SI_E1AP_DT_QoS_Flow_Failed_List * obj_QoS_Flow_Failed_List = NULL; 
	__si_e1ap_init_QoS_Flow_Failed_List( &obj_QoS_Flow_Failed_List);

	// L:1260
	SI_E1AP_DT_QoS_Flow_Failed_Item * objQoS_Flow_Failed_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__QoS_Flow_Failed_Item( &objQoS_Flow_Failed_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_QoS_Flow_Failed_List->QoS_Flow_Failed_Item, (uint8_t*)objQoS_Flow_Failed_Item);

	*pQoS_Flow_Failed_List = obj_QoS_Flow_Failed_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__QoS_Flow_Failed_Item( SI_E1AP_DT_QoS_Flow_Failed_Item ** pQoS_Flow_Failed_Item)
{
	SI_E1AP_DT_QoS_Flow_Failed_Item * obj_QoS_Flow_Failed_Item = (SI_E1AP_DT_QoS_Flow_Failed_Item*) __si_allocM( sizeof(SI_E1AP_DT_QoS_Flow_Failed_Item));
	memset( obj_QoS_Flow_Failed_Item, 0, sizeof( SI_E1AP_DT_QoS_Flow_Failed_Item));

	// L:486
	obj_QoS_Flow_Failed_Item->qoS_Flow_Identifier = __getTestINTEGER( 0, 63);    // L:533

	__si_e1ap__set_testdata__Cause( &obj_QoS_Flow_Failed_Item->cause);    // L:588


	*pQoS_Flow_Failed_Item = obj_QoS_Flow_Failed_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__QoS_Flow_Mapping_List( SI_E1AP_DT_QoS_Flow_Mapping_List ** pQoS_Flow_Mapping_List)
{
	SI_E1AP_DT_QoS_Flow_Mapping_List * obj_QoS_Flow_Mapping_List = NULL; 
	__si_e1ap_init_QoS_Flow_Mapping_List( &obj_QoS_Flow_Mapping_List);

	// L:1260
	SI_E1AP_DT_QoS_Flow_Mapping_Item * objQoS_Flow_Mapping_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__QoS_Flow_Mapping_Item( &objQoS_Flow_Mapping_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_QoS_Flow_Mapping_List->QoS_Flow_Mapping_Item, (uint8_t*)objQoS_Flow_Mapping_Item);

	*pQoS_Flow_Mapping_List = obj_QoS_Flow_Mapping_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__QoS_Flow_Mapping_Item( SI_E1AP_DT_QoS_Flow_Mapping_Item ** pQoS_Flow_Mapping_Item)
{
	SI_E1AP_DT_QoS_Flow_Mapping_Item * obj_QoS_Flow_Mapping_Item = (SI_E1AP_DT_QoS_Flow_Mapping_Item*) __si_allocM( sizeof(SI_E1AP_DT_QoS_Flow_Mapping_Item));
	memset( obj_QoS_Flow_Mapping_Item, 0, sizeof( SI_E1AP_DT_QoS_Flow_Mapping_Item));

	// L:486
	obj_QoS_Flow_Mapping_Item->qoS_Flow_Identifier = __getTestINTEGER( 0, 63);    // L:533

	obj_QoS_Flow_Mapping_Item->selected_eqoSFlowMappingIndication = QoS_Flow_Mapping_Indication_ul_val;   // L:529
	obj_QoS_Flow_Mapping_Item->isPresent_qoSFlowMappingIndication = 1;


	*pQoS_Flow_Mapping_Item = obj_QoS_Flow_Mapping_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__QoS_Parameters_Support_List( SI_E1AP_DT_QoS_Parameters_Support_List ** pQoS_Parameters_Support_List)
{
	SI_E1AP_DT_QoS_Parameters_Support_List * obj_QoS_Parameters_Support_List = (SI_E1AP_DT_QoS_Parameters_Support_List*) __si_allocM( sizeof(SI_E1AP_DT_QoS_Parameters_Support_List));
	memset( obj_QoS_Parameters_Support_List, 0, sizeof( SI_E1AP_DT_QoS_Parameters_Support_List));

	// L:486
	__si_e1ap__set_testdata__EUTRAN_QoS_Support_List( &obj_QoS_Parameters_Support_List->eUTRAN_QoS_Support_List);    // L:580
	obj_QoS_Parameters_Support_List->isPresent_eUTRAN_QoS_Support_List = 1;

	__si_e1ap__set_testdata__NG_RAN_QoS_Support_List( &obj_QoS_Parameters_Support_List->nG_RAN_QoS_Support_List);    // L:580
	obj_QoS_Parameters_Support_List->isPresent_nG_RAN_QoS_Support_List = 1;


	*pQoS_Parameters_Support_List = obj_QoS_Parameters_Support_List;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__QoS_Flow_QoS_Parameter_List( SI_E1AP_DT_QoS_Flow_QoS_Parameter_List ** pQoS_Flow_QoS_Parameter_List)
{
	SI_E1AP_DT_QoS_Flow_QoS_Parameter_List * obj_QoS_Flow_QoS_Parameter_List = NULL; 
	__si_e1ap_init_QoS_Flow_QoS_Parameter_List( &obj_QoS_Flow_QoS_Parameter_List);

	// L:1260
	SI_E1AP_DT_QoS_Flow_QoS_Parameter_Item * objQoS_Flow_QoS_Parameter_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__QoS_Flow_QoS_Parameter_Item( &objQoS_Flow_QoS_Parameter_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_QoS_Flow_QoS_Parameter_List->QoS_Flow_QoS_Parameter_Item, (uint8_t*)objQoS_Flow_QoS_Parameter_Item);

	*pQoS_Flow_QoS_Parameter_List = obj_QoS_Flow_QoS_Parameter_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__QoS_Flow_QoS_Parameter_Item( SI_E1AP_DT_QoS_Flow_QoS_Parameter_Item ** pQoS_Flow_QoS_Parameter_Item)
{
	SI_E1AP_DT_QoS_Flow_QoS_Parameter_Item * obj_QoS_Flow_QoS_Parameter_Item = (SI_E1AP_DT_QoS_Flow_QoS_Parameter_Item*) __si_allocM( sizeof(SI_E1AP_DT_QoS_Flow_QoS_Parameter_Item));
	memset( obj_QoS_Flow_QoS_Parameter_Item, 0, sizeof( SI_E1AP_DT_QoS_Flow_QoS_Parameter_Item));

	// L:486
	obj_QoS_Flow_QoS_Parameter_Item->qoS_Flow_Identifier = __getTestINTEGER( 0, 63);    // L:533

	__si_e1ap__set_testdata__QoSFlowLevelQoSParameters( &obj_QoS_Flow_QoS_Parameter_Item->qoSFlowLevelQoSParameters);    // L:584

	obj_QoS_Flow_QoS_Parameter_Item->selected_eqoSFlowMappingIndication = QoS_Flow_Mapping_Indication_ul_val;   // L:529
	obj_QoS_Flow_QoS_Parameter_Item->isPresent_qoSFlowMappingIndication = 1;


	*pQoS_Flow_QoS_Parameter_Item = obj_QoS_Flow_QoS_Parameter_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__QoSFlowLevelQoSParameters( SI_E1AP_DT_QoSFlowLevelQoSParameters ** pQoSFlowLevelQoSParameters)
{
	SI_E1AP_DT_QoSFlowLevelQoSParameters * obj_QoSFlowLevelQoSParameters = (SI_E1AP_DT_QoSFlowLevelQoSParameters*) __si_allocM( sizeof(SI_E1AP_DT_QoSFlowLevelQoSParameters));
	memset( obj_QoSFlowLevelQoSParameters, 0, sizeof( SI_E1AP_DT_QoSFlowLevelQoSParameters));

	// L:486
	__si_e1ap__set_testdata__QoS_Characteristics( &obj_QoSFlowLevelQoSParameters->qoS_Characteristics);    // L:588

	__si_e1ap__set_testdata__NGRANAllocationAndRetentionPriority( &obj_QoSFlowLevelQoSParameters->nGRANallocationRetentionPriority);    // L:584

	__si_e1ap__set_testdata__GBR_QoSFlowInformation( &obj_QoSFlowLevelQoSParameters->gBR_QoS_Flow_Information);    // L:584
	obj_QoSFlowLevelQoSParameters->isPresent_gBR_QoS_Flow_Information = 1;

	obj_QoSFlowLevelQoSParameters->selected_ereflective_QoS_Attribute = QoSFlowLevelQoSParameters_reflective_QoS_Attribute_subject_to_val;   // L:529
	obj_QoSFlowLevelQoSParameters->isPresent_reflective_QoS_Attribute = 1;

	obj_QoSFlowLevelQoSParameters->selected_eadditional_QoS_Information = QoSFlowLevelQoSParameters_additional_QoS_Information_more_likely_val;   // L:529
	obj_QoSFlowLevelQoSParameters->isPresent_additional_QoS_Information = 1;

	obj_QoSFlowLevelQoSParameters->paging_Policy_Index = __getTestINTEGER( 1, 8);    // L:533
	obj_QoSFlowLevelQoSParameters->isPresent_paging_Policy_Index = 1;

	obj_QoSFlowLevelQoSParameters->selected_ereflective_QoS_Indicator = QoSFlowLevelQoSParameters_reflective_QoS_Indicator_enabled_val;   // L:529
	obj_QoSFlowLevelQoSParameters->isPresent_reflective_QoS_Indicator = 1;


	*pQoSFlowLevelQoSParameters = obj_QoSFlowLevelQoSParameters;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__QoS_Flow_Removed_Item( SI_E1AP_DT_QoS_Flow_Removed_Item ** pQoS_Flow_Removed_Item)
{
	SI_E1AP_DT_QoS_Flow_Removed_Item * obj_QoS_Flow_Removed_Item = (SI_E1AP_DT_QoS_Flow_Removed_Item*) __si_allocM( sizeof(SI_E1AP_DT_QoS_Flow_Removed_Item));
	memset( obj_QoS_Flow_Removed_Item, 0, sizeof( SI_E1AP_DT_QoS_Flow_Removed_Item));

	// L:486
	obj_QoS_Flow_Removed_Item->qoS_Flow_Identifier = __getTestINTEGER( 0, 63);    // L:533

	obj_QoS_Flow_Removed_Item->selected_eqoS_Flow_Released_In_Session = QoSFlowRemovedItem_qoS_Flow_Released_In_Session_released_in_session_val;   // L:529
	obj_QoS_Flow_Removed_Item->isPresent_qoS_Flow_Released_In_Session = 1;

	__si_e1ap_init_QoSFlowRemovedItem_qoS_Flow_Accumulated_Session_Time2( &obj_QoS_Flow_Removed_Item->qoS_Flow_Accumulated_Session_Time, "\x09\x13\x01\x15\x03", 5);    // L:545
	obj_QoS_Flow_Removed_Item->isPresent_qoS_Flow_Accumulated_Session_Time = 1;


	*pQoS_Flow_Removed_Item = obj_QoS_Flow_Removed_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__QoS_Flows_to_be_forwarded_List( SI_E1AP_DT_QoS_Flows_to_be_forwarded_List ** pQoS_Flows_to_be_forwarded_List)
{
	SI_E1AP_DT_QoS_Flows_to_be_forwarded_List * obj_QoS_Flows_to_be_forwarded_List = NULL; 
	__si_e1ap_init_QoS_Flows_to_be_forwarded_List( &obj_QoS_Flows_to_be_forwarded_List);

	// L:1260
	SI_E1AP_DT_QoS_Flows_to_be_forwarded_Item * objQoS_Flows_to_be_forwarded_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__QoS_Flows_to_be_forwarded_Item( &objQoS_Flows_to_be_forwarded_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_QoS_Flows_to_be_forwarded_List->QoS_Flows_to_be_forwarded_Item, (uint8_t*)objQoS_Flows_to_be_forwarded_Item);

	*pQoS_Flows_to_be_forwarded_List = obj_QoS_Flows_to_be_forwarded_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__QoS_Flows_to_be_forwarded_Item( SI_E1AP_DT_QoS_Flows_to_be_forwarded_Item ** pQoS_Flows_to_be_forwarded_Item)
{
	SI_E1AP_DT_QoS_Flows_to_be_forwarded_Item * obj_QoS_Flows_to_be_forwarded_Item = (SI_E1AP_DT_QoS_Flows_to_be_forwarded_Item*) __si_allocM( sizeof(SI_E1AP_DT_QoS_Flows_to_be_forwarded_Item));
	memset( obj_QoS_Flows_to_be_forwarded_Item, 0, sizeof( SI_E1AP_DT_QoS_Flows_to_be_forwarded_Item));

	// L:486
	obj_QoS_Flows_to_be_forwarded_Item->qoS_Flow_Identifier = __getTestINTEGER( 0, 63);    // L:533


	*pQoS_Flows_to_be_forwarded_Item = obj_QoS_Flows_to_be_forwarded_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__QoS_Mapping_Information( SI_E1AP_DT_QoS_Mapping_Information ** pQoS_Mapping_Information)
{
	SI_E1AP_DT_QoS_Mapping_Information * obj_QoS_Mapping_Information = (SI_E1AP_DT_QoS_Mapping_Information*) __si_allocM( sizeof(SI_E1AP_DT_QoS_Mapping_Information));
	memset( obj_QoS_Mapping_Information, 0, sizeof( SI_E1AP_DT_QoS_Mapping_Information));

	// L:486
	__si_e1ap_init_QoSMappingInformation_dscp2( &obj_QoS_Mapping_Information->dscp, "6", 1, 6);  // L:574
	obj_QoS_Mapping_Information->dscp->bitslen = 6; //   L:575
	obj_QoS_Mapping_Information->isPresent_dscp = 1;

	__si_e1ap_init_QoSMappingInformation_flow_label2( &obj_QoS_Mapping_Information->flow_label, "606", 3, 20);  // L:574
	obj_QoS_Mapping_Information->flow_label->bitslen = 20; //   L:575
	obj_QoS_Mapping_Information->isPresent_flow_label = 1;


	*pQoS_Mapping_Information = obj_QoS_Mapping_Information;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DataForwardingtoNG_RANQoSFlowInformationList( SI_E1AP_DT_DataForwardingtoNG_RANQoSFlowInformationList ** pDataForwardingtoNG_RANQoSFlowInformationList)
{
	SI_E1AP_DT_DataForwardingtoNG_RANQoSFlowInformationList * obj_DataForwardingtoNG_RANQoSFlowInformationList = NULL; 
	__si_e1ap_init_DataForwardingtoNG_RANQoSFlowInformationList( &obj_DataForwardingtoNG_RANQoSFlowInformationList);

	// L:1260
	SI_E1AP_DT_DataForwardingtoNG_RANQoSFlowInformationList_Item * objDataForwardingtoNG_RANQoSFlowInformationList_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DataForwardingtoNG_RANQoSFlowInformationList_Item( &objDataForwardingtoNG_RANQoSFlowInformationList_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DataForwardingtoNG_RANQoSFlowInformationList->DataForwardingtoNG_RANQoSFlowInformationList_Item, (uint8_t*)objDataForwardingtoNG_RANQoSFlowInformationList_Item);

	*pDataForwardingtoNG_RANQoSFlowInformationList = obj_DataForwardingtoNG_RANQoSFlowInformationList;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__DataForwardingtoNG_RANQoSFlowInformationList_Item( SI_E1AP_DT_DataForwardingtoNG_RANQoSFlowInformationList_Item ** pDataForwardingtoNG_RANQoSFlowInformationList_Item)
{
	SI_E1AP_DT_DataForwardingtoNG_RANQoSFlowInformationList_Item * obj_DataForwardingtoNG_RANQoSFlowInformationList_Item = (SI_E1AP_DT_DataForwardingtoNG_RANQoSFlowInformationList_Item*) __si_allocM( sizeof(SI_E1AP_DT_DataForwardingtoNG_RANQoSFlowInformationList_Item));
	memset( obj_DataForwardingtoNG_RANQoSFlowInformationList_Item, 0, sizeof( SI_E1AP_DT_DataForwardingtoNG_RANQoSFlowInformationList_Item));

	// L:486
	obj_DataForwardingtoNG_RANQoSFlowInformationList_Item->qoS_Flow_Identifier = __getTestINTEGER( 0, 63);    // L:533


	*pDataForwardingtoNG_RANQoSFlowInformationList_Item = obj_DataForwardingtoNG_RANQoSFlowInformationList_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__RedundantPDUSessionInformation( SI_E1AP_DT_RedundantPDUSessionInformation ** pRedundantPDUSessionInformation)
{
	SI_E1AP_DT_RedundantPDUSessionInformation * obj_RedundantPDUSessionInformation = (SI_E1AP_DT_RedundantPDUSessionInformation*) __si_allocM( sizeof(SI_E1AP_DT_RedundantPDUSessionInformation));
	memset( obj_RedundantPDUSessionInformation, 0, sizeof( SI_E1AP_DT_RedundantPDUSessionInformation));

	// L:486
	obj_RedundantPDUSessionInformation->selected_erSN = RSN_v1_val;   // L:529


	*pRedundantPDUSessionInformation = obj_RedundantPDUSessionInformation;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__RetainabilityMeasurementsInfo( SI_E1AP_DT_RetainabilityMeasurementsInfo ** pRetainabilityMeasurementsInfo)
{
	SI_E1AP_DT_RetainabilityMeasurementsInfo * obj_RetainabilityMeasurementsInfo = NULL; 
	__si_e1ap_init_RetainabilityMeasurementsInfo( &obj_RetainabilityMeasurementsInfo);

	// L:1260
	SI_E1AP_DT_DRB_Removed_Item * objDRB_Removed_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_Removed_Item( &objDRB_Removed_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_RetainabilityMeasurementsInfo->DRB_Removed_Item, (uint8_t*)objDRB_Removed_Item);

	*pRetainabilityMeasurementsInfo = obj_RetainabilityMeasurementsInfo;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__ROHC_Parameters( SI_E1AP_DT_ROHC_Parameters ** pROHC_Parameters)
{
	SI_E1AP_DT_ROHC_Parameters * obj_ROHC_Parameters = (SI_E1AP_DT_ROHC_Parameters*) __si_allocM( sizeof(SI_E1AP_DT_ROHC_Parameters));
	memset( obj_ROHC_Parameters, 0, sizeof( SI_E1AP_DT_ROHC_Parameters));

	obj_ROHC_Parameters->SelectedChoice = 0;

	// L:2784

	switch( obj_ROHC_Parameters->SelectedChoice)
	{
		case 0:
			__si_e1ap__set_testdata__ROHC( &obj_ROHC_Parameters->u.rOHC);  // L:2910  ,  Parser:SEQUENCE, ROHC
			break;
		case 1:
			__si_e1ap__set_testdata__UplinkOnlyROHC( &obj_ROHC_Parameters->u.uPlinkOnlyROHC);  // L:2910  ,  Parser:SEQUENCE, UplinkOnlyROHC
			break;
		case 2:
			__si_e1ap__set_testdata__PDU_ROHC_Parameters_ExtIEs( &obj_ROHC_Parameters->u.choice_Extension);    // L:2871
			break;
	}

	*pROHC_Parameters = obj_ROHC_Parameters;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__ROHC( SI_E1AP_DT_ROHC ** pROHC)
{
	SI_E1AP_DT_ROHC * obj_ROHC = (SI_E1AP_DT_ROHC*) __si_allocM( sizeof(SI_E1AP_DT_ROHC));
	memset( obj_ROHC, 0, sizeof( SI_E1AP_DT_ROHC));

	// L:486
	obj_ROHC->maxCID = __getTestINTEGER( 0, 16383);    // L:533

	obj_ROHC->rOHC_Profiles = __getTestINTEGER( 0, 511);    // L:533

	obj_ROHC->selected_econtinueROHC = ROHC_continueROHC_true_val;   // L:529
	obj_ROHC->isPresent_continueROHC = 1;


	*pROHC = obj_ROHC;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__SecurityAlgorithm( SI_E1AP_DT_SecurityAlgorithm ** pSecurityAlgorithm)
{
	SI_E1AP_DT_SecurityAlgorithm * obj_SecurityAlgorithm = (SI_E1AP_DT_SecurityAlgorithm*) __si_allocM( sizeof(SI_E1AP_DT_SecurityAlgorithm));
	memset( obj_SecurityAlgorithm, 0, sizeof( SI_E1AP_DT_SecurityAlgorithm));

	// L:486
	obj_SecurityAlgorithm->selected_ecipheringAlgorithm = CipheringAlgorithm_nEA0_val;   // L:529

	obj_SecurityAlgorithm->selected_eintegrityProtectionAlgorithm = IntegrityProtectionAlgorithm_nIA0_val;   // L:529
	obj_SecurityAlgorithm->isPresent_integrityProtectionAlgorithm = 1;


	*pSecurityAlgorithm = obj_SecurityAlgorithm;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__SecurityIndication( SI_E1AP_DT_SecurityIndication ** pSecurityIndication)
{
	SI_E1AP_DT_SecurityIndication * obj_SecurityIndication = (SI_E1AP_DT_SecurityIndication*) __si_allocM( sizeof(SI_E1AP_DT_SecurityIndication));
	memset( obj_SecurityIndication, 0, sizeof( SI_E1AP_DT_SecurityIndication));

	// L:486
	obj_SecurityIndication->selected_eintegrityProtectionIndication = IntegrityProtectionIndication_required_val;   // L:529

	obj_SecurityIndication->selected_econfidentialityProtectionIndication = ConfidentialityProtectionIndication_required_val;   // L:529

	__si_e1ap__set_testdata__MaximumIPdatarate( &obj_SecurityIndication->maximumIPdatarate);    // L:584
	obj_SecurityIndication->isPresent_maximumIPdatarate = 1;


	*pSecurityIndication = obj_SecurityIndication;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__SecurityInformation( SI_E1AP_DT_SecurityInformation ** pSecurityInformation)
{
	SI_E1AP_DT_SecurityInformation * obj_SecurityInformation = (SI_E1AP_DT_SecurityInformation*) __si_allocM( sizeof(SI_E1AP_DT_SecurityInformation));
	memset( obj_SecurityInformation, 0, sizeof( SI_E1AP_DT_SecurityInformation));

	// L:486
	__si_e1ap__set_testdata__SecurityAlgorithm( &obj_SecurityInformation->securityAlgorithm);    // L:584

	__si_e1ap__set_testdata__UPSecuritykey( &obj_SecurityInformation->uPSecuritykey);    // L:584


	*pSecurityInformation = obj_SecurityInformation;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__SecurityResult( SI_E1AP_DT_SecurityResult ** pSecurityResult)
{
	SI_E1AP_DT_SecurityResult * obj_SecurityResult = (SI_E1AP_DT_SecurityResult*) __si_allocM( sizeof(SI_E1AP_DT_SecurityResult));
	memset( obj_SecurityResult, 0, sizeof( SI_E1AP_DT_SecurityResult));

	// L:486
	obj_SecurityResult->selected_eintegrityProtectionResult = IntegrityProtectionResult_performed_val;   // L:529

	obj_SecurityResult->selected_econfidentialityProtectionResult = ConfidentialityProtectionResult_performed_val;   // L:529


	*pSecurityResult = obj_SecurityResult;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__Slice_Support_List( SI_E1AP_DT_Slice_Support_List ** pSlice_Support_List)
{
	SI_E1AP_DT_Slice_Support_List * obj_Slice_Support_List = NULL; 
	__si_e1ap_init_Slice_Support_List( &obj_Slice_Support_List);

	// L:1260
	SI_E1AP_DT_Slice_Support_Item * objSlice_Support_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__Slice_Support_Item( &objSlice_Support_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_Slice_Support_List->Slice_Support_Item, (uint8_t*)objSlice_Support_Item);

	*pSlice_Support_List = obj_Slice_Support_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__Slice_Support_Item( SI_E1AP_DT_Slice_Support_Item ** pSlice_Support_Item)
{
	SI_E1AP_DT_Slice_Support_Item * obj_Slice_Support_Item = (SI_E1AP_DT_Slice_Support_Item*) __si_allocM( sizeof(SI_E1AP_DT_Slice_Support_Item));
	memset( obj_Slice_Support_Item, 0, sizeof( SI_E1AP_DT_Slice_Support_Item));

	// L:486
	__si_e1ap__set_testdata__SNSSAI( &obj_Slice_Support_Item->sNSSAI);    // L:584


	*pSlice_Support_Item = obj_Slice_Support_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__SNSSAI( SI_E1AP_DT_SNSSAI ** pSNSSAI)
{
	SI_E1AP_DT_SNSSAI * obj_SNSSAI = (SI_E1AP_DT_SNSSAI*) __si_allocM( sizeof(SI_E1AP_DT_SNSSAI));
	memset( obj_SNSSAI, 0, sizeof( SI_E1AP_DT_SNSSAI));

	// L:486
	__si_e1ap_init_SNSSAI_sST2( &obj_SNSSAI->sST, "\x05", 1);    // L:545

	__si_e1ap_init_SNSSAI_sD2( &obj_SNSSAI->sD, "\x09\x17\x09", 3);    // L:545
	obj_SNSSAI->isPresent_sD = 1;


	*pSNSSAI = obj_SNSSAI;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__SDAP_Configuration( SI_E1AP_DT_SDAP_Configuration ** pSDAP_Configuration)
{
	SI_E1AP_DT_SDAP_Configuration * obj_SDAP_Configuration = (SI_E1AP_DT_SDAP_Configuration*) __si_allocM( sizeof(SI_E1AP_DT_SDAP_Configuration));
	memset( obj_SDAP_Configuration, 0, sizeof( SI_E1AP_DT_SDAP_Configuration));

	// L:486
	obj_SDAP_Configuration->selected_edefaultDRB = DefaultDRB_true_val;   // L:529

	obj_SDAP_Configuration->selected_esDAP_Header_UL = SDAP_Header_UL_present_val;   // L:529

	obj_SDAP_Configuration->selected_esDAP_Header_DL = SDAP_Header_DL_present_val;   // L:529


	*pSDAP_Configuration = obj_SDAP_Configuration;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__TNL_AvailableCapacityIndicator( SI_E1AP_DT_TNL_AvailableCapacityIndicator ** pTNL_AvailableCapacityIndicator)
{
	SI_E1AP_DT_TNL_AvailableCapacityIndicator * obj_TNL_AvailableCapacityIndicator = (SI_E1AP_DT_TNL_AvailableCapacityIndicator*) __si_allocM( sizeof(SI_E1AP_DT_TNL_AvailableCapacityIndicator));
	memset( obj_TNL_AvailableCapacityIndicator, 0, sizeof( SI_E1AP_DT_TNL_AvailableCapacityIndicator));

	// L:486
	obj_TNL_AvailableCapacityIndicator->dL_TNL_OfferedCapacity = __getTestINTEGER( 0, 16777216);    // L:533

	obj_TNL_AvailableCapacityIndicator->dL_TNL_AvailableCapacity = __getTestINTEGER( 0, 100);    // L:533

	obj_TNL_AvailableCapacityIndicator->uL_TNL_OfferedCapacity = __getTestINTEGER( 0, 16777216);    // L:533

	obj_TNL_AvailableCapacityIndicator->uL_TNL_AvailableCapacity = __getTestINTEGER( 0, 100);    // L:533


	*pTNL_AvailableCapacityIndicator = obj_TNL_AvailableCapacityIndicator;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__TSCTrafficCharacteristics( SI_E1AP_DT_TSCTrafficCharacteristics ** pTSCTrafficCharacteristics)
{
	SI_E1AP_DT_TSCTrafficCharacteristics * obj_TSCTrafficCharacteristics = (SI_E1AP_DT_TSCTrafficCharacteristics*) __si_allocM( sizeof(SI_E1AP_DT_TSCTrafficCharacteristics));
	memset( obj_TSCTrafficCharacteristics, 0, sizeof( SI_E1AP_DT_TSCTrafficCharacteristics));

	// L:486
	__si_e1ap__set_testdata__TSCAssistanceInformation( &obj_TSCTrafficCharacteristics->tSCTrafficCharacteristicsUL);    // L:584
	obj_TSCTrafficCharacteristics->isPresent_tSCTrafficCharacteristicsUL = 1;

	__si_e1ap__set_testdata__TSCAssistanceInformation( &obj_TSCTrafficCharacteristics->tSCTrafficCharacteristicsDL);    // L:584
	obj_TSCTrafficCharacteristics->isPresent_tSCTrafficCharacteristicsDL = 1;


	*pTSCTrafficCharacteristics = obj_TSCTrafficCharacteristics;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__TSCAssistanceInformation( SI_E1AP_DT_TSCAssistanceInformation ** pTSCAssistanceInformation)
{
	SI_E1AP_DT_TSCAssistanceInformation * obj_TSCAssistanceInformation = (SI_E1AP_DT_TSCAssistanceInformation*) __si_allocM( sizeof(SI_E1AP_DT_TSCAssistanceInformation));
	memset( obj_TSCAssistanceInformation, 0, sizeof( SI_E1AP_DT_TSCAssistanceInformation));

	// L:486
	obj_TSCAssistanceInformation->periodicity = __getTestINTEGER( 1, 640000);    // L:533

	__si_e1ap_init_BurstArrivalTime2( &obj_TSCAssistanceInformation->burstArrivalTime, "\x08\x08\x09\x18\x12", 5);    // L:540
	obj_TSCAssistanceInformation->isPresent_burstArrivalTime = 1;


	*pTSCAssistanceInformation = obj_TSCAssistanceInformation;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__TraceActivation( SI_E1AP_DT_TraceActivation ** pTraceActivation)
{
	SI_E1AP_DT_TraceActivation * obj_TraceActivation = (SI_E1AP_DT_TraceActivation*) __si_allocM( sizeof(SI_E1AP_DT_TraceActivation));
	memset( obj_TraceActivation, 0, sizeof( SI_E1AP_DT_TraceActivation));

	// L:486
	__si_e1ap_init_TraceID2( &obj_TraceActivation->traceID, "\x20\x15\x05\x01\x19\x07\x02\x20", 8);    // L:545

	__si_e1ap_init_InterfacesToTrace2( &obj_TraceActivation->interfacesToTrace, "0", 1, 8);  // L:574
	obj_TraceActivation->interfacesToTrace->bitslen = 8; //   L:575

	obj_TraceActivation->selected_etraceDepth = TraceDepth_minimum_val;   // L:529

	__si_e1ap_init_TransportLayerAddress2( &obj_TraceActivation->traceCollectionEntityIPAddress, "9", 1, 1);  // L:574
	obj_TraceActivation->traceCollectionEntityIPAddress->bitslen = 1; //   L:575


	*pTraceActivation = obj_TraceActivation;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__T_ReorderingTimer( SI_E1AP_DT_T_ReorderingTimer ** pT_ReorderingTimer)
{
	SI_E1AP_DT_T_ReorderingTimer * obj_T_ReorderingTimer = (SI_E1AP_DT_T_ReorderingTimer*) __si_allocM( sizeof(SI_E1AP_DT_T_ReorderingTimer));
	memset( obj_T_ReorderingTimer, 0, sizeof( SI_E1AP_DT_T_ReorderingTimer));

	// L:486
	obj_T_ReorderingTimer->selected_et_Reordering = T_Reordering_ms0_val;   // L:529


	*pT_ReorderingTimer = obj_T_ReorderingTimer;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__Transport_Layer_Address_Info( SI_E1AP_DT_Transport_Layer_Address_Info ** pTransport_Layer_Address_Info)
{
	SI_E1AP_DT_Transport_Layer_Address_Info * obj_Transport_Layer_Address_Info = (SI_E1AP_DT_Transport_Layer_Address_Info*) __si_allocM( sizeof(SI_E1AP_DT_Transport_Layer_Address_Info));
	memset( obj_Transport_Layer_Address_Info, 0, sizeof( SI_E1AP_DT_Transport_Layer_Address_Info));

	// L:486
	__si_e1ap__set_testdata__Transport_UP_Layer_Addresses_Info_To_Add_List( &obj_Transport_Layer_Address_Info->transport_UP_Layer_Addresses_Info_To_Add_List);    // L:580
	obj_Transport_Layer_Address_Info->isPresent_transport_UP_Layer_Addresses_Info_To_Add_List = 1;

	__si_e1ap__set_testdata__Transport_UP_Layer_Addresses_Info_To_Remove_List( &obj_Transport_Layer_Address_Info->transport_UP_Layer_Addresses_Info_To_Remove_List);    // L:580
	obj_Transport_Layer_Address_Info->isPresent_transport_UP_Layer_Addresses_Info_To_Remove_List = 1;


	*pTransport_Layer_Address_Info = obj_Transport_Layer_Address_Info;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__Transport_UP_Layer_Addresses_Info_To_Add_List( SI_E1AP_DT_Transport_UP_Layer_Addresses_Info_To_Add_List ** pTransport_UP_Layer_Addresses_Info_To_Add_List)
{
	SI_E1AP_DT_Transport_UP_Layer_Addresses_Info_To_Add_List * obj_Transport_UP_Layer_Addresses_Info_To_Add_List = NULL; 
	__si_e1ap_init_Transport_UP_Layer_Addresses_Info_To_Add_List( &obj_Transport_UP_Layer_Addresses_Info_To_Add_List);

	// L:1260
	SI_E1AP_DT_Transport_UP_Layer_Addresses_Info_To_Add_Item * objTransport_UP_Layer_Addresses_Info_To_Add_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__Transport_UP_Layer_Addresses_Info_To_Add_Item( &objTransport_UP_Layer_Addresses_Info_To_Add_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_Transport_UP_Layer_Addresses_Info_To_Add_List->Transport_UP_Layer_Addresses_Info_To_Add_Item, (uint8_t*)objTransport_UP_Layer_Addresses_Info_To_Add_Item);

	*pTransport_UP_Layer_Addresses_Info_To_Add_List = obj_Transport_UP_Layer_Addresses_Info_To_Add_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__Transport_UP_Layer_Addresses_Info_To_Add_Item( SI_E1AP_DT_Transport_UP_Layer_Addresses_Info_To_Add_Item ** pTransport_UP_Layer_Addresses_Info_To_Add_Item)
{
	SI_E1AP_DT_Transport_UP_Layer_Addresses_Info_To_Add_Item * obj_Transport_UP_Layer_Addresses_Info_To_Add_Item = (SI_E1AP_DT_Transport_UP_Layer_Addresses_Info_To_Add_Item*) __si_allocM( sizeof(SI_E1AP_DT_Transport_UP_Layer_Addresses_Info_To_Add_Item));
	memset( obj_Transport_UP_Layer_Addresses_Info_To_Add_Item, 0, sizeof( SI_E1AP_DT_Transport_UP_Layer_Addresses_Info_To_Add_Item));

	// L:486
	__si_e1ap_init_TransportLayerAddress2( &obj_Transport_UP_Layer_Addresses_Info_To_Add_Item->iP_SecTransportLayerAddress, "0", 1, 1);  // L:574
	obj_Transport_UP_Layer_Addresses_Info_To_Add_Item->iP_SecTransportLayerAddress->bitslen = 1; //   L:575

	__si_e1ap__set_testdata__GTPTLAs( &obj_Transport_UP_Layer_Addresses_Info_To_Add_Item->gTPTransportLayerAddressesToAdd);    // L:580
	obj_Transport_UP_Layer_Addresses_Info_To_Add_Item->isPresent_gTPTransportLayerAddressesToAdd = 1;


	*pTransport_UP_Layer_Addresses_Info_To_Add_Item = obj_Transport_UP_Layer_Addresses_Info_To_Add_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__Transport_UP_Layer_Addresses_Info_To_Remove_List( SI_E1AP_DT_Transport_UP_Layer_Addresses_Info_To_Remove_List ** pTransport_UP_Layer_Addresses_Info_To_Remove_List)
{
	SI_E1AP_DT_Transport_UP_Layer_Addresses_Info_To_Remove_List * obj_Transport_UP_Layer_Addresses_Info_To_Remove_List = NULL; 
	__si_e1ap_init_Transport_UP_Layer_Addresses_Info_To_Remove_List( &obj_Transport_UP_Layer_Addresses_Info_To_Remove_List);

	// L:1260
	SI_E1AP_DT_Transport_UP_Layer_Addresses_Info_To_Remove_Item * objTransport_UP_Layer_Addresses_Info_To_Remove_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__Transport_UP_Layer_Addresses_Info_To_Remove_Item( &objTransport_UP_Layer_Addresses_Info_To_Remove_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_Transport_UP_Layer_Addresses_Info_To_Remove_List->Transport_UP_Layer_Addresses_Info_To_Remove_Item, (uint8_t*)objTransport_UP_Layer_Addresses_Info_To_Remove_Item);

	*pTransport_UP_Layer_Addresses_Info_To_Remove_List = obj_Transport_UP_Layer_Addresses_Info_To_Remove_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__Transport_UP_Layer_Addresses_Info_To_Remove_Item( SI_E1AP_DT_Transport_UP_Layer_Addresses_Info_To_Remove_Item ** pTransport_UP_Layer_Addresses_Info_To_Remove_Item)
{
	SI_E1AP_DT_Transport_UP_Layer_Addresses_Info_To_Remove_Item * obj_Transport_UP_Layer_Addresses_Info_To_Remove_Item = (SI_E1AP_DT_Transport_UP_Layer_Addresses_Info_To_Remove_Item*) __si_allocM( sizeof(SI_E1AP_DT_Transport_UP_Layer_Addresses_Info_To_Remove_Item));
	memset( obj_Transport_UP_Layer_Addresses_Info_To_Remove_Item, 0, sizeof( SI_E1AP_DT_Transport_UP_Layer_Addresses_Info_To_Remove_Item));

	// L:486
	__si_e1ap_init_TransportLayerAddress2( &obj_Transport_UP_Layer_Addresses_Info_To_Remove_Item->iP_SecTransportLayerAddress, "9", 1, 1);  // L:574
	obj_Transport_UP_Layer_Addresses_Info_To_Remove_Item->iP_SecTransportLayerAddress->bitslen = 1; //   L:575

	__si_e1ap__set_testdata__GTPTLAs( &obj_Transport_UP_Layer_Addresses_Info_To_Remove_Item->gTPTransportLayerAddressesToRemove);    // L:580
	obj_Transport_UP_Layer_Addresses_Info_To_Remove_Item->isPresent_gTPTransportLayerAddressesToRemove = 1;


	*pTransport_UP_Layer_Addresses_Info_To_Remove_Item = obj_Transport_UP_Layer_Addresses_Info_To_Remove_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__UDC_Parameters( SI_E1AP_DT_UDC_Parameters ** pUDC_Parameters)
{
	SI_E1AP_DT_UDC_Parameters * obj_UDC_Parameters = (SI_E1AP_DT_UDC_Parameters*) __si_allocM( sizeof(SI_E1AP_DT_UDC_Parameters));
	memset( obj_UDC_Parameters, 0, sizeof( SI_E1AP_DT_UDC_Parameters));

	// L:486
	obj_UDC_Parameters->selected_ebufferSize = BufferSize_kbyte2_val;   // L:529

	obj_UDC_Parameters->selected_edictionary = Dictionary_sip_SDP_val;   // L:529
	obj_UDC_Parameters->isPresent_dictionary = 1;

	obj_UDC_Parameters->selected_econtinueUDC = UDCParameters_continueUDC_true_val;   // L:529
	obj_UDC_Parameters->isPresent_continueUDC = 1;


	*pUDC_Parameters = obj_UDC_Parameters;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__UE_associatedLogicalE1_ConnectionItem( SI_E1AP_DT_UE_associatedLogicalE1_ConnectionItem ** pUE_associatedLogicalE1_ConnectionItem)
{
	SI_E1AP_DT_UE_associatedLogicalE1_ConnectionItem * obj_UE_associatedLogicalE1_ConnectionItem = (SI_E1AP_DT_UE_associatedLogicalE1_ConnectionItem*) __si_allocM( sizeof(SI_E1AP_DT_UE_associatedLogicalE1_ConnectionItem));
	memset( obj_UE_associatedLogicalE1_ConnectionItem, 0, sizeof( SI_E1AP_DT_UE_associatedLogicalE1_ConnectionItem));

	// L:486
	obj_UE_associatedLogicalE1_ConnectionItem->gNB_CU_CP_UE_E1AP_ID = __getTestINTEGER( 0, 4294967295);    // L:533
	obj_UE_associatedLogicalE1_ConnectionItem->isPresent_gNB_CU_CP_UE_E1AP_ID = 1;

	obj_UE_associatedLogicalE1_ConnectionItem->gNB_CU_UP_UE_E1AP_ID = __getTestINTEGER( 0, 4294967295);    // L:533
	obj_UE_associatedLogicalE1_ConnectionItem->isPresent_gNB_CU_UP_UE_E1AP_ID = 1;


	*pUE_associatedLogicalE1_ConnectionItem = obj_UE_associatedLogicalE1_ConnectionItem;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__UESliceMaximumBitRateList( SI_E1AP_DT_UESliceMaximumBitRateList ** pUESliceMaximumBitRateList)
{
	SI_E1AP_DT_UESliceMaximumBitRateList * obj_UESliceMaximumBitRateList = NULL; 
	__si_e1ap_init_UESliceMaximumBitRateList( &obj_UESliceMaximumBitRateList);

	// L:1260
	SI_E1AP_DT_UESliceMaximumBitRateItem * objUESliceMaximumBitRateItem = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__UESliceMaximumBitRateItem( &objUESliceMaximumBitRateItem);  // L:1395

	// L:1419
	__si_linked_list_add( obj_UESliceMaximumBitRateList->UESliceMaximumBitRateItem, (uint8_t*)objUESliceMaximumBitRateItem);

	*pUESliceMaximumBitRateList = obj_UESliceMaximumBitRateList;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__UESliceMaximumBitRateItem( SI_E1AP_DT_UESliceMaximumBitRateItem ** pUESliceMaximumBitRateItem)
{
	SI_E1AP_DT_UESliceMaximumBitRateItem * obj_UESliceMaximumBitRateItem = (SI_E1AP_DT_UESliceMaximumBitRateItem*) __si_allocM( sizeof(SI_E1AP_DT_UESliceMaximumBitRateItem));
	memset( obj_UESliceMaximumBitRateItem, 0, sizeof( SI_E1AP_DT_UESliceMaximumBitRateItem));

	// L:486
	__si_e1ap__set_testdata__SNSSAI( &obj_UESliceMaximumBitRateItem->sNSSAI);    // L:584

	obj_UESliceMaximumBitRateItem->uESliceMaximumBitRateDL = __getTestINTEGER( 0, 4000000000000);    // L:533


	*pUESliceMaximumBitRateItem = obj_UESliceMaximumBitRateItem;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__ULUPTNLAddressToUpdateItem( SI_E1AP_DT_ULUPTNLAddressToUpdateItem ** pULUPTNLAddressToUpdateItem)
{
	SI_E1AP_DT_ULUPTNLAddressToUpdateItem * obj_ULUPTNLAddressToUpdateItem = (SI_E1AP_DT_ULUPTNLAddressToUpdateItem*) __si_allocM( sizeof(SI_E1AP_DT_ULUPTNLAddressToUpdateItem));
	memset( obj_ULUPTNLAddressToUpdateItem, 0, sizeof( SI_E1AP_DT_ULUPTNLAddressToUpdateItem));

	// L:486
	__si_e1ap_init_TransportLayerAddress2( &obj_ULUPTNLAddressToUpdateItem->oldTNLAdress, "6", 1, 1);  // L:574
	obj_ULUPTNLAddressToUpdateItem->oldTNLAdress->bitslen = 1; //   L:575

	__si_e1ap_init_TransportLayerAddress2( &obj_ULUPTNLAddressToUpdateItem->newTNLAdress, "0", 1, 1);  // L:574
	obj_ULUPTNLAddressToUpdateItem->newTNLAdress->bitslen = 1; //   L:575


	*pULUPTNLAddressToUpdateItem = obj_ULUPTNLAddressToUpdateItem;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__UP_Parameters( SI_E1AP_DT_UP_Parameters ** pUP_Parameters)
{
	SI_E1AP_DT_UP_Parameters * obj_UP_Parameters = NULL; 
	__si_e1ap_init_UP_Parameters( &obj_UP_Parameters);

	// L:1260
	SI_E1AP_DT_UP_Parameters_Item * objUP_Parameters_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__UP_Parameters_Item( &objUP_Parameters_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_UP_Parameters->UP_Parameters_Item, (uint8_t*)objUP_Parameters_Item);

	*pUP_Parameters = obj_UP_Parameters;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__UP_Parameters_Item( SI_E1AP_DT_UP_Parameters_Item ** pUP_Parameters_Item)
{
	SI_E1AP_DT_UP_Parameters_Item * obj_UP_Parameters_Item = (SI_E1AP_DT_UP_Parameters_Item*) __si_allocM( sizeof(SI_E1AP_DT_UP_Parameters_Item));
	memset( obj_UP_Parameters_Item, 0, sizeof( SI_E1AP_DT_UP_Parameters_Item));

	// L:486
	__si_e1ap__set_testdata__UP_TNL_Information( &obj_UP_Parameters_Item->uP_TNL_Information);    // L:588

	obj_UP_Parameters_Item->cell_Group_ID = __getTestINTEGER( 0, 3);    // L:533


	*pUP_Parameters_Item = obj_UP_Parameters_Item;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__UPSecuritykey( SI_E1AP_DT_UPSecuritykey ** pUPSecuritykey)
{
	SI_E1AP_DT_UPSecuritykey * obj_UPSecuritykey = (SI_E1AP_DT_UPSecuritykey*) __si_allocM( sizeof(SI_E1AP_DT_UPSecuritykey));
	memset( obj_UPSecuritykey, 0, sizeof( SI_E1AP_DT_UPSecuritykey));

	// L:486
	__si_e1ap_init_EncryptionKey2( &obj_UPSecuritykey->encryptionKey, "\x06\x05\x20\x20\x12", 5);    // L:540

	__si_e1ap_init_IntegrityProtectionKey2( &obj_UPSecuritykey->integrityProtectionKey, "\x22\x13\x21\x08\x09", 5);    // L:540
	obj_UPSecuritykey->isPresent_integrityProtectionKey = 1;


	*pUPSecuritykey = obj_UPSecuritykey;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__UP_TNL_Information( SI_E1AP_DT_UP_TNL_Information ** pUP_TNL_Information)
{
	SI_E1AP_DT_UP_TNL_Information * obj_UP_TNL_Information = (SI_E1AP_DT_UP_TNL_Information*) __si_allocM( sizeof(SI_E1AP_DT_UP_TNL_Information));
	memset( obj_UP_TNL_Information, 0, sizeof( SI_E1AP_DT_UP_TNL_Information));

	obj_UP_TNL_Information->SelectedChoice = 0;

	// L:2784

	switch( obj_UP_TNL_Information->SelectedChoice)
	{
		case 0:
			__si_e1ap__set_testdata__GTPTunnel( &obj_UP_TNL_Information->u.gTPTunnel);  // L:2910  ,  Parser:SEQUENCE, GTPTunnel
			break;
		case 1:
			__si_e1ap__set_testdata__PDU_UP_TNL_Information_ExtIEs( &obj_UP_TNL_Information->u.choice_extension);    // L:2871
			break;
	}

	*pUP_TNL_Information = obj_UP_TNL_Information;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__UplinkOnlyROHC( SI_E1AP_DT_UplinkOnlyROHC ** pUplinkOnlyROHC)
{
	SI_E1AP_DT_UplinkOnlyROHC * obj_UplinkOnlyROHC = (SI_E1AP_DT_UplinkOnlyROHC*) __si_allocM( sizeof(SI_E1AP_DT_UplinkOnlyROHC));
	memset( obj_UplinkOnlyROHC, 0, sizeof( SI_E1AP_DT_UplinkOnlyROHC));

	// L:486
	obj_UplinkOnlyROHC->maxCID = __getTestINTEGER( 0, 16383);    // L:533

	obj_UplinkOnlyROHC->rOHC_Profiles = __getTestINTEGER( 0, 511);    // L:533

	obj_UplinkOnlyROHC->selected_econtinueROHC = UplinkOnlyROHC_continueROHC_true_val;   // L:529
	obj_UplinkOnlyROHC->isPresent_continueROHC = 1;


	*pUplinkOnlyROHC = obj_UplinkOnlyROHC;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__UserPlaneFailureIndication( SI_E1AP_DT_UserPlaneFailureIndication ** pUserPlaneFailureIndication)
{
	SI_E1AP_DT_UserPlaneFailureIndication * obj_UserPlaneFailureIndication = (SI_E1AP_DT_UserPlaneFailureIndication*) __si_allocM( sizeof(SI_E1AP_DT_UserPlaneFailureIndication));
	memset( obj_UserPlaneFailureIndication, 0, sizeof( SI_E1AP_DT_UserPlaneFailureIndication));

	// L:486
	obj_UserPlaneFailureIndication->selected_euserPlaneFailureType = UserPlaneFailureType_gtp_u_error_indication_received_val;   // L:529

	__si_e1ap__set_testdata__UP_TNL_Information( &obj_UserPlaneFailureIndication->nG_DL_UP_TNL_Information);    // L:588

	__si_e1ap__set_testdata__UP_TNL_Information( &obj_UserPlaneFailureIndication->nG_UL_UP_TNL_Information);    // L:588


	*pUserPlaneFailureIndication = obj_UserPlaneFailureIndication;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__ResetType( SI_E1AP_DT_ResetType ** pResetType)
{
	SI_E1AP_DT_ResetType * obj_ResetType = (SI_E1AP_DT_ResetType*) __si_allocM( sizeof(SI_E1AP_DT_ResetType));
	memset( obj_ResetType, 0, sizeof( SI_E1AP_DT_ResetType));

	obj_ResetType->SelectedChoice = 0;

	// L:2784

	switch( obj_ResetType->SelectedChoice)
	{
		case 0:
			obj_ResetType->u.e1_Interface = ResetAll_reset_all_val;  // TODO: set enum   L:2894  ,  Parser:ENUMERATED, ResetAll
			break;
		case 1:
			__si_e1ap__set_testdata__UE_associatedLogicalE1_ConnectionListRes( &obj_ResetType->u.partOfE1_Interface);  // L:2910  ,  Parser:SEQUENCE_OF, UE-associatedLogicalE1-ConnectionListRes
			break;
		case 2:
			__si_e1ap__set_testdata__PDU_ResetType_ExtIEs( &obj_ResetType->u.choice_extension);    // L:2871
			break;
	}

	*pResetType = obj_ResetType;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__System_BearerContextSetupRequest( SI_E1AP_DT_System_BearerContextSetupRequest ** pSystem_BearerContextSetupRequest)
{
	SI_E1AP_DT_System_BearerContextSetupRequest * obj_System_BearerContextSetupRequest = (SI_E1AP_DT_System_BearerContextSetupRequest*) __si_allocM( sizeof(SI_E1AP_DT_System_BearerContextSetupRequest));
	memset( obj_System_BearerContextSetupRequest, 0, sizeof( SI_E1AP_DT_System_BearerContextSetupRequest));

	obj_System_BearerContextSetupRequest->SelectedChoice = 0;

	// L:2784

	switch( obj_System_BearerContextSetupRequest->SelectedChoice)
	{
		case 0:
			//e-utran-bearercontextsetuprequest  - EUTRAN-BearerContextSetupRequest
			__si_e1ap__set_testdata__PDU_EUTRAN_BearerContextSetupRequest( &obj_System_BearerContextSetupRequest->u.e_UTRAN_BearerContextSetupRequest);  // L:2876
			break;
		case 1:
			//ng-ran-bearercontextsetuprequest  - NG-RAN-BearerContextSetupRequest
			__si_e1ap__set_testdata__PDU_NG_RAN_BearerContextSetupRequest( &obj_System_BearerContextSetupRequest->u.nG_RAN_BearerContextSetupRequest);  // L:2876
			break;
		case 2:
			__si_e1ap__set_testdata__PDU_System_BearerContextSetupRequest_ExtIEs( &obj_System_BearerContextSetupRequest->u.choice_extension);    // L:2871
			break;
	}

	*pSystem_BearerContextSetupRequest = obj_System_BearerContextSetupRequest;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__System_BearerContextSetupResponse( SI_E1AP_DT_System_BearerContextSetupResponse ** pSystem_BearerContextSetupResponse)
{
	SI_E1AP_DT_System_BearerContextSetupResponse * obj_System_BearerContextSetupResponse = (SI_E1AP_DT_System_BearerContextSetupResponse*) __si_allocM( sizeof(SI_E1AP_DT_System_BearerContextSetupResponse));
	memset( obj_System_BearerContextSetupResponse, 0, sizeof( SI_E1AP_DT_System_BearerContextSetupResponse));

	obj_System_BearerContextSetupResponse->SelectedChoice = 0;

	// L:2784

	switch( obj_System_BearerContextSetupResponse->SelectedChoice)
	{
		case 0:
			//e-utran-bearercontextsetupresponse  - EUTRAN-BearerContextSetupResponse
			__si_e1ap__set_testdata__PDU_EUTRAN_BearerContextSetupResponse( &obj_System_BearerContextSetupResponse->u.e_UTRAN_BearerContextSetupResponse);  // L:2876
			break;
		case 1:
			//ng-ran-bearercontextsetupresponse  - NG-RAN-BearerContextSetupResponse
			__si_e1ap__set_testdata__PDU_NG_RAN_BearerContextSetupResponse( &obj_System_BearerContextSetupResponse->u.nG_RAN_BearerContextSetupResponse);  // L:2876
			break;
		case 2:
			__si_e1ap__set_testdata__PDU_System_BearerContextSetupResponse_ExtIEs( &obj_System_BearerContextSetupResponse->u.choice_extension);    // L:2871
			break;
	}

	*pSystem_BearerContextSetupResponse = obj_System_BearerContextSetupResponse;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__System_BearerContextModificationRequest( SI_E1AP_DT_System_BearerContextModificationRequest ** pSystem_BearerContextModificationRequest)
{
	SI_E1AP_DT_System_BearerContextModificationRequest * obj_System_BearerContextModificationRequest = (SI_E1AP_DT_System_BearerContextModificationRequest*) __si_allocM( sizeof(SI_E1AP_DT_System_BearerContextModificationRequest));
	memset( obj_System_BearerContextModificationRequest, 0, sizeof( SI_E1AP_DT_System_BearerContextModificationRequest));

	obj_System_BearerContextModificationRequest->SelectedChoice = 0;

	// L:2784

	switch( obj_System_BearerContextModificationRequest->SelectedChoice)
	{
		case 0:
			//e-utran-bearercontextmodificationrequest  - EUTRAN-BearerContextModificationRequest
			__si_e1ap__set_testdata__PDU_EUTRAN_BearerContextModificationRequest( &obj_System_BearerContextModificationRequest->u.e_UTRAN_BearerContextModificationRequest);  // L:2876
			break;
		case 1:
			//ng-ran-bearercontextmodificationrequest  - NG-RAN-BearerContextModificationRequest
			__si_e1ap__set_testdata__PDU_NG_RAN_BearerContextModificationRequest( &obj_System_BearerContextModificationRequest->u.nG_RAN_BearerContextModificationRequest);  // L:2876
			break;
		case 2:
			__si_e1ap__set_testdata__PDU_System_BearerContextModificationRequest_ExtIEs( &obj_System_BearerContextModificationRequest->u.choice_extension);    // L:2871
			break;
	}

	*pSystem_BearerContextModificationRequest = obj_System_BearerContextModificationRequest;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__System_BearerContextModificationResponse( SI_E1AP_DT_System_BearerContextModificationResponse ** pSystem_BearerContextModificationResponse)
{
	SI_E1AP_DT_System_BearerContextModificationResponse * obj_System_BearerContextModificationResponse = (SI_E1AP_DT_System_BearerContextModificationResponse*) __si_allocM( sizeof(SI_E1AP_DT_System_BearerContextModificationResponse));
	memset( obj_System_BearerContextModificationResponse, 0, sizeof( SI_E1AP_DT_System_BearerContextModificationResponse));

	obj_System_BearerContextModificationResponse->SelectedChoice = 0;

	// L:2784

	switch( obj_System_BearerContextModificationResponse->SelectedChoice)
	{
		case 0:
			//e-utran-bearercontextmodificationresponse  - EUTRAN-BearerContextModificationResponse
			__si_e1ap__set_testdata__PDU_EUTRAN_BearerContextModificationResponse( &obj_System_BearerContextModificationResponse->u.e_UTRAN_BearerContextModificationResponse);  // L:2876
			break;
		case 1:
			//ng-ran-bearercontextmodificationresponse  - NG-RAN-BearerContextModificationResponse
			__si_e1ap__set_testdata__PDU_NG_RAN_BearerContextModificationResponse( &obj_System_BearerContextModificationResponse->u.nG_RAN_BearerContextModificationResponse);  // L:2876
			break;
		case 2:
			__si_e1ap__set_testdata__PDU_System_BearerContextModificationResponse_ExtIEs( &obj_System_BearerContextModificationResponse->u.choice_extension);    // L:2871
			break;
	}

	*pSystem_BearerContextModificationResponse = obj_System_BearerContextModificationResponse;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__System_BearerContextModificationRequired( SI_E1AP_DT_System_BearerContextModificationRequired ** pSystem_BearerContextModificationRequired)
{
	SI_E1AP_DT_System_BearerContextModificationRequired * obj_System_BearerContextModificationRequired = (SI_E1AP_DT_System_BearerContextModificationRequired*) __si_allocM( sizeof(SI_E1AP_DT_System_BearerContextModificationRequired));
	memset( obj_System_BearerContextModificationRequired, 0, sizeof( SI_E1AP_DT_System_BearerContextModificationRequired));

	obj_System_BearerContextModificationRequired->SelectedChoice = 0;

	// L:2784

	switch( obj_System_BearerContextModificationRequired->SelectedChoice)
	{
		case 0:
			//e-utran-bearercontextmodificationrequired  - EUTRAN-BearerContextModificationRequired
			__si_e1ap__set_testdata__PDU_EUTRAN_BearerContextModificationRequired( &obj_System_BearerContextModificationRequired->u.e_UTRAN_BearerContextModificationRequired);  // L:2876
			break;
		case 1:
			//ng-ran-bearercontextmodificationrequired  - NG-RAN-BearerContextModificationRequired
			__si_e1ap__set_testdata__PDU_NG_RAN_BearerContextModificationRequired( &obj_System_BearerContextModificationRequired->u.nG_RAN_BearerContextModificationRequired);  // L:2876
			break;
		case 2:
			__si_e1ap__set_testdata__PDU_System_BearerContextModificationRequired_ExtIEs( &obj_System_BearerContextModificationRequired->u.choice_extension);    // L:2871
			break;
	}

	*pSystem_BearerContextModificationRequired = obj_System_BearerContextModificationRequired;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__System_BearerContextModificationConfirm( SI_E1AP_DT_System_BearerContextModificationConfirm ** pSystem_BearerContextModificationConfirm)
{
	SI_E1AP_DT_System_BearerContextModificationConfirm * obj_System_BearerContextModificationConfirm = (SI_E1AP_DT_System_BearerContextModificationConfirm*) __si_allocM( sizeof(SI_E1AP_DT_System_BearerContextModificationConfirm));
	memset( obj_System_BearerContextModificationConfirm, 0, sizeof( SI_E1AP_DT_System_BearerContextModificationConfirm));

	obj_System_BearerContextModificationConfirm->SelectedChoice = 0;

	// L:2784

	switch( obj_System_BearerContextModificationConfirm->SelectedChoice)
	{
		case 0:
			//e-utran-bearercontextmodificationconfirm  - EUTRAN-BearerContextModificationConfirm
			__si_e1ap__set_testdata__PDU_EUTRAN_BearerContextModificationConfirm( &obj_System_BearerContextModificationConfirm->u.e_UTRAN_BearerContextModificationConfirm);  // L:2876
			break;
		case 1:
			//ng-ran-bearercontextmodificationconfirm  - NG-RAN-BearerContextModificationConfirm
			__si_e1ap__set_testdata__PDU_NG_RAN_BearerContextModificationConfirm( &obj_System_BearerContextModificationConfirm->u.nG_RAN_BearerContextModificationConfirm);  // L:2876
			break;
		case 2:
			__si_e1ap__set_testdata__PDU_System_BearerContextModificationConfirm_ExtIEs( &obj_System_BearerContextModificationConfirm->u.choice_extension);    // L:2871
			break;
	}

	*pSystem_BearerContextModificationConfirm = obj_System_BearerContextModificationConfirm;
}


// CHOICE  L:11113
void __si_e1ap__set_testdata__System_GNB_CU_UP_CounterCheckRequest( SI_E1AP_DT_System_GNB_CU_UP_CounterCheckRequest ** pSystem_GNB_CU_UP_CounterCheckRequest)
{
	SI_E1AP_DT_System_GNB_CU_UP_CounterCheckRequest * obj_System_GNB_CU_UP_CounterCheckRequest = (SI_E1AP_DT_System_GNB_CU_UP_CounterCheckRequest*) __si_allocM( sizeof(SI_E1AP_DT_System_GNB_CU_UP_CounterCheckRequest));
	memset( obj_System_GNB_CU_UP_CounterCheckRequest, 0, sizeof( SI_E1AP_DT_System_GNB_CU_UP_CounterCheckRequest));

	obj_System_GNB_CU_UP_CounterCheckRequest->SelectedChoice = 0;

	// L:2784

	switch( obj_System_GNB_CU_UP_CounterCheckRequest->SelectedChoice)
	{
		case 0:
			//e-utran-gnb-cu-up-countercheckrequest  - EUTRAN-GNB-CU-UP-CounterCheckRequest
			__si_e1ap__set_testdata__PDU_EUTRAN_GNB_CU_UP_CounterCheckRequest( &obj_System_GNB_CU_UP_CounterCheckRequest->u.e_UTRAN_GNB_CU_UP_CounterCheckRequest);  // L:2876
			break;
		case 1:
			//ng-ran-gnb-cu-up-countercheckrequest  - NG-RAN-GNB-CU-UP-CounterCheckRequest
			__si_e1ap__set_testdata__PDU_NG_RAN_GNB_CU_UP_CounterCheckRequest( &obj_System_GNB_CU_UP_CounterCheckRequest->u.nG_RAN_GNB_CU_UP_CounterCheckRequest);  // L:2876
			break;
		case 2:
			__si_e1ap__set_testdata__PDU_System_GNB_CU_UP_CounterCheckRequest_ExtIEs( &obj_System_GNB_CU_UP_CounterCheckRequest->u.choice_extension);    // L:2871
			break;
	}

	*pSystem_GNB_CU_UP_CounterCheckRequest = obj_System_GNB_CU_UP_CounterCheckRequest;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__UE_associatedLogicalE1_ConnectionListRes( SI_E1AP_DT_UE_associatedLogicalE1_ConnectionListRes ** pUE_associatedLogicalE1_ConnectionListRes)
{
	SI_E1AP_DT_UE_associatedLogicalE1_ConnectionListRes * obj_UE_associatedLogicalE1_ConnectionListRes = NULL; 
	__si_e1ap_init_UE_associatedLogicalE1_ConnectionListRes( &obj_UE_associatedLogicalE1_ConnectionListRes);

	// L:1260
	SI_E1AP_DT_PDU_UE_associatedLogicalE1_ConnectionItemRes * objUE_associatedLogicalE1_ConnectionItemRes = NULL;
	__si_e1ap__set_testdata__PDU_UE_associatedLogicalE1_ConnectionItemRes( &objUE_associatedLogicalE1_ConnectionItemRes);
	// L:1419
	__si_linked_list_add( obj_UE_associatedLogicalE1_ConnectionListRes->UE_associatedLogicalE1_ConnectionItemRes, (uint8_t*)objUE_associatedLogicalE1_ConnectionItemRes);

	*pUE_associatedLogicalE1_ConnectionListRes = obj_UE_associatedLogicalE1_ConnectionListRes;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__UE_associatedLogicalE1_ConnectionListResAck( SI_E1AP_DT_UE_associatedLogicalE1_ConnectionListResAck ** pUE_associatedLogicalE1_ConnectionListResAck)
{
	SI_E1AP_DT_UE_associatedLogicalE1_ConnectionListResAck * obj_UE_associatedLogicalE1_ConnectionListResAck = NULL; 
	__si_e1ap_init_UE_associatedLogicalE1_ConnectionListResAck( &obj_UE_associatedLogicalE1_ConnectionListResAck);

	// L:1260
	SI_E1AP_DT_PDU_UE_associatedLogicalE1_ConnectionItemResAck * objUE_associatedLogicalE1_ConnectionItemResAck = NULL;
	__si_e1ap__set_testdata__PDU_UE_associatedLogicalE1_ConnectionItemResAck( &objUE_associatedLogicalE1_ConnectionItemResAck);
	// L:1419
	__si_linked_list_add( obj_UE_associatedLogicalE1_ConnectionListResAck->UE_associatedLogicalE1_ConnectionItemResAck, (uint8_t*)objUE_associatedLogicalE1_ConnectionItemResAck);

	*pUE_associatedLogicalE1_ConnectionListResAck = obj_UE_associatedLogicalE1_ConnectionListResAck;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__SupportedPLMNs_List( SI_E1AP_DT_SupportedPLMNs_List ** pSupportedPLMNs_List)
{
	SI_E1AP_DT_SupportedPLMNs_List * obj_SupportedPLMNs_List = NULL; 
	__si_e1ap_init_SupportedPLMNs_List( &obj_SupportedPLMNs_List);

	// L:1260
	SI_E1AP_DT_SupportedPLMNs_Item * objSupportedPLMNs_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__SupportedPLMNs_Item( &objSupportedPLMNs_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_SupportedPLMNs_List->SupportedPLMNs_Item, (uint8_t*)objSupportedPLMNs_Item);

	*pSupportedPLMNs_List = obj_SupportedPLMNs_List;
}


// SEQUENCE  L:11113
void __si_e1ap__set_testdata__SupportedPLMNs_Item( SI_E1AP_DT_SupportedPLMNs_Item ** pSupportedPLMNs_Item)
{
	SI_E1AP_DT_SupportedPLMNs_Item * obj_SupportedPLMNs_Item = (SI_E1AP_DT_SupportedPLMNs_Item*) __si_allocM( sizeof(SI_E1AP_DT_SupportedPLMNs_Item));
	memset( obj_SupportedPLMNs_Item, 0, sizeof( SI_E1AP_DT_SupportedPLMNs_Item));

	// L:486
	__si_e1ap_init_PLMN_Identity2( &obj_SupportedPLMNs_Item->pLMN_Identity, "\x16\x05\x09", 3);    // L:545

	__si_e1ap__set_testdata__Slice_Support_List( &obj_SupportedPLMNs_Item->slice_Support_List);    // L:580
	obj_SupportedPLMNs_Item->isPresent_slice_Support_List = 1;

	__si_e1ap__set_testdata__NR_CGI_Support_List( &obj_SupportedPLMNs_Item->nR_CGI_Support_List);    // L:580
	obj_SupportedPLMNs_Item->isPresent_nR_CGI_Support_List = 1;

	__si_e1ap__set_testdata__QoS_Parameters_Support_List( &obj_SupportedPLMNs_Item->qoS_Parameters_Support_List);    // L:584
	obj_SupportedPLMNs_Item->isPresent_qoS_Parameters_Support_List = 1;


	*pSupportedPLMNs_Item = obj_SupportedPLMNs_Item;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__GNB_CU_UP_TNLA_To_Remove_List( SI_E1AP_DT_GNB_CU_UP_TNLA_To_Remove_List ** pGNB_CU_UP_TNLA_To_Remove_List)
{
	SI_E1AP_DT_GNB_CU_UP_TNLA_To_Remove_List * obj_GNB_CU_UP_TNLA_To_Remove_List = NULL; 
	__si_e1ap_init_GNB_CU_UP_TNLA_To_Remove_List( &obj_GNB_CU_UP_TNLA_To_Remove_List);

	// L:1260
	SI_E1AP_DT_GNB_CU_UP_TNLA_To_Remove_Item * objGNB_CU_UP_TNLA_To_Remove_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__GNB_CU_UP_TNLA_To_Remove_Item( &objGNB_CU_UP_TNLA_To_Remove_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_GNB_CU_UP_TNLA_To_Remove_List->GNB_CU_UP_TNLA_To_Remove_Item, (uint8_t*)objGNB_CU_UP_TNLA_To_Remove_Item);

	*pGNB_CU_UP_TNLA_To_Remove_List = obj_GNB_CU_UP_TNLA_To_Remove_List;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__GNB_CU_CP_TNLA_To_Add_List( SI_E1AP_DT_GNB_CU_CP_TNLA_To_Add_List ** pGNB_CU_CP_TNLA_To_Add_List)
{
	SI_E1AP_DT_GNB_CU_CP_TNLA_To_Add_List * obj_GNB_CU_CP_TNLA_To_Add_List = NULL; 
	__si_e1ap_init_GNB_CU_CP_TNLA_To_Add_List( &obj_GNB_CU_CP_TNLA_To_Add_List);

	// L:1260
	SI_E1AP_DT_GNB_CU_CP_TNLA_To_Add_Item * objGNB_CU_CP_TNLA_To_Add_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__GNB_CU_CP_TNLA_To_Add_Item( &objGNB_CU_CP_TNLA_To_Add_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_GNB_CU_CP_TNLA_To_Add_List->GNB_CU_CP_TNLA_To_Add_Item, (uint8_t*)objGNB_CU_CP_TNLA_To_Add_Item);

	*pGNB_CU_CP_TNLA_To_Add_List = obj_GNB_CU_CP_TNLA_To_Add_List;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__GNB_CU_CP_TNLA_To_Remove_List( SI_E1AP_DT_GNB_CU_CP_TNLA_To_Remove_List ** pGNB_CU_CP_TNLA_To_Remove_List)
{
	SI_E1AP_DT_GNB_CU_CP_TNLA_To_Remove_List * obj_GNB_CU_CP_TNLA_To_Remove_List = NULL; 
	__si_e1ap_init_GNB_CU_CP_TNLA_To_Remove_List( &obj_GNB_CU_CP_TNLA_To_Remove_List);

	// L:1260
	SI_E1AP_DT_GNB_CU_CP_TNLA_To_Remove_Item * objGNB_CU_CP_TNLA_To_Remove_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__GNB_CU_CP_TNLA_To_Remove_Item( &objGNB_CU_CP_TNLA_To_Remove_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_GNB_CU_CP_TNLA_To_Remove_List->GNB_CU_CP_TNLA_To_Remove_Item, (uint8_t*)objGNB_CU_CP_TNLA_To_Remove_Item);

	*pGNB_CU_CP_TNLA_To_Remove_List = obj_GNB_CU_CP_TNLA_To_Remove_List;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__GNB_CU_CP_TNLA_To_Update_List( SI_E1AP_DT_GNB_CU_CP_TNLA_To_Update_List ** pGNB_CU_CP_TNLA_To_Update_List)
{
	SI_E1AP_DT_GNB_CU_CP_TNLA_To_Update_List * obj_GNB_CU_CP_TNLA_To_Update_List = NULL; 
	__si_e1ap_init_GNB_CU_CP_TNLA_To_Update_List( &obj_GNB_CU_CP_TNLA_To_Update_List);

	// L:1260
	SI_E1AP_DT_GNB_CU_CP_TNLA_To_Update_Item * objGNB_CU_CP_TNLA_To_Update_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__GNB_CU_CP_TNLA_To_Update_Item( &objGNB_CU_CP_TNLA_To_Update_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_GNB_CU_CP_TNLA_To_Update_List->GNB_CU_CP_TNLA_To_Update_Item, (uint8_t*)objGNB_CU_CP_TNLA_To_Update_Item);

	*pGNB_CU_CP_TNLA_To_Update_List = obj_GNB_CU_CP_TNLA_To_Update_List;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__GNB_CU_CP_TNLA_Setup_List( SI_E1AP_DT_GNB_CU_CP_TNLA_Setup_List ** pGNB_CU_CP_TNLA_Setup_List)
{
	SI_E1AP_DT_GNB_CU_CP_TNLA_Setup_List * obj_GNB_CU_CP_TNLA_Setup_List = NULL; 
	__si_e1ap_init_GNB_CU_CP_TNLA_Setup_List( &obj_GNB_CU_CP_TNLA_Setup_List);

	// L:1260
	SI_E1AP_DT_GNB_CU_CP_TNLA_Setup_Item * objGNB_CU_CP_TNLA_Setup_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__GNB_CU_CP_TNLA_Setup_Item( &objGNB_CU_CP_TNLA_Setup_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_GNB_CU_CP_TNLA_Setup_List->GNB_CU_CP_TNLA_Setup_Item, (uint8_t*)objGNB_CU_CP_TNLA_Setup_Item);

	*pGNB_CU_CP_TNLA_Setup_List = obj_GNB_CU_CP_TNLA_Setup_List;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__GNB_CU_CP_TNLA_Failed_To_Setup_List( SI_E1AP_DT_GNB_CU_CP_TNLA_Failed_To_Setup_List ** pGNB_CU_CP_TNLA_Failed_To_Setup_List)
{
	SI_E1AP_DT_GNB_CU_CP_TNLA_Failed_To_Setup_List * obj_GNB_CU_CP_TNLA_Failed_To_Setup_List = NULL; 
	__si_e1ap_init_GNB_CU_CP_TNLA_Failed_To_Setup_List( &obj_GNB_CU_CP_TNLA_Failed_To_Setup_List);

	// L:1260
	SI_E1AP_DT_GNB_CU_CP_TNLA_Failed_To_Setup_Item * objGNB_CU_CP_TNLA_Failed_To_Setup_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__GNB_CU_CP_TNLA_Failed_To_Setup_Item( &objGNB_CU_CP_TNLA_Failed_To_Setup_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_GNB_CU_CP_TNLA_Failed_To_Setup_List->GNB_CU_CP_TNLA_Failed_To_Setup_Item, (uint8_t*)objGNB_CU_CP_TNLA_Failed_To_Setup_Item);

	*pGNB_CU_CP_TNLA_Failed_To_Setup_List = obj_GNB_CU_CP_TNLA_Failed_To_Setup_List;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DRB_Status_List( SI_E1AP_DT_DRB_Status_List ** pDRB_Status_List)
{
	SI_E1AP_DT_DRB_Status_List * obj_DRB_Status_List = NULL; 
	__si_e1ap_init_DRB_Status_List( &obj_DRB_Status_List);

	// L:1260
	SI_E1AP_DT_DRB_Status_Item * objDRB_Status_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DRB_Status_Item( &objDRB_Status_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DRB_Status_List->DRB_Status_Item, (uint8_t*)objDRB_Status_Item);

	*pDRB_Status_List = obj_DRB_Status_List;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__DLUPTNLAddressToUpdateList( SI_E1AP_DT_DLUPTNLAddressToUpdateList ** pDLUPTNLAddressToUpdateList)
{
	SI_E1AP_DT_DLUPTNLAddressToUpdateList * obj_DLUPTNLAddressToUpdateList = NULL; 
	__si_e1ap_init_DLUPTNLAddressToUpdateList( &obj_DLUPTNLAddressToUpdateList);

	// L:1260
	SI_E1AP_DT_DLUPTNLAddressToUpdateItem * objDLUPTNLAddressToUpdateItem = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__DLUPTNLAddressToUpdateItem( &objDLUPTNLAddressToUpdateItem);  // L:1395

	// L:1419
	__si_linked_list_add( obj_DLUPTNLAddressToUpdateList->DLUPTNLAddressToUpdateItem, (uint8_t*)objDLUPTNLAddressToUpdateItem);

	*pDLUPTNLAddressToUpdateList = obj_DLUPTNLAddressToUpdateList;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__ULUPTNLAddressToUpdateList( SI_E1AP_DT_ULUPTNLAddressToUpdateList ** pULUPTNLAddressToUpdateList)
{
	SI_E1AP_DT_ULUPTNLAddressToUpdateList * obj_ULUPTNLAddressToUpdateList = NULL; 
	__si_e1ap_init_ULUPTNLAddressToUpdateList( &obj_ULUPTNLAddressToUpdateList);

	// L:1260
	SI_E1AP_DT_ULUPTNLAddressToUpdateItem * objULUPTNLAddressToUpdateItem = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__ULUPTNLAddressToUpdateItem( &objULUPTNLAddressToUpdateItem);  // L:1395

	// L:1419
	__si_linked_list_add( obj_ULUPTNLAddressToUpdateList->ULUPTNLAddressToUpdateItem, (uint8_t*)objULUPTNLAddressToUpdateItem);

	*pULUPTNLAddressToUpdateList = obj_ULUPTNLAddressToUpdateList;
}


// SEQUENCE_OF  L:11113
void __si_e1ap__set_testdata__IAB_Donor_CU_UPPSKInfo( SI_E1AP_DT_IAB_Donor_CU_UPPSKInfo ** pIAB_Donor_CU_UPPSKInfo)
{
	SI_E1AP_DT_IAB_Donor_CU_UPPSKInfo * obj_IAB_Donor_CU_UPPSKInfo = NULL; 
	__si_e1ap_init_IAB_Donor_CU_UPPSKInfo( &obj_IAB_Donor_CU_UPPSKInfo);

	// L:1260
	SI_E1AP_DT_IAB_Donor_CU_UPPSKInfo_Item * objIAB_Donor_CU_UPPSKInfo_Item = NULL;
	//SEQUENCE // L:1394
	__si_e1ap__set_testdata__IAB_Donor_CU_UPPSKInfo_Item( &objIAB_Donor_CU_UPPSKInfo_Item);  // L:1395

	// L:1419
	__si_linked_list_add( obj_IAB_Donor_CU_UPPSKInfo->IAB_Donor_CU_UPPSKInfo_Item, (uint8_t*)objIAB_Donor_CU_UPPSKInfo_Item);

	*pIAB_Donor_CU_UPPSKInfo = obj_IAB_Donor_CU_UPPSKInfo;
}




//  L:11222
void __si_e1ap__set_testdata__PDU_ActivityInformation_ExtIEs( SI_E1AP_DT_PDU_ActivityInformation_ExtIEs ** pActivityInformation_ExtIEs)
{
	SI_E1AP_DT_PDU_ActivityInformation_ExtIEs * obj_ActivityInformation_ExtIEs = (SI_E1AP_DT_PDU_ActivityInformation_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_ActivityInformation_ExtIEs));
	memset( obj_ActivityInformation_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_ActivityInformation_ExtIEs));


	*pActivityInformation_ExtIEs = obj_ActivityInformation_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_AlternativeQoSParaSetItem_ExtIEs( SI_E1AP_DT_PDU_AlternativeQoSParaSetItem_ExtIEs ** pAlternativeQoSParaSetItem_ExtIEs)
{
	SI_E1AP_DT_PDU_AlternativeQoSParaSetItem_ExtIEs * obj_AlternativeQoSParaSetItem_ExtIEs = (SI_E1AP_DT_PDU_AlternativeQoSParaSetItem_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_AlternativeQoSParaSetItem_ExtIEs));
	memset( obj_AlternativeQoSParaSetItem_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_AlternativeQoSParaSetItem_ExtIEs));

	// MaxDataBurstVolume  , PRESENCE = optional  INTEGER , MIN=0, MAX=4095
	obj_AlternativeQoSParaSetItem_ExtIEs->maximumDataBurstVolume = __getTestINTEGER( 0, 4095);
	obj_AlternativeQoSParaSetItem_ExtIEs->maximumDataBurstVolume_isset = 1;



	*pAlternativeQoSParaSetItem_ExtIEs = obj_AlternativeQoSParaSetItem_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_BCBearerContextToSetup_ExtIEs( SI_E1AP_DT_PDU_BCBearerContextToSetup_ExtIEs ** pBCBearerContextToSetup_ExtIEs)
{
	SI_E1AP_DT_PDU_BCBearerContextToSetup_ExtIEs * obj_BCBearerContextToSetup_ExtIEs = (SI_E1AP_DT_PDU_BCBearerContextToSetup_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCBearerContextToSetup_ExtIEs));
	memset( obj_BCBearerContextToSetup_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_BCBearerContextToSetup_ExtIEs));


	*pBCBearerContextToSetup_ExtIEs = obj_BCBearerContextToSetup_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_BCBearerContextNGU_TNLInfoat5GC_ExtIEs( SI_E1AP_DT_PDU_BCBearerContextNGU_TNLInfoat5GC_ExtIEs ** pBCBearerContextNGU_TNLInfoat5GC_ExtIEs)
{
	SI_E1AP_DT_PDU_BCBearerContextNGU_TNLInfoat5GC_ExtIEs * obj_BCBearerContextNGU_TNLInfoat5GC_ExtIEs = (SI_E1AP_DT_PDU_BCBearerContextNGU_TNLInfoat5GC_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCBearerContextNGU_TNLInfoat5GC_ExtIEs));
	memset( obj_BCBearerContextNGU_TNLInfoat5GC_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_BCBearerContextNGU_TNLInfoat5GC_ExtIEs));


	*pBCBearerContextNGU_TNLInfoat5GC_ExtIEs = obj_BCBearerContextNGU_TNLInfoat5GC_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_BCMRBSetupConfiguration_Item_ExtIEs( SI_E1AP_DT_PDU_BCMRBSetupConfiguration_Item_ExtIEs ** pBCMRBSetupConfiguration_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_BCMRBSetupConfiguration_Item_ExtIEs * obj_BCMRBSetupConfiguration_Item_ExtIEs = (SI_E1AP_DT_PDU_BCMRBSetupConfiguration_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCMRBSetupConfiguration_Item_ExtIEs));
	memset( obj_BCMRBSetupConfiguration_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_BCMRBSetupConfiguration_Item_ExtIEs));

	// F1U-TNL-InfoToAdd-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__F1U_TNL_InfoToAdd_List( &obj_BCMRBSetupConfiguration_Item_ExtIEs->f1UTNLInfoToAddList);
	obj_BCMRBSetupConfiguration_Item_ExtIEs->f1UTNLInfoToAddList_isset = 1;



	*pBCMRBSetupConfiguration_Item_ExtIEs = obj_BCMRBSetupConfiguration_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_BCBearerContextToSetupResponse_ExtIEs( SI_E1AP_DT_PDU_BCBearerContextToSetupResponse_ExtIEs ** pBCBearerContextToSetupResponse_ExtIEs)
{
	SI_E1AP_DT_PDU_BCBearerContextToSetupResponse_ExtIEs * obj_BCBearerContextToSetupResponse_ExtIEs = (SI_E1AP_DT_PDU_BCBearerContextToSetupResponse_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCBearerContextToSetupResponse_ExtIEs));
	memset( obj_BCBearerContextToSetupResponse_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_BCBearerContextToSetupResponse_ExtIEs));


	*pBCBearerContextToSetupResponse_ExtIEs = obj_BCBearerContextToSetupResponse_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_BCBearerContextNGU_TNLInfoatNGRAN_ExtIEs( SI_E1AP_DT_PDU_BCBearerContextNGU_TNLInfoatNGRAN_ExtIEs ** pBCBearerContextNGU_TNLInfoatNGRAN_ExtIEs)
{
	SI_E1AP_DT_PDU_BCBearerContextNGU_TNLInfoatNGRAN_ExtIEs * obj_BCBearerContextNGU_TNLInfoatNGRAN_ExtIEs = (SI_E1AP_DT_PDU_BCBearerContextNGU_TNLInfoatNGRAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCBearerContextNGU_TNLInfoatNGRAN_ExtIEs));
	memset( obj_BCBearerContextNGU_TNLInfoatNGRAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_BCBearerContextNGU_TNLInfoatNGRAN_ExtIEs));


	*pBCBearerContextNGU_TNLInfoatNGRAN_ExtIEs = obj_BCBearerContextNGU_TNLInfoatNGRAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_BCMRBSetupResponseList_Item_ExtIEs( SI_E1AP_DT_PDU_BCMRBSetupResponseList_Item_ExtIEs ** pBCMRBSetupResponseList_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_BCMRBSetupResponseList_Item_ExtIEs * obj_BCMRBSetupResponseList_Item_ExtIEs = (SI_E1AP_DT_PDU_BCMRBSetupResponseList_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCMRBSetupResponseList_Item_ExtIEs));
	memset( obj_BCMRBSetupResponseList_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_BCMRBSetupResponseList_Item_ExtIEs));

	// F1U-TNL-InfoAdded-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__F1U_TNL_InfoAdded_List( &obj_BCMRBSetupResponseList_Item_ExtIEs->f1UTNLInfoAddedList);
	obj_BCMRBSetupResponseList_Item_ExtIEs->f1UTNLInfoAddedList_isset = 1;



	*pBCMRBSetupResponseList_Item_ExtIEs = obj_BCMRBSetupResponseList_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_BCBearerContextF1U_TNLInfoatCU_ExtIEs( SI_E1AP_DT_PDU_BCBearerContextF1U_TNLInfoatCU_ExtIEs ** pBCBearerContextF1U_TNLInfoatCU_ExtIEs)
{
	SI_E1AP_DT_PDU_BCBearerContextF1U_TNLInfoatCU_ExtIEs * obj_BCBearerContextF1U_TNLInfoatCU_ExtIEs = (SI_E1AP_DT_PDU_BCBearerContextF1U_TNLInfoatCU_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCBearerContextF1U_TNLInfoatCU_ExtIEs));
	memset( obj_BCBearerContextF1U_TNLInfoatCU_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_BCBearerContextF1U_TNLInfoatCU_ExtIEs));


	*pBCBearerContextF1U_TNLInfoatCU_ExtIEs = obj_BCBearerContextF1U_TNLInfoatCU_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_BCMRBFailedList_Item_ExtIEs( SI_E1AP_DT_PDU_BCMRBFailedList_Item_ExtIEs ** pBCMRBFailedList_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_BCMRBFailedList_Item_ExtIEs * obj_BCMRBFailedList_Item_ExtIEs = (SI_E1AP_DT_PDU_BCMRBFailedList_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCMRBFailedList_Item_ExtIEs));
	memset( obj_BCMRBFailedList_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_BCMRBFailedList_Item_ExtIEs));


	*pBCMRBFailedList_Item_ExtIEs = obj_BCMRBFailedList_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_BCBearerContextToModify_ExtIEs( SI_E1AP_DT_PDU_BCBearerContextToModify_ExtIEs ** pBCBearerContextToModify_ExtIEs)
{
	SI_E1AP_DT_PDU_BCBearerContextToModify_ExtIEs * obj_BCBearerContextToModify_ExtIEs = (SI_E1AP_DT_PDU_BCBearerContextToModify_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCBearerContextToModify_ExtIEs));
	memset( obj_BCBearerContextToModify_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_BCBearerContextToModify_ExtIEs));

	// BCBearerContextNGU-TNLInfoatNGRAN-Request , PRESENCE = optional   CHOICE
	__si_e1ap__set_testdata__BCBearerContextNGU_TNLInfoatNGRAN_Request( &obj_BCBearerContextToModify_ExtIEs->bCBearerContextNGUTNLInfoatNGRANRequest);
	obj_BCBearerContextToModify_ExtIEs->bCBearerContextNGUTNLInfoatNGRANRequest->SelectedChoice = BCBearerContextNGU_TNLInfoatNGRAN_Request_locationindependent_val;

	switch( obj_BCBearerContextToModify_ExtIEs->bCBearerContextNGUTNLInfoatNGRANRequest->SelectedChoice)
	{
		case BCBearerContextNGU_TNLInfoatNGRAN_Request_locationindependent_val:
			obj_BCBearerContextToModify_ExtIEs->bCBearerContextNGUTNLInfoatNGRANRequest->u.locationindependent = MBSNGUInformationAtNGRAN_Request_true_val;
			break;
		case BCBearerContextNGU_TNLInfoatNGRAN_Request_locationdependent_val:
			__si_e1ap__set_testdata__MBSNGUInformationAtNGRAN_Request_List( &obj_BCBearerContextToModify_ExtIEs->bCBearerContextNGUTNLInfoatNGRANRequest->u.locationdependent); //   L:11463
			break;
		case BCBearerContextNGU_TNLInfoatNGRAN_Request_choice_extension_val:  // L:11477
			{
				__si_e1ap__set_testdata__PDU_BCBearerContextNGU_TNLInfoatNGRAN_Request_ExtIEs( &obj_BCBearerContextToModify_ExtIEs->bCBearerContextNGUTNLInfoatNGRANRequest->u.choice_extension);   // L:11497
			}
			break;
		default:
			break;
	}

	obj_BCBearerContextToModify_ExtIEs->bCBearerContextNGUTNLInfoatNGRANRequest_isset = 1;



	*pBCBearerContextToModify_ExtIEs = obj_BCBearerContextToModify_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_BCBearerContextNGU_TNLInfoatNGRAN_Request_ExtIEs( SI_E1AP_DT_PDU_BCBearerContextNGU_TNLInfoatNGRAN_Request_ExtIEs ** pBCBearerContextNGU_TNLInfoatNGRAN_Request_ExtIEs)
{
	SI_E1AP_DT_PDU_BCBearerContextNGU_TNLInfoatNGRAN_Request_ExtIEs * obj_BCBearerContextNGU_TNLInfoatNGRAN_Request_ExtIEs = (SI_E1AP_DT_PDU_BCBearerContextNGU_TNLInfoatNGRAN_Request_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCBearerContextNGU_TNLInfoatNGRAN_Request_ExtIEs));
	memset( obj_BCBearerContextNGU_TNLInfoatNGRAN_Request_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_BCBearerContextNGU_TNLInfoatNGRAN_Request_ExtIEs));


	*pBCBearerContextNGU_TNLInfoatNGRAN_Request_ExtIEs = obj_BCBearerContextNGU_TNLInfoatNGRAN_Request_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_BCMRBModifyConfiguration_Item_ExtIEs( SI_E1AP_DT_PDU_BCMRBModifyConfiguration_Item_ExtIEs ** pBCMRBModifyConfiguration_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_BCMRBModifyConfiguration_Item_ExtIEs * obj_BCMRBModifyConfiguration_Item_ExtIEs = (SI_E1AP_DT_PDU_BCMRBModifyConfiguration_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCMRBModifyConfiguration_Item_ExtIEs));
	memset( obj_BCMRBModifyConfiguration_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_BCMRBModifyConfiguration_Item_ExtIEs));

	// F1U-TNL-InfoToAddOrModify-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__F1U_TNL_InfoToAddOrModify_List( &obj_BCMRBModifyConfiguration_Item_ExtIEs->f1UTNLInfoToAddOrModifyList);
	obj_BCMRBModifyConfiguration_Item_ExtIEs->f1UTNLInfoToAddOrModifyList_isset = 1;


	// F1U-TNL-InfoToRelease-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__F1U_TNL_InfoToRelease_List( &obj_BCMRBModifyConfiguration_Item_ExtIEs->f1UTNLInfoToReleaseList);
	obj_BCMRBModifyConfiguration_Item_ExtIEs->f1UTNLInfoToReleaseList_isset = 1;



	*pBCMRBModifyConfiguration_Item_ExtIEs = obj_BCMRBModifyConfiguration_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_BCBearerContextF1U_TNLInfoatDU_ExtIEs( SI_E1AP_DT_PDU_BCBearerContextF1U_TNLInfoatDU_ExtIEs ** pBCBearerContextF1U_TNLInfoatDU_ExtIEs)
{
	SI_E1AP_DT_PDU_BCBearerContextF1U_TNLInfoatDU_ExtIEs * obj_BCBearerContextF1U_TNLInfoatDU_ExtIEs = (SI_E1AP_DT_PDU_BCBearerContextF1U_TNLInfoatDU_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCBearerContextF1U_TNLInfoatDU_ExtIEs));
	memset( obj_BCBearerContextF1U_TNLInfoatDU_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_BCBearerContextF1U_TNLInfoatDU_ExtIEs));


	*pBCBearerContextF1U_TNLInfoatDU_ExtIEs = obj_BCBearerContextF1U_TNLInfoatDU_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_BCBearerContextToModifyResponse_ExtIEs( SI_E1AP_DT_PDU_BCBearerContextToModifyResponse_ExtIEs ** pBCBearerContextToModifyResponse_ExtIEs)
{
	SI_E1AP_DT_PDU_BCBearerContextToModifyResponse_ExtIEs * obj_BCBearerContextToModifyResponse_ExtIEs = (SI_E1AP_DT_PDU_BCBearerContextToModifyResponse_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCBearerContextToModifyResponse_ExtIEs));
	memset( obj_BCBearerContextToModifyResponse_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_BCBearerContextToModifyResponse_ExtIEs));


	*pBCBearerContextToModifyResponse_ExtIEs = obj_BCBearerContextToModifyResponse_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_BCMRBSetupModifyResponseList_Item_ExtIEs( SI_E1AP_DT_PDU_BCMRBSetupModifyResponseList_Item_ExtIEs ** pBCMRBSetupModifyResponseList_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_BCMRBSetupModifyResponseList_Item_ExtIEs * obj_BCMRBSetupModifyResponseList_Item_ExtIEs = (SI_E1AP_DT_PDU_BCMRBSetupModifyResponseList_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCMRBSetupModifyResponseList_Item_ExtIEs));
	memset( obj_BCMRBSetupModifyResponseList_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_BCMRBSetupModifyResponseList_Item_ExtIEs));

	// F1U-TNL-InfoAddedOrModified-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__F1U_TNL_InfoAddedOrModified_List( &obj_BCMRBSetupModifyResponseList_Item_ExtIEs->f1UTNLInfoAddedOrModifiedList);
	obj_BCMRBSetupModifyResponseList_Item_ExtIEs->f1UTNLInfoAddedOrModifiedList_isset = 1;



	*pBCMRBSetupModifyResponseList_Item_ExtIEs = obj_BCMRBSetupModifyResponseList_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_BCBearerContextToModifyRequired_ExtIEs( SI_E1AP_DT_PDU_BCBearerContextToModifyRequired_ExtIEs ** pBCBearerContextToModifyRequired_ExtIEs)
{
	SI_E1AP_DT_PDU_BCBearerContextToModifyRequired_ExtIEs * obj_BCBearerContextToModifyRequired_ExtIEs = (SI_E1AP_DT_PDU_BCBearerContextToModifyRequired_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCBearerContextToModifyRequired_ExtIEs));
	memset( obj_BCBearerContextToModifyRequired_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_BCBearerContextToModifyRequired_ExtIEs));


	*pBCBearerContextToModifyRequired_ExtIEs = obj_BCBearerContextToModifyRequired_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_BCBearerContextToModifyConfirm_ExtIEs( SI_E1AP_DT_PDU_BCBearerContextToModifyConfirm_ExtIEs ** pBCBearerContextToModifyConfirm_ExtIEs)
{
	SI_E1AP_DT_PDU_BCBearerContextToModifyConfirm_ExtIEs * obj_BCBearerContextToModifyConfirm_ExtIEs = (SI_E1AP_DT_PDU_BCBearerContextToModifyConfirm_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCBearerContextToModifyConfirm_ExtIEs));
	memset( obj_BCBearerContextToModifyConfirm_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_BCBearerContextToModifyConfirm_ExtIEs));


	*pBCBearerContextToModifyConfirm_ExtIEs = obj_BCBearerContextToModifyConfirm_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_Cause_ExtIEs( SI_E1AP_DT_PDU_Cause_ExtIEs ** pCause_ExtIEs)
{
	SI_E1AP_DT_PDU_Cause_ExtIEs * obj_Cause_ExtIEs = (SI_E1AP_DT_PDU_Cause_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Cause_ExtIEs));
	memset( obj_Cause_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_Cause_ExtIEs));


	*pCause_ExtIEs = obj_Cause_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_Cell_Group_Information_Item_ExtIEs( SI_E1AP_DT_PDU_Cell_Group_Information_Item_ExtIEs ** pCell_Group_Information_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_Cell_Group_Information_Item_ExtIEs * obj_Cell_Group_Information_Item_ExtIEs = (SI_E1AP_DT_PDU_Cell_Group_Information_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Cell_Group_Information_Item_ExtIEs));
	memset( obj_Cell_Group_Information_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_Cell_Group_Information_Item_ExtIEs));

	// Number-of-tunnels  , PRESENCE = optional  INTEGER , MIN=1, MAX=4
	obj_Cell_Group_Information_Item_ExtIEs->numberoftunnels = __getTestINTEGER( 1, 4);
	obj_Cell_Group_Information_Item_ExtIEs->numberoftunnels_isset = 1;



	*pCell_Group_Information_Item_ExtIEs = obj_Cell_Group_Information_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_CP_TNL_Information_ExtIEs( SI_E1AP_DT_PDU_CP_TNL_Information_ExtIEs ** pCP_TNL_Information_ExtIEs)
{
	SI_E1AP_DT_PDU_CP_TNL_Information_ExtIEs * obj_CP_TNL_Information_ExtIEs = (SI_E1AP_DT_PDU_CP_TNL_Information_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_CP_TNL_Information_ExtIEs));
	memset( obj_CP_TNL_Information_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_CP_TNL_Information_ExtIEs));

	// Endpoint-IP-address-and-port, PRESENCE = mandatory   SEQUENCE
	__si_e1ap__set_testdata__Endpoint_IP_address_and_port( &obj_CP_TNL_Information_ExtIEs->endpointIPAddressandPort);
	obj_CP_TNL_Information_ExtIEs->endpointIPAddressandPort_isset = 1;



	*pCP_TNL_Information_ExtIEs = obj_CP_TNL_Information_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_CriticalityDiagnostics_ExtIEs( SI_E1AP_DT_PDU_CriticalityDiagnostics_ExtIEs ** pCriticalityDiagnostics_ExtIEs)
{
	SI_E1AP_DT_PDU_CriticalityDiagnostics_ExtIEs * obj_CriticalityDiagnostics_ExtIEs = (SI_E1AP_DT_PDU_CriticalityDiagnostics_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_CriticalityDiagnostics_ExtIEs));
	memset( obj_CriticalityDiagnostics_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_CriticalityDiagnostics_ExtIEs));


	*pCriticalityDiagnostics_ExtIEs = obj_CriticalityDiagnostics_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_CriticalityDiagnostics_IE_List_ExtIEs( SI_E1AP_DT_PDU_CriticalityDiagnostics_IE_List_ExtIEs ** pCriticalityDiagnostics_IE_List_ExtIEs)
{
	SI_E1AP_DT_PDU_CriticalityDiagnostics_IE_List_ExtIEs * obj_CriticalityDiagnostics_IE_List_ExtIEs = (SI_E1AP_DT_PDU_CriticalityDiagnostics_IE_List_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_CriticalityDiagnostics_IE_List_ExtIEs));
	memset( obj_CriticalityDiagnostics_IE_List_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_CriticalityDiagnostics_IE_List_ExtIEs));


	*pCriticalityDiagnostics_IE_List_ExtIEs = obj_CriticalityDiagnostics_IE_List_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DAPSRequestInfo_ExtIEs( SI_E1AP_DT_PDU_DAPSRequestInfo_ExtIEs ** pDAPSRequestInfo_ExtIEs)
{
	SI_E1AP_DT_PDU_DAPSRequestInfo_ExtIEs * obj_DAPSRequestInfo_ExtIEs = (SI_E1AP_DT_PDU_DAPSRequestInfo_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DAPSRequestInfo_ExtIEs));
	memset( obj_DAPSRequestInfo_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DAPSRequestInfo_ExtIEs));


	*pDAPSRequestInfo_ExtIEs = obj_DAPSRequestInfo_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_Data_Forwarding_Information_Request_ExtIEs( SI_E1AP_DT_PDU_Data_Forwarding_Information_Request_ExtIEs ** pData_Forwarding_Information_Request_ExtIEs)
{
	SI_E1AP_DT_PDU_Data_Forwarding_Information_Request_ExtIEs * obj_Data_Forwarding_Information_Request_ExtIEs = (SI_E1AP_DT_PDU_Data_Forwarding_Information_Request_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Data_Forwarding_Information_Request_ExtIEs));
	memset( obj_Data_Forwarding_Information_Request_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_Data_Forwarding_Information_Request_ExtIEs));


	*pData_Forwarding_Information_Request_ExtIEs = obj_Data_Forwarding_Information_Request_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_Data_Forwarding_Information_ExtIEs( SI_E1AP_DT_PDU_Data_Forwarding_Information_ExtIEs ** pData_Forwarding_Information_ExtIEs)
{
	SI_E1AP_DT_PDU_Data_Forwarding_Information_ExtIEs * obj_Data_Forwarding_Information_ExtIEs = (SI_E1AP_DT_PDU_Data_Forwarding_Information_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Data_Forwarding_Information_ExtIEs));
	memset( obj_Data_Forwarding_Information_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_Data_Forwarding_Information_ExtIEs));

	// DataForwardingtoNG-RANQoSFlowInformationList  , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__DataForwardingtoNG_RANQoSFlowInformationList( &obj_Data_Forwarding_Information_ExtIEs->dataForwardingtoNGRANQoSFlowInformationList);
	obj_Data_Forwarding_Information_ExtIEs->dataForwardingtoNGRANQoSFlowInformationList_isset = 1;


	// PDUSetbasedHandlingIndicator , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_Data_Forwarding_Information_ExtIEs->pDUSetbasedHandlingIndicator = PDUSetbasedHandlingIndicator_supported_val;
	obj_Data_Forwarding_Information_ExtIEs->pDUSetbasedHandlingIndicator_isset = 1;



	*pData_Forwarding_Information_ExtIEs = obj_Data_Forwarding_Information_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DataForwardingtoE_UTRANInformationListItem_ExtIEs( SI_E1AP_DT_PDU_DataForwardingtoE_UTRANInformationListItem_ExtIEs ** pDataForwardingtoE_UTRANInformationListItem_ExtIEs)
{
	SI_E1AP_DT_PDU_DataForwardingtoE_UTRANInformationListItem_ExtIEs * obj_DataForwardingtoE_UTRANInformationListItem_ExtIEs = (SI_E1AP_DT_PDU_DataForwardingtoE_UTRANInformationListItem_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DataForwardingtoE_UTRANInformationListItem_ExtIEs));
	memset( obj_DataForwardingtoE_UTRANInformationListItem_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DataForwardingtoE_UTRANInformationListItem_ExtIEs));


	*pDataForwardingtoE_UTRANInformationListItem_ExtIEs = obj_DataForwardingtoE_UTRANInformationListItem_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_Data_Usage_per_PDU_Session_Report_ExtIEs( SI_E1AP_DT_PDU_Data_Usage_per_PDU_Session_Report_ExtIEs ** pData_Usage_per_PDU_Session_Report_ExtIEs)
{
	SI_E1AP_DT_PDU_Data_Usage_per_PDU_Session_Report_ExtIEs * obj_Data_Usage_per_PDU_Session_Report_ExtIEs = (SI_E1AP_DT_PDU_Data_Usage_per_PDU_Session_Report_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Data_Usage_per_PDU_Session_Report_ExtIEs));
	memset( obj_Data_Usage_per_PDU_Session_Report_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_Data_Usage_per_PDU_Session_Report_ExtIEs));


	*pData_Usage_per_PDU_Session_Report_ExtIEs = obj_Data_Usage_per_PDU_Session_Report_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_Data_Usage_per_QoS_Flow_Item_ExtIEs( SI_E1AP_DT_PDU_Data_Usage_per_QoS_Flow_Item_ExtIEs ** pData_Usage_per_QoS_Flow_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_Data_Usage_per_QoS_Flow_Item_ExtIEs * obj_Data_Usage_per_QoS_Flow_Item_ExtIEs = (SI_E1AP_DT_PDU_Data_Usage_per_QoS_Flow_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Data_Usage_per_QoS_Flow_Item_ExtIEs));
	memset( obj_Data_Usage_per_QoS_Flow_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_Data_Usage_per_QoS_Flow_Item_ExtIEs));


	*pData_Usage_per_QoS_Flow_Item_ExtIEs = obj_Data_Usage_per_QoS_Flow_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_Data_Usage_Report_ItemExtIEs( SI_E1AP_DT_PDU_Data_Usage_Report_ItemExtIEs ** pData_Usage_Report_ItemExtIEs)
{
	SI_E1AP_DT_PDU_Data_Usage_Report_ItemExtIEs * obj_Data_Usage_Report_ItemExtIEs = (SI_E1AP_DT_PDU_Data_Usage_Report_ItemExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Data_Usage_Report_ItemExtIEs));
	memset( obj_Data_Usage_Report_ItemExtIEs, 0, sizeof( SI_E1AP_DT_PDU_Data_Usage_Report_ItemExtIEs));


	*pData_Usage_Report_ItemExtIEs = obj_Data_Usage_Report_ItemExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DLDiscarding_ExtIEs( SI_E1AP_DT_PDU_DLDiscarding_ExtIEs ** pDLDiscarding_ExtIEs)
{
	SI_E1AP_DT_PDU_DLDiscarding_ExtIEs * obj_DLDiscarding_ExtIEs = (SI_E1AP_DT_PDU_DLDiscarding_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DLDiscarding_ExtIEs));
	memset( obj_DLDiscarding_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DLDiscarding_ExtIEs));


	*pDLDiscarding_ExtIEs = obj_DLDiscarding_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DLUPTNLAddressToUpdateItemExtIEs( SI_E1AP_DT_PDU_DLUPTNLAddressToUpdateItemExtIEs ** pDLUPTNLAddressToUpdateItemExtIEs)
{
	SI_E1AP_DT_PDU_DLUPTNLAddressToUpdateItemExtIEs * obj_DLUPTNLAddressToUpdateItemExtIEs = (SI_E1AP_DT_PDU_DLUPTNLAddressToUpdateItemExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DLUPTNLAddressToUpdateItemExtIEs));
	memset( obj_DLUPTNLAddressToUpdateItemExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DLUPTNLAddressToUpdateItemExtIEs));


	*pDLUPTNLAddressToUpdateItemExtIEs = obj_DLUPTNLAddressToUpdateItemExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_Activity_ItemExtIEs( SI_E1AP_DT_PDU_DRB_Activity_ItemExtIEs ** pDRB_Activity_ItemExtIEs)
{
	SI_E1AP_DT_PDU_DRB_Activity_ItemExtIEs * obj_DRB_Activity_ItemExtIEs = (SI_E1AP_DT_PDU_DRB_Activity_ItemExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_Activity_ItemExtIEs));
	memset( obj_DRB_Activity_ItemExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_Activity_ItemExtIEs));


	*pDRB_Activity_ItemExtIEs = obj_DRB_Activity_ItemExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_Confirm_Modified_Item_EUTRAN_ExtIEs( SI_E1AP_DT_PDU_DRB_Confirm_Modified_Item_EUTRAN_ExtIEs ** pDRB_Confirm_Modified_Item_EUTRAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_Confirm_Modified_Item_EUTRAN_ExtIEs * obj_DRB_Confirm_Modified_Item_EUTRAN_ExtIEs = (SI_E1AP_DT_PDU_DRB_Confirm_Modified_Item_EUTRAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_Confirm_Modified_Item_EUTRAN_ExtIEs));
	memset( obj_DRB_Confirm_Modified_Item_EUTRAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_Confirm_Modified_Item_EUTRAN_ExtIEs));


	*pDRB_Confirm_Modified_Item_EUTRAN_ExtIEs = obj_DRB_Confirm_Modified_Item_EUTRAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_Confirm_Modified_Item_NG_RAN_ExtIEs( SI_E1AP_DT_PDU_DRB_Confirm_Modified_Item_NG_RAN_ExtIEs ** pDRB_Confirm_Modified_Item_NG_RAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_Confirm_Modified_Item_NG_RAN_ExtIEs * obj_DRB_Confirm_Modified_Item_NG_RAN_ExtIEs = (SI_E1AP_DT_PDU_DRB_Confirm_Modified_Item_NG_RAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_Confirm_Modified_Item_NG_RAN_ExtIEs));
	memset( obj_DRB_Confirm_Modified_Item_NG_RAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_Confirm_Modified_Item_NG_RAN_ExtIEs));


	*pDRB_Confirm_Modified_Item_NG_RAN_ExtIEs = obj_DRB_Confirm_Modified_Item_NG_RAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_Failed_Item_EUTRAN_ExtIEs( SI_E1AP_DT_PDU_DRB_Failed_Item_EUTRAN_ExtIEs ** pDRB_Failed_Item_EUTRAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_Failed_Item_EUTRAN_ExtIEs * obj_DRB_Failed_Item_EUTRAN_ExtIEs = (SI_E1AP_DT_PDU_DRB_Failed_Item_EUTRAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_Failed_Item_EUTRAN_ExtIEs));
	memset( obj_DRB_Failed_Item_EUTRAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_Failed_Item_EUTRAN_ExtIEs));


	*pDRB_Failed_Item_EUTRAN_ExtIEs = obj_DRB_Failed_Item_EUTRAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_Failed_Mod_Item_EUTRAN_ExtIEs( SI_E1AP_DT_PDU_DRB_Failed_Mod_Item_EUTRAN_ExtIEs ** pDRB_Failed_Mod_Item_EUTRAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_Failed_Mod_Item_EUTRAN_ExtIEs * obj_DRB_Failed_Mod_Item_EUTRAN_ExtIEs = (SI_E1AP_DT_PDU_DRB_Failed_Mod_Item_EUTRAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_Failed_Mod_Item_EUTRAN_ExtIEs));
	memset( obj_DRB_Failed_Mod_Item_EUTRAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_Failed_Mod_Item_EUTRAN_ExtIEs));


	*pDRB_Failed_Mod_Item_EUTRAN_ExtIEs = obj_DRB_Failed_Mod_Item_EUTRAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_Failed_Item_NG_RAN_ExtIEs( SI_E1AP_DT_PDU_DRB_Failed_Item_NG_RAN_ExtIEs ** pDRB_Failed_Item_NG_RAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_Failed_Item_NG_RAN_ExtIEs * obj_DRB_Failed_Item_NG_RAN_ExtIEs = (SI_E1AP_DT_PDU_DRB_Failed_Item_NG_RAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_Failed_Item_NG_RAN_ExtIEs));
	memset( obj_DRB_Failed_Item_NG_RAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_Failed_Item_NG_RAN_ExtIEs));


	*pDRB_Failed_Item_NG_RAN_ExtIEs = obj_DRB_Failed_Item_NG_RAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_Failed_Mod_Item_NG_RAN_ExtIEs( SI_E1AP_DT_PDU_DRB_Failed_Mod_Item_NG_RAN_ExtIEs ** pDRB_Failed_Mod_Item_NG_RAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_Failed_Mod_Item_NG_RAN_ExtIEs * obj_DRB_Failed_Mod_Item_NG_RAN_ExtIEs = (SI_E1AP_DT_PDU_DRB_Failed_Mod_Item_NG_RAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_Failed_Mod_Item_NG_RAN_ExtIEs));
	memset( obj_DRB_Failed_Mod_Item_NG_RAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_Failed_Mod_Item_NG_RAN_ExtIEs));


	*pDRB_Failed_Mod_Item_NG_RAN_ExtIEs = obj_DRB_Failed_Mod_Item_NG_RAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_Failed_To_Modify_Item_EUTRAN_ExtIEs( SI_E1AP_DT_PDU_DRB_Failed_To_Modify_Item_EUTRAN_ExtIEs ** pDRB_Failed_To_Modify_Item_EUTRAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_Failed_To_Modify_Item_EUTRAN_ExtIEs * obj_DRB_Failed_To_Modify_Item_EUTRAN_ExtIEs = (SI_E1AP_DT_PDU_DRB_Failed_To_Modify_Item_EUTRAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_Failed_To_Modify_Item_EUTRAN_ExtIEs));
	memset( obj_DRB_Failed_To_Modify_Item_EUTRAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_Failed_To_Modify_Item_EUTRAN_ExtIEs));


	*pDRB_Failed_To_Modify_Item_EUTRAN_ExtIEs = obj_DRB_Failed_To_Modify_Item_EUTRAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_Failed_To_Modify_Item_NG_RAN_ExtIEs( SI_E1AP_DT_PDU_DRB_Failed_To_Modify_Item_NG_RAN_ExtIEs ** pDRB_Failed_To_Modify_Item_NG_RAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_Failed_To_Modify_Item_NG_RAN_ExtIEs * obj_DRB_Failed_To_Modify_Item_NG_RAN_ExtIEs = (SI_E1AP_DT_PDU_DRB_Failed_To_Modify_Item_NG_RAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_Failed_To_Modify_Item_NG_RAN_ExtIEs));
	memset( obj_DRB_Failed_To_Modify_Item_NG_RAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_Failed_To_Modify_Item_NG_RAN_ExtIEs));


	*pDRB_Failed_To_Modify_Item_NG_RAN_ExtIEs = obj_DRB_Failed_To_Modify_Item_NG_RAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_Measurement_Results_Information_Item_ExtIEs( SI_E1AP_DT_PDU_DRB_Measurement_Results_Information_Item_ExtIEs ** pDRB_Measurement_Results_Information_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_Measurement_Results_Information_Item_ExtIEs * obj_DRB_Measurement_Results_Information_Item_ExtIEs = (SI_E1AP_DT_PDU_DRB_Measurement_Results_Information_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_Measurement_Results_Information_Item_ExtIEs));
	memset( obj_DRB_Measurement_Results_Information_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_Measurement_Results_Information_Item_ExtIEs));


	*pDRB_Measurement_Results_Information_Item_ExtIEs = obj_DRB_Measurement_Results_Information_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_Modified_Item_EUTRAN_ExtIEs( SI_E1AP_DT_PDU_DRB_Modified_Item_EUTRAN_ExtIEs ** pDRB_Modified_Item_EUTRAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_Modified_Item_EUTRAN_ExtIEs * obj_DRB_Modified_Item_EUTRAN_ExtIEs = (SI_E1AP_DT_PDU_DRB_Modified_Item_EUTRAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_Modified_Item_EUTRAN_ExtIEs));
	memset( obj_DRB_Modified_Item_EUTRAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_Modified_Item_EUTRAN_ExtIEs));


	*pDRB_Modified_Item_EUTRAN_ExtIEs = obj_DRB_Modified_Item_EUTRAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_Modified_Item_NG_RAN_ExtIEs( SI_E1AP_DT_PDU_DRB_Modified_Item_NG_RAN_ExtIEs ** pDRB_Modified_Item_NG_RAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_Modified_Item_NG_RAN_ExtIEs * obj_DRB_Modified_Item_NG_RAN_ExtIEs = (SI_E1AP_DT_PDU_DRB_Modified_Item_NG_RAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_Modified_Item_NG_RAN_ExtIEs));
	memset( obj_DRB_Modified_Item_NG_RAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_Modified_Item_NG_RAN_ExtIEs));

	// EarlyForwardingCOUNTInfo , PRESENCE = optional   CHOICE
	__si_e1ap__set_testdata__EarlyForwardingCOUNTInfo( &obj_DRB_Modified_Item_NG_RAN_ExtIEs->earlyForwardingCOUNTInfo);
	obj_DRB_Modified_Item_NG_RAN_ExtIEs->earlyForwardingCOUNTInfo->SelectedChoice = EarlyForwardingCOUNTInfo_firstDLCount_val;

	switch( obj_DRB_Modified_Item_NG_RAN_ExtIEs->earlyForwardingCOUNTInfo->SelectedChoice)
	{
		case EarlyForwardingCOUNTInfo_firstDLCount_val:
			__si_e1ap__set_testdata__FirstDLCount( &obj_DRB_Modified_Item_NG_RAN_ExtIEs->earlyForwardingCOUNTInfo->u.firstDLCount); //   L:11384
			break;
		case EarlyForwardingCOUNTInfo_dLDiscardingCount_val:
			__si_e1ap__set_testdata__DLDiscarding( &obj_DRB_Modified_Item_NG_RAN_ExtIEs->earlyForwardingCOUNTInfo->u.dLDiscardingCount); //   L:11384
			break;
		case EarlyForwardingCOUNTInfo_choice_Extension_val:  // L:11477
			{
				__si_e1ap__set_testdata__PDU_EarlyForwardingCOUNTInfo_ExtIEs( &obj_DRB_Modified_Item_NG_RAN_ExtIEs->earlyForwardingCOUNTInfo->u.choice_Extension);   // L:11497
			}
			break;
		default:
			break;
	}

	obj_DRB_Modified_Item_NG_RAN_ExtIEs->earlyForwardingCOUNTInfo_isset = 1;


	// QoS-Flow-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__QoS_Flow_List( &obj_DRB_Modified_Item_NG_RAN_ExtIEs->oldQoSFlowMapULendmarkerexpected);
	obj_DRB_Modified_Item_NG_RAN_ExtIEs->oldQoSFlowMapULendmarkerexpected_isset = 1;



	*pDRB_Modified_Item_NG_RAN_ExtIEs = obj_DRB_Modified_Item_NG_RAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_Removed_Item_ExtIEs( SI_E1AP_DT_PDU_DRB_Removed_Item_ExtIEs ** pDRB_Removed_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_Removed_Item_ExtIEs * obj_DRB_Removed_Item_ExtIEs = (SI_E1AP_DT_PDU_DRB_Removed_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_Removed_Item_ExtIEs));
	memset( obj_DRB_Removed_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_Removed_Item_ExtIEs));


	*pDRB_Removed_Item_ExtIEs = obj_DRB_Removed_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_Required_To_Modify_Item_EUTRAN_ExtIEs( SI_E1AP_DT_PDU_DRB_Required_To_Modify_Item_EUTRAN_ExtIEs ** pDRB_Required_To_Modify_Item_EUTRAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_Required_To_Modify_Item_EUTRAN_ExtIEs * obj_DRB_Required_To_Modify_Item_EUTRAN_ExtIEs = (SI_E1AP_DT_PDU_DRB_Required_To_Modify_Item_EUTRAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_Required_To_Modify_Item_EUTRAN_ExtIEs));
	memset( obj_DRB_Required_To_Modify_Item_EUTRAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_Required_To_Modify_Item_EUTRAN_ExtIEs));


	*pDRB_Required_To_Modify_Item_EUTRAN_ExtIEs = obj_DRB_Required_To_Modify_Item_EUTRAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_Required_To_Modify_Item_NG_RAN_ExtIEs( SI_E1AP_DT_PDU_DRB_Required_To_Modify_Item_NG_RAN_ExtIEs ** pDRB_Required_To_Modify_Item_NG_RAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_Required_To_Modify_Item_NG_RAN_ExtIEs * obj_DRB_Required_To_Modify_Item_NG_RAN_ExtIEs = (SI_E1AP_DT_PDU_DRB_Required_To_Modify_Item_NG_RAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_Required_To_Modify_Item_NG_RAN_ExtIEs));
	memset( obj_DRB_Required_To_Modify_Item_NG_RAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_Required_To_Modify_Item_NG_RAN_ExtIEs));


	*pDRB_Required_To_Modify_Item_NG_RAN_ExtIEs = obj_DRB_Required_To_Modify_Item_NG_RAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_Setup_Item_EUTRAN_ExtIEs( SI_E1AP_DT_PDU_DRB_Setup_Item_EUTRAN_ExtIEs ** pDRB_Setup_Item_EUTRAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_Setup_Item_EUTRAN_ExtIEs * obj_DRB_Setup_Item_EUTRAN_ExtIEs = (SI_E1AP_DT_PDU_DRB_Setup_Item_EUTRAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_Setup_Item_EUTRAN_ExtIEs));
	memset( obj_DRB_Setup_Item_EUTRAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_Setup_Item_EUTRAN_ExtIEs));

	// TransportLayerAddress  , PRESENCE = optional   BITSTRING , MIN=1, MAX=160
	__si_e1ap_init_TransportLayerAddress2( &obj_DRB_Setup_Item_EUTRAN_ExtIEs->dataForwardingSourceIPAddress, "4", 1, 1);
	obj_DRB_Setup_Item_EUTRAN_ExtIEs->dataForwardingSourceIPAddress->bitslen = 1;
	obj_DRB_Setup_Item_EUTRAN_ExtIEs->dataForwardingSourceIPAddress_isset = 1;


	// SecurityResult , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__SecurityResult( &obj_DRB_Setup_Item_EUTRAN_ExtIEs->securityResult);
	obj_DRB_Setup_Item_EUTRAN_ExtIEs->securityResult_isset = 1;



	*pDRB_Setup_Item_EUTRAN_ExtIEs = obj_DRB_Setup_Item_EUTRAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_Setup_Mod_Item_EUTRAN_ExtIEs( SI_E1AP_DT_PDU_DRB_Setup_Mod_Item_EUTRAN_ExtIEs ** pDRB_Setup_Mod_Item_EUTRAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_Setup_Mod_Item_EUTRAN_ExtIEs * obj_DRB_Setup_Mod_Item_EUTRAN_ExtIEs = (SI_E1AP_DT_PDU_DRB_Setup_Mod_Item_EUTRAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_Setup_Mod_Item_EUTRAN_ExtIEs));
	memset( obj_DRB_Setup_Mod_Item_EUTRAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_Setup_Mod_Item_EUTRAN_ExtIEs));

	// SecurityResult , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__SecurityResult( &obj_DRB_Setup_Mod_Item_EUTRAN_ExtIEs->securityResult);
	obj_DRB_Setup_Mod_Item_EUTRAN_ExtIEs->securityResult_isset = 1;


	// TransportLayerAddress  , PRESENCE = optional   BITSTRING , MIN=1, MAX=160
	__si_e1ap_init_TransportLayerAddress2( &obj_DRB_Setup_Mod_Item_EUTRAN_ExtIEs->dataForwardingSourceIPAddress, "7", 1, 1);
	obj_DRB_Setup_Mod_Item_EUTRAN_ExtIEs->dataForwardingSourceIPAddress->bitslen = 1;
	obj_DRB_Setup_Mod_Item_EUTRAN_ExtIEs->dataForwardingSourceIPAddress_isset = 1;



	*pDRB_Setup_Mod_Item_EUTRAN_ExtIEs = obj_DRB_Setup_Mod_Item_EUTRAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_Setup_Item_NG_RAN_ExtIEs( SI_E1AP_DT_PDU_DRB_Setup_Item_NG_RAN_ExtIEs ** pDRB_Setup_Item_NG_RAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_Setup_Item_NG_RAN_ExtIEs * obj_DRB_Setup_Item_NG_RAN_ExtIEs = (SI_E1AP_DT_PDU_DRB_Setup_Item_NG_RAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_Setup_Item_NG_RAN_ExtIEs));
	memset( obj_DRB_Setup_Item_NG_RAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_Setup_Item_NG_RAN_ExtIEs));


	*pDRB_Setup_Item_NG_RAN_ExtIEs = obj_DRB_Setup_Item_NG_RAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_Setup_Mod_Item_NG_RAN_ExtIEs( SI_E1AP_DT_PDU_DRB_Setup_Mod_Item_NG_RAN_ExtIEs ** pDRB_Setup_Mod_Item_NG_RAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_Setup_Mod_Item_NG_RAN_ExtIEs * obj_DRB_Setup_Mod_Item_NG_RAN_ExtIEs = (SI_E1AP_DT_PDU_DRB_Setup_Mod_Item_NG_RAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_Setup_Mod_Item_NG_RAN_ExtIEs));
	memset( obj_DRB_Setup_Mod_Item_NG_RAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_Setup_Mod_Item_NG_RAN_ExtIEs));


	*pDRB_Setup_Mod_Item_NG_RAN_ExtIEs = obj_DRB_Setup_Mod_Item_NG_RAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_Status_ItemExtIEs( SI_E1AP_DT_PDU_DRB_Status_ItemExtIEs ** pDRB_Status_ItemExtIEs)
{
	SI_E1AP_DT_PDU_DRB_Status_ItemExtIEs * obj_DRB_Status_ItemExtIEs = (SI_E1AP_DT_PDU_DRB_Status_ItemExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_Status_ItemExtIEs));
	memset( obj_DRB_Status_ItemExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_Status_ItemExtIEs));


	*pDRB_Status_ItemExtIEs = obj_DRB_Status_ItemExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRBs_Subject_To_Counter_Check_Item_EUTRAN_ExtIEs( SI_E1AP_DT_PDU_DRBs_Subject_To_Counter_Check_Item_EUTRAN_ExtIEs ** pDRBs_Subject_To_Counter_Check_Item_EUTRAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRBs_Subject_To_Counter_Check_Item_EUTRAN_ExtIEs * obj_DRBs_Subject_To_Counter_Check_Item_EUTRAN_ExtIEs = (SI_E1AP_DT_PDU_DRBs_Subject_To_Counter_Check_Item_EUTRAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRBs_Subject_To_Counter_Check_Item_EUTRAN_ExtIEs));
	memset( obj_DRBs_Subject_To_Counter_Check_Item_EUTRAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRBs_Subject_To_Counter_Check_Item_EUTRAN_ExtIEs));


	*pDRBs_Subject_To_Counter_Check_Item_EUTRAN_ExtIEs = obj_DRBs_Subject_To_Counter_Check_Item_EUTRAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRBs_Subject_To_Counter_Check_Item_NG_RAN_ExtIEs( SI_E1AP_DT_PDU_DRBs_Subject_To_Counter_Check_Item_NG_RAN_ExtIEs ** pDRBs_Subject_To_Counter_Check_Item_NG_RAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRBs_Subject_To_Counter_Check_Item_NG_RAN_ExtIEs * obj_DRBs_Subject_To_Counter_Check_Item_NG_RAN_ExtIEs = (SI_E1AP_DT_PDU_DRBs_Subject_To_Counter_Check_Item_NG_RAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRBs_Subject_To_Counter_Check_Item_NG_RAN_ExtIEs));
	memset( obj_DRBs_Subject_To_Counter_Check_Item_NG_RAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRBs_Subject_To_Counter_Check_Item_NG_RAN_ExtIEs));


	*pDRBs_Subject_To_Counter_Check_Item_NG_RAN_ExtIEs = obj_DRBs_Subject_To_Counter_Check_Item_NG_RAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRBs_Subject_To_Early_Forwarding_Item_ExtIEs( SI_E1AP_DT_PDU_DRBs_Subject_To_Early_Forwarding_Item_ExtIEs ** pDRBs_Subject_To_Early_Forwarding_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_DRBs_Subject_To_Early_Forwarding_Item_ExtIEs * obj_DRBs_Subject_To_Early_Forwarding_Item_ExtIEs = (SI_E1AP_DT_PDU_DRBs_Subject_To_Early_Forwarding_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRBs_Subject_To_Early_Forwarding_Item_ExtIEs));
	memset( obj_DRBs_Subject_To_Early_Forwarding_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRBs_Subject_To_Early_Forwarding_Item_ExtIEs));


	*pDRBs_Subject_To_Early_Forwarding_Item_ExtIEs = obj_DRBs_Subject_To_Early_Forwarding_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_To_Modify_Item_EUTRAN_ExtIEs( SI_E1AP_DT_PDU_DRB_To_Modify_Item_EUTRAN_ExtIEs ** pDRB_To_Modify_Item_EUTRAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_To_Modify_Item_EUTRAN_ExtIEs * obj_DRB_To_Modify_Item_EUTRAN_ExtIEs = (SI_E1AP_DT_PDU_DRB_To_Modify_Item_EUTRAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_To_Modify_Item_EUTRAN_ExtIEs));
	memset( obj_DRB_To_Modify_Item_EUTRAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_To_Modify_Item_EUTRAN_ExtIEs));


	*pDRB_To_Modify_Item_EUTRAN_ExtIEs = obj_DRB_To_Modify_Item_EUTRAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_To_Modify_Item_NG_RAN_ExtIEs( SI_E1AP_DT_PDU_DRB_To_Modify_Item_NG_RAN_ExtIEs ** pDRB_To_Modify_Item_NG_RAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_To_Modify_Item_NG_RAN_ExtIEs * obj_DRB_To_Modify_Item_NG_RAN_ExtIEs = (SI_E1AP_DT_PDU_DRB_To_Modify_Item_NG_RAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_To_Modify_Item_NG_RAN_ExtIEs));
	memset( obj_DRB_To_Modify_Item_NG_RAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_To_Modify_Item_NG_RAN_ExtIEs));

	// QoS-Flow-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__QoS_Flow_List( &obj_DRB_To_Modify_Item_NG_RAN_ExtIEs->oldQoSFlowMapULendmarkerexpected);
	obj_DRB_To_Modify_Item_NG_RAN_ExtIEs->oldQoSFlowMapULendmarkerexpected_isset = 1;


	// QoSFlowLevelQoSParameters , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__QoSFlowLevelQoSParameters( &obj_DRB_To_Modify_Item_NG_RAN_ExtIEs->dRBQoS);
	obj_DRB_To_Modify_Item_NG_RAN_ExtIEs->dRBQoS_isset = 1;


	// EarlyForwardingCOUNTReq , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_DRB_To_Modify_Item_NG_RAN_ExtIEs->earlyForwardingCOUNTReq = EarlyForwardingCOUNTReq_first_dl_count_val;
	obj_DRB_To_Modify_Item_NG_RAN_ExtIEs->earlyForwardingCOUNTReq_isset = 1;


	// EarlyForwardingCOUNTInfo , PRESENCE = optional   CHOICE
	__si_e1ap__set_testdata__EarlyForwardingCOUNTInfo( &obj_DRB_To_Modify_Item_NG_RAN_ExtIEs->earlyForwardingCOUNTInfo);
	obj_DRB_To_Modify_Item_NG_RAN_ExtIEs->earlyForwardingCOUNTInfo->SelectedChoice = EarlyForwardingCOUNTInfo_firstDLCount_val;

	switch( obj_DRB_To_Modify_Item_NG_RAN_ExtIEs->earlyForwardingCOUNTInfo->SelectedChoice)
	{
		case EarlyForwardingCOUNTInfo_firstDLCount_val:
			__si_e1ap__set_testdata__FirstDLCount( &obj_DRB_To_Modify_Item_NG_RAN_ExtIEs->earlyForwardingCOUNTInfo->u.firstDLCount); //   L:11384
			break;
		case EarlyForwardingCOUNTInfo_dLDiscardingCount_val:
			__si_e1ap__set_testdata__DLDiscarding( &obj_DRB_To_Modify_Item_NG_RAN_ExtIEs->earlyForwardingCOUNTInfo->u.dLDiscardingCount); //   L:11384
			break;
		case EarlyForwardingCOUNTInfo_choice_Extension_val:  // L:11477
			{
				__si_e1ap__set_testdata__PDU_EarlyForwardingCOUNTInfo_ExtIEs( &obj_DRB_To_Modify_Item_NG_RAN_ExtIEs->earlyForwardingCOUNTInfo->u.choice_Extension);   // L:11497
			}
			break;
		default:
			break;
	}

	obj_DRB_To_Modify_Item_NG_RAN_ExtIEs->earlyForwardingCOUNTInfo_isset = 1;


	// DAPSRequestInfo , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__DAPSRequestInfo( &obj_DRB_To_Modify_Item_NG_RAN_ExtIEs->dAPSRequestInfo);
	obj_DRB_To_Modify_Item_NG_RAN_ExtIEs->dAPSRequestInfo_isset = 1;


	// EarlyDataForwardingIndicator , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_DRB_To_Modify_Item_NG_RAN_ExtIEs->earlyDataForwardingIndicator = EarlyDataForwardingIndicator_stop_val;
	obj_DRB_To_Modify_Item_NG_RAN_ExtIEs->earlyDataForwardingIndicator_isset = 1;


	// SDTindicatorMod , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_DRB_To_Modify_Item_NG_RAN_ExtIEs->sDTindicatorMod = SDTindicatorMod_true_val;
	obj_DRB_To_Modify_Item_NG_RAN_ExtIEs->sDTindicatorMod_isset = 1;


	// PDCP-COUNT-Reset , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_DRB_To_Modify_Item_NG_RAN_ExtIEs->pDCPCOUNTReset = PDCP_COUNT_Reset_true_val;
	obj_DRB_To_Modify_Item_NG_RAN_ExtIEs->pDCPCOUNTReset_isset = 1;



	*pDRB_To_Modify_Item_NG_RAN_ExtIEs = obj_DRB_To_Modify_Item_NG_RAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_To_Remove_Item_EUTRAN_ExtIEs( SI_E1AP_DT_PDU_DRB_To_Remove_Item_EUTRAN_ExtIEs ** pDRB_To_Remove_Item_EUTRAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_To_Remove_Item_EUTRAN_ExtIEs * obj_DRB_To_Remove_Item_EUTRAN_ExtIEs = (SI_E1AP_DT_PDU_DRB_To_Remove_Item_EUTRAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_To_Remove_Item_EUTRAN_ExtIEs));
	memset( obj_DRB_To_Remove_Item_EUTRAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_To_Remove_Item_EUTRAN_ExtIEs));


	*pDRB_To_Remove_Item_EUTRAN_ExtIEs = obj_DRB_To_Remove_Item_EUTRAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_Required_To_Remove_Item_EUTRAN_ExtIEs( SI_E1AP_DT_PDU_DRB_Required_To_Remove_Item_EUTRAN_ExtIEs ** pDRB_Required_To_Remove_Item_EUTRAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_Required_To_Remove_Item_EUTRAN_ExtIEs * obj_DRB_Required_To_Remove_Item_EUTRAN_ExtIEs = (SI_E1AP_DT_PDU_DRB_Required_To_Remove_Item_EUTRAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_Required_To_Remove_Item_EUTRAN_ExtIEs));
	memset( obj_DRB_Required_To_Remove_Item_EUTRAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_Required_To_Remove_Item_EUTRAN_ExtIEs));


	*pDRB_Required_To_Remove_Item_EUTRAN_ExtIEs = obj_DRB_Required_To_Remove_Item_EUTRAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_To_Remove_Item_NG_RAN_ExtIEs( SI_E1AP_DT_PDU_DRB_To_Remove_Item_NG_RAN_ExtIEs ** pDRB_To_Remove_Item_NG_RAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_To_Remove_Item_NG_RAN_ExtIEs * obj_DRB_To_Remove_Item_NG_RAN_ExtIEs = (SI_E1AP_DT_PDU_DRB_To_Remove_Item_NG_RAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_To_Remove_Item_NG_RAN_ExtIEs));
	memset( obj_DRB_To_Remove_Item_NG_RAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_To_Remove_Item_NG_RAN_ExtIEs));


	*pDRB_To_Remove_Item_NG_RAN_ExtIEs = obj_DRB_To_Remove_Item_NG_RAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_Required_To_Remove_Item_NG_RAN_ExtIEs( SI_E1AP_DT_PDU_DRB_Required_To_Remove_Item_NG_RAN_ExtIEs ** pDRB_Required_To_Remove_Item_NG_RAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_Required_To_Remove_Item_NG_RAN_ExtIEs * obj_DRB_Required_To_Remove_Item_NG_RAN_ExtIEs = (SI_E1AP_DT_PDU_DRB_Required_To_Remove_Item_NG_RAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_Required_To_Remove_Item_NG_RAN_ExtIEs));
	memset( obj_DRB_Required_To_Remove_Item_NG_RAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_Required_To_Remove_Item_NG_RAN_ExtIEs));


	*pDRB_Required_To_Remove_Item_NG_RAN_ExtIEs = obj_DRB_Required_To_Remove_Item_NG_RAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_To_Setup_Item_EUTRAN_ExtIEs( SI_E1AP_DT_PDU_DRB_To_Setup_Item_EUTRAN_ExtIEs ** pDRB_To_Setup_Item_EUTRAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_To_Setup_Item_EUTRAN_ExtIEs * obj_DRB_To_Setup_Item_EUTRAN_ExtIEs = (SI_E1AP_DT_PDU_DRB_To_Setup_Item_EUTRAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_To_Setup_Item_EUTRAN_ExtIEs));
	memset( obj_DRB_To_Setup_Item_EUTRAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_To_Setup_Item_EUTRAN_ExtIEs));

	// TransportLayerAddress  , PRESENCE = optional   BITSTRING , MIN=1, MAX=160
	__si_e1ap_init_TransportLayerAddress2( &obj_DRB_To_Setup_Item_EUTRAN_ExtIEs->dataForwardingSourceIPAddress, "3", 1, 1);
	obj_DRB_To_Setup_Item_EUTRAN_ExtIEs->dataForwardingSourceIPAddress->bitslen = 1;
	obj_DRB_To_Setup_Item_EUTRAN_ExtIEs->dataForwardingSourceIPAddress_isset = 1;


	// SecurityIndication , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__SecurityIndication( &obj_DRB_To_Setup_Item_EUTRAN_ExtIEs->securityIndication);
	obj_DRB_To_Setup_Item_EUTRAN_ExtIEs->securityIndication_isset = 1;



	*pDRB_To_Setup_Item_EUTRAN_ExtIEs = obj_DRB_To_Setup_Item_EUTRAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_To_Setup_Mod_Item_EUTRAN_ExtIEs( SI_E1AP_DT_PDU_DRB_To_Setup_Mod_Item_EUTRAN_ExtIEs ** pDRB_To_Setup_Mod_Item_EUTRAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_To_Setup_Mod_Item_EUTRAN_ExtIEs * obj_DRB_To_Setup_Mod_Item_EUTRAN_ExtIEs = (SI_E1AP_DT_PDU_DRB_To_Setup_Mod_Item_EUTRAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_To_Setup_Mod_Item_EUTRAN_ExtIEs));
	memset( obj_DRB_To_Setup_Mod_Item_EUTRAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_To_Setup_Mod_Item_EUTRAN_ExtIEs));

	// SecurityIndication , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__SecurityIndication( &obj_DRB_To_Setup_Mod_Item_EUTRAN_ExtIEs->securityIndication);
	obj_DRB_To_Setup_Mod_Item_EUTRAN_ExtIEs->securityIndication_isset = 1;


	// TransportLayerAddress  , PRESENCE = optional   BITSTRING , MIN=1, MAX=160
	__si_e1ap_init_TransportLayerAddress2( &obj_DRB_To_Setup_Mod_Item_EUTRAN_ExtIEs->dataForwardingSourceIPAddress, "8", 1, 1);
	obj_DRB_To_Setup_Mod_Item_EUTRAN_ExtIEs->dataForwardingSourceIPAddress->bitslen = 1;
	obj_DRB_To_Setup_Mod_Item_EUTRAN_ExtIEs->dataForwardingSourceIPAddress_isset = 1;



	*pDRB_To_Setup_Mod_Item_EUTRAN_ExtIEs = obj_DRB_To_Setup_Mod_Item_EUTRAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_To_Setup_Item_NG_RAN_ExtIEs( SI_E1AP_DT_PDU_DRB_To_Setup_Item_NG_RAN_ExtIEs ** pDRB_To_Setup_Item_NG_RAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_To_Setup_Item_NG_RAN_ExtIEs * obj_DRB_To_Setup_Item_NG_RAN_ExtIEs = (SI_E1AP_DT_PDU_DRB_To_Setup_Item_NG_RAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_To_Setup_Item_NG_RAN_ExtIEs));
	memset( obj_DRB_To_Setup_Item_NG_RAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_To_Setup_Item_NG_RAN_ExtIEs));

	// QoSFlowLevelQoSParameters , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__QoSFlowLevelQoSParameters( &obj_DRB_To_Setup_Item_NG_RAN_ExtIEs->dRBQoS);
	obj_DRB_To_Setup_Item_NG_RAN_ExtIEs->dRBQoS_isset = 1;


	// DAPSRequestInfo , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__DAPSRequestInfo( &obj_DRB_To_Setup_Item_NG_RAN_ExtIEs->dAPSRequestInfo);
	obj_DRB_To_Setup_Item_NG_RAN_ExtIEs->dAPSRequestInfo_isset = 1;


	// IgnoreMappingRuleIndication , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_DRB_To_Setup_Item_NG_RAN_ExtIEs->ignoreMappingRuleIndication = IgnoreMappingRuleIndication_true_val;
	obj_DRB_To_Setup_Item_NG_RAN_ExtIEs->ignoreMappingRuleIndication_isset = 1;


	// QoS-Flows-DRB-Remapping , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_DRB_To_Setup_Item_NG_RAN_ExtIEs->qoSFlowsDRBRemapping = QoS_Flows_DRB_Remapping_update_val;
	obj_DRB_To_Setup_Item_NG_RAN_ExtIEs->qoSFlowsDRBRemapping_isset = 1;


	// SDTindicatorSetup , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_DRB_To_Setup_Item_NG_RAN_ExtIEs->sDTindicatorSetup = SDTindicatorSetup_true_val;
	obj_DRB_To_Setup_Item_NG_RAN_ExtIEs->sDTindicatorSetup_isset = 1;


	// SpecialTriggeringPurpose , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_DRB_To_Setup_Item_NG_RAN_ExtIEs->specialTriggeringPurpose = SpecialTriggeringPurpose_indirect_data_forwarding_val;
	obj_DRB_To_Setup_Item_NG_RAN_ExtIEs->specialTriggeringPurpose_isset = 1;



	*pDRB_To_Setup_Item_NG_RAN_ExtIEs = obj_DRB_To_Setup_Item_NG_RAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_To_Setup_Mod_Item_NG_RAN_ExtIEs( SI_E1AP_DT_PDU_DRB_To_Setup_Mod_Item_NG_RAN_ExtIEs ** pDRB_To_Setup_Mod_Item_NG_RAN_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_To_Setup_Mod_Item_NG_RAN_ExtIEs * obj_DRB_To_Setup_Mod_Item_NG_RAN_ExtIEs = (SI_E1AP_DT_PDU_DRB_To_Setup_Mod_Item_NG_RAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_To_Setup_Mod_Item_NG_RAN_ExtIEs));
	memset( obj_DRB_To_Setup_Mod_Item_NG_RAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_To_Setup_Mod_Item_NG_RAN_ExtIEs));

	// QoSFlowLevelQoSParameters , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__QoSFlowLevelQoSParameters( &obj_DRB_To_Setup_Mod_Item_NG_RAN_ExtIEs->dRBQoS);
	obj_DRB_To_Setup_Mod_Item_NG_RAN_ExtIEs->dRBQoS_isset = 1;


	// IgnoreMappingRuleIndication , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_DRB_To_Setup_Mod_Item_NG_RAN_ExtIEs->ignoreMappingRuleIndication = IgnoreMappingRuleIndication_true_val;
	obj_DRB_To_Setup_Mod_Item_NG_RAN_ExtIEs->ignoreMappingRuleIndication_isset = 1;


	// DAPSRequestInfo , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__DAPSRequestInfo( &obj_DRB_To_Setup_Mod_Item_NG_RAN_ExtIEs->dAPSRequestInfo);
	obj_DRB_To_Setup_Mod_Item_NG_RAN_ExtIEs->dAPSRequestInfo_isset = 1;


	// SDTindicatorSetup , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_DRB_To_Setup_Mod_Item_NG_RAN_ExtIEs->sDTindicatorSetup = SDTindicatorSetup_true_val;
	obj_DRB_To_Setup_Mod_Item_NG_RAN_ExtIEs->sDTindicatorSetup_isset = 1;


	// SpecialTriggeringPurpose , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_DRB_To_Setup_Mod_Item_NG_RAN_ExtIEs->specialTriggeringPurpose = SpecialTriggeringPurpose_indirect_data_forwarding_val;
	obj_DRB_To_Setup_Mod_Item_NG_RAN_ExtIEs->specialTriggeringPurpose_isset = 1;



	*pDRB_To_Setup_Mod_Item_NG_RAN_ExtIEs = obj_DRB_To_Setup_Mod_Item_NG_RAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRB_Usage_Report_Item_ExtIEs( SI_E1AP_DT_PDU_DRB_Usage_Report_Item_ExtIEs ** pDRB_Usage_Report_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_DRB_Usage_Report_Item_ExtIEs * obj_DRB_Usage_Report_Item_ExtIEs = (SI_E1AP_DT_PDU_DRB_Usage_Report_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRB_Usage_Report_Item_ExtIEs));
	memset( obj_DRB_Usage_Report_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRB_Usage_Report_Item_ExtIEs));


	*pDRB_Usage_Report_Item_ExtIEs = obj_DRB_Usage_Report_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_Dynamic5QIDescriptor_ExtIEs( SI_E1AP_DT_PDU_Dynamic5QIDescriptor_ExtIEs ** pDynamic5QIDescriptor_ExtIEs)
{
	SI_E1AP_DT_PDU_Dynamic5QIDescriptor_ExtIEs * obj_Dynamic5QIDescriptor_ExtIEs = (SI_E1AP_DT_PDU_Dynamic5QIDescriptor_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Dynamic5QIDescriptor_ExtIEs));
	memset( obj_Dynamic5QIDescriptor_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_Dynamic5QIDescriptor_ExtIEs));

	// ExtendedPacketDelayBudget , PRESENCE = optional  INTEGER , MIN=1, MAX=65535
	obj_Dynamic5QIDescriptor_ExtIEs->extendedPacketDelayBudget = __getTestINTEGER( 1, 65535);
	obj_Dynamic5QIDescriptor_ExtIEs->extendedPacketDelayBudget_isset = 1;


	// ExtendedPacketDelayBudget , PRESENCE = optional  INTEGER , MIN=1, MAX=65535
	obj_Dynamic5QIDescriptor_ExtIEs->cNPacketDelayBudgetDownlink = __getTestINTEGER( 1, 65535);
	obj_Dynamic5QIDescriptor_ExtIEs->cNPacketDelayBudgetDownlink_isset = 1;


	// ExtendedPacketDelayBudget , PRESENCE = optional  INTEGER , MIN=1, MAX=65535
	obj_Dynamic5QIDescriptor_ExtIEs->cNPacketDelayBudgetUplink = __getTestINTEGER( 1, 65535);
	obj_Dynamic5QIDescriptor_ExtIEs->cNPacketDelayBudgetUplink_isset = 1;



	*pDynamic5QIDescriptor_ExtIEs = obj_Dynamic5QIDescriptor_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_EarlyForwardingCOUNTInfo_ExtIEs( SI_E1AP_DT_PDU_EarlyForwardingCOUNTInfo_ExtIEs ** pEarlyForwardingCOUNTInfo_ExtIEs)
{
	SI_E1AP_DT_PDU_EarlyForwardingCOUNTInfo_ExtIEs * obj_EarlyForwardingCOUNTInfo_ExtIEs = (SI_E1AP_DT_PDU_EarlyForwardingCOUNTInfo_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_EarlyForwardingCOUNTInfo_ExtIEs));
	memset( obj_EarlyForwardingCOUNTInfo_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_EarlyForwardingCOUNTInfo_ExtIEs));


	*pEarlyForwardingCOUNTInfo_ExtIEs = obj_EarlyForwardingCOUNTInfo_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_ECNMarkingorCongestionInformationReportingRequest_ExtIEs( SI_E1AP_DT_PDU_ECNMarkingorCongestionInformationReportingRequest_ExtIEs ** pECNMarkingorCongestionInformationReportingRequest_ExtIEs)
{
	SI_E1AP_DT_PDU_ECNMarkingorCongestionInformationReportingRequest_ExtIEs * obj_ECNMarkingorCongestionInformationReportingRequest_ExtIEs = (SI_E1AP_DT_PDU_ECNMarkingorCongestionInformationReportingRequest_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_ECNMarkingorCongestionInformationReportingRequest_ExtIEs));
	memset( obj_ECNMarkingorCongestionInformationReportingRequest_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_ECNMarkingorCongestionInformationReportingRequest_ExtIEs));


	*pECNMarkingorCongestionInformationReportingRequest_ExtIEs = obj_ECNMarkingorCongestionInformationReportingRequest_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_EHC_Common_Parameters_ExtIEs( SI_E1AP_DT_PDU_EHC_Common_Parameters_ExtIEs ** pEHC_Common_Parameters_ExtIEs)
{
	SI_E1AP_DT_PDU_EHC_Common_Parameters_ExtIEs * obj_EHC_Common_Parameters_ExtIEs = (SI_E1AP_DT_PDU_EHC_Common_Parameters_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_EHC_Common_Parameters_ExtIEs));
	memset( obj_EHC_Common_Parameters_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_EHC_Common_Parameters_ExtIEs));


	*pEHC_Common_Parameters_ExtIEs = obj_EHC_Common_Parameters_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_EHC_Downlink_Parameters_ExtIEs( SI_E1AP_DT_PDU_EHC_Downlink_Parameters_ExtIEs ** pEHC_Downlink_Parameters_ExtIEs)
{
	SI_E1AP_DT_PDU_EHC_Downlink_Parameters_ExtIEs * obj_EHC_Downlink_Parameters_ExtIEs = (SI_E1AP_DT_PDU_EHC_Downlink_Parameters_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_EHC_Downlink_Parameters_ExtIEs));
	memset( obj_EHC_Downlink_Parameters_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_EHC_Downlink_Parameters_ExtIEs));

	// MaxCIDEHCDL , PRESENCE = optional  INTEGER , MIN=1, MAX=32767
	obj_EHC_Downlink_Parameters_ExtIEs->maxCIDEHCDL = __getTestINTEGER( 1, 32767);
	obj_EHC_Downlink_Parameters_ExtIEs->maxCIDEHCDL_isset = 1;



	*pEHC_Downlink_Parameters_ExtIEs = obj_EHC_Downlink_Parameters_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_EHC_Uplink_Parameters_ExtIEs( SI_E1AP_DT_PDU_EHC_Uplink_Parameters_ExtIEs ** pEHC_Uplink_Parameters_ExtIEs)
{
	SI_E1AP_DT_PDU_EHC_Uplink_Parameters_ExtIEs * obj_EHC_Uplink_Parameters_ExtIEs = (SI_E1AP_DT_PDU_EHC_Uplink_Parameters_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_EHC_Uplink_Parameters_ExtIEs));
	memset( obj_EHC_Uplink_Parameters_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_EHC_Uplink_Parameters_ExtIEs));


	*pEHC_Uplink_Parameters_ExtIEs = obj_EHC_Uplink_Parameters_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_EHC_Parameters_ExtIEs( SI_E1AP_DT_PDU_EHC_Parameters_ExtIEs ** pEHC_Parameters_ExtIEs)
{
	SI_E1AP_DT_PDU_EHC_Parameters_ExtIEs * obj_EHC_Parameters_ExtIEs = (SI_E1AP_DT_PDU_EHC_Parameters_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_EHC_Parameters_ExtIEs));
	memset( obj_EHC_Parameters_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_EHC_Parameters_ExtIEs));


	*pEHC_Parameters_ExtIEs = obj_EHC_Parameters_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_Endpoint_IP_address_and_port_ExtIEs( SI_E1AP_DT_PDU_Endpoint_IP_address_and_port_ExtIEs ** pEndpoint_IP_address_and_port_ExtIEs)
{
	SI_E1AP_DT_PDU_Endpoint_IP_address_and_port_ExtIEs * obj_Endpoint_IP_address_and_port_ExtIEs = (SI_E1AP_DT_PDU_Endpoint_IP_address_and_port_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Endpoint_IP_address_and_port_ExtIEs));
	memset( obj_Endpoint_IP_address_and_port_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_Endpoint_IP_address_and_port_ExtIEs));


	*pEndpoint_IP_address_and_port_ExtIEs = obj_Endpoint_IP_address_and_port_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_EUTRANAllocationAndRetentionPriority_ExtIEs( SI_E1AP_DT_PDU_EUTRANAllocationAndRetentionPriority_ExtIEs ** pEUTRANAllocationAndRetentionPriority_ExtIEs)
{
	SI_E1AP_DT_PDU_EUTRANAllocationAndRetentionPriority_ExtIEs * obj_EUTRANAllocationAndRetentionPriority_ExtIEs = (SI_E1AP_DT_PDU_EUTRANAllocationAndRetentionPriority_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_EUTRANAllocationAndRetentionPriority_ExtIEs));
	memset( obj_EUTRANAllocationAndRetentionPriority_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_EUTRANAllocationAndRetentionPriority_ExtIEs));


	*pEUTRANAllocationAndRetentionPriority_ExtIEs = obj_EUTRANAllocationAndRetentionPriority_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_ECGI_ExtIEs( SI_E1AP_DT_PDU_ECGI_ExtIEs ** pECGI_ExtIEs)
{
	SI_E1AP_DT_PDU_ECGI_ExtIEs * obj_ECGI_ExtIEs = (SI_E1AP_DT_PDU_ECGI_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_ECGI_ExtIEs));
	memset( obj_ECGI_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_ECGI_ExtIEs));


	*pECGI_ExtIEs = obj_ECGI_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_ECGI_Support_Item_ExtIEs( SI_E1AP_DT_PDU_ECGI_Support_Item_ExtIEs ** pECGI_Support_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_ECGI_Support_Item_ExtIEs * obj_ECGI_Support_Item_ExtIEs = (SI_E1AP_DT_PDU_ECGI_Support_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_ECGI_Support_Item_ExtIEs));
	memset( obj_ECGI_Support_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_ECGI_Support_Item_ExtIEs));


	*pECGI_Support_Item_ExtIEs = obj_ECGI_Support_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_EUTRAN_QoS_Support_Item_ExtIEs( SI_E1AP_DT_PDU_EUTRAN_QoS_Support_Item_ExtIEs ** pEUTRAN_QoS_Support_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_EUTRAN_QoS_Support_Item_ExtIEs * obj_EUTRAN_QoS_Support_Item_ExtIEs = (SI_E1AP_DT_PDU_EUTRAN_QoS_Support_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_EUTRAN_QoS_Support_Item_ExtIEs));
	memset( obj_EUTRAN_QoS_Support_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_EUTRAN_QoS_Support_Item_ExtIEs));


	*pEUTRAN_QoS_Support_Item_ExtIEs = obj_EUTRAN_QoS_Support_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_EUTRAN_QoS_ExtIEs( SI_E1AP_DT_PDU_EUTRAN_QoS_ExtIEs ** pEUTRAN_QoS_ExtIEs)
{
	SI_E1AP_DT_PDU_EUTRAN_QoS_ExtIEs * obj_EUTRAN_QoS_ExtIEs = (SI_E1AP_DT_PDU_EUTRAN_QoS_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_EUTRAN_QoS_ExtIEs));
	memset( obj_EUTRAN_QoS_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_EUTRAN_QoS_ExtIEs));


	*pEUTRAN_QoS_ExtIEs = obj_EUTRAN_QoS_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_FirstDLCount_ExtIEs( SI_E1AP_DT_PDU_FirstDLCount_ExtIEs ** pFirstDLCount_ExtIEs)
{
	SI_E1AP_DT_PDU_FirstDLCount_ExtIEs * obj_FirstDLCount_ExtIEs = (SI_E1AP_DT_PDU_FirstDLCount_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_FirstDLCount_ExtIEs));
	memset( obj_FirstDLCount_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_FirstDLCount_ExtIEs));


	*pFirstDLCount_ExtIEs = obj_FirstDLCount_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_F1U_TNL_InfoAdded_Item_ExtIEs( SI_E1AP_DT_PDU_F1U_TNL_InfoAdded_Item_ExtIEs ** pF1U_TNL_InfoAdded_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_F1U_TNL_InfoAdded_Item_ExtIEs * obj_F1U_TNL_InfoAdded_Item_ExtIEs = (SI_E1AP_DT_PDU_F1U_TNL_InfoAdded_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_F1U_TNL_InfoAdded_Item_ExtIEs));
	memset( obj_F1U_TNL_InfoAdded_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_F1U_TNL_InfoAdded_Item_ExtIEs));


	*pF1U_TNL_InfoAdded_Item_ExtIEs = obj_F1U_TNL_InfoAdded_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_F1U_TNL_InfoToAdd_Item_ExtIEs( SI_E1AP_DT_PDU_F1U_TNL_InfoToAdd_Item_ExtIEs ** pF1U_TNL_InfoToAdd_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_F1U_TNL_InfoToAdd_Item_ExtIEs * obj_F1U_TNL_InfoToAdd_Item_ExtIEs = (SI_E1AP_DT_PDU_F1U_TNL_InfoToAdd_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_F1U_TNL_InfoToAdd_Item_ExtIEs));
	memset( obj_F1U_TNL_InfoToAdd_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_F1U_TNL_InfoToAdd_Item_ExtIEs));


	*pF1U_TNL_InfoToAdd_Item_ExtIEs = obj_F1U_TNL_InfoToAdd_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_F1U_TNL_InfoAddedOrModified_Item_ExtIEs( SI_E1AP_DT_PDU_F1U_TNL_InfoAddedOrModified_Item_ExtIEs ** pF1U_TNL_InfoAddedOrModified_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_F1U_TNL_InfoAddedOrModified_Item_ExtIEs * obj_F1U_TNL_InfoAddedOrModified_Item_ExtIEs = (SI_E1AP_DT_PDU_F1U_TNL_InfoAddedOrModified_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_F1U_TNL_InfoAddedOrModified_Item_ExtIEs));
	memset( obj_F1U_TNL_InfoAddedOrModified_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_F1U_TNL_InfoAddedOrModified_Item_ExtIEs));


	*pF1U_TNL_InfoAddedOrModified_Item_ExtIEs = obj_F1U_TNL_InfoAddedOrModified_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_F1U_TNL_InfoToAddOrModify_Item_ExtIEs( SI_E1AP_DT_PDU_F1U_TNL_InfoToAddOrModify_Item_ExtIEs ** pF1U_TNL_InfoToAddOrModify_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_F1U_TNL_InfoToAddOrModify_Item_ExtIEs * obj_F1U_TNL_InfoToAddOrModify_Item_ExtIEs = (SI_E1AP_DT_PDU_F1U_TNL_InfoToAddOrModify_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_F1U_TNL_InfoToAddOrModify_Item_ExtIEs));
	memset( obj_F1U_TNL_InfoToAddOrModify_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_F1U_TNL_InfoToAddOrModify_Item_ExtIEs));


	*pF1U_TNL_InfoToAddOrModify_Item_ExtIEs = obj_F1U_TNL_InfoToAddOrModify_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_F1U_TNL_InfoToRelease_Item_ExtIEs( SI_E1AP_DT_PDU_F1U_TNL_InfoToRelease_Item_ExtIEs ** pF1U_TNL_InfoToRelease_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_F1U_TNL_InfoToRelease_Item_ExtIEs * obj_F1U_TNL_InfoToRelease_Item_ExtIEs = (SI_E1AP_DT_PDU_F1U_TNL_InfoToRelease_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_F1U_TNL_InfoToRelease_Item_ExtIEs));
	memset( obj_F1U_TNL_InfoToRelease_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_F1U_TNL_InfoToRelease_Item_ExtIEs));


	*pF1U_TNL_InfoToRelease_Item_ExtIEs = obj_F1U_TNL_InfoToRelease_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_GlobalMBSSessionID_ExtIEs( SI_E1AP_DT_PDU_GlobalMBSSessionID_ExtIEs ** pGlobalMBSSessionID_ExtIEs)
{
	SI_E1AP_DT_PDU_GlobalMBSSessionID_ExtIEs * obj_GlobalMBSSessionID_ExtIEs = (SI_E1AP_DT_PDU_GlobalMBSSessionID_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GlobalMBSSessionID_ExtIEs));
	memset( obj_GlobalMBSSessionID_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_GlobalMBSSessionID_ExtIEs));


	*pGlobalMBSSessionID_ExtIEs = obj_GlobalMBSSessionID_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_Extended_GNB_CU_CP_Name_ExtIEs( SI_E1AP_DT_PDU_Extended_GNB_CU_CP_Name_ExtIEs ** pExtended_GNB_CU_CP_Name_ExtIEs)
{
	SI_E1AP_DT_PDU_Extended_GNB_CU_CP_Name_ExtIEs * obj_Extended_GNB_CU_CP_Name_ExtIEs = (SI_E1AP_DT_PDU_Extended_GNB_CU_CP_Name_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Extended_GNB_CU_CP_Name_ExtIEs));
	memset( obj_Extended_GNB_CU_CP_Name_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_Extended_GNB_CU_CP_Name_ExtIEs));


	*pExtended_GNB_CU_CP_Name_ExtIEs = obj_Extended_GNB_CU_CP_Name_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_GNB_CU_UP_CellGroupRelatedConfiguration_Item_ExtIEs( SI_E1AP_DT_PDU_GNB_CU_UP_CellGroupRelatedConfiguration_Item_ExtIEs ** pGNB_CU_UP_CellGroupRelatedConfiguration_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_GNB_CU_UP_CellGroupRelatedConfiguration_Item_ExtIEs * obj_GNB_CU_UP_CellGroupRelatedConfiguration_Item_ExtIEs = (SI_E1AP_DT_PDU_GNB_CU_UP_CellGroupRelatedConfiguration_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GNB_CU_UP_CellGroupRelatedConfiguration_Item_ExtIEs));
	memset( obj_GNB_CU_UP_CellGroupRelatedConfiguration_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_GNB_CU_UP_CellGroupRelatedConfiguration_Item_ExtIEs));


	*pGNB_CU_UP_CellGroupRelatedConfiguration_Item_ExtIEs = obj_GNB_CU_UP_CellGroupRelatedConfiguration_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_GNB_CU_UP_MBS_Support_Info_ExtIEs( SI_E1AP_DT_PDU_GNB_CU_UP_MBS_Support_Info_ExtIEs ** pGNB_CU_UP_MBS_Support_Info_ExtIEs)
{
	SI_E1AP_DT_PDU_GNB_CU_UP_MBS_Support_Info_ExtIEs * obj_GNB_CU_UP_MBS_Support_Info_ExtIEs = (SI_E1AP_DT_PDU_GNB_CU_UP_MBS_Support_Info_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GNB_CU_UP_MBS_Support_Info_ExtIEs));
	memset( obj_GNB_CU_UP_MBS_Support_Info_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_GNB_CU_UP_MBS_Support_Info_ExtIEs));


	*pGNB_CU_UP_MBS_Support_Info_ExtIEs = obj_GNB_CU_UP_MBS_Support_Info_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_Extended_GNB_CU_UP_Name_ExtIEs( SI_E1AP_DT_PDU_Extended_GNB_CU_UP_Name_ExtIEs ** pExtended_GNB_CU_UP_Name_ExtIEs)
{
	SI_E1AP_DT_PDU_Extended_GNB_CU_UP_Name_ExtIEs * obj_Extended_GNB_CU_UP_Name_ExtIEs = (SI_E1AP_DT_PDU_Extended_GNB_CU_UP_Name_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Extended_GNB_CU_UP_Name_ExtIEs));
	memset( obj_Extended_GNB_CU_UP_Name_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_Extended_GNB_CU_UP_Name_ExtIEs));


	*pExtended_GNB_CU_UP_Name_ExtIEs = obj_Extended_GNB_CU_UP_Name_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_GNB_CU_CP_TNLA_Setup_Item_ExtIEs( SI_E1AP_DT_PDU_GNB_CU_CP_TNLA_Setup_Item_ExtIEs ** pGNB_CU_CP_TNLA_Setup_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_GNB_CU_CP_TNLA_Setup_Item_ExtIEs * obj_GNB_CU_CP_TNLA_Setup_Item_ExtIEs = (SI_E1AP_DT_PDU_GNB_CU_CP_TNLA_Setup_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GNB_CU_CP_TNLA_Setup_Item_ExtIEs));
	memset( obj_GNB_CU_CP_TNLA_Setup_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_GNB_CU_CP_TNLA_Setup_Item_ExtIEs));


	*pGNB_CU_CP_TNLA_Setup_Item_ExtIEs = obj_GNB_CU_CP_TNLA_Setup_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_GNB_CU_CP_TNLA_Failed_To_Setup_Item_ExtIEs( SI_E1AP_DT_PDU_GNB_CU_CP_TNLA_Failed_To_Setup_Item_ExtIEs ** pGNB_CU_CP_TNLA_Failed_To_Setup_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_GNB_CU_CP_TNLA_Failed_To_Setup_Item_ExtIEs * obj_GNB_CU_CP_TNLA_Failed_To_Setup_Item_ExtIEs = (SI_E1AP_DT_PDU_GNB_CU_CP_TNLA_Failed_To_Setup_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GNB_CU_CP_TNLA_Failed_To_Setup_Item_ExtIEs));
	memset( obj_GNB_CU_CP_TNLA_Failed_To_Setup_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_GNB_CU_CP_TNLA_Failed_To_Setup_Item_ExtIEs));


	*pGNB_CU_CP_TNLA_Failed_To_Setup_Item_ExtIEs = obj_GNB_CU_CP_TNLA_Failed_To_Setup_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_GNB_CU_CP_TNLA_To_Add_Item_ExtIEs( SI_E1AP_DT_PDU_GNB_CU_CP_TNLA_To_Add_Item_ExtIEs ** pGNB_CU_CP_TNLA_To_Add_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_GNB_CU_CP_TNLA_To_Add_Item_ExtIEs * obj_GNB_CU_CP_TNLA_To_Add_Item_ExtIEs = (SI_E1AP_DT_PDU_GNB_CU_CP_TNLA_To_Add_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GNB_CU_CP_TNLA_To_Add_Item_ExtIEs));
	memset( obj_GNB_CU_CP_TNLA_To_Add_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_GNB_CU_CP_TNLA_To_Add_Item_ExtIEs));


	*pGNB_CU_CP_TNLA_To_Add_Item_ExtIEs = obj_GNB_CU_CP_TNLA_To_Add_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_GNB_CU_CP_TNLA_To_Remove_Item_ExtIEs( SI_E1AP_DT_PDU_GNB_CU_CP_TNLA_To_Remove_Item_ExtIEs ** pGNB_CU_CP_TNLA_To_Remove_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_GNB_CU_CP_TNLA_To_Remove_Item_ExtIEs * obj_GNB_CU_CP_TNLA_To_Remove_Item_ExtIEs = (SI_E1AP_DT_PDU_GNB_CU_CP_TNLA_To_Remove_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GNB_CU_CP_TNLA_To_Remove_Item_ExtIEs));
	memset( obj_GNB_CU_CP_TNLA_To_Remove_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_GNB_CU_CP_TNLA_To_Remove_Item_ExtIEs));

	// CP-TNL-Information , PRESENCE = optional   CHOICE
	__si_e1ap__set_testdata__CP_TNL_Information( &obj_GNB_CU_CP_TNLA_To_Remove_Item_ExtIEs->tNLAssociationTransportLayerAddressgNBCUUP);
	obj_GNB_CU_CP_TNLA_To_Remove_Item_ExtIEs->tNLAssociationTransportLayerAddressgNBCUUP->SelectedChoice = CP_TNL_Information_endpoint_IP_Address_val;

	switch( obj_GNB_CU_CP_TNLA_To_Remove_Item_ExtIEs->tNLAssociationTransportLayerAddressgNBCUUP->SelectedChoice)
	{
		case CP_TNL_Information_endpoint_IP_Address_val:
			// TransportLayerAddress     CHOICE , MIN=1, MAX=160
			{
				__si_e1ap_init_TransportLayerAddress2( &obj_GNB_CU_CP_TNLA_To_Remove_Item_ExtIEs->tNLAssociationTransportLayerAddressgNBCUUP->u.endpoint_IP_Address, "3", 1, 1);  // L:11445
				obj_GNB_CU_CP_TNLA_To_Remove_Item_ExtIEs->tNLAssociationTransportLayerAddressgNBCUUP->u.endpoint_IP_Address->bitslen = 1; //   L:11448
			}
			break;
		case CP_TNL_Information_choice_extension_val:  // L:11477
			{
				__si_e1ap__set_testdata__PDU_CP_TNL_Information_ExtIEs( &obj_GNB_CU_CP_TNLA_To_Remove_Item_ExtIEs->tNLAssociationTransportLayerAddressgNBCUUP->u.choice_extension);   // L:11497
			}
			break;
		default:
			break;
	}

	obj_GNB_CU_CP_TNLA_To_Remove_Item_ExtIEs->tNLAssociationTransportLayerAddressgNBCUUP_isset = 1;



	*pGNB_CU_CP_TNLA_To_Remove_Item_ExtIEs = obj_GNB_CU_CP_TNLA_To_Remove_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_GNB_CU_CP_TNLA_To_Update_Item_ExtIEs( SI_E1AP_DT_PDU_GNB_CU_CP_TNLA_To_Update_Item_ExtIEs ** pGNB_CU_CP_TNLA_To_Update_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_GNB_CU_CP_TNLA_To_Update_Item_ExtIEs * obj_GNB_CU_CP_TNLA_To_Update_Item_ExtIEs = (SI_E1AP_DT_PDU_GNB_CU_CP_TNLA_To_Update_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GNB_CU_CP_TNLA_To_Update_Item_ExtIEs));
	memset( obj_GNB_CU_CP_TNLA_To_Update_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_GNB_CU_CP_TNLA_To_Update_Item_ExtIEs));


	*pGNB_CU_CP_TNLA_To_Update_Item_ExtIEs = obj_GNB_CU_CP_TNLA_To_Update_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_GNB_CU_UP_TNLA_To_Remove_Item_ExtIEs( SI_E1AP_DT_PDU_GNB_CU_UP_TNLA_To_Remove_Item_ExtIEs ** pGNB_CU_UP_TNLA_To_Remove_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_GNB_CU_UP_TNLA_To_Remove_Item_ExtIEs * obj_GNB_CU_UP_TNLA_To_Remove_Item_ExtIEs = (SI_E1AP_DT_PDU_GNB_CU_UP_TNLA_To_Remove_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GNB_CU_UP_TNLA_To_Remove_Item_ExtIEs));
	memset( obj_GNB_CU_UP_TNLA_To_Remove_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_GNB_CU_UP_TNLA_To_Remove_Item_ExtIEs));


	*pGNB_CU_UP_TNLA_To_Remove_Item_ExtIEs = obj_GNB_CU_UP_TNLA_To_Remove_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_GBR_QosInformation_ExtIEs( SI_E1AP_DT_PDU_GBR_QosInformation_ExtIEs ** pGBR_QosInformation_ExtIEs)
{
	SI_E1AP_DT_PDU_GBR_QosInformation_ExtIEs * obj_GBR_QosInformation_ExtIEs = (SI_E1AP_DT_PDU_GBR_QosInformation_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GBR_QosInformation_ExtIEs));
	memset( obj_GBR_QosInformation_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_GBR_QosInformation_ExtIEs));


	*pGBR_QosInformation_ExtIEs = obj_GBR_QosInformation_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_GBR_QosFlowInformation_ExtIEs( SI_E1AP_DT_PDU_GBR_QosFlowInformation_ExtIEs ** pGBR_QosFlowInformation_ExtIEs)
{
	SI_E1AP_DT_PDU_GBR_QosFlowInformation_ExtIEs * obj_GBR_QosFlowInformation_ExtIEs = (SI_E1AP_DT_PDU_GBR_QosFlowInformation_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GBR_QosFlowInformation_ExtIEs));
	memset( obj_GBR_QosFlowInformation_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_GBR_QosFlowInformation_ExtIEs));

	// AlternativeQoSParaSetList , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__AlternativeQoSParaSetList( &obj_GBR_QosFlowInformation_ExtIEs->alternativeQoSParaSetList);
	obj_GBR_QosFlowInformation_ExtIEs->alternativeQoSParaSetList_isset = 1;



	*pGBR_QosFlowInformation_ExtIEs = obj_GBR_QosFlowInformation_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_GTPTLA_Item_ExtIEs( SI_E1AP_DT_PDU_GTPTLA_Item_ExtIEs ** pGTPTLA_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_GTPTLA_Item_ExtIEs * obj_GTPTLA_Item_ExtIEs = (SI_E1AP_DT_PDU_GTPTLA_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GTPTLA_Item_ExtIEs));
	memset( obj_GTPTLA_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_GTPTLA_Item_ExtIEs));


	*pGTPTLA_Item_ExtIEs = obj_GTPTLA_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_GTPTunnel_ExtIEs( SI_E1AP_DT_PDU_GTPTunnel_ExtIEs ** pGTPTunnel_ExtIEs)
{
	SI_E1AP_DT_PDU_GTPTunnel_ExtIEs * obj_GTPTunnel_ExtIEs = (SI_E1AP_DT_PDU_GTPTunnel_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GTPTunnel_ExtIEs));
	memset( obj_GTPTunnel_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_GTPTunnel_ExtIEs));


	*pGTPTunnel_ExtIEs = obj_GTPTunnel_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_HW_CapacityIndicator_ExtIEs( SI_E1AP_DT_PDU_HW_CapacityIndicator_ExtIEs ** pHW_CapacityIndicator_ExtIEs)
{
	SI_E1AP_DT_PDU_HW_CapacityIndicator_ExtIEs * obj_HW_CapacityIndicator_ExtIEs = (SI_E1AP_DT_PDU_HW_CapacityIndicator_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_HW_CapacityIndicator_ExtIEs));
	memset( obj_HW_CapacityIndicator_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_HW_CapacityIndicator_ExtIEs));


	*pHW_CapacityIndicator_ExtIEs = obj_HW_CapacityIndicator_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_ImmediateMDT_ExtIEs( SI_E1AP_DT_PDU_ImmediateMDT_ExtIEs ** pImmediateMDT_ExtIEs)
{
	SI_E1AP_DT_PDU_ImmediateMDT_ExtIEs * obj_ImmediateMDT_ExtIEs = (SI_E1AP_DT_PDU_ImmediateMDT_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_ImmediateMDT_ExtIEs));
	memset( obj_ImmediateMDT_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_ImmediateMDT_ExtIEs));


	*pImmediateMDT_ExtIEs = obj_ImmediateMDT_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_IAB_donor_CU_UPPSKInfoItemExtIEs( SI_E1AP_DT_PDU_IAB_donor_CU_UPPSKInfoItemExtIEs ** pIAB_donor_CU_UPPSKInfoItemExtIEs)
{
	SI_E1AP_DT_PDU_IAB_donor_CU_UPPSKInfoItemExtIEs * obj_IAB_donor_CU_UPPSKInfoItemExtIEs = (SI_E1AP_DT_PDU_IAB_donor_CU_UPPSKInfoItemExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_IAB_donor_CU_UPPSKInfoItemExtIEs));
	memset( obj_IAB_donor_CU_UPPSKInfoItemExtIEs, 0, sizeof( SI_E1AP_DT_PDU_IAB_donor_CU_UPPSKInfoItemExtIEs));


	*pIAB_donor_CU_UPPSKInfoItemExtIEs = obj_IAB_donor_CU_UPPSKInfoItemExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_LocationDependentMBSNGUInformationAt5GC_Item_ExtIEs( SI_E1AP_DT_PDU_LocationDependentMBSNGUInformationAt5GC_Item_ExtIEs ** pLocationDependentMBSNGUInformationAt5GC_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_LocationDependentMBSNGUInformationAt5GC_Item_ExtIEs * obj_LocationDependentMBSNGUInformationAt5GC_Item_ExtIEs = (SI_E1AP_DT_PDU_LocationDependentMBSNGUInformationAt5GC_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_LocationDependentMBSNGUInformationAt5GC_Item_ExtIEs));
	memset( obj_LocationDependentMBSNGUInformationAt5GC_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_LocationDependentMBSNGUInformationAt5GC_Item_ExtIEs));


	*pLocationDependentMBSNGUInformationAt5GC_Item_ExtIEs = obj_LocationDependentMBSNGUInformationAt5GC_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_LocationDependentMBSF1UInformationAtCU_Item_ExtIEs( SI_E1AP_DT_PDU_LocationDependentMBSF1UInformationAtCU_Item_ExtIEs ** pLocationDependentMBSF1UInformationAtCU_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_LocationDependentMBSF1UInformationAtCU_Item_ExtIEs * obj_LocationDependentMBSF1UInformationAtCU_Item_ExtIEs = (SI_E1AP_DT_PDU_LocationDependentMBSF1UInformationAtCU_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_LocationDependentMBSF1UInformationAtCU_Item_ExtIEs));
	memset( obj_LocationDependentMBSF1UInformationAtCU_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_LocationDependentMBSF1UInformationAtCU_Item_ExtIEs));


	*pLocationDependentMBSF1UInformationAtCU_Item_ExtIEs = obj_LocationDependentMBSF1UInformationAtCU_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_LocationDependentMBSF1UInformationAtDU_Item_ExtIEs( SI_E1AP_DT_PDU_LocationDependentMBSF1UInformationAtDU_Item_ExtIEs ** pLocationDependentMBSF1UInformationAtDU_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_LocationDependentMBSF1UInformationAtDU_Item_ExtIEs * obj_LocationDependentMBSF1UInformationAtDU_Item_ExtIEs = (SI_E1AP_DT_PDU_LocationDependentMBSF1UInformationAtDU_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_LocationDependentMBSF1UInformationAtDU_Item_ExtIEs));
	memset( obj_LocationDependentMBSF1UInformationAtDU_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_LocationDependentMBSF1UInformationAtDU_Item_ExtIEs));

	// F1UTunnelNotEstablished, PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_LocationDependentMBSF1UInformationAtDU_Item_ExtIEs->f1UTunnelNotEstablished = F1UTunnelNotEstablished_true_val;
	obj_LocationDependentMBSF1UInformationAtDU_Item_ExtIEs->f1UTunnelNotEstablished_isset = 1;



	*pLocationDependentMBSF1UInformationAtDU_Item_ExtIEs = obj_LocationDependentMBSF1UInformationAtDU_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_LocationDependentMBSNGUInformationAtNGRAN_Item_ExtIEs( SI_E1AP_DT_PDU_LocationDependentMBSNGUInformationAtNGRAN_Item_ExtIEs ** pLocationDependentMBSNGUInformationAtNGRAN_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_LocationDependentMBSNGUInformationAtNGRAN_Item_ExtIEs * obj_LocationDependentMBSNGUInformationAtNGRAN_Item_ExtIEs = (SI_E1AP_DT_PDU_LocationDependentMBSNGUInformationAtNGRAN_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_LocationDependentMBSNGUInformationAtNGRAN_Item_ExtIEs));
	memset( obj_LocationDependentMBSNGUInformationAtNGRAN_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_LocationDependentMBSNGUInformationAtNGRAN_Item_ExtIEs));


	*pLocationDependentMBSNGUInformationAtNGRAN_Item_ExtIEs = obj_LocationDependentMBSNGUInformationAtNGRAN_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MaximumIPdatarate_ExtIEs( SI_E1AP_DT_PDU_MaximumIPdatarate_ExtIEs ** pMaximumIPdatarate_ExtIEs)
{
	SI_E1AP_DT_PDU_MaximumIPdatarate_ExtIEs * obj_MaximumIPdatarate_ExtIEs = (SI_E1AP_DT_PDU_MaximumIPdatarate_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MaximumIPdatarate_ExtIEs));
	memset( obj_MaximumIPdatarate_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MaximumIPdatarate_ExtIEs));


	*pMaximumIPdatarate_ExtIEs = obj_MaximumIPdatarate_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MBSF1UInformationAtCU_ExtIEs( SI_E1AP_DT_PDU_MBSF1UInformationAtCU_ExtIEs ** pMBSF1UInformationAtCU_ExtIEs)
{
	SI_E1AP_DT_PDU_MBSF1UInformationAtCU_ExtIEs * obj_MBSF1UInformationAtCU_ExtIEs = (SI_E1AP_DT_PDU_MBSF1UInformationAtCU_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MBSF1UInformationAtCU_ExtIEs));
	memset( obj_MBSF1UInformationAtCU_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MBSF1UInformationAtCU_ExtIEs));


	*pMBSF1UInformationAtCU_ExtIEs = obj_MBSF1UInformationAtCU_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MBSF1UInformationAtDU_ExtIEs( SI_E1AP_DT_PDU_MBSF1UInformationAtDU_ExtIEs ** pMBSF1UInformationAtDU_ExtIEs)
{
	SI_E1AP_DT_PDU_MBSF1UInformationAtDU_ExtIEs * obj_MBSF1UInformationAtDU_ExtIEs = (SI_E1AP_DT_PDU_MBSF1UInformationAtDU_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MBSF1UInformationAtDU_ExtIEs));
	memset( obj_MBSF1UInformationAtDU_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MBSF1UInformationAtDU_ExtIEs));

	// F1UTunnelNotEstablished, PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_MBSF1UInformationAtDU_ExtIEs->f1UTunnelNotEstablished = F1UTunnelNotEstablished_true_val;
	obj_MBSF1UInformationAtDU_ExtIEs->f1UTunnelNotEstablished_isset = 1;



	*pMBSF1UInformationAtDU_ExtIEs = obj_MBSF1UInformationAtDU_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MBSNGUInformationAt5GC_ExtIEs( SI_E1AP_DT_PDU_MBSNGUInformationAt5GC_ExtIEs ** pMBSNGUInformationAt5GC_ExtIEs)
{
	SI_E1AP_DT_PDU_MBSNGUInformationAt5GC_ExtIEs * obj_MBSNGUInformationAt5GC_ExtIEs = (SI_E1AP_DT_PDU_MBSNGUInformationAt5GC_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MBSNGUInformationAt5GC_ExtIEs));
	memset( obj_MBSNGUInformationAt5GC_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MBSNGUInformationAt5GC_ExtIEs));


	*pMBSNGUInformationAt5GC_ExtIEs = obj_MBSNGUInformationAt5GC_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MBSNGUInformationAt5GC_Multicast_ExtIEs( SI_E1AP_DT_PDU_MBSNGUInformationAt5GC_Multicast_ExtIEs ** pMBSNGUInformationAt5GC_Multicast_ExtIEs)
{
	SI_E1AP_DT_PDU_MBSNGUInformationAt5GC_Multicast_ExtIEs * obj_MBSNGUInformationAt5GC_Multicast_ExtIEs = (SI_E1AP_DT_PDU_MBSNGUInformationAt5GC_Multicast_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MBSNGUInformationAt5GC_Multicast_ExtIEs));
	memset( obj_MBSNGUInformationAt5GC_Multicast_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MBSNGUInformationAt5GC_Multicast_ExtIEs));


	*pMBSNGUInformationAt5GC_Multicast_ExtIEs = obj_MBSNGUInformationAt5GC_Multicast_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MBSNGUInformationAtNGRAN_ExtIEs( SI_E1AP_DT_PDU_MBSNGUInformationAtNGRAN_ExtIEs ** pMBSNGUInformationAtNGRAN_ExtIEs)
{
	SI_E1AP_DT_PDU_MBSNGUInformationAtNGRAN_ExtIEs * obj_MBSNGUInformationAtNGRAN_ExtIEs = (SI_E1AP_DT_PDU_MBSNGUInformationAtNGRAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MBSNGUInformationAtNGRAN_ExtIEs));
	memset( obj_MBSNGUInformationAtNGRAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MBSNGUInformationAtNGRAN_ExtIEs));


	*pMBSNGUInformationAtNGRAN_ExtIEs = obj_MBSNGUInformationAtNGRAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MBSNGUInformationAtNGRAN_Request_Item_ExtIEs( SI_E1AP_DT_PDU_MBSNGUInformationAtNGRAN_Request_Item_ExtIEs ** pMBSNGUInformationAtNGRAN_Request_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_MBSNGUInformationAtNGRAN_Request_Item_ExtIEs * obj_MBSNGUInformationAtNGRAN_Request_Item_ExtIEs = (SI_E1AP_DT_PDU_MBSNGUInformationAtNGRAN_Request_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MBSNGUInformationAtNGRAN_Request_Item_ExtIEs));
	memset( obj_MBSNGUInformationAtNGRAN_Request_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MBSNGUInformationAtNGRAN_Request_Item_ExtIEs));


	*pMBSNGUInformationAtNGRAN_Request_Item_ExtIEs = obj_MBSNGUInformationAtNGRAN_Request_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MBSSessionAssociatedInfoNonSupportToSupport_ExtIEs( SI_E1AP_DT_PDU_MBSSessionAssociatedInfoNonSupportToSupport_ExtIEs ** pMBSSessionAssociatedInfoNonSupportToSupport_ExtIEs)
{
	SI_E1AP_DT_PDU_MBSSessionAssociatedInfoNonSupportToSupport_ExtIEs * obj_MBSSessionAssociatedInfoNonSupportToSupport_ExtIEs = (SI_E1AP_DT_PDU_MBSSessionAssociatedInfoNonSupportToSupport_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MBSSessionAssociatedInfoNonSupportToSupport_ExtIEs));
	memset( obj_MBSSessionAssociatedInfoNonSupportToSupport_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MBSSessionAssociatedInfoNonSupportToSupport_ExtIEs));


	*pMBSSessionAssociatedInfoNonSupportToSupport_ExtIEs = obj_MBSSessionAssociatedInfoNonSupportToSupport_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MBSSessionAssociatedInformation_ExtIEs( SI_E1AP_DT_PDU_MBSSessionAssociatedInformation_ExtIEs ** pMBSSessionAssociatedInformation_ExtIEs)
{
	SI_E1AP_DT_PDU_MBSSessionAssociatedInformation_ExtIEs * obj_MBSSessionAssociatedInformation_ExtIEs = (SI_E1AP_DT_PDU_MBSSessionAssociatedInformation_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MBSSessionAssociatedInformation_ExtIEs));
	memset( obj_MBSSessionAssociatedInformation_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MBSSessionAssociatedInformation_ExtIEs));


	*pMBSSessionAssociatedInformation_ExtIEs = obj_MBSSessionAssociatedInformation_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MBSSessionAssociatedInformation_Item_ExtIEs( SI_E1AP_DT_PDU_MBSSessionAssociatedInformation_Item_ExtIEs ** pMBSSessionAssociatedInformation_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_MBSSessionAssociatedInformation_Item_ExtIEs * obj_MBSSessionAssociatedInformation_Item_ExtIEs = (SI_E1AP_DT_PDU_MBSSessionAssociatedInformation_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MBSSessionAssociatedInformation_Item_ExtIEs));
	memset( obj_MBSSessionAssociatedInformation_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MBSSessionAssociatedInformation_Item_ExtIEs));


	*pMBSSessionAssociatedInformation_Item_ExtIEs = obj_MBSSessionAssociatedInformation_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MBS_Support_Info_ToAdd_Item_ExtIEs( SI_E1AP_DT_PDU_MBS_Support_Info_ToAdd_Item_ExtIEs ** pMBS_Support_Info_ToAdd_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_MBS_Support_Info_ToAdd_Item_ExtIEs * obj_MBS_Support_Info_ToAdd_Item_ExtIEs = (SI_E1AP_DT_PDU_MBS_Support_Info_ToAdd_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MBS_Support_Info_ToAdd_Item_ExtIEs));
	memset( obj_MBS_Support_Info_ToAdd_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MBS_Support_Info_ToAdd_Item_ExtIEs));


	*pMBS_Support_Info_ToAdd_Item_ExtIEs = obj_MBS_Support_Info_ToAdd_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MBSSessionResourceNotification_ExtIEs( SI_E1AP_DT_PDU_MBSSessionResourceNotification_ExtIEs ** pMBSSessionResourceNotification_ExtIEs)
{
	SI_E1AP_DT_PDU_MBSSessionResourceNotification_ExtIEs * obj_MBSSessionResourceNotification_ExtIEs = (SI_E1AP_DT_PDU_MBSSessionResourceNotification_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MBSSessionResourceNotification_ExtIEs));
	memset( obj_MBSSessionResourceNotification_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MBSSessionResourceNotification_ExtIEs));


	*pMBSSessionResourceNotification_ExtIEs = obj_MBSSessionResourceNotification_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MBS_DL_Data_Arrival_ExtIEs( SI_E1AP_DT_PDU_MBS_DL_Data_Arrival_ExtIEs ** pMBS_DL_Data_Arrival_ExtIEs)
{
	SI_E1AP_DT_PDU_MBS_DL_Data_Arrival_ExtIEs * obj_MBS_DL_Data_Arrival_ExtIEs = (SI_E1AP_DT_PDU_MBS_DL_Data_Arrival_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MBS_DL_Data_Arrival_ExtIEs));
	memset( obj_MBS_DL_Data_Arrival_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MBS_DL_Data_Arrival_ExtIEs));


	*pMBS_DL_Data_Arrival_ExtIEs = obj_MBS_DL_Data_Arrival_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MCBearerContext_Inactivity_ExtIEs( SI_E1AP_DT_PDU_MCBearerContext_Inactivity_ExtIEs ** pMCBearerContext_Inactivity_ExtIEs)
{
	SI_E1AP_DT_PDU_MCBearerContext_Inactivity_ExtIEs * obj_MCBearerContext_Inactivity_ExtIEs = (SI_E1AP_DT_PDU_MCBearerContext_Inactivity_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCBearerContext_Inactivity_ExtIEs));
	memset( obj_MCBearerContext_Inactivity_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MCBearerContext_Inactivity_ExtIEs));


	*pMCBearerContext_Inactivity_ExtIEs = obj_MCBearerContext_Inactivity_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MBS_Support_Info_ToRemove_Item_ExtIEs( SI_E1AP_DT_PDU_MBS_Support_Info_ToRemove_Item_ExtIEs ** pMBS_Support_Info_ToRemove_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_MBS_Support_Info_ToRemove_Item_ExtIEs * obj_MBS_Support_Info_ToRemove_Item_ExtIEs = (SI_E1AP_DT_PDU_MBS_Support_Info_ToRemove_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MBS_Support_Info_ToRemove_Item_ExtIEs));
	memset( obj_MBS_Support_Info_ToRemove_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MBS_Support_Info_ToRemove_Item_ExtIEs));


	*pMBS_Support_Info_ToRemove_Item_ExtIEs = obj_MBS_Support_Info_ToRemove_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MCBearerContextToSetup_ExtIEs( SI_E1AP_DT_PDU_MCBearerContextToSetup_ExtIEs ** pMCBearerContextToSetup_ExtIEs)
{
	SI_E1AP_DT_PDU_MCBearerContextToSetup_ExtIEs * obj_MCBearerContextToSetup_ExtIEs = (SI_E1AP_DT_PDU_MCBearerContextToSetup_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCBearerContextToSetup_ExtIEs));
	memset( obj_MCBearerContextToSetup_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MCBearerContextToSetup_ExtIEs));

	// MBSSessionAssociatedInfoNonSupportToSupport , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__MBSSessionAssociatedInfoNonSupportToSupport( &obj_MCBearerContextToSetup_ExtIEs->mBSSessionAssociatedInfoNonSupportToSupport);
	obj_MCBearerContextToSetup_ExtIEs->mBSSessionAssociatedInfoNonSupportToSupport_isset = 1;


	// MBSAreaSessionID , PRESENCE = optional  INTEGER , MIN=0, MAX=65535
	obj_MCBearerContextToSetup_ExtIEs->mBSAreaSessionID = __getTestINTEGER( 0, 65535);
	obj_MCBearerContextToSetup_ExtIEs->mBSAreaSessionID_isset = 1;


	// Inactivity-Timer , PRESENCE = optional  INTEGER , MIN=1, MAX=7200
	obj_MCBearerContextToSetup_ExtIEs->mCBearerContextInactivityTimer = __getTestINTEGER( 1, 7200);
	obj_MCBearerContextToSetup_ExtIEs->mCBearerContextInactivityTimer_isset = 1;


	// MCBearerContextStatusChange , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_MCBearerContextToSetup_ExtIEs->mCBearerContextStatusChange = MCBearerContextStatusChange_suspend_val;
	obj_MCBearerContextToSetup_ExtIEs->mCBearerContextStatusChange_isset = 1;



	*pMCBearerContextToSetup_ExtIEs = obj_MCBearerContextToSetup_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MCMRBSetupConfiguration_Item_ExtIEs( SI_E1AP_DT_PDU_MCMRBSetupConfiguration_Item_ExtIEs ** pMCMRBSetupConfiguration_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_MCMRBSetupConfiguration_Item_ExtIEs * obj_MCMRBSetupConfiguration_Item_ExtIEs = (SI_E1AP_DT_PDU_MCMRBSetupConfiguration_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCMRBSetupConfiguration_Item_ExtIEs));
	memset( obj_MCMRBSetupConfiguration_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MCMRBSetupConfiguration_Item_ExtIEs));


	*pMCMRBSetupConfiguration_Item_ExtIEs = obj_MCMRBSetupConfiguration_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MCBearerContextToSetupResponse_ExtIEs( SI_E1AP_DT_PDU_MCBearerContextToSetupResponse_ExtIEs ** pMCBearerContextToSetupResponse_ExtIEs)
{
	SI_E1AP_DT_PDU_MCBearerContextToSetupResponse_ExtIEs * obj_MCBearerContextToSetupResponse_ExtIEs = (SI_E1AP_DT_PDU_MCBearerContextToSetupResponse_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCBearerContextToSetupResponse_ExtIEs));
	memset( obj_MCBearerContextToSetupResponse_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MCBearerContextToSetupResponse_ExtIEs));


	*pMCBearerContextToSetupResponse_ExtIEs = obj_MCBearerContextToSetupResponse_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MCBearerContextNGU_TNLInfoatNGRAN_ExtIEs( SI_E1AP_DT_PDU_MCBearerContextNGU_TNLInfoatNGRAN_ExtIEs ** pMCBearerContextNGU_TNLInfoatNGRAN_ExtIEs)
{
	SI_E1AP_DT_PDU_MCBearerContextNGU_TNLInfoatNGRAN_ExtIEs * obj_MCBearerContextNGU_TNLInfoatNGRAN_ExtIEs = (SI_E1AP_DT_PDU_MCBearerContextNGU_TNLInfoatNGRAN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCBearerContextNGU_TNLInfoatNGRAN_ExtIEs));
	memset( obj_MCBearerContextNGU_TNLInfoatNGRAN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MCBearerContextNGU_TNLInfoatNGRAN_ExtIEs));


	*pMCBearerContextNGU_TNLInfoatNGRAN_ExtIEs = obj_MCBearerContextNGU_TNLInfoatNGRAN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MCMRBSetupResponseList_Item_ExtIEs( SI_E1AP_DT_PDU_MCMRBSetupResponseList_Item_ExtIEs ** pMCMRBSetupResponseList_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_MCMRBSetupResponseList_Item_ExtIEs * obj_MCMRBSetupResponseList_Item_ExtIEs = (SI_E1AP_DT_PDU_MCMRBSetupResponseList_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCMRBSetupResponseList_Item_ExtIEs));
	memset( obj_MCMRBSetupResponseList_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MCMRBSetupResponseList_Item_ExtIEs));


	*pMCMRBSetupResponseList_Item_ExtIEs = obj_MCMRBSetupResponseList_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MCMRBFailedList_Item_ExtIEs( SI_E1AP_DT_PDU_MCMRBFailedList_Item_ExtIEs ** pMCMRBFailedList_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_MCMRBFailedList_Item_ExtIEs * obj_MCMRBFailedList_Item_ExtIEs = (SI_E1AP_DT_PDU_MCMRBFailedList_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCMRBFailedList_Item_ExtIEs));
	memset( obj_MCMRBFailedList_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MCMRBFailedList_Item_ExtIEs));


	*pMCMRBFailedList_Item_ExtIEs = obj_MCMRBFailedList_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MCBearerContextToModify_ExtIEs( SI_E1AP_DT_PDU_MCBearerContextToModify_ExtIEs ** pMCBearerContextToModify_ExtIEs)
{
	SI_E1AP_DT_PDU_MCBearerContextToModify_ExtIEs * obj_MCBearerContextToModify_ExtIEs = (SI_E1AP_DT_PDU_MCBearerContextToModify_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCBearerContextToModify_ExtIEs));
	memset( obj_MCBearerContextToModify_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MCBearerContextToModify_ExtIEs));

	// MCForwardingResourceRequest , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__MCForwardingResourceRequest( &obj_MCBearerContextToModify_ExtIEs->mCForwardingResourceRequest);
	obj_MCBearerContextToModify_ExtIEs->mCForwardingResourceRequest_isset = 1;


	// MCForwardingResourceIndication , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__MCForwardingResourceIndication( &obj_MCBearerContextToModify_ExtIEs->mCForwardingResourceIndication);
	obj_MCBearerContextToModify_ExtIEs->mCForwardingResourceIndication_isset = 1;


	// MCForwardingResourceRelease , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__MCForwardingResourceRelease( &obj_MCBearerContextToModify_ExtIEs->mCForwardingResourceRelease);
	obj_MCBearerContextToModify_ExtIEs->mCForwardingResourceRelease_isset = 1;


	// MBSSessionAssociatedInfoNonSupportToSupport , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__MBSSessionAssociatedInfoNonSupportToSupport( &obj_MCBearerContextToModify_ExtIEs->mBSSessionAssociatedInfoNonSupportToSupport);
	obj_MCBearerContextToModify_ExtIEs->mBSSessionAssociatedInfoNonSupportToSupport_isset = 1;


	// Inactivity-Timer , PRESENCE = optional  INTEGER , MIN=1, MAX=7200
	obj_MCBearerContextToModify_ExtIEs->mCBearerContextInactivityTimer = __getTestINTEGER( 1, 7200);
	obj_MCBearerContextToModify_ExtIEs->mCBearerContextInactivityTimer_isset = 1;


	// MCBearerContextStatusChange , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_MCBearerContextToModify_ExtIEs->mCBearerContextStatusChange = MCBearerContextStatusChange_suspend_val;
	obj_MCBearerContextToModify_ExtIEs->mCBearerContextStatusChange_isset = 1;



	*pMCBearerContextToModify_ExtIEs = obj_MCBearerContextToModify_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MCBearerContextNGUTNLInfoat5GC_ExtIEs( SI_E1AP_DT_PDU_MCBearerContextNGUTNLInfoat5GC_ExtIEs ** pMCBearerContextNGUTNLInfoat5GC_ExtIEs)
{
	SI_E1AP_DT_PDU_MCBearerContextNGUTNLInfoat5GC_ExtIEs * obj_MCBearerContextNGUTNLInfoat5GC_ExtIEs = (SI_E1AP_DT_PDU_MCBearerContextNGUTNLInfoat5GC_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCBearerContextNGUTNLInfoat5GC_ExtIEs));
	memset( obj_MCBearerContextNGUTNLInfoat5GC_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MCBearerContextNGUTNLInfoat5GC_ExtIEs));


	*pMCBearerContextNGUTNLInfoat5GC_ExtIEs = obj_MCBearerContextNGUTNLInfoat5GC_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MCBearerContextNGUTnlInfoatNGRANRequest_ExtIEs( SI_E1AP_DT_PDU_MCBearerContextNGUTnlInfoatNGRANRequest_ExtIEs ** pMCBearerContextNGUTnlInfoatNGRANRequest_ExtIEs)
{
	SI_E1AP_DT_PDU_MCBearerContextNGUTnlInfoatNGRANRequest_ExtIEs * obj_MCBearerContextNGUTnlInfoatNGRANRequest_ExtIEs = (SI_E1AP_DT_PDU_MCBearerContextNGUTnlInfoatNGRANRequest_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCBearerContextNGUTnlInfoatNGRANRequest_ExtIEs));
	memset( obj_MCBearerContextNGUTnlInfoatNGRANRequest_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MCBearerContextNGUTnlInfoatNGRANRequest_ExtIEs));


	*pMCBearerContextNGUTnlInfoatNGRANRequest_ExtIEs = obj_MCBearerContextNGUTnlInfoatNGRANRequest_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MCMRBSetupModifyConfiguration_Item_ExtIEs( SI_E1AP_DT_PDU_MCMRBSetupModifyConfiguration_Item_ExtIEs ** pMCMRBSetupModifyConfiguration_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_MCMRBSetupModifyConfiguration_Item_ExtIEs * obj_MCMRBSetupModifyConfiguration_Item_ExtIEs = (SI_E1AP_DT_PDU_MCMRBSetupModifyConfiguration_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCMRBSetupModifyConfiguration_Item_ExtIEs));
	memset( obj_MCMRBSetupModifyConfiguration_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MCMRBSetupModifyConfiguration_Item_ExtIEs));


	*pMCMRBSetupModifyConfiguration_Item_ExtIEs = obj_MCMRBSetupModifyConfiguration_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MCBearerContextF1UTNLInfoatDU_ExtIEs( SI_E1AP_DT_PDU_MCBearerContextF1UTNLInfoatDU_ExtIEs ** pMCBearerContextF1UTNLInfoatDU_ExtIEs)
{
	SI_E1AP_DT_PDU_MCBearerContextF1UTNLInfoatDU_ExtIEs * obj_MCBearerContextF1UTNLInfoatDU_ExtIEs = (SI_E1AP_DT_PDU_MCBearerContextF1UTNLInfoatDU_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCBearerContextF1UTNLInfoatDU_ExtIEs));
	memset( obj_MCBearerContextF1UTNLInfoatDU_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MCBearerContextF1UTNLInfoatDU_ExtIEs));


	*pMCBearerContextF1UTNLInfoatDU_ExtIEs = obj_MCBearerContextF1UTNLInfoatDU_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MBSMulticastF1UContextDescriptor_ExtIEs( SI_E1AP_DT_PDU_MBSMulticastF1UContextDescriptor_ExtIEs ** pMBSMulticastF1UContextDescriptor_ExtIEs)
{
	SI_E1AP_DT_PDU_MBSMulticastF1UContextDescriptor_ExtIEs * obj_MBSMulticastF1UContextDescriptor_ExtIEs = (SI_E1AP_DT_PDU_MBSMulticastF1UContextDescriptor_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MBSMulticastF1UContextDescriptor_ExtIEs));
	memset( obj_MBSMulticastF1UContextDescriptor_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MBSMulticastF1UContextDescriptor_ExtIEs));


	*pMBSMulticastF1UContextDescriptor_ExtIEs = obj_MBSMulticastF1UContextDescriptor_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MCBearerContextToModifyResponse_ExtIEs( SI_E1AP_DT_PDU_MCBearerContextToModifyResponse_ExtIEs ** pMCBearerContextToModifyResponse_ExtIEs)
{
	SI_E1AP_DT_PDU_MCBearerContextToModifyResponse_ExtIEs * obj_MCBearerContextToModifyResponse_ExtIEs = (SI_E1AP_DT_PDU_MCBearerContextToModifyResponse_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCBearerContextToModifyResponse_ExtIEs));
	memset( obj_MCBearerContextToModifyResponse_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MCBearerContextToModifyResponse_ExtIEs));

	// MCForwardingResourceResponse , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__MCForwardingResourceResponse( &obj_MCBearerContextToModifyResponse_ExtIEs->mCForwardingResourceResponse);
	obj_MCBearerContextToModifyResponse_ExtIEs->mCForwardingResourceResponse_isset = 1;



	*pMCBearerContextToModifyResponse_ExtIEs = obj_MCBearerContextToModifyResponse_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MCBearerContextNGU_TNLInfoatNGRANModifyResponse_ExtIEs( SI_E1AP_DT_PDU_MCBearerContextNGU_TNLInfoatNGRANModifyResponse_ExtIEs ** pMCBearerContextNGU_TNLInfoatNGRANModifyResponse_ExtIEs)
{
	SI_E1AP_DT_PDU_MCBearerContextNGU_TNLInfoatNGRANModifyResponse_ExtIEs * obj_MCBearerContextNGU_TNLInfoatNGRANModifyResponse_ExtIEs = (SI_E1AP_DT_PDU_MCBearerContextNGU_TNLInfoatNGRANModifyResponse_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCBearerContextNGU_TNLInfoatNGRANModifyResponse_ExtIEs));
	memset( obj_MCBearerContextNGU_TNLInfoatNGRANModifyResponse_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MCBearerContextNGU_TNLInfoatNGRANModifyResponse_ExtIEs));


	*pMCBearerContextNGU_TNLInfoatNGRANModifyResponse_ExtIEs = obj_MCBearerContextNGU_TNLInfoatNGRANModifyResponse_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MCMRBSetupModifyResponseList_Item_ExtIEs( SI_E1AP_DT_PDU_MCMRBSetupModifyResponseList_Item_ExtIEs ** pMCMRBSetupModifyResponseList_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_MCMRBSetupModifyResponseList_Item_ExtIEs * obj_MCMRBSetupModifyResponseList_Item_ExtIEs = (SI_E1AP_DT_PDU_MCMRBSetupModifyResponseList_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCMRBSetupModifyResponseList_Item_ExtIEs));
	memset( obj_MCMRBSetupModifyResponseList_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MCMRBSetupModifyResponseList_Item_ExtIEs));


	*pMCMRBSetupModifyResponseList_Item_ExtIEs = obj_MCMRBSetupModifyResponseList_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MCBearerContextToModifyRequired_ExtIEs( SI_E1AP_DT_PDU_MCBearerContextToModifyRequired_ExtIEs ** pMCBearerContextToModifyRequired_ExtIEs)
{
	SI_E1AP_DT_PDU_MCBearerContextToModifyRequired_ExtIEs * obj_MCBearerContextToModifyRequired_ExtIEs = (SI_E1AP_DT_PDU_MCBearerContextToModifyRequired_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCBearerContextToModifyRequired_ExtIEs));
	memset( obj_MCBearerContextToModifyRequired_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MCBearerContextToModifyRequired_ExtIEs));

	// MCForwardingResourceReleaseIndication , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__MCForwardingResourceReleaseIndication( &obj_MCBearerContextToModifyRequired_ExtIEs->mCForwardingResourceReleaseIndication);
	obj_MCBearerContextToModifyRequired_ExtIEs->mCForwardingResourceReleaseIndication_isset = 1;



	*pMCBearerContextToModifyRequired_ExtIEs = obj_MCBearerContextToModifyRequired_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MCMRBModifyRequiredConfiguration_Item_ExtIEs( SI_E1AP_DT_PDU_MCMRBModifyRequiredConfiguration_Item_ExtIEs ** pMCMRBModifyRequiredConfiguration_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_MCMRBModifyRequiredConfiguration_Item_ExtIEs * obj_MCMRBModifyRequiredConfiguration_Item_ExtIEs = (SI_E1AP_DT_PDU_MCMRBModifyRequiredConfiguration_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCMRBModifyRequiredConfiguration_Item_ExtIEs));
	memset( obj_MCMRBModifyRequiredConfiguration_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MCMRBModifyRequiredConfiguration_Item_ExtIEs));


	*pMCMRBModifyRequiredConfiguration_Item_ExtIEs = obj_MCMRBModifyRequiredConfiguration_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MCMRBModifyConfirmList_Item_ExtIEs( SI_E1AP_DT_PDU_MCMRBModifyConfirmList_Item_ExtIEs ** pMCMRBModifyConfirmList_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_MCMRBModifyConfirmList_Item_ExtIEs * obj_MCMRBModifyConfirmList_Item_ExtIEs = (SI_E1AP_DT_PDU_MCMRBModifyConfirmList_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCMRBModifyConfirmList_Item_ExtIEs));
	memset( obj_MCMRBModifyConfirmList_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MCMRBModifyConfirmList_Item_ExtIEs));


	*pMCMRBModifyConfirmList_Item_ExtIEs = obj_MCMRBModifyConfirmList_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MCBearerContextToModifyConfirm_ExtIEs( SI_E1AP_DT_PDU_MCBearerContextToModifyConfirm_ExtIEs ** pMCBearerContextToModifyConfirm_ExtIEs)
{
	SI_E1AP_DT_PDU_MCBearerContextToModifyConfirm_ExtIEs * obj_MCBearerContextToModifyConfirm_ExtIEs = (SI_E1AP_DT_PDU_MCBearerContextToModifyConfirm_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCBearerContextToModifyConfirm_ExtIEs));
	memset( obj_MCBearerContextToModifyConfirm_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MCBearerContextToModifyConfirm_ExtIEs));


	*pMCBearerContextToModifyConfirm_ExtIEs = obj_MCBearerContextToModifyConfirm_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MCForwardingResourceRequest_ExtIEs( SI_E1AP_DT_PDU_MCForwardingResourceRequest_ExtIEs ** pMCForwardingResourceRequest_ExtIEs)
{
	SI_E1AP_DT_PDU_MCForwardingResourceRequest_ExtIEs * obj_MCForwardingResourceRequest_ExtIEs = (SI_E1AP_DT_PDU_MCForwardingResourceRequest_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCForwardingResourceRequest_ExtIEs));
	memset( obj_MCForwardingResourceRequest_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MCForwardingResourceRequest_ExtIEs));


	*pMCForwardingResourceRequest_ExtIEs = obj_MCForwardingResourceRequest_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MRBForwardingResourceRequest_Item_ExtIEs( SI_E1AP_DT_PDU_MRBForwardingResourceRequest_Item_ExtIEs ** pMRBForwardingResourceRequest_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_MRBForwardingResourceRequest_Item_ExtIEs * obj_MRBForwardingResourceRequest_Item_ExtIEs = (SI_E1AP_DT_PDU_MRBForwardingResourceRequest_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MRBForwardingResourceRequest_Item_ExtIEs));
	memset( obj_MRBForwardingResourceRequest_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MRBForwardingResourceRequest_Item_ExtIEs));


	*pMRBForwardingResourceRequest_Item_ExtIEs = obj_MRBForwardingResourceRequest_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MCForwardingResourceIndication_ExtIEs( SI_E1AP_DT_PDU_MCForwardingResourceIndication_ExtIEs ** pMCForwardingResourceIndication_ExtIEs)
{
	SI_E1AP_DT_PDU_MCForwardingResourceIndication_ExtIEs * obj_MCForwardingResourceIndication_ExtIEs = (SI_E1AP_DT_PDU_MCForwardingResourceIndication_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCForwardingResourceIndication_ExtIEs));
	memset( obj_MCForwardingResourceIndication_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MCForwardingResourceIndication_ExtIEs));


	*pMCForwardingResourceIndication_ExtIEs = obj_MCForwardingResourceIndication_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MRBForwardingResourceIndication_Item_ExtIEs( SI_E1AP_DT_PDU_MRBForwardingResourceIndication_Item_ExtIEs ** pMRBForwardingResourceIndication_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_MRBForwardingResourceIndication_Item_ExtIEs * obj_MRBForwardingResourceIndication_Item_ExtIEs = (SI_E1AP_DT_PDU_MRBForwardingResourceIndication_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MRBForwardingResourceIndication_Item_ExtIEs));
	memset( obj_MRBForwardingResourceIndication_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MRBForwardingResourceIndication_Item_ExtIEs));


	*pMRBForwardingResourceIndication_Item_ExtIEs = obj_MRBForwardingResourceIndication_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MCForwardingResourceResponse_ExtIEs( SI_E1AP_DT_PDU_MCForwardingResourceResponse_ExtIEs ** pMCForwardingResourceResponse_ExtIEs)
{
	SI_E1AP_DT_PDU_MCForwardingResourceResponse_ExtIEs * obj_MCForwardingResourceResponse_ExtIEs = (SI_E1AP_DT_PDU_MCForwardingResourceResponse_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCForwardingResourceResponse_ExtIEs));
	memset( obj_MCForwardingResourceResponse_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MCForwardingResourceResponse_ExtIEs));


	*pMCForwardingResourceResponse_ExtIEs = obj_MCForwardingResourceResponse_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MRBForwardingResourceResponse_Item_ExtIEs( SI_E1AP_DT_PDU_MRBForwardingResourceResponse_Item_ExtIEs ** pMRBForwardingResourceResponse_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_MRBForwardingResourceResponse_Item_ExtIEs * obj_MRBForwardingResourceResponse_Item_ExtIEs = (SI_E1AP_DT_PDU_MRBForwardingResourceResponse_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MRBForwardingResourceResponse_Item_ExtIEs));
	memset( obj_MRBForwardingResourceResponse_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MRBForwardingResourceResponse_Item_ExtIEs));


	*pMRBForwardingResourceResponse_Item_ExtIEs = obj_MRBForwardingResourceResponse_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MCForwardingResourceRelease_ExtIEs( SI_E1AP_DT_PDU_MCForwardingResourceRelease_ExtIEs ** pMCForwardingResourceRelease_ExtIEs)
{
	SI_E1AP_DT_PDU_MCForwardingResourceRelease_ExtIEs * obj_MCForwardingResourceRelease_ExtIEs = (SI_E1AP_DT_PDU_MCForwardingResourceRelease_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCForwardingResourceRelease_ExtIEs));
	memset( obj_MCForwardingResourceRelease_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MCForwardingResourceRelease_ExtIEs));


	*pMCForwardingResourceRelease_ExtIEs = obj_MCForwardingResourceRelease_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MCForwardingResourceReleaseIndication_ExtIEs( SI_E1AP_DT_PDU_MCForwardingResourceReleaseIndication_ExtIEs ** pMCForwardingResourceReleaseIndication_ExtIEs)
{
	SI_E1AP_DT_PDU_MCForwardingResourceReleaseIndication_ExtIEs * obj_MCForwardingResourceReleaseIndication_ExtIEs = (SI_E1AP_DT_PDU_MCForwardingResourceReleaseIndication_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCForwardingResourceReleaseIndication_ExtIEs));
	memset( obj_MCForwardingResourceReleaseIndication_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MCForwardingResourceReleaseIndication_ExtIEs));


	*pMCForwardingResourceReleaseIndication_ExtIEs = obj_MCForwardingResourceReleaseIndication_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MRB_ProgressInformation_ExtIEs( SI_E1AP_DT_PDU_MRB_ProgressInformation_ExtIEs ** pMRB_ProgressInformation_ExtIEs)
{
	SI_E1AP_DT_PDU_MRB_ProgressInformation_ExtIEs * obj_MRB_ProgressInformation_ExtIEs = (SI_E1AP_DT_PDU_MRB_ProgressInformation_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MRB_ProgressInformation_ExtIEs));
	memset( obj_MRB_ProgressInformation_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MRB_ProgressInformation_ExtIEs));


	*pMRB_ProgressInformation_ExtIEs = obj_MRB_ProgressInformation_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MRB_ProgressInformationSNs_ExtIEs( SI_E1AP_DT_PDU_MRB_ProgressInformationSNs_ExtIEs ** pMRB_ProgressInformationSNs_ExtIEs)
{
	SI_E1AP_DT_PDU_MRB_ProgressInformationSNs_ExtIEs * obj_MRB_ProgressInformationSNs_ExtIEs = (SI_E1AP_DT_PDU_MRB_ProgressInformationSNs_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MRB_ProgressInformationSNs_ExtIEs));
	memset( obj_MRB_ProgressInformationSNs_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MRB_ProgressInformationSNs_ExtIEs));


	*pMRB_ProgressInformationSNs_ExtIEs = obj_MRB_ProgressInformationSNs_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MRDC_Data_Usage_Report_Item_ExtIEs( SI_E1AP_DT_PDU_MRDC_Data_Usage_Report_Item_ExtIEs ** pMRDC_Data_Usage_Report_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_MRDC_Data_Usage_Report_Item_ExtIEs * obj_MRDC_Data_Usage_Report_Item_ExtIEs = (SI_E1AP_DT_PDU_MRDC_Data_Usage_Report_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MRDC_Data_Usage_Report_Item_ExtIEs));
	memset( obj_MRDC_Data_Usage_Report_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MRDC_Data_Usage_Report_Item_ExtIEs));


	*pMRDC_Data_Usage_Report_Item_ExtIEs = obj_MRDC_Data_Usage_Report_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MRDC_Usage_Information_ExtIEs( SI_E1AP_DT_PDU_MRDC_Usage_Information_ExtIEs ** pMRDC_Usage_Information_ExtIEs)
{
	SI_E1AP_DT_PDU_MRDC_Usage_Information_ExtIEs * obj_MRDC_Usage_Information_ExtIEs = (SI_E1AP_DT_PDU_MRDC_Usage_Information_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MRDC_Usage_Information_ExtIEs));
	memset( obj_MRDC_Usage_Information_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MRDC_Usage_Information_ExtIEs));


	*pMRDC_Usage_Information_ExtIEs = obj_MRDC_Usage_Information_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_M4Configuration_ExtIEs( SI_E1AP_DT_PDU_M4Configuration_ExtIEs ** pM4Configuration_ExtIEs)
{
	SI_E1AP_DT_PDU_M4Configuration_ExtIEs * obj_M4Configuration_ExtIEs = (SI_E1AP_DT_PDU_M4Configuration_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_M4Configuration_ExtIEs));
	memset( obj_M4Configuration_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_M4Configuration_ExtIEs));

	// M4ReportAmount , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_M4Configuration_ExtIEs->m4ReportAmount = M4ReportAmount_r1_val;
	obj_M4Configuration_ExtIEs->m4ReportAmount_isset = 1;



	*pM4Configuration_ExtIEs = obj_M4Configuration_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_M6Configuration_ExtIEs( SI_E1AP_DT_PDU_M6Configuration_ExtIEs ** pM6Configuration_ExtIEs)
{
	SI_E1AP_DT_PDU_M6Configuration_ExtIEs * obj_M6Configuration_ExtIEs = (SI_E1AP_DT_PDU_M6Configuration_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_M6Configuration_ExtIEs));
	memset( obj_M6Configuration_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_M6Configuration_ExtIEs));

	// M6ReportAmount , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_M6Configuration_ExtIEs->m6ReportAmount = M6ReportAmount_r1_val;
	obj_M6Configuration_ExtIEs->m6ReportAmount_isset = 1;



	*pM6Configuration_ExtIEs = obj_M6Configuration_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_M7Configuration_ExtIEs( SI_E1AP_DT_PDU_M7Configuration_ExtIEs ** pM7Configuration_ExtIEs)
{
	SI_E1AP_DT_PDU_M7Configuration_ExtIEs * obj_M7Configuration_ExtIEs = (SI_E1AP_DT_PDU_M7Configuration_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_M7Configuration_ExtIEs));
	memset( obj_M7Configuration_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_M7Configuration_ExtIEs));

	// M7ReportAmount , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_M7Configuration_ExtIEs->m7ReportAmount = M7ReportAmount_r1_val;
	obj_M7Configuration_ExtIEs->m7ReportAmount_isset = 1;



	*pM7Configuration_ExtIEs = obj_M7Configuration_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MDT_Configuration_ExtIEs( SI_E1AP_DT_PDU_MDT_Configuration_ExtIEs ** pMDT_Configuration_ExtIEs)
{
	SI_E1AP_DT_PDU_MDT_Configuration_ExtIEs * obj_MDT_Configuration_ExtIEs = (SI_E1AP_DT_PDU_MDT_Configuration_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MDT_Configuration_ExtIEs));
	memset( obj_MDT_Configuration_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MDT_Configuration_ExtIEs));


	*pMDT_Configuration_ExtIEs = obj_MDT_Configuration_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MDTMode_ExtIEs( SI_E1AP_DT_PDU_MDTMode_ExtIEs ** pMDTMode_ExtIEs)
{
	SI_E1AP_DT_PDU_MDTMode_ExtIEs * obj_MDTMode_ExtIEs = (SI_E1AP_DT_PDU_MDTMode_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MDTMode_ExtIEs));
	memset( obj_MDTMode_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MDTMode_ExtIEs));


	*pMDTMode_ExtIEs = obj_MDTMode_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MT_SDT_Information_ExtIEs( SI_E1AP_DT_PDU_MT_SDT_Information_ExtIEs ** pMT_SDT_Information_ExtIEs)
{
	SI_E1AP_DT_PDU_MT_SDT_Information_ExtIEs * obj_MT_SDT_Information_ExtIEs = (SI_E1AP_DT_PDU_MT_SDT_Information_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MT_SDT_Information_ExtIEs));
	memset( obj_MT_SDT_Information_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MT_SDT_Information_ExtIEs));


	*pMT_SDT_Information_ExtIEs = obj_MT_SDT_Information_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MBS_ServiceArea_ExtIEs( SI_E1AP_DT_PDU_MBS_ServiceArea_ExtIEs ** pMBS_ServiceArea_ExtIEs)
{
	SI_E1AP_DT_PDU_MBS_ServiceArea_ExtIEs * obj_MBS_ServiceArea_ExtIEs = (SI_E1AP_DT_PDU_MBS_ServiceArea_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MBS_ServiceArea_ExtIEs));
	memset( obj_MBS_ServiceArea_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MBS_ServiceArea_ExtIEs));


	*pMBS_ServiceArea_ExtIEs = obj_MBS_ServiceArea_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MBS_ServiceAreaInformation_ExtIEs( SI_E1AP_DT_PDU_MBS_ServiceAreaInformation_ExtIEs ** pMBS_ServiceAreaInformation_ExtIEs)
{
	SI_E1AP_DT_PDU_MBS_ServiceAreaInformation_ExtIEs * obj_MBS_ServiceAreaInformation_ExtIEs = (SI_E1AP_DT_PDU_MBS_ServiceAreaInformation_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MBS_ServiceAreaInformation_ExtIEs));
	memset( obj_MBS_ServiceAreaInformation_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MBS_ServiceAreaInformation_ExtIEs));


	*pMBS_ServiceAreaInformation_ExtIEs = obj_MBS_ServiceAreaInformation_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MBS_ServiceAreaTAIList_Item_ExtIEs( SI_E1AP_DT_PDU_MBS_ServiceAreaTAIList_Item_ExtIEs ** pMBS_ServiceAreaTAIList_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_MBS_ServiceAreaTAIList_Item_ExtIEs * obj_MBS_ServiceAreaTAIList_Item_ExtIEs = (SI_E1AP_DT_PDU_MBS_ServiceAreaTAIList_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MBS_ServiceAreaTAIList_Item_ExtIEs));
	memset( obj_MBS_ServiceAreaTAIList_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MBS_ServiceAreaTAIList_Item_ExtIEs));


	*pMBS_ServiceAreaTAIList_Item_ExtIEs = obj_MBS_ServiceAreaTAIList_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_MBS_ServiceAreaInformationItem_ExtIEs( SI_E1AP_DT_PDU_MBS_ServiceAreaInformationItem_ExtIEs ** pMBS_ServiceAreaInformationItem_ExtIEs)
{
	SI_E1AP_DT_PDU_MBS_ServiceAreaInformationItem_ExtIEs * obj_MBS_ServiceAreaInformationItem_ExtIEs = (SI_E1AP_DT_PDU_MBS_ServiceAreaInformationItem_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MBS_ServiceAreaInformationItem_ExtIEs));
	memset( obj_MBS_ServiceAreaInformationItem_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_MBS_ServiceAreaInformationItem_ExtIEs));


	*pMBS_ServiceAreaInformationItem_ExtIEs = obj_MBS_ServiceAreaInformationItem_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_NGRANAllocationAndRetentionPriority_ExtIEs( SI_E1AP_DT_PDU_NGRANAllocationAndRetentionPriority_ExtIEs ** pNGRANAllocationAndRetentionPriority_ExtIEs)
{
	SI_E1AP_DT_PDU_NGRANAllocationAndRetentionPriority_ExtIEs * obj_NGRANAllocationAndRetentionPriority_ExtIEs = (SI_E1AP_DT_PDU_NGRANAllocationAndRetentionPriority_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_NGRANAllocationAndRetentionPriority_ExtIEs));
	memset( obj_NGRANAllocationAndRetentionPriority_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_NGRANAllocationAndRetentionPriority_ExtIEs));


	*pNGRANAllocationAndRetentionPriority_ExtIEs = obj_NGRANAllocationAndRetentionPriority_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_NG_RAN_QoS_Support_Item_ExtIEs( SI_E1AP_DT_PDU_NG_RAN_QoS_Support_Item_ExtIEs ** pNG_RAN_QoS_Support_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_NG_RAN_QoS_Support_Item_ExtIEs * obj_NG_RAN_QoS_Support_Item_ExtIEs = (SI_E1AP_DT_PDU_NG_RAN_QoS_Support_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_NG_RAN_QoS_Support_Item_ExtIEs));
	memset( obj_NG_RAN_QoS_Support_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_NG_RAN_QoS_Support_Item_ExtIEs));


	*pNG_RAN_QoS_Support_Item_ExtIEs = obj_NG_RAN_QoS_Support_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_Non_Dynamic5QIDescriptor_ExtIEs( SI_E1AP_DT_PDU_Non_Dynamic5QIDescriptor_ExtIEs ** pNon_Dynamic5QIDescriptor_ExtIEs)
{
	SI_E1AP_DT_PDU_Non_Dynamic5QIDescriptor_ExtIEs * obj_Non_Dynamic5QIDescriptor_ExtIEs = (SI_E1AP_DT_PDU_Non_Dynamic5QIDescriptor_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Non_Dynamic5QIDescriptor_ExtIEs));
	memset( obj_Non_Dynamic5QIDescriptor_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_Non_Dynamic5QIDescriptor_ExtIEs));

	// ExtendedPacketDelayBudget , PRESENCE = optional  INTEGER , MIN=1, MAX=65535
	obj_Non_Dynamic5QIDescriptor_ExtIEs->cNPacketDelayBudgetDownlink = __getTestINTEGER( 1, 65535);
	obj_Non_Dynamic5QIDescriptor_ExtIEs->cNPacketDelayBudgetDownlink_isset = 1;


	// ExtendedPacketDelayBudget , PRESENCE = optional  INTEGER , MIN=1, MAX=65535
	obj_Non_Dynamic5QIDescriptor_ExtIEs->cNPacketDelayBudgetUplink = __getTestINTEGER( 1, 65535);
	obj_Non_Dynamic5QIDescriptor_ExtIEs->cNPacketDelayBudgetUplink_isset = 1;



	*pNon_Dynamic5QIDescriptor_ExtIEs = obj_Non_Dynamic5QIDescriptor_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_NPNSupportInfo_ExtIEs( SI_E1AP_DT_PDU_NPNSupportInfo_ExtIEs ** pNPNSupportInfo_ExtIEs)
{
	SI_E1AP_DT_PDU_NPNSupportInfo_ExtIEs * obj_NPNSupportInfo_ExtIEs = (SI_E1AP_DT_PDU_NPNSupportInfo_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_NPNSupportInfo_ExtIEs));
	memset( obj_NPNSupportInfo_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_NPNSupportInfo_ExtIEs));


	*pNPNSupportInfo_ExtIEs = obj_NPNSupportInfo_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_NPNSupportInfo_SNPN_ExtIEs( SI_E1AP_DT_PDU_NPNSupportInfo_SNPN_ExtIEs ** pNPNSupportInfo_SNPN_ExtIEs)
{
	SI_E1AP_DT_PDU_NPNSupportInfo_SNPN_ExtIEs * obj_NPNSupportInfo_SNPN_ExtIEs = (SI_E1AP_DT_PDU_NPNSupportInfo_SNPN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_NPNSupportInfo_SNPN_ExtIEs));
	memset( obj_NPNSupportInfo_SNPN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_NPNSupportInfo_SNPN_ExtIEs));


	*pNPNSupportInfo_SNPN_ExtIEs = obj_NPNSupportInfo_SNPN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_NPNContextInfo_ExtIEs( SI_E1AP_DT_PDU_NPNContextInfo_ExtIEs ** pNPNContextInfo_ExtIEs)
{
	SI_E1AP_DT_PDU_NPNContextInfo_ExtIEs * obj_NPNContextInfo_ExtIEs = (SI_E1AP_DT_PDU_NPNContextInfo_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_NPNContextInfo_ExtIEs));
	memset( obj_NPNContextInfo_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_NPNContextInfo_ExtIEs));


	*pNPNContextInfo_ExtIEs = obj_NPNContextInfo_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_NPNContextInfo_SNPN_ExtIEs( SI_E1AP_DT_PDU_NPNContextInfo_SNPN_ExtIEs ** pNPNContextInfo_SNPN_ExtIEs)
{
	SI_E1AP_DT_PDU_NPNContextInfo_SNPN_ExtIEs * obj_NPNContextInfo_SNPN_ExtIEs = (SI_E1AP_DT_PDU_NPNContextInfo_SNPN_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_NPNContextInfo_SNPN_ExtIEs));
	memset( obj_NPNContextInfo_SNPN_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_NPNContextInfo_SNPN_ExtIEs));


	*pNPNContextInfo_SNPN_ExtIEs = obj_NPNContextInfo_SNPN_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_NR_CGI_ExtIEs( SI_E1AP_DT_PDU_NR_CGI_ExtIEs ** pNR_CGI_ExtIEs)
{
	SI_E1AP_DT_PDU_NR_CGI_ExtIEs * obj_NR_CGI_ExtIEs = (SI_E1AP_DT_PDU_NR_CGI_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_NR_CGI_ExtIEs));
	memset( obj_NR_CGI_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_NR_CGI_ExtIEs));


	*pNR_CGI_ExtIEs = obj_NR_CGI_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_NR_CGI_Support_Item_ExtIEs( SI_E1AP_DT_PDU_NR_CGI_Support_Item_ExtIEs ** pNR_CGI_Support_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_NR_CGI_Support_Item_ExtIEs * obj_NR_CGI_Support_Item_ExtIEs = (SI_E1AP_DT_PDU_NR_CGI_Support_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_NR_CGI_Support_Item_ExtIEs));
	memset( obj_NR_CGI_Support_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_NR_CGI_Support_Item_ExtIEs));


	*pNR_CGI_Support_Item_ExtIEs = obj_NR_CGI_Support_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_Extended_NR_CGI_Support_Item_ExtIEs( SI_E1AP_DT_PDU_Extended_NR_CGI_Support_Item_ExtIEs ** pExtended_NR_CGI_Support_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_Extended_NR_CGI_Support_Item_ExtIEs * obj_Extended_NR_CGI_Support_Item_ExtIEs = (SI_E1AP_DT_PDU_Extended_NR_CGI_Support_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Extended_NR_CGI_Support_Item_ExtIEs));
	memset( obj_Extended_NR_CGI_Support_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_Extended_NR_CGI_Support_Item_ExtIEs));


	*pExtended_NR_CGI_Support_Item_ExtIEs = obj_Extended_NR_CGI_Support_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_N6JitterInformationExtIEs( SI_E1AP_DT_PDU_N6JitterInformationExtIEs ** pN6JitterInformationExtIEs)
{
	SI_E1AP_DT_PDU_N6JitterInformationExtIEs * obj_N6JitterInformationExtIEs = (SI_E1AP_DT_PDU_N6JitterInformationExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_N6JitterInformationExtIEs));
	memset( obj_N6JitterInformationExtIEs, 0, sizeof( SI_E1AP_DT_PDU_N6JitterInformationExtIEs));


	*pN6JitterInformationExtIEs = obj_N6JitterInformationExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_PacketErrorRate_ExtIEs( SI_E1AP_DT_PDU_PacketErrorRate_ExtIEs ** pPacketErrorRate_ExtIEs)
{
	SI_E1AP_DT_PDU_PacketErrorRate_ExtIEs * obj_PacketErrorRate_ExtIEs = (SI_E1AP_DT_PDU_PacketErrorRate_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_PacketErrorRate_ExtIEs));
	memset( obj_PacketErrorRate_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_PacketErrorRate_ExtIEs));


	*pPacketErrorRate_ExtIEs = obj_PacketErrorRate_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_PDCP_Configuration_ExtIEs( SI_E1AP_DT_PDU_PDCP_Configuration_ExtIEs ** pPDCP_Configuration_ExtIEs)
{
	SI_E1AP_DT_PDU_PDCP_Configuration_ExtIEs * obj_PDCP_Configuration_ExtIEs = (SI_E1AP_DT_PDU_PDCP_Configuration_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_PDCP_Configuration_ExtIEs));
	memset( obj_PDCP_Configuration_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_PDCP_Configuration_ExtIEs));

	// PDCP-StatusReportIndication , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_PDCP_Configuration_ExtIEs->pDCPStatusReportIndication = PDCP_StatusReportIndication_downlink_val;
	obj_PDCP_Configuration_ExtIEs->pDCPStatusReportIndication_isset = 1;


	// AdditionalPDCPduplicationInformation , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_PDCP_Configuration_ExtIEs->additionalPDCPduplicationInformation = AdditionalPDCPduplicationInformation_three_val;
	obj_PDCP_Configuration_ExtIEs->additionalPDCPduplicationInformation_isset = 1;


	// EHC-Parameters , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__EHC_Parameters( &obj_PDCP_Configuration_ExtIEs->eHCParameters);
	obj_PDCP_Configuration_ExtIEs->eHCParameters_isset = 1;


	// UDC-Parameters , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__UDC_Parameters( &obj_PDCP_Configuration_ExtIEs->uDCParameters);
	obj_PDCP_Configuration_ExtIEs->uDCParameters_isset = 1;


	// DiscardTimerExtended , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_PDCP_Configuration_ExtIEs->discardTimerExtended = DiscardTimerExtended_ms0dot5_val;
	obj_PDCP_Configuration_ExtIEs->discardTimerExtended_isset = 1;


	// PSIbasedDiscardTimer , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_PDCP_Configuration_ExtIEs->pSIbasedDiscardTimer = PSIbasedDiscardTimer_ms0_val;
	obj_PDCP_Configuration_ExtIEs->pSIbasedDiscardTimer_isset = 1;


	// PDCPSNGapReport , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_PDCP_Configuration_ExtIEs->pDCPSNGapReport = PDCPSNGapReport_true_val;
	obj_PDCP_Configuration_ExtIEs->pDCPSNGapReport_isset = 1;



	*pPDCP_Configuration_ExtIEs = obj_PDCP_Configuration_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_PDCP_Count_ExtIEs( SI_E1AP_DT_PDU_PDCP_Count_ExtIEs ** pPDCP_Count_ExtIEs)
{
	SI_E1AP_DT_PDU_PDCP_Count_ExtIEs * obj_PDCP_Count_ExtIEs = (SI_E1AP_DT_PDU_PDCP_Count_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_PDCP_Count_ExtIEs));
	memset( obj_PDCP_Count_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_PDCP_Count_ExtIEs));


	*pPDCP_Count_ExtIEs = obj_PDCP_Count_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_PDU_Session_Resource_Data_Usage_Item_ExtIEs( SI_E1AP_DT_PDU_PDU_Session_Resource_Data_Usage_Item_ExtIEs ** pPDU_Session_Resource_Data_Usage_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_PDU_Session_Resource_Data_Usage_Item_ExtIEs * obj_PDU_Session_Resource_Data_Usage_Item_ExtIEs = (SI_E1AP_DT_PDU_PDU_Session_Resource_Data_Usage_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_PDU_Session_Resource_Data_Usage_Item_ExtIEs));
	memset( obj_PDU_Session_Resource_Data_Usage_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_PDU_Session_Resource_Data_Usage_Item_ExtIEs));


	*pPDU_Session_Resource_Data_Usage_Item_ExtIEs = obj_PDU_Session_Resource_Data_Usage_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_PDCP_SN_Status_Information_ExtIEs( SI_E1AP_DT_PDU_PDCP_SN_Status_Information_ExtIEs ** pPDCP_SN_Status_Information_ExtIEs)
{
	SI_E1AP_DT_PDU_PDCP_SN_Status_Information_ExtIEs * obj_PDCP_SN_Status_Information_ExtIEs = (SI_E1AP_DT_PDU_PDCP_SN_Status_Information_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_PDCP_SN_Status_Information_ExtIEs));
	memset( obj_PDCP_SN_Status_Information_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_PDCP_SN_Status_Information_ExtIEs));


	*pPDCP_SN_Status_Information_ExtIEs = obj_PDCP_SN_Status_Information_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DRBBStatusTransfer_ExtIEs( SI_E1AP_DT_PDU_DRBBStatusTransfer_ExtIEs ** pDRBBStatusTransfer_ExtIEs)
{
	SI_E1AP_DT_PDU_DRBBStatusTransfer_ExtIEs * obj_DRBBStatusTransfer_ExtIEs = (SI_E1AP_DT_PDU_DRBBStatusTransfer_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DRBBStatusTransfer_ExtIEs));
	memset( obj_DRBBStatusTransfer_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DRBBStatusTransfer_ExtIEs));


	*pDRBBStatusTransfer_ExtIEs = obj_DRBBStatusTransfer_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_PDU_Session_Resource_Activity_ItemExtIEs( SI_E1AP_DT_PDU_PDU_Session_Resource_Activity_ItemExtIEs ** pPDU_Session_Resource_Activity_ItemExtIEs)
{
	SI_E1AP_DT_PDU_PDU_Session_Resource_Activity_ItemExtIEs * obj_PDU_Session_Resource_Activity_ItemExtIEs = (SI_E1AP_DT_PDU_PDU_Session_Resource_Activity_ItemExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_PDU_Session_Resource_Activity_ItemExtIEs));
	memset( obj_PDU_Session_Resource_Activity_ItemExtIEs, 0, sizeof( SI_E1AP_DT_PDU_PDU_Session_Resource_Activity_ItemExtIEs));


	*pPDU_Session_Resource_Activity_ItemExtIEs = obj_PDU_Session_Resource_Activity_ItemExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_PDU_Session_Resource_Confirm_Modified_Item_ExtIEs( SI_E1AP_DT_PDU_PDU_Session_Resource_Confirm_Modified_Item_ExtIEs ** pPDU_Session_Resource_Confirm_Modified_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_PDU_Session_Resource_Confirm_Modified_Item_ExtIEs * obj_PDU_Session_Resource_Confirm_Modified_Item_ExtIEs = (SI_E1AP_DT_PDU_PDU_Session_Resource_Confirm_Modified_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_PDU_Session_Resource_Confirm_Modified_Item_ExtIEs));
	memset( obj_PDU_Session_Resource_Confirm_Modified_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_PDU_Session_Resource_Confirm_Modified_Item_ExtIEs));


	*pPDU_Session_Resource_Confirm_Modified_Item_ExtIEs = obj_PDU_Session_Resource_Confirm_Modified_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_PDU_Session_Resource_Failed_Item_ExtIEs( SI_E1AP_DT_PDU_PDU_Session_Resource_Failed_Item_ExtIEs ** pPDU_Session_Resource_Failed_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_PDU_Session_Resource_Failed_Item_ExtIEs * obj_PDU_Session_Resource_Failed_Item_ExtIEs = (SI_E1AP_DT_PDU_PDU_Session_Resource_Failed_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_PDU_Session_Resource_Failed_Item_ExtIEs));
	memset( obj_PDU_Session_Resource_Failed_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_PDU_Session_Resource_Failed_Item_ExtIEs));


	*pPDU_Session_Resource_Failed_Item_ExtIEs = obj_PDU_Session_Resource_Failed_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_PDU_Session_Resource_Failed_Mod_Item_ExtIEs( SI_E1AP_DT_PDU_PDU_Session_Resource_Failed_Mod_Item_ExtIEs ** pPDU_Session_Resource_Failed_Mod_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_PDU_Session_Resource_Failed_Mod_Item_ExtIEs * obj_PDU_Session_Resource_Failed_Mod_Item_ExtIEs = (SI_E1AP_DT_PDU_PDU_Session_Resource_Failed_Mod_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_PDU_Session_Resource_Failed_Mod_Item_ExtIEs));
	memset( obj_PDU_Session_Resource_Failed_Mod_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_PDU_Session_Resource_Failed_Mod_Item_ExtIEs));


	*pPDU_Session_Resource_Failed_Mod_Item_ExtIEs = obj_PDU_Session_Resource_Failed_Mod_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_PDU_Session_Resource_Failed_To_Modify_Item_ExtIEs( SI_E1AP_DT_PDU_PDU_Session_Resource_Failed_To_Modify_Item_ExtIEs ** pPDU_Session_Resource_Failed_To_Modify_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_PDU_Session_Resource_Failed_To_Modify_Item_ExtIEs * obj_PDU_Session_Resource_Failed_To_Modify_Item_ExtIEs = (SI_E1AP_DT_PDU_PDU_Session_Resource_Failed_To_Modify_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_PDU_Session_Resource_Failed_To_Modify_Item_ExtIEs));
	memset( obj_PDU_Session_Resource_Failed_To_Modify_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_PDU_Session_Resource_Failed_To_Modify_Item_ExtIEs));


	*pPDU_Session_Resource_Failed_To_Modify_Item_ExtIEs = obj_PDU_Session_Resource_Failed_To_Modify_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_PDU_Session_Resource_Modified_Item_ExtIEs( SI_E1AP_DT_PDU_PDU_Session_Resource_Modified_Item_ExtIEs ** pPDU_Session_Resource_Modified_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_PDU_Session_Resource_Modified_Item_ExtIEs * obj_PDU_Session_Resource_Modified_Item_ExtIEs = (SI_E1AP_DT_PDU_PDU_Session_Resource_Modified_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_PDU_Session_Resource_Modified_Item_ExtIEs));
	memset( obj_PDU_Session_Resource_Modified_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_PDU_Session_Resource_Modified_Item_ExtIEs));

	// UP-TNL-Information , PRESENCE = optional   CHOICE
	__si_e1ap__set_testdata__UP_TNL_Information( &obj_PDU_Session_Resource_Modified_Item_ExtIEs->redundantnGDLUPTNLInformation);
	obj_PDU_Session_Resource_Modified_Item_ExtIEs->redundantnGDLUPTNLInformation->SelectedChoice = UP_TNL_Information_gTPTunnel_val;

	switch( obj_PDU_Session_Resource_Modified_Item_ExtIEs->redundantnGDLUPTNLInformation->SelectedChoice)
	{
		case UP_TNL_Information_gTPTunnel_val:
			__si_e1ap__set_testdata__GTPTunnel( &obj_PDU_Session_Resource_Modified_Item_ExtIEs->redundantnGDLUPTNLInformation->u.gTPTunnel); //   L:11384
			break;
		case UP_TNL_Information_choice_extension_val:  // L:11477
			{
				__si_e1ap__set_testdata__PDU_UP_TNL_Information_ExtIEs( &obj_PDU_Session_Resource_Modified_Item_ExtIEs->redundantnGDLUPTNLInformation->u.choice_extension);   // L:11497
			}
			break;
		default:
			break;
	}

	obj_PDU_Session_Resource_Modified_Item_ExtIEs->redundantnGDLUPTNLInformation_isset = 1;



	*pPDU_Session_Resource_Modified_Item_ExtIEs = obj_PDU_Session_Resource_Modified_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_PDU_Session_Resource_Required_To_Modify_Item_ExtIEs( SI_E1AP_DT_PDU_PDU_Session_Resource_Required_To_Modify_Item_ExtIEs ** pPDU_Session_Resource_Required_To_Modify_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_PDU_Session_Resource_Required_To_Modify_Item_ExtIEs * obj_PDU_Session_Resource_Required_To_Modify_Item_ExtIEs = (SI_E1AP_DT_PDU_PDU_Session_Resource_Required_To_Modify_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_PDU_Session_Resource_Required_To_Modify_Item_ExtIEs));
	memset( obj_PDU_Session_Resource_Required_To_Modify_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_PDU_Session_Resource_Required_To_Modify_Item_ExtIEs));

	// UP-TNL-Information , PRESENCE = optional   CHOICE
	__si_e1ap__set_testdata__UP_TNL_Information( &obj_PDU_Session_Resource_Required_To_Modify_Item_ExtIEs->redundantnGDLUPTNLInformation);
	obj_PDU_Session_Resource_Required_To_Modify_Item_ExtIEs->redundantnGDLUPTNLInformation->SelectedChoice = UP_TNL_Information_gTPTunnel_val;

	switch( obj_PDU_Session_Resource_Required_To_Modify_Item_ExtIEs->redundantnGDLUPTNLInformation->SelectedChoice)
	{
		case UP_TNL_Information_gTPTunnel_val:
			__si_e1ap__set_testdata__GTPTunnel( &obj_PDU_Session_Resource_Required_To_Modify_Item_ExtIEs->redundantnGDLUPTNLInformation->u.gTPTunnel); //   L:11384
			break;
		case UP_TNL_Information_choice_extension_val:  // L:11477
			{
				__si_e1ap__set_testdata__PDU_UP_TNL_Information_ExtIEs( &obj_PDU_Session_Resource_Required_To_Modify_Item_ExtIEs->redundantnGDLUPTNLInformation->u.choice_extension);   // L:11497
			}
			break;
		default:
			break;
	}

	obj_PDU_Session_Resource_Required_To_Modify_Item_ExtIEs->redundantnGDLUPTNLInformation_isset = 1;



	*pPDU_Session_Resource_Required_To_Modify_Item_ExtIEs = obj_PDU_Session_Resource_Required_To_Modify_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_PDU_Session_Resource_Setup_Item_ExtIEs( SI_E1AP_DT_PDU_PDU_Session_Resource_Setup_Item_ExtIEs ** pPDU_Session_Resource_Setup_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_PDU_Session_Resource_Setup_Item_ExtIEs * obj_PDU_Session_Resource_Setup_Item_ExtIEs = (SI_E1AP_DT_PDU_PDU_Session_Resource_Setup_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_PDU_Session_Resource_Setup_Item_ExtIEs));
	memset( obj_PDU_Session_Resource_Setup_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_PDU_Session_Resource_Setup_Item_ExtIEs));

	// UP-TNL-Information , PRESENCE = optional   CHOICE
	__si_e1ap__set_testdata__UP_TNL_Information( &obj_PDU_Session_Resource_Setup_Item_ExtIEs->redundantnGDLUPTNLInformation);
	obj_PDU_Session_Resource_Setup_Item_ExtIEs->redundantnGDLUPTNLInformation->SelectedChoice = UP_TNL_Information_gTPTunnel_val;

	switch( obj_PDU_Session_Resource_Setup_Item_ExtIEs->redundantnGDLUPTNLInformation->SelectedChoice)
	{
		case UP_TNL_Information_gTPTunnel_val:
			__si_e1ap__set_testdata__GTPTunnel( &obj_PDU_Session_Resource_Setup_Item_ExtIEs->redundantnGDLUPTNLInformation->u.gTPTunnel); //   L:11384
			break;
		case UP_TNL_Information_choice_extension_val:  // L:11477
			{
				__si_e1ap__set_testdata__PDU_UP_TNL_Information_ExtIEs( &obj_PDU_Session_Resource_Setup_Item_ExtIEs->redundantnGDLUPTNLInformation->u.choice_extension);   // L:11497
			}
			break;
		default:
			break;
	}

	obj_PDU_Session_Resource_Setup_Item_ExtIEs->redundantnGDLUPTNLInformation_isset = 1;


	// RedundantPDUSessionInformation , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__RedundantPDUSessionInformation( &obj_PDU_Session_Resource_Setup_Item_ExtIEs->redundantPDUSessionInformationused);
	obj_PDU_Session_Resource_Setup_Item_ExtIEs->redundantPDUSessionInformationused_isset = 1;



	*pPDU_Session_Resource_Setup_Item_ExtIEs = obj_PDU_Session_Resource_Setup_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_PDU_Session_Resource_Setup_Mod_Item_ExtIEs( SI_E1AP_DT_PDU_PDU_Session_Resource_Setup_Mod_Item_ExtIEs ** pPDU_Session_Resource_Setup_Mod_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_PDU_Session_Resource_Setup_Mod_Item_ExtIEs * obj_PDU_Session_Resource_Setup_Mod_Item_ExtIEs = (SI_E1AP_DT_PDU_PDU_Session_Resource_Setup_Mod_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_PDU_Session_Resource_Setup_Mod_Item_ExtIEs));
	memset( obj_PDU_Session_Resource_Setup_Mod_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_PDU_Session_Resource_Setup_Mod_Item_ExtIEs));

	// UP-TNL-Information , PRESENCE = optional   CHOICE
	__si_e1ap__set_testdata__UP_TNL_Information( &obj_PDU_Session_Resource_Setup_Mod_Item_ExtIEs->redundantnGDLUPTNLInformation);
	obj_PDU_Session_Resource_Setup_Mod_Item_ExtIEs->redundantnGDLUPTNLInformation->SelectedChoice = UP_TNL_Information_gTPTunnel_val;

	switch( obj_PDU_Session_Resource_Setup_Mod_Item_ExtIEs->redundantnGDLUPTNLInformation->SelectedChoice)
	{
		case UP_TNL_Information_gTPTunnel_val:
			__si_e1ap__set_testdata__GTPTunnel( &obj_PDU_Session_Resource_Setup_Mod_Item_ExtIEs->redundantnGDLUPTNLInformation->u.gTPTunnel); //   L:11384
			break;
		case UP_TNL_Information_choice_extension_val:  // L:11477
			{
				__si_e1ap__set_testdata__PDU_UP_TNL_Information_ExtIEs( &obj_PDU_Session_Resource_Setup_Mod_Item_ExtIEs->redundantnGDLUPTNLInformation->u.choice_extension);   // L:11497
			}
			break;
		default:
			break;
	}

	obj_PDU_Session_Resource_Setup_Mod_Item_ExtIEs->redundantnGDLUPTNLInformation_isset = 1;



	*pPDU_Session_Resource_Setup_Mod_Item_ExtIEs = obj_PDU_Session_Resource_Setup_Mod_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_PDU_Session_Resource_To_Modify_Item_ExtIEs( SI_E1AP_DT_PDU_PDU_Session_Resource_To_Modify_Item_ExtIEs ** pPDU_Session_Resource_To_Modify_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_PDU_Session_Resource_To_Modify_Item_ExtIEs * obj_PDU_Session_Resource_To_Modify_Item_ExtIEs = (SI_E1AP_DT_PDU_PDU_Session_Resource_To_Modify_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_PDU_Session_Resource_To_Modify_Item_ExtIEs));
	memset( obj_PDU_Session_Resource_To_Modify_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_PDU_Session_Resource_To_Modify_Item_ExtIEs));

	// SNSSAI , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__SNSSAI( &obj_PDU_Session_Resource_To_Modify_Item_ExtIEs->sNSSAI);
	obj_PDU_Session_Resource_To_Modify_Item_ExtIEs->sNSSAI_isset = 1;


	// CommonNetworkInstance    OCTETSTRING, PRESENCE = optional , MIN=0, MAX=0
	__si_e1ap_init_CommonNetworkInstance2( &obj_PDU_Session_Resource_To_Modify_Item_ExtIEs->commonNetworkInstance, "\x21\x20\x21\x11\x01", 5);
	obj_PDU_Session_Resource_To_Modify_Item_ExtIEs->commonNetworkInstance_isset = 1;


	// UP-TNL-Information , PRESENCE = optional   CHOICE
	__si_e1ap__set_testdata__UP_TNL_Information( &obj_PDU_Session_Resource_To_Modify_Item_ExtIEs->redundantnGULUPTNLInformation);
	obj_PDU_Session_Resource_To_Modify_Item_ExtIEs->redundantnGULUPTNLInformation->SelectedChoice = UP_TNL_Information_gTPTunnel_val;

	switch( obj_PDU_Session_Resource_To_Modify_Item_ExtIEs->redundantnGULUPTNLInformation->SelectedChoice)
	{
		case UP_TNL_Information_gTPTunnel_val:
			__si_e1ap__set_testdata__GTPTunnel( &obj_PDU_Session_Resource_To_Modify_Item_ExtIEs->redundantnGULUPTNLInformation->u.gTPTunnel); //   L:11384
			break;
		case UP_TNL_Information_choice_extension_val:  // L:11477
			{
				__si_e1ap__set_testdata__PDU_UP_TNL_Information_ExtIEs( &obj_PDU_Session_Resource_To_Modify_Item_ExtIEs->redundantnGULUPTNLInformation->u.choice_extension);   // L:11497
			}
			break;
		default:
			break;
	}

	obj_PDU_Session_Resource_To_Modify_Item_ExtIEs->redundantnGULUPTNLInformation_isset = 1;


	// CommonNetworkInstance    OCTETSTRING, PRESENCE = optional , MIN=0, MAX=0
	__si_e1ap_init_CommonNetworkInstance2( &obj_PDU_Session_Resource_To_Modify_Item_ExtIEs->redundantCommonNetworkInstance, "\x13\x08\x17\x24\x04", 5);
	obj_PDU_Session_Resource_To_Modify_Item_ExtIEs->redundantCommonNetworkInstance_isset = 1;


	// DataForwardingtoE-UTRANInformationList , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__DataForwardingtoE_UTRANInformationList( &obj_PDU_Session_Resource_To_Modify_Item_ExtIEs->dataForwardingtoEUTRANInformationList);
	obj_PDU_Session_Resource_To_Modify_Item_ExtIEs->dataForwardingtoEUTRANInformationList_isset = 1;


	// SecurityIndication , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__SecurityIndication( &obj_PDU_Session_Resource_To_Modify_Item_ExtIEs->securityIndicationModify);
	obj_PDU_Session_Resource_To_Modify_Item_ExtIEs->securityIndicationModify_isset = 1;


	// Data-Forwarding-Information , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__Data_Forwarding_Information( &obj_PDU_Session_Resource_To_Modify_Item_ExtIEs->secondaryPDUSessionDataForwardingInformation);
	obj_PDU_Session_Resource_To_Modify_Item_ExtIEs->secondaryPDUSessionDataForwardingInformation_isset = 1;


	// UserPlaneFailureIndication , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__UserPlaneFailureIndication( &obj_PDU_Session_Resource_To_Modify_Item_ExtIEs->userPlaneFailureIndication);
	obj_PDU_Session_Resource_To_Modify_Item_ExtIEs->userPlaneFailureIndication_isset = 1;



	*pPDU_Session_Resource_To_Modify_Item_ExtIEs = obj_PDU_Session_Resource_To_Modify_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_PDU_Session_Resource_To_Remove_Item_ExtIEs( SI_E1AP_DT_PDU_PDU_Session_Resource_To_Remove_Item_ExtIEs ** pPDU_Session_Resource_To_Remove_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_PDU_Session_Resource_To_Remove_Item_ExtIEs * obj_PDU_Session_Resource_To_Remove_Item_ExtIEs = (SI_E1AP_DT_PDU_PDU_Session_Resource_To_Remove_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_PDU_Session_Resource_To_Remove_Item_ExtIEs));
	memset( obj_PDU_Session_Resource_To_Remove_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_PDU_Session_Resource_To_Remove_Item_ExtIEs));

	// Cause , PRESENCE = optional   CHOICE
	__si_e1ap__set_testdata__Cause( &obj_PDU_Session_Resource_To_Remove_Item_ExtIEs->cause);
	obj_PDU_Session_Resource_To_Remove_Item_ExtIEs->cause->SelectedChoice = Cause_radioNetwork_val;

	switch( obj_PDU_Session_Resource_To_Remove_Item_ExtIEs->cause->SelectedChoice)
	{
		case Cause_radioNetwork_val:
			obj_PDU_Session_Resource_To_Remove_Item_ExtIEs->cause->u.radioNetwork = CauseRadioNetwork_unspecified_val;
			break;
		case Cause_transport_val:
			obj_PDU_Session_Resource_To_Remove_Item_ExtIEs->cause->u.transport = CauseTransport_unspecified_val;
			break;
		case Cause_protocol_val:
			obj_PDU_Session_Resource_To_Remove_Item_ExtIEs->cause->u.protocol = CauseProtocol_transfer_syntax_error_val;
			break;
		case Cause_misc_val:
			obj_PDU_Session_Resource_To_Remove_Item_ExtIEs->cause->u.misc = CauseMisc_control_processing_overload_val;
			break;
		case Cause_choice_extension_val:  // L:11477
			{
				__si_e1ap__set_testdata__PDU_Cause_ExtIEs( &obj_PDU_Session_Resource_To_Remove_Item_ExtIEs->cause->u.choice_extension);   // L:11497
			}
			break;
		default:
			break;
	}

	obj_PDU_Session_Resource_To_Remove_Item_ExtIEs->cause_isset = 1;


	// UserPlaneErrorIndicator , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_PDU_Session_Resource_To_Remove_Item_ExtIEs->userPlaneErrorIndicator = UserPlaneErrorIndicator_gTP_U_error_indication_received_val;
	obj_PDU_Session_Resource_To_Remove_Item_ExtIEs->userPlaneErrorIndicator_isset = 1;



	*pPDU_Session_Resource_To_Remove_Item_ExtIEs = obj_PDU_Session_Resource_To_Remove_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_PDU_Session_Resource_To_Setup_Item_ExtIEs( SI_E1AP_DT_PDU_PDU_Session_Resource_To_Setup_Item_ExtIEs ** pPDU_Session_Resource_To_Setup_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_PDU_Session_Resource_To_Setup_Item_ExtIEs * obj_PDU_Session_Resource_To_Setup_Item_ExtIEs = (SI_E1AP_DT_PDU_PDU_Session_Resource_To_Setup_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_PDU_Session_Resource_To_Setup_Item_ExtIEs));
	memset( obj_PDU_Session_Resource_To_Setup_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_PDU_Session_Resource_To_Setup_Item_ExtIEs));

	// CommonNetworkInstance    OCTETSTRING, PRESENCE = optional , MIN=0, MAX=0
	__si_e1ap_init_CommonNetworkInstance2( &obj_PDU_Session_Resource_To_Setup_Item_ExtIEs->commonNetworkInstance, "\x23\x10\x14\x04\x18", 5);
	obj_PDU_Session_Resource_To_Setup_Item_ExtIEs->commonNetworkInstance_isset = 1;


	// UP-TNL-Information , PRESENCE = optional   CHOICE
	__si_e1ap__set_testdata__UP_TNL_Information( &obj_PDU_Session_Resource_To_Setup_Item_ExtIEs->redundantnGULUPTNLInformation);
	obj_PDU_Session_Resource_To_Setup_Item_ExtIEs->redundantnGULUPTNLInformation->SelectedChoice = UP_TNL_Information_gTPTunnel_val;

	switch( obj_PDU_Session_Resource_To_Setup_Item_ExtIEs->redundantnGULUPTNLInformation->SelectedChoice)
	{
		case UP_TNL_Information_gTPTunnel_val:
			__si_e1ap__set_testdata__GTPTunnel( &obj_PDU_Session_Resource_To_Setup_Item_ExtIEs->redundantnGULUPTNLInformation->u.gTPTunnel); //   L:11384
			break;
		case UP_TNL_Information_choice_extension_val:  // L:11477
			{
				__si_e1ap__set_testdata__PDU_UP_TNL_Information_ExtIEs( &obj_PDU_Session_Resource_To_Setup_Item_ExtIEs->redundantnGULUPTNLInformation->u.choice_extension);   // L:11497
			}
			break;
		default:
			break;
	}

	obj_PDU_Session_Resource_To_Setup_Item_ExtIEs->redundantnGULUPTNLInformation_isset = 1;


	// CommonNetworkInstance    OCTETSTRING, PRESENCE = optional , MIN=0, MAX=0
	__si_e1ap_init_CommonNetworkInstance2( &obj_PDU_Session_Resource_To_Setup_Item_ExtIEs->redundantCommonNetworkInstance, "\x17\x08\x03\x21\x08", 5);
	obj_PDU_Session_Resource_To_Setup_Item_ExtIEs->redundantCommonNetworkInstance_isset = 1;


	// RedundantPDUSessionInformation , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__RedundantPDUSessionInformation( &obj_PDU_Session_Resource_To_Setup_Item_ExtIEs->redundantPDUSessionInformation);
	obj_PDU_Session_Resource_To_Setup_Item_ExtIEs->redundantPDUSessionInformation_isset = 1;


	// SpecialTriggeringPurpose , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_PDU_Session_Resource_To_Setup_Item_ExtIEs->specialTriggeringPurpose = SpecialTriggeringPurpose_indirect_data_forwarding_val;
	obj_PDU_Session_Resource_To_Setup_Item_ExtIEs->specialTriggeringPurpose_isset = 1;



	*pPDU_Session_Resource_To_Setup_Item_ExtIEs = obj_PDU_Session_Resource_To_Setup_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_PDU_Session_Resource_To_Setup_Mod_Item_ExtIEs( SI_E1AP_DT_PDU_PDU_Session_Resource_To_Setup_Mod_Item_ExtIEs ** pPDU_Session_Resource_To_Setup_Mod_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_PDU_Session_Resource_To_Setup_Mod_Item_ExtIEs * obj_PDU_Session_Resource_To_Setup_Mod_Item_ExtIEs = (SI_E1AP_DT_PDU_PDU_Session_Resource_To_Setup_Mod_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_PDU_Session_Resource_To_Setup_Mod_Item_ExtIEs));
	memset( obj_PDU_Session_Resource_To_Setup_Mod_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_PDU_Session_Resource_To_Setup_Mod_Item_ExtIEs));

	// NetworkInstance , PRESENCE = optional  INTEGER , MIN=1, MAX=256
	obj_PDU_Session_Resource_To_Setup_Mod_Item_ExtIEs->networkInstance = __getTestINTEGER( 1, 256);
	obj_PDU_Session_Resource_To_Setup_Mod_Item_ExtIEs->networkInstance_isset = 1;


	// CommonNetworkInstance    OCTETSTRING, PRESENCE = optional , MIN=0, MAX=0
	__si_e1ap_init_CommonNetworkInstance2( &obj_PDU_Session_Resource_To_Setup_Mod_Item_ExtIEs->commonNetworkInstance, "\x01\x16\x24\x08\x22", 5);
	obj_PDU_Session_Resource_To_Setup_Mod_Item_ExtIEs->commonNetworkInstance_isset = 1;


	// UP-TNL-Information , PRESENCE = optional   CHOICE
	__si_e1ap__set_testdata__UP_TNL_Information( &obj_PDU_Session_Resource_To_Setup_Mod_Item_ExtIEs->redundantnGULUPTNLInformation);
	obj_PDU_Session_Resource_To_Setup_Mod_Item_ExtIEs->redundantnGULUPTNLInformation->SelectedChoice = UP_TNL_Information_gTPTunnel_val;

	switch( obj_PDU_Session_Resource_To_Setup_Mod_Item_ExtIEs->redundantnGULUPTNLInformation->SelectedChoice)
	{
		case UP_TNL_Information_gTPTunnel_val:
			__si_e1ap__set_testdata__GTPTunnel( &obj_PDU_Session_Resource_To_Setup_Mod_Item_ExtIEs->redundantnGULUPTNLInformation->u.gTPTunnel); //   L:11384
			break;
		case UP_TNL_Information_choice_extension_val:  // L:11477
			{
				__si_e1ap__set_testdata__PDU_UP_TNL_Information_ExtIEs( &obj_PDU_Session_Resource_To_Setup_Mod_Item_ExtIEs->redundantnGULUPTNLInformation->u.choice_extension);   // L:11497
			}
			break;
		default:
			break;
	}

	obj_PDU_Session_Resource_To_Setup_Mod_Item_ExtIEs->redundantnGULUPTNLInformation_isset = 1;


	// CommonNetworkInstance    OCTETSTRING, PRESENCE = optional , MIN=0, MAX=0
	__si_e1ap_init_CommonNetworkInstance2( &obj_PDU_Session_Resource_To_Setup_Mod_Item_ExtIEs->redundantCommonNetworkInstance, "\x11\x16\x05\x24\x09", 5);
	obj_PDU_Session_Resource_To_Setup_Mod_Item_ExtIEs->redundantCommonNetworkInstance_isset = 1;


	// SpecialTriggeringPurpose , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_PDU_Session_Resource_To_Setup_Mod_Item_ExtIEs->specialTriggeringPurpose = SpecialTriggeringPurpose_indirect_data_forwarding_val;
	obj_PDU_Session_Resource_To_Setup_Mod_Item_ExtIEs->specialTriggeringPurpose_isset = 1;



	*pPDU_Session_Resource_To_Setup_Mod_Item_ExtIEs = obj_PDU_Session_Resource_To_Setup_Mod_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_PDU_Session_To_Notify_Item_ExtIEs( SI_E1AP_DT_PDU_PDU_Session_To_Notify_Item_ExtIEs ** pPDU_Session_To_Notify_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_PDU_Session_To_Notify_Item_ExtIEs * obj_PDU_Session_To_Notify_Item_ExtIEs = (SI_E1AP_DT_PDU_PDU_Session_To_Notify_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_PDU_Session_To_Notify_Item_ExtIEs));
	memset( obj_PDU_Session_To_Notify_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_PDU_Session_To_Notify_Item_ExtIEs));


	*pPDU_Session_To_Notify_Item_ExtIEs = obj_PDU_Session_To_Notify_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_PDUSetQoSParameters_ExtIEs( SI_E1AP_DT_PDU_PDUSetQoSParameters_ExtIEs ** pPDUSetQoSParameters_ExtIEs)
{
	SI_E1AP_DT_PDU_PDUSetQoSParameters_ExtIEs * obj_PDUSetQoSParameters_ExtIEs = (SI_E1AP_DT_PDU_PDUSetQoSParameters_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_PDUSetQoSParameters_ExtIEs));
	memset( obj_PDUSetQoSParameters_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_PDUSetQoSParameters_ExtIEs));


	*pPDUSetQoSParameters_ExtIEs = obj_PDUSetQoSParameters_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_PDUSetQoSInformation_ExtIEs( SI_E1AP_DT_PDU_PDUSetQoSInformation_ExtIEs ** pPDUSetQoSInformation_ExtIEs)
{
	SI_E1AP_DT_PDU_PDUSetQoSInformation_ExtIEs * obj_PDUSetQoSInformation_ExtIEs = (SI_E1AP_DT_PDU_PDUSetQoSInformation_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_PDUSetQoSInformation_ExtIEs));
	memset( obj_PDUSetQoSInformation_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_PDUSetQoSInformation_ExtIEs));


	*pPDUSetQoSInformation_ExtIEs = obj_PDUSetQoSInformation_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_QoS_Characteristics_ExtIEs( SI_E1AP_DT_PDU_QoS_Characteristics_ExtIEs ** pQoS_Characteristics_ExtIEs)
{
	SI_E1AP_DT_PDU_QoS_Characteristics_ExtIEs * obj_QoS_Characteristics_ExtIEs = (SI_E1AP_DT_PDU_QoS_Characteristics_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_QoS_Characteristics_ExtIEs));
	memset( obj_QoS_Characteristics_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_QoS_Characteristics_ExtIEs));


	*pQoS_Characteristics_ExtIEs = obj_QoS_Characteristics_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_QoS_Flow_Item_ExtIEs( SI_E1AP_DT_PDU_QoS_Flow_Item_ExtIEs ** pQoS_Flow_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_QoS_Flow_Item_ExtIEs * obj_QoS_Flow_Item_ExtIEs = (SI_E1AP_DT_PDU_QoS_Flow_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_QoS_Flow_Item_ExtIEs));
	memset( obj_QoS_Flow_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_QoS_Flow_Item_ExtIEs));

	// QoS-Flow-Mapping-Indication , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_QoS_Flow_Item_ExtIEs->qoSFlowMappingIndication = QoS_Flow_Mapping_Indication_ul_val;
	obj_QoS_Flow_Item_ExtIEs->qoSFlowMappingIndication_isset = 1;


	// TransportLayerAddress  , PRESENCE = optional   BITSTRING , MIN=1, MAX=160
	__si_e1ap_init_TransportLayerAddress2( &obj_QoS_Flow_Item_ExtIEs->dataForwardingSourceIPAddress, "8", 1, 1);
	obj_QoS_Flow_Item_ExtIEs->dataForwardingSourceIPAddress->bitslen = 1;
	obj_QoS_Flow_Item_ExtIEs->dataForwardingSourceIPAddress_isset = 1;


	// ECNMarkingorCongestionInformationReportingStatus , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_QoS_Flow_Item_ExtIEs->eCNMarkingorCongestionInformationReportingStatus = ECNMarkingorCongestionInformationReportingStatus_active_val;
	obj_QoS_Flow_Item_ExtIEs->eCNMarkingorCongestionInformationReportingStatus_isset = 1;



	*pQoS_Flow_Item_ExtIEs = obj_QoS_Flow_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_QoS_Flow_Failed_Item_ExtIEs( SI_E1AP_DT_PDU_QoS_Flow_Failed_Item_ExtIEs ** pQoS_Flow_Failed_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_QoS_Flow_Failed_Item_ExtIEs * obj_QoS_Flow_Failed_Item_ExtIEs = (SI_E1AP_DT_PDU_QoS_Flow_Failed_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_QoS_Flow_Failed_Item_ExtIEs));
	memset( obj_QoS_Flow_Failed_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_QoS_Flow_Failed_Item_ExtIEs));


	*pQoS_Flow_Failed_Item_ExtIEs = obj_QoS_Flow_Failed_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_QoS_Flow_Mapping_Item_ExtIEs( SI_E1AP_DT_PDU_QoS_Flow_Mapping_Item_ExtIEs ** pQoS_Flow_Mapping_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_QoS_Flow_Mapping_Item_ExtIEs * obj_QoS_Flow_Mapping_Item_ExtIEs = (SI_E1AP_DT_PDU_QoS_Flow_Mapping_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_QoS_Flow_Mapping_Item_ExtIEs));
	memset( obj_QoS_Flow_Mapping_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_QoS_Flow_Mapping_Item_ExtIEs));


	*pQoS_Flow_Mapping_Item_ExtIEs = obj_QoS_Flow_Mapping_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_QoS_Parameters_Support_List_ItemExtIEs( SI_E1AP_DT_PDU_QoS_Parameters_Support_List_ItemExtIEs ** pQoS_Parameters_Support_List_ItemExtIEs)
{
	SI_E1AP_DT_PDU_QoS_Parameters_Support_List_ItemExtIEs * obj_QoS_Parameters_Support_List_ItemExtIEs = (SI_E1AP_DT_PDU_QoS_Parameters_Support_List_ItemExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_QoS_Parameters_Support_List_ItemExtIEs));
	memset( obj_QoS_Parameters_Support_List_ItemExtIEs, 0, sizeof( SI_E1AP_DT_PDU_QoS_Parameters_Support_List_ItemExtIEs));


	*pQoS_Parameters_Support_List_ItemExtIEs = obj_QoS_Parameters_Support_List_ItemExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_QoS_Flow_QoS_Parameter_Item_ExtIEs( SI_E1AP_DT_PDU_QoS_Flow_QoS_Parameter_Item_ExtIEs ** pQoS_Flow_QoS_Parameter_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_QoS_Flow_QoS_Parameter_Item_ExtIEs * obj_QoS_Flow_QoS_Parameter_Item_ExtIEs = (SI_E1AP_DT_PDU_QoS_Flow_QoS_Parameter_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_QoS_Flow_QoS_Parameter_Item_ExtIEs));
	memset( obj_QoS_Flow_QoS_Parameter_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_QoS_Flow_QoS_Parameter_Item_ExtIEs));

	// RedundantQoSFlowIndicator, PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_QoS_Flow_QoS_Parameter_Item_ExtIEs->redundantQosFlowIndicator = RedundantQoSFlowIndicator_true_val;
	obj_QoS_Flow_QoS_Parameter_Item_ExtIEs->redundantQosFlowIndicator_isset = 1;


	// TSCTrafficCharacteristics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__TSCTrafficCharacteristics( &obj_QoS_Flow_QoS_Parameter_Item_ExtIEs->tSCTrafficCharacteristics);
	obj_QoS_Flow_QoS_Parameter_Item_ExtIEs->tSCTrafficCharacteristics_isset = 1;


	// ECNMarkingorCongestionInformationReportingRequest , PRESENCE = optional   CHOICE
	__si_e1ap__set_testdata__ECNMarkingorCongestionInformationReportingRequest( &obj_QoS_Flow_QoS_Parameter_Item_ExtIEs->eCNMarkingorCongestionInformationReportingRequest);
	obj_QoS_Flow_QoS_Parameter_Item_ExtIEs->eCNMarkingorCongestionInformationReportingRequest->SelectedChoice = ECNMarkingorCongestionInformationReportingRequest_eCNMarkingatNGRAN_val;

	switch( obj_QoS_Flow_QoS_Parameter_Item_ExtIEs->eCNMarkingorCongestionInformationReportingRequest->SelectedChoice)
	{
		case ECNMarkingorCongestionInformationReportingRequest_eCNMarkingatNGRAN_val:
			obj_QoS_Flow_QoS_Parameter_Item_ExtIEs->eCNMarkingorCongestionInformationReportingRequest->u.eCNMarkingatNGRAN = ECNMarkingorCongestionInformationReportingRequest_eCNMarkingatNGRAN_ul_val;
			break;
		case ECNMarkingorCongestionInformationReportingRequest_eCNMarkingatUPF_val:
			obj_QoS_Flow_QoS_Parameter_Item_ExtIEs->eCNMarkingorCongestionInformationReportingRequest->u.eCNMarkingatUPF = ECNMarkingorCongestionInformationReportingRequest_eCNMarkingatUPF_ul_val;
			break;
		case ECNMarkingorCongestionInformationReportingRequest_congestionInformation_val:
			obj_QoS_Flow_QoS_Parameter_Item_ExtIEs->eCNMarkingorCongestionInformationReportingRequest->u.congestionInformation = ECNMarkingorCongestionInformationReportingRequest_congestionInformation_ul_val;
			break;
		case ECNMarkingorCongestionInformationReportingRequest_choice_extension_val:  // L:11477
			{
				__si_e1ap__set_testdata__PDU_ECNMarkingorCongestionInformationReportingRequest_ExtIEs( &obj_QoS_Flow_QoS_Parameter_Item_ExtIEs->eCNMarkingorCongestionInformationReportingRequest->u.choice_extension);   // L:11497
			}
			break;
		default:
			break;
	}

	obj_QoS_Flow_QoS_Parameter_Item_ExtIEs->eCNMarkingorCongestionInformationReportingRequest_isset = 1;



	*pQoS_Flow_QoS_Parameter_Item_ExtIEs = obj_QoS_Flow_QoS_Parameter_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_QoSFlowLevelQoSParameters_ExtIEs( SI_E1AP_DT_PDU_QoSFlowLevelQoSParameters_ExtIEs ** pQoSFlowLevelQoSParameters_ExtIEs)
{
	SI_E1AP_DT_PDU_QoSFlowLevelQoSParameters_ExtIEs * obj_QoSFlowLevelQoSParameters_ExtIEs = (SI_E1AP_DT_PDU_QoSFlowLevelQoSParameters_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_QoSFlowLevelQoSParameters_ExtIEs));
	memset( obj_QoSFlowLevelQoSParameters_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_QoSFlowLevelQoSParameters_ExtIEs));

	// QosMonitoringRequest , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_QoSFlowLevelQoSParameters_ExtIEs->qoSMonitoringRequest = QosMonitoringRequest_ul_val;
	obj_QoSFlowLevelQoSParameters_ExtIEs->qoSMonitoringRequest_isset = 1;


	// GBR-QoSFlowInformation, PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__GBR_QoSFlowInformation( &obj_QoSFlowLevelQoSParameters_ExtIEs->mCGOfferedGBRQoSFlowInfo);
	obj_QoSFlowLevelQoSParameters_ExtIEs->mCGOfferedGBRQoSFlowInfo_isset = 1;


	// QosMonitoringReportingFrequency , PRESENCE = optional  INTEGER , MIN=1, MAX=1800
	obj_QoSFlowLevelQoSParameters_ExtIEs->qosMonitoringReportingFrequency = __getTestINTEGER( 1, 1800);
	obj_QoSFlowLevelQoSParameters_ExtIEs->qosMonitoringReportingFrequency_isset = 1;


	// QosMonitoringDisabled , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_QoSFlowLevelQoSParameters_ExtIEs->qoSMonitoringDisabled = QosMonitoringDisabled_true_val;
	obj_QoSFlowLevelQoSParameters_ExtIEs->qoSMonitoringDisabled_isset = 1;


	// TransportLayerAddress  , PRESENCE = optional   BITSTRING , MIN=1, MAX=160
	__si_e1ap_init_TransportLayerAddress2( &obj_QoSFlowLevelQoSParameters_ExtIEs->dataForwardingSourceIPAddress, "3", 1, 1);
	obj_QoSFlowLevelQoSParameters_ExtIEs->dataForwardingSourceIPAddress->bitslen = 1;
	obj_QoSFlowLevelQoSParameters_ExtIEs->dataForwardingSourceIPAddress_isset = 1;


	// PDUSetQoSParameters , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__PDUSetQoSParameters( &obj_QoSFlowLevelQoSParameters_ExtIEs->pDUSetQoSParameters);
	obj_QoSFlowLevelQoSParameters_ExtIEs->pDUSetQoSParameters_isset = 1;



	*pQoSFlowLevelQoSParameters_ExtIEs = obj_QoSFlowLevelQoSParameters_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_QoS_Flow_Removed_Item_ExtIEs( SI_E1AP_DT_PDU_QoS_Flow_Removed_Item_ExtIEs ** pQoS_Flow_Removed_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_QoS_Flow_Removed_Item_ExtIEs * obj_QoS_Flow_Removed_Item_ExtIEs = (SI_E1AP_DT_PDU_QoS_Flow_Removed_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_QoS_Flow_Removed_Item_ExtIEs));
	memset( obj_QoS_Flow_Removed_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_QoS_Flow_Removed_Item_ExtIEs));


	*pQoS_Flow_Removed_Item_ExtIEs = obj_QoS_Flow_Removed_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_QoS_Flows_to_be_forwarded_Item_ExtIEs( SI_E1AP_DT_PDU_QoS_Flows_to_be_forwarded_Item_ExtIEs ** pQoS_Flows_to_be_forwarded_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_QoS_Flows_to_be_forwarded_Item_ExtIEs * obj_QoS_Flows_to_be_forwarded_Item_ExtIEs = (SI_E1AP_DT_PDU_QoS_Flows_to_be_forwarded_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_QoS_Flows_to_be_forwarded_Item_ExtIEs));
	memset( obj_QoS_Flows_to_be_forwarded_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_QoS_Flows_to_be_forwarded_Item_ExtIEs));


	*pQoS_Flows_to_be_forwarded_Item_ExtIEs = obj_QoS_Flows_to_be_forwarded_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_DataForwardingtoNG_RANQoSFlowInformationList_Item_ExtIEs( SI_E1AP_DT_PDU_DataForwardingtoNG_RANQoSFlowInformationList_Item_ExtIEs ** pDataForwardingtoNG_RANQoSFlowInformationList_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_DataForwardingtoNG_RANQoSFlowInformationList_Item_ExtIEs * obj_DataForwardingtoNG_RANQoSFlowInformationList_Item_ExtIEs = (SI_E1AP_DT_PDU_DataForwardingtoNG_RANQoSFlowInformationList_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DataForwardingtoNG_RANQoSFlowInformationList_Item_ExtIEs));
	memset( obj_DataForwardingtoNG_RANQoSFlowInformationList_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_DataForwardingtoNG_RANQoSFlowInformationList_Item_ExtIEs));


	*pDataForwardingtoNG_RANQoSFlowInformationList_Item_ExtIEs = obj_DataForwardingtoNG_RANQoSFlowInformationList_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_RedundantPDUSessionInformation_ExtIEs( SI_E1AP_DT_PDU_RedundantPDUSessionInformation_ExtIEs ** pRedundantPDUSessionInformation_ExtIEs)
{
	SI_E1AP_DT_PDU_RedundantPDUSessionInformation_ExtIEs * obj_RedundantPDUSessionInformation_ExtIEs = (SI_E1AP_DT_PDU_RedundantPDUSessionInformation_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_RedundantPDUSessionInformation_ExtIEs));
	memset( obj_RedundantPDUSessionInformation_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_RedundantPDUSessionInformation_ExtIEs));

	// PDUSession-PairID , PRESENCE = optional  INTEGER , MIN=0, MAX=255
	obj_RedundantPDUSessionInformation_ExtIEs->pDUSessionPairID = __getTestINTEGER( 0, 255);
	obj_RedundantPDUSessionInformation_ExtIEs->pDUSessionPairID_isset = 1;



	*pRedundantPDUSessionInformation_ExtIEs = obj_RedundantPDUSessionInformation_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_ROHC_Parameters_ExtIEs( SI_E1AP_DT_PDU_ROHC_Parameters_ExtIEs ** pROHC_Parameters_ExtIEs)
{
	SI_E1AP_DT_PDU_ROHC_Parameters_ExtIEs * obj_ROHC_Parameters_ExtIEs = (SI_E1AP_DT_PDU_ROHC_Parameters_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_ROHC_Parameters_ExtIEs));
	memset( obj_ROHC_Parameters_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_ROHC_Parameters_ExtIEs));


	*pROHC_Parameters_ExtIEs = obj_ROHC_Parameters_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_ROHC_ExtIEs( SI_E1AP_DT_PDU_ROHC_ExtIEs ** pROHC_ExtIEs)
{
	SI_E1AP_DT_PDU_ROHC_ExtIEs * obj_ROHC_ExtIEs = (SI_E1AP_DT_PDU_ROHC_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_ROHC_ExtIEs));
	memset( obj_ROHC_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_ROHC_ExtIEs));


	*pROHC_ExtIEs = obj_ROHC_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_SecurityAlgorithm_ExtIEs( SI_E1AP_DT_PDU_SecurityAlgorithm_ExtIEs ** pSecurityAlgorithm_ExtIEs)
{
	SI_E1AP_DT_PDU_SecurityAlgorithm_ExtIEs * obj_SecurityAlgorithm_ExtIEs = (SI_E1AP_DT_PDU_SecurityAlgorithm_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_SecurityAlgorithm_ExtIEs));
	memset( obj_SecurityAlgorithm_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_SecurityAlgorithm_ExtIEs));


	*pSecurityAlgorithm_ExtIEs = obj_SecurityAlgorithm_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_SecurityIndication_ExtIEs( SI_E1AP_DT_PDU_SecurityIndication_ExtIEs ** pSecurityIndication_ExtIEs)
{
	SI_E1AP_DT_PDU_SecurityIndication_ExtIEs * obj_SecurityIndication_ExtIEs = (SI_E1AP_DT_PDU_SecurityIndication_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_SecurityIndication_ExtIEs));
	memset( obj_SecurityIndication_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_SecurityIndication_ExtIEs));


	*pSecurityIndication_ExtIEs = obj_SecurityIndication_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_SecurityInformation_ExtIEs( SI_E1AP_DT_PDU_SecurityInformation_ExtIEs ** pSecurityInformation_ExtIEs)
{
	SI_E1AP_DT_PDU_SecurityInformation_ExtIEs * obj_SecurityInformation_ExtIEs = (SI_E1AP_DT_PDU_SecurityInformation_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_SecurityInformation_ExtIEs));
	memset( obj_SecurityInformation_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_SecurityInformation_ExtIEs));


	*pSecurityInformation_ExtIEs = obj_SecurityInformation_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_SecurityResult_ExtIEs( SI_E1AP_DT_PDU_SecurityResult_ExtIEs ** pSecurityResult_ExtIEs)
{
	SI_E1AP_DT_PDU_SecurityResult_ExtIEs * obj_SecurityResult_ExtIEs = (SI_E1AP_DT_PDU_SecurityResult_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_SecurityResult_ExtIEs));
	memset( obj_SecurityResult_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_SecurityResult_ExtIEs));


	*pSecurityResult_ExtIEs = obj_SecurityResult_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_Slice_Support_Item_ExtIEs( SI_E1AP_DT_PDU_Slice_Support_Item_ExtIEs ** pSlice_Support_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_Slice_Support_Item_ExtIEs * obj_Slice_Support_Item_ExtIEs = (SI_E1AP_DT_PDU_Slice_Support_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Slice_Support_Item_ExtIEs));
	memset( obj_Slice_Support_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_Slice_Support_Item_ExtIEs));


	*pSlice_Support_Item_ExtIEs = obj_Slice_Support_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_SNSSAI_ExtIEs( SI_E1AP_DT_PDU_SNSSAI_ExtIEs ** pSNSSAI_ExtIEs)
{
	SI_E1AP_DT_PDU_SNSSAI_ExtIEs * obj_SNSSAI_ExtIEs = (SI_E1AP_DT_PDU_SNSSAI_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_SNSSAI_ExtIEs));
	memset( obj_SNSSAI_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_SNSSAI_ExtIEs));


	*pSNSSAI_ExtIEs = obj_SNSSAI_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_SDAP_Configuration_ExtIEs( SI_E1AP_DT_PDU_SDAP_Configuration_ExtIEs ** pSDAP_Configuration_ExtIEs)
{
	SI_E1AP_DT_PDU_SDAP_Configuration_ExtIEs * obj_SDAP_Configuration_ExtIEs = (SI_E1AP_DT_PDU_SDAP_Configuration_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_SDAP_Configuration_ExtIEs));
	memset( obj_SDAP_Configuration_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_SDAP_Configuration_ExtIEs));


	*pSDAP_Configuration_ExtIEs = obj_SDAP_Configuration_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_TNL_AvailableCapacityIndicator_ExtIEs( SI_E1AP_DT_PDU_TNL_AvailableCapacityIndicator_ExtIEs ** pTNL_AvailableCapacityIndicator_ExtIEs)
{
	SI_E1AP_DT_PDU_TNL_AvailableCapacityIndicator_ExtIEs * obj_TNL_AvailableCapacityIndicator_ExtIEs = (SI_E1AP_DT_PDU_TNL_AvailableCapacityIndicator_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_TNL_AvailableCapacityIndicator_ExtIEs));
	memset( obj_TNL_AvailableCapacityIndicator_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_TNL_AvailableCapacityIndicator_ExtIEs));


	*pTNL_AvailableCapacityIndicator_ExtIEs = obj_TNL_AvailableCapacityIndicator_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_TSCTrafficCharacteristics_ExtIEs( SI_E1AP_DT_PDU_TSCTrafficCharacteristics_ExtIEs ** pTSCTrafficCharacteristics_ExtIEs)
{
	SI_E1AP_DT_PDU_TSCTrafficCharacteristics_ExtIEs * obj_TSCTrafficCharacteristics_ExtIEs = (SI_E1AP_DT_PDU_TSCTrafficCharacteristics_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_TSCTrafficCharacteristics_ExtIEs));
	memset( obj_TSCTrafficCharacteristics_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_TSCTrafficCharacteristics_ExtIEs));


	*pTSCTrafficCharacteristics_ExtIEs = obj_TSCTrafficCharacteristics_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_TSCAssistanceInformation_ExtIEs( SI_E1AP_DT_PDU_TSCAssistanceInformation_ExtIEs ** pTSCAssistanceInformation_ExtIEs)
{
	SI_E1AP_DT_PDU_TSCAssistanceInformation_ExtIEs * obj_TSCAssistanceInformation_ExtIEs = (SI_E1AP_DT_PDU_TSCAssistanceInformation_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_TSCAssistanceInformation_ExtIEs));
	memset( obj_TSCAssistanceInformation_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_TSCAssistanceInformation_ExtIEs));

	// SurvivalTime , PRESENCE = optional  INTEGER , MIN=0, MAX=1920000
	obj_TSCAssistanceInformation_ExtIEs->survivalTime = __getTestINTEGER( 0, 1920000);
	obj_TSCAssistanceInformation_ExtIEs->survivalTime_isset = 1;


	// N6JitterInformation , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__N6JitterInformation( &obj_TSCAssistanceInformation_ExtIEs->n6JitterInformation);
	obj_TSCAssistanceInformation_ExtIEs->n6JitterInformation_isset = 1;



	*pTSCAssistanceInformation_ExtIEs = obj_TSCAssistanceInformation_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_TraceActivation_ExtIEs( SI_E1AP_DT_PDU_TraceActivation_ExtIEs ** pTraceActivation_ExtIEs)
{
	SI_E1AP_DT_PDU_TraceActivation_ExtIEs * obj_TraceActivation_ExtIEs = (SI_E1AP_DT_PDU_TraceActivation_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_TraceActivation_ExtIEs));
	memset( obj_TraceActivation_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_TraceActivation_ExtIEs));

	// MDT-Configuration , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__MDT_Configuration( &obj_TraceActivation_ExtIEs->mDTConfiguration);
	obj_TraceActivation_ExtIEs->mDTConfiguration_isset = 1;


	// URIaddress    PrintableString, PRESENCE = optional , MIN=0, MAX=0
	__si_e1ap_init_URIaddress2( &obj_TraceActivation_ExtIEs->traceCollectionEntityURI, "aeiou", 5);
	obj_TraceActivation_ExtIEs->traceCollectionEntityURI_isset = 1;



	*pTraceActivation_ExtIEs = obj_TraceActivation_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_T_ReorderingTimer_ExtIEs( SI_E1AP_DT_PDU_T_ReorderingTimer_ExtIEs ** pT_ReorderingTimer_ExtIEs)
{
	SI_E1AP_DT_PDU_T_ReorderingTimer_ExtIEs * obj_T_ReorderingTimer_ExtIEs = (SI_E1AP_DT_PDU_T_ReorderingTimer_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_T_ReorderingTimer_ExtIEs));
	memset( obj_T_ReorderingTimer_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_T_ReorderingTimer_ExtIEs));


	*pT_ReorderingTimer_ExtIEs = obj_T_ReorderingTimer_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_Transport_Layer_Address_Info_ExtIEs( SI_E1AP_DT_PDU_Transport_Layer_Address_Info_ExtIEs ** pTransport_Layer_Address_Info_ExtIEs)
{
	SI_E1AP_DT_PDU_Transport_Layer_Address_Info_ExtIEs * obj_Transport_Layer_Address_Info_ExtIEs = (SI_E1AP_DT_PDU_Transport_Layer_Address_Info_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Transport_Layer_Address_Info_ExtIEs));
	memset( obj_Transport_Layer_Address_Info_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_Transport_Layer_Address_Info_ExtIEs));


	*pTransport_Layer_Address_Info_ExtIEs = obj_Transport_Layer_Address_Info_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_Transport_UP_Layer_Addresses_Info_To_Add_ItemExtIEs( SI_E1AP_DT_PDU_Transport_UP_Layer_Addresses_Info_To_Add_ItemExtIEs ** pTransport_UP_Layer_Addresses_Info_To_Add_ItemExtIEs)
{
	SI_E1AP_DT_PDU_Transport_UP_Layer_Addresses_Info_To_Add_ItemExtIEs * obj_Transport_UP_Layer_Addresses_Info_To_Add_ItemExtIEs = (SI_E1AP_DT_PDU_Transport_UP_Layer_Addresses_Info_To_Add_ItemExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Transport_UP_Layer_Addresses_Info_To_Add_ItemExtIEs));
	memset( obj_Transport_UP_Layer_Addresses_Info_To_Add_ItemExtIEs, 0, sizeof( SI_E1AP_DT_PDU_Transport_UP_Layer_Addresses_Info_To_Add_ItemExtIEs));


	*pTransport_UP_Layer_Addresses_Info_To_Add_ItemExtIEs = obj_Transport_UP_Layer_Addresses_Info_To_Add_ItemExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_Transport_UP_Layer_Addresses_Info_To_Remove_ItemExtIEs( SI_E1AP_DT_PDU_Transport_UP_Layer_Addresses_Info_To_Remove_ItemExtIEs ** pTransport_UP_Layer_Addresses_Info_To_Remove_ItemExtIEs)
{
	SI_E1AP_DT_PDU_Transport_UP_Layer_Addresses_Info_To_Remove_ItemExtIEs * obj_Transport_UP_Layer_Addresses_Info_To_Remove_ItemExtIEs = (SI_E1AP_DT_PDU_Transport_UP_Layer_Addresses_Info_To_Remove_ItemExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Transport_UP_Layer_Addresses_Info_To_Remove_ItemExtIEs));
	memset( obj_Transport_UP_Layer_Addresses_Info_To_Remove_ItemExtIEs, 0, sizeof( SI_E1AP_DT_PDU_Transport_UP_Layer_Addresses_Info_To_Remove_ItemExtIEs));


	*pTransport_UP_Layer_Addresses_Info_To_Remove_ItemExtIEs = obj_Transport_UP_Layer_Addresses_Info_To_Remove_ItemExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_UDC_Parameters_ExtIEs( SI_E1AP_DT_PDU_UDC_Parameters_ExtIEs ** pUDC_Parameters_ExtIEs)
{
	SI_E1AP_DT_PDU_UDC_Parameters_ExtIEs * obj_UDC_Parameters_ExtIEs = (SI_E1AP_DT_PDU_UDC_Parameters_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_UDC_Parameters_ExtIEs));
	memset( obj_UDC_Parameters_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_UDC_Parameters_ExtIEs));

	// UDC_Parameters_ExtIEs_id_VersionID , PRESENCE = optional  INTEGER , MIN=0, MAX=15
	obj_UDC_Parameters_ExtIEs->versionID = __getTestINTEGER( 0, 15);
	obj_UDC_Parameters_ExtIEs->versionID_isset = 1;



	*pUDC_Parameters_ExtIEs = obj_UDC_Parameters_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_UE_associatedLogicalE1_ConnectionItemExtIEs( SI_E1AP_DT_PDU_UE_associatedLogicalE1_ConnectionItemExtIEs ** pUE_associatedLogicalE1_ConnectionItemExtIEs)
{
	SI_E1AP_DT_PDU_UE_associatedLogicalE1_ConnectionItemExtIEs * obj_UE_associatedLogicalE1_ConnectionItemExtIEs = (SI_E1AP_DT_PDU_UE_associatedLogicalE1_ConnectionItemExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_UE_associatedLogicalE1_ConnectionItemExtIEs));
	memset( obj_UE_associatedLogicalE1_ConnectionItemExtIEs, 0, sizeof( SI_E1AP_DT_PDU_UE_associatedLogicalE1_ConnectionItemExtIEs));


	*pUE_associatedLogicalE1_ConnectionItemExtIEs = obj_UE_associatedLogicalE1_ConnectionItemExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_UESliceMaximumBitRateItem_ExtIEs( SI_E1AP_DT_PDU_UESliceMaximumBitRateItem_ExtIEs ** pUESliceMaximumBitRateItem_ExtIEs)
{
	SI_E1AP_DT_PDU_UESliceMaximumBitRateItem_ExtIEs * obj_UESliceMaximumBitRateItem_ExtIEs = (SI_E1AP_DT_PDU_UESliceMaximumBitRateItem_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_UESliceMaximumBitRateItem_ExtIEs));
	memset( obj_UESliceMaximumBitRateItem_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_UESliceMaximumBitRateItem_ExtIEs));


	*pUESliceMaximumBitRateItem_ExtIEs = obj_UESliceMaximumBitRateItem_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_ULUPTNLAddressToUpdateItemExtIEs( SI_E1AP_DT_PDU_ULUPTNLAddressToUpdateItemExtIEs ** pULUPTNLAddressToUpdateItemExtIEs)
{
	SI_E1AP_DT_PDU_ULUPTNLAddressToUpdateItemExtIEs * obj_ULUPTNLAddressToUpdateItemExtIEs = (SI_E1AP_DT_PDU_ULUPTNLAddressToUpdateItemExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_ULUPTNLAddressToUpdateItemExtIEs));
	memset( obj_ULUPTNLAddressToUpdateItemExtIEs, 0, sizeof( SI_E1AP_DT_PDU_ULUPTNLAddressToUpdateItemExtIEs));


	*pULUPTNLAddressToUpdateItemExtIEs = obj_ULUPTNLAddressToUpdateItemExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_UP_Parameters_Item_ExtIEs( SI_E1AP_DT_PDU_UP_Parameters_Item_ExtIEs ** pUP_Parameters_Item_ExtIEs)
{
	SI_E1AP_DT_PDU_UP_Parameters_Item_ExtIEs * obj_UP_Parameters_Item_ExtIEs = (SI_E1AP_DT_PDU_UP_Parameters_Item_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_UP_Parameters_Item_ExtIEs));
	memset( obj_UP_Parameters_Item_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_UP_Parameters_Item_ExtIEs));

	// QoS-Mapping-Information , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__QoS_Mapping_Information( &obj_UP_Parameters_Item_ExtIEs->qoSMappingInformation);
	obj_UP_Parameters_Item_ExtIEs->qoSMappingInformation_isset = 1;


	// IndirectPathIndication , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_UP_Parameters_Item_ExtIEs->indirectPathIndication = IndirectPathIndication_true_val;
	obj_UP_Parameters_Item_ExtIEs->indirectPathIndication_isset = 1;



	*pUP_Parameters_Item_ExtIEs = obj_UP_Parameters_Item_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_UPSecuritykey_ExtIEs( SI_E1AP_DT_PDU_UPSecuritykey_ExtIEs ** pUPSecuritykey_ExtIEs)
{
	SI_E1AP_DT_PDU_UPSecuritykey_ExtIEs * obj_UPSecuritykey_ExtIEs = (SI_E1AP_DT_PDU_UPSecuritykey_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_UPSecuritykey_ExtIEs));
	memset( obj_UPSecuritykey_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_UPSecuritykey_ExtIEs));


	*pUPSecuritykey_ExtIEs = obj_UPSecuritykey_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_UP_TNL_Information_ExtIEs( SI_E1AP_DT_PDU_UP_TNL_Information_ExtIEs ** pUP_TNL_Information_ExtIEs)
{
	SI_E1AP_DT_PDU_UP_TNL_Information_ExtIEs * obj_UP_TNL_Information_ExtIEs = (SI_E1AP_DT_PDU_UP_TNL_Information_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_UP_TNL_Information_ExtIEs));
	memset( obj_UP_TNL_Information_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_UP_TNL_Information_ExtIEs));


	*pUP_TNL_Information_ExtIEs = obj_UP_TNL_Information_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_UplinkOnlyROHC_ExtIEs( SI_E1AP_DT_PDU_UplinkOnlyROHC_ExtIEs ** pUplinkOnlyROHC_ExtIEs)
{
	SI_E1AP_DT_PDU_UplinkOnlyROHC_ExtIEs * obj_UplinkOnlyROHC_ExtIEs = (SI_E1AP_DT_PDU_UplinkOnlyROHC_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_UplinkOnlyROHC_ExtIEs));
	memset( obj_UplinkOnlyROHC_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_UplinkOnlyROHC_ExtIEs));


	*pUplinkOnlyROHC_ExtIEs = obj_UplinkOnlyROHC_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_UserPlaneFailureIndication_ExtIEs( SI_E1AP_DT_PDU_UserPlaneFailureIndication_ExtIEs ** pUserPlaneFailureIndication_ExtIEs)
{
	SI_E1AP_DT_PDU_UserPlaneFailureIndication_ExtIEs * obj_UserPlaneFailureIndication_ExtIEs = (SI_E1AP_DT_PDU_UserPlaneFailureIndication_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_UserPlaneFailureIndication_ExtIEs));
	memset( obj_UserPlaneFailureIndication_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_UserPlaneFailureIndication_ExtIEs));


	*pUserPlaneFailureIndication_ExtIEs = obj_UserPlaneFailureIndication_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_ResetType_ExtIEs( SI_E1AP_DT_PDU_ResetType_ExtIEs ** pResetType_ExtIEs)
{
	SI_E1AP_DT_PDU_ResetType_ExtIEs * obj_ResetType_ExtIEs = (SI_E1AP_DT_PDU_ResetType_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_ResetType_ExtIEs));
	memset( obj_ResetType_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_ResetType_ExtIEs));


	*pResetType_ExtIEs = obj_ResetType_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_System_BearerContextSetupRequest_ExtIEs( SI_E1AP_DT_PDU_System_BearerContextSetupRequest_ExtIEs ** pSystem_BearerContextSetupRequest_ExtIEs)
{
	SI_E1AP_DT_PDU_System_BearerContextSetupRequest_ExtIEs * obj_System_BearerContextSetupRequest_ExtIEs = (SI_E1AP_DT_PDU_System_BearerContextSetupRequest_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_System_BearerContextSetupRequest_ExtIEs));
	memset( obj_System_BearerContextSetupRequest_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_System_BearerContextSetupRequest_ExtIEs));


	*pSystem_BearerContextSetupRequest_ExtIEs = obj_System_BearerContextSetupRequest_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_EUTRAN_BearerContextSetupRequest( SI_E1AP_DT_PDU_EUTRAN_BearerContextSetupRequest ** pEUTRAN_BearerContextSetupRequest)
{
	SI_E1AP_DT_PDU_EUTRAN_BearerContextSetupRequest * obj_EUTRAN_BearerContextSetupRequest = (SI_E1AP_DT_PDU_EUTRAN_BearerContextSetupRequest*) __si_allocM( sizeof(SI_E1AP_DT_PDU_EUTRAN_BearerContextSetupRequest));
	memset( obj_EUTRAN_BearerContextSetupRequest, 0, sizeof( SI_E1AP_DT_PDU_EUTRAN_BearerContextSetupRequest));

	// DRB-To-Setup-List-EUTRAN , PRESENCE = mandatory   SEQUENCE_OF
	__si_e1ap__set_testdata__DRB_To_Setup_List_EUTRAN( &obj_EUTRAN_BearerContextSetupRequest->dRBToSetupListEUTRAN);
	obj_EUTRAN_BearerContextSetupRequest->dRBToSetupListEUTRAN_isset = 1;


	// SubscriberProfileIDforRFP , PRESENCE = optional  INTEGER , MIN=1, MAX=256
	obj_EUTRAN_BearerContextSetupRequest->subscriberProfileIDforRFP = __getTestINTEGER( 1, 256);
	obj_EUTRAN_BearerContextSetupRequest->subscriberProfileIDforRFP_isset = 1;


	// AdditionalRRMPriorityIndex , PRESENCE = optional   BITSTRING , MIN=32, MAX=32
	__si_e1ap_init_AdditionalRRMPriorityIndex2( &obj_EUTRAN_BearerContextSetupRequest->additionalRRMPriorityIndex, "4883", 4, 32);
	obj_EUTRAN_BearerContextSetupRequest->additionalRRMPriorityIndex->bitslen = 32;
	obj_EUTRAN_BearerContextSetupRequest->additionalRRMPriorityIndex_isset = 1;



	*pEUTRAN_BearerContextSetupRequest = obj_EUTRAN_BearerContextSetupRequest;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_NG_RAN_BearerContextSetupRequest( SI_E1AP_DT_PDU_NG_RAN_BearerContextSetupRequest ** pNG_RAN_BearerContextSetupRequest)
{
	SI_E1AP_DT_PDU_NG_RAN_BearerContextSetupRequest * obj_NG_RAN_BearerContextSetupRequest = (SI_E1AP_DT_PDU_NG_RAN_BearerContextSetupRequest*) __si_allocM( sizeof(SI_E1AP_DT_PDU_NG_RAN_BearerContextSetupRequest));
	memset( obj_NG_RAN_BearerContextSetupRequest, 0, sizeof( SI_E1AP_DT_PDU_NG_RAN_BearerContextSetupRequest));

	// PDU-Session-Resource-To-Setup-List , PRESENCE = mandatory   SEQUENCE_OF
	__si_e1ap__set_testdata__PDU_Session_Resource_To_Setup_List( &obj_NG_RAN_BearerContextSetupRequest->pDUSessionResourceToSetupList);
	obj_NG_RAN_BearerContextSetupRequest->pDUSessionResourceToSetupList_isset = 1;



	*pNG_RAN_BearerContextSetupRequest = obj_NG_RAN_BearerContextSetupRequest;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_System_BearerContextSetupResponse_ExtIEs( SI_E1AP_DT_PDU_System_BearerContextSetupResponse_ExtIEs ** pSystem_BearerContextSetupResponse_ExtIEs)
{
	SI_E1AP_DT_PDU_System_BearerContextSetupResponse_ExtIEs * obj_System_BearerContextSetupResponse_ExtIEs = (SI_E1AP_DT_PDU_System_BearerContextSetupResponse_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_System_BearerContextSetupResponse_ExtIEs));
	memset( obj_System_BearerContextSetupResponse_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_System_BearerContextSetupResponse_ExtIEs));


	*pSystem_BearerContextSetupResponse_ExtIEs = obj_System_BearerContextSetupResponse_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_EUTRAN_BearerContextSetupResponse( SI_E1AP_DT_PDU_EUTRAN_BearerContextSetupResponse ** pEUTRAN_BearerContextSetupResponse)
{
	SI_E1AP_DT_PDU_EUTRAN_BearerContextSetupResponse * obj_EUTRAN_BearerContextSetupResponse = (SI_E1AP_DT_PDU_EUTRAN_BearerContextSetupResponse*) __si_allocM( sizeof(SI_E1AP_DT_PDU_EUTRAN_BearerContextSetupResponse));
	memset( obj_EUTRAN_BearerContextSetupResponse, 0, sizeof( SI_E1AP_DT_PDU_EUTRAN_BearerContextSetupResponse));

	// DRB-Setup-List-EUTRAN , PRESENCE = mandatory   SEQUENCE_OF
	__si_e1ap__set_testdata__DRB_Setup_List_EUTRAN( &obj_EUTRAN_BearerContextSetupResponse->dRBSetupListEUTRAN);
	obj_EUTRAN_BearerContextSetupResponse->dRBSetupListEUTRAN_isset = 1;


	// DRB-Failed-List-EUTRAN , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__DRB_Failed_List_EUTRAN( &obj_EUTRAN_BearerContextSetupResponse->dRBFailedListEUTRAN);
	obj_EUTRAN_BearerContextSetupResponse->dRBFailedListEUTRAN_isset = 1;



	*pEUTRAN_BearerContextSetupResponse = obj_EUTRAN_BearerContextSetupResponse;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_NG_RAN_BearerContextSetupResponse( SI_E1AP_DT_PDU_NG_RAN_BearerContextSetupResponse ** pNG_RAN_BearerContextSetupResponse)
{
	SI_E1AP_DT_PDU_NG_RAN_BearerContextSetupResponse * obj_NG_RAN_BearerContextSetupResponse = (SI_E1AP_DT_PDU_NG_RAN_BearerContextSetupResponse*) __si_allocM( sizeof(SI_E1AP_DT_PDU_NG_RAN_BearerContextSetupResponse));
	memset( obj_NG_RAN_BearerContextSetupResponse, 0, sizeof( SI_E1AP_DT_PDU_NG_RAN_BearerContextSetupResponse));

	// PDU-Session-Resource-Setup-List , PRESENCE = mandatory   SEQUENCE_OF
	__si_e1ap__set_testdata__PDU_Session_Resource_Setup_List( &obj_NG_RAN_BearerContextSetupResponse->pDUSessionResourceSetupList);
	obj_NG_RAN_BearerContextSetupResponse->pDUSessionResourceSetupList_isset = 1;


	// PDU-Session-Resource-Failed-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__PDU_Session_Resource_Failed_List( &obj_NG_RAN_BearerContextSetupResponse->pDUSessionResourceFailedList);
	obj_NG_RAN_BearerContextSetupResponse->pDUSessionResourceFailedList_isset = 1;



	*pNG_RAN_BearerContextSetupResponse = obj_NG_RAN_BearerContextSetupResponse;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_System_BearerContextModificationRequest_ExtIEs( SI_E1AP_DT_PDU_System_BearerContextModificationRequest_ExtIEs ** pSystem_BearerContextModificationRequest_ExtIEs)
{
	SI_E1AP_DT_PDU_System_BearerContextModificationRequest_ExtIEs * obj_System_BearerContextModificationRequest_ExtIEs = (SI_E1AP_DT_PDU_System_BearerContextModificationRequest_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_System_BearerContextModificationRequest_ExtIEs));
	memset( obj_System_BearerContextModificationRequest_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_System_BearerContextModificationRequest_ExtIEs));


	*pSystem_BearerContextModificationRequest_ExtIEs = obj_System_BearerContextModificationRequest_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_EUTRAN_BearerContextModificationRequest( SI_E1AP_DT_PDU_EUTRAN_BearerContextModificationRequest ** pEUTRAN_BearerContextModificationRequest)
{
	SI_E1AP_DT_PDU_EUTRAN_BearerContextModificationRequest * obj_EUTRAN_BearerContextModificationRequest = (SI_E1AP_DT_PDU_EUTRAN_BearerContextModificationRequest*) __si_allocM( sizeof(SI_E1AP_DT_PDU_EUTRAN_BearerContextModificationRequest));
	memset( obj_EUTRAN_BearerContextModificationRequest, 0, sizeof( SI_E1AP_DT_PDU_EUTRAN_BearerContextModificationRequest));

	// DRB-To-Setup-Mod-List-EUTRAN , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__DRB_To_Setup_Mod_List_EUTRAN( &obj_EUTRAN_BearerContextModificationRequest->dRBToSetupModListEUTRAN);
	obj_EUTRAN_BearerContextModificationRequest->dRBToSetupModListEUTRAN_isset = 1;


	// DRB-To-Modify-List-EUTRAN , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__DRB_To_Modify_List_EUTRAN( &obj_EUTRAN_BearerContextModificationRequest->dRBToModifyListEUTRAN);
	obj_EUTRAN_BearerContextModificationRequest->dRBToModifyListEUTRAN_isset = 1;


	// DRB-To-Remove-List-EUTRAN , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__DRB_To_Remove_List_EUTRAN( &obj_EUTRAN_BearerContextModificationRequest->dRBToRemoveListEUTRAN);
	obj_EUTRAN_BearerContextModificationRequest->dRBToRemoveListEUTRAN_isset = 1;


	// SubscriberProfileIDforRFP , PRESENCE = optional  INTEGER , MIN=1, MAX=256
	obj_EUTRAN_BearerContextModificationRequest->subscriberProfileIDforRFP = __getTestINTEGER( 1, 256);
	obj_EUTRAN_BearerContextModificationRequest->subscriberProfileIDforRFP_isset = 1;


	// AdditionalRRMPriorityIndex , PRESENCE = optional   BITSTRING , MIN=32, MAX=32
	__si_e1ap_init_AdditionalRRMPriorityIndex2( &obj_EUTRAN_BearerContextModificationRequest->additionalRRMPriorityIndex, "9029", 4, 32);
	obj_EUTRAN_BearerContextModificationRequest->additionalRRMPriorityIndex->bitslen = 32;
	obj_EUTRAN_BearerContextModificationRequest->additionalRRMPriorityIndex_isset = 1;



	*pEUTRAN_BearerContextModificationRequest = obj_EUTRAN_BearerContextModificationRequest;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_NG_RAN_BearerContextModificationRequest( SI_E1AP_DT_PDU_NG_RAN_BearerContextModificationRequest ** pNG_RAN_BearerContextModificationRequest)
{
	SI_E1AP_DT_PDU_NG_RAN_BearerContextModificationRequest * obj_NG_RAN_BearerContextModificationRequest = (SI_E1AP_DT_PDU_NG_RAN_BearerContextModificationRequest*) __si_allocM( sizeof(SI_E1AP_DT_PDU_NG_RAN_BearerContextModificationRequest));
	memset( obj_NG_RAN_BearerContextModificationRequest, 0, sizeof( SI_E1AP_DT_PDU_NG_RAN_BearerContextModificationRequest));

	// PDU-Session-Resource-To-Setup-Mod-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__PDU_Session_Resource_To_Setup_Mod_List( &obj_NG_RAN_BearerContextModificationRequest->pDUSessionResourceToSetupModList);
	obj_NG_RAN_BearerContextModificationRequest->pDUSessionResourceToSetupModList_isset = 1;


	// PDU-Session-Resource-To-Modify-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__PDU_Session_Resource_To_Modify_List( &obj_NG_RAN_BearerContextModificationRequest->pDUSessionResourceToModifyList);
	obj_NG_RAN_BearerContextModificationRequest->pDUSessionResourceToModifyList_isset = 1;


	// PDU-Session-Resource-To-Remove-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__PDU_Session_Resource_To_Remove_List( &obj_NG_RAN_BearerContextModificationRequest->pDUSessionResourceToRemoveList);
	obj_NG_RAN_BearerContextModificationRequest->pDUSessionResourceToRemoveList_isset = 1;



	*pNG_RAN_BearerContextModificationRequest = obj_NG_RAN_BearerContextModificationRequest;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_System_BearerContextModificationResponse_ExtIEs( SI_E1AP_DT_PDU_System_BearerContextModificationResponse_ExtIEs ** pSystem_BearerContextModificationResponse_ExtIEs)
{
	SI_E1AP_DT_PDU_System_BearerContextModificationResponse_ExtIEs * obj_System_BearerContextModificationResponse_ExtIEs = (SI_E1AP_DT_PDU_System_BearerContextModificationResponse_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_System_BearerContextModificationResponse_ExtIEs));
	memset( obj_System_BearerContextModificationResponse_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_System_BearerContextModificationResponse_ExtIEs));


	*pSystem_BearerContextModificationResponse_ExtIEs = obj_System_BearerContextModificationResponse_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_EUTRAN_BearerContextModificationResponse( SI_E1AP_DT_PDU_EUTRAN_BearerContextModificationResponse ** pEUTRAN_BearerContextModificationResponse)
{
	SI_E1AP_DT_PDU_EUTRAN_BearerContextModificationResponse * obj_EUTRAN_BearerContextModificationResponse = (SI_E1AP_DT_PDU_EUTRAN_BearerContextModificationResponse*) __si_allocM( sizeof(SI_E1AP_DT_PDU_EUTRAN_BearerContextModificationResponse));
	memset( obj_EUTRAN_BearerContextModificationResponse, 0, sizeof( SI_E1AP_DT_PDU_EUTRAN_BearerContextModificationResponse));

	// DRB-Setup-Mod-List-EUTRAN , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__DRB_Setup_Mod_List_EUTRAN( &obj_EUTRAN_BearerContextModificationResponse->dRBSetupModListEUTRAN);
	obj_EUTRAN_BearerContextModificationResponse->dRBSetupModListEUTRAN_isset = 1;


	// DRB-Failed-Mod-List-EUTRAN , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__DRB_Failed_Mod_List_EUTRAN( &obj_EUTRAN_BearerContextModificationResponse->dRBFailedModListEUTRAN);
	obj_EUTRAN_BearerContextModificationResponse->dRBFailedModListEUTRAN_isset = 1;


	// DRB-Modified-List-EUTRAN , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__DRB_Modified_List_EUTRAN( &obj_EUTRAN_BearerContextModificationResponse->dRBModifiedListEUTRAN);
	obj_EUTRAN_BearerContextModificationResponse->dRBModifiedListEUTRAN_isset = 1;


	// DRB-Failed-To-Modify-List-EUTRAN , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__DRB_Failed_To_Modify_List_EUTRAN( &obj_EUTRAN_BearerContextModificationResponse->dRBFailedToModifyListEUTRAN);
	obj_EUTRAN_BearerContextModificationResponse->dRBFailedToModifyListEUTRAN_isset = 1;


	// RetainabilityMeasurementsInfo , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__RetainabilityMeasurementsInfo( &obj_EUTRAN_BearerContextModificationResponse->retainabilityMeasurementsInfo);
	obj_EUTRAN_BearerContextModificationResponse->retainabilityMeasurementsInfo_isset = 1;



	*pEUTRAN_BearerContextModificationResponse = obj_EUTRAN_BearerContextModificationResponse;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_NG_RAN_BearerContextModificationResponse( SI_E1AP_DT_PDU_NG_RAN_BearerContextModificationResponse ** pNG_RAN_BearerContextModificationResponse)
{
	SI_E1AP_DT_PDU_NG_RAN_BearerContextModificationResponse * obj_NG_RAN_BearerContextModificationResponse = (SI_E1AP_DT_PDU_NG_RAN_BearerContextModificationResponse*) __si_allocM( sizeof(SI_E1AP_DT_PDU_NG_RAN_BearerContextModificationResponse));
	memset( obj_NG_RAN_BearerContextModificationResponse, 0, sizeof( SI_E1AP_DT_PDU_NG_RAN_BearerContextModificationResponse));

	// PDU-Session-Resource-Setup-Mod-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__PDU_Session_Resource_Setup_Mod_List( &obj_NG_RAN_BearerContextModificationResponse->pDUSessionResourceSetupModList);
	obj_NG_RAN_BearerContextModificationResponse->pDUSessionResourceSetupModList_isset = 1;


	// PDU-Session-Resource-Failed-Mod-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__PDU_Session_Resource_Failed_Mod_List( &obj_NG_RAN_BearerContextModificationResponse->pDUSessionResourceFailedModList);
	obj_NG_RAN_BearerContextModificationResponse->pDUSessionResourceFailedModList_isset = 1;


	// PDU-Session-Resource-Modified-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__PDU_Session_Resource_Modified_List( &obj_NG_RAN_BearerContextModificationResponse->pDUSessionResourceModifiedList);
	obj_NG_RAN_BearerContextModificationResponse->pDUSessionResourceModifiedList_isset = 1;


	// PDU-Session-Resource-Failed-To-Modify-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__PDU_Session_Resource_Failed_To_Modify_List( &obj_NG_RAN_BearerContextModificationResponse->pDUSessionResourceFailedToModifyList);
	obj_NG_RAN_BearerContextModificationResponse->pDUSessionResourceFailedToModifyList_isset = 1;


	// RetainabilityMeasurementsInfo , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__RetainabilityMeasurementsInfo( &obj_NG_RAN_BearerContextModificationResponse->retainabilityMeasurementsInfo);
	obj_NG_RAN_BearerContextModificationResponse->retainabilityMeasurementsInfo_isset = 1;



	*pNG_RAN_BearerContextModificationResponse = obj_NG_RAN_BearerContextModificationResponse;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_System_BearerContextModificationRequired_ExtIEs( SI_E1AP_DT_PDU_System_BearerContextModificationRequired_ExtIEs ** pSystem_BearerContextModificationRequired_ExtIEs)
{
	SI_E1AP_DT_PDU_System_BearerContextModificationRequired_ExtIEs * obj_System_BearerContextModificationRequired_ExtIEs = (SI_E1AP_DT_PDU_System_BearerContextModificationRequired_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_System_BearerContextModificationRequired_ExtIEs));
	memset( obj_System_BearerContextModificationRequired_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_System_BearerContextModificationRequired_ExtIEs));


	*pSystem_BearerContextModificationRequired_ExtIEs = obj_System_BearerContextModificationRequired_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_EUTRAN_BearerContextModificationRequired( SI_E1AP_DT_PDU_EUTRAN_BearerContextModificationRequired ** pEUTRAN_BearerContextModificationRequired)
{
	SI_E1AP_DT_PDU_EUTRAN_BearerContextModificationRequired * obj_EUTRAN_BearerContextModificationRequired = (SI_E1AP_DT_PDU_EUTRAN_BearerContextModificationRequired*) __si_allocM( sizeof(SI_E1AP_DT_PDU_EUTRAN_BearerContextModificationRequired));
	memset( obj_EUTRAN_BearerContextModificationRequired, 0, sizeof( SI_E1AP_DT_PDU_EUTRAN_BearerContextModificationRequired));

	// DRB-Required-To-Modify-List-EUTRAN , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__DRB_Required_To_Modify_List_EUTRAN( &obj_EUTRAN_BearerContextModificationRequired->dRBRequiredToModifyListEUTRAN);
	obj_EUTRAN_BearerContextModificationRequired->dRBRequiredToModifyListEUTRAN_isset = 1;


	// DRB-Required-To-Remove-List-EUTRAN , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__DRB_Required_To_Remove_List_EUTRAN( &obj_EUTRAN_BearerContextModificationRequired->dRBRequiredToRemoveListEUTRAN);
	obj_EUTRAN_BearerContextModificationRequired->dRBRequiredToRemoveListEUTRAN_isset = 1;



	*pEUTRAN_BearerContextModificationRequired = obj_EUTRAN_BearerContextModificationRequired;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_NG_RAN_BearerContextModificationRequired( SI_E1AP_DT_PDU_NG_RAN_BearerContextModificationRequired ** pNG_RAN_BearerContextModificationRequired)
{
	SI_E1AP_DT_PDU_NG_RAN_BearerContextModificationRequired * obj_NG_RAN_BearerContextModificationRequired = (SI_E1AP_DT_PDU_NG_RAN_BearerContextModificationRequired*) __si_allocM( sizeof(SI_E1AP_DT_PDU_NG_RAN_BearerContextModificationRequired));
	memset( obj_NG_RAN_BearerContextModificationRequired, 0, sizeof( SI_E1AP_DT_PDU_NG_RAN_BearerContextModificationRequired));

	// PDU-Session-Resource-Required-To-Modify-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__PDU_Session_Resource_Required_To_Modify_List( &obj_NG_RAN_BearerContextModificationRequired->pDUSessionResourceRequiredToModifyList);
	obj_NG_RAN_BearerContextModificationRequired->pDUSessionResourceRequiredToModifyList_isset = 1;


	// PDU-Session-Resource-To-Remove-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__PDU_Session_Resource_To_Remove_List( &obj_NG_RAN_BearerContextModificationRequired->pDUSessionResourceToRemoveList);
	obj_NG_RAN_BearerContextModificationRequired->pDUSessionResourceToRemoveList_isset = 1;



	*pNG_RAN_BearerContextModificationRequired = obj_NG_RAN_BearerContextModificationRequired;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_System_BearerContextModificationConfirm_ExtIEs( SI_E1AP_DT_PDU_System_BearerContextModificationConfirm_ExtIEs ** pSystem_BearerContextModificationConfirm_ExtIEs)
{
	SI_E1AP_DT_PDU_System_BearerContextModificationConfirm_ExtIEs * obj_System_BearerContextModificationConfirm_ExtIEs = (SI_E1AP_DT_PDU_System_BearerContextModificationConfirm_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_System_BearerContextModificationConfirm_ExtIEs));
	memset( obj_System_BearerContextModificationConfirm_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_System_BearerContextModificationConfirm_ExtIEs));


	*pSystem_BearerContextModificationConfirm_ExtIEs = obj_System_BearerContextModificationConfirm_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_EUTRAN_BearerContextModificationConfirm( SI_E1AP_DT_PDU_EUTRAN_BearerContextModificationConfirm ** pEUTRAN_BearerContextModificationConfirm)
{
	SI_E1AP_DT_PDU_EUTRAN_BearerContextModificationConfirm * obj_EUTRAN_BearerContextModificationConfirm = (SI_E1AP_DT_PDU_EUTRAN_BearerContextModificationConfirm*) __si_allocM( sizeof(SI_E1AP_DT_PDU_EUTRAN_BearerContextModificationConfirm));
	memset( obj_EUTRAN_BearerContextModificationConfirm, 0, sizeof( SI_E1AP_DT_PDU_EUTRAN_BearerContextModificationConfirm));

	// DRB-Confirm-Modified-List-EUTRAN , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__DRB_Confirm_Modified_List_EUTRAN( &obj_EUTRAN_BearerContextModificationConfirm->dRBConfirmModifiedListEUTRAN);
	obj_EUTRAN_BearerContextModificationConfirm->dRBConfirmModifiedListEUTRAN_isset = 1;



	*pEUTRAN_BearerContextModificationConfirm = obj_EUTRAN_BearerContextModificationConfirm;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_NG_RAN_BearerContextModificationConfirm( SI_E1AP_DT_PDU_NG_RAN_BearerContextModificationConfirm ** pNG_RAN_BearerContextModificationConfirm)
{
	SI_E1AP_DT_PDU_NG_RAN_BearerContextModificationConfirm * obj_NG_RAN_BearerContextModificationConfirm = (SI_E1AP_DT_PDU_NG_RAN_BearerContextModificationConfirm*) __si_allocM( sizeof(SI_E1AP_DT_PDU_NG_RAN_BearerContextModificationConfirm));
	memset( obj_NG_RAN_BearerContextModificationConfirm, 0, sizeof( SI_E1AP_DT_PDU_NG_RAN_BearerContextModificationConfirm));

	// PDU-Session-Resource-Confirm-Modified-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__PDU_Session_Resource_Confirm_Modified_List( &obj_NG_RAN_BearerContextModificationConfirm->pDUSessionResourceConfirmModifiedList);
	obj_NG_RAN_BearerContextModificationConfirm->pDUSessionResourceConfirmModifiedList_isset = 1;



	*pNG_RAN_BearerContextModificationConfirm = obj_NG_RAN_BearerContextModificationConfirm;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_System_GNB_CU_UP_CounterCheckRequest_ExtIEs( SI_E1AP_DT_PDU_System_GNB_CU_UP_CounterCheckRequest_ExtIEs ** pSystem_GNB_CU_UP_CounterCheckRequest_ExtIEs)
{
	SI_E1AP_DT_PDU_System_GNB_CU_UP_CounterCheckRequest_ExtIEs * obj_System_GNB_CU_UP_CounterCheckRequest_ExtIEs = (SI_E1AP_DT_PDU_System_GNB_CU_UP_CounterCheckRequest_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_System_GNB_CU_UP_CounterCheckRequest_ExtIEs));
	memset( obj_System_GNB_CU_UP_CounterCheckRequest_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_System_GNB_CU_UP_CounterCheckRequest_ExtIEs));


	*pSystem_GNB_CU_UP_CounterCheckRequest_ExtIEs = obj_System_GNB_CU_UP_CounterCheckRequest_ExtIEs;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_EUTRAN_GNB_CU_UP_CounterCheckRequest( SI_E1AP_DT_PDU_EUTRAN_GNB_CU_UP_CounterCheckRequest ** pEUTRAN_GNB_CU_UP_CounterCheckRequest)
{
	SI_E1AP_DT_PDU_EUTRAN_GNB_CU_UP_CounterCheckRequest * obj_EUTRAN_GNB_CU_UP_CounterCheckRequest = (SI_E1AP_DT_PDU_EUTRAN_GNB_CU_UP_CounterCheckRequest*) __si_allocM( sizeof(SI_E1AP_DT_PDU_EUTRAN_GNB_CU_UP_CounterCheckRequest));
	memset( obj_EUTRAN_GNB_CU_UP_CounterCheckRequest, 0, sizeof( SI_E1AP_DT_PDU_EUTRAN_GNB_CU_UP_CounterCheckRequest));

	// DRBs-Subject-To-Counter-Check-List-EUTRAN , PRESENCE = mandatory   SEQUENCE_OF
	__si_e1ap__set_testdata__DRBs_Subject_To_Counter_Check_List_EUTRAN( &obj_EUTRAN_GNB_CU_UP_CounterCheckRequest->dRBsSubjectToCounterCheckListEUTRAN);
	obj_EUTRAN_GNB_CU_UP_CounterCheckRequest->dRBsSubjectToCounterCheckListEUTRAN_isset = 1;



	*pEUTRAN_GNB_CU_UP_CounterCheckRequest = obj_EUTRAN_GNB_CU_UP_CounterCheckRequest;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_NG_RAN_GNB_CU_UP_CounterCheckRequest( SI_E1AP_DT_PDU_NG_RAN_GNB_CU_UP_CounterCheckRequest ** pNG_RAN_GNB_CU_UP_CounterCheckRequest)
{
	SI_E1AP_DT_PDU_NG_RAN_GNB_CU_UP_CounterCheckRequest * obj_NG_RAN_GNB_CU_UP_CounterCheckRequest = (SI_E1AP_DT_PDU_NG_RAN_GNB_CU_UP_CounterCheckRequest*) __si_allocM( sizeof(SI_E1AP_DT_PDU_NG_RAN_GNB_CU_UP_CounterCheckRequest));
	memset( obj_NG_RAN_GNB_CU_UP_CounterCheckRequest, 0, sizeof( SI_E1AP_DT_PDU_NG_RAN_GNB_CU_UP_CounterCheckRequest));

	// DRBs-Subject-To-Counter-Check-List-NG-RAN , PRESENCE = mandatory   SEQUENCE_OF
	__si_e1ap__set_testdata__DRBs_Subject_To_Counter_Check_List_NG_RAN( &obj_NG_RAN_GNB_CU_UP_CounterCheckRequest->dRBsSubjectToCounterCheckListNGRAN);
	obj_NG_RAN_GNB_CU_UP_CounterCheckRequest->dRBsSubjectToCounterCheckListNGRAN_isset = 1;



	*pNG_RAN_GNB_CU_UP_CounterCheckRequest = obj_NG_RAN_GNB_CU_UP_CounterCheckRequest;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_UE_associatedLogicalE1_ConnectionItemRes( SI_E1AP_DT_PDU_UE_associatedLogicalE1_ConnectionItemRes ** pUE_associatedLogicalE1_ConnectionItemRes)
{
	SI_E1AP_DT_PDU_UE_associatedLogicalE1_ConnectionItemRes * obj_UE_associatedLogicalE1_ConnectionItemRes = (SI_E1AP_DT_PDU_UE_associatedLogicalE1_ConnectionItemRes*) __si_allocM( sizeof(SI_E1AP_DT_PDU_UE_associatedLogicalE1_ConnectionItemRes));
	memset( obj_UE_associatedLogicalE1_ConnectionItemRes, 0, sizeof( SI_E1AP_DT_PDU_UE_associatedLogicalE1_ConnectionItemRes));

	// UE-associatedLogicalE1-ConnectionItem , PRESENCE = mandatory   SEQUENCE
	__si_e1ap__set_testdata__UE_associatedLogicalE1_ConnectionItem( &obj_UE_associatedLogicalE1_ConnectionItemRes->uEassociatedLogicalE1ConnectionItem);
	obj_UE_associatedLogicalE1_ConnectionItemRes->uEassociatedLogicalE1ConnectionItem_isset = 1;



	*pUE_associatedLogicalE1_ConnectionItemRes = obj_UE_associatedLogicalE1_ConnectionItemRes;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_UE_associatedLogicalE1_ConnectionItemResAck( SI_E1AP_DT_PDU_UE_associatedLogicalE1_ConnectionItemResAck ** pUE_associatedLogicalE1_ConnectionItemResAck)
{
	SI_E1AP_DT_PDU_UE_associatedLogicalE1_ConnectionItemResAck * obj_UE_associatedLogicalE1_ConnectionItemResAck = (SI_E1AP_DT_PDU_UE_associatedLogicalE1_ConnectionItemResAck*) __si_allocM( sizeof(SI_E1AP_DT_PDU_UE_associatedLogicalE1_ConnectionItemResAck));
	memset( obj_UE_associatedLogicalE1_ConnectionItemResAck, 0, sizeof( SI_E1AP_DT_PDU_UE_associatedLogicalE1_ConnectionItemResAck));

	// UE-associatedLogicalE1-ConnectionItem , PRESENCE = mandatory   SEQUENCE
	__si_e1ap__set_testdata__UE_associatedLogicalE1_ConnectionItem( &obj_UE_associatedLogicalE1_ConnectionItemResAck->uEassociatedLogicalE1ConnectionItem);
	obj_UE_associatedLogicalE1_ConnectionItemResAck->uEassociatedLogicalE1ConnectionItem_isset = 1;



	*pUE_associatedLogicalE1_ConnectionItemResAck = obj_UE_associatedLogicalE1_ConnectionItemResAck;
}

//  L:11222
void __si_e1ap__set_testdata__PDU_SupportedPLMNs_ExtIEs( SI_E1AP_DT_PDU_SupportedPLMNs_ExtIEs ** pSupportedPLMNs_ExtIEs)
{
	SI_E1AP_DT_PDU_SupportedPLMNs_ExtIEs * obj_SupportedPLMNs_ExtIEs = (SI_E1AP_DT_PDU_SupportedPLMNs_ExtIEs*) __si_allocM( sizeof(SI_E1AP_DT_PDU_SupportedPLMNs_ExtIEs));
	memset( obj_SupportedPLMNs_ExtIEs, 0, sizeof( SI_E1AP_DT_PDU_SupportedPLMNs_ExtIEs));

	// NPNSupportInfo , PRESENCE = optional   CHOICE
	__si_e1ap__set_testdata__NPNSupportInfo( &obj_SupportedPLMNs_ExtIEs->nPNSupportInfo);
	obj_SupportedPLMNs_ExtIEs->nPNSupportInfo->SelectedChoice = NPNSupportInfo_sNPN_val;

	switch( obj_SupportedPLMNs_ExtIEs->nPNSupportInfo->SelectedChoice)
	{
		case NPNSupportInfo_sNPN_val:
			__si_e1ap__set_testdata__NPNSupportInfo_SNPN( &obj_SupportedPLMNs_ExtIEs->nPNSupportInfo->u.sNPN); //   L:11384
			break;
		case NPNSupportInfo_choice_extension_val:  // L:11477
			{
				__si_e1ap__set_testdata__PDU_NPNSupportInfo_ExtIEs( &obj_SupportedPLMNs_ExtIEs->nPNSupportInfo->u.choice_extension);   // L:11497
			}
			break;
		default:
			break;
	}

	obj_SupportedPLMNs_ExtIEs->nPNSupportInfo_isset = 1;


	// ExtendedSliceSupportList , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__ExtendedSliceSupportList( &obj_SupportedPLMNs_ExtIEs->extendedSliceSupportList);
	obj_SupportedPLMNs_ExtIEs->extendedSliceSupportList_isset = 1;


	// Extended-NR-CGI-Support-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__Extended_NR_CGI_Support_List( &obj_SupportedPLMNs_ExtIEs->extendedNRCGISupportList);
	obj_SupportedPLMNs_ExtIEs->extendedNRCGISupportList_isset = 1;


	// ECGI-Support-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__ECGI_Support_List( &obj_SupportedPLMNs_ExtIEs->eCGISupportList);
	obj_SupportedPLMNs_ExtIEs->eCGISupportList_isset = 1;



	*pSupportedPLMNs_ExtIEs = obj_SupportedPLMNs_ExtIEs;
}



void __si_e1ap__Send_Reset_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_Reset * obj_Reset = (SI_E1AP_DT_PDU_Reset*) __si_allocM( sizeof(SI_E1AP_DT_PDU_Reset));
	memset( obj_Reset, 0, sizeof( SI_E1AP_DT_PDU_Reset));

	// TransactionID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=255
	obj_Reset->transactionID = __getTestINTEGER( 0, 255);
	obj_Reset->transactionID_isset = 1;


	// Cause , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__Cause( &obj_Reset->cause);
	obj_Reset->cause->SelectedChoice = Cause_transport_val;

	switch( obj_Reset->cause->SelectedChoice)
	{
		case Cause_radioNetwork_val:
			obj_Reset->cause->u.radioNetwork = CauseRadioNetwork_unspecified_val;
			break;
		case Cause_transport_val:
			obj_Reset->cause->u.transport = CauseTransport_unspecified_val;
			break;
		case Cause_protocol_val:
			obj_Reset->cause->u.protocol = CauseProtocol_transfer_syntax_error_val;
			break;
		case Cause_misc_val:
			obj_Reset->cause->u.misc = CauseMisc_control_processing_overload_val;
			break;
		case Cause_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_Cause_ExtIEs( &obj_Reset->cause->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_Reset->cause_isset = 1;


	// ResetType  , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__ResetType( &obj_Reset->resetType);
	obj_Reset->resetType->SelectedChoice = ResetType_e1_Interface_val;

	switch( obj_Reset->resetType->SelectedChoice)
	{
		case ResetType_e1_Interface_val:
			obj_Reset->resetType->u.e1_Interface = ResetAll_reset_all_val;
			break;
		case ResetType_partOfE1_Interface_val:
			__si_e1ap__set_testdata__UE_associatedLogicalE1_ConnectionListRes( &obj_Reset->resetType->u.partOfE1_Interface); //   L:11791
			break;
		case ResetType_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_ResetType_ExtIEs( &obj_Reset->resetType->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_Reset->resetType_isset = 1;



	__si_e1ap_send_Reset( obj_Reset, node);
	__si_e1ap_memfree_pdu_Reset( obj_Reset);
}

void __si_e1ap__Send_ResetAcknowledge_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_ResetAcknowledge * obj_ResetAcknowledge = (SI_E1AP_DT_PDU_ResetAcknowledge*) __si_allocM( sizeof(SI_E1AP_DT_PDU_ResetAcknowledge));
	memset( obj_ResetAcknowledge, 0, sizeof( SI_E1AP_DT_PDU_ResetAcknowledge));

	// TransactionID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=255
	obj_ResetAcknowledge->transactionID = __getTestINTEGER( 0, 255);
	obj_ResetAcknowledge->transactionID_isset = 1;


	// UE-associatedLogicalE1-ConnectionListResAck , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__UE_associatedLogicalE1_ConnectionListResAck( &obj_ResetAcknowledge->uEassociatedLogicalE1ConnectionListResAck);
	obj_ResetAcknowledge->uEassociatedLogicalE1ConnectionListResAck_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_ResetAcknowledge->criticalityDiagnostics);
	obj_ResetAcknowledge->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_ResetAcknowledge( obj_ResetAcknowledge, node);
	__si_e1ap_memfree_pdu_ResetAcknowledge( obj_ResetAcknowledge);
}

void __si_e1ap__Send_ErrorIndication_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_ErrorIndication * obj_ErrorIndication = (SI_E1AP_DT_PDU_ErrorIndication*) __si_allocM( sizeof(SI_E1AP_DT_PDU_ErrorIndication));
	memset( obj_ErrorIndication, 0, sizeof( SI_E1AP_DT_PDU_ErrorIndication));

	// TransactionID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=255
	obj_ErrorIndication->transactionID = __getTestINTEGER( 0, 255);
	obj_ErrorIndication->transactionID_isset = 1;


	// GNB-CU-CP-UE-E1AP-ID  , PRESENCE = optional  INTEGER , MIN=0, MAX=4294967295
	obj_ErrorIndication->gNBCUCPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_ErrorIndication->gNBCUCPUEE1APID_isset = 1;


	// GNB-CU-UP-UE-E1AP-ID  , PRESENCE = optional  INTEGER , MIN=0, MAX=4294967295
	obj_ErrorIndication->gNBCUUPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_ErrorIndication->gNBCUUPUEE1APID_isset = 1;


	// Cause , PRESENCE = optional   CHOICE
	__si_e1ap__set_testdata__Cause( &obj_ErrorIndication->cause);
	obj_ErrorIndication->cause->SelectedChoice = Cause_radioNetwork_val;

	switch( obj_ErrorIndication->cause->SelectedChoice)
	{
		case Cause_radioNetwork_val:
			obj_ErrorIndication->cause->u.radioNetwork = CauseRadioNetwork_unspecified_val;
			break;
		case Cause_transport_val:
			obj_ErrorIndication->cause->u.transport = CauseTransport_unspecified_val;
			break;
		case Cause_protocol_val:
			obj_ErrorIndication->cause->u.protocol = CauseProtocol_transfer_syntax_error_val;
			break;
		case Cause_misc_val:
			obj_ErrorIndication->cause->u.misc = CauseMisc_control_processing_overload_val;
			break;
		case Cause_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_Cause_ExtIEs( &obj_ErrorIndication->cause->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_ErrorIndication->cause_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_ErrorIndication->criticalityDiagnostics);
	obj_ErrorIndication->criticalityDiagnostics_isset = 1;


	// GNB-CU-CP-MBS-E1AP-ID  , PRESENCE = optional  INTEGER , MIN=0, MAX=16777215
	obj_ErrorIndication->gNBCUCPMBSE1APID = __getTestINTEGER( 0, 16777215);
	obj_ErrorIndication->gNBCUCPMBSE1APID_isset = 1;


	// GNB-CU-UP-MBS-E1AP-ID  , PRESENCE = optional  INTEGER , MIN=0, MAX=65535
	obj_ErrorIndication->gNBCUUPMBSE1APID = __getTestINTEGER( 0, 65535);
	obj_ErrorIndication->gNBCUUPMBSE1APID_isset = 1;



	__si_e1ap_send_ErrorIndication( obj_ErrorIndication, node);
	__si_e1ap_memfree_pdu_ErrorIndication( obj_ErrorIndication);
}

void __si_e1ap__Send_GNB_CU_UP_E1SetupRequest_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_GNB_CU_UP_E1SetupRequest * obj_GNB_CU_UP_E1SetupRequest = (SI_E1AP_DT_PDU_GNB_CU_UP_E1SetupRequest*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GNB_CU_UP_E1SetupRequest));
	memset( obj_GNB_CU_UP_E1SetupRequest, 0, sizeof( SI_E1AP_DT_PDU_GNB_CU_UP_E1SetupRequest));

	// TransactionID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=255
	obj_GNB_CU_UP_E1SetupRequest->transactionID = __getTestINTEGER( 0, 255);
	obj_GNB_CU_UP_E1SetupRequest->transactionID_isset = 1;


	// GNB-CU-UP-ID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=68719476735
	obj_GNB_CU_UP_E1SetupRequest->gNBCUUPID = __getTestINTEGER( 0, 68719476735);
	obj_GNB_CU_UP_E1SetupRequest->gNBCUUPID_isset = 1;


	// GNB-CU-UP-Name        PrintableString, PRESENCE = optional , MIN=1, MAX=150
	__si_e1ap_init_GNB_CU_UP_Name2( &obj_GNB_CU_UP_E1SetupRequest->gNBCUUPName, "S", 1);
	obj_GNB_CU_UP_E1SetupRequest->gNBCUUPName_isset = 1;


	// CNSupport , PRESENCE = mandatory   ENUMERATED, PRESENCE = mandatory
	obj_GNB_CU_UP_E1SetupRequest->cNSupport = CNSupport_c_epc_val;
	obj_GNB_CU_UP_E1SetupRequest->cNSupport_isset = 1;


	// SupportedPLMNs-List , PRESENCE = mandatory   SEQUENCE_OF
	__si_e1ap__set_testdata__SupportedPLMNs_List( &obj_GNB_CU_UP_E1SetupRequest->supportedPLMNs);
	obj_GNB_CU_UP_E1SetupRequest->supportedPLMNs_isset = 1;


	// GNB-CU-UP-Capacity    , PRESENCE = optional  INTEGER , MIN=0, MAX=255
	obj_GNB_CU_UP_E1SetupRequest->gNBCUUPCapacity = __getTestINTEGER( 0, 255);
	obj_GNB_CU_UP_E1SetupRequest->gNBCUUPCapacity_isset = 1;


	// Transport-Layer-Address-Info , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__Transport_Layer_Address_Info( &obj_GNB_CU_UP_E1SetupRequest->transportLayerAddressInfo);
	obj_GNB_CU_UP_E1SetupRequest->transportLayerAddressInfo_isset = 1;


	// Extended-GNB-CU-UP-Name , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__Extended_GNB_CU_UP_Name( &obj_GNB_CU_UP_E1SetupRequest->extendedGNBCUUPName);
	obj_GNB_CU_UP_E1SetupRequest->extendedGNBCUUPName_isset = 1;


	// GNB-CU-UP-MBS-Support-Info , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__GNB_CU_UP_MBS_Support_Info( &obj_GNB_CU_UP_E1SetupRequest->gNBCUUPMBSSupportInfo);
	obj_GNB_CU_UP_E1SetupRequest->gNBCUUPMBSSupportInfo_isset = 1;



	__si_e1ap_send_GNB_CU_UP_E1SetupRequest( obj_GNB_CU_UP_E1SetupRequest, node);
	__si_e1ap_memfree_pdu_GNB_CU_UP_E1SetupRequest( obj_GNB_CU_UP_E1SetupRequest);
}

void __si_e1ap__Send_GNB_CU_UP_E1SetupResponse_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_GNB_CU_UP_E1SetupResponse * obj_GNB_CU_UP_E1SetupResponse = (SI_E1AP_DT_PDU_GNB_CU_UP_E1SetupResponse*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GNB_CU_UP_E1SetupResponse));
	memset( obj_GNB_CU_UP_E1SetupResponse, 0, sizeof( SI_E1AP_DT_PDU_GNB_CU_UP_E1SetupResponse));

	// TransactionID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=255
	obj_GNB_CU_UP_E1SetupResponse->transactionID = __getTestINTEGER( 0, 255);
	obj_GNB_CU_UP_E1SetupResponse->transactionID_isset = 1;


	// GNB-CU-CP-Name        PrintableString, PRESENCE = optional , MIN=1, MAX=150
	__si_e1ap_init_GNB_CU_CP_Name2( &obj_GNB_CU_UP_E1SetupResponse->gNBCUCPName, "u", 1);
	obj_GNB_CU_UP_E1SetupResponse->gNBCUCPName_isset = 1;


	// Transport-Layer-Address-Info , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__Transport_Layer_Address_Info( &obj_GNB_CU_UP_E1SetupResponse->transportLayerAddressInfo);
	obj_GNB_CU_UP_E1SetupResponse->transportLayerAddressInfo_isset = 1;


	// Extended-GNB-CU-CP-Name , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__Extended_GNB_CU_CP_Name( &obj_GNB_CU_UP_E1SetupResponse->extendedGNBCUCPName);
	obj_GNB_CU_UP_E1SetupResponse->extendedGNBCUCPName_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_GNB_CU_UP_E1SetupResponse->criticalityDiagnostics);
	obj_GNB_CU_UP_E1SetupResponse->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_GNB_CU_UP_E1SetupResponse( obj_GNB_CU_UP_E1SetupResponse, node);
	__si_e1ap_memfree_pdu_GNB_CU_UP_E1SetupResponse( obj_GNB_CU_UP_E1SetupResponse);
}

void __si_e1ap__Send_GNB_CU_UP_E1SetupFailure_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_GNB_CU_UP_E1SetupFailure * obj_GNB_CU_UP_E1SetupFailure = (SI_E1AP_DT_PDU_GNB_CU_UP_E1SetupFailure*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GNB_CU_UP_E1SetupFailure));
	memset( obj_GNB_CU_UP_E1SetupFailure, 0, sizeof( SI_E1AP_DT_PDU_GNB_CU_UP_E1SetupFailure));

	// TransactionID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=255
	obj_GNB_CU_UP_E1SetupFailure->transactionID = __getTestINTEGER( 0, 255);
	obj_GNB_CU_UP_E1SetupFailure->transactionID_isset = 1;


	// Cause , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__Cause( &obj_GNB_CU_UP_E1SetupFailure->cause);
	obj_GNB_CU_UP_E1SetupFailure->cause->SelectedChoice = Cause_radioNetwork_val;

	switch( obj_GNB_CU_UP_E1SetupFailure->cause->SelectedChoice)
	{
		case Cause_radioNetwork_val:
			obj_GNB_CU_UP_E1SetupFailure->cause->u.radioNetwork = CauseRadioNetwork_unspecified_val;
			break;
		case Cause_transport_val:
			obj_GNB_CU_UP_E1SetupFailure->cause->u.transport = CauseTransport_unspecified_val;
			break;
		case Cause_protocol_val:
			obj_GNB_CU_UP_E1SetupFailure->cause->u.protocol = CauseProtocol_transfer_syntax_error_val;
			break;
		case Cause_misc_val:
			obj_GNB_CU_UP_E1SetupFailure->cause->u.misc = CauseMisc_control_processing_overload_val;
			break;
		case Cause_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_Cause_ExtIEs( &obj_GNB_CU_UP_E1SetupFailure->cause->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_GNB_CU_UP_E1SetupFailure->cause_isset = 1;


	// TimeToWait , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_GNB_CU_UP_E1SetupFailure->timeToWait = TimeToWait_v1s_val;
	obj_GNB_CU_UP_E1SetupFailure->timeToWait_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_GNB_CU_UP_E1SetupFailure->criticalityDiagnostics);
	obj_GNB_CU_UP_E1SetupFailure->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_GNB_CU_UP_E1SetupFailure( obj_GNB_CU_UP_E1SetupFailure, node);
	__si_e1ap_memfree_pdu_GNB_CU_UP_E1SetupFailure( obj_GNB_CU_UP_E1SetupFailure);
}

void __si_e1ap__Send_GNB_CU_CP_E1SetupRequest_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupRequest * obj_GNB_CU_CP_E1SetupRequest = (SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupRequest*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupRequest));
	memset( obj_GNB_CU_CP_E1SetupRequest, 0, sizeof( SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupRequest));

	// TransactionID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=255
	obj_GNB_CU_CP_E1SetupRequest->transactionID = __getTestINTEGER( 0, 255);
	obj_GNB_CU_CP_E1SetupRequest->transactionID_isset = 1;


	// GNB-CU-CP-Name        PrintableString, PRESENCE = optional , MIN=1, MAX=150
	__si_e1ap_init_GNB_CU_CP_Name2( &obj_GNB_CU_CP_E1SetupRequest->gNBCUCPName, "e", 1);
	obj_GNB_CU_CP_E1SetupRequest->gNBCUCPName_isset = 1;


	// Transport-Layer-Address-Info , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__Transport_Layer_Address_Info( &obj_GNB_CU_CP_E1SetupRequest->transportLayerAddressInfo);
	obj_GNB_CU_CP_E1SetupRequest->transportLayerAddressInfo_isset = 1;


	// Extended-GNB-CU-CP-Name , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__Extended_GNB_CU_CP_Name( &obj_GNB_CU_CP_E1SetupRequest->extendedGNBCUCPName);
	obj_GNB_CU_CP_E1SetupRequest->extendedGNBCUCPName_isset = 1;



	__si_e1ap_send_GNB_CU_CP_E1SetupRequest( obj_GNB_CU_CP_E1SetupRequest, node);
	__si_e1ap_memfree_pdu_GNB_CU_CP_E1SetupRequest( obj_GNB_CU_CP_E1SetupRequest);
}

void __si_e1ap__Send_GNB_CU_CP_E1SetupResponse_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupResponse * obj_GNB_CU_CP_E1SetupResponse = (SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupResponse*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupResponse));
	memset( obj_GNB_CU_CP_E1SetupResponse, 0, sizeof( SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupResponse));

	// TransactionID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=255
	obj_GNB_CU_CP_E1SetupResponse->transactionID = __getTestINTEGER( 0, 255);
	obj_GNB_CU_CP_E1SetupResponse->transactionID_isset = 1;


	// GNB-CU-UP-ID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=68719476735
	obj_GNB_CU_CP_E1SetupResponse->gNBCUUPID = __getTestINTEGER( 0, 68719476735);
	obj_GNB_CU_CP_E1SetupResponse->gNBCUUPID_isset = 1;


	// GNB-CU-UP-Name        PrintableString, PRESENCE = optional , MIN=1, MAX=150
	__si_e1ap_init_GNB_CU_UP_Name2( &obj_GNB_CU_CP_E1SetupResponse->gNBCUUPName, "T", 1);
	obj_GNB_CU_CP_E1SetupResponse->gNBCUUPName_isset = 1;


	// CNSupport , PRESENCE = mandatory   ENUMERATED, PRESENCE = mandatory
	obj_GNB_CU_CP_E1SetupResponse->cNSupport = CNSupport_c_epc_val;
	obj_GNB_CU_CP_E1SetupResponse->cNSupport_isset = 1;


	// SupportedPLMNs-List , PRESENCE = mandatory   SEQUENCE_OF
	__si_e1ap__set_testdata__SupportedPLMNs_List( &obj_GNB_CU_CP_E1SetupResponse->supportedPLMNs);
	obj_GNB_CU_CP_E1SetupResponse->supportedPLMNs_isset = 1;


	// GNB-CU-UP-Capacity    , PRESENCE = optional  INTEGER , MIN=0, MAX=255
	obj_GNB_CU_CP_E1SetupResponse->gNBCUUPCapacity = __getTestINTEGER( 0, 255);
	obj_GNB_CU_CP_E1SetupResponse->gNBCUUPCapacity_isset = 1;


	// Transport-Layer-Address-Info , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__Transport_Layer_Address_Info( &obj_GNB_CU_CP_E1SetupResponse->transportLayerAddressInfo);
	obj_GNB_CU_CP_E1SetupResponse->transportLayerAddressInfo_isset = 1;


	// Extended-GNB-CU-UP-Name , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__Extended_GNB_CU_UP_Name( &obj_GNB_CU_CP_E1SetupResponse->extendedGNBCUUPName);
	obj_GNB_CU_CP_E1SetupResponse->extendedGNBCUUPName_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_GNB_CU_CP_E1SetupResponse->criticalityDiagnostics);
	obj_GNB_CU_CP_E1SetupResponse->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_GNB_CU_CP_E1SetupResponse( obj_GNB_CU_CP_E1SetupResponse, node);
	__si_e1ap_memfree_pdu_GNB_CU_CP_E1SetupResponse( obj_GNB_CU_CP_E1SetupResponse);
}

void __si_e1ap__Send_GNB_CU_CP_E1SetupFailure_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupFailure * obj_GNB_CU_CP_E1SetupFailure = (SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupFailure*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupFailure));
	memset( obj_GNB_CU_CP_E1SetupFailure, 0, sizeof( SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupFailure));

	// TransactionID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=255
	obj_GNB_CU_CP_E1SetupFailure->transactionID = __getTestINTEGER( 0, 255);
	obj_GNB_CU_CP_E1SetupFailure->transactionID_isset = 1;


	// Cause , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__Cause( &obj_GNB_CU_CP_E1SetupFailure->cause);
	obj_GNB_CU_CP_E1SetupFailure->cause->SelectedChoice = Cause_radioNetwork_val;

	switch( obj_GNB_CU_CP_E1SetupFailure->cause->SelectedChoice)
	{
		case Cause_radioNetwork_val:
			obj_GNB_CU_CP_E1SetupFailure->cause->u.radioNetwork = CauseRadioNetwork_unspecified_val;
			break;
		case Cause_transport_val:
			obj_GNB_CU_CP_E1SetupFailure->cause->u.transport = CauseTransport_unspecified_val;
			break;
		case Cause_protocol_val:
			obj_GNB_CU_CP_E1SetupFailure->cause->u.protocol = CauseProtocol_transfer_syntax_error_val;
			break;
		case Cause_misc_val:
			obj_GNB_CU_CP_E1SetupFailure->cause->u.misc = CauseMisc_control_processing_overload_val;
			break;
		case Cause_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_Cause_ExtIEs( &obj_GNB_CU_CP_E1SetupFailure->cause->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_GNB_CU_CP_E1SetupFailure->cause_isset = 1;


	// TimeToWait , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_GNB_CU_CP_E1SetupFailure->timeToWait = TimeToWait_v1s_val;
	obj_GNB_CU_CP_E1SetupFailure->timeToWait_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_GNB_CU_CP_E1SetupFailure->criticalityDiagnostics);
	obj_GNB_CU_CP_E1SetupFailure->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_GNB_CU_CP_E1SetupFailure( obj_GNB_CU_CP_E1SetupFailure, node);
	__si_e1ap_memfree_pdu_GNB_CU_CP_E1SetupFailure( obj_GNB_CU_CP_E1SetupFailure);
}

void __si_e1ap__Send_GNB_CU_UP_ConfigurationUpdate_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_GNB_CU_UP_ConfigurationUpdate * obj_GNB_CU_UP_ConfigurationUpdate = (SI_E1AP_DT_PDU_GNB_CU_UP_ConfigurationUpdate*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GNB_CU_UP_ConfigurationUpdate));
	memset( obj_GNB_CU_UP_ConfigurationUpdate, 0, sizeof( SI_E1AP_DT_PDU_GNB_CU_UP_ConfigurationUpdate));

	// TransactionID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=255
	obj_GNB_CU_UP_ConfigurationUpdate->transactionID = __getTestINTEGER( 0, 255);
	obj_GNB_CU_UP_ConfigurationUpdate->transactionID_isset = 1;


	// GNB-CU-UP-ID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=68719476735
	obj_GNB_CU_UP_ConfigurationUpdate->gNBCUUPID = __getTestINTEGER( 0, 68719476735);
	obj_GNB_CU_UP_ConfigurationUpdate->gNBCUUPID_isset = 1;


	// GNB-CU-UP-Name        PrintableString, PRESENCE = optional , MIN=1, MAX=150
	__si_e1ap_init_GNB_CU_UP_Name2( &obj_GNB_CU_UP_ConfigurationUpdate->gNBCUUPName, "q", 1);
	obj_GNB_CU_UP_ConfigurationUpdate->gNBCUUPName_isset = 1;


	// SupportedPLMNs-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__SupportedPLMNs_List( &obj_GNB_CU_UP_ConfigurationUpdate->supportedPLMNs);
	obj_GNB_CU_UP_ConfigurationUpdate->supportedPLMNs_isset = 1;


	// GNB-CU-UP-Capacity    , PRESENCE = optional  INTEGER , MIN=0, MAX=255
	obj_GNB_CU_UP_ConfigurationUpdate->gNBCUUPCapacity = __getTestINTEGER( 0, 255);
	obj_GNB_CU_UP_ConfigurationUpdate->gNBCUUPCapacity_isset = 1;


	// GNB-CU-UP-TNLA-To-Remove-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__GNB_CU_UP_TNLA_To_Remove_List( &obj_GNB_CU_UP_ConfigurationUpdate->gNBCUUPTNLAToRemoveList);
	obj_GNB_CU_UP_ConfigurationUpdate->gNBCUUPTNLAToRemoveList_isset = 1;


	// Transport-Layer-Address-Info , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__Transport_Layer_Address_Info( &obj_GNB_CU_UP_ConfigurationUpdate->transportLayerAddressInfo);
	obj_GNB_CU_UP_ConfigurationUpdate->transportLayerAddressInfo_isset = 1;


	// Extended-GNB-CU-UP-Name , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__Extended_GNB_CU_UP_Name( &obj_GNB_CU_UP_ConfigurationUpdate->extendedGNBCUUPName);
	obj_GNB_CU_UP_ConfigurationUpdate->extendedGNBCUUPName_isset = 1;


	// GNB-CU-UP-MBS-Support-Info , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__GNB_CU_UP_MBS_Support_Info( &obj_GNB_CU_UP_ConfigurationUpdate->gNBCUUPMBSSupportInfo);
	obj_GNB_CU_UP_ConfigurationUpdate->gNBCUUPMBSSupportInfo_isset = 1;



	__si_e1ap_send_GNB_CU_UP_ConfigurationUpdate( obj_GNB_CU_UP_ConfigurationUpdate, node);
	__si_e1ap_memfree_pdu_GNB_CU_UP_ConfigurationUpdate( obj_GNB_CU_UP_ConfigurationUpdate);
}

void __si_e1ap__Send_GNB_CU_UP_ConfigurationUpdateAcknowledge_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_GNB_CU_UP_ConfigurationUpdateAcknowledge * obj_GNB_CU_UP_ConfigurationUpdateAcknowledge = (SI_E1AP_DT_PDU_GNB_CU_UP_ConfigurationUpdateAcknowledge*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GNB_CU_UP_ConfigurationUpdateAcknowledge));
	memset( obj_GNB_CU_UP_ConfigurationUpdateAcknowledge, 0, sizeof( SI_E1AP_DT_PDU_GNB_CU_UP_ConfigurationUpdateAcknowledge));

	// TransactionID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=255
	obj_GNB_CU_UP_ConfigurationUpdateAcknowledge->transactionID = __getTestINTEGER( 0, 255);
	obj_GNB_CU_UP_ConfigurationUpdateAcknowledge->transactionID_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_GNB_CU_UP_ConfigurationUpdateAcknowledge->criticalityDiagnostics);
	obj_GNB_CU_UP_ConfigurationUpdateAcknowledge->criticalityDiagnostics_isset = 1;


	// Transport-Layer-Address-Info , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__Transport_Layer_Address_Info( &obj_GNB_CU_UP_ConfigurationUpdateAcknowledge->transportLayerAddressInfo);
	obj_GNB_CU_UP_ConfigurationUpdateAcknowledge->transportLayerAddressInfo_isset = 1;



	__si_e1ap_send_GNB_CU_UP_ConfigurationUpdateAcknowledge( obj_GNB_CU_UP_ConfigurationUpdateAcknowledge, node);
	__si_e1ap_memfree_pdu_GNB_CU_UP_ConfigurationUpdateAcknowledge( obj_GNB_CU_UP_ConfigurationUpdateAcknowledge);
}

void __si_e1ap__Send_GNB_CU_UP_ConfigurationUpdateFailure_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_GNB_CU_UP_ConfigurationUpdateFailure * obj_GNB_CU_UP_ConfigurationUpdateFailure = (SI_E1AP_DT_PDU_GNB_CU_UP_ConfigurationUpdateFailure*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GNB_CU_UP_ConfigurationUpdateFailure));
	memset( obj_GNB_CU_UP_ConfigurationUpdateFailure, 0, sizeof( SI_E1AP_DT_PDU_GNB_CU_UP_ConfigurationUpdateFailure));

	// TransactionID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=255
	obj_GNB_CU_UP_ConfigurationUpdateFailure->transactionID = __getTestINTEGER( 0, 255);
	obj_GNB_CU_UP_ConfigurationUpdateFailure->transactionID_isset = 1;


	// Cause , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__Cause( &obj_GNB_CU_UP_ConfigurationUpdateFailure->cause);
	obj_GNB_CU_UP_ConfigurationUpdateFailure->cause->SelectedChoice = Cause_radioNetwork_val;

	switch( obj_GNB_CU_UP_ConfigurationUpdateFailure->cause->SelectedChoice)
	{
		case Cause_radioNetwork_val:
			obj_GNB_CU_UP_ConfigurationUpdateFailure->cause->u.radioNetwork = CauseRadioNetwork_unspecified_val;
			break;
		case Cause_transport_val:
			obj_GNB_CU_UP_ConfigurationUpdateFailure->cause->u.transport = CauseTransport_unspecified_val;
			break;
		case Cause_protocol_val:
			obj_GNB_CU_UP_ConfigurationUpdateFailure->cause->u.protocol = CauseProtocol_transfer_syntax_error_val;
			break;
		case Cause_misc_val:
			obj_GNB_CU_UP_ConfigurationUpdateFailure->cause->u.misc = CauseMisc_control_processing_overload_val;
			break;
		case Cause_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_Cause_ExtIEs( &obj_GNB_CU_UP_ConfigurationUpdateFailure->cause->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_GNB_CU_UP_ConfigurationUpdateFailure->cause_isset = 1;


	// TimeToWait , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_GNB_CU_UP_ConfigurationUpdateFailure->timeToWait = TimeToWait_v1s_val;
	obj_GNB_CU_UP_ConfigurationUpdateFailure->timeToWait_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_GNB_CU_UP_ConfigurationUpdateFailure->criticalityDiagnostics);
	obj_GNB_CU_UP_ConfigurationUpdateFailure->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_GNB_CU_UP_ConfigurationUpdateFailure( obj_GNB_CU_UP_ConfigurationUpdateFailure, node);
	__si_e1ap_memfree_pdu_GNB_CU_UP_ConfigurationUpdateFailure( obj_GNB_CU_UP_ConfigurationUpdateFailure);
}

void __si_e1ap__Send_GNB_CU_CP_ConfigurationUpdate_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_GNB_CU_CP_ConfigurationUpdate * obj_GNB_CU_CP_ConfigurationUpdate = (SI_E1AP_DT_PDU_GNB_CU_CP_ConfigurationUpdate*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GNB_CU_CP_ConfigurationUpdate));
	memset( obj_GNB_CU_CP_ConfigurationUpdate, 0, sizeof( SI_E1AP_DT_PDU_GNB_CU_CP_ConfigurationUpdate));

	// TransactionID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=255
	obj_GNB_CU_CP_ConfigurationUpdate->transactionID = __getTestINTEGER( 0, 255);
	obj_GNB_CU_CP_ConfigurationUpdate->transactionID_isset = 1;


	// GNB-CU-CP-Name        PrintableString, PRESENCE = optional , MIN=1, MAX=150
	__si_e1ap_init_GNB_CU_CP_Name2( &obj_GNB_CU_CP_ConfigurationUpdate->gNBCUCPName, "A", 1);
	obj_GNB_CU_CP_ConfigurationUpdate->gNBCUCPName_isset = 1;


	// GNB-CU-CP-TNLA-To-Add-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__GNB_CU_CP_TNLA_To_Add_List( &obj_GNB_CU_CP_ConfigurationUpdate->gNBCUCPTNLAToAddList);
	obj_GNB_CU_CP_ConfigurationUpdate->gNBCUCPTNLAToAddList_isset = 1;


	// GNB-CU-CP-TNLA-To-Remove-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__GNB_CU_CP_TNLA_To_Remove_List( &obj_GNB_CU_CP_ConfigurationUpdate->gNBCUCPTNLAToRemoveList);
	obj_GNB_CU_CP_ConfigurationUpdate->gNBCUCPTNLAToRemoveList_isset = 1;


	// GNB-CU-CP-TNLA-To-Update-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__GNB_CU_CP_TNLA_To_Update_List( &obj_GNB_CU_CP_ConfigurationUpdate->gNBCUCPTNLAToUpdateList);
	obj_GNB_CU_CP_ConfigurationUpdate->gNBCUCPTNLAToUpdateList_isset = 1;


	// Transport-Layer-Address-Info , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__Transport_Layer_Address_Info( &obj_GNB_CU_CP_ConfigurationUpdate->transportLayerAddressInfo);
	obj_GNB_CU_CP_ConfigurationUpdate->transportLayerAddressInfo_isset = 1;


	// Extended-GNB-CU-CP-Name , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__Extended_GNB_CU_CP_Name( &obj_GNB_CU_CP_ConfigurationUpdate->extendedGNBCUCPName);
	obj_GNB_CU_CP_ConfigurationUpdate->extendedGNBCUCPName_isset = 1;



	__si_e1ap_send_GNB_CU_CP_ConfigurationUpdate( obj_GNB_CU_CP_ConfigurationUpdate, node);
	__si_e1ap_memfree_pdu_GNB_CU_CP_ConfigurationUpdate( obj_GNB_CU_CP_ConfigurationUpdate);
}

void __si_e1ap__Send_GNB_CU_CP_ConfigurationUpdateAcknowledge_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_GNB_CU_CP_ConfigurationUpdateAcknowledge * obj_GNB_CU_CP_ConfigurationUpdateAcknowledge = (SI_E1AP_DT_PDU_GNB_CU_CP_ConfigurationUpdateAcknowledge*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GNB_CU_CP_ConfigurationUpdateAcknowledge));
	memset( obj_GNB_CU_CP_ConfigurationUpdateAcknowledge, 0, sizeof( SI_E1AP_DT_PDU_GNB_CU_CP_ConfigurationUpdateAcknowledge));

	// TransactionID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=255
	obj_GNB_CU_CP_ConfigurationUpdateAcknowledge->transactionID = __getTestINTEGER( 0, 255);
	obj_GNB_CU_CP_ConfigurationUpdateAcknowledge->transactionID_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_GNB_CU_CP_ConfigurationUpdateAcknowledge->criticalityDiagnostics);
	obj_GNB_CU_CP_ConfigurationUpdateAcknowledge->criticalityDiagnostics_isset = 0;


	// GNB-CU-CP-TNLA-Setup-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__GNB_CU_CP_TNLA_Setup_List( &obj_GNB_CU_CP_ConfigurationUpdateAcknowledge->gNBCUCPTNLASetupList);
	obj_GNB_CU_CP_ConfigurationUpdateAcknowledge->gNBCUCPTNLASetupList_isset = 1;


	// GNB-CU-CP-TNLA-Failed-To-Setup-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__GNB_CU_CP_TNLA_Failed_To_Setup_List( &obj_GNB_CU_CP_ConfigurationUpdateAcknowledge->gNBCUCPTNLAFailedToSetupList);
	obj_GNB_CU_CP_ConfigurationUpdateAcknowledge->gNBCUCPTNLAFailedToSetupList_isset = 0;


	// Transport-Layer-Address-Info , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__Transport_Layer_Address_Info( &obj_GNB_CU_CP_ConfigurationUpdateAcknowledge->transportLayerAddressInfo);
	obj_GNB_CU_CP_ConfigurationUpdateAcknowledge->transportLayerAddressInfo_isset = 0;



	__si_e1ap_send_GNB_CU_CP_ConfigurationUpdateAcknowledge( obj_GNB_CU_CP_ConfigurationUpdateAcknowledge, node);
	__si_e1ap_memfree_pdu_GNB_CU_CP_ConfigurationUpdateAcknowledge( obj_GNB_CU_CP_ConfigurationUpdateAcknowledge);
}

void __si_e1ap__Send_GNB_CU_CP_ConfigurationUpdateFailure_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_GNB_CU_CP_ConfigurationUpdateFailure * obj_GNB_CU_CP_ConfigurationUpdateFailure = (SI_E1AP_DT_PDU_GNB_CU_CP_ConfigurationUpdateFailure*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GNB_CU_CP_ConfigurationUpdateFailure));
	memset( obj_GNB_CU_CP_ConfigurationUpdateFailure, 0, sizeof( SI_E1AP_DT_PDU_GNB_CU_CP_ConfigurationUpdateFailure));

	// TransactionID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=255
	obj_GNB_CU_CP_ConfigurationUpdateFailure->transactionID = __getTestINTEGER( 0, 255);
	obj_GNB_CU_CP_ConfigurationUpdateFailure->transactionID_isset = 1;


	// Cause , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__Cause( &obj_GNB_CU_CP_ConfigurationUpdateFailure->cause);
	obj_GNB_CU_CP_ConfigurationUpdateFailure->cause->SelectedChoice = Cause_radioNetwork_val;

	switch( obj_GNB_CU_CP_ConfigurationUpdateFailure->cause->SelectedChoice)
	{
		case Cause_radioNetwork_val:
			obj_GNB_CU_CP_ConfigurationUpdateFailure->cause->u.radioNetwork = CauseRadioNetwork_unspecified_val;
			break;
		case Cause_transport_val:
			obj_GNB_CU_CP_ConfigurationUpdateFailure->cause->u.transport = CauseTransport_unspecified_val;
			break;
		case Cause_protocol_val:
			obj_GNB_CU_CP_ConfigurationUpdateFailure->cause->u.protocol = CauseProtocol_transfer_syntax_error_val;
			break;
		case Cause_misc_val:
			obj_GNB_CU_CP_ConfigurationUpdateFailure->cause->u.misc = CauseMisc_control_processing_overload_val;
			break;
		case Cause_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_Cause_ExtIEs( &obj_GNB_CU_CP_ConfigurationUpdateFailure->cause->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_GNB_CU_CP_ConfigurationUpdateFailure->cause_isset = 1;


	// TimeToWait , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_GNB_CU_CP_ConfigurationUpdateFailure->timeToWait = TimeToWait_v1s_val;
	obj_GNB_CU_CP_ConfigurationUpdateFailure->timeToWait_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_GNB_CU_CP_ConfigurationUpdateFailure->criticalityDiagnostics);
	obj_GNB_CU_CP_ConfigurationUpdateFailure->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_GNB_CU_CP_ConfigurationUpdateFailure( obj_GNB_CU_CP_ConfigurationUpdateFailure, node);
	__si_e1ap_memfree_pdu_GNB_CU_CP_ConfigurationUpdateFailure( obj_GNB_CU_CP_ConfigurationUpdateFailure);
}

void __si_e1ap__Send_E1ReleaseRequest_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_E1ReleaseRequest * obj_E1ReleaseRequest = (SI_E1AP_DT_PDU_E1ReleaseRequest*) __si_allocM( sizeof(SI_E1AP_DT_PDU_E1ReleaseRequest));
	memset( obj_E1ReleaseRequest, 0, sizeof( SI_E1AP_DT_PDU_E1ReleaseRequest));

	// TransactionID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=255
	obj_E1ReleaseRequest->transactionID = __getTestINTEGER( 0, 255);
	obj_E1ReleaseRequest->transactionID_isset = 1;


	// Cause , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__Cause( &obj_E1ReleaseRequest->cause);
	obj_E1ReleaseRequest->cause->SelectedChoice = Cause_radioNetwork_val;

	switch( obj_E1ReleaseRequest->cause->SelectedChoice)
	{
		case Cause_radioNetwork_val:
			obj_E1ReleaseRequest->cause->u.radioNetwork = CauseRadioNetwork_unspecified_val;
			break;
		case Cause_transport_val:
			obj_E1ReleaseRequest->cause->u.transport = CauseTransport_unspecified_val;
			break;
		case Cause_protocol_val:
			obj_E1ReleaseRequest->cause->u.protocol = CauseProtocol_transfer_syntax_error_val;
			break;
		case Cause_misc_val:
			obj_E1ReleaseRequest->cause->u.misc = CauseMisc_control_processing_overload_val;
			break;
		case Cause_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_Cause_ExtIEs( &obj_E1ReleaseRequest->cause->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_E1ReleaseRequest->cause_isset = 1;



	__si_e1ap_send_E1ReleaseRequest( obj_E1ReleaseRequest, node);
	__si_e1ap_memfree_pdu_E1ReleaseRequest( obj_E1ReleaseRequest);
}

void __si_e1ap__Send_E1ReleaseResponse_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_E1ReleaseResponse * obj_E1ReleaseResponse = (SI_E1AP_DT_PDU_E1ReleaseResponse*) __si_allocM( sizeof(SI_E1AP_DT_PDU_E1ReleaseResponse));
	memset( obj_E1ReleaseResponse, 0, sizeof( SI_E1AP_DT_PDU_E1ReleaseResponse));

	// TransactionID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=255
	obj_E1ReleaseResponse->transactionID = __getTestINTEGER( 0, 255);
	obj_E1ReleaseResponse->transactionID_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_E1ReleaseResponse->criticalityDiagnostics);
	obj_E1ReleaseResponse->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_E1ReleaseResponse( obj_E1ReleaseResponse, node);
	__si_e1ap_memfree_pdu_E1ReleaseResponse( obj_E1ReleaseResponse);
}

void __si_e1ap__Send_BearerContextSetupRequest_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_BearerContextSetupRequest * obj_BearerContextSetupRequest = (SI_E1AP_DT_PDU_BearerContextSetupRequest*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BearerContextSetupRequest));
	memset( obj_BearerContextSetupRequest, 0, sizeof( SI_E1AP_DT_PDU_BearerContextSetupRequest));

	// GNB-CU-CP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_BearerContextSetupRequest->gNBCUCPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_BearerContextSetupRequest->gNBCUCPUEE1APID_isset = 1;


	// SecurityInformation , PRESENCE = mandatory   SEQUENCE
	__si_e1ap__set_testdata__SecurityInformation( &obj_BearerContextSetupRequest->securityInformation);
	obj_BearerContextSetupRequest->securityInformation_isset = 1;


	// BitRate , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4000000000000
	obj_BearerContextSetupRequest->uEDLAggregateMaximumBitRate = __getTestINTEGER( 0, 4000000000000);
	obj_BearerContextSetupRequest->uEDLAggregateMaximumBitRate_isset = 1;


	// BitRate , PRESENCE = optional  INTEGER , MIN=0, MAX=4000000000000
	obj_BearerContextSetupRequest->uEDLMaximumIntegrityProtectedDataRate = __getTestINTEGER( 0, 4000000000000);
	obj_BearerContextSetupRequest->uEDLMaximumIntegrityProtectedDataRate_isset = 1;


	// PLMN-Identity    OCTETSTRING, PRESENCE = mandatory , MIN=3, MAX=3
	__si_e1ap_init_PLMN_Identity2( &obj_BearerContextSetupRequest->servingPLMN, "\x16\x09\x10", 3);
	obj_BearerContextSetupRequest->servingPLMN_isset = 1;


	// ActivityNotificationLevel , PRESENCE = mandatory   ENUMERATED, PRESENCE = mandatory
	obj_BearerContextSetupRequest->activityNotificationLevel = ActivityNotificationLevel_drb_val;
	obj_BearerContextSetupRequest->activityNotificationLevel_isset = 1;


	// Inactivity-Timer , PRESENCE = optional  INTEGER , MIN=1, MAX=7200
	obj_BearerContextSetupRequest->uEInactivityTimer = __getTestINTEGER( 1, 7200);
	obj_BearerContextSetupRequest->uEInactivityTimer_isset = 1;


	// BearerContextStatusChange , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_BearerContextSetupRequest->bearerContextStatusChange = BearerContextStatusChange_suspend_val;
	obj_BearerContextSetupRequest->bearerContextStatusChange_isset = 1;


	// System-BearerContextSetupRequest  , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__System_BearerContextSetupRequest( &obj_BearerContextSetupRequest->systemBearerContextSetupRequest);
	obj_BearerContextSetupRequest->systemBearerContextSetupRequest->SelectedChoice = System_BearerContextSetupRequest_e_UTRAN_BearerContextSetupRequest_val;

	switch( obj_BearerContextSetupRequest->systemBearerContextSetupRequest->SelectedChoice)
	{
		case System_BearerContextSetupRequest_e_UTRAN_BearerContextSetupRequest_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_EUTRAN_BearerContextSetupRequest( &obj_BearerContextSetupRequest->systemBearerContextSetupRequest->u.e_UTRAN_BearerContextSetupRequest);   // L:11825
			}
			break;
		case System_BearerContextSetupRequest_nG_RAN_BearerContextSetupRequest_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_NG_RAN_BearerContextSetupRequest( &obj_BearerContextSetupRequest->systemBearerContextSetupRequest->u.nG_RAN_BearerContextSetupRequest);   // L:11825
			}
			break;
		case System_BearerContextSetupRequest_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_System_BearerContextSetupRequest_ExtIEs( &obj_BearerContextSetupRequest->systemBearerContextSetupRequest->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_BearerContextSetupRequest->systemBearerContextSetupRequest_isset = 1;


	// RANUEID    OCTETSTRING, PRESENCE = optional , MIN=8, MAX=8
	__si_e1ap_init_RANUEID2( &obj_BearerContextSetupRequest->rANUEID, "\x23\x15\x11\x12\x18\x08\x01\x15", 8);
	obj_BearerContextSetupRequest->rANUEID_isset = 1;


	// GNB-DU-ID , PRESENCE = optional  INTEGER , MIN=0, MAX=68719476735
	obj_BearerContextSetupRequest->gNBDUID = __getTestINTEGER( 0, 68719476735);
	obj_BearerContextSetupRequest->gNBDUID_isset = 1;


	// TraceActivation , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__TraceActivation( &obj_BearerContextSetupRequest->traceActivation);
	obj_BearerContextSetupRequest->traceActivation_isset = 1;


	// NPNContextInfo , PRESENCE = optional   CHOICE
	__si_e1ap__set_testdata__NPNContextInfo( &obj_BearerContextSetupRequest->nPNContextInfo);
	obj_BearerContextSetupRequest->nPNContextInfo->SelectedChoice = NPNContextInfo_sNPN_val;

	switch( obj_BearerContextSetupRequest->nPNContextInfo->SelectedChoice)
	{
		case NPNContextInfo_sNPN_val:
			__si_e1ap__set_testdata__NPNContextInfo_SNPN( &obj_BearerContextSetupRequest->nPNContextInfo->u.sNPN); //   L:11712
			break;
		case NPNContextInfo_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_NPNContextInfo_ExtIEs( &obj_BearerContextSetupRequest->nPNContextInfo->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_BearerContextSetupRequest->nPNContextInfo_isset = 1;


	// MDTPLMNList , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__MDTPLMNList( &obj_BearerContextSetupRequest->managementBasedMDTPLMNList);
	obj_BearerContextSetupRequest->managementBasedMDTPLMNList_isset = 1;


	// CHOInitiation , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_BearerContextSetupRequest->cHOInitiation = CHOInitiation_true_val;
	obj_BearerContextSetupRequest->cHOInitiation_isset = 1;


	// AdditionalHandoverInfo , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_BearerContextSetupRequest->additionalHandoverInfo = AdditionalHandoverInfo_discard_pdpc_SN_val;
	obj_BearerContextSetupRequest->additionalHandoverInfo_isset = 1;


	// DirectForwardingPathAvailability , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_BearerContextSetupRequest->directForwardingPathAvailability = DirectForwardingPathAvailability_inter_system_direct_path_available_val;
	obj_BearerContextSetupRequest->directForwardingPathAvailability_isset = 1;


	// GNB-CU-UP-UE-E1AP-ID  , PRESENCE = optional  INTEGER , MIN=0, MAX=4294967295
	obj_BearerContextSetupRequest->gNBCUUPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_BearerContextSetupRequest->gNBCUUPUEE1APID_isset = 1;


	// MDTPollutedMeasurementIndicator , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_BearerContextSetupRequest->mDTPollutedMeasurementIndicator = MDTPollutedMeasurementIndicator_iDC_val;
	obj_BearerContextSetupRequest->mDTPollutedMeasurementIndicator_isset = 1;


	// UESliceMaximumBitRateList , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__UESliceMaximumBitRateList( &obj_BearerContextSetupRequest->uESliceMaximumBitRateList);
	obj_BearerContextSetupRequest->uESliceMaximumBitRateList_isset = 1;


	// SCGActivationStatus , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_BearerContextSetupRequest->sCGActivationStatus = SCGActivationStatus_scg_activated_val;
	obj_BearerContextSetupRequest->sCGActivationStatus_isset = 1;


	// MT-SDT-Information-Request , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_BearerContextSetupRequest->mTSDTInformationRequest = MT_SDT_Information_Request_true_val;
	obj_BearerContextSetupRequest->mTSDTInformationRequest_isset = 1;


	// SDT-data-size-threshold , PRESENCE = optional  INTEGER , MIN=1, MAX=192000
	obj_BearerContextSetupRequest->sDTdatasizethreshold = __getTestINTEGER( 1, 192000);
	obj_BearerContextSetupRequest->sDTdatasizethreshold_isset = 1;



	__si_e1ap_send_BearerContextSetupRequest( obj_BearerContextSetupRequest, node);
	__si_e1ap_memfree_pdu_BearerContextSetupRequest( obj_BearerContextSetupRequest);
}

void __si_e1ap__Send_BearerContextSetupResponse_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_BearerContextSetupResponse * obj_BearerContextSetupResponse = (SI_E1AP_DT_PDU_BearerContextSetupResponse*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BearerContextSetupResponse));
	memset( obj_BearerContextSetupResponse, 0, sizeof( SI_E1AP_DT_PDU_BearerContextSetupResponse));

	// GNB-CU-CP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_BearerContextSetupResponse->gNBCUCPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_BearerContextSetupResponse->gNBCUCPUEE1APID_isset = 1;


	// GNB-CU-UP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_BearerContextSetupResponse->gNBCUUPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_BearerContextSetupResponse->gNBCUUPUEE1APID_isset = 1;


	// System-BearerContextSetupResponse , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__System_BearerContextSetupResponse( &obj_BearerContextSetupResponse->systemBearerContextSetupResponse);
	obj_BearerContextSetupResponse->systemBearerContextSetupResponse->SelectedChoice = System_BearerContextSetupResponse_e_UTRAN_BearerContextSetupResponse_val;

	switch( obj_BearerContextSetupResponse->systemBearerContextSetupResponse->SelectedChoice)
	{
		case System_BearerContextSetupResponse_e_UTRAN_BearerContextSetupResponse_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_EUTRAN_BearerContextSetupResponse( &obj_BearerContextSetupResponse->systemBearerContextSetupResponse->u.e_UTRAN_BearerContextSetupResponse);   // L:11825
			}
			break;
		case System_BearerContextSetupResponse_nG_RAN_BearerContextSetupResponse_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_NG_RAN_BearerContextSetupResponse( &obj_BearerContextSetupResponse->systemBearerContextSetupResponse->u.nG_RAN_BearerContextSetupResponse);   // L:11825
			}
			break;
		case System_BearerContextSetupResponse_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_System_BearerContextSetupResponse_ExtIEs( &obj_BearerContextSetupResponse->systemBearerContextSetupResponse->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_BearerContextSetupResponse->systemBearerContextSetupResponse_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_BearerContextSetupResponse->criticalityDiagnostics);
	obj_BearerContextSetupResponse->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_BearerContextSetupResponse( obj_BearerContextSetupResponse, node);
	__si_e1ap_memfree_pdu_BearerContextSetupResponse( obj_BearerContextSetupResponse);
}

void __si_e1ap__Send_BearerContextSetupFailure_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_BearerContextSetupFailure * obj_BearerContextSetupFailure = (SI_E1AP_DT_PDU_BearerContextSetupFailure*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BearerContextSetupFailure));
	memset( obj_BearerContextSetupFailure, 0, sizeof( SI_E1AP_DT_PDU_BearerContextSetupFailure));

	// GNB-CU-CP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_BearerContextSetupFailure->gNBCUCPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_BearerContextSetupFailure->gNBCUCPUEE1APID_isset = 1;


	// GNB-CU-UP-UE-E1AP-ID  , PRESENCE = optional  INTEGER , MIN=0, MAX=4294967295
	obj_BearerContextSetupFailure->gNBCUUPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_BearerContextSetupFailure->gNBCUUPUEE1APID_isset = 1;


	// Cause , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__Cause( &obj_BearerContextSetupFailure->cause);
	obj_BearerContextSetupFailure->cause->SelectedChoice = Cause_radioNetwork_val;

	switch( obj_BearerContextSetupFailure->cause->SelectedChoice)
	{
		case Cause_radioNetwork_val:
			obj_BearerContextSetupFailure->cause->u.radioNetwork = CauseRadioNetwork_unspecified_val;
			break;
		case Cause_transport_val:
			obj_BearerContextSetupFailure->cause->u.transport = CauseTransport_unspecified_val;
			break;
		case Cause_protocol_val:
			obj_BearerContextSetupFailure->cause->u.protocol = CauseProtocol_transfer_syntax_error_val;
			break;
		case Cause_misc_val:
			obj_BearerContextSetupFailure->cause->u.misc = CauseMisc_control_processing_overload_val;
			break;
		case Cause_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_Cause_ExtIEs( &obj_BearerContextSetupFailure->cause->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_BearerContextSetupFailure->cause_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_BearerContextSetupFailure->criticalityDiagnostics);
	obj_BearerContextSetupFailure->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_BearerContextSetupFailure( obj_BearerContextSetupFailure, node);
	__si_e1ap_memfree_pdu_BearerContextSetupFailure( obj_BearerContextSetupFailure);
}

void __si_e1ap__Send_BearerContextModificationRequest_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_BearerContextModificationRequest * obj_BearerContextModificationRequest = (SI_E1AP_DT_PDU_BearerContextModificationRequest*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BearerContextModificationRequest));
	memset( obj_BearerContextModificationRequest, 0, sizeof( SI_E1AP_DT_PDU_BearerContextModificationRequest));

	// GNB-CU-CP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_BearerContextModificationRequest->gNBCUCPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_BearerContextModificationRequest->gNBCUCPUEE1APID_isset = 1;


	// GNB-CU-UP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_BearerContextModificationRequest->gNBCUUPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_BearerContextModificationRequest->gNBCUUPUEE1APID_isset = 1;


	// SecurityInformation , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__SecurityInformation( &obj_BearerContextModificationRequest->securityInformation);
	obj_BearerContextModificationRequest->securityInformation_isset = 1;


	// BitRate , PRESENCE = optional  INTEGER , MIN=0, MAX=4000000000000
	obj_BearerContextModificationRequest->uEDLAggregateMaximumBitRate = __getTestINTEGER( 0, 4000000000000);
	obj_BearerContextModificationRequest->uEDLAggregateMaximumBitRate_isset = 1;


	// BitRate , PRESENCE = optional  INTEGER , MIN=0, MAX=4000000000000
	obj_BearerContextModificationRequest->uEDLMaximumIntegrityProtectedDataRate = __getTestINTEGER( 0, 4000000000000);
	obj_BearerContextModificationRequest->uEDLMaximumIntegrityProtectedDataRate_isset = 1;


	// BearerContextStatusChange , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_BearerContextModificationRequest->bearerContextStatusChange = BearerContextStatusChange_suspend_val;
	obj_BearerContextModificationRequest->bearerContextStatusChange_isset = 1;


	// New-UL-TNL-Information-Required, PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_BearerContextModificationRequest->newULTNLInformationRequired = New_UL_TNL_Information_Required_required_val;
	obj_BearerContextModificationRequest->newULTNLInformationRequired_isset = 1;


	// Inactivity-Timer , PRESENCE = optional  INTEGER , MIN=1, MAX=7200
	obj_BearerContextModificationRequest->uEInactivityTimer = __getTestINTEGER( 1, 7200);
	obj_BearerContextModificationRequest->uEInactivityTimer_isset = 1;


	// DataDiscardRequired , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_BearerContextModificationRequest->dataDiscardRequired = DataDiscardRequired_required_val;
	obj_BearerContextModificationRequest->dataDiscardRequired_isset = 1;


	// System-BearerContextModificationRequest  , PRESENCE = optional   CHOICE
	__si_e1ap__set_testdata__System_BearerContextModificationRequest( &obj_BearerContextModificationRequest->systemBearerContextModificationRequest);
	obj_BearerContextModificationRequest->systemBearerContextModificationRequest->SelectedChoice = System_BearerContextModificationRequest_e_UTRAN_BearerContextModificationRequest_val;

	switch( obj_BearerContextModificationRequest->systemBearerContextModificationRequest->SelectedChoice)
	{
		case System_BearerContextModificationRequest_e_UTRAN_BearerContextModificationRequest_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_EUTRAN_BearerContextModificationRequest( &obj_BearerContextModificationRequest->systemBearerContextModificationRequest->u.e_UTRAN_BearerContextModificationRequest);   // L:11825
			}
			break;
		case System_BearerContextModificationRequest_nG_RAN_BearerContextModificationRequest_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_NG_RAN_BearerContextModificationRequest( &obj_BearerContextModificationRequest->systemBearerContextModificationRequest->u.nG_RAN_BearerContextModificationRequest);   // L:11825
			}
			break;
		case System_BearerContextModificationRequest_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_System_BearerContextModificationRequest_ExtIEs( &obj_BearerContextModificationRequest->systemBearerContextModificationRequest->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_BearerContextModificationRequest->systemBearerContextModificationRequest_isset = 1;


	// RANUEID    OCTETSTRING, PRESENCE = optional , MIN=8, MAX=8
	__si_e1ap_init_RANUEID2( &obj_BearerContextModificationRequest->rANUEID, "\x05\x18\x22\x14\x21\x13\x01\x08", 8);
	obj_BearerContextModificationRequest->rANUEID_isset = 1;


	// GNB-DU-ID , PRESENCE = optional  INTEGER , MIN=0, MAX=68719476735
	obj_BearerContextModificationRequest->gNBDUID = __getTestINTEGER( 0, 68719476735);
	obj_BearerContextModificationRequest->gNBDUID_isset = 1;


	// ActivityNotificationLevel , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_BearerContextModificationRequest->activityNotificationLevel = ActivityNotificationLevel_drb_val;
	obj_BearerContextModificationRequest->activityNotificationLevel_isset = 1;


	// MDTPollutedMeasurementIndicator , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_BearerContextModificationRequest->mDTPollutedMeasurementIndicator = MDTPollutedMeasurementIndicator_iDC_val;
	obj_BearerContextModificationRequest->mDTPollutedMeasurementIndicator_isset = 1;


	// UESliceMaximumBitRateList , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__UESliceMaximumBitRateList( &obj_BearerContextModificationRequest->uESliceMaximumBitRateList);
	obj_BearerContextModificationRequest->uESliceMaximumBitRateList_isset = 1;


	// SCGActivationStatus , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_BearerContextModificationRequest->sCGActivationStatus = SCGActivationStatus_scg_activated_val;
	obj_BearerContextModificationRequest->sCGActivationStatus_isset = 1;


	// SDTContinueROHC , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_BearerContextModificationRequest->sDTContinueROHC = SDTContinueROHC_true_val;
	obj_BearerContextModificationRequest->sDTContinueROHC_isset = 1;


	// MDTPLMNModificationList , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__MDTPLMNModificationList( &obj_BearerContextModificationRequest->managementBasedMDTPLMNModificationList);
	obj_BearerContextModificationRequest->managementBasedMDTPLMNModificationList_isset = 1;


	// InactivityInformationRequest , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_BearerContextModificationRequest->inactivityInformationRequest = InactivityInformationRequest_true_val;
	obj_BearerContextModificationRequest->inactivityInformationRequest_isset = 1;


	// MT-SDT-Information-Request , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_BearerContextModificationRequest->mTSDTInformationRequest = MT_SDT_Information_Request_true_val;
	obj_BearerContextModificationRequest->mTSDTInformationRequest_isset = 1;


	// SDT-data-size-threshold , PRESENCE = optional  INTEGER , MIN=1, MAX=192000
	obj_BearerContextModificationRequest->sDTdatasizethreshold = __getTestINTEGER( 1, 192000);
	obj_BearerContextModificationRequest->sDTdatasizethreshold_isset = 1;



	__si_e1ap_send_BearerContextModificationRequest( obj_BearerContextModificationRequest, node);
	__si_e1ap_memfree_pdu_BearerContextModificationRequest( obj_BearerContextModificationRequest);
}

void __si_e1ap__Send_BearerContextModificationResponse_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_BearerContextModificationResponse * obj_BearerContextModificationResponse = (SI_E1AP_DT_PDU_BearerContextModificationResponse*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BearerContextModificationResponse));
	memset( obj_BearerContextModificationResponse, 0, sizeof( SI_E1AP_DT_PDU_BearerContextModificationResponse));

	// GNB-CU-CP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_BearerContextModificationResponse->gNBCUCPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_BearerContextModificationResponse->gNBCUCPUEE1APID_isset = 1;


	// GNB-CU-UP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_BearerContextModificationResponse->gNBCUUPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_BearerContextModificationResponse->gNBCUUPUEE1APID_isset = 1;


	// System-BearerContextModificationResponse  , PRESENCE = optional   CHOICE
	__si_e1ap__set_testdata__System_BearerContextModificationResponse( &obj_BearerContextModificationResponse->systemBearerContextModificationResponse);
	obj_BearerContextModificationResponse->systemBearerContextModificationResponse->SelectedChoice = System_BearerContextModificationResponse_e_UTRAN_BearerContextModificationResponse_val;

	switch( obj_BearerContextModificationResponse->systemBearerContextModificationResponse->SelectedChoice)
	{
		case System_BearerContextModificationResponse_e_UTRAN_BearerContextModificationResponse_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_EUTRAN_BearerContextModificationResponse( &obj_BearerContextModificationResponse->systemBearerContextModificationResponse->u.e_UTRAN_BearerContextModificationResponse);   // L:11825
			}
			break;
		case System_BearerContextModificationResponse_nG_RAN_BearerContextModificationResponse_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_NG_RAN_BearerContextModificationResponse( &obj_BearerContextModificationResponse->systemBearerContextModificationResponse->u.nG_RAN_BearerContextModificationResponse);   // L:11825
			}
			break;
		case System_BearerContextModificationResponse_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_System_BearerContextModificationResponse_ExtIEs( &obj_BearerContextModificationResponse->systemBearerContextModificationResponse->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_BearerContextModificationResponse->systemBearerContextModificationResponse_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_BearerContextModificationResponse->criticalityDiagnostics);
	obj_BearerContextModificationResponse->criticalityDiagnostics_isset = 1;


	// UEInactivityInformation , PRESENCE = optional  INTEGER , MIN=1, MAX=7200
	obj_BearerContextModificationResponse->uEInactivityInformation = __getTestINTEGER( 1, 7200);
	obj_BearerContextModificationResponse->uEInactivityInformation_isset = 1;



	__si_e1ap_send_BearerContextModificationResponse( obj_BearerContextModificationResponse, node);
	__si_e1ap_memfree_pdu_BearerContextModificationResponse( obj_BearerContextModificationResponse);
}

void __si_e1ap__Send_BearerContextModificationFailure_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_BearerContextModificationFailure * obj_BearerContextModificationFailure = (SI_E1AP_DT_PDU_BearerContextModificationFailure*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BearerContextModificationFailure));
	memset( obj_BearerContextModificationFailure, 0, sizeof( SI_E1AP_DT_PDU_BearerContextModificationFailure));

	// GNB-CU-CP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_BearerContextModificationFailure->gNBCUCPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_BearerContextModificationFailure->gNBCUCPUEE1APID_isset = 1;


	// GNB-CU-UP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_BearerContextModificationFailure->gNBCUUPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_BearerContextModificationFailure->gNBCUUPUEE1APID_isset = 1;


	// Cause , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__Cause( &obj_BearerContextModificationFailure->cause);
	obj_BearerContextModificationFailure->cause->SelectedChoice = Cause_radioNetwork_val;

	switch( obj_BearerContextModificationFailure->cause->SelectedChoice)
	{
		case Cause_radioNetwork_val:
			obj_BearerContextModificationFailure->cause->u.radioNetwork = CauseRadioNetwork_unspecified_val;
			break;
		case Cause_transport_val:
			obj_BearerContextModificationFailure->cause->u.transport = CauseTransport_unspecified_val;
			break;
		case Cause_protocol_val:
			obj_BearerContextModificationFailure->cause->u.protocol = CauseProtocol_transfer_syntax_error_val;
			break;
		case Cause_misc_val:
			obj_BearerContextModificationFailure->cause->u.misc = CauseMisc_control_processing_overload_val;
			break;
		case Cause_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_Cause_ExtIEs( &obj_BearerContextModificationFailure->cause->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_BearerContextModificationFailure->cause_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_BearerContextModificationFailure->criticalityDiagnostics);
	obj_BearerContextModificationFailure->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_BearerContextModificationFailure( obj_BearerContextModificationFailure, node);
	__si_e1ap_memfree_pdu_BearerContextModificationFailure( obj_BearerContextModificationFailure);
}

void __si_e1ap__Send_BearerContextModificationRequired_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_BearerContextModificationRequired * obj_BearerContextModificationRequired = (SI_E1AP_DT_PDU_BearerContextModificationRequired*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BearerContextModificationRequired));
	memset( obj_BearerContextModificationRequired, 0, sizeof( SI_E1AP_DT_PDU_BearerContextModificationRequired));

	// GNB-CU-CP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_BearerContextModificationRequired->gNBCUCPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_BearerContextModificationRequired->gNBCUCPUEE1APID_isset = 1;


	// GNB-CU-UP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_BearerContextModificationRequired->gNBCUUPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_BearerContextModificationRequired->gNBCUUPUEE1APID_isset = 1;


	// System-BearerContextModificationRequired  , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__System_BearerContextModificationRequired( &obj_BearerContextModificationRequired->systemBearerContextModificationRequired);
	obj_BearerContextModificationRequired->systemBearerContextModificationRequired->SelectedChoice = System_BearerContextModificationRequired_e_UTRAN_BearerContextModificationRequired_val;

	switch( obj_BearerContextModificationRequired->systemBearerContextModificationRequired->SelectedChoice)
	{
		case System_BearerContextModificationRequired_e_UTRAN_BearerContextModificationRequired_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_EUTRAN_BearerContextModificationRequired( &obj_BearerContextModificationRequired->systemBearerContextModificationRequired->u.e_UTRAN_BearerContextModificationRequired);   // L:11825
			}
			break;
		case System_BearerContextModificationRequired_nG_RAN_BearerContextModificationRequired_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_NG_RAN_BearerContextModificationRequired( &obj_BearerContextModificationRequired->systemBearerContextModificationRequired->u.nG_RAN_BearerContextModificationRequired);   // L:11825
			}
			break;
		case System_BearerContextModificationRequired_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_System_BearerContextModificationRequired_ExtIEs( &obj_BearerContextModificationRequired->systemBearerContextModificationRequired->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_BearerContextModificationRequired->systemBearerContextModificationRequired_isset = 1;



	__si_e1ap_send_BearerContextModificationRequired( obj_BearerContextModificationRequired, node);
	__si_e1ap_memfree_pdu_BearerContextModificationRequired( obj_BearerContextModificationRequired);
}

void __si_e1ap__Send_BearerContextModificationConfirm_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_BearerContextModificationConfirm * obj_BearerContextModificationConfirm = (SI_E1AP_DT_PDU_BearerContextModificationConfirm*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BearerContextModificationConfirm));
	memset( obj_BearerContextModificationConfirm, 0, sizeof( SI_E1AP_DT_PDU_BearerContextModificationConfirm));

	// GNB-CU-CP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_BearerContextModificationConfirm->gNBCUCPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_BearerContextModificationConfirm->gNBCUCPUEE1APID_isset = 1;


	// GNB-CU-UP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_BearerContextModificationConfirm->gNBCUUPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_BearerContextModificationConfirm->gNBCUUPUEE1APID_isset = 1;


	// System-BearerContextModificationConfirm  , PRESENCE = optional   CHOICE
	__si_e1ap__set_testdata__System_BearerContextModificationConfirm( &obj_BearerContextModificationConfirm->systemBearerContextModificationConfirm);
	obj_BearerContextModificationConfirm->systemBearerContextModificationConfirm->SelectedChoice = System_BearerContextModificationConfirm_e_UTRAN_BearerContextModificationConfirm_val;

	switch( obj_BearerContextModificationConfirm->systemBearerContextModificationConfirm->SelectedChoice)
	{
		case System_BearerContextModificationConfirm_e_UTRAN_BearerContextModificationConfirm_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_EUTRAN_BearerContextModificationConfirm( &obj_BearerContextModificationConfirm->systemBearerContextModificationConfirm->u.e_UTRAN_BearerContextModificationConfirm);   // L:11825
			}
			break;
		case System_BearerContextModificationConfirm_nG_RAN_BearerContextModificationConfirm_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_NG_RAN_BearerContextModificationConfirm( &obj_BearerContextModificationConfirm->systemBearerContextModificationConfirm->u.nG_RAN_BearerContextModificationConfirm);   // L:11825
			}
			break;
		case System_BearerContextModificationConfirm_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_System_BearerContextModificationConfirm_ExtIEs( &obj_BearerContextModificationConfirm->systemBearerContextModificationConfirm->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_BearerContextModificationConfirm->systemBearerContextModificationConfirm_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_BearerContextModificationConfirm->criticalityDiagnostics);
	obj_BearerContextModificationConfirm->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_BearerContextModificationConfirm( obj_BearerContextModificationConfirm, node);
	__si_e1ap_memfree_pdu_BearerContextModificationConfirm( obj_BearerContextModificationConfirm);
}

void __si_e1ap__Send_BearerContextReleaseCommand_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_BearerContextReleaseCommand * obj_BearerContextReleaseCommand = (SI_E1AP_DT_PDU_BearerContextReleaseCommand*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BearerContextReleaseCommand));
	memset( obj_BearerContextReleaseCommand, 0, sizeof( SI_E1AP_DT_PDU_BearerContextReleaseCommand));

	// GNB-CU-CP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_BearerContextReleaseCommand->gNBCUCPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_BearerContextReleaseCommand->gNBCUCPUEE1APID_isset = 1;


	// GNB-CU-UP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_BearerContextReleaseCommand->gNBCUUPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_BearerContextReleaseCommand->gNBCUUPUEE1APID_isset = 1;


	// Cause , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__Cause( &obj_BearerContextReleaseCommand->cause);
	obj_BearerContextReleaseCommand->cause->SelectedChoice = Cause_radioNetwork_val;

	switch( obj_BearerContextReleaseCommand->cause->SelectedChoice)
	{
		case Cause_radioNetwork_val:
			obj_BearerContextReleaseCommand->cause->u.radioNetwork = CauseRadioNetwork_unspecified_val;
			break;
		case Cause_transport_val:
			obj_BearerContextReleaseCommand->cause->u.transport = CauseTransport_unspecified_val;
			break;
		case Cause_protocol_val:
			obj_BearerContextReleaseCommand->cause->u.protocol = CauseProtocol_transfer_syntax_error_val;
			break;
		case Cause_misc_val:
			obj_BearerContextReleaseCommand->cause->u.misc = CauseMisc_control_processing_overload_val;
			break;
		case Cause_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_Cause_ExtIEs( &obj_BearerContextReleaseCommand->cause->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_BearerContextReleaseCommand->cause_isset = 1;



	__si_e1ap_send_BearerContextReleaseCommand( obj_BearerContextReleaseCommand, node);
	__si_e1ap_memfree_pdu_BearerContextReleaseCommand( obj_BearerContextReleaseCommand);
}

void __si_e1ap__Send_BearerContextReleaseComplete_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_BearerContextReleaseComplete * obj_BearerContextReleaseComplete = (SI_E1AP_DT_PDU_BearerContextReleaseComplete*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BearerContextReleaseComplete));
	memset( obj_BearerContextReleaseComplete, 0, sizeof( SI_E1AP_DT_PDU_BearerContextReleaseComplete));

	// GNB-CU-CP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_BearerContextReleaseComplete->gNBCUCPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_BearerContextReleaseComplete->gNBCUCPUEE1APID_isset = 1;


	// GNB-CU-UP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_BearerContextReleaseComplete->gNBCUUPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_BearerContextReleaseComplete->gNBCUUPUEE1APID_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_BearerContextReleaseComplete->criticalityDiagnostics);
	obj_BearerContextReleaseComplete->criticalityDiagnostics_isset = 1;


	// RetainabilityMeasurementsInfo , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__RetainabilityMeasurementsInfo( &obj_BearerContextReleaseComplete->retainabilityMeasurementsInfo);
	obj_BearerContextReleaseComplete->retainabilityMeasurementsInfo_isset = 1;



	__si_e1ap_send_BearerContextReleaseComplete( obj_BearerContextReleaseComplete, node);
	__si_e1ap_memfree_pdu_BearerContextReleaseComplete( obj_BearerContextReleaseComplete);
}

void __si_e1ap__Send_BearerContextReleaseRequest_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_BearerContextReleaseRequest * obj_BearerContextReleaseRequest = (SI_E1AP_DT_PDU_BearerContextReleaseRequest*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BearerContextReleaseRequest));
	memset( obj_BearerContextReleaseRequest, 0, sizeof( SI_E1AP_DT_PDU_BearerContextReleaseRequest));

	// GNB-CU-CP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_BearerContextReleaseRequest->gNBCUCPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_BearerContextReleaseRequest->gNBCUCPUEE1APID_isset = 1;


	// GNB-CU-UP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_BearerContextReleaseRequest->gNBCUUPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_BearerContextReleaseRequest->gNBCUUPUEE1APID_isset = 1;


	// DRB-Status-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__DRB_Status_List( &obj_BearerContextReleaseRequest->dRBStatusList);
	obj_BearerContextReleaseRequest->dRBStatusList_isset = 1;


	// Cause , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__Cause( &obj_BearerContextReleaseRequest->cause);
	obj_BearerContextReleaseRequest->cause->SelectedChoice = Cause_radioNetwork_val;

	switch( obj_BearerContextReleaseRequest->cause->SelectedChoice)
	{
		case Cause_radioNetwork_val:
			obj_BearerContextReleaseRequest->cause->u.radioNetwork = CauseRadioNetwork_unspecified_val;
			break;
		case Cause_transport_val:
			obj_BearerContextReleaseRequest->cause->u.transport = CauseTransport_unspecified_val;
			break;
		case Cause_protocol_val:
			obj_BearerContextReleaseRequest->cause->u.protocol = CauseProtocol_transfer_syntax_error_val;
			break;
		case Cause_misc_val:
			obj_BearerContextReleaseRequest->cause->u.misc = CauseMisc_control_processing_overload_val;
			break;
		case Cause_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_Cause_ExtIEs( &obj_BearerContextReleaseRequest->cause->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_BearerContextReleaseRequest->cause_isset = 1;



	__si_e1ap_send_BearerContextReleaseRequest( obj_BearerContextReleaseRequest, node);
	__si_e1ap_memfree_pdu_BearerContextReleaseRequest( obj_BearerContextReleaseRequest);
}

void __si_e1ap__Send_BearerContextInactivityNotification_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_BearerContextInactivityNotification * obj_BearerContextInactivityNotification = (SI_E1AP_DT_PDU_BearerContextInactivityNotification*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BearerContextInactivityNotification));
	memset( obj_BearerContextInactivityNotification, 0, sizeof( SI_E1AP_DT_PDU_BearerContextInactivityNotification));

	// GNB-CU-CP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_BearerContextInactivityNotification->gNBCUCPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_BearerContextInactivityNotification->gNBCUCPUEE1APID_isset = 1;


	// GNB-CU-UP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_BearerContextInactivityNotification->gNBCUUPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_BearerContextInactivityNotification->gNBCUUPUEE1APID_isset = 1;


	// ActivityInformation , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__ActivityInformation( &obj_BearerContextInactivityNotification->activityInformation);
	obj_BearerContextInactivityNotification->activityInformation->SelectedChoice = ActivityInformation_dRB_Activity_List_val;

	switch( obj_BearerContextInactivityNotification->activityInformation->SelectedChoice)
	{
		case ActivityInformation_dRB_Activity_List_val:
			__si_e1ap__set_testdata__DRB_Activity_List( &obj_BearerContextInactivityNotification->activityInformation->u.dRB_Activity_List); //   L:11791
			break;
		case ActivityInformation_pDU_Session_Resource_Activity_List_val:
			__si_e1ap__set_testdata__PDU_Session_Resource_Activity_List( &obj_BearerContextInactivityNotification->activityInformation->u.pDU_Session_Resource_Activity_List); //   L:11791
			break;
		case ActivityInformation_uE_Activity_val:
			obj_BearerContextInactivityNotification->activityInformation->u.uE_Activity = UE_Activity_active_val;
			break;
		case ActivityInformation_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_ActivityInformation_ExtIEs( &obj_BearerContextInactivityNotification->activityInformation->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_BearerContextInactivityNotification->activityInformation_isset = 1;



	__si_e1ap_send_BearerContextInactivityNotification( obj_BearerContextInactivityNotification, node);
	__si_e1ap_memfree_pdu_BearerContextInactivityNotification( obj_BearerContextInactivityNotification);
}

void __si_e1ap__Send_DLDataNotification_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_DLDataNotification * obj_DLDataNotification = (SI_E1AP_DT_PDU_DLDataNotification*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DLDataNotification));
	memset( obj_DLDataNotification, 0, sizeof( SI_E1AP_DT_PDU_DLDataNotification));

	// GNB-CU-CP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_DLDataNotification->gNBCUCPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_DLDataNotification->gNBCUCPUEE1APID_isset = 1;


	// GNB-CU-UP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_DLDataNotification->gNBCUUPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_DLDataNotification->gNBCUUPUEE1APID_isset = 1;


	// PPI , PRESENCE = optional  INTEGER , MIN=0, MAX=7
	obj_DLDataNotification->pPI = __getTestINTEGER( 0, 7);
	obj_DLDataNotification->pPI_isset = 1;


	// PDU-Session-To-Notify-List , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__PDU_Session_To_Notify_List( &obj_DLDataNotification->pDUSessionToNotifyList);
	obj_DLDataNotification->pDUSessionToNotifyList_isset = 1;


	// MT-SDT-Information , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__MT_SDT_Information( &obj_DLDataNotification->mTSDTInformation);
	obj_DLDataNotification->mTSDTInformation_isset = 1;


	// SDT-data-size-threshold-Crossed , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_DLDataNotification->sDTdatasizethresholdCrossed = SDT_data_size_threshold_Crossed_true_val;
	obj_DLDataNotification->sDTdatasizethresholdCrossed_isset = 1;



	__si_e1ap_send_DLDataNotification( obj_DLDataNotification, node);
	__si_e1ap_memfree_pdu_DLDataNotification( obj_DLDataNotification);
}

void __si_e1ap__Send_ULDataNotification_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_ULDataNotification * obj_ULDataNotification = (SI_E1AP_DT_PDU_ULDataNotification*) __si_allocM( sizeof(SI_E1AP_DT_PDU_ULDataNotification));
	memset( obj_ULDataNotification, 0, sizeof( SI_E1AP_DT_PDU_ULDataNotification));

	// GNB-CU-CP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_ULDataNotification->gNBCUCPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_ULDataNotification->gNBCUCPUEE1APID_isset = 1;


	// GNB-CU-UP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_ULDataNotification->gNBCUUPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_ULDataNotification->gNBCUUPUEE1APID_isset = 1;


	// PDU-Session-To-Notify-List , PRESENCE = mandatory   SEQUENCE_OF
	__si_e1ap__set_testdata__PDU_Session_To_Notify_List( &obj_ULDataNotification->pDUSessionToNotifyList);
	obj_ULDataNotification->pDUSessionToNotifyList_isset = 1;



	__si_e1ap_send_ULDataNotification( obj_ULDataNotification, node);
	__si_e1ap_memfree_pdu_ULDataNotification( obj_ULDataNotification);
}

void __si_e1ap__Send_DataUsageReport_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_DataUsageReport * obj_DataUsageReport = (SI_E1AP_DT_PDU_DataUsageReport*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DataUsageReport));
	memset( obj_DataUsageReport, 0, sizeof( SI_E1AP_DT_PDU_DataUsageReport));

	// GNB-CU-CP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_DataUsageReport->gNBCUCPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_DataUsageReport->gNBCUCPUEE1APID_isset = 1;


	// GNB-CU-UP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_DataUsageReport->gNBCUUPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_DataUsageReport->gNBCUUPUEE1APID_isset = 1;


	// Data-Usage-Report-List , PRESENCE = mandatory   SEQUENCE_OF
	__si_e1ap__set_testdata__Data_Usage_Report_List( &obj_DataUsageReport->dataUsageReportList);
	obj_DataUsageReport->dataUsageReportList_isset = 1;



	__si_e1ap_send_DataUsageReport( obj_DataUsageReport, node);
	__si_e1ap_memfree_pdu_DataUsageReport( obj_DataUsageReport);
}

void __si_e1ap__Send_GNB_CU_UP_CounterCheckRequest_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_GNB_CU_UP_CounterCheckRequest * obj_GNB_CU_UP_CounterCheckRequest = (SI_E1AP_DT_PDU_GNB_CU_UP_CounterCheckRequest*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GNB_CU_UP_CounterCheckRequest));
	memset( obj_GNB_CU_UP_CounterCheckRequest, 0, sizeof( SI_E1AP_DT_PDU_GNB_CU_UP_CounterCheckRequest));

	// GNB-CU-CP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_GNB_CU_UP_CounterCheckRequest->gNBCUCPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_GNB_CU_UP_CounterCheckRequest->gNBCUCPUEE1APID_isset = 1;


	// GNB-CU-UP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_GNB_CU_UP_CounterCheckRequest->gNBCUUPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_GNB_CU_UP_CounterCheckRequest->gNBCUUPUEE1APID_isset = 1;


	// System-GNB-CU-UP-CounterCheckRequest  , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__System_GNB_CU_UP_CounterCheckRequest( &obj_GNB_CU_UP_CounterCheckRequest->systemGNBCUUPCounterCheckRequest);
	obj_GNB_CU_UP_CounterCheckRequest->systemGNBCUUPCounterCheckRequest->SelectedChoice = System_GNB_CU_UP_CounterCheckRequest_e_UTRAN_GNB_CU_UP_CounterCheckRequest_val;

	switch( obj_GNB_CU_UP_CounterCheckRequest->systemGNBCUUPCounterCheckRequest->SelectedChoice)
	{
		case System_GNB_CU_UP_CounterCheckRequest_e_UTRAN_GNB_CU_UP_CounterCheckRequest_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_EUTRAN_GNB_CU_UP_CounterCheckRequest( &obj_GNB_CU_UP_CounterCheckRequest->systemGNBCUUPCounterCheckRequest->u.e_UTRAN_GNB_CU_UP_CounterCheckRequest);   // L:11825
			}
			break;
		case System_GNB_CU_UP_CounterCheckRequest_nG_RAN_GNB_CU_UP_CounterCheckRequest_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_NG_RAN_GNB_CU_UP_CounterCheckRequest( &obj_GNB_CU_UP_CounterCheckRequest->systemGNBCUUPCounterCheckRequest->u.nG_RAN_GNB_CU_UP_CounterCheckRequest);   // L:11825
			}
			break;
		case System_GNB_CU_UP_CounterCheckRequest_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_System_GNB_CU_UP_CounterCheckRequest_ExtIEs( &obj_GNB_CU_UP_CounterCheckRequest->systemGNBCUUPCounterCheckRequest->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_GNB_CU_UP_CounterCheckRequest->systemGNBCUUPCounterCheckRequest_isset = 1;



	__si_e1ap_send_GNB_CU_UP_CounterCheckRequest( obj_GNB_CU_UP_CounterCheckRequest, node);
	__si_e1ap_memfree_pdu_GNB_CU_UP_CounterCheckRequest( obj_GNB_CU_UP_CounterCheckRequest);
}

void __si_e1ap__Send_GNB_CU_UP_StatusIndication_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_GNB_CU_UP_StatusIndication * obj_GNB_CU_UP_StatusIndication = (SI_E1AP_DT_PDU_GNB_CU_UP_StatusIndication*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GNB_CU_UP_StatusIndication));
	memset( obj_GNB_CU_UP_StatusIndication, 0, sizeof( SI_E1AP_DT_PDU_GNB_CU_UP_StatusIndication));

	// TransactionID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=255
	obj_GNB_CU_UP_StatusIndication->transactionID = __getTestINTEGER( 0, 255);
	obj_GNB_CU_UP_StatusIndication->transactionID_isset = 1;


	// GNB-CU-UP-OverloadInformation , PRESENCE = mandatory   ENUMERATED, PRESENCE = mandatory
	obj_GNB_CU_UP_StatusIndication->gNBCUUPOverloadInformation = GNB_CU_UP_OverloadInformation_overloaded_val;
	obj_GNB_CU_UP_StatusIndication->gNBCUUPOverloadInformation_isset = 1;



	__si_e1ap_send_GNB_CU_UP_StatusIndication( obj_GNB_CU_UP_StatusIndication, node);
	__si_e1ap_memfree_pdu_GNB_CU_UP_StatusIndication( obj_GNB_CU_UP_StatusIndication);
}

void __si_e1ap__Send_PrivateMessage_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_PrivateMessage * obj_PrivateMessage = (SI_E1AP_DT_PDU_PrivateMessage*) __si_allocM( sizeof(SI_E1AP_DT_PDU_PrivateMessage));
	memset( obj_PrivateMessage, 0, sizeof( SI_E1AP_DT_PDU_PrivateMessage));


	__si_e1ap_send_PrivateMessage( obj_PrivateMessage, node);
	__si_e1ap_memfree_pdu_PrivateMessage( obj_PrivateMessage);
}

void __si_e1ap__Send_GNB_CU_CPMeasurementResultsInformation_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_GNB_CU_CPMeasurementResultsInformation * obj_GNB_CU_CPMeasurementResultsInformation = (SI_E1AP_DT_PDU_GNB_CU_CPMeasurementResultsInformation*) __si_allocM( sizeof(SI_E1AP_DT_PDU_GNB_CU_CPMeasurementResultsInformation));
	memset( obj_GNB_CU_CPMeasurementResultsInformation, 0, sizeof( SI_E1AP_DT_PDU_GNB_CU_CPMeasurementResultsInformation));

	// GNB-CU-CP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_GNB_CU_CPMeasurementResultsInformation->gNBCUCPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_GNB_CU_CPMeasurementResultsInformation->gNBCUCPUEE1APID_isset = 1;


	// GNB-CU-UP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_GNB_CU_CPMeasurementResultsInformation->gNBCUUPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_GNB_CU_CPMeasurementResultsInformation->gNBCUUPUEE1APID_isset = 1;


	// DRB-Measurement-Results-Information-List , PRESENCE = mandatory   SEQUENCE_OF
	__si_e1ap__set_testdata__DRB_Measurement_Results_Information_List( &obj_GNB_CU_CPMeasurementResultsInformation->dRBMeasurementResultsInformationList);
	obj_GNB_CU_CPMeasurementResultsInformation->dRBMeasurementResultsInformationList_isset = 1;



	__si_e1ap_send_GNB_CU_CPMeasurementResultsInformation( obj_GNB_CU_CPMeasurementResultsInformation, node);
	__si_e1ap_memfree_pdu_GNB_CU_CPMeasurementResultsInformation( obj_GNB_CU_CPMeasurementResultsInformation);
}

void __si_e1ap__Send_MRDC_DataUsageReport_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_MRDC_DataUsageReport * obj_MRDC_DataUsageReport = (SI_E1AP_DT_PDU_MRDC_DataUsageReport*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MRDC_DataUsageReport));
	memset( obj_MRDC_DataUsageReport, 0, sizeof( SI_E1AP_DT_PDU_MRDC_DataUsageReport));

	// GNB-CU-CP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_MRDC_DataUsageReport->gNBCUCPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_MRDC_DataUsageReport->gNBCUCPUEE1APID_isset = 1;


	// GNB-CU-UP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_MRDC_DataUsageReport->gNBCUUPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_MRDC_DataUsageReport->gNBCUUPUEE1APID_isset = 1;


	// PDU-Session-Resource-Data-Usage-List , PRESENCE = mandatory   SEQUENCE_OF
	__si_e1ap__set_testdata__PDU_Session_Resource_Data_Usage_List( &obj_MRDC_DataUsageReport->pDUSessionResourceDataUsageList);
	obj_MRDC_DataUsageReport->pDUSessionResourceDataUsageList_isset = 1;



	__si_e1ap_send_MRDC_DataUsageReport( obj_MRDC_DataUsageReport, node);
	__si_e1ap_memfree_pdu_MRDC_DataUsageReport( obj_MRDC_DataUsageReport);
}

void __si_e1ap__Send_DeactivateTrace_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_DeactivateTrace * obj_DeactivateTrace = (SI_E1AP_DT_PDU_DeactivateTrace*) __si_allocM( sizeof(SI_E1AP_DT_PDU_DeactivateTrace));
	memset( obj_DeactivateTrace, 0, sizeof( SI_E1AP_DT_PDU_DeactivateTrace));

	// GNB-CU-CP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_DeactivateTrace->gNBCUCPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_DeactivateTrace->gNBCUCPUEE1APID_isset = 1;


	// GNB-CU-UP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_DeactivateTrace->gNBCUUPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_DeactivateTrace->gNBCUUPUEE1APID_isset = 1;


	// TraceID    OCTETSTRING, PRESENCE = mandatory , MIN=8, MAX=8
	__si_e1ap_init_TraceID2( &obj_DeactivateTrace->traceID, "\x21\x15\x14\x18\x18\x11\x06\x02", 8);
	obj_DeactivateTrace->traceID_isset = 1;



	__si_e1ap_send_DeactivateTrace( obj_DeactivateTrace, node);
	__si_e1ap_memfree_pdu_DeactivateTrace( obj_DeactivateTrace);
}

void __si_e1ap__Send_TraceStart_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_TraceStart * obj_TraceStart = (SI_E1AP_DT_PDU_TraceStart*) __si_allocM( sizeof(SI_E1AP_DT_PDU_TraceStart));
	memset( obj_TraceStart, 0, sizeof( SI_E1AP_DT_PDU_TraceStart));

	// GNB-CU-CP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_TraceStart->gNBCUCPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_TraceStart->gNBCUCPUEE1APID_isset = 1;


	// GNB-CU-UP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_TraceStart->gNBCUUPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_TraceStart->gNBCUUPUEE1APID_isset = 1;


	// TraceActivation , PRESENCE = mandatory   SEQUENCE
	__si_e1ap__set_testdata__TraceActivation( &obj_TraceStart->traceActivation);
	obj_TraceStart->traceActivation_isset = 1;



	__si_e1ap_send_TraceStart( obj_TraceStart, node);
	__si_e1ap_memfree_pdu_TraceStart( obj_TraceStart);
}

void __si_e1ap__Send_ResourceStatusRequest_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_ResourceStatusRequest * obj_ResourceStatusRequest = (SI_E1AP_DT_PDU_ResourceStatusRequest*) __si_allocM( sizeof(SI_E1AP_DT_PDU_ResourceStatusRequest));
	memset( obj_ResourceStatusRequest, 0, sizeof( SI_E1AP_DT_PDU_ResourceStatusRequest));

	// TransactionID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=255
	obj_ResourceStatusRequest->transactionID = __getTestINTEGER( 0, 255);
	obj_ResourceStatusRequest->transactionID_isset = 1;


	// RegistrationRequest , PRESENCE = mandatory   ENUMERATED, PRESENCE = mandatory
	obj_ResourceStatusRequest->registrationRequest = RegistrationRequest_start_val;
	obj_ResourceStatusRequest->registrationRequest_isset = 1;


	// ReportCharacteristics , PRESENCE = conditional   BITSTRING , MIN=36, MAX=36
	__si_e1ap_init_ReportCharacteristics2( &obj_ResourceStatusRequest->reportCharacteristics, "63332", 5, 36);
	obj_ResourceStatusRequest->reportCharacteristics->bitslen = 36;
	obj_ResourceStatusRequest->reportCharacteristics_isset = 1;


	// ReportingPeriodicity , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_ResourceStatusRequest->reportingPeriodicity = ReportingPeriodicity_ms500_val;
	obj_ResourceStatusRequest->reportingPeriodicity_isset = 1;



	__si_e1ap_send_ResourceStatusRequest( obj_ResourceStatusRequest, node);
	__si_e1ap_memfree_pdu_ResourceStatusRequest( obj_ResourceStatusRequest);
}

void __si_e1ap__Send_ResourceStatusResponse_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_ResourceStatusResponse * obj_ResourceStatusResponse = (SI_E1AP_DT_PDU_ResourceStatusResponse*) __si_allocM( sizeof(SI_E1AP_DT_PDU_ResourceStatusResponse));
	memset( obj_ResourceStatusResponse, 0, sizeof( SI_E1AP_DT_PDU_ResourceStatusResponse));

	// TransactionID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=255
	obj_ResourceStatusResponse->transactionID = __getTestINTEGER( 0, 255);
	obj_ResourceStatusResponse->transactionID_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_ResourceStatusResponse->criticalityDiagnostics);
	obj_ResourceStatusResponse->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_ResourceStatusResponse( obj_ResourceStatusResponse, node);
	__si_e1ap_memfree_pdu_ResourceStatusResponse( obj_ResourceStatusResponse);
}

void __si_e1ap__Send_ResourceStatusFailure_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_ResourceStatusFailure * obj_ResourceStatusFailure = (SI_E1AP_DT_PDU_ResourceStatusFailure*) __si_allocM( sizeof(SI_E1AP_DT_PDU_ResourceStatusFailure));
	memset( obj_ResourceStatusFailure, 0, sizeof( SI_E1AP_DT_PDU_ResourceStatusFailure));

	// TransactionID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=255
	obj_ResourceStatusFailure->transactionID = __getTestINTEGER( 0, 255);
	obj_ResourceStatusFailure->transactionID_isset = 1;


	// Cause , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__Cause( &obj_ResourceStatusFailure->cause);
	obj_ResourceStatusFailure->cause->SelectedChoice = Cause_radioNetwork_val;

	switch( obj_ResourceStatusFailure->cause->SelectedChoice)
	{
		case Cause_radioNetwork_val:
			obj_ResourceStatusFailure->cause->u.radioNetwork = CauseRadioNetwork_unspecified_val;
			break;
		case Cause_transport_val:
			obj_ResourceStatusFailure->cause->u.transport = CauseTransport_unspecified_val;
			break;
		case Cause_protocol_val:
			obj_ResourceStatusFailure->cause->u.protocol = CauseProtocol_transfer_syntax_error_val;
			break;
		case Cause_misc_val:
			obj_ResourceStatusFailure->cause->u.misc = CauseMisc_control_processing_overload_val;
			break;
		case Cause_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_Cause_ExtIEs( &obj_ResourceStatusFailure->cause->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_ResourceStatusFailure->cause_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_ResourceStatusFailure->criticalityDiagnostics);
	obj_ResourceStatusFailure->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_ResourceStatusFailure( obj_ResourceStatusFailure, node);
	__si_e1ap_memfree_pdu_ResourceStatusFailure( obj_ResourceStatusFailure);
}

void __si_e1ap__Send_ResourceStatusUpdate_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_ResourceStatusUpdate * obj_ResourceStatusUpdate = (SI_E1AP_DT_PDU_ResourceStatusUpdate*) __si_allocM( sizeof(SI_E1AP_DT_PDU_ResourceStatusUpdate));
	memset( obj_ResourceStatusUpdate, 0, sizeof( SI_E1AP_DT_PDU_ResourceStatusUpdate));

	// TransactionID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=255
	obj_ResourceStatusUpdate->transactionID = __getTestINTEGER( 0, 255);
	obj_ResourceStatusUpdate->transactionID_isset = 1;


	// TNL-AvailableCapacityIndicator , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__TNL_AvailableCapacityIndicator( &obj_ResourceStatusUpdate->tNLAvailableCapacityIndicator);
	obj_ResourceStatusUpdate->tNLAvailableCapacityIndicator_isset = 1;


	// HW-CapacityIndicator , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__HW_CapacityIndicator( &obj_ResourceStatusUpdate->hWCapacityIndicator);
	obj_ResourceStatusUpdate->hWCapacityIndicator_isset = 1;



	__si_e1ap_send_ResourceStatusUpdate( obj_ResourceStatusUpdate, node);
	__si_e1ap_memfree_pdu_ResourceStatusUpdate( obj_ResourceStatusUpdate);
}

void __si_e1ap__Send_IAB_UPTNLAddressUpdate_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_IAB_UPTNLAddressUpdate * obj_IAB_UPTNLAddressUpdate = (SI_E1AP_DT_PDU_IAB_UPTNLAddressUpdate*) __si_allocM( sizeof(SI_E1AP_DT_PDU_IAB_UPTNLAddressUpdate));
	memset( obj_IAB_UPTNLAddressUpdate, 0, sizeof( SI_E1AP_DT_PDU_IAB_UPTNLAddressUpdate));

	// TransactionID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=255
	obj_IAB_UPTNLAddressUpdate->transactionID = __getTestINTEGER( 0, 255);
	obj_IAB_UPTNLAddressUpdate->transactionID_isset = 1;


	// DLUPTNLAddressToUpdateList , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__DLUPTNLAddressToUpdateList( &obj_IAB_UPTNLAddressUpdate->dLUPTNLAddressToUpdateList);
	obj_IAB_UPTNLAddressUpdate->dLUPTNLAddressToUpdateList_isset = 1;



	__si_e1ap_send_IAB_UPTNLAddressUpdate( obj_IAB_UPTNLAddressUpdate, node);
	__si_e1ap_memfree_pdu_IAB_UPTNLAddressUpdate( obj_IAB_UPTNLAddressUpdate);
}

void __si_e1ap__Send_IAB_UPTNLAddressUpdateAcknowledge_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_IAB_UPTNLAddressUpdateAcknowledge * obj_IAB_UPTNLAddressUpdateAcknowledge = (SI_E1AP_DT_PDU_IAB_UPTNLAddressUpdateAcknowledge*) __si_allocM( sizeof(SI_E1AP_DT_PDU_IAB_UPTNLAddressUpdateAcknowledge));
	memset( obj_IAB_UPTNLAddressUpdateAcknowledge, 0, sizeof( SI_E1AP_DT_PDU_IAB_UPTNLAddressUpdateAcknowledge));

	// TransactionID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=255
	obj_IAB_UPTNLAddressUpdateAcknowledge->transactionID = __getTestINTEGER( 0, 255);
	obj_IAB_UPTNLAddressUpdateAcknowledge->transactionID_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_IAB_UPTNLAddressUpdateAcknowledge->criticalityDiagnostics);
	obj_IAB_UPTNLAddressUpdateAcknowledge->criticalityDiagnostics_isset = 1;


	// ULUPTNLAddressToUpdateList , PRESENCE = optional   SEQUENCE_OF
	__si_e1ap__set_testdata__ULUPTNLAddressToUpdateList( &obj_IAB_UPTNLAddressUpdateAcknowledge->uLUPTNLAddressToUpdateList);
	obj_IAB_UPTNLAddressUpdateAcknowledge->uLUPTNLAddressToUpdateList_isset = 1;



	__si_e1ap_send_IAB_UPTNLAddressUpdateAcknowledge( obj_IAB_UPTNLAddressUpdateAcknowledge, node);
	__si_e1ap_memfree_pdu_IAB_UPTNLAddressUpdateAcknowledge( obj_IAB_UPTNLAddressUpdateAcknowledge);
}

void __si_e1ap__Send_IAB_UPTNLAddressUpdateFailure_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_IAB_UPTNLAddressUpdateFailure * obj_IAB_UPTNLAddressUpdateFailure = (SI_E1AP_DT_PDU_IAB_UPTNLAddressUpdateFailure*) __si_allocM( sizeof(SI_E1AP_DT_PDU_IAB_UPTNLAddressUpdateFailure));
	memset( obj_IAB_UPTNLAddressUpdateFailure, 0, sizeof( SI_E1AP_DT_PDU_IAB_UPTNLAddressUpdateFailure));

	// TransactionID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=255
	obj_IAB_UPTNLAddressUpdateFailure->transactionID = __getTestINTEGER( 0, 255);
	obj_IAB_UPTNLAddressUpdateFailure->transactionID_isset = 1;


	// Cause , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__Cause( &obj_IAB_UPTNLAddressUpdateFailure->cause);
	obj_IAB_UPTNLAddressUpdateFailure->cause->SelectedChoice = Cause_radioNetwork_val;

	switch( obj_IAB_UPTNLAddressUpdateFailure->cause->SelectedChoice)
	{
		case Cause_radioNetwork_val:
			obj_IAB_UPTNLAddressUpdateFailure->cause->u.radioNetwork = CauseRadioNetwork_unspecified_val;
			break;
		case Cause_transport_val:
			obj_IAB_UPTNLAddressUpdateFailure->cause->u.transport = CauseTransport_unspecified_val;
			break;
		case Cause_protocol_val:
			obj_IAB_UPTNLAddressUpdateFailure->cause->u.protocol = CauseProtocol_transfer_syntax_error_val;
			break;
		case Cause_misc_val:
			obj_IAB_UPTNLAddressUpdateFailure->cause->u.misc = CauseMisc_control_processing_overload_val;
			break;
		case Cause_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_Cause_ExtIEs( &obj_IAB_UPTNLAddressUpdateFailure->cause->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_IAB_UPTNLAddressUpdateFailure->cause_isset = 1;


	// TimeToWait , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_IAB_UPTNLAddressUpdateFailure->timeToWait = TimeToWait_v1s_val;
	obj_IAB_UPTNLAddressUpdateFailure->timeToWait_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_IAB_UPTNLAddressUpdateFailure->criticalityDiagnostics);
	obj_IAB_UPTNLAddressUpdateFailure->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_IAB_UPTNLAddressUpdateFailure( obj_IAB_UPTNLAddressUpdateFailure, node);
	__si_e1ap_memfree_pdu_IAB_UPTNLAddressUpdateFailure( obj_IAB_UPTNLAddressUpdateFailure);
}

void __si_e1ap__Send_CellTrafficTrace_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_CellTrafficTrace * obj_CellTrafficTrace = (SI_E1AP_DT_PDU_CellTrafficTrace*) __si_allocM( sizeof(SI_E1AP_DT_PDU_CellTrafficTrace));
	memset( obj_CellTrafficTrace, 0, sizeof( SI_E1AP_DT_PDU_CellTrafficTrace));

	// GNB-CU-CP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_CellTrafficTrace->gNBCUCPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_CellTrafficTrace->gNBCUCPUEE1APID_isset = 1;


	// GNB-CU-UP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_CellTrafficTrace->gNBCUUPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_CellTrafficTrace->gNBCUUPUEE1APID_isset = 1;


	// TraceID    OCTETSTRING, PRESENCE = mandatory , MIN=8, MAX=8
	__si_e1ap_init_TraceID2( &obj_CellTrafficTrace->traceID, "\x12\x21\x12\x04\x05\x04\x11\x14", 8);
	obj_CellTrafficTrace->traceID_isset = 1;


	// TransportLayerAddress  , PRESENCE = mandatory   BITSTRING , MIN=1, MAX=160
	__si_e1ap_init_TransportLayerAddress2( &obj_CellTrafficTrace->traceCollectionEntityIPAddress, "9", 1, 1);
	obj_CellTrafficTrace->traceCollectionEntityIPAddress->bitslen = 1;
	obj_CellTrafficTrace->traceCollectionEntityIPAddress_isset = 1;


	// PrivacyIndicator , PRESENCE = optional   ENUMERATED, PRESENCE = optional
	obj_CellTrafficTrace->privacyIndicator = PrivacyIndicator_immediate_MDT_val;
	obj_CellTrafficTrace->privacyIndicator_isset = 1;


	// URIaddress    PrintableString, PRESENCE = optional , MIN=0, MAX=0
	__si_e1ap_init_URIaddress2( &obj_CellTrafficTrace->uRIaddress, "aeiou", 5);
	obj_CellTrafficTrace->uRIaddress_isset = 1;



	__si_e1ap_send_CellTrafficTrace( obj_CellTrafficTrace, node);
	__si_e1ap_memfree_pdu_CellTrafficTrace( obj_CellTrafficTrace);
}

void __si_e1ap__Send_EarlyForwardingSNTransfer_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_EarlyForwardingSNTransfer * obj_EarlyForwardingSNTransfer = (SI_E1AP_DT_PDU_EarlyForwardingSNTransfer*) __si_allocM( sizeof(SI_E1AP_DT_PDU_EarlyForwardingSNTransfer));
	memset( obj_EarlyForwardingSNTransfer, 0, sizeof( SI_E1AP_DT_PDU_EarlyForwardingSNTransfer));

	// GNB-CU-CP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_EarlyForwardingSNTransfer->gNBCUCPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_EarlyForwardingSNTransfer->gNBCUCPUEE1APID_isset = 1;


	// GNB-CU-UP-UE-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=4294967295
	obj_EarlyForwardingSNTransfer->gNBCUUPUEE1APID = __getTestINTEGER( 0, 4294967295);
	obj_EarlyForwardingSNTransfer->gNBCUUPUEE1APID_isset = 1;


	// DRBs-Subject-To-Early-Forwarding-List , PRESENCE = mandatory   SEQUENCE_OF
	__si_e1ap__set_testdata__DRBs_Subject_To_Early_Forwarding_List( &obj_EarlyForwardingSNTransfer->dRBsSubjectToEarlyForwardingList);
	obj_EarlyForwardingSNTransfer->dRBsSubjectToEarlyForwardingList_isset = 1;



	__si_e1ap_send_EarlyForwardingSNTransfer( obj_EarlyForwardingSNTransfer, node);
	__si_e1ap_memfree_pdu_EarlyForwardingSNTransfer( obj_EarlyForwardingSNTransfer);
}

void __si_e1ap__Send_IABPSKNotification_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_IABPSKNotification * obj_IABPSKNotification = (SI_E1AP_DT_PDU_IABPSKNotification*) __si_allocM( sizeof(SI_E1AP_DT_PDU_IABPSKNotification));
	memset( obj_IABPSKNotification, 0, sizeof( SI_E1AP_DT_PDU_IABPSKNotification));

	// TransactionID    , PRESENCE = mandatory  INTEGER , MIN=0, MAX=255
	obj_IABPSKNotification->transactionID = __getTestINTEGER( 0, 255);
	obj_IABPSKNotification->transactionID_isset = 1;


	// IAB-Donor-CU-UPPSKInfo , PRESENCE = mandatory   SEQUENCE_OF
	__si_e1ap__set_testdata__IAB_Donor_CU_UPPSKInfo( &obj_IABPSKNotification->iABDonorCUUPPSKInfo);
	obj_IABPSKNotification->iABDonorCUUPPSKInfo_isset = 1;



	__si_e1ap_send_IABPSKNotification( obj_IABPSKNotification, node);
	__si_e1ap_memfree_pdu_IABPSKNotification( obj_IABPSKNotification);
}

void __si_e1ap__Send_BCBearerContextSetupRequest_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_BCBearerContextSetupRequest * obj_BCBearerContextSetupRequest = (SI_E1AP_DT_PDU_BCBearerContextSetupRequest*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCBearerContextSetupRequest));
	memset( obj_BCBearerContextSetupRequest, 0, sizeof( SI_E1AP_DT_PDU_BCBearerContextSetupRequest));

	// GNB-CU-CP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=16777215
	obj_BCBearerContextSetupRequest->gNBCUCPMBSE1APID = __getTestINTEGER( 0, 16777215);
	obj_BCBearerContextSetupRequest->gNBCUCPMBSE1APID_isset = 1;


	// GlobalMBSSessionID , PRESENCE = mandatory   SEQUENCE
	__si_e1ap__set_testdata__GlobalMBSSessionID( &obj_BCBearerContextSetupRequest->globalMBSSessionID);
	obj_BCBearerContextSetupRequest->globalMBSSessionID_isset = 1;


	// BCBearerContextToSetup , PRESENCE = mandatory   SEQUENCE
	__si_e1ap__set_testdata__BCBearerContextToSetup( &obj_BCBearerContextSetupRequest->bCBearerContextToSetup);
	obj_BCBearerContextSetupRequest->bCBearerContextToSetup_isset = 1;


	// AssociatedSessionID    OCTETSTRING, PRESENCE = optional , MIN=0, MAX=0
	__si_e1ap_init_AssociatedSessionID2( &obj_BCBearerContextSetupRequest->associatedSessionID, "\x07\x18\x08\x07\x23", 5);
	obj_BCBearerContextSetupRequest->associatedSessionID_isset = 1;


	// MBS-ServiceArea , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__MBS_ServiceArea( &obj_BCBearerContextSetupRequest->mBSServiceArea);
	obj_BCBearerContextSetupRequest->mBSServiceArea_isset = 1;



	__si_e1ap_send_BCBearerContextSetupRequest( obj_BCBearerContextSetupRequest, node);
	__si_e1ap_memfree_pdu_BCBearerContextSetupRequest( obj_BCBearerContextSetupRequest);
}

void __si_e1ap__Send_BCBearerContextSetupResponse_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_BCBearerContextSetupResponse * obj_BCBearerContextSetupResponse = (SI_E1AP_DT_PDU_BCBearerContextSetupResponse*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCBearerContextSetupResponse));
	memset( obj_BCBearerContextSetupResponse, 0, sizeof( SI_E1AP_DT_PDU_BCBearerContextSetupResponse));

	// GNB-CU-CP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=16777215
	obj_BCBearerContextSetupResponse->gNBCUCPMBSE1APID = __getTestINTEGER( 0, 16777215);
	obj_BCBearerContextSetupResponse->gNBCUCPMBSE1APID_isset = 1;


	// GNB-CU-UP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=65535
	obj_BCBearerContextSetupResponse->gNBCUUPMBSE1APID = __getTestINTEGER( 0, 65535);
	obj_BCBearerContextSetupResponse->gNBCUUPMBSE1APID_isset = 1;


	// BCBearerContextToSetupResponse , PRESENCE = mandatory   SEQUENCE
	__si_e1ap__set_testdata__BCBearerContextToSetupResponse( &obj_BCBearerContextSetupResponse->bCBearerContextToSetupResponse);
	obj_BCBearerContextSetupResponse->bCBearerContextToSetupResponse_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_BCBearerContextSetupResponse->criticalityDiagnostics);
	obj_BCBearerContextSetupResponse->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_BCBearerContextSetupResponse( obj_BCBearerContextSetupResponse, node);
	__si_e1ap_memfree_pdu_BCBearerContextSetupResponse( obj_BCBearerContextSetupResponse);
}

void __si_e1ap__Send_BCBearerContextSetupFailure_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_BCBearerContextSetupFailure * obj_BCBearerContextSetupFailure = (SI_E1AP_DT_PDU_BCBearerContextSetupFailure*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCBearerContextSetupFailure));
	memset( obj_BCBearerContextSetupFailure, 0, sizeof( SI_E1AP_DT_PDU_BCBearerContextSetupFailure));

	// GNB-CU-CP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=16777215
	obj_BCBearerContextSetupFailure->gNBCUCPMBSE1APID = __getTestINTEGER( 0, 16777215);
	obj_BCBearerContextSetupFailure->gNBCUCPMBSE1APID_isset = 1;


	// GNB-CU-UP-MBS-E1AP-ID  , PRESENCE = optional  INTEGER , MIN=0, MAX=65535
	obj_BCBearerContextSetupFailure->gNBCUUPMBSE1APID = __getTestINTEGER( 0, 65535);
	obj_BCBearerContextSetupFailure->gNBCUUPMBSE1APID_isset = 1;


	// Cause , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__Cause( &obj_BCBearerContextSetupFailure->cause);
	obj_BCBearerContextSetupFailure->cause->SelectedChoice = Cause_radioNetwork_val;

	switch( obj_BCBearerContextSetupFailure->cause->SelectedChoice)
	{
		case Cause_radioNetwork_val:
			obj_BCBearerContextSetupFailure->cause->u.radioNetwork = CauseRadioNetwork_unspecified_val;
			break;
		case Cause_transport_val:
			obj_BCBearerContextSetupFailure->cause->u.transport = CauseTransport_unspecified_val;
			break;
		case Cause_protocol_val:
			obj_BCBearerContextSetupFailure->cause->u.protocol = CauseProtocol_transfer_syntax_error_val;
			break;
		case Cause_misc_val:
			obj_BCBearerContextSetupFailure->cause->u.misc = CauseMisc_control_processing_overload_val;
			break;
		case Cause_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_Cause_ExtIEs( &obj_BCBearerContextSetupFailure->cause->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_BCBearerContextSetupFailure->cause_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_BCBearerContextSetupFailure->criticalityDiagnostics);
	obj_BCBearerContextSetupFailure->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_BCBearerContextSetupFailure( obj_BCBearerContextSetupFailure, node);
	__si_e1ap_memfree_pdu_BCBearerContextSetupFailure( obj_BCBearerContextSetupFailure);
}

void __si_e1ap__Send_BCBearerContextModificationRequest_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_BCBearerContextModificationRequest * obj_BCBearerContextModificationRequest = (SI_E1AP_DT_PDU_BCBearerContextModificationRequest*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCBearerContextModificationRequest));
	memset( obj_BCBearerContextModificationRequest, 0, sizeof( SI_E1AP_DT_PDU_BCBearerContextModificationRequest));

	// GNB-CU-CP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=16777215
	obj_BCBearerContextModificationRequest->gNBCUCPMBSE1APID = __getTestINTEGER( 0, 16777215);
	obj_BCBearerContextModificationRequest->gNBCUCPMBSE1APID_isset = 1;


	// GNB-CU-UP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=65535
	obj_BCBearerContextModificationRequest->gNBCUUPMBSE1APID = __getTestINTEGER( 0, 65535);
	obj_BCBearerContextModificationRequest->gNBCUUPMBSE1APID_isset = 1;


	// BCBearerContextToModify , PRESENCE = mandatory   SEQUENCE
	__si_e1ap__set_testdata__BCBearerContextToModify( &obj_BCBearerContextModificationRequest->bCBearerContextToModify);
	obj_BCBearerContextModificationRequest->bCBearerContextToModify_isset = 1;



	__si_e1ap_send_BCBearerContextModificationRequest( obj_BCBearerContextModificationRequest, node);
	__si_e1ap_memfree_pdu_BCBearerContextModificationRequest( obj_BCBearerContextModificationRequest);
}

void __si_e1ap__Send_BCBearerContextModificationResponse_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_BCBearerContextModificationResponse * obj_BCBearerContextModificationResponse = (SI_E1AP_DT_PDU_BCBearerContextModificationResponse*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCBearerContextModificationResponse));
	memset( obj_BCBearerContextModificationResponse, 0, sizeof( SI_E1AP_DT_PDU_BCBearerContextModificationResponse));

	// GNB-CU-CP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=16777215
	obj_BCBearerContextModificationResponse->gNBCUCPMBSE1APID = __getTestINTEGER( 0, 16777215);
	obj_BCBearerContextModificationResponse->gNBCUCPMBSE1APID_isset = 1;


	// GNB-CU-UP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=65535
	obj_BCBearerContextModificationResponse->gNBCUUPMBSE1APID = __getTestINTEGER( 0, 65535);
	obj_BCBearerContextModificationResponse->gNBCUUPMBSE1APID_isset = 1;


	// BCBearerContextToModifyResponse , PRESENCE = mandatory   SEQUENCE
	__si_e1ap__set_testdata__BCBearerContextToModifyResponse( &obj_BCBearerContextModificationResponse->bCBearerContextToModifyResponse);
	obj_BCBearerContextModificationResponse->bCBearerContextToModifyResponse_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_BCBearerContextModificationResponse->criticalityDiagnostics);
	obj_BCBearerContextModificationResponse->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_BCBearerContextModificationResponse( obj_BCBearerContextModificationResponse, node);
	__si_e1ap_memfree_pdu_BCBearerContextModificationResponse( obj_BCBearerContextModificationResponse);
}

void __si_e1ap__Send_BCBearerContextModificationFailure_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_BCBearerContextModificationFailure * obj_BCBearerContextModificationFailure = (SI_E1AP_DT_PDU_BCBearerContextModificationFailure*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCBearerContextModificationFailure));
	memset( obj_BCBearerContextModificationFailure, 0, sizeof( SI_E1AP_DT_PDU_BCBearerContextModificationFailure));

	// GNB-CU-CP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=16777215
	obj_BCBearerContextModificationFailure->gNBCUCPMBSE1APID = __getTestINTEGER( 0, 16777215);
	obj_BCBearerContextModificationFailure->gNBCUCPMBSE1APID_isset = 1;


	// GNB-CU-UP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=65535
	obj_BCBearerContextModificationFailure->gNBCUUPMBSE1APID = __getTestINTEGER( 0, 65535);
	obj_BCBearerContextModificationFailure->gNBCUUPMBSE1APID_isset = 1;


	// Cause , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__Cause( &obj_BCBearerContextModificationFailure->cause);
	obj_BCBearerContextModificationFailure->cause->SelectedChoice = Cause_radioNetwork_val;

	switch( obj_BCBearerContextModificationFailure->cause->SelectedChoice)
	{
		case Cause_radioNetwork_val:
			obj_BCBearerContextModificationFailure->cause->u.radioNetwork = CauseRadioNetwork_unspecified_val;
			break;
		case Cause_transport_val:
			obj_BCBearerContextModificationFailure->cause->u.transport = CauseTransport_unspecified_val;
			break;
		case Cause_protocol_val:
			obj_BCBearerContextModificationFailure->cause->u.protocol = CauseProtocol_transfer_syntax_error_val;
			break;
		case Cause_misc_val:
			obj_BCBearerContextModificationFailure->cause->u.misc = CauseMisc_control_processing_overload_val;
			break;
		case Cause_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_Cause_ExtIEs( &obj_BCBearerContextModificationFailure->cause->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_BCBearerContextModificationFailure->cause_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_BCBearerContextModificationFailure->criticalityDiagnostics);
	obj_BCBearerContextModificationFailure->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_BCBearerContextModificationFailure( obj_BCBearerContextModificationFailure, node);
	__si_e1ap_memfree_pdu_BCBearerContextModificationFailure( obj_BCBearerContextModificationFailure);
}

void __si_e1ap__Send_BCBearerContextModificationRequired_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_BCBearerContextModificationRequired * obj_BCBearerContextModificationRequired = (SI_E1AP_DT_PDU_BCBearerContextModificationRequired*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCBearerContextModificationRequired));
	memset( obj_BCBearerContextModificationRequired, 0, sizeof( SI_E1AP_DT_PDU_BCBearerContextModificationRequired));

	// GNB-CU-CP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=16777215
	obj_BCBearerContextModificationRequired->gNBCUCPMBSE1APID = __getTestINTEGER( 0, 16777215);
	obj_BCBearerContextModificationRequired->gNBCUCPMBSE1APID_isset = 1;


	// GNB-CU-UP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=65535
	obj_BCBearerContextModificationRequired->gNBCUUPMBSE1APID = __getTestINTEGER( 0, 65535);
	obj_BCBearerContextModificationRequired->gNBCUUPMBSE1APID_isset = 1;


	// BCBearerContextToModifyRequired , PRESENCE = mandatory   SEQUENCE
	__si_e1ap__set_testdata__BCBearerContextToModifyRequired( &obj_BCBearerContextModificationRequired->bCBearerContextToModifyRequired);
	obj_BCBearerContextModificationRequired->bCBearerContextToModifyRequired_isset = 1;



	__si_e1ap_send_BCBearerContextModificationRequired( obj_BCBearerContextModificationRequired, node);
	__si_e1ap_memfree_pdu_BCBearerContextModificationRequired( obj_BCBearerContextModificationRequired);
}

void __si_e1ap__Send_BCBearerContextModificationConfirm_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_BCBearerContextModificationConfirm * obj_BCBearerContextModificationConfirm = (SI_E1AP_DT_PDU_BCBearerContextModificationConfirm*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCBearerContextModificationConfirm));
	memset( obj_BCBearerContextModificationConfirm, 0, sizeof( SI_E1AP_DT_PDU_BCBearerContextModificationConfirm));

	// GNB-CU-CP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=16777215
	obj_BCBearerContextModificationConfirm->gNBCUCPMBSE1APID = __getTestINTEGER( 0, 16777215);
	obj_BCBearerContextModificationConfirm->gNBCUCPMBSE1APID_isset = 1;


	// GNB-CU-UP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=65535
	obj_BCBearerContextModificationConfirm->gNBCUUPMBSE1APID = __getTestINTEGER( 0, 65535);
	obj_BCBearerContextModificationConfirm->gNBCUUPMBSE1APID_isset = 1;


	// BCBearerContextToModifyConfirm , PRESENCE = mandatory   SEQUENCE
	__si_e1ap__set_testdata__BCBearerContextToModifyConfirm( &obj_BCBearerContextModificationConfirm->bCBearerContextToModifyConfirm);
	obj_BCBearerContextModificationConfirm->bCBearerContextToModifyConfirm_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_BCBearerContextModificationConfirm->criticalityDiagnostics);
	obj_BCBearerContextModificationConfirm->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_BCBearerContextModificationConfirm( obj_BCBearerContextModificationConfirm, node);
	__si_e1ap_memfree_pdu_BCBearerContextModificationConfirm( obj_BCBearerContextModificationConfirm);
}

void __si_e1ap__Send_BCBearerContextReleaseCommand_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_BCBearerContextReleaseCommand * obj_BCBearerContextReleaseCommand = (SI_E1AP_DT_PDU_BCBearerContextReleaseCommand*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCBearerContextReleaseCommand));
	memset( obj_BCBearerContextReleaseCommand, 0, sizeof( SI_E1AP_DT_PDU_BCBearerContextReleaseCommand));

	// GNB-CU-CP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=16777215
	obj_BCBearerContextReleaseCommand->gNBCUCPMBSE1APID = __getTestINTEGER( 0, 16777215);
	obj_BCBearerContextReleaseCommand->gNBCUCPMBSE1APID_isset = 1;


	// GNB-CU-UP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=65535
	obj_BCBearerContextReleaseCommand->gNBCUUPMBSE1APID = __getTestINTEGER( 0, 65535);
	obj_BCBearerContextReleaseCommand->gNBCUUPMBSE1APID_isset = 1;


	// Cause , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__Cause( &obj_BCBearerContextReleaseCommand->cause);
	obj_BCBearerContextReleaseCommand->cause->SelectedChoice = Cause_radioNetwork_val;

	switch( obj_BCBearerContextReleaseCommand->cause->SelectedChoice)
	{
		case Cause_radioNetwork_val:
			obj_BCBearerContextReleaseCommand->cause->u.radioNetwork = CauseRadioNetwork_unspecified_val;
			break;
		case Cause_transport_val:
			obj_BCBearerContextReleaseCommand->cause->u.transport = CauseTransport_unspecified_val;
			break;
		case Cause_protocol_val:
			obj_BCBearerContextReleaseCommand->cause->u.protocol = CauseProtocol_transfer_syntax_error_val;
			break;
		case Cause_misc_val:
			obj_BCBearerContextReleaseCommand->cause->u.misc = CauseMisc_control_processing_overload_val;
			break;
		case Cause_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_Cause_ExtIEs( &obj_BCBearerContextReleaseCommand->cause->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_BCBearerContextReleaseCommand->cause_isset = 1;



	__si_e1ap_send_BCBearerContextReleaseCommand( obj_BCBearerContextReleaseCommand, node);
	__si_e1ap_memfree_pdu_BCBearerContextReleaseCommand( obj_BCBearerContextReleaseCommand);
}

void __si_e1ap__Send_BCBearerContextReleaseComplete_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_BCBearerContextReleaseComplete * obj_BCBearerContextReleaseComplete = (SI_E1AP_DT_PDU_BCBearerContextReleaseComplete*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCBearerContextReleaseComplete));
	memset( obj_BCBearerContextReleaseComplete, 0, sizeof( SI_E1AP_DT_PDU_BCBearerContextReleaseComplete));

	// GNB-CU-CP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=16777215
	obj_BCBearerContextReleaseComplete->gNBCUCPMBSE1APID = __getTestINTEGER( 0, 16777215);
	obj_BCBearerContextReleaseComplete->gNBCUCPMBSE1APID_isset = 1;


	// GNB-CU-UP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=65535
	obj_BCBearerContextReleaseComplete->gNBCUUPMBSE1APID = __getTestINTEGER( 0, 65535);
	obj_BCBearerContextReleaseComplete->gNBCUUPMBSE1APID_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_BCBearerContextReleaseComplete->criticalityDiagnostics);
	obj_BCBearerContextReleaseComplete->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_BCBearerContextReleaseComplete( obj_BCBearerContextReleaseComplete, node);
	__si_e1ap_memfree_pdu_BCBearerContextReleaseComplete( obj_BCBearerContextReleaseComplete);
}

void __si_e1ap__Send_BCBearerContextReleaseRequest_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_BCBearerContextReleaseRequest * obj_BCBearerContextReleaseRequest = (SI_E1AP_DT_PDU_BCBearerContextReleaseRequest*) __si_allocM( sizeof(SI_E1AP_DT_PDU_BCBearerContextReleaseRequest));
	memset( obj_BCBearerContextReleaseRequest, 0, sizeof( SI_E1AP_DT_PDU_BCBearerContextReleaseRequest));

	// GNB-CU-CP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=16777215
	obj_BCBearerContextReleaseRequest->gNBCUCPMBSE1APID = __getTestINTEGER( 0, 16777215);
	obj_BCBearerContextReleaseRequest->gNBCUCPMBSE1APID_isset = 1;


	// GNB-CU-UP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=65535
	obj_BCBearerContextReleaseRequest->gNBCUUPMBSE1APID = __getTestINTEGER( 0, 65535);
	obj_BCBearerContextReleaseRequest->gNBCUUPMBSE1APID_isset = 1;


	// Cause , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__Cause( &obj_BCBearerContextReleaseRequest->cause);
	obj_BCBearerContextReleaseRequest->cause->SelectedChoice = Cause_radioNetwork_val;

	switch( obj_BCBearerContextReleaseRequest->cause->SelectedChoice)
	{
		case Cause_radioNetwork_val:
			obj_BCBearerContextReleaseRequest->cause->u.radioNetwork = CauseRadioNetwork_unspecified_val;
			break;
		case Cause_transport_val:
			obj_BCBearerContextReleaseRequest->cause->u.transport = CauseTransport_unspecified_val;
			break;
		case Cause_protocol_val:
			obj_BCBearerContextReleaseRequest->cause->u.protocol = CauseProtocol_transfer_syntax_error_val;
			break;
		case Cause_misc_val:
			obj_BCBearerContextReleaseRequest->cause->u.misc = CauseMisc_control_processing_overload_val;
			break;
		case Cause_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_Cause_ExtIEs( &obj_BCBearerContextReleaseRequest->cause->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_BCBearerContextReleaseRequest->cause_isset = 1;



	__si_e1ap_send_BCBearerContextReleaseRequest( obj_BCBearerContextReleaseRequest, node);
	__si_e1ap_memfree_pdu_BCBearerContextReleaseRequest( obj_BCBearerContextReleaseRequest);
}

void __si_e1ap__Send_MCBearerContextSetupRequest_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_MCBearerContextSetupRequest * obj_MCBearerContextSetupRequest = (SI_E1AP_DT_PDU_MCBearerContextSetupRequest*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCBearerContextSetupRequest));
	memset( obj_MCBearerContextSetupRequest, 0, sizeof( SI_E1AP_DT_PDU_MCBearerContextSetupRequest));

	// GNB-CU-CP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=16777215
	obj_MCBearerContextSetupRequest->gNBCUCPMBSE1APID = __getTestINTEGER( 0, 16777215);
	obj_MCBearerContextSetupRequest->gNBCUCPMBSE1APID_isset = 1;


	// GlobalMBSSessionID , PRESENCE = mandatory   SEQUENCE
	__si_e1ap__set_testdata__GlobalMBSSessionID( &obj_MCBearerContextSetupRequest->globalMBSSessionID);
	obj_MCBearerContextSetupRequest->globalMBSSessionID_isset = 1;


	// MCBearerContextToSetup , PRESENCE = mandatory   SEQUENCE
	__si_e1ap__set_testdata__MCBearerContextToSetup( &obj_MCBearerContextSetupRequest->mCBearerContextToSetup);
	obj_MCBearerContextSetupRequest->mCBearerContextToSetup_isset = 1;



	__si_e1ap_send_MCBearerContextSetupRequest( obj_MCBearerContextSetupRequest, node);
	__si_e1ap_memfree_pdu_MCBearerContextSetupRequest( obj_MCBearerContextSetupRequest);
}

void __si_e1ap__Send_MCBearerContextSetupResponse_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_MCBearerContextSetupResponse * obj_MCBearerContextSetupResponse = (SI_E1AP_DT_PDU_MCBearerContextSetupResponse*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCBearerContextSetupResponse));
	memset( obj_MCBearerContextSetupResponse, 0, sizeof( SI_E1AP_DT_PDU_MCBearerContextSetupResponse));

	// GNB-CU-CP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=16777215
	obj_MCBearerContextSetupResponse->gNBCUCPMBSE1APID = __getTestINTEGER( 0, 16777215);
	obj_MCBearerContextSetupResponse->gNBCUCPMBSE1APID_isset = 1;


	// GNB-CU-UP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=65535
	obj_MCBearerContextSetupResponse->gNBCUUPMBSE1APID = __getTestINTEGER( 0, 65535);
	obj_MCBearerContextSetupResponse->gNBCUUPMBSE1APID_isset = 1;


	// MCBearerContextToSetupResponse , PRESENCE = mandatory   SEQUENCE
	__si_e1ap__set_testdata__MCBearerContextToSetupResponse( &obj_MCBearerContextSetupResponse->mCBearerContextToSetupResponse);
	obj_MCBearerContextSetupResponse->mCBearerContextToSetupResponse_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_MCBearerContextSetupResponse->criticalityDiagnostics);
	obj_MCBearerContextSetupResponse->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_MCBearerContextSetupResponse( obj_MCBearerContextSetupResponse, node);
	__si_e1ap_memfree_pdu_MCBearerContextSetupResponse( obj_MCBearerContextSetupResponse);
}

void __si_e1ap__Send_MCBearerContextSetupFailure_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_MCBearerContextSetupFailure * obj_MCBearerContextSetupFailure = (SI_E1AP_DT_PDU_MCBearerContextSetupFailure*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCBearerContextSetupFailure));
	memset( obj_MCBearerContextSetupFailure, 0, sizeof( SI_E1AP_DT_PDU_MCBearerContextSetupFailure));

	// GNB-CU-CP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=16777215
	obj_MCBearerContextSetupFailure->gNBCUCPMBSE1APID = __getTestINTEGER( 0, 16777215);
	obj_MCBearerContextSetupFailure->gNBCUCPMBSE1APID_isset = 1;


	// GNB-CU-UP-MBS-E1AP-ID  , PRESENCE = optional  INTEGER , MIN=0, MAX=65535
	obj_MCBearerContextSetupFailure->gNBCUUPMBSE1APID = __getTestINTEGER( 0, 65535);
	obj_MCBearerContextSetupFailure->gNBCUUPMBSE1APID_isset = 1;


	// Cause , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__Cause( &obj_MCBearerContextSetupFailure->cause);
	obj_MCBearerContextSetupFailure->cause->SelectedChoice = Cause_radioNetwork_val;

	switch( obj_MCBearerContextSetupFailure->cause->SelectedChoice)
	{
		case Cause_radioNetwork_val:
			obj_MCBearerContextSetupFailure->cause->u.radioNetwork = CauseRadioNetwork_unspecified_val;
			break;
		case Cause_transport_val:
			obj_MCBearerContextSetupFailure->cause->u.transport = CauseTransport_unspecified_val;
			break;
		case Cause_protocol_val:
			obj_MCBearerContextSetupFailure->cause->u.protocol = CauseProtocol_transfer_syntax_error_val;
			break;
		case Cause_misc_val:
			obj_MCBearerContextSetupFailure->cause->u.misc = CauseMisc_control_processing_overload_val;
			break;
		case Cause_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_Cause_ExtIEs( &obj_MCBearerContextSetupFailure->cause->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_MCBearerContextSetupFailure->cause_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_MCBearerContextSetupFailure->criticalityDiagnostics);
	obj_MCBearerContextSetupFailure->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_MCBearerContextSetupFailure( obj_MCBearerContextSetupFailure, node);
	__si_e1ap_memfree_pdu_MCBearerContextSetupFailure( obj_MCBearerContextSetupFailure);
}

void __si_e1ap__Send_MCBearerContextModificationRequest_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_MCBearerContextModificationRequest * obj_MCBearerContextModificationRequest = (SI_E1AP_DT_PDU_MCBearerContextModificationRequest*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCBearerContextModificationRequest));
	memset( obj_MCBearerContextModificationRequest, 0, sizeof( SI_E1AP_DT_PDU_MCBearerContextModificationRequest));

	// GNB-CU-CP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=16777215
	obj_MCBearerContextModificationRequest->gNBCUCPMBSE1APID = __getTestINTEGER( 0, 16777215);
	obj_MCBearerContextModificationRequest->gNBCUCPMBSE1APID_isset = 1;


	// GNB-CU-UP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=65535
	obj_MCBearerContextModificationRequest->gNBCUUPMBSE1APID = __getTestINTEGER( 0, 65535);
	obj_MCBearerContextModificationRequest->gNBCUUPMBSE1APID_isset = 1;


	// MCBearerContextToModify , PRESENCE = mandatory   SEQUENCE
	__si_e1ap__set_testdata__MCBearerContextToModify( &obj_MCBearerContextModificationRequest->mCBearerContextToModify);
	obj_MCBearerContextModificationRequest->mCBearerContextToModify_isset = 1;



	__si_e1ap_send_MCBearerContextModificationRequest( obj_MCBearerContextModificationRequest, node);
	__si_e1ap_memfree_pdu_MCBearerContextModificationRequest( obj_MCBearerContextModificationRequest);
}

void __si_e1ap__Send_MCBearerContextModificationResponse_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_MCBearerContextModificationResponse * obj_MCBearerContextModificationResponse = (SI_E1AP_DT_PDU_MCBearerContextModificationResponse*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCBearerContextModificationResponse));
	memset( obj_MCBearerContextModificationResponse, 0, sizeof( SI_E1AP_DT_PDU_MCBearerContextModificationResponse));

	// GNB-CU-CP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=16777215
	obj_MCBearerContextModificationResponse->gNBCUCPMBSE1APID = __getTestINTEGER( 0, 16777215);
	obj_MCBearerContextModificationResponse->gNBCUCPMBSE1APID_isset = 1;


	// GNB-CU-UP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=65535
	obj_MCBearerContextModificationResponse->gNBCUUPMBSE1APID = __getTestINTEGER( 0, 65535);
	obj_MCBearerContextModificationResponse->gNBCUUPMBSE1APID_isset = 1;


	// MCBearerContextToModifyResponse , PRESENCE = mandatory   SEQUENCE
	__si_e1ap__set_testdata__MCBearerContextToModifyResponse( &obj_MCBearerContextModificationResponse->mCBearerContextToModifyResponse);
	obj_MCBearerContextModificationResponse->mCBearerContextToModifyResponse_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_MCBearerContextModificationResponse->criticalityDiagnostics);
	obj_MCBearerContextModificationResponse->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_MCBearerContextModificationResponse( obj_MCBearerContextModificationResponse, node);
	__si_e1ap_memfree_pdu_MCBearerContextModificationResponse( obj_MCBearerContextModificationResponse);
}

void __si_e1ap__Send_MCBearerContextModificationFailure_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_MCBearerContextModificationFailure * obj_MCBearerContextModificationFailure = (SI_E1AP_DT_PDU_MCBearerContextModificationFailure*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCBearerContextModificationFailure));
	memset( obj_MCBearerContextModificationFailure, 0, sizeof( SI_E1AP_DT_PDU_MCBearerContextModificationFailure));

	// GNB-CU-CP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=16777215
	obj_MCBearerContextModificationFailure->gNBCUCPMBSE1APID = __getTestINTEGER( 0, 16777215);
	obj_MCBearerContextModificationFailure->gNBCUCPMBSE1APID_isset = 1;


	// GNB-CU-UP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=65535
	obj_MCBearerContextModificationFailure->gNBCUUPMBSE1APID = __getTestINTEGER( 0, 65535);
	obj_MCBearerContextModificationFailure->gNBCUUPMBSE1APID_isset = 1;


	// MBSMulticastF1UContextDescriptor , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__MBSMulticastF1UContextDescriptor( &obj_MCBearerContextModificationFailure->mBSMulticastF1UContextDescriptor);
	obj_MCBearerContextModificationFailure->mBSMulticastF1UContextDescriptor_isset = 1;


	// Cause , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__Cause( &obj_MCBearerContextModificationFailure->cause);
	obj_MCBearerContextModificationFailure->cause->SelectedChoice = Cause_radioNetwork_val;

	switch( obj_MCBearerContextModificationFailure->cause->SelectedChoice)
	{
		case Cause_radioNetwork_val:
			obj_MCBearerContextModificationFailure->cause->u.radioNetwork = CauseRadioNetwork_unspecified_val;
			break;
		case Cause_transport_val:
			obj_MCBearerContextModificationFailure->cause->u.transport = CauseTransport_unspecified_val;
			break;
		case Cause_protocol_val:
			obj_MCBearerContextModificationFailure->cause->u.protocol = CauseProtocol_transfer_syntax_error_val;
			break;
		case Cause_misc_val:
			obj_MCBearerContextModificationFailure->cause->u.misc = CauseMisc_control_processing_overload_val;
			break;
		case Cause_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_Cause_ExtIEs( &obj_MCBearerContextModificationFailure->cause->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_MCBearerContextModificationFailure->cause_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_MCBearerContextModificationFailure->criticalityDiagnostics);
	obj_MCBearerContextModificationFailure->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_MCBearerContextModificationFailure( obj_MCBearerContextModificationFailure, node);
	__si_e1ap_memfree_pdu_MCBearerContextModificationFailure( obj_MCBearerContextModificationFailure);
}

void __si_e1ap__Send_MCBearerContextModificationRequired_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_MCBearerContextModificationRequired * obj_MCBearerContextModificationRequired = (SI_E1AP_DT_PDU_MCBearerContextModificationRequired*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCBearerContextModificationRequired));
	memset( obj_MCBearerContextModificationRequired, 0, sizeof( SI_E1AP_DT_PDU_MCBearerContextModificationRequired));

	// GNB-CU-CP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=16777215
	obj_MCBearerContextModificationRequired->gNBCUCPMBSE1APID = __getTestINTEGER( 0, 16777215);
	obj_MCBearerContextModificationRequired->gNBCUCPMBSE1APID_isset = 1;


	// GNB-CU-UP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=65535
	obj_MCBearerContextModificationRequired->gNBCUUPMBSE1APID = __getTestINTEGER( 0, 65535);
	obj_MCBearerContextModificationRequired->gNBCUUPMBSE1APID_isset = 1;


	// MCBearerContextToModifyRequired , PRESENCE = mandatory   SEQUENCE
	__si_e1ap__set_testdata__MCBearerContextToModifyRequired( &obj_MCBearerContextModificationRequired->mCBearerContextToModifyRequired);
	obj_MCBearerContextModificationRequired->mCBearerContextToModifyRequired_isset = 1;



	__si_e1ap_send_MCBearerContextModificationRequired( obj_MCBearerContextModificationRequired, node);
	__si_e1ap_memfree_pdu_MCBearerContextModificationRequired( obj_MCBearerContextModificationRequired);
}

void __si_e1ap__Send_MCBearerContextModificationConfirm_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_MCBearerContextModificationConfirm * obj_MCBearerContextModificationConfirm = (SI_E1AP_DT_PDU_MCBearerContextModificationConfirm*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCBearerContextModificationConfirm));
	memset( obj_MCBearerContextModificationConfirm, 0, sizeof( SI_E1AP_DT_PDU_MCBearerContextModificationConfirm));

	// GNB-CU-CP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=16777215
	obj_MCBearerContextModificationConfirm->gNBCUCPMBSE1APID = __getTestINTEGER( 0, 16777215);
	obj_MCBearerContextModificationConfirm->gNBCUCPMBSE1APID_isset = 1;


	// GNB-CU-UP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=65535
	obj_MCBearerContextModificationConfirm->gNBCUUPMBSE1APID = __getTestINTEGER( 0, 65535);
	obj_MCBearerContextModificationConfirm->gNBCUUPMBSE1APID_isset = 1;


	// MCBearerContextToModifyConfirm , PRESENCE = mandatory   SEQUENCE
	__si_e1ap__set_testdata__MCBearerContextToModifyConfirm( &obj_MCBearerContextModificationConfirm->mCBearerContextToModifyConfirm);
	obj_MCBearerContextModificationConfirm->mCBearerContextToModifyConfirm_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_MCBearerContextModificationConfirm->criticalityDiagnostics);
	obj_MCBearerContextModificationConfirm->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_MCBearerContextModificationConfirm( obj_MCBearerContextModificationConfirm, node);
	__si_e1ap_memfree_pdu_MCBearerContextModificationConfirm( obj_MCBearerContextModificationConfirm);
}

void __si_e1ap__Send_MCBearerNotification_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_MCBearerNotification * obj_MCBearerNotification = (SI_E1AP_DT_PDU_MCBearerNotification*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCBearerNotification));
	memset( obj_MCBearerNotification, 0, sizeof( SI_E1AP_DT_PDU_MCBearerNotification));

	// GNB-CU-CP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=16777215
	obj_MCBearerNotification->gNBCUCPMBSE1APID = __getTestINTEGER( 0, 16777215);
	obj_MCBearerNotification->gNBCUCPMBSE1APID_isset = 1;


	// GNB-CU-UP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=65535
	obj_MCBearerNotification->gNBCUUPMBSE1APID = __getTestINTEGER( 0, 65535);
	obj_MCBearerNotification->gNBCUUPMBSE1APID_isset = 1;


	// MBSSessionResourceNotification , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__MBSSessionResourceNotification( &obj_MCBearerNotification->mBSSessionResourceNotification);
	obj_MCBearerNotification->mBSSessionResourceNotification->SelectedChoice = MBSSessionResourceNotification_mbs_DL_Data_Arrival_val;

	switch( obj_MCBearerNotification->mBSSessionResourceNotification->SelectedChoice)
	{
		case MBSSessionResourceNotification_mbs_DL_Data_Arrival_val:
			__si_e1ap__set_testdata__MBS_DL_Data_Arrival( &obj_MCBearerNotification->mBSSessionResourceNotification->u.mbs_DL_Data_Arrival); //   L:11712
			break;
		case MBSSessionResourceNotification_inactivity_val:
			__si_e1ap__set_testdata__MCBearerContext_Inactivity( &obj_MCBearerNotification->mBSSessionResourceNotification->u.inactivity); //   L:11712
			break;
		case MBSSessionResourceNotification_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_MBSSessionResourceNotification_ExtIEs( &obj_MCBearerNotification->mBSSessionResourceNotification->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_MCBearerNotification->mBSSessionResourceNotification_isset = 1;



	__si_e1ap_send_MCBearerNotification( obj_MCBearerNotification, node);
	__si_e1ap_memfree_pdu_MCBearerNotification( obj_MCBearerNotification);
}

void __si_e1ap__Send_MCBearerContextReleaseCommand_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_MCBearerContextReleaseCommand * obj_MCBearerContextReleaseCommand = (SI_E1AP_DT_PDU_MCBearerContextReleaseCommand*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCBearerContextReleaseCommand));
	memset( obj_MCBearerContextReleaseCommand, 0, sizeof( SI_E1AP_DT_PDU_MCBearerContextReleaseCommand));

	// GNB-CU-CP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=16777215
	obj_MCBearerContextReleaseCommand->gNBCUCPMBSE1APID = __getTestINTEGER( 0, 16777215);
	obj_MCBearerContextReleaseCommand->gNBCUCPMBSE1APID_isset = 1;


	// GNB-CU-UP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=65535
	obj_MCBearerContextReleaseCommand->gNBCUUPMBSE1APID = __getTestINTEGER( 0, 65535);
	obj_MCBearerContextReleaseCommand->gNBCUUPMBSE1APID_isset = 1;


	// Cause , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__Cause( &obj_MCBearerContextReleaseCommand->cause);
	obj_MCBearerContextReleaseCommand->cause->SelectedChoice = Cause_radioNetwork_val;

	switch( obj_MCBearerContextReleaseCommand->cause->SelectedChoice)
	{
		case Cause_radioNetwork_val:
			obj_MCBearerContextReleaseCommand->cause->u.radioNetwork = CauseRadioNetwork_unspecified_val;
			break;
		case Cause_transport_val:
			obj_MCBearerContextReleaseCommand->cause->u.transport = CauseTransport_unspecified_val;
			break;
		case Cause_protocol_val:
			obj_MCBearerContextReleaseCommand->cause->u.protocol = CauseProtocol_transfer_syntax_error_val;
			break;
		case Cause_misc_val:
			obj_MCBearerContextReleaseCommand->cause->u.misc = CauseMisc_control_processing_overload_val;
			break;
		case Cause_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_Cause_ExtIEs( &obj_MCBearerContextReleaseCommand->cause->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_MCBearerContextReleaseCommand->cause_isset = 1;



	__si_e1ap_send_MCBearerContextReleaseCommand( obj_MCBearerContextReleaseCommand, node);
	__si_e1ap_memfree_pdu_MCBearerContextReleaseCommand( obj_MCBearerContextReleaseCommand);
}

void __si_e1ap__Send_MCBearerContextReleaseComplete_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_MCBearerContextReleaseComplete * obj_MCBearerContextReleaseComplete = (SI_E1AP_DT_PDU_MCBearerContextReleaseComplete*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCBearerContextReleaseComplete));
	memset( obj_MCBearerContextReleaseComplete, 0, sizeof( SI_E1AP_DT_PDU_MCBearerContextReleaseComplete));

	// GNB-CU-CP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=16777215
	obj_MCBearerContextReleaseComplete->gNBCUCPMBSE1APID = __getTestINTEGER( 0, 16777215);
	obj_MCBearerContextReleaseComplete->gNBCUCPMBSE1APID_isset = 1;


	// GNB-CU-UP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=65535
	obj_MCBearerContextReleaseComplete->gNBCUUPMBSE1APID = __getTestINTEGER( 0, 65535);
	obj_MCBearerContextReleaseComplete->gNBCUUPMBSE1APID_isset = 1;


	// CriticalityDiagnostics , PRESENCE = optional   SEQUENCE
	__si_e1ap__set_testdata__CriticalityDiagnostics( &obj_MCBearerContextReleaseComplete->criticalityDiagnostics);
	obj_MCBearerContextReleaseComplete->criticalityDiagnostics_isset = 1;



	__si_e1ap_send_MCBearerContextReleaseComplete( obj_MCBearerContextReleaseComplete, node);
	__si_e1ap_memfree_pdu_MCBearerContextReleaseComplete( obj_MCBearerContextReleaseComplete);
}

void __si_e1ap__Send_MCBearerContextReleaseRequest_Prototype( SI_E1APNode * node)
{
	SI_E1AP_DT_PDU_MCBearerContextReleaseRequest * obj_MCBearerContextReleaseRequest = (SI_E1AP_DT_PDU_MCBearerContextReleaseRequest*) __si_allocM( sizeof(SI_E1AP_DT_PDU_MCBearerContextReleaseRequest));
	memset( obj_MCBearerContextReleaseRequest, 0, sizeof( SI_E1AP_DT_PDU_MCBearerContextReleaseRequest));

	// GNB-CU-CP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=16777215
	obj_MCBearerContextReleaseRequest->gNBCUCPMBSE1APID = __getTestINTEGER( 0, 16777215);
	obj_MCBearerContextReleaseRequest->gNBCUCPMBSE1APID_isset = 1;


	// GNB-CU-UP-MBS-E1AP-ID  , PRESENCE = mandatory  INTEGER , MIN=0, MAX=65535
	obj_MCBearerContextReleaseRequest->gNBCUUPMBSE1APID = __getTestINTEGER( 0, 65535);
	obj_MCBearerContextReleaseRequest->gNBCUUPMBSE1APID_isset = 1;


	// Cause , PRESENCE = mandatory   CHOICE
	__si_e1ap__set_testdata__Cause( &obj_MCBearerContextReleaseRequest->cause);
	obj_MCBearerContextReleaseRequest->cause->SelectedChoice = Cause_radioNetwork_val;

	switch( obj_MCBearerContextReleaseRequest->cause->SelectedChoice)
	{
		case Cause_radioNetwork_val:
			obj_MCBearerContextReleaseRequest->cause->u.radioNetwork = CauseRadioNetwork_unspecified_val;
			break;
		case Cause_transport_val:
			obj_MCBearerContextReleaseRequest->cause->u.transport = CauseTransport_unspecified_val;
			break;
		case Cause_protocol_val:
			obj_MCBearerContextReleaseRequest->cause->u.protocol = CauseProtocol_transfer_syntax_error_val;
			break;
		case Cause_misc_val:
			obj_MCBearerContextReleaseRequest->cause->u.misc = CauseMisc_control_processing_overload_val;
			break;
		case Cause_choice_extension_val:  // L:11805
			{
				__si_e1ap__set_testdata__PDU_Cause_ExtIEs( &obj_MCBearerContextReleaseRequest->cause->u.choice_extension);   // L:11825
			}
			break;
		default:
			break;
	}

	obj_MCBearerContextReleaseRequest->cause_isset = 1;



	__si_e1ap_send_MCBearerContextReleaseRequest( obj_MCBearerContextReleaseRequest, node);
	__si_e1ap_memfree_pdu_MCBearerContextReleaseRequest( obj_MCBearerContextReleaseRequest);
}




void __si_e1ap__Handle_Reset_Prototype( SI_E1AP_DT_PDU_Reset * obj_Reset, SI_E1APNode * node)
{
	if( obj_Reset->transactionID_isset == 1)
	{
	}

	if( obj_Reset->cause_isset == 1)
	{
	}

	if( obj_Reset->resetType_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_Reset( obj_Reset);
}


void __si_e1ap__Handle_ResetAcknowledge_Prototype( SI_E1AP_DT_PDU_ResetAcknowledge * obj_ResetAcknowledge, SI_E1APNode * node)
{
	if( obj_ResetAcknowledge->transactionID_isset == 1)
	{
	}

	if( obj_ResetAcknowledge->uEassociatedLogicalE1ConnectionListResAck_isset == 1)
	{
	}

	if( obj_ResetAcknowledge->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_ResetAcknowledge( obj_ResetAcknowledge);
}


void __si_e1ap__Handle_ErrorIndication_Prototype( SI_E1AP_DT_PDU_ErrorIndication * obj_ErrorIndication, SI_E1APNode * node)
{
	if( obj_ErrorIndication->transactionID_isset == 1)
	{
	}

	if( obj_ErrorIndication->gNBCUCPUEE1APID_isset == 1)
	{
	}

	if( obj_ErrorIndication->gNBCUUPUEE1APID_isset == 1)
	{
	}

	if( obj_ErrorIndication->cause_isset == 1)
	{
	}

	if( obj_ErrorIndication->criticalityDiagnostics_isset == 1)
	{
	}

	if( obj_ErrorIndication->gNBCUCPMBSE1APID_isset == 1)
	{
	}

	if( obj_ErrorIndication->gNBCUUPMBSE1APID_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_ErrorIndication( obj_ErrorIndication);
}


void __si_e1ap__Handle_GNB_CU_UP_E1SetupRequest_Prototype( SI_E1AP_DT_PDU_GNB_CU_UP_E1SetupRequest * obj_GNB_CU_UP_E1SetupRequest, SI_E1APNode * node)
{
	if( obj_GNB_CU_UP_E1SetupRequest->transactionID_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_E1SetupRequest->gNBCUUPID_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_E1SetupRequest->gNBCUUPName_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_E1SetupRequest->cNSupport_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_E1SetupRequest->supportedPLMNs_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_E1SetupRequest->gNBCUUPCapacity_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_E1SetupRequest->transportLayerAddressInfo_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_E1SetupRequest->extendedGNBCUUPName_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_E1SetupRequest->gNBCUUPMBSSupportInfo_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_GNB_CU_UP_E1SetupRequest( obj_GNB_CU_UP_E1SetupRequest);
}


void __si_e1ap__Handle_GNB_CU_UP_E1SetupResponse_Prototype( SI_E1AP_DT_PDU_GNB_CU_UP_E1SetupResponse * obj_GNB_CU_UP_E1SetupResponse, SI_E1APNode * node)
{
	if( obj_GNB_CU_UP_E1SetupResponse->transactionID_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_E1SetupResponse->gNBCUCPName_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_E1SetupResponse->transportLayerAddressInfo_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_E1SetupResponse->extendedGNBCUCPName_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_E1SetupResponse->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_GNB_CU_UP_E1SetupResponse( obj_GNB_CU_UP_E1SetupResponse);
}


void __si_e1ap__Handle_GNB_CU_UP_E1SetupFailure_Prototype( SI_E1AP_DT_PDU_GNB_CU_UP_E1SetupFailure * obj_GNB_CU_UP_E1SetupFailure, SI_E1APNode * node)
{
	if( obj_GNB_CU_UP_E1SetupFailure->transactionID_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_E1SetupFailure->cause_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_E1SetupFailure->timeToWait_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_E1SetupFailure->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_GNB_CU_UP_E1SetupFailure( obj_GNB_CU_UP_E1SetupFailure);
}


void __si_e1ap__Handle_GNB_CU_CP_E1SetupRequest_Prototype( SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupRequest * obj_GNB_CU_CP_E1SetupRequest, SI_E1APNode * node)
{
	if( obj_GNB_CU_CP_E1SetupRequest->transactionID_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_E1SetupRequest->gNBCUCPName_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_E1SetupRequest->transportLayerAddressInfo_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_E1SetupRequest->extendedGNBCUCPName_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_GNB_CU_CP_E1SetupRequest( obj_GNB_CU_CP_E1SetupRequest);
}


void __si_e1ap__Handle_GNB_CU_CP_E1SetupResponse_Prototype( SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupResponse * obj_GNB_CU_CP_E1SetupResponse, SI_E1APNode * node)
{
	if( obj_GNB_CU_CP_E1SetupResponse->transactionID_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_E1SetupResponse->gNBCUUPID_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_E1SetupResponse->gNBCUUPName_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_E1SetupResponse->cNSupport_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_E1SetupResponse->supportedPLMNs_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_E1SetupResponse->gNBCUUPCapacity_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_E1SetupResponse->transportLayerAddressInfo_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_E1SetupResponse->extendedGNBCUUPName_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_E1SetupResponse->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_GNB_CU_CP_E1SetupResponse( obj_GNB_CU_CP_E1SetupResponse);
}


void __si_e1ap__Handle_GNB_CU_CP_E1SetupFailure_Prototype( SI_E1AP_DT_PDU_GNB_CU_CP_E1SetupFailure * obj_GNB_CU_CP_E1SetupFailure, SI_E1APNode * node)
{
	if( obj_GNB_CU_CP_E1SetupFailure->transactionID_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_E1SetupFailure->cause_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_E1SetupFailure->timeToWait_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_E1SetupFailure->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_GNB_CU_CP_E1SetupFailure( obj_GNB_CU_CP_E1SetupFailure);
}


void __si_e1ap__Handle_GNB_CU_UP_ConfigurationUpdate_Prototype( SI_E1AP_DT_PDU_GNB_CU_UP_ConfigurationUpdate * obj_GNB_CU_UP_ConfigurationUpdate, SI_E1APNode * node)
{
	if( obj_GNB_CU_UP_ConfigurationUpdate->transactionID_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_ConfigurationUpdate->gNBCUUPID_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_ConfigurationUpdate->gNBCUUPName_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_ConfigurationUpdate->supportedPLMNs_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_ConfigurationUpdate->gNBCUUPCapacity_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_ConfigurationUpdate->gNBCUUPTNLAToRemoveList_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_ConfigurationUpdate->transportLayerAddressInfo_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_ConfigurationUpdate->extendedGNBCUUPName_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_ConfigurationUpdate->gNBCUUPMBSSupportInfo_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_GNB_CU_UP_ConfigurationUpdate( obj_GNB_CU_UP_ConfigurationUpdate);
}


void __si_e1ap__Handle_GNB_CU_UP_ConfigurationUpdateAcknowledge_Prototype( SI_E1AP_DT_PDU_GNB_CU_UP_ConfigurationUpdateAcknowledge * obj_GNB_CU_UP_ConfigurationUpdateAcknowledge, SI_E1APNode * node)
{
	if( obj_GNB_CU_UP_ConfigurationUpdateAcknowledge->transactionID_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_ConfigurationUpdateAcknowledge->criticalityDiagnostics_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_ConfigurationUpdateAcknowledge->transportLayerAddressInfo_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_GNB_CU_UP_ConfigurationUpdateAcknowledge( obj_GNB_CU_UP_ConfigurationUpdateAcknowledge);
}


void __si_e1ap__Handle_GNB_CU_UP_ConfigurationUpdateFailure_Prototype( SI_E1AP_DT_PDU_GNB_CU_UP_ConfigurationUpdateFailure * obj_GNB_CU_UP_ConfigurationUpdateFailure, SI_E1APNode * node)
{
	if( obj_GNB_CU_UP_ConfigurationUpdateFailure->transactionID_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_ConfigurationUpdateFailure->cause_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_ConfigurationUpdateFailure->timeToWait_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_ConfigurationUpdateFailure->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_GNB_CU_UP_ConfigurationUpdateFailure( obj_GNB_CU_UP_ConfigurationUpdateFailure);
}


void __si_e1ap__Handle_GNB_CU_CP_ConfigurationUpdate_Prototype( SI_E1AP_DT_PDU_GNB_CU_CP_ConfigurationUpdate * obj_GNB_CU_CP_ConfigurationUpdate, SI_E1APNode * node)
{
	if( obj_GNB_CU_CP_ConfigurationUpdate->transactionID_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_ConfigurationUpdate->gNBCUCPName_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_ConfigurationUpdate->gNBCUCPTNLAToAddList_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_ConfigurationUpdate->gNBCUCPTNLAToRemoveList_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_ConfigurationUpdate->gNBCUCPTNLAToUpdateList_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_ConfigurationUpdate->transportLayerAddressInfo_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_ConfigurationUpdate->extendedGNBCUCPName_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_GNB_CU_CP_ConfigurationUpdate( obj_GNB_CU_CP_ConfigurationUpdate);
}


void __si_e1ap__Handle_GNB_CU_CP_ConfigurationUpdateAcknowledge_Prototype( SI_E1AP_DT_PDU_GNB_CU_CP_ConfigurationUpdateAcknowledge * obj_GNB_CU_CP_ConfigurationUpdateAcknowledge, SI_E1APNode * node)
{
	if( obj_GNB_CU_CP_ConfigurationUpdateAcknowledge->transactionID_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_ConfigurationUpdateAcknowledge->criticalityDiagnostics_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_ConfigurationUpdateAcknowledge->gNBCUCPTNLASetupList_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_ConfigurationUpdateAcknowledge->gNBCUCPTNLAFailedToSetupList_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_ConfigurationUpdateAcknowledge->transportLayerAddressInfo_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_GNB_CU_CP_ConfigurationUpdateAcknowledge( obj_GNB_CU_CP_ConfigurationUpdateAcknowledge);
}


void __si_e1ap__Handle_GNB_CU_CP_ConfigurationUpdateFailure_Prototype( SI_E1AP_DT_PDU_GNB_CU_CP_ConfigurationUpdateFailure * obj_GNB_CU_CP_ConfigurationUpdateFailure, SI_E1APNode * node)
{
	if( obj_GNB_CU_CP_ConfigurationUpdateFailure->transactionID_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_ConfigurationUpdateFailure->cause_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_ConfigurationUpdateFailure->timeToWait_isset == 1)
	{
	}

	if( obj_GNB_CU_CP_ConfigurationUpdateFailure->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_GNB_CU_CP_ConfigurationUpdateFailure( obj_GNB_CU_CP_ConfigurationUpdateFailure);
}


void __si_e1ap__Handle_E1ReleaseRequest_Prototype( SI_E1AP_DT_PDU_E1ReleaseRequest * obj_E1ReleaseRequest, SI_E1APNode * node)
{
	if( obj_E1ReleaseRequest->transactionID_isset == 1)
	{
	}

	if( obj_E1ReleaseRequest->cause_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_E1ReleaseRequest( obj_E1ReleaseRequest);
}


void __si_e1ap__Handle_E1ReleaseResponse_Prototype( SI_E1AP_DT_PDU_E1ReleaseResponse * obj_E1ReleaseResponse, SI_E1APNode * node)
{
	if( obj_E1ReleaseResponse->transactionID_isset == 1)
	{
	}

	if( obj_E1ReleaseResponse->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_E1ReleaseResponse( obj_E1ReleaseResponse);
}


void __si_e1ap__Handle_BearerContextSetupRequest_Prototype( SI_E1AP_DT_PDU_BearerContextSetupRequest * obj_BearerContextSetupRequest, SI_E1APNode * node)
{
	if( obj_BearerContextSetupRequest->gNBCUCPUEE1APID_isset == 1)
	{
	}

	if( obj_BearerContextSetupRequest->securityInformation_isset == 1)
	{
	}

	if( obj_BearerContextSetupRequest->uEDLAggregateMaximumBitRate_isset == 1)
	{
	}

	if( obj_BearerContextSetupRequest->uEDLMaximumIntegrityProtectedDataRate_isset == 1)
	{
	}

	if( obj_BearerContextSetupRequest->servingPLMN_isset == 1)
	{
	}

	if( obj_BearerContextSetupRequest->activityNotificationLevel_isset == 1)
	{
	}

	if( obj_BearerContextSetupRequest->uEInactivityTimer_isset == 1)
	{
	}

	if( obj_BearerContextSetupRequest->bearerContextStatusChange_isset == 1)
	{
	}

	if( obj_BearerContextSetupRequest->systemBearerContextSetupRequest_isset == 1)
	{
	}

	if( obj_BearerContextSetupRequest->rANUEID_isset == 1)
	{
	}

	if( obj_BearerContextSetupRequest->gNBDUID_isset == 1)
	{
	}

	if( obj_BearerContextSetupRequest->traceActivation_isset == 1)
	{
	}

	if( obj_BearerContextSetupRequest->nPNContextInfo_isset == 1)
	{
	}

	if( obj_BearerContextSetupRequest->managementBasedMDTPLMNList_isset == 1)
	{
	}

	if( obj_BearerContextSetupRequest->cHOInitiation_isset == 1)
	{
	}

	if( obj_BearerContextSetupRequest->additionalHandoverInfo_isset == 1)
	{
	}

	if( obj_BearerContextSetupRequest->directForwardingPathAvailability_isset == 1)
	{
	}

	if( obj_BearerContextSetupRequest->gNBCUUPUEE1APID_isset == 1)
	{
	}

	if( obj_BearerContextSetupRequest->mDTPollutedMeasurementIndicator_isset == 1)
	{
	}

	if( obj_BearerContextSetupRequest->uESliceMaximumBitRateList_isset == 1)
	{
	}

	if( obj_BearerContextSetupRequest->sCGActivationStatus_isset == 1)
	{
	}

	if( obj_BearerContextSetupRequest->mTSDTInformationRequest_isset == 1)
	{
	}

	if( obj_BearerContextSetupRequest->sDTdatasizethreshold_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_BearerContextSetupRequest( obj_BearerContextSetupRequest);
}


void __si_e1ap__Handle_BearerContextSetupResponse_Prototype( SI_E1AP_DT_PDU_BearerContextSetupResponse * obj_BearerContextSetupResponse, SI_E1APNode * node)
{
	if( obj_BearerContextSetupResponse->gNBCUCPUEE1APID_isset == 1)
	{
	}

	if( obj_BearerContextSetupResponse->gNBCUUPUEE1APID_isset == 1)
	{
	}

	if( obj_BearerContextSetupResponse->systemBearerContextSetupResponse_isset == 1)
	{
	}

	if( obj_BearerContextSetupResponse->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_BearerContextSetupResponse( obj_BearerContextSetupResponse);
}


void __si_e1ap__Handle_BearerContextSetupFailure_Prototype( SI_E1AP_DT_PDU_BearerContextSetupFailure * obj_BearerContextSetupFailure, SI_E1APNode * node)
{
	if( obj_BearerContextSetupFailure->gNBCUCPUEE1APID_isset == 1)
	{
	}

	if( obj_BearerContextSetupFailure->gNBCUUPUEE1APID_isset == 1)
	{
	}

	if( obj_BearerContextSetupFailure->cause_isset == 1)
	{
	}

	if( obj_BearerContextSetupFailure->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_BearerContextSetupFailure( obj_BearerContextSetupFailure);
}


void __si_e1ap__Handle_BearerContextModificationRequest_Prototype( SI_E1AP_DT_PDU_BearerContextModificationRequest * obj_BearerContextModificationRequest, SI_E1APNode * node)
{
	if( obj_BearerContextModificationRequest->gNBCUCPUEE1APID_isset == 1)
	{
	}

	if( obj_BearerContextModificationRequest->gNBCUUPUEE1APID_isset == 1)
	{
	}

	if( obj_BearerContextModificationRequest->securityInformation_isset == 1)
	{
	}

	if( obj_BearerContextModificationRequest->uEDLAggregateMaximumBitRate_isset == 1)
	{
	}

	if( obj_BearerContextModificationRequest->uEDLMaximumIntegrityProtectedDataRate_isset == 1)
	{
	}

	if( obj_BearerContextModificationRequest->bearerContextStatusChange_isset == 1)
	{
	}

	if( obj_BearerContextModificationRequest->newULTNLInformationRequired_isset == 1)
	{
	}

	if( obj_BearerContextModificationRequest->uEInactivityTimer_isset == 1)
	{
	}

	if( obj_BearerContextModificationRequest->dataDiscardRequired_isset == 1)
	{
	}

	if( obj_BearerContextModificationRequest->systemBearerContextModificationRequest_isset == 1)
	{
	}

	if( obj_BearerContextModificationRequest->rANUEID_isset == 1)
	{
	}

	if( obj_BearerContextModificationRequest->gNBDUID_isset == 1)
	{
	}

	if( obj_BearerContextModificationRequest->activityNotificationLevel_isset == 1)
	{
	}

	if( obj_BearerContextModificationRequest->mDTPollutedMeasurementIndicator_isset == 1)
	{
	}

	if( obj_BearerContextModificationRequest->uESliceMaximumBitRateList_isset == 1)
	{
	}

	if( obj_BearerContextModificationRequest->sCGActivationStatus_isset == 1)
	{
	}

	if( obj_BearerContextModificationRequest->sDTContinueROHC_isset == 1)
	{
	}

	if( obj_BearerContextModificationRequest->managementBasedMDTPLMNModificationList_isset == 1)
	{
	}

	if( obj_BearerContextModificationRequest->inactivityInformationRequest_isset == 1)
	{
	}

	if( obj_BearerContextModificationRequest->mTSDTInformationRequest_isset == 1)
	{
	}

	if( obj_BearerContextModificationRequest->sDTdatasizethreshold_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_BearerContextModificationRequest( obj_BearerContextModificationRequest);
}


void __si_e1ap__Handle_BearerContextModificationResponse_Prototype( SI_E1AP_DT_PDU_BearerContextModificationResponse * obj_BearerContextModificationResponse, SI_E1APNode * node)
{
	if( obj_BearerContextModificationResponse->gNBCUCPUEE1APID_isset == 1)
	{
	}

	if( obj_BearerContextModificationResponse->gNBCUUPUEE1APID_isset == 1)
	{
	}

	if( obj_BearerContextModificationResponse->systemBearerContextModificationResponse_isset == 1)
	{
	}

	if( obj_BearerContextModificationResponse->criticalityDiagnostics_isset == 1)
	{
	}

	if( obj_BearerContextModificationResponse->uEInactivityInformation_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_BearerContextModificationResponse( obj_BearerContextModificationResponse);
}


void __si_e1ap__Handle_BearerContextModificationFailure_Prototype( SI_E1AP_DT_PDU_BearerContextModificationFailure * obj_BearerContextModificationFailure, SI_E1APNode * node)
{
	if( obj_BearerContextModificationFailure->gNBCUCPUEE1APID_isset == 1)
	{
	}

	if( obj_BearerContextModificationFailure->gNBCUUPUEE1APID_isset == 1)
	{
	}

	if( obj_BearerContextModificationFailure->cause_isset == 1)
	{
	}

	if( obj_BearerContextModificationFailure->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_BearerContextModificationFailure( obj_BearerContextModificationFailure);
}


void __si_e1ap__Handle_BearerContextModificationRequired_Prototype( SI_E1AP_DT_PDU_BearerContextModificationRequired * obj_BearerContextModificationRequired, SI_E1APNode * node)
{
	if( obj_BearerContextModificationRequired->gNBCUCPUEE1APID_isset == 1)
	{
	}

	if( obj_BearerContextModificationRequired->gNBCUUPUEE1APID_isset == 1)
	{
	}

	if( obj_BearerContextModificationRequired->systemBearerContextModificationRequired_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_BearerContextModificationRequired( obj_BearerContextModificationRequired);
}


void __si_e1ap__Handle_BearerContextModificationConfirm_Prototype( SI_E1AP_DT_PDU_BearerContextModificationConfirm * obj_BearerContextModificationConfirm, SI_E1APNode * node)
{
	if( obj_BearerContextModificationConfirm->gNBCUCPUEE1APID_isset == 1)
	{
	}

	if( obj_BearerContextModificationConfirm->gNBCUUPUEE1APID_isset == 1)
	{
	}

	if( obj_BearerContextModificationConfirm->systemBearerContextModificationConfirm_isset == 1)
	{
	}

	if( obj_BearerContextModificationConfirm->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_BearerContextModificationConfirm( obj_BearerContextModificationConfirm);
}


void __si_e1ap__Handle_BearerContextReleaseCommand_Prototype( SI_E1AP_DT_PDU_BearerContextReleaseCommand * obj_BearerContextReleaseCommand, SI_E1APNode * node)
{
	if( obj_BearerContextReleaseCommand->gNBCUCPUEE1APID_isset == 1)
	{
	}

	if( obj_BearerContextReleaseCommand->gNBCUUPUEE1APID_isset == 1)
	{
	}

	if( obj_BearerContextReleaseCommand->cause_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_BearerContextReleaseCommand( obj_BearerContextReleaseCommand);
}


void __si_e1ap__Handle_BearerContextReleaseComplete_Prototype( SI_E1AP_DT_PDU_BearerContextReleaseComplete * obj_BearerContextReleaseComplete, SI_E1APNode * node)
{
	if( obj_BearerContextReleaseComplete->gNBCUCPUEE1APID_isset == 1)
	{
	}

	if( obj_BearerContextReleaseComplete->gNBCUUPUEE1APID_isset == 1)
	{
	}

	if( obj_BearerContextReleaseComplete->criticalityDiagnostics_isset == 1)
	{
	}

	if( obj_BearerContextReleaseComplete->retainabilityMeasurementsInfo_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_BearerContextReleaseComplete( obj_BearerContextReleaseComplete);
}


void __si_e1ap__Handle_BearerContextReleaseRequest_Prototype( SI_E1AP_DT_PDU_BearerContextReleaseRequest * obj_BearerContextReleaseRequest, SI_E1APNode * node)
{
	if( obj_BearerContextReleaseRequest->gNBCUCPUEE1APID_isset == 1)
	{
	}

	if( obj_BearerContextReleaseRequest->gNBCUUPUEE1APID_isset == 1)
	{
	}

	if( obj_BearerContextReleaseRequest->dRBStatusList_isset == 1)
	{
	}

	if( obj_BearerContextReleaseRequest->cause_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_BearerContextReleaseRequest( obj_BearerContextReleaseRequest);
}


void __si_e1ap__Handle_BearerContextInactivityNotification_Prototype( SI_E1AP_DT_PDU_BearerContextInactivityNotification * obj_BearerContextInactivityNotification, SI_E1APNode * node)
{
	if( obj_BearerContextInactivityNotification->gNBCUCPUEE1APID_isset == 1)
	{
	}

	if( obj_BearerContextInactivityNotification->gNBCUUPUEE1APID_isset == 1)
	{
	}

	if( obj_BearerContextInactivityNotification->activityInformation_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_BearerContextInactivityNotification( obj_BearerContextInactivityNotification);
}


void __si_e1ap__Handle_DLDataNotification_Prototype( SI_E1AP_DT_PDU_DLDataNotification * obj_DLDataNotification, SI_E1APNode * node)
{
	if( obj_DLDataNotification->gNBCUCPUEE1APID_isset == 1)
	{
	}

	if( obj_DLDataNotification->gNBCUUPUEE1APID_isset == 1)
	{
	}

	if( obj_DLDataNotification->pPI_isset == 1)
	{
	}

	if( obj_DLDataNotification->pDUSessionToNotifyList_isset == 1)
	{
	}

	if( obj_DLDataNotification->mTSDTInformation_isset == 1)
	{
	}

	if( obj_DLDataNotification->sDTdatasizethresholdCrossed_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_DLDataNotification( obj_DLDataNotification);
}


void __si_e1ap__Handle_ULDataNotification_Prototype( SI_E1AP_DT_PDU_ULDataNotification * obj_ULDataNotification, SI_E1APNode * node)
{
	if( obj_ULDataNotification->gNBCUCPUEE1APID_isset == 1)
	{
	}

	if( obj_ULDataNotification->gNBCUUPUEE1APID_isset == 1)
	{
	}

	if( obj_ULDataNotification->pDUSessionToNotifyList_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_ULDataNotification( obj_ULDataNotification);
}


void __si_e1ap__Handle_DataUsageReport_Prototype( SI_E1AP_DT_PDU_DataUsageReport * obj_DataUsageReport, SI_E1APNode * node)
{
	if( obj_DataUsageReport->gNBCUCPUEE1APID_isset == 1)
	{
	}

	if( obj_DataUsageReport->gNBCUUPUEE1APID_isset == 1)
	{
	}

	if( obj_DataUsageReport->dataUsageReportList_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_DataUsageReport( obj_DataUsageReport);
}


void __si_e1ap__Handle_GNB_CU_UP_CounterCheckRequest_Prototype( SI_E1AP_DT_PDU_GNB_CU_UP_CounterCheckRequest * obj_GNB_CU_UP_CounterCheckRequest, SI_E1APNode * node)
{
	if( obj_GNB_CU_UP_CounterCheckRequest->gNBCUCPUEE1APID_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_CounterCheckRequest->gNBCUUPUEE1APID_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_CounterCheckRequest->systemGNBCUUPCounterCheckRequest_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_GNB_CU_UP_CounterCheckRequest( obj_GNB_CU_UP_CounterCheckRequest);
}


void __si_e1ap__Handle_GNB_CU_UP_StatusIndication_Prototype( SI_E1AP_DT_PDU_GNB_CU_UP_StatusIndication * obj_GNB_CU_UP_StatusIndication, SI_E1APNode * node)
{
	if( obj_GNB_CU_UP_StatusIndication->transactionID_isset == 1)
	{
	}

	if( obj_GNB_CU_UP_StatusIndication->gNBCUUPOverloadInformation_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_GNB_CU_UP_StatusIndication( obj_GNB_CU_UP_StatusIndication);
}


void __si_e1ap__Handle_PrivateMessage_Prototype( SI_E1AP_DT_PDU_PrivateMessage * obj_PrivateMessage, SI_E1APNode * node)
{
	__si_e1ap_memfree_pdu_PrivateMessage( obj_PrivateMessage);
}


void __si_e1ap__Handle_GNB_CU_CPMeasurementResultsInformation_Prototype( SI_E1AP_DT_PDU_GNB_CU_CPMeasurementResultsInformation * obj_GNB_CU_CPMeasurementResultsInformation, SI_E1APNode * node)
{
	if( obj_GNB_CU_CPMeasurementResultsInformation->gNBCUCPUEE1APID_isset == 1)
	{
	}

	if( obj_GNB_CU_CPMeasurementResultsInformation->gNBCUUPUEE1APID_isset == 1)
	{
	}

	if( obj_GNB_CU_CPMeasurementResultsInformation->dRBMeasurementResultsInformationList_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_GNB_CU_CPMeasurementResultsInformation( obj_GNB_CU_CPMeasurementResultsInformation);
}


void __si_e1ap__Handle_MRDC_DataUsageReport_Prototype( SI_E1AP_DT_PDU_MRDC_DataUsageReport * obj_MRDC_DataUsageReport, SI_E1APNode * node)
{
	if( obj_MRDC_DataUsageReport->gNBCUCPUEE1APID_isset == 1)
	{
	}

	if( obj_MRDC_DataUsageReport->gNBCUUPUEE1APID_isset == 1)
	{
	}

	if( obj_MRDC_DataUsageReport->pDUSessionResourceDataUsageList_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_MRDC_DataUsageReport( obj_MRDC_DataUsageReport);
}


void __si_e1ap__Handle_DeactivateTrace_Prototype( SI_E1AP_DT_PDU_DeactivateTrace * obj_DeactivateTrace, SI_E1APNode * node)
{
	if( obj_DeactivateTrace->gNBCUCPUEE1APID_isset == 1)
	{
	}

	if( obj_DeactivateTrace->gNBCUUPUEE1APID_isset == 1)
	{
	}

	if( obj_DeactivateTrace->traceID_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_DeactivateTrace( obj_DeactivateTrace);
}


void __si_e1ap__Handle_TraceStart_Prototype( SI_E1AP_DT_PDU_TraceStart * obj_TraceStart, SI_E1APNode * node)
{
	if( obj_TraceStart->gNBCUCPUEE1APID_isset == 1)
	{
	}

	if( obj_TraceStart->gNBCUUPUEE1APID_isset == 1)
	{
	}

	if( obj_TraceStart->traceActivation_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_TraceStart( obj_TraceStart);
}


void __si_e1ap__Handle_ResourceStatusRequest_Prototype( SI_E1AP_DT_PDU_ResourceStatusRequest * obj_ResourceStatusRequest, SI_E1APNode * node)
{
	if( obj_ResourceStatusRequest->transactionID_isset == 1)
	{
	}

	if( obj_ResourceStatusRequest->registrationRequest_isset == 1)
	{
	}

	if( obj_ResourceStatusRequest->reportCharacteristics_isset == 1)
	{
	}

	if( obj_ResourceStatusRequest->reportingPeriodicity_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_ResourceStatusRequest( obj_ResourceStatusRequest);
}


void __si_e1ap__Handle_ResourceStatusResponse_Prototype( SI_E1AP_DT_PDU_ResourceStatusResponse * obj_ResourceStatusResponse, SI_E1APNode * node)
{
	if( obj_ResourceStatusResponse->transactionID_isset == 1)
	{
	}

	if( obj_ResourceStatusResponse->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_ResourceStatusResponse( obj_ResourceStatusResponse);
}


void __si_e1ap__Handle_ResourceStatusFailure_Prototype( SI_E1AP_DT_PDU_ResourceStatusFailure * obj_ResourceStatusFailure, SI_E1APNode * node)
{
	if( obj_ResourceStatusFailure->transactionID_isset == 1)
	{
	}

	if( obj_ResourceStatusFailure->cause_isset == 1)
	{
	}

	if( obj_ResourceStatusFailure->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_ResourceStatusFailure( obj_ResourceStatusFailure);
}


void __si_e1ap__Handle_ResourceStatusUpdate_Prototype( SI_E1AP_DT_PDU_ResourceStatusUpdate * obj_ResourceStatusUpdate, SI_E1APNode * node)
{
	if( obj_ResourceStatusUpdate->transactionID_isset == 1)
	{
	}

	if( obj_ResourceStatusUpdate->tNLAvailableCapacityIndicator_isset == 1)
	{
	}

	if( obj_ResourceStatusUpdate->hWCapacityIndicator_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_ResourceStatusUpdate( obj_ResourceStatusUpdate);
}


void __si_e1ap__Handle_IAB_UPTNLAddressUpdate_Prototype( SI_E1AP_DT_PDU_IAB_UPTNLAddressUpdate * obj_IAB_UPTNLAddressUpdate, SI_E1APNode * node)
{
	if( obj_IAB_UPTNLAddressUpdate->transactionID_isset == 1)
	{
	}

	if( obj_IAB_UPTNLAddressUpdate->dLUPTNLAddressToUpdateList_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_IAB_UPTNLAddressUpdate( obj_IAB_UPTNLAddressUpdate);
}


void __si_e1ap__Handle_IAB_UPTNLAddressUpdateAcknowledge_Prototype( SI_E1AP_DT_PDU_IAB_UPTNLAddressUpdateAcknowledge * obj_IAB_UPTNLAddressUpdateAcknowledge, SI_E1APNode * node)
{
	if( obj_IAB_UPTNLAddressUpdateAcknowledge->transactionID_isset == 1)
	{
	}

	if( obj_IAB_UPTNLAddressUpdateAcknowledge->criticalityDiagnostics_isset == 1)
	{
	}

	if( obj_IAB_UPTNLAddressUpdateAcknowledge->uLUPTNLAddressToUpdateList_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_IAB_UPTNLAddressUpdateAcknowledge( obj_IAB_UPTNLAddressUpdateAcknowledge);
}


void __si_e1ap__Handle_IAB_UPTNLAddressUpdateFailure_Prototype( SI_E1AP_DT_PDU_IAB_UPTNLAddressUpdateFailure * obj_IAB_UPTNLAddressUpdateFailure, SI_E1APNode * node)
{
	if( obj_IAB_UPTNLAddressUpdateFailure->transactionID_isset == 1)
	{
	}

	if( obj_IAB_UPTNLAddressUpdateFailure->cause_isset == 1)
	{
	}

	if( obj_IAB_UPTNLAddressUpdateFailure->timeToWait_isset == 1)
	{
	}

	if( obj_IAB_UPTNLAddressUpdateFailure->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_IAB_UPTNLAddressUpdateFailure( obj_IAB_UPTNLAddressUpdateFailure);
}


void __si_e1ap__Handle_CellTrafficTrace_Prototype( SI_E1AP_DT_PDU_CellTrafficTrace * obj_CellTrafficTrace, SI_E1APNode * node)
{
	if( obj_CellTrafficTrace->gNBCUCPUEE1APID_isset == 1)
	{
	}

	if( obj_CellTrafficTrace->gNBCUUPUEE1APID_isset == 1)
	{
	}

	if( obj_CellTrafficTrace->traceID_isset == 1)
	{
	}

	if( obj_CellTrafficTrace->traceCollectionEntityIPAddress_isset == 1)
	{
	}

	if( obj_CellTrafficTrace->privacyIndicator_isset == 1)
	{
	}

	if( obj_CellTrafficTrace->uRIaddress_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_CellTrafficTrace( obj_CellTrafficTrace);
}


void __si_e1ap__Handle_EarlyForwardingSNTransfer_Prototype( SI_E1AP_DT_PDU_EarlyForwardingSNTransfer * obj_EarlyForwardingSNTransfer, SI_E1APNode * node)
{
	if( obj_EarlyForwardingSNTransfer->gNBCUCPUEE1APID_isset == 1)
	{
	}

	if( obj_EarlyForwardingSNTransfer->gNBCUUPUEE1APID_isset == 1)
	{
	}

	if( obj_EarlyForwardingSNTransfer->dRBsSubjectToEarlyForwardingList_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_EarlyForwardingSNTransfer( obj_EarlyForwardingSNTransfer);
}


void __si_e1ap__Handle_IABPSKNotification_Prototype( SI_E1AP_DT_PDU_IABPSKNotification * obj_IABPSKNotification, SI_E1APNode * node)
{
	if( obj_IABPSKNotification->transactionID_isset == 1)
	{
	}

	if( obj_IABPSKNotification->iABDonorCUUPPSKInfo_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_IABPSKNotification( obj_IABPSKNotification);
}


void __si_e1ap__Handle_BCBearerContextSetupRequest_Prototype( SI_E1AP_DT_PDU_BCBearerContextSetupRequest * obj_BCBearerContextSetupRequest, SI_E1APNode * node)
{
	if( obj_BCBearerContextSetupRequest->gNBCUCPMBSE1APID_isset == 1)
	{
	}

	if( obj_BCBearerContextSetupRequest->globalMBSSessionID_isset == 1)
	{
	}

	if( obj_BCBearerContextSetupRequest->bCBearerContextToSetup_isset == 1)
	{
	}

	if( obj_BCBearerContextSetupRequest->associatedSessionID_isset == 1)
	{
	}

	if( obj_BCBearerContextSetupRequest->mBSServiceArea_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_BCBearerContextSetupRequest( obj_BCBearerContextSetupRequest);
}


void __si_e1ap__Handle_BCBearerContextSetupResponse_Prototype( SI_E1AP_DT_PDU_BCBearerContextSetupResponse * obj_BCBearerContextSetupResponse, SI_E1APNode * node)
{
	if( obj_BCBearerContextSetupResponse->gNBCUCPMBSE1APID_isset == 1)
	{
	}

	if( obj_BCBearerContextSetupResponse->gNBCUUPMBSE1APID_isset == 1)
	{
	}

	if( obj_BCBearerContextSetupResponse->bCBearerContextToSetupResponse_isset == 1)
	{
	}

	if( obj_BCBearerContextSetupResponse->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_BCBearerContextSetupResponse( obj_BCBearerContextSetupResponse);
}


void __si_e1ap__Handle_BCBearerContextSetupFailure_Prototype( SI_E1AP_DT_PDU_BCBearerContextSetupFailure * obj_BCBearerContextSetupFailure, SI_E1APNode * node)
{
	if( obj_BCBearerContextSetupFailure->gNBCUCPMBSE1APID_isset == 1)
	{
	}

	if( obj_BCBearerContextSetupFailure->gNBCUUPMBSE1APID_isset == 1)
	{
	}

	if( obj_BCBearerContextSetupFailure->cause_isset == 1)
	{
	}

	if( obj_BCBearerContextSetupFailure->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_BCBearerContextSetupFailure( obj_BCBearerContextSetupFailure);
}


void __si_e1ap__Handle_BCBearerContextModificationRequest_Prototype( SI_E1AP_DT_PDU_BCBearerContextModificationRequest * obj_BCBearerContextModificationRequest, SI_E1APNode * node)
{
	if( obj_BCBearerContextModificationRequest->gNBCUCPMBSE1APID_isset == 1)
	{
	}

	if( obj_BCBearerContextModificationRequest->gNBCUUPMBSE1APID_isset == 1)
	{
	}

	if( obj_BCBearerContextModificationRequest->bCBearerContextToModify_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_BCBearerContextModificationRequest( obj_BCBearerContextModificationRequest);
}


void __si_e1ap__Handle_BCBearerContextModificationResponse_Prototype( SI_E1AP_DT_PDU_BCBearerContextModificationResponse * obj_BCBearerContextModificationResponse, SI_E1APNode * node)
{
	if( obj_BCBearerContextModificationResponse->gNBCUCPMBSE1APID_isset == 1)
	{
	}

	if( obj_BCBearerContextModificationResponse->gNBCUUPMBSE1APID_isset == 1)
	{
	}

	if( obj_BCBearerContextModificationResponse->bCBearerContextToModifyResponse_isset == 1)
	{
	}

	if( obj_BCBearerContextModificationResponse->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_BCBearerContextModificationResponse( obj_BCBearerContextModificationResponse);
}


void __si_e1ap__Handle_BCBearerContextModificationFailure_Prototype( SI_E1AP_DT_PDU_BCBearerContextModificationFailure * obj_BCBearerContextModificationFailure, SI_E1APNode * node)
{
	if( obj_BCBearerContextModificationFailure->gNBCUCPMBSE1APID_isset == 1)
	{
	}

	if( obj_BCBearerContextModificationFailure->gNBCUUPMBSE1APID_isset == 1)
	{
	}

	if( obj_BCBearerContextModificationFailure->cause_isset == 1)
	{
	}

	if( obj_BCBearerContextModificationFailure->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_BCBearerContextModificationFailure( obj_BCBearerContextModificationFailure);
}


void __si_e1ap__Handle_BCBearerContextModificationRequired_Prototype( SI_E1AP_DT_PDU_BCBearerContextModificationRequired * obj_BCBearerContextModificationRequired, SI_E1APNode * node)
{
	if( obj_BCBearerContextModificationRequired->gNBCUCPMBSE1APID_isset == 1)
	{
	}

	if( obj_BCBearerContextModificationRequired->gNBCUUPMBSE1APID_isset == 1)
	{
	}

	if( obj_BCBearerContextModificationRequired->bCBearerContextToModifyRequired_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_BCBearerContextModificationRequired( obj_BCBearerContextModificationRequired);
}


void __si_e1ap__Handle_BCBearerContextModificationConfirm_Prototype( SI_E1AP_DT_PDU_BCBearerContextModificationConfirm * obj_BCBearerContextModificationConfirm, SI_E1APNode * node)
{
	if( obj_BCBearerContextModificationConfirm->gNBCUCPMBSE1APID_isset == 1)
	{
	}

	if( obj_BCBearerContextModificationConfirm->gNBCUUPMBSE1APID_isset == 1)
	{
	}

	if( obj_BCBearerContextModificationConfirm->bCBearerContextToModifyConfirm_isset == 1)
	{
	}

	if( obj_BCBearerContextModificationConfirm->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_BCBearerContextModificationConfirm( obj_BCBearerContextModificationConfirm);
}


void __si_e1ap__Handle_BCBearerContextReleaseCommand_Prototype( SI_E1AP_DT_PDU_BCBearerContextReleaseCommand * obj_BCBearerContextReleaseCommand, SI_E1APNode * node)
{
	if( obj_BCBearerContextReleaseCommand->gNBCUCPMBSE1APID_isset == 1)
	{
	}

	if( obj_BCBearerContextReleaseCommand->gNBCUUPMBSE1APID_isset == 1)
	{
	}

	if( obj_BCBearerContextReleaseCommand->cause_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_BCBearerContextReleaseCommand( obj_BCBearerContextReleaseCommand);
}


void __si_e1ap__Handle_BCBearerContextReleaseComplete_Prototype( SI_E1AP_DT_PDU_BCBearerContextReleaseComplete * obj_BCBearerContextReleaseComplete, SI_E1APNode * node)
{
	if( obj_BCBearerContextReleaseComplete->gNBCUCPMBSE1APID_isset == 1)
	{
	}

	if( obj_BCBearerContextReleaseComplete->gNBCUUPMBSE1APID_isset == 1)
	{
	}

	if( obj_BCBearerContextReleaseComplete->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_BCBearerContextReleaseComplete( obj_BCBearerContextReleaseComplete);
}


void __si_e1ap__Handle_BCBearerContextReleaseRequest_Prototype( SI_E1AP_DT_PDU_BCBearerContextReleaseRequest * obj_BCBearerContextReleaseRequest, SI_E1APNode * node)
{
	if( obj_BCBearerContextReleaseRequest->gNBCUCPMBSE1APID_isset == 1)
	{
	}

	if( obj_BCBearerContextReleaseRequest->gNBCUUPMBSE1APID_isset == 1)
	{
	}

	if( obj_BCBearerContextReleaseRequest->cause_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_BCBearerContextReleaseRequest( obj_BCBearerContextReleaseRequest);
}


void __si_e1ap__Handle_MCBearerContextSetupRequest_Prototype( SI_E1AP_DT_PDU_MCBearerContextSetupRequest * obj_MCBearerContextSetupRequest, SI_E1APNode * node)
{
	if( obj_MCBearerContextSetupRequest->gNBCUCPMBSE1APID_isset == 1)
	{
	}

	if( obj_MCBearerContextSetupRequest->globalMBSSessionID_isset == 1)
	{
	}

	if( obj_MCBearerContextSetupRequest->mCBearerContextToSetup_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_MCBearerContextSetupRequest( obj_MCBearerContextSetupRequest);
}


void __si_e1ap__Handle_MCBearerContextSetupResponse_Prototype( SI_E1AP_DT_PDU_MCBearerContextSetupResponse * obj_MCBearerContextSetupResponse, SI_E1APNode * node)
{
	if( obj_MCBearerContextSetupResponse->gNBCUCPMBSE1APID_isset == 1)
	{
	}

	if( obj_MCBearerContextSetupResponse->gNBCUUPMBSE1APID_isset == 1)
	{
	}

	if( obj_MCBearerContextSetupResponse->mCBearerContextToSetupResponse_isset == 1)
	{
	}

	if( obj_MCBearerContextSetupResponse->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_MCBearerContextSetupResponse( obj_MCBearerContextSetupResponse);
}


void __si_e1ap__Handle_MCBearerContextSetupFailure_Prototype( SI_E1AP_DT_PDU_MCBearerContextSetupFailure * obj_MCBearerContextSetupFailure, SI_E1APNode * node)
{
	if( obj_MCBearerContextSetupFailure->gNBCUCPMBSE1APID_isset == 1)
	{
	}

	if( obj_MCBearerContextSetupFailure->gNBCUUPMBSE1APID_isset == 1)
	{
	}

	if( obj_MCBearerContextSetupFailure->cause_isset == 1)
	{
	}

	if( obj_MCBearerContextSetupFailure->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_MCBearerContextSetupFailure( obj_MCBearerContextSetupFailure);
}


void __si_e1ap__Handle_MCBearerContextModificationRequest_Prototype( SI_E1AP_DT_PDU_MCBearerContextModificationRequest * obj_MCBearerContextModificationRequest, SI_E1APNode * node)
{
	if( obj_MCBearerContextModificationRequest->gNBCUCPMBSE1APID_isset == 1)
	{
	}

	if( obj_MCBearerContextModificationRequest->gNBCUUPMBSE1APID_isset == 1)
	{
	}

	if( obj_MCBearerContextModificationRequest->mCBearerContextToModify_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_MCBearerContextModificationRequest( obj_MCBearerContextModificationRequest);
}


void __si_e1ap__Handle_MCBearerContextModificationResponse_Prototype( SI_E1AP_DT_PDU_MCBearerContextModificationResponse * obj_MCBearerContextModificationResponse, SI_E1APNode * node)
{
	if( obj_MCBearerContextModificationResponse->gNBCUCPMBSE1APID_isset == 1)
	{
	}

	if( obj_MCBearerContextModificationResponse->gNBCUUPMBSE1APID_isset == 1)
	{
	}

	if( obj_MCBearerContextModificationResponse->mCBearerContextToModifyResponse_isset == 1)
	{
	}

	if( obj_MCBearerContextModificationResponse->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_MCBearerContextModificationResponse( obj_MCBearerContextModificationResponse);
}


void __si_e1ap__Handle_MCBearerContextModificationFailure_Prototype( SI_E1AP_DT_PDU_MCBearerContextModificationFailure * obj_MCBearerContextModificationFailure, SI_E1APNode * node)
{
	if( obj_MCBearerContextModificationFailure->gNBCUCPMBSE1APID_isset == 1)
	{
	}

	if( obj_MCBearerContextModificationFailure->gNBCUUPMBSE1APID_isset == 1)
	{
	}

	if( obj_MCBearerContextModificationFailure->mBSMulticastF1UContextDescriptor_isset == 1)
	{
	}

	if( obj_MCBearerContextModificationFailure->cause_isset == 1)
	{
	}

	if( obj_MCBearerContextModificationFailure->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_MCBearerContextModificationFailure( obj_MCBearerContextModificationFailure);
}


void __si_e1ap__Handle_MCBearerContextModificationRequired_Prototype( SI_E1AP_DT_PDU_MCBearerContextModificationRequired * obj_MCBearerContextModificationRequired, SI_E1APNode * node)
{
	if( obj_MCBearerContextModificationRequired->gNBCUCPMBSE1APID_isset == 1)
	{
	}

	if( obj_MCBearerContextModificationRequired->gNBCUUPMBSE1APID_isset == 1)
	{
	}

	if( obj_MCBearerContextModificationRequired->mCBearerContextToModifyRequired_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_MCBearerContextModificationRequired( obj_MCBearerContextModificationRequired);
}


void __si_e1ap__Handle_MCBearerContextModificationConfirm_Prototype( SI_E1AP_DT_PDU_MCBearerContextModificationConfirm * obj_MCBearerContextModificationConfirm, SI_E1APNode * node)
{
	if( obj_MCBearerContextModificationConfirm->gNBCUCPMBSE1APID_isset == 1)
	{
	}

	if( obj_MCBearerContextModificationConfirm->gNBCUUPMBSE1APID_isset == 1)
	{
	}

	if( obj_MCBearerContextModificationConfirm->mCBearerContextToModifyConfirm_isset == 1)
	{
	}

	if( obj_MCBearerContextModificationConfirm->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_MCBearerContextModificationConfirm( obj_MCBearerContextModificationConfirm);
}


void __si_e1ap__Handle_MCBearerNotification_Prototype( SI_E1AP_DT_PDU_MCBearerNotification * obj_MCBearerNotification, SI_E1APNode * node)
{
	if( obj_MCBearerNotification->gNBCUCPMBSE1APID_isset == 1)
	{
	}

	if( obj_MCBearerNotification->gNBCUUPMBSE1APID_isset == 1)
	{
	}

	if( obj_MCBearerNotification->mBSSessionResourceNotification_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_MCBearerNotification( obj_MCBearerNotification);
}


void __si_e1ap__Handle_MCBearerContextReleaseCommand_Prototype( SI_E1AP_DT_PDU_MCBearerContextReleaseCommand * obj_MCBearerContextReleaseCommand, SI_E1APNode * node)
{
	if( obj_MCBearerContextReleaseCommand->gNBCUCPMBSE1APID_isset == 1)
	{
	}

	if( obj_MCBearerContextReleaseCommand->gNBCUUPMBSE1APID_isset == 1)
	{
	}

	if( obj_MCBearerContextReleaseCommand->cause_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_MCBearerContextReleaseCommand( obj_MCBearerContextReleaseCommand);
}


void __si_e1ap__Handle_MCBearerContextReleaseComplete_Prototype( SI_E1AP_DT_PDU_MCBearerContextReleaseComplete * obj_MCBearerContextReleaseComplete, SI_E1APNode * node)
{
	if( obj_MCBearerContextReleaseComplete->gNBCUCPMBSE1APID_isset == 1)
	{
	}

	if( obj_MCBearerContextReleaseComplete->gNBCUUPMBSE1APID_isset == 1)
	{
	}

	if( obj_MCBearerContextReleaseComplete->criticalityDiagnostics_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_MCBearerContextReleaseComplete( obj_MCBearerContextReleaseComplete);
}


void __si_e1ap__Handle_MCBearerContextReleaseRequest_Prototype( SI_E1AP_DT_PDU_MCBearerContextReleaseRequest * obj_MCBearerContextReleaseRequest, SI_E1APNode * node)
{
	if( obj_MCBearerContextReleaseRequest->gNBCUCPMBSE1APID_isset == 1)
	{
	}

	if( obj_MCBearerContextReleaseRequest->gNBCUUPMBSE1APID_isset == 1)
	{
	}

	if( obj_MCBearerContextReleaseRequest->cause_isset == 1)
	{
	}

	__si_e1ap_memfree_pdu_MCBearerContextReleaseRequest( obj_MCBearerContextReleaseRequest);
}


