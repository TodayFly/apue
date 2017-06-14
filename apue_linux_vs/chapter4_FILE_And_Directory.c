#include "apue.h"
#include <fcntl.h>
#include <unistd.h>
static struct stat fileinfo;
static struct timespec timeinfo; // s and ns

/* Figure 4.3 Print type of file for each command-line argument */
void printFileInfo(int argc, char * argv[]) {
	int i;
	struct stat buf;
	char * ptr;
	for (i = 1; i < argc; i++) {
		//printf("%s: ", argv[i]);
		if (lstat(argv[i], &buf) < 0) {
			err_ret("lstat error");
			continue;
		}
		if (S_ISREG(buf.st_mode))
			ptr = "regular file";
		else if (S_ISDIR(buf.st_mode))
			ptr = "directory";
		else if (S_ISLNK(buf.st_mode))
			ptr = "symbolic link";
		else if (S_ISSOCK(buf.st_mode))
			ptr = "socket";
		else
			ptr = "other ";
		printf("%s is a %s\n", argv[i],ptr);
		if (S_ISUID & buf.st_mode)
			printf("set set-user-ID\n");
		else
			printf("not set set-user-ID\n");
	}
	exit(0);
}
/* Figure 4.16 Open a file and then unlink it  */
void myunlink()
{
	int fd;
	if ((fd = open("newfile", O_RDWR | O_CREAT)) < 0)	err_sys("open error");
	system("ls -l newfile");
	if (unlink("newfile") < 0)	err_sys("unlink error");	// 程序结束前不会删除
	printf("file unlinked\n");
	sleep(10);
	system("ls -l newfile");
}

/* symbolic links */
void mysymboliclink() {/*open function follows a symbolic link*/
	int fd;
	if ((fd = symlink("nofile", "symlink_file")) < 0)
		err_sys("symlink error");
	close(fd);
}
/* 截断文件，保持访问时间和修改时间不变 */
void fileTime() {
	int i, fd;
	char * fn = "testfile";
	struct stat buf;
	struct timespec times[2];
	if (stat(fn, &buf) < 0) err_ret("%s: stat error", fn);
	if ((fd = open(fn, O_RDWR | O_TRUNC)) < 0) err_ret("%s: open error", fn);

	times[0] = buf.st_atim; times[1] = buf.st_mtim;
	if (futimens(fd, times) < 0) /* reset times */
		err_ret("%s: futimens error", fn);
	close(fd);
}

/* 切换工作目录 */
void cdpwd() {
	char buf[4096];
	char *ptr;
	size_t size;
	ptr = path_alloc(&size);

	if (chdir("testdir") < 0) err_sys("chdir failed");

	if (getcwd(buf, 4096) == NULL) err_sys("getcwd failed ");
	if (getcwd(ptr, size) == NULL) err_sys("getcwd failed ");

	printf("cwd = %s\ncwd = %s\n", buf,ptr);
	exit(0);
}
int chapter4(int argc, char * argv[]) {
	//fileTime();
	cdpwd();
	exit(0);
}