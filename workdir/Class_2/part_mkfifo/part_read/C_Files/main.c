#include "Sysctrl.h"

/* 函数名称：memset()  void *memset(void *str, int c, size_t n);
 * 函数功能：复制字符C到str指向字符串前n个字符
 * 函数示例：str[] = "ABCDEFG"，memset(str, '$', 4)   ->    "$$$$EFG"
 */

#define MAX_DATA_LEN   256

#define mkfifo_name   "/tmp/mkfifo"

int main(void)
{
	int fd;
	char buff[MAX_DATA_LEN];

	/*检查mkfifo是否存在，不存在就创建，存在就接着往下走*/
	if(access(mkfifo_name, F_OK) == -1)
	{
		/*文件不存在，创造mkfifo文件*/
		if(mkfifo(mkfifo_name, 0666) == -1)
		{
			printf("创造有名管道失败！\n");
			exit(1);
		}
		else
		{
			printf("创造有名管道成功！\n");
		}
	}


	fd = open(mkfifo_name, O_RDONLY);

	if(fd == -1)
	{
		printf("打开有名管道失败！\n");
		exit(1);
	}
	else
	{
		/*循环读取有名管道中的内容*/
		memset(buff, 0, sizeof(buff));
		for(;;)
		{
			if(read(fd, buff, MAX_DATA_LEN) > 0)
			{
				printf("Read %s from FIFO\n",buff);
			}
		}
	}

	close(fd);
	exit(0);
}
