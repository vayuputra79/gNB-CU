all:
	gcc -g3 -o gNB-CU-CP gNB-CU-CP.c gNB-CU-CP_F1AP.c gNB-CU-CP_E1AP.c gNB-CU-CP_Context.c -L. libE1AP_18_3.so libF1AP_18_4.so libsicore.so -I./ -lpthread -I../jansson-2.13/src/ -ljansson -lsctp -DSCTP_SUPPORT -Wl,-rpath . 
	gcc -g3 -o F1AP_Client F1AP_Client.c -L. libF1AP_18_4.so libsicore.so -I./ -lpthread -lsctp -Wl,-rpath .
	