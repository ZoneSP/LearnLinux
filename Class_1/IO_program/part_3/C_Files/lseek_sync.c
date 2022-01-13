/*先包含OPEN、CLOSE函数所需要的头文件*/
#include "SysCtrl.h"

/*Linux下，test.txt代表同级目录，./test.txt代表上级目录，../test.txt代表上上级目录*/
int main(int argc, char **argv)
{
	int fd1;

	if(argc != 2)
	{
		printf("请传入一个参数！\n");
		return -1;
	}

	fd1 = open(argv[1], O_RDWR | O_CREAT, 0666);

	write(fd1, "123", 3);

	lseek(fd1, 10, SEEK_SET);

	write(fd1, "abc", 3);

	close(fd1);

	return 0;
}
