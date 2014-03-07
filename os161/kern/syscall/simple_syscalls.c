//The file for simple custom system calls, like our hello world system 
//call

#include <types.h>
#include <copyinout.h>
#include <syscall.h>
#include <lib.h>

int sys_helloworld(void){
	kprintf("HELLO world\n");
	return 0;
}

void sys__exit(int code){
  thread_exit();
}

int sys_printint(int tp){
  int len = 0;
  int neg = 0;
  

  // kprintf("tp = %d\n", tp);

  if (tp < 0) { 
	  tp = -tp;
	  neg = 1;
	  ++len;
  }

  //Changed this to divide by 10, because subtraction
  //just gives us the value, not the length
  int tmp;
  for (tmp = tp; tmp > 0; tmp/=10){
    ++len;
  }

  //kprintf("len = %d; attempting kmalloc\n", len);
  //++len; //Make room for that null terminating char
  char istr[len+2];
  istr[len] = '\n';
  istr[len+1] = '\0';
  
  if (!istr)
	  panic("memory allocation failed");

 // kprintf("attempting sign storage\n");
  tmp = 1;
  if (neg){
	  istr[0]='-'; 
  }
  // kprintf("constructing string\n");
  while( tp > 0 ){
   istr[len-tmp] = '0' + (tp % 10);
	tp = tp / 10;
	++tmp;
  }
  //istr[++len] = 0;

 
 // kprintf("printing string\n");
  return kprintf(istr);
}

int sys_printstring(char *string, size_t len){
	   char result[len];
		size_t real_len;
		copyinstr(string, result, len, &real_len);
		kprintf(result);
		return real_len;
}
