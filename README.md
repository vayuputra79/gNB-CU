# gNB-CU
3GPP 5G - gNodeB Central Unit - Disaggregated RAN 

Central Unit (CU): It is a logical node that includes the gNB functions like Transfer of user data, Mobility control, Radio access network sharing, Positioning, Session Management etc.,


- **3GPP TS 38.401**:  NG-RAN Architecture description
- **3GPP TS 38.473**:  F1 Application Protocol (F1AP)
- **3GPP TS 38.463**:  E1 Application Protocol (E1AP) 
- **3GPP TS 38.413**:  NG Application Protocol (NGAP)
- **3GPP TS 38.423**:  Xn Application Protocol (XnAP)



![plot](https://github.com/Anil79/gNB-CU/blob/main/ng_ran_architecture.png)

**Architecture for separation of gNB-CU-CP and gNB-CU-UP**

![plot](https://github.com/Anil79/gNB-CU/blob/main/gnb_cu.png)

[3GPP TS 138 401]
https://www.etsi.org/deliver/etsi_ts/138400_138499/138401/16.03.00_60/ts_138401v160300p.pdf

- A gNB may consist of a gNB-CU-CP, multiple gNB-CU-UPs and multiple gNB-DUs; 
- The gNB-CU-CP is connected to the gNB-DU through the F1-C interface; 
- The gNB-CU-UP is connected to the gNB-DU through the F1-U interface; 
- The gNB-CU-UP is connected to the gNB-CU-CP through the E1 interface; 
- One gNB-DU is connected to only one gNB-CU-CP; 
- One gNB-CU-UP is connected to only one gNB-CU-CP; 
- One gNB-DU can be connected to multiple gNB-CU-UPs under the control of the same gNB-CU-CP; 
- One gNB-CU-UP can be connected to multiple DUs under the control of the same gNB-CU-CP; 

NOTE 1: For resiliency, a gNB-DU and/or a gNB-CU-UP may be connected to multiple gNB-CU-CPs by appropriate implementation. 

NOTE 2: The connectivity between a gNB-CU-UP and a gNB-DU is established by the gNB-CU-CP using Bearer Context Management functions. 

NOTE 3: The gNB-CU-CP selects the appropriate gNB-CU-UP(s) for the requested services for the UE. In case of multiple CU-UPs they belong to same security domain as defined in TS 33.210 [18]. 

NOTE 4: Data forwarding between gNB-CU-UPs during intra-gNB-CU-CP handover within a gNB may be supported by Xn-U.

## Interfaces

- **F1AP**
- **E1AP**
- **NGAP**
- **E2AP**
- **XnAP**
- **X2AP**
- **E2AP**
- **W1AP**



## F1 Interface  

F1 interface connects the gNB-CU to the gNB-DU, enabling communication and data transfer between

**F1-C (Control Plane)**  
- Handles signaling and control plane functions between the gNB-CU-CP (Central Unit Control Plane) and the gNB-DU.
- Uses SCTP (Stream Control Transmission Protocol) over IP for the transport layer and F1AP (F1 Application Protocol) for signaling. 

![plot](https://github.com/Anil79/gNB-CU/blob/main/f1_c_ps.png)

**F1-U (User Plane)**  
- Facilitates the transfer of user data between the gNB-CU-UP (Central Unit User Plane) and the gNB-DU. 
- Uses UDP (User Datagram Protocol) and GTP-U (GPRS Tunneling Protocol - User Plane) over IP for the transport layer.

![plot](https://github.com/Anil79/gNB-CU/blob/main/f1_u_ps.png)


## E1 Interface
- **3GPP TS 38.460**:  E1 general aspects and principles

**TEIDs allocation**
- The gNB-CU-UP is responsible for the allocation of the F1-U UL GTP TEID for each data radio bearer. 
- The gNB-CU-UP is responsible for the allocation of the S1-U DL GTP TEID for each E-RAB and the NG-U DL GTP TEID for each PDU Session. 
- The gNB-CU-UP is responsible for the allocation of the X2-U DL/UL GTP TEID or the Xn-U DL/UL GTP TEID for each data radio bearer.

**gNB-CU-UP will uses F1-U Protocol Stack**




# Disaggregated RAN Architecture

![plot](https://github.com/Anil79/gNB-CU/blob/main/gNB_CU_DIA.png)











