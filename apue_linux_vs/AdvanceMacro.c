#include "apue.h"

/*
	�߼����÷���
	1. ���а���������ţ�#��##.
	2. �궨����do{ }while(0)
*/

// #
#define put(x) printf("%s \n",""#x" string")
#define type(t,n) t t_##n

void AdvanceMacroFun() {

	put(justdoit);
}