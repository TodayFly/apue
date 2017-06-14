#include "apue.h"

/*
	高级宏用法。
	1. 宏中包含特殊符号：#、##.
	2. 宏定义用do{ }while(0)
*/

// #
#define put(x) printf("%s \n",""#x" string")
#define type(t,n) t t_##n

void AdvanceMacroFun() {

	put(justdoit);
}