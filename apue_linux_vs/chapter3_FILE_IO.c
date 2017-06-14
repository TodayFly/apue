#include "apue.h"
#include <fcntl.h>
#include "CommonHeader.h"
int  myio(int argc, char * argv[]){
	int n=0;
	put("test for open function");
	int fd_dir;
	if ((fd_dir = open("testdir", O_DIRECTORY)) < 0)
		err_sys("open dir error");
	printf("open dir succeed, fd_dir = %d\n", fd_dir);
	int fd_file;
	if ((fd_file=openat(fd_dir, "test.txt", O_RDWR | O_APPEND)) < 0)
		err_sys("open error");
	printf("open file succeed, fd_file = %d\n", fd_file);
	printf("now, close fd_file and fd_dir. When a process terminates, all of its open files are closed automatically \n");
	close(fd_file);
	close(fd_dir);
	
	put("open function to create a new file. mode is not use");
	printf("using lseek function \n");
	if ((fd_file = open("newfile", O_RDWR | O_CREAT | O_APPEND)) < 0)
		err_sys("open err");
	off_t currpos;
	if ((currpos = lseek(fd_file, 0, SEEK_CUR)) == -1) err_sys("cannot seek");
	printf("current offset of newfile = %d\n", currpos);
	if ((currpos = lseek(fd_file, 100, SEEK_SET)) == -1) { err_sys("cannot seek"); }
	if ((n=write(fd_file, "a new line", 10)) != 10)  err_sys("write error. %d",n);
	printf("Create a hole file. current offset = %d\n", currpos);
	put("read function");
	close(fd_file);

	put("creat function to create a new file");
	printf("Returns: file descriptor opened for write - only if OK, -1 on error\n");
	if ((fd_file = creat("creat_new_file", FILE_MODE)) < 0)
		err_sys("creat err");
	close(fd_file);
	exit(0);
}