#include <sys/types.h>
#include <unistd.h>
#include <err.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <err.h>



int main(){
  helloworld();

  for (int i=-10; i < 10000; i += 700){
    printint(i);
	 printstring("cat", 2);
  }
}
