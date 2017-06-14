#include "apue.h"
int chapter4(int argc, char * argv[]);
void SysInfoFun();
void myThreadFun(int argc, char *argv[]);
int ProcessFun(int argc, char * argv[]);
void AdvanceMacroFun();
int main(int argc, char * argv[])
{
	//chapter4(argc,argv);
	//SysInfoFun();
	//myThreadFun(argc, argv);
	ProcessFun(argc, argv);
	//AdvanceMacroFun();
	return 0;
}