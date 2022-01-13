#include "Sysctrl.h"

/* 函数名称：exit()
 * 函数功能：关闭所有文件，中止正在执行的进程
 * 函数作用：exit(0)，exit(1~x)
 * 0代表正常退出，1~x均表示异常退出
 */

int main(int argc, char **argv)
{
	int Loop = 0;
	pid_t i;
	int status;
	pid_t wait_i;
	
	i = fork();

	if(i == -1)
	{
		printf("fork error!\n");
		return -1;
	}

	if(i == 0)
	{
		printf("子进程再和你打招呼\n");
		exit(7);
	}
	else
	{
		printf("父进程创建的新子进程PID：%d\n",i);
		wait_i = wait(&status);
		printf("现在wait返回的子进程PID的值是：%d\n",wait_i);
		if(WIFEXITED(status) == 1)
		{
			printf("exit value：%d\n", WEXITSTATUS(status));
		}

		return 0;
	}
}
