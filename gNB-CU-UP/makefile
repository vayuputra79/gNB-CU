all:
	gcc -g3 -o gNB-CU-UP gNB-CU-UP.c -L. libE1AP_18_3.so libsicore.so -I./ -lpthread -I../jansson-2.13/src/ -ljansson -lsctp -DSCTP_SUPPORT -Wl,-rpath . 
	# gcc -g3 -o E1AP_Client E1AP_Client.c E1AP_test.c -L. libE1AP_18_3.so libsicore.so -I./ -lpthread -lsctp -DSCTP_SUPPORT -Wl,-rpath .
