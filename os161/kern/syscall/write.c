#include <types.h>
#include <kern/errno.h>
#include <lib.h>
#include <limits.h>
#include <syscall.h>

/////////////////////////////
////
//// Because write returns the number of bytes written, all
////  bad returns are the ordinary MAGNITUDE for the error,
////  but are always NEGATIVE
////


int sys_write(int filehandle, const void *buf, size_t size){
	if (size > KBUF_MAX){
	    return -(EINVAL);
  	}
	if (filehandle == 1 /* STDOUT_FILENO is undefined in kernel space, but it's probably going to remain '1' forever hehehe */){
		 kprintf(buf);
	 	 return size;
  	}
	    			 	   	   
  	return -(EBADF);
}
