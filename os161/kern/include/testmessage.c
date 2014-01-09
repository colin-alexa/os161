#include <test.h>
#include <current.h>

void test_thread(void*, unsigned long);

void test_thread(void * ptr, unsigned long val){
	char *name = ptr;
	kprintf(name);
	kprintf(curthread->t_name);
}

int testmessage(int c, char** args){
	for (int i=1; i<c; i++){
		kprintf(args[i]);
		kprintf(" ");
	}
	kprintf("\n");
	thread_fork("test thread", NULL, test_thread, "thread message", c);
	return 0;
}

