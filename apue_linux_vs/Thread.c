#include "apue.h"

static void CommonExitFun() {
	printf("Program exit! \n");
}

void myThreadFun(int argc, char *argv[]) {
	if (atexit(CommonExitFun) != 0) err_sys("atexit error");


}