#include <types.h>
#include <lib.h>
#include <thread.h>
#include <synch.h>
#include <test.h>

static
void thread_function(void *ptr, unsigned long value){
	(void)value;
	kprintf("Thread go");
	char* cp = ptr;
	*cp+='0';
	//Doesn't seem to be doing exactly what I want, but hard to debug
	//until printf has proper locks
	kprintf(cp);	
}

int mythreadtest(int nargs, char **args){
	kprintf("Running my thread test");
	(void)nargs; //Avoid unused parameter warning
	//args[0] is name of calling program
	int n = (*args[1])-'0';
	//The bottom loop doesn't seem to be running, or there's
	//something wrong with the way we're launching threads
	for (int i = 0; i < n; ++i){
		thread_fork("thread test thread", NULL, thread_function, &i, 1);
	}

	return 0;
}
