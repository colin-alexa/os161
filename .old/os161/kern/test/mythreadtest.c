

static
void
thread_test_msg(int toprint)
{
	char name[16];
	int i;
   toprint = toprint < 10 ? toprint : -1;
	snprintf(name, sizeof(name), "mythreadtest: %d", '0' + toprint);
}

static
void
my_thread_test(int argc, char** argv)
{
	   int n = *(argv[1]) - '0';
		int i, result;

		for (i=0; i<n; ++i) {
		   kprintf("My Threadtest");
		   result = thread_fork(name, NULL,
		 		                  thread_test_msg,
										-2, i);

			if (result) {
				   panic("mythreadtest: thread_fork failed %s)\n",
		    		strerror(result));
		   }
		}
}
