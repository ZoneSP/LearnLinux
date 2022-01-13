#include "Sysctrl.h"

/* 函数名称：memset()  void *memset(void *str, int c, size_t n);
 * 函数功能：复制字符C到str指向字符串前n个字符
 * 函数示例：str[] = "ABCDEFG"，memset(str, '$', 4)   ->    "$$$$EFG"
 */

#define MAX_DATA_LEN   256

#define mkfifo_name   "/tmp/mkfifo"

int main(int argc, char *argv[])
{
	int fd;
	char buff[MAX_DATA_LEN];
	
	/*检测输入参数个数是否正确*/
	if(argc != 2)
	{
		printf("请输入一个参数！\n");
		exit(1);
	}

	sscanf(argv[1], "%s", buff);  //将输入的数据放置进buff


	/*检查mkfifo是否存在，不存在就创建，存在就接着往下走*/
	if(access(mkfifo_name, F_OK) == -1)
	{
		/*文件不存在，报错返回*/
		printf("有名管道不存在！\n");
		exit(1);
	}


	fd = open(mkfifo_name, O_WRONLY);

	if(fd == -1)
	{
		printf("打开有名管道失败！\n");
		exit(1);
	}
	else
	{
		if(write(fd, buff, sizeof(buff)) > 0)
		{
			printf("Write %s in FIFO\n",buff);
		}
	}

	close(fd);
	exit(0);
}
