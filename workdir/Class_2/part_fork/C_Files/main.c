#include "Sysctrl.h"

/* 函数名称：exit()
 * 函数功能：关闭所有文件，中止正在执行的进程
 * 函数作用：exit(0)，exit(1~x)
 * 0代表正常退出，1~x均表示异常退出
 */

int main(int argc, char **argv)
{
	pid_t i;
	printf("Now is before fork !\n");
	i = fork();
	printf("Now is after fork(), i = %d\n",i);	

	return 0;
}
