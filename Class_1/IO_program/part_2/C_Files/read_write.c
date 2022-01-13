/*先包含OPEN、CLOSE函数所需要的头文件*/
#include "SysCtrl.h"

/*Linux下，test.txt代表同级目录，./test.txt代表上级目录，../test.txt代表上上级目录*/
int main(int argc, char **argv)
{
	int fd1, fd2;
	char buf[512];
	int read_size;

	if(argc != 3)
	{
		printf("请输入两个参数！\n");
		return -1;
	}

	
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_WRONLY | O_CREAT, 0666);
	

	if(fd1 == -1 || fd2 == -1)
	{
		printf("Open file error! \n");
		close(fd1);
		close(fd2);
		return -1;
	}
	else
	{
		for(;;)
		{
			read_size = read(fd1, buf, 512);

			if(!read_size)
               	 	{
				break;
                	}
                	else
                	{
                        	write(fd2, buf, read_size);
                	}
		}

	}
	
		

	close(fd1);
	close(fd2);
	return 0;
}
