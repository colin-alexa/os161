#include <types.h>
#include <lib.h>
#include <thread.h>
#include <synch.h>
#include <test.h>

static struct lock * testLock;

static
void lt_thread_function(void *ptr, unsigned long value){
	(void)value;
   // kprintf("nolocks");
  lock_acquire(testLock);
	kprintf("Lock test thread go ");
	char *cp = (char *)ptr;
	*cp += '0';
	//Doesn't seem to be doing exactly what I want, but hard to debug
	//until printf has proper locks
	kprintf(cp);
	kprintf("\n");
	*cp -= '0'; // undoing the addition from earlier
   *cp += 1;
  lock_release(testLock);
}

int mylocktest(int nargs, char **args){
	kprintf("Running my lock test");
	(void)nargs; //Avoid unused parameter warning
	//args[0] is name of calling program

   testLock = lock_create("testLock"); // We are leaking this memory; 
	                                    // there is no corresponding lock_delete


	int n = (*args[1])-'0';
	int * j;
	*j = 0;
	//The bottom loop doesn't seem to be running, or there's
	//something wrong with the way we're launching threads
	for (int i = 0; i < n; ++i){
		thread_fork("lock test thread", NULL, lt_thread_function, j, 1);
	}

	return 0;
}
