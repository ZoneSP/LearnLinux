#include "Sysctrl.h"

/* 函数名称：exit()
 * 函数功能：关闭所有文件，中止正在执行的进程
 * 函数作用：exit(0)，exit(1~x)
 * 0代表正常退出，1~x均表示异常退出
 */

int main(int argc, char **argv)
{
	pid_t i;
	int check_flag;
	i = fork();
	
	if(i == 0)
	{
		/*当下是子进程*/
		printf("此刻进程PID为： %d\n",i);
		execl("/bin/ls", "ls", "-l", NULL);  //NULL代表参数传输完毕
		printf("error!!!\n");  //只有当ls -l不执行时，才会运行到这里，然后报错
		return -1;
	}
	
	printf("此刻进程PID为：%d\n",i);
	
	return 0;
}
