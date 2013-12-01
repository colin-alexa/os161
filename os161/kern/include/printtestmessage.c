#include <test.h>

int printtestmessage(int c, char** args){
	for (int i =0; i < c; i++){
		kprintf(*(args+i));
	}
	return 0;
}
