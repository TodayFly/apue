#include "apue.h"


static void CommonExitFun() {
	printf("Process exit! \n");
}

/* 环境变量 */
void envnFun() {

}

/* fork 父/子进程变量 */
int globvar = 6;
void forkfun() {
	int var = 88;
	pid_t pid;
	char buf[] = "a write to stdout \n";
	if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
		err_sys("write error");
	printf("before fork\n");
	if ((pid = fork()) < 0) err_sys("fork error");
	else if (pid == 0) {/* child */
		globvar = -globvar;
		var = -var;
	}
	else sleep(3);/* parent */
	printf("ppid = %ld pid = %ld, glob = %d, var = %d\n", (long)getppid(),(long)getpid(), globvar,
		var);
	exit(0);
}



int ProcessFun(int argc, char * argv[]) {
	if (atexit(CommonExitFun) != 0) err_sys("atexit error");
	forkfun();
}