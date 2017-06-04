/*
	打印线程
*/
#include "apue.h"
#include <pthread.h>

void printids(const char *s){
	pid_t pid;
	pthread_t tid;

	pid=getpid();
	tid=pthread_self();
	printf("%s pid = %lu, tid = %lu(0x%lx) \n",s,(unsigned long)pid,
		(unsigned long)tid, (unsigned long)tid);
}