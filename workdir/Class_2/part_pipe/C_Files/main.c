#include "Sysctrl.h"

/* 函数名称：memset()  void *memset(void *str, int c, size_t n);
 * 函数功能：复制字符C到str指向字符串前n个字符
 * 函数示例：str[] = "ABCDEFG"，memset(str, '$', 4)   ->    "$$$$EFG"
 */

#define MAX_DATA_LEN   256

int main(void)
{
	pid_t pid;
	int pipe_fd[2];
	int status;
	char buf[MAX_DATA_LEN];
	const char data[] = "Pipe Test Program";
	int real_read, real_write;
	
	memset((void*)buf, 0, sizeof(buf));  //buf[256]全部填0

	/*创建管道*/
	if(pipe(pipe_fd) < 0)
	{
		printf("pipe create error\n");
		exit(1);
	}

	/*创建子进程*/
	if((pid = fork()) == 0)
	{
		/*子进程关闭写描述*/
		close(pipe_fd[1]);

		/*子进程读取管道内容*/
		if((real_read = read(pipe_fd[0], buf,  MAX_DATA_LEN)) > 0)
		{
			printf("%d bytes read from the pipe is '%s'\n",real_read,buf);
		}

		/*关闭子进程读描述符*/
		close(pipe_fd[0]);

		exit(0);
	}
	else if(pid > 0)
	{
		/*此处是父进程*/
		close(pipe_fd[0]);

		if((real_write = write(pipe_fd[1], data, strlen(data))) != -1)
		{
			printf("Parent write %d bytes : '%s'\n", real_write, data);
		}

		/*关闭父进程写描述符*/
		close(pipe_fd[1]);

		/*收集子进程退出信息*/
		wait(&status);

		exit(0);

	}

	return 0;
}
