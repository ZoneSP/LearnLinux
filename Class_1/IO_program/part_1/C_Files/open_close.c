/*先包含OPEN、CLOSE函数所需要的头文件*/
#include "SysCtrl.h"

/*Linux下，test.txt代表同级目录，./test.txt代表上级目录，../test.txt代表上上级目录*/
int main(int argc, char **argv)
{
	int fd1, fd2;

	if(argc != 3)
	{
		printf("请输入两个参数！\n");
		return -1;
	}

	
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY | O_CREAT, 0666);
	

	if(fd1 == -1 || fd2 == -1)
	{
		printf("Open file error! \n");
	}
	else
	{
		printf("Now return fd is: %d\n",fd1);
	}

	close(fd1);
	close(fd2);
	return 0;
}
