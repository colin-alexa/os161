#include <types.h>
#include <lib.h>
#include <test.h>
#include <thread.h>
#include <current.h>

static
void thread_function(void *ptr, unsigned long value){
	char* name = ptr;
	kprintf(name);
	//The above is the name passed in, the below is using the "curthread" 
	//global defined in current.h
	kprintf(curthread->t_name);
}

int mytest(int nargs, char **args){
	kprintf("My test works!");
	for (int i = 0; i < nargs; i++){
		kprintf(args[i]);
		kprintf("\n");
	}
	//thread_fork can take a null process; it defaults to the current one
	thread_fork("test thread", NULL, thread_function, "test thread", nargs);
	return 0; //Menu thinks there's an error without a 0 return
}

