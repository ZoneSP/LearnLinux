#include "Sysctrl.h"

/* 函数名称：memset()  void *memset(void *str, int c, size_t n);
 * 函数功能：复制字符C到str指向字符串前n个字符
 * 函数示例：str[] = "ABCDEFG"，memset(str, '$', 4)   ->    "$$$$EFG"
 */

#define MAX_DATA_LEN   256


int main(int argc, char *argv[])
{
	pid_t pid;

	/*创建一个子进程*/
	pid = fork();

	if(pid < 0)
	{
		printf("创建子进程失败！\n");
		exit(1);
	}


	if(pid == 0)
	{
		/*子进程处理区域*/
		printf("子进程即将暂停自己！\n");

		raise(SIGSTOP);
	}
	else
	{
		sleep(3);  /*等待3秒，让子进程完成动作*/

		if(kill(pid, SIGKILL) == 0)
		{
			printf("父进程终结了子进程！\n");
		}
		else
		{
			printf("父进程终结子进程失败\n");
		}

		wait(NULL);

		printf("父进程退出运行\n");

		exit(0);
	}
}
