#include "Sysctrl.h"

/* 函数名称：exit()
 * 函数功能：关闭所有文件，中止正在执行的进程
 * 函数作用：exit(0)，exit(1~x)
 * 0代表正常退出，1~x均表示异常退出
 */

int main(int argc, char **argv)
{
	pid_t i;
	i = fork();
	
	switch(i)
	{
		case -1:
			printf("fork error!\n");
			return -1;
			break;
		case 0:
			printf("这里是子进程!");
			_exit(1);
			break;
		default:
			printf("这里是父进程");
			exit(1);
			break;
	}
	
	printf("这里应该要看不见才对\n");
	return 0;
}
