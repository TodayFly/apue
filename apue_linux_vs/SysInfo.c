#include "apue.h"	//  Date File           Structure		function
#include <pwd.h>	//  /etc/passwd			passwd			getpwnam, getpwuid
#include <netdb.h>  //  /etc/hosts			hostent			getnameinfo, getaddrinfo
					//  /etc/networks		netent			getnetbyname, getnetbyaddr
					//  /etc/protocols		protoent		getprotobyname, getprotobynumber
					//  /etc/services		servent			getservbyname, getservbyport
struct passwd *pw;

#include <sys/utsname.h>
struct utsname sysinfo;

#include <time.h>


void printsysinfo() {
	int i;
	char name[100];
	if ((i = uname(&sysinfo)) < 0) err_sys("uname error");
	printf("sysname = %s\nrelease = %s\nversion =  %s\nmachine = %s\n", sysinfo.sysname, sysinfo.release
		, sysinfo.version, sysinfo.machine);
	if ((i = gethostname(name, sizeof(name))) < 0) err_sys("gethostname error");
	printf("host = %s\n", name);

	time_t t;
	struct tm *tmp;
	char buf[65];

	time(&t);
	tmp = localtime(&t);
	if (strftime(buf, 64, "time and date: %r, %a %b %d, %Y", tmp) == 0)
		printf("buffer length 64 is too small\n");
	else
		printf("%s\n", buf);
}

void SysInfoFun() {
	printsysinfo();
}